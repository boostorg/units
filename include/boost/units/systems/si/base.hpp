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

#include <boost/units/systems/base_units/meter_base_unit.hpp>
#include <boost/units/systems/base_units/kilogram_base_unit.hpp>
#include <boost/units/systems/base_units/second_base_unit.hpp>
#include <boost/units/systems/base_units/ampere_base_unit.hpp>
#include <boost/units/systems/base_units/kelvin_base_unit.hpp>
#include <boost/units/systems/base_units/mole_base_unit.hpp>
#include <boost/units/systems/base_units/candela_base_unit.hpp>
#include <boost/units/systems/base_units/radian_base_unit.hpp>
#include <boost/units/systems/base_units/steradian_base_unit.hpp>

namespace boost {

namespace units { 

namespace SI {

/// placeholder class defining SI unit system
typedef make_system<meter_base_unit, kilogram_base_unit, second_base_unit, ampere_base_unit, kelvin_base_unit, mole_base_unit, candela_base_unit, radian_base_unit, steradian_base_unit>::type system;

/// dimensionless SI unit
typedef unit<dimensionless_type,system>         dimensionless;

} // namespace SI

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_SI_BASE_HPP
