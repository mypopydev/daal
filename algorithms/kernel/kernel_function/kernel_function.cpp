/* file: kernel_function.cpp */
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
//  Implementation of kernel function algorithm and types methods.
//--
*/

#include "kernel_function_types.h"
#include "serialization_utils.h"
#include "daal_strings.h"

using namespace daal::data_management;
using namespace daal::services;

namespace daal
{
namespace algorithms
{
namespace kernel_function
{
namespace interface1
{
__DAAL_REGISTER_SERIALIZATION_CLASS(Result, SERIALIZATION_KERNEL_FUNCTION_RESULT_ID);

ParameterBase::ParameterBase(size_t rowIndexX, size_t rowIndexY, size_t rowIndexResult, ComputationMode computationMode) :
    rowIndexX(rowIndexX), rowIndexY(rowIndexY), rowIndexResult(rowIndexResult), computationMode(computationMode) {}

Input::Input() : daal::algorithms::Input(lastInputId + 1) {}
Input::Input(const Input& other) : daal::algorithms::Input(other){}

/**
* Returns the input object of the kernel function algorithm
* \param[in] id    Identifier of the input object
* \return          %Input object that corresponds to the given identifier
*/
NumericTablePtr Input::get(InputId id) const
{
    return staticPointerCast<NumericTable, SerializationIface>(Argument::get(id));
}

/**
* Sets the input object of the kernel function algorithm
* \param[in] id    Identifier of the input object
* \param[in] ptr   Pointer to the input object
*/
void Input::set(InputId id, const NumericTablePtr &ptr)
{
    Argument::set(id, ptr);
}

Status Input::checkCSR() const
{
    Status s;
    const int csrLayout = (int)NumericTableIface::csrArray;

    DAAL_CHECK_STATUS(s, checkNumericTable(get(X).get(), XStr(), 0, csrLayout));

    const size_t nFeaturesX = get(X)->getNumberOfColumns();

    return checkNumericTable(get(Y).get(), YStr(), 0, csrLayout, nFeaturesX);
}

Status Input::checkDense() const
{
    Status s;
    DAAL_CHECK_STATUS(s, checkNumericTable(get(X).get(), XStr()));

    const size_t nFeaturesX = get(X)->getNumberOfColumns();

    return checkNumericTable(get(Y).get(), YStr(), 0, 0, nFeaturesX);
}
/**
 * Returns the result of the kernel function algorithm
 * \param[in] id   Identifier of the result
 * \return         Final result that corresponds to the given identifier
 */
NumericTablePtr Result::get(ResultId id) const
{
    return staticPointerCast<NumericTable, SerializationIface>(Argument::get(id));
}

/**
 * Sets the result of the kernel function algorithm
 * \param[in] id    Identifier of the partial result
 * \param[in] ptr   Pointer to the object
 */
void Result::set(ResultId id, const NumericTablePtr &ptr)
{
    Argument::set(id, ptr);
}

/**
* Checks the result of the kernel function algorithm
* \param[in] input   %Input objects of the algorithm
* \param[in] par     %Parameter of the algorithm
* \param[in] method  Computation method of the algorithm
*/
Status Result::check(const daal::algorithms::Input *input, const daal::algorithms::Parameter *par, int method) const
{
    Status s;
    Input *algInput = static_cast<Input *>(const_cast<daal::algorithms::Input *>(input));
    ParameterBase *algParameter = static_cast<ParameterBase *>(const_cast<daal::algorithms::Parameter *>(par));

    const size_t nRowsX = algInput->get(X)->getNumberOfRows();
    const size_t nRowsY = algInput->get(Y)->getNumberOfRows();

    const int unexpectedLayouts = packed_mask;
    DAAL_CHECK_STATUS(s, checkNumericTable(get(values).get(), valuesStr(), unexpectedLayouts, 0, 0, nRowsX));

    const size_t nVectorsValues = get(values)->getNumberOfRows();

    if(algParameter->rowIndexResult >= nVectorsValues)
    {
        return Status(Error::create(ErrorIncorrectParameter, ParameterName, rowIndexResultStr()));
    }
    if(algParameter->rowIndexX >= nRowsX)
    {
        return Status(Error::create(ErrorIncorrectParameter, ParameterName, rowIndexXStr()));
    }
    if(algParameter->rowIndexY >= nRowsY)
    {
        return Status(Error::create(ErrorIncorrectParameter, ParameterName, rowIndexYStr()));
    }
    return s;
}

}// namespace interface1
}// namespace kernel_function
}// namespace algorithms
}// namespace daal
