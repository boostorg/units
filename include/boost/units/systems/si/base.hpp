// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_SI_BASE_HPP
#define BOOST_UNITS_SI_BASE_HPP

#include <string>

#include <boost/units/io.hpp>
#include <boost/units/static_constant.hpp>
#include <boost/units/unit.hpp>
#include <boost/units/make_system.hpp>
#include <boost/units/systems/physical_units.hpp>
#include <boost/units/systems/base_units.hpp>

namespace boost {

namespace units { 

namespace SI {

/// placeholder class defining SI unit system
typedef make_system<meter_tag, kilogram_tag, second_tag, ampere_tag, kelvin_tag, mole_tag, candela_tag, radian_tag, steradian_tag>::type system;

/// dimensionless SI unit
typedef unit<dimensionless_type,system>         dimensionless;

} // namespace SI

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_SI_BASE_HPP
