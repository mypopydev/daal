/* file: spatial_stochastic_pooling2d_backward_input.cpp */
/*******************************************************************************
* Copyright 2014-2018 Intel Corporation.
*
* This software and the related documents are Intel copyrighted  materials,  and
* your use of  them is  governed by the  express license  under which  they were
* provided to you (License).  Unless the License provides otherwise, you may not
* use, modify, copy, publish, distribute,  disclose or transmit this software or
* the related documents without Intel's prior written permission.
*
* This software and the related documents  are provided as  is,  with no express
* or implied  warranties,  other  than those  that are  expressly stated  in the
* License.
*******************************************************************************/

#include <jni.h>
#include "neural_networks/layers/spatial_stochastic_pooling2d/JSpatialStochasticPooling2dBackwardInput.h"
#include "neural_networks/layers/spatial_stochastic_pooling2d/JSpatialStochasticPooling2dLayerDataId.h"
#include "neural_networks/layers/spatial_stochastic_pooling2d/JSpatialStochasticPooling2dLayerDataNumericTableId.h"

#include "daal.h"

#include "common_helpers.h"

#define auxSelectedIndicesId com_intel_daal_algorithms_neural_networks_layers_spatial_stochastic_pooling2d_SpatialStochasticPooling2dLayerDataId_auxSelectedIndicesId
#define auxInputDimensionsId com_intel_daal_algorithms_neural_networks_layers_spatial_stochastic_pooling2d_SpatialStochasticPooling2dLayerDataNumericTableId_auxInputDimensionsId

USING_COMMON_NAMESPACES();
using namespace daal::algorithms::neural_networks::layers::spatial_stochastic_pooling2d;

/*
 * Class:     com_intel_daal_algorithms_neural_networks_layers_stochastic_1pooling2d_SpatialStochasticPooling2dBackwardInput
 * Method:    cSetInput
 * Signature: (JIJ)V
 */
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_neural_1networks_layers_spatial_1stochastic_1pooling2d_SpatialStochasticPooling2dBackwardInput_cSetInput
(JNIEnv *env, jobject thisObj, jlong inputAddr, jint id, jlong ntAddr)
{
    if (id == auxSelectedIndicesId)
    {
        jniInput<backward::Input>::set<LayerDataId, Tensor>(inputAddr, id, ntAddr);
    }
}

/*
 * Class:     com_intel_daal_algorithms_neural_networks_layers_stochastic_1pooling2d_SpatialStochasticPooling2dBackwardInput
 * Method:    cGetInput
 * Signature: (JI)J
 */
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_neural_1networks_layers_spatial_1stochastic_1pooling2d_SpatialStochasticPooling2dBackwardInput_cGetInput
(JNIEnv *env, jobject thisObj, jlong inputAddr, jint id)
{
    if (id == auxSelectedIndicesId)
    {
        return jniInput<backward::Input>::get<LayerDataId, Tensor>(inputAddr, id);
    }

    return (jlong)0;
}

/*
 * Class:     com_intel_daal_algorithms_neural_networks_layers_spatial_stochastic_pooling2d_SpatialStochasticPooling2dBackwardInput
 * Method:    cSetInputNumericTable
 * Signature: (JIJ)V
 */
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_neural_1networks_layers_spatial_1stochastic_1pooling2d_SpatialStochasticPooling2dBackwardInput_cSetInputNumericTable
(JNIEnv *env, jobject thisObj, jlong inputAddr, jint id, jlong ntAddr)
{
    if (id == auxInputDimensionsId)
    {
        jniInput<backward::Input>::set<LayerDataNumericTableId, NumericTable>(inputAddr, id, ntAddr);
    }
}

/*
 * Class:     com_intel_daal_algorithms_neural_networks_layers_spatial_stochastic_pooling2d_SpatialStochasticPooling2dBackwardInput
 * Method:    cGetInputNumericTable
 * Signature: (JI)J
 */
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_neural_1networks_layers_spatial_1stochastic_1pooling2d_SpatialStochasticPooling2dBackwardInput_cGetInputNumericTable
(JNIEnv *env, jobject thisObj, jlong inputAddr, jint id)
{
    if (id == auxInputDimensionsId)
    {
        return jniInput<backward::Input>::get<LayerDataNumericTableId, NumericTable>(inputAddr, id);
    }

    return (jlong)0;
}
