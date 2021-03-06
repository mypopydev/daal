/* file: adagrad_dense_default_batch_fpt_cpu.cpp */
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
//  Implementation of adagrad calculation.
//--


#include "adagrad_batch_container.h"
#include "adagrad_dense_default_kernel.h"
#include "adagrad_dense_default_impl.i"

namespace daal
{
namespace algorithms
{
namespace optimization_solver
{
namespace adagrad
{

namespace interface1
{
template class BatchContainer<DAAL_FPTYPE, defaultDense, DAAL_CPU>;
}

namespace internal
{
template class AdagradKernel<DAAL_FPTYPE, defaultDense, DAAL_CPU>;
}

} // namespace adagrad

} // namespace optimization_solver

} // namespace algorithms

} // namespace daal
