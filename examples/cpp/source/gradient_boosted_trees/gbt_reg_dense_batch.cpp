/* file: gbt_reg_dense_batch.cpp */
/*******************************************************************************
* Copyright 2014-2018 Intel Corporation
* All Rights Reserved.
*
* If this  software was obtained  under the  Intel Simplified  Software License,
* the following terms apply:
*
* The source code,  information  and material  ("Material") contained  herein is
* owned by Intel Corporation or its  suppliers or licensors,  and  title to such
* Material remains with Intel  Corporation or its  suppliers or  licensors.  The
* Material  contains  proprietary  information  of  Intel or  its suppliers  and
* licensors.  The Material is protected by  worldwide copyright  laws and treaty
* provisions.  No part  of  the  Material   may  be  used,  copied,  reproduced,
* modified, published,  uploaded, posted, transmitted,  distributed or disclosed
* in any way without Intel's prior express written permission.  No license under
* any patent,  copyright or other  intellectual property rights  in the Material
* is granted to  or  conferred  upon  you,  either   expressly,  by implication,
* inducement,  estoppel  or  otherwise.  Any  license   under such  intellectual
* property rights must be express and approved by Intel in writing.
*
* Unless otherwise agreed by Intel in writing,  you may not remove or alter this
* notice or  any  other  notice   embedded  in  Materials  by  Intel  or Intel's
* suppliers or licensors in any way.
*
*
* If this  software  was obtained  under the  Apache License,  Version  2.0 (the
* "License"), the following terms apply:
*
* You may  not use this  file except  in compliance  with  the License.  You may
* obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
*
*
* Unless  required  by   applicable  law  or  agreed  to  in  writing,  software
* distributed under the License  is distributed  on an  "AS IS"  BASIS,  WITHOUT
* WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*
* See the   License  for the   specific  language   governing   permissions  and
* limitations under the License.
*******************************************************************************/

/*
!  Content:
!    C++ example of gradient boosted trees regression in the batch processing mode.
!
!    The program trains the gradient boosted trees regression model on a training
!    datasetFileName and computes regression for the test data.
!******************************************************************************/

/**
 * <a name="DAAL-EXAMPLE-CPP-GBT_REG_DENSE_BATCH"></a>
 * \example gbt_reg_dense_batch.cpp
 */

#include "daal.h"
#include "service.h"

using namespace std;
using namespace daal;
using namespace daal::algorithms::gbt::regression;

/* Input data set parameters */
const string trainDatasetFileName = "../data/batch/df_regression_train.csv";
const string testDatasetFileName  = "../data/batch/df_regression_test.csv";
const size_t categoricalFeaturesIndices[] = { 3 };
const size_t nFeatures = 13;  /* Number of features in training and testing data sets */

/* Gradient boosted trees training parameters */
const size_t maxIterations = 40;

training::ResultPtr trainModel();
void testModel(const training::ResultPtr& res);
void loadData(const std::string& fileName, NumericTablePtr& pData, NumericTablePtr& pDependentVar);

int main(int argc, char *argv[])
{
    checkArguments(argc, argv, 2, &trainDatasetFileName, &testDatasetFileName);

    training::ResultPtr trainingResult = trainModel();
    testModel(trainingResult);

    return 0;
}

training::ResultPtr trainModel()
{
    /* Create Numeric Tables for training data and dependent variables */
    NumericTablePtr trainData;
    NumericTablePtr trainDependentVariable;

    loadData(trainDatasetFileName, trainData, trainDependentVariable);

    /* Create an algorithm object to train the gradient boosted trees regression model with the default method */
    training::Batch<> algorithm;

    /* Pass a training data set and dependent values to the algorithm */
    algorithm.input.set(training::data, trainData);
    algorithm.input.set(training::dependentVariable, trainDependentVariable);

    algorithm.parameter().maxIterations = maxIterations;

    /* Build the gradient boosted trees regression model */
    algorithm.compute();

    /* Retrieve the algorithm results */
    return algorithm.getResult();
}

void testModel(const training::ResultPtr& trainingResult)
{
    /* Create Numeric Tables for testing data and ground truth values */
    NumericTablePtr testData;
    NumericTablePtr testGroundTruth;

    loadData(testDatasetFileName, testData, testGroundTruth);

    /* Create an algorithm object to predict values of gradient boosted trees regression */
    prediction::Batch<> algorithm;

    /* Pass a testing data set and the trained model to the algorithm */
    algorithm.input.set(prediction::data, testData);
    algorithm.input.set(prediction::model, trainingResult->get(training::model));

    /* Predict values of gradient boosted trees regression */
    algorithm.compute();

    /* Retrieve the algorithm results */
    prediction::ResultPtr predictionResult = algorithm.getResult();
    printNumericTable(predictionResult->get(prediction::prediction),
        "Gragient boosted trees prediction results (first 10 rows):", 10);
    printNumericTable(testGroundTruth, "Ground truth (first 10 rows):", 10);
}

void loadData(const std::string& fileName, NumericTablePtr& pData, NumericTablePtr& pDependentVar)
{
    /* Initialize FileDataSource<CSVFeatureManager> to retrieve the input data from a .csv file */
    FileDataSource<CSVFeatureManager> trainDataSource(fileName,
        DataSource::notAllocateNumericTable,
        DataSource::doDictionaryFromContext);

    /* Create Numeric Tables for training data and dependent variables */
    pData.reset(new HomogenNumericTable<>(nFeatures, 0, NumericTable::notAllocate));
    pDependentVar.reset(new HomogenNumericTable<>(1, 0, NumericTable::notAllocate));
    NumericTablePtr mergedData(new MergedNumericTable(pData, pDependentVar));

    /* Retrieve the data from input file */
    trainDataSource.loadDataBlock(mergedData.get());

    NumericTableDictionaryPtr pDictionary = pData->getDictionarySharedPtr();
    for(size_t i = 0, n = sizeof(categoricalFeaturesIndices) / sizeof(categoricalFeaturesIndices[0]); i < n; ++i)
        (*pDictionary)[categoricalFeaturesIndices[i]].featureType = data_feature_utils::DAAL_CATEGORICAL;
}
