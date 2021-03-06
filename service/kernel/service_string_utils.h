/* file: service_string_utils.h */
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

#ifndef __KERNEL_SERVICE_STRING_UTILS_H__
#define __KERNEL_SERVICE_STRING_UTILS_H__

#include <cstdio>
#include <cstring>

#include "services/daal_string.h"
#include "service_defines.h"
#include "service_service.h"

namespace daal
{
namespace services
{
namespace internal
{

template<class T>
void toStringBuffer(T number, char *buffer)
{}

template<> void toStringBuffer<int>(int value, char *buffer)
{
#if defined(_WIN32) || defined(_WIN64)
    sprintf_s(buffer, DAAL_MAX_STRING_SIZE, "%d", value);
#else
    snprintf(buffer, DAAL_MAX_STRING_SIZE, "%d", value);
#endif
}

template<> void toStringBuffer<double>(double value, char *buffer)
{
#if defined(_WIN32) || defined(_WIN64)
    sprintf_s(buffer, DAAL_MAX_STRING_SIZE, "%f", value);
#else
    snprintf(buffer, DAAL_MAX_STRING_SIZE, "%f", value);
#endif
}

template<> void toStringBuffer<String>(String value, char *buffer)
{
    daal::internal::Service<>::serv_strncpy_s(buffer, DAAL_MAX_STRING_SIZE, value.c_str(),
                                              DAAL_MAX_STRING_SIZE - value.length() );
}

} // namespace internal
} // namespace services
} // namespace daal

#endif
