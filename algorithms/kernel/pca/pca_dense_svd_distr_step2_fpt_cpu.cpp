/* file: pca_dense_svd_distr_step2_fpt_cpu.cpp */
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
//  Implementation of PCA calculation functions.
//--

#include "pca_dense_svd_distr_step2_container.h"
#include "pca_dense_svd_distr_step2_kernel.h"
#include "pca_dense_svd_distr_step2_impl.i"

namespace daal
{
namespace algorithms
{
namespace pca
{
namespace interface1
{
template class DistributedContainer<step2Master, DAAL_FPTYPE, svdDense, DAAL_CPU>;
}
namespace internal
{
template class PCASVDStep2MasterKernel<DAAL_FPTYPE, DAAL_CPU>;
}
}
}
}
