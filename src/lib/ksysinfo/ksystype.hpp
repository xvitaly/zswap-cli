/**
 * SPDX-FileCopyrightText: 2020-2023 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: MIT
*/

#ifndef KSYSTYPE_HPP
#define KSYSTYPE_HPP

/** @file ksysinfo/ksystype.hpp
 *  This file works with private Linux kernel types.
 */

#include <linux/types.h>

/**
 *  Namespace with definition of private Linux kernel types.
*/
namespace ksystype {
    /**
     *  Defines long type.
    */
    using long_t = __kernel_long_t;

    /**
     *  Defines unsigned long type.
    */
    using ulong_t = __kernel_ulong_t;

    /**
     *  Defines unsigned short type.
    */
    using ushort_t = __u16;

    /**
     *  Defines unsigned int type.
    */
    using uint_t = __u32;
}

#endif // KSYSTYPE_HPP
