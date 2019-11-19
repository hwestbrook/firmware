/**
   Copyright (c) 2013-2016 Particle Industries, Inc.  All rights reserved.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation, either
   version 3 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, see <http://www.gnu.org/licenses/>.
 ******************************************************************************
 */

#include "hal_platform_nrf52840_config.h"
#include "user_hal.h"


#define CAT2(a,b) a##b
#define CAT(a,b) CAT2(a,b)

#define USER_IMAGE CAT(user_platform_, CAT(PLATFORM_ID,_bin))
#define USER_IMAGE_LEN CAT(user_platform_, CAT(PLATFORM_ID,_bin_len))


#ifdef __cplusplus
extern "C" {
#endif

extern const unsigned int USER_IMAGE_LEN;
extern const unsigned char USER_IMAGE[];

#ifdef __cplusplus
}
#endif


const uint8_t* HAL_User_Image(uint32_t* size, void* reserved)
{
#if defined(INCLUDE_APP)
    if (size)
        *size = (uint32_t)USER_IMAGE_LEN;
    return (const uint8_t*)USER_IMAGE;
#else
    return (const uint8_t*)0;
#endif // INCLUDE_APP
}
