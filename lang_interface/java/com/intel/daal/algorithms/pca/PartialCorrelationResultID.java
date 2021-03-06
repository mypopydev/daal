/* file: PartialCorrelationResultID.java */
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
 * @ingroup pca
 * @{
 */
package com.intel.daal.algorithms.pca;

import com.intel.daal.utils.*;
/**
 * <a name="DAAL-CLASS-ALGORITHMS__PCA__PARTIALCORRELATIONRESULTID"></a>
 * @brief Available identifiers of partial results of the %correlation method of the PCA algorithm
 */
public final class PartialCorrelationResultID {
    private int _value;

    static {
        LibUtils.loadLibrary();
    }

    /**
     * Constructs the partial result object identifier using the provided value
     * @param value     Value corresponding to the partial result object identifier
     */
    public PartialCorrelationResultID(int value) {
        _value = value;
    }

    /**
     * Returns the value corresponding to the partial result object identifier
     * @return Value corresponding to the partial result object identifier
     */
    public int getValue() {
        return _value;
    }

    private static final int nObservationsId           = 0;
    private static final int crossProductCorrelationId = 1;
    private static final int sumCorrelationId          = 2;

    /*!< Number of observations */
    public static final PartialCorrelationResultID nObservations           = new PartialCorrelationResultID(
            nObservationsId);
    /*!< Cross-product matrix */
    public static final PartialCorrelationResultID crossProductCorrelation = new PartialCorrelationResultID(
            crossProductCorrelationId);
    /*!< Array of sums */
    public static final PartialCorrelationResultID sumCorrelation          = new PartialCorrelationResultID(
            sumCorrelationId);
}
/** @} */
