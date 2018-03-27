/* file: service_thread_pinner.h */
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
//  Implementation of thread pinner class
//--
*/

#ifndef __SERVICE_THREAD_PINNER_H__
#define __SERVICE_THREAD_PINNER_H__

#include "daal_defines.h"
#if !defined (DAAL_THREAD_PINNING_DISABLED)

#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

namespace daal
{
namespace services
{
namespace internal
{

class thread_pinner_task_t
{
public:
    virtual void operator()() = 0;
};

}
}
}

extern "C" {
    DAAL_EXPORT void _thread_pinner_thread_pinner_init(void(int&, int&, int&, int**), void (*deleter)(void*));
    DAAL_EXPORT void _thread_pinner_read_topology();
    DAAL_EXPORT void _thread_pinner_on_scheduler_entry(bool);
    DAAL_EXPORT void _thread_pinner_on_scheduler_exit(bool);
    DAAL_EXPORT void _thread_pinner_execute(daal::services::internal::thread_pinner_task_t& task);

    DAAL_EXPORT int  _thread_pinner_get_status();
    DAAL_EXPORT bool _thread_pinner_get_pinning();
    DAAL_EXPORT bool _thread_pinner_set_pinning(bool p);

    DAAL_EXPORT void* _getThreadPinner(bool create_pinner, void(int&, int&, int&, int**), void (*deleter)(void*));
}

namespace daal
{
namespace services
{
namespace internal
{

class thread_pinner_t
{
public:

    thread_pinner_t(void (*f)(int&, int&, int&, int**), void (*deleter)(void*))
    {
        _thread_pinner_thread_pinner_init(f, deleter);
    }
    void read_topology()
    {
        _thread_pinner_read_topology();
    }
    void on_scheduler_entry( bool p)
    {
        _thread_pinner_on_scheduler_entry(p);
    }
    void on_scheduler_exit( bool p)
    {
        _thread_pinner_on_scheduler_exit(p);
    }
    void execute(thread_pinner_task_t& task)
    {
        _thread_pinner_execute(task);
    }
    int  get_status()
    {
        return _thread_pinner_get_status();
    }
    bool get_pinning()
    {
        return _thread_pinner_get_pinning();
    }
    bool set_pinning(bool p)
    {
        return _thread_pinner_set_pinning(p);
    }
};

inline thread_pinner_t* getThreadPinner(bool create_pinner, void (*read_topo)(int&, int&, int&, int**), void (*deleter)(void*))
{
    return (thread_pinner_t*) _getThreadPinner(create_pinner, read_topo, deleter);
}

}
}
}

#endif /* #if !defined (DAAL_THREAD_PINNING_DISABLED) */
#endif /* #ifndef __SERVICE_THREAD_PINNER_H__ */
