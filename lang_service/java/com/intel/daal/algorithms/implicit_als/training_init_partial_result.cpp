/* file: training_init_partial_result.cpp */
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

#include <jni.h>

#include "daal.h"

#include "implicit_als/training/init/JInitPartialResult.h"

#include "implicit_als_init_defines.i"

#include "common_helpers.h"

USING_COMMON_NAMESPACES()
using namespace daal::algorithms::implicit_als::training::init;

/*
 * Class:     com_intel_daal_algorithms_implicit_als_training_init_InitPartialResult
 * Method:    cNewPartialResult
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_implicit_1als_training_init_InitPartialResult_cNewPartialResult
(JNIEnv *env, jobject thisObj)
{
    return jniArgument<implicit_als::training::init::PartialResult>::newObj();
}

/*
 * Class:     com_intel_daal_algorithms_implicit_als_training_init_InitPartialResult
 * Method:    cGetPartialResultModel
 * Signature: (JI)J
 */
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_implicit_1als_training_init_InitPartialResult_cGetPartialResultModel
(JNIEnv *env, jobject thisObj, jlong partialResultAddr, jint id)
{
    return jniArgument<implicit_als::training::init::PartialResult>::
        get<PartialResultId, implicit_als::PartialModel>(partialResultAddr, id);
}

/*
 * Class:     com_intel_daal_algorithms_implicit_als_training_init_InitPartialResult
 * Method:    cSetPartialResultModel
 * Signature: (JIJ)V
 */
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_implicit_1als_training_init_InitPartialResult_cSetPartialResultModel
(JNIEnv *env, jobject thisObj, jlong partialResultAddr, jint id, jlong mdlAddr)
{
    jniArgument<implicit_als::training::init::PartialResult>::
        set<PartialResultId, implicit_als::PartialModel>(partialResultAddr, id, mdlAddr);
}

/*
 * Class:     com_intel_daal_algorithms_implicit_als_training_init_InitPartialResult
 * Method:    cGetPartialResultCollection
 * Signature: (JI)J
 */
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_implicit_1als_training_init_InitPartialResult_cGetPartialResultCollection
(JNIEnv *env, jobject thisObj, jlong partialResultAddr, jint id)
{
    return jniArgument<implicit_als::training::init::PartialResult>::
        get<PartialResultCollectionId, KeyValueDataCollection>(partialResultAddr, id);
}

/*
 * Class:     com_intel_daal_algorithms_implicit_als_training_init_InitPartialResult
 * Method:    cSetPartialResultCollection
 * Signature: (JIJ)V
 */
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_implicit_1als_training_init_InitPartialResult_cSetPartialResultCollection
(JNIEnv *env, jobject thisObj, jlong partialResultAddr, jint id, jlong collectionAddr)
{
    jniArgument<implicit_als::training::init::PartialResult>::
        set<PartialResultCollectionId, KeyValueDataCollection>(partialResultAddr, id, collectionAddr);
}

/*
 * Class:     com_intel_daal_algorithms_implicit_als_training_init_InitPartialResult
 * Method:    cGetPartialResultTable
 * Signature: (JIJ)J
 */
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_implicit_1als_training_init_InitPartialResult_cGetPartialResultTable
(JNIEnv *env, jobject thisObj, jlong partialResultAddr, jint id, jlong key)
{
    return jniArgument<implicit_als::training::init::PartialResult>::
        get<PartialResultCollectionId, NumericTable>(partialResultAddr, id, key);
}
