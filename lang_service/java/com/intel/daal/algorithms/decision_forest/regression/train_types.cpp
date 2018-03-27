/* file: train_types.cpp */
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

/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>

#include "daal.h"
#include "decision_forest/regression/training/JParameter.h"
#include "decision_forest/regression/training/JResultNumericTableId.h"
#include "decision_forest/regression/training/JTrainingResult.h"
#include "decision_forest/regression/training/JTrainingResultId.h"
#include "decision_forest/regression/training/JInputId.h"
#include "decision_forest/regression/training/JTrainingInput.h"
#include "JComputeMode.h"
#include "decision_forest/JVariableImportanceModeId.h"
#include "common_helpers.h"

USING_COMMON_NAMESPACES()

namespace dfr = decision_forest::regression;
namespace dfrt = daal::algorithms::decision_forest::regression::training;

#define outOfBagErrorId  com_intel_daal_algorithms_decision_forest_regression_training_ResultNumericTableId_outOfBagErrorId
#define outOfBagErrorPerObservationId  com_intel_daal_algorithms_decision_forest_regression_training_ResultNumericTableId_outOfBagErrorPerObservationId
#define variableImportanceId  com_intel_daal_algorithms_decision_forest_regression_training_ResultNumericTableId_variableImportanceId
#define jBatch   com_intel_daal_algorithms_ComputeMode_batchValue
#define ModelResult  com_intel_daal_algorithms_decision_forest_regression_training_TrainingResultId_Model

/*
* Class:     com_intel_daal_algorithms_decision_forest_regression_training_Parameter
* Method:    cGetNTrees
* Signature: (J)J
*/
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_decision_1forest_regression_training_Parameter_cGetNTrees
(JNIEnv *, jobject, jlong parAddr)
{
    return(jlong)(*(dfrt::Parameter *)parAddr).nTrees;
}

/*
* Class:     com_intel_daal_algorithms_decision_forest_regression_training_Parameter
* Method:    cSetNTrees
* Signature: (JJ)V
*/
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_decision_1forest_regression_training_Parameter_cSetNTrees
(JNIEnv *, jobject, jlong parAddr, jlong value)
{
    (*(dfrt::Parameter *)parAddr).nTrees = value;
}

/*
* Class:     com_intel_daal_algorithms_decision_forest_regression_training_Parameter
* Method:    cSetObservationsPerTreeFraction
* Signature: (JD)V
*/
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_decision_1forest_regression_training_Parameter_cSetObservationsPerTreeFraction
(JNIEnv *, jobject, jlong parAddr, jdouble value)
{
    (*(dfrt::Parameter *)parAddr).observationsPerTreeFraction = value;
}

/*
* Class:     com_intel_daal_algorithms_decision_forest_regression_training_Parameter
* Method:    cGetObservationsPerTreeFraction
* Signature: (J)D
*/
JNIEXPORT jdouble JNICALL Java_com_intel_daal_algorithms_decision_1forest_regression_training_Parameter_cGetObservationsPerTreeFraction
(JNIEnv *, jobject, jlong parAddr)
{
    return(jdouble)(*(dfrt::Parameter *)parAddr).observationsPerTreeFraction;
}

/*
* Class:     com_intel_daal_algorithms_decision_forest_regression_training_Parameter
* Method:    cGetFeaturesPerNode
* Signature: (J)J
*/
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_decision_1forest_regression_training_Parameter_cGetFeaturesPerNode
(JNIEnv *, jobject, jlong parAddr)
{
    return(jlong)(*(dfrt::Parameter *)parAddr).featuresPerNode;
}

/*
* Class:     com_intel_daal_algorithms_decision_forest_regression_training_Parameter
* Method:    cSetFeaturesPerNode
* Signature: (JJ)V
*/
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_decision_1forest_regression_training_Parameter_cSetFeaturesPerNode
(JNIEnv *, jobject, jlong parAddr, jlong value)
{
    (*(dfrt::Parameter *)parAddr).featuresPerNode = value;
}

/*
* Class:     com_intel_daal_algorithms_decision_forest_regression_training_Parameter
* Method:    cGetMaxTreeDepth
* Signature: (J)J
*/
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_decision_1forest_regression_training_Parameter_cGetMaxTreeDepth
(JNIEnv *, jobject, jlong parAddr)
{
    return(jlong)(*(dfrt::Parameter *)parAddr).maxTreeDepth;
}

