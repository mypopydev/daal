/* file: zscore_dense_default_kernel_fpt_cpu.cpp */
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

//++
//  Implementation of zscore normalization calculation functions.
//
//--


#include "zscore_base.h"
#include "zscore_dense_default_kernel.h"
#include "zscore_impl.i"
#include "zscore_dense_default_impl.i"

namespace daal
{
namespace algorithms
{
namespace normalization
{
namespace zscore
{

namespace internal
{
template class ZScoreKernel<DAAL_FPTYPE, defaultDense, DAAL_CPU>;
}

} // namespace zscore
} // namespace normalization
} // namespace algorithms
} // namespace daal
