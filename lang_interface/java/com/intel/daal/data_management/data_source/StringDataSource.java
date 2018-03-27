/* file: StringDataSource.java */
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

/**
 * @ingroup data_sources
 * @{
 */
package com.intel.daal.data_management.data_source;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.Serializable;

import com.intel.daal.services.DaalContext;

/**
 *  <a name="DAAL-CLASS-DATA_MANAGEMENT__DATA_SOURCE__STRINGDATASOURCE"></a>
 * @brief Specifies the methods for accessing the data stored as a text in java.io.Strings format
 */
public class StringDataSource extends DataSource implements Serializable {
    /** @private */
    static {
        System.loadLibrary("JavaAPI");
    }

    /**
     * Default constructor
     */
    public StringDataSource(DaalContext context, String data) {
        super(context);

        cObject = cInit(data, data.length());
        featureManager = new FeatureManager(context, cGetFeatureManager(cObject));
        _dataForSerialization = data;
    }

    /**
     * Constructor
     */
    public StringDataSource(DaalContext context, String data, DictionaryCreationFlag doDict,
            NumericTableAllocationFlag doNT) {
        super(context);

        cObject = cInit(data, data.length());
        featureManager = new FeatureManager(context, cGetFeatureManager(cObject));
        _dataForSerialization = data;

        if (doDict.ordinal() == DictionaryCreationFlag.DoDictionaryFromContext.ordinal()) {
            this.createDictionaryFromContext();
        }

        if (doNT.ordinal() == NumericTableAllocationFlag.DoAllocateNumericTable.ordinal()) {
            this.allocateNumericTable();
        }
    }

    protected native long cInit(String data, long length);

    /**
     *  Sets new string as a source for the data
     *  @param  data  Strings with the data
     */
    public void setData(String data) {
        cSetData(cObject, data, data.length());
    }

    private native void cSetData(long ptr, String data, long length);

    protected String _dataForSerialization;

    private void readObject(ObjectInputStream aInputStream) throws ClassNotFoundException, IOException {
        aInputStream.defaultReadObject();
        cObject = cInit(_dataForSerialization, _dataForSerialization.length());
        featureManager = new FeatureManager(getContext(), cGetFeatureManager(cObject));
    }

    private native void cDispose(long ptr);
    private native long cGetFeatureManager(long cObject);
}
/** @} */
