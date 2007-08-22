// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_FAHRENHEIT_HPP
#define BOOST_UNITS_FAHRENHEIT_HPP

#include <string>

#include <boost/units/absolute.hpp>
#include <boost/units/io.hpp>
#include <boost/units/make_system.hpp>
#include <boost/units/static_constant.hpp>
#include <boost/units/systems/base_units/fahrenheit.hpp>

namespace boost {

namespace units {

namespace fahrenheit {

typedef make_system<fahrenheit_base_unit>::type system;

typedef unit<temperature_dimension,system>   temperature;

BOOST_UNITS_STATIC_CONSTANT(degree,temperature);
BOOST_UNITS_STATIC_CONSTANT(degrees,temperature);

} // namespace fahrenheit

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_FAHRENHEIT_HPP