/*
* Class:     com_intel_daal_algorithms_decision_forest_regression_training_Parameter
* Method:    cSetMaxTreeDepth
* Signature: (JJ)V
*/
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_decision_1forest_regression_training_Parameter_cSetMaxTreeDepth
(JNIEnv *, jobject, jlong parAddr, jlong value)
{
    (*(dfrt::Parameter *)parAddr).maxTreeDepth = value;
}

/*
* Class:     com_intel_daal_algorithms_decision_forest_regression_training_Parameter
* Method:    cGetMinObservationsInLeafNode
* Signature: (J)J
*/
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_decision_1forest_regression_training_Parameter_cGetMinObservationsInLeafNode
(JNIEnv *, jobject, jlong parAddr)
{
    return(jlong)(*(dfrt::Parameter *)parAddr).minObservationsInLeafNode;
}

/*
* Class:     com_intel_daal_algorithms_decision_forest_regression_training_Parameter
* Method:    cSetMinObservationsInLeafNode
* Signature: (JJ)V
*/
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_decision_1forest_regression_training_Parameter_cSetMinObservationsInLeafNode
(JNIEnv *, jobject, jlong parAddr, jlong value)
{
    (*(dfrt::Parameter *)parAddr).minObservationsInLeafNode = value;
}

/*
* Class:     com_intel_daal_algorithms_decision_forest_regression_training_Parameter
* Method:    cGetSeed
* Signature: (J)I
*/
JNIEXPORT jint JNICALL Java_com_intel_daal_algorithms_decision_1forest_regression_training_Parameter_cGetSeed
(JNIEnv *, jobject, jlong parAddr)
{
    return(jint)(*(dfrt::Parameter *)parAddr).seed;
}

/*
* Class:     com_intel_daal_algorithms_decision_forest_regression_training_Parameter
* Method:    cSetSeed
* Signature: (JI)V
*/
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_decision_1forest_regression_training_Parameter_cSetSeed
(JNIEnv *, jobject, jlong parAddr, jint value)
{
    (*(dfrt::Parameter *)parAddr).seed = value;
}

/*
 * Class:     com_intel_daal_algorithms_decision_forest_regression_training_Parameter
 * Method:    cSetEngine
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_decision_1forest_regression_training_Parameter_cSetEngine
(JNIEnv *env, jobject thisObj, jlong cParameter, jlong engineAddr)
{
    (((dfrt::Parameter *)cParameter))->engine = staticPointerCast<engines::BatchBase, AlgorithmIface> (*(SharedPtr<AlgorithmIface> *)engineAddr);
}

/*
* Class:     com_intel_daal_algorithms_decision_forest_regression_training_Parameter
* Method:    cSetImpurityThreshold
* Signature: (JD)V
*/
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_decision_1forest_regression_training_Parameter_cSetImpurityThreshold
(JNIEnv *, jobject, jlong parAddr, jdouble value)
{
    (*(dfrt::Parameter *)parAddr).impurityThreshold = value;
}

/*
* Class:     com_intel_daal_algorithms_decision_forest_regression_training_Parameter
* Method:    cGetImpurityThreshold
* Signature: (J)D
*/
JNIEXPORT jdouble JNICALL Java_com_intel_daal_algorithms_decision_1forest_regression_training_Parameter_cGetImpurityThreshold
(JNIEnv *, jobject, jlong parAddr)
{
    return(jdouble)(*(dfrt::Parameter *)parAddr).impurityThreshold;
}

/*
* Class:     com_intel_daal_algorithms_decision_forest_regression_training_Parameter
* Method:    cSetResultsToCompute
* Signature: (JJ)V
*/
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_decision_1forest_regression_training_Parameter_cSetResultsToCompute
(JNIEnv *, jobject, jlong parAddr, jlong value)
{
    (*(dfrt::Parameter *)parAddr).resultsToCompute = value;
}

/*
* Class:     com_intel_daal_algorithms_decision_forest_regression_training_Parameter
* Method:    cGetResultsToCompute
* Signature: (J)J
*/
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_decision_1forest_regression_training_Parameter_cGetResultsToCompute
(JNIEnv *, jobject, jlong parAddr)
{
    return(jlong)(*(dfrt::Parameter *)parAddr).resultsToCompute;
}

