/* file: BatchNormalizationForwardResult.java */
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

/**
 * @ingroup batch_normalization_forward
 * @{
 */
package com.intel.daal.algorithms.neural_networks.layers.batch_normalization;

import com.intel.daal.utils.*;
import com.intel.daal.data_management.data.Factory;
import com.intel.daal.data_management.data.Tensor;
import com.intel.daal.services.DaalContext;

/**
 * <a name="DAAL-CLASS-ALGORITHMS__NEURAL_NETWORKS__LAYERS__BATCHNORMALIZATIONBATCH_NORMALIZATION__BATCHNORMALIZATIONFORWARDRESULT"></a>
 * @brief Class that provides methods to access the result obtained with the compute() method of the forward batch normalization layer
 */
public final class BatchNormalizationForwardResult extends com.intel.daal.algorithms.neural_networks.layers.ForwardResult {
    /** @private */
    static {
        LibUtils.loadLibrary();
    }

    /**
     * Constructs the forward batch normalization layer result
     * @param context   Context to manage the forward batch normalization layer result
     */
    public BatchNormalizationForwardResult(DaalContext context) {
        super(context);
        this.cObject = cNewResult();
    }

    public BatchNormalizationForwardResult(DaalContext context, long cObject) {
        super(context, cObject);
    }

    /**
     * Returns the result of the forward batch normalization layer
     * @param  id   Identifier of the result
     * @return Result that corresponds to the given identifier
     */
    public Tensor get(BatchNormalizationLayerDataId id) {
        if (id == BatchNormalizationLayerDataId.auxData || id == BatchNormalizationLayerDataId.auxWeights ||
            id == BatchNormalizationLayerDataId.auxMean || id == BatchNormalizationLayerDataId.auxStandardDeviation ||
            id == BatchNormalizationLayerDataId.auxPopulationMean || id == BatchNormalizationLayerDataId.auxPopulationVariance) {
            return (Tensor)Factory.instance().createObject(getContext(), cGetValue(cObject, id.getValue()));
        }
        else {
            throw new IllegalArgumentException("id unsupported");
        }
    }

    /**
     * Sets the result of the forward batch normalization layer
     * @param id   Identifier of the result
     * @param val  Result that corresponds to the given identifier
     */
    public void set(BatchNormalizationLayerDataId id, Tensor val) {
        if (id == BatchNormalizationLayerDataId.auxData || id == BatchNormalizationLayerDataId.auxWeights ||
            id == BatchNormalizationLayerDataId.auxMean || id == BatchNormalizationLayerDataId.auxStandardDeviation ||
            id == BatchNormalizationLayerDataId.auxPopulationMean || id == BatchNormalizationLayerDataId.auxPopulationVariance) {
            cSetValue(cObject, id.getValue(), val.getCObject());
        }
        else {
            throw new IllegalArgumentException("id unsupported");
        }
    }

    private native long cNewResult();

    private native long cGetValue(long cObject, int id);

    private native void cSetValue(long cObject, int id, long ntAddr);
}
/** @} */
