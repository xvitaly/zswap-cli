#
# SPDX-FileCopyrightText: 2020-2022 EasyCoding Team and contributors
#
# SPDX-License-Identifier: MIT
#

set(Boost_USE_STATIC_LIBS ${LINK_BOOST_STATICALLY})
find_package(Boost 1.65.0 COMPONENTS program_options REQUIRED)