/*
* Class:     com_intel_daal_algorithms_decision_forest_regression_training_Parameter
* Method:    cGetVariableImportanceMode
* Signature: (J)I
*/
JNIEXPORT jint JNICALL Java_com_intel_daal_algorithms_decision_1forest_regression_training_Parameter_cGetVariableImportanceMode
(JNIEnv *, jobject, jlong parAddr)
{
    return(jint)(*(dfrt::Parameter *)parAddr).varImportance;
}

/*
* Class:     com_intel_daal_algorithms_decision_forest_regression_training_Parameter
* Method:    cSetVariableImportanceMode
* Signature: (JI)V
*/
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_decision_1forest_regression_training_Parameter_cSetVariableImportanceMode
(JNIEnv *, jobject, jlong parAddr, jint value)
{
    (*(dfrt::Parameter *)parAddr).varImportance = decision_forest::training::VariableImportanceMode(value);
}

/*
* Class:     com_intel_daal_algorithms_decision_forest_regression_training_TrainingResult
* Method:    cGetResult
* Signature: (JI)J
*/
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_decision_1forest_regression_training_TrainingResult_cGetResult
(JNIEnv *env, jobject thisObj, jlong algAddr, jint prec, jint method)
{
    return jniBatch<dfrt::Method, dfrt::Batch, dfrt::defaultDense>::getResult(prec, method, algAddr);
}

/*
* Class:     com_intel_daal_algorithms_decision_forest_regression_training_TrainingResult
* Method:    cGetModel
* Signature: (JI)J
*/
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_decision_1forest_regression_training_TrainingResult_cGetModel
(JNIEnv *, jobject thisObj, jlong resAddr, jint id)
{
    dfr::ModelPtr *m = new dfr::ModelPtr();
    dfrt::ResultPtr res = services::staticPointerCast<dfrt::Result, SerializationIface>(*((SerializationIfacePtr *)resAddr));
    jlong resModel = 0;
    switch(id)
    {
    case ModelResult:
        *m = res->get(dfrt::model);
        break;
    default:
        break;
    }
    return (jlong)m;
}

/*
* Class:     com_intel_daal_algorithms_decision_forest_regression_training_TrainingResult
* Method:    cGetResultTable
* Signature: (JI)J
*/
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_decision_1forest_regression_training_TrainingResult_cGetResultTable
(JNIEnv *, jobject thisObj, jlong resAddr, jint id)
{
    NumericTablePtr* pTbl = new NumericTablePtr();
    dfrt::ResultPtr res =
        services::staticPointerCast<dfrt::Result, SerializationIface>(*((SerializationIfacePtr *)resAddr));

    jlong resModel = 0;
    switch(id)
    {
    case outOfBagErrorId:
    case variableImportanceId:
    case outOfBagErrorPerObservationId:
        *pTbl = res->get(dfrt::ResultNumericTableId(id));
        break;
    default:
        break;
    }
    return (jlong)pTbl;
}

/*
* Class:     com_intel_daal_algorithms_decision_forest_regression_training_TrainingInput
* Method:    cInit
* Signature: (JI)J
*/
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_decision_1forest_regression_training_TrainingInput_cInit
(JNIEnv *, jobject, jlong algAddr, jint prec, jint method)
{
    return jniBatch<dfrt::Method, dfrt::Batch, dfrt::defaultDense>::getInput(prec, method, algAddr);
}

/*
* Class:     com_intel_daal_algorithms_decision_forest_regression_training_TrainingInput
* Method:    cSetInput
* Signature: (JIJ)V
*/
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_decision_1forest_regression_training_TrainingInput_cSetInput
(JNIEnv *, jobject, jlong inputAddr, jint id, jlong valAddr)
{
    jniInput<dfrt::Input>::set<dfrt::InputId, NumericTable>(inputAddr, dfrt::InputId(id), valAddr);
}

/*
* Class:     com_intel_daal_algorithms_decision_forest_regression_training_TrainingInput
* Method:    cGetInput
* Signature: (JI)J
*/
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_decision_1forest_regression_training_TrainingInput_cGetInput
(JNIEnv *, jobject, jlong inputAddr, jint id)
{
    return jniInput<dfrt::Input>::get<dfrt::InputId, NumericTable>(inputAddr, dfrt::InputId(id));
}
