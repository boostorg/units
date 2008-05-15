// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_CGS_BASE_HPP
#define BOOST_UNITS_CGS_BASE_HPP

#include <string>

#include <boost/units/io.hpp>
#include <boost/units/static_constant.hpp>
#include <boost/units/unit.hpp>
#include <boost/units/make_system.hpp>

#include <boost/units/systems/base_units/centimeter.hpp>
#include <boost/units/systems/base_units/gram.hpp>
#include <boost/units/systems/base_units/second.hpp>

namespace boost {

namespace units { 

namespace CGS {

/// placeholder class defining CGS unit system
typedef make_system<centimeter_base_unit, gram_base_unit, second_base_unit>::type system;

/// various unit typedefs for convenience
typedef unit<dimensionless_type,system>         dimensionless;

} // namespace CGS
                                                    
} // namespace units

} // namespace boost

#endif // BOOST_UNITS_CGS_BASE_HPP
