/*
 * Copyright (c) 2018 Particle Industries, Inc.  All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */

#ifndef USBD_WCID_H_
#define USBD_WCID_H_

#define USB_WCID_DATA(...) __VA_ARGS__

#define USB_WCID_MS_OS_STRING_DESCRIPTOR(signature, code)                   \
    signature,                                     /* qwSignature */        \
    code,                                          /* MS_VendorCode */      \
    0x00                                           /* Padding */

#define USB_WCID_EXT_COMPAT_ID_OS_DESCRIPTOR(intf, cid, sid)                    \
    0x28, 0x00, 0x00, 0x00,                        /* dwLength */               \
    0x00, 0x01,                                    /* bcdVersion */             \
    0x04, 0x00,                                    /* wIndex */                 \
    0x01,                                          /* bCount */                 \
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,      /* Reserved */               \
    intf,                                          /* bFirstInterfaceNumber */  \
    0x01,                                          /* Reserved */               \
    cid,                                           /* compatibleID */           \
    sid,                                           /* subCompatibleID */        \
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00             /* Reserved */

#define USB_WCID_EXT_PROP_OS_DESCRIPTOR(guid)                                   \
    0x92, 0x00, 0x00, 0x00,                        /* dwLength */               \
    0x00, 0x01,                                    /* bcdVersion */             \
    0x05, 0x00,                                    /* wIndex */                 \
    0x01, 0x00,                                    /* wCount */                 \
    0x88, 0x00, 0x00, 0x00,                        /* dwSize */                 \
    0x07, 0x00, 0x00, 0x00,                        /* dwPropertyDataType */     \
    0x2a, 0x00,                                    /* wPropertyNameLength */    \
    'D', 0x00, 'e', 0x00, 'v', 0x00, 'i', 0x00,    /* bPropertyName */          \
    'c', 0x00, 'e', 0x00, 'I', 0x00, 'n', 0x00,    /* "DeviceInterfaceGUID" */  \
    't', 0x00, 'e', 0x00, 'r', 0x00, 'f', 0x00,                                 \
    'a', 0x00, 'c', 0x00, 'e', 0x00, 'G', 0x00,                                 \
    'U', 0x00, 'I', 0x00, 'D', 0x00, 's', 0x00,                                 \
    0x00, 0x00,                                                                 \
    0x50, 0x00, 0x00, 0x00,                        /* dwPropertyDataLength */   \
    guid, 0x00, 0x00, 0x00, 0x00, 0x00             /* bPropertyData */          \

#endif // USBD_WCID_H_
