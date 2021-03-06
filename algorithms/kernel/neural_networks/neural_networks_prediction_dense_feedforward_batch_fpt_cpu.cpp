/* file: neural_networks_prediction_dense_feedforward_batch_fpt_cpu.cpp */
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
//  Implementation of neural networks calculation functions.
//--


#include "neural_networks_prediction_batch_container.h"
#include "neural_networks_prediction_feedforward_kernel.h"
#include "neural_networks_prediction_feedforward_impl.i"

namespace daal
{
namespace algorithms
{
namespace neural_networks
{
namespace prediction
{
namespace interface1
{
template class neural_networks::prediction::BatchContainer<DAAL_FPTYPE, feedforwardDense, DAAL_CPU>;
}
namespace internal
{
template class NeuralNetworksFeedforwardPredictionKernel<DAAL_FPTYPE, feedforwardDense, DAAL_CPU>;
}
}
}
}
}
