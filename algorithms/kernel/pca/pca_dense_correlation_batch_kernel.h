/* file: pca_dense_correlation_batch_kernel.h */
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

/*
//++
//  Declaration of template structs that calculate PCA Correlation.
//--
*/

#ifndef __PCA_DENSE_CORRELATION_BATCH_KERNEL_H__
#define __PCA_DENSE_CORRELATION_BATCH_KERNEL_H__

#include "pca_types.h"
#include "service_defines.h"
#include "services/error_handling.h"
#include "pca_dense_correlation_base.h"

namespace daal
{
namespace algorithms
{
namespace pca
{
namespace internal
{
template <typename algorithmFPType, CpuType cpu>
class PCACorrelationKernel<batch, algorithmFPType, cpu> : public PCACorrelationBase<algorithmFPType, cpu>
{
public:
    explicit PCACorrelationKernel() {};
    services::Status compute(bool isCorrelation,
                             const data_management::NumericTable& dataTable,
                             covariance::BatchImpl* covarianceAlg,
                             data_management::NumericTable& eigenvectors,
                             data_management::NumericTable& eigenvalues);

    services::Status compute(bool isCorrelation,
                             bool isDeterministic,
                             const data_management::NumericTable& dataTable,
                             covariance::BatchImpl* covarianceAlg,
                             DAAL_UINT64 resultsToCompute,
                             data_management::NumericTable& eigenvectors,
                             data_management::NumericTable& eigenvalues,
                             data_management::NumericTable& means,
                             data_management::NumericTable& variances);

};

} // namespace internal
} // namespace pca
} // namespace algorithms
} // namespace daal

#endif
