/* file: bernoulli_impl.i */
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
//++
//  Implementation of bernoulli algorithm
//--
*/

#ifndef __BERNOULLI_IMPL_I__
#define __BERNOULLI_IMPL_I__

using namespace daal::algorithms::distributions::uniform::internal;
using namespace daal::data_management;

namespace daal
{
namespace algorithms
{
namespace distributions
{
namespace bernoulli
{
namespace internal
{

template<typename algorithmFPType, Method method, CpuType cpu>
Status BernoulliKernel<algorithmFPType, method, cpu>::computeInt(int *resultArray, size_t n, algorithmFPType p, engines::BatchBase &engine)
{
    const int one  = 1;
    const int zero = 0;
    const size_t nElemsInBlock = 1024;

    size_t nBlocks = n / nElemsInBlock;
    nBlocks += (nBlocks * nElemsInBlock != n);

    algorithmFPType buffer[nElemsInBlock];

    size_t nElemsToProcess = nElemsInBlock;
    Status s;
    for(size_t block = 0; block < nBlocks; block++)
    {
        size_t nProcessed = block * nElemsInBlock;
        int *array = resultArray + nProcessed;
        if(block == nBlocks - 1)
        {
            nElemsToProcess = n - nProcessed;
        }
        DAAL_CHECK_STATUS(s, (UniformKernelDefault<algorithmFPType, cpu>::compute(0.0, 1.0, engine, nElemsToProcess, buffer)));

        for(size_t j = 0; j < nElemsToProcess; j++)
        {
            array[j] = ((buffer[j] < p) ? one : zero);
        }
    }
    return s;
}

template<typename algorithmFPType, Method method, CpuType cpu>
Status BernoulliKernel<algorithmFPType, method, cpu>::computeFPType(NumericTable *resultTable, algorithmFPType p, engines::BatchBase &engine)
{
    const algorithmFPType one  = 1;
    const algorithmFPType zero = 0;
    const size_t nElemsInBlock = 1024;

    size_t nRows = resultTable->getNumberOfRows();
    size_t nCols = resultTable->getNumberOfColumns();

    Status s;

    if(nElemsInBlock > nCols)
    {
        size_t nRowsInBlock = nElemsInBlock / nCols;
        size_t nRowBlocks = nRows / nRowsInBlock;
        nRowBlocks += (nRowBlocks * nRowsInBlock != nRows);

        for(size_t block = 0; block < nRowBlocks; block++) /* blocking by rows */
        {
            size_t nProcessedRows = block * nRowsInBlock;
            size_t nRowsToProcess = (block == nRowBlocks - 1) ? (nRows - nProcessedRows) : nRowsInBlock;

            daal::internal::WriteRows<algorithmFPType, cpu> resultBlock(resultTable, nProcessedRows, nRowsToProcess);
            DAAL_CHECK_BLOCK_STATUS(resultBlock);
            algorithmFPType *resultArray = resultBlock.get();

            size_t nElemsToProcess = nRowsToProcess * nCols;
            DAAL_CHECK_STATUS(s, (UniformKernelDefault<algorithmFPType, cpu>::compute(0.0, 1.0, engine, nElemsToProcess, resultArray)));

            for(size_t j = 0; j < nElemsToProcess; j++)
            {
                resultArray[j] = ((resultArray[j] < p) ? one : zero);
            }
        }
    }
    else
    {
        size_t nColBlocks = nCols / nElemsInBlock;
        nColBlocks += (nColBlocks * nElemsInBlock != nCols);

        for(size_t block = 0; block < nRows; block++) /* blocking by rows */
        {
            daal::internal::WriteRows<algorithmFPType, cpu> resultBlock(resultTable, block, 1);
            DAAL_CHECK_BLOCK_STATUS(resultBlock);
            algorithmFPType *resultArray = resultBlock.get();

            for(size_t colBlock = 0; colBlock < nColBlocks; colBlock++) /* blocking within one column */
            {
                size_t nProcessedElems = nElemsInBlock * colBlock;
                size_t nElemsToProcess = (colBlock == nColBlocks - 1) ? (nCols - nProcessedElems) : nElemsInBlock;

                algorithmFPType *array = resultArray + nProcessedElems;
                DAAL_CHECK_STATUS(s, (UniformKernelDefault<algorithmFPType, cpu>::compute(0.0, 1.0, engine, nElemsToProcess, array)));

                for(size_t j = 0; j < nElemsToProcess; j++)
                {
                    array[j] = ((array[j] < p) ? one : zero);
                }
            }
        }
    }
    return s;
}

template<typename algorithmFPType, Method method, CpuType cpu>
Status BernoulliKernel<algorithmFPType, method, cpu>::compute(algorithmFPType p, engines::BatchBase &engine, NumericTable *resultTable)
{
    NumericTableDictionary *resultDict = resultTable->getDictionary();
    if(resultDict->getFeaturesEqual() == DictionaryIface::equal && resultTable->getDataLayout() == NumericTableIface::aos &&
      (*resultDict)[0].indexType      == data_feature_utils::DAAL_INT32_S)  /* if table is HomogenNT<int> */
    {
        size_t n = resultTable->getNumberOfRows() * resultTable->getNumberOfColumns();
        int *resultArray = ((HomogenNumericTable<int> *)resultTable)->getArray();
        return computeInt(resultArray, n, p, engine);
    }
    else
    {
        return computeFPType(resultTable, p, engine);
    }
    return Status();
}

} // namespace internal
} // namespace bernoulli
} // namespace distributions
} // namespace algorithms
} // namespace daal

#endif
