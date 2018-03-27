/* file: eltwise_sum_layer_forward_fpt.cpp */
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
//  Implementation of element-wise sum calculation algorithm and types methods.
//--
*/

#include "eltwise_sum_layer_forward_types.h"
#include "eltwise_sum_layer_types.h"

namespace daal
{
namespace algorithms
{
namespace neural_networks
{
namespace layers
{
namespace eltwise_sum
{
namespace forward
{
namespace interface1
{

using namespace daal::data_management;

/**
 * Allocates memory to store the result of forward  element-wise sum layer
 * \param[in] input     %Input object for the algorithm
 * \param[in] parameter %Parameter of forward element-wise sum layer
 * \param[in] method    Computation method for the layer
 */
template <typename algorithmFPType>
DAAL_EXPORT services::Status Result::allocate(const daal::algorithms::Input *input,
                                              const daal::algorithms::Parameter *parameter,
                                              const int method)
{
    services::Status s;
    const Input *eltwiseInput = dynamic_cast<const Input *>(input);
    DAAL_CHECK(eltwiseInput, services::ErrorNullInput);
    DAAL_CHECK_STATUS(s, eltwiseInput->check(parameter, method));
    DAAL_CHECK_STATUS(s, allocateValueTensor<algorithmFPType>(eltwiseInput));

    // We call this function just to allocate
    // resultLayerData and consciously ignore returned value
    LayerDataPtr resultLayerData = getResultLayerDataAllocateIfEmpty();
    DAAL_CHECK_MALLOC(resultLayerData);

    return setResultForBackward(input);
}

template<typename algorithmFPType>
services::Status Result::allocateValueTensor(const Input *eltwiseInput)
{
    TensorPtr firstInput = eltwiseInput->get(layers::forward::inputLayerData, 0);
    services::Status s;
    TensorPtr value = HomogenTensor<algorithmFPType>::create(firstInput->getDimensions(), Tensor::doAllocate, &s);
    DAAL_CHECK_MALLOC(value);

    set(layers::forward::value, value);

    return s;
}

template DAAL_EXPORT services::Status Result::allocate<DAAL_FPTYPE>(
    const daal::algorithms::Input *, const daal::algorithms::Parameter *, const int);

template DAAL_EXPORT services::Status Result::allocateValueTensor<DAAL_FPTYPE>(const Input *);

}// namespace interface1
}// namespace forward
}// namespace eltwise_sum
}// namespace layers
}// namespace neural_networks
}// namespace algorithms
}// namespace daal
