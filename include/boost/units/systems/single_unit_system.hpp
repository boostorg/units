// Boost.Units - A C++ library for zero-overhead dimensional analysis and
// unit/quantity manipulation and conversion
//
// Copyright (C) 2018 Eisuke Kawashima
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_SINGLE_UNIT_SYSTEM_HPP
#define BOOST_UNITS_SINGLE_UNIT_SYSTEM_HPP

/**
\file

\brief single_unit_systems.cpp

\details
Enable to define various non-si units
**/

#include <boost/units/make_system.hpp>

#define BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(namespace_,unit_name_,dimension_)              \
namespace boost {                                                                            \
namespace units {                                                                            \
namespace namespace_ {                                                                       \
typedef make_system<unit_name_ ## _base_unit>::type unit_name_ ## system_;                   \
typedef unit<dimension_ ## _dimension,unit_name_ ## system_> unit_name_ ## _ ## dimension_;  \
static BOOST_CONSTEXPR unit_name_ ## _ ## dimension_ unit_name_;                             \
static BOOST_CONSTEXPR unit_name_ ## _ ## dimension_ unit_name_ ## s;                        \
}                                                                                            \
}                                                                                            \
}

#endif // BOOST_UNITS_SINGLE_UNIT_SYSTEM_HPP
