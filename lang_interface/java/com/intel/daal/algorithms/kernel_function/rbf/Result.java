/* file: Result.java */
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
 * @ingroup kernel_function_rbf
 * @{
 */
package com.intel.daal.algorithms.kernel_function.rbf;

import com.intel.daal.utils.*;
import com.intel.daal.algorithms.Precision;
import com.intel.daal.algorithms.kernel_function.ResultId;
import com.intel.daal.data_management.data.Factory;
import com.intel.daal.data_management.data.NumericTable;
import com.intel.daal.services.DaalContext;

/**
 * <a name="DAAL-CLASS-ALGORITHMS__KERNEL_FUNCTION__RBF__RESULT"></a>
 * @brief Results obtained with the compute() method of the RBF kernel function algorithm in the batch processing mode
 */
public class Result extends com.intel.daal.algorithms.Result {
    /** @private */
    static {
        LibUtils.loadLibrary();
    }

    /**
     * Constructs the result of the RBF kernel function algorithm in the batch processing mode
     * @param context   Context to manage the result of the RBF kernel function algorithm in the batch processing mode
     */
    public Result(DaalContext context) {
        super(context);
        this.cObject = cNewResult();
    }

    public Result(DaalContext context, long cObject) {
        super(context, cObject);
    }

    /**
     * Returns the result of the RBF kernel function algorithm
     * @param id   Identifier of the result
     * @return     Final result that corresponds to the given identifier
     */
    public NumericTable get(ResultId id) {
        if (id != ResultId.values) {
            throw new IllegalArgumentException("id unsupported");
        }
        return (NumericTable)Factory.instance().createObject(getContext(), cGetResultTable(cObject, id.getValue()));
    }

    /**
     * Sets the result of the RBF kernel function algorithm
     * @param id    Identifier of the result
     * @param val   Object to store the final result
     */
    public void set(ResultId id, NumericTable val) {
        if (id != ResultId.values) {
            throw new IllegalArgumentException("id unsupported");
        }
        cSetResultTable(cObject, id.getValue(), val.getCObject());
    }

    private native long cNewResult();

    private native long cGetResultTable(long cObject, int id);

    private native void cSetResultTable(long cObject, int id, long cNumTable);
}
/** @} */
