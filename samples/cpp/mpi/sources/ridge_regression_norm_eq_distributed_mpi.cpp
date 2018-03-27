/* file: ridge_regression_norm_eq_distributed_mpi.cpp */
//==============================================================
//
// SAMPLE SOURCE CODE - SUBJECT TO THE TERMS OF SAMPLE CODE LICENSE AGREEMENT,
// http://software.intel.com/en-us/articles/intel-sample-source-code-license-agreement/
//
// Copyright 2017-2018 Intel Corporation
//
// THIS FILE IS PROVIDED "AS IS" WITH NO WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT
// NOT LIMITED TO ANY IMPLIED WARRANTY OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
// PURPOSE, NON-INFRINGEMENT OF INTELLECTUAL PROPERTY RIGHTS.
//
// =============================================================

/*
!  Content:
!    C++ sample of ridge regression in the distributed processing mode.
!
!    The program trains the ridge regression model on a training data set with the normal equations method and computes regression for the test data.
!******************************************************************************/

/**
 * <a name="DAAL-SAMPLE-CPP-RIDGE_REGRESSION_NORM_EQ_DISTRIBUTED"></a>
 * \example ridge_regression_norm_eq_distributed_mpi.cpp
 */

#include <mpi.h>
#include "daal.h"
#include "service.h"

using namespace std;
using namespace daal;
using namespace daal::algorithms::ridge_regression;

const string trainDatasetFileNames[] =
{
    "./data/distributed/linear_regression_train_1.csv",
    "./data/distributed/linear_regression_train_2.csv",
    "./data/distributed/linear_regression_train_3.csv",
    "./data/distributed/linear_regression_train_4.csv"
};
string testDatasetFileName    = "./data/distributed/linear_regression_test.csv";

const size_t nBlocks              = 4;

const size_t nFeatures           = 10;  /* Number of features in training and testing data sets */
const size_t nDependentVariables = 2;   /* Number of dependent variables that correspond to each observation */

int rankId, comm_size;
#define mpi_root 0

void trainModel();
void testModel();

training::ResultPtr trainingResult;
prediction::ResultPtr predictionResult;

int main(int argc, char *argv[])
{
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rankId);

    trainModel();

    if (rankId == mpi_root)
    {
        testModel();
    }

    MPI_Finalize();

    return 0;
}

void trainModel()
{
    /* Initialize FileDataSource<CSVFeatureManager> to retrieve the input data from a .csv file */
    FileDataSource<CSVFeatureManager> trainDataSource(trainDatasetFileNames[rankId],
                                                      DataSource::notAllocateNumericTable,
                                                      DataSource::doDictionaryFromContext);

    /* Create Numeric Tables for training data and labels */
    NumericTablePtr trainData(new HomogenNumericTable<>(nFeatures, 0, NumericTable::doNotAllocate));
    NumericTablePtr trainDependentVariables(new HomogenNumericTable<>(nDependentVariables, 0, NumericTable::doNotAllocate));
    NumericTablePtr mergedData(new MergedNumericTable(trainData, trainDependentVariables));

    /* Retrieve the data from the input file */
    trainDataSource.loadDataBlock(mergedData.get());

    /* Create an algorithm object to train the ridge regression model based on the local-node data */
    training::Distributed<step1Local> localAlgorithm;

    /* Pass a training data set and dependent values to the algorithm */
    localAlgorithm.input.set(training::data, trainData);
    localAlgorithm.input.set(training::dependentVariables, trainDependentVariables);

    /* Train the ridge regression model on local nodes */
    localAlgorithm.compute();

    /* Serialize partial results required by step 2 */
    services::SharedPtr<byte> serializedData;
    InputDataArchive dataArch;
    localAlgorithm.getPartialResult()->serialize(dataArch);
    size_t perNodeArchLength = dataArch.getSizeOfArchive();

    /* Serialized data is of equal size on each node if each node called compute() equal number of times */
    if (rankId == mpi_root)
    {
        serializedData = services::SharedPtr<byte>(new byte[perNodeArchLength * nBlocks]);
    }

    byte *nodeResults = new byte[perNodeArchLength];
    dataArch.copyArchiveToArray( nodeResults, perNodeArchLength );

    /* Transfer partial results to step 2 on the root node */
    MPI_Gather(nodeResults, perNodeArchLength, MPI_CHAR, serializedData.get(), perNodeArchLength, MPI_CHAR, mpi_root, MPI_COMM_WORLD);

    delete[] nodeResults;

    if (rankId == mpi_root)
    {
        /* Create an algorithm object to build the final ridge regression model on the master node */
        training::Distributed<step2Master> masterAlgorithm;

        for (size_t i = 0; i < nBlocks; ++i)
        {
            /* Deserialize partial results from step 1 */
            OutputDataArchive dataArch(serializedData.get() + perNodeArchLength * i, perNodeArchLength);

            training::PartialResultPtr dataForStep2FromStep1 =
                training::PartialResultPtr(new training::PartialResult());
            dataForStep2FromStep1->deserialize(dataArch);

            /* Set the local ridge regression model as input for the master-node algorithm */
            masterAlgorithm.input.add(training::partialModels, dataForStep2FromStep1);
        }

        /* Merge and finalizeCompute the ridge regression model on the master node */
        masterAlgorithm.compute();
        masterAlgorithm.finalizeCompute();

        /* Retrieve the algorithm results */
        trainingResult = masterAlgorithm.getResult();
        printNumericTable(trainingResult->get(training::model)->getBeta(), "Ridge Regression coefficients:");
    }
}

void testModel()
{
    /* Initialize FileDataSource<CSVFeatureManager> to retrieve the input data from a .csv file */
    FileDataSource<CSVFeatureManager> testDataSource(testDatasetFileName, DataSource::doAllocateNumericTable, DataSource::doDictionaryFromContext);

    /* Create Numeric Tables for testing data and ground truth values */
    NumericTablePtr testData(new HomogenNumericTable<>(nFeatures, 0, NumericTable::doNotAllocate));
    NumericTablePtr testGroundTruth(new HomogenNumericTable<>(nDependentVariables, 0, NumericTable::doNotAllocate));
    NumericTablePtr mergedData(new MergedNumericTable(testData, testGroundTruth));

    /* Retrieve the data from an input file */
    testDataSource.loadDataBlock(mergedData.get());

    /* Create an algorithm object to predict values of ridge regression */
    prediction::Batch<> algorithm;

    /* Pass a testing data set and the trained model to the algorithm */
    algorithm.input.set(prediction::data, testData);
    algorithm.input.set(prediction::model, trainingResult->get(training::model));

    /* Predict values of ridge regression */
    algorithm.compute();

    /* Retrieve the algorithm results */
    predictionResult = algorithm.getResult();
    printNumericTable(predictionResult->get(prediction::prediction), "Ridge Regression prediction results: (first 10 rows):", 10);
    printNumericTable(testGroundTruth, "Ground truth (first 10 rows):", 10);
}
