// Boost.Units - A C++ library for zero-overhead dimensional analysis and
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_CODATA_UNIVERSAL_CONSTANTS_HPP
#define BOOST_UNITS_CODATA_UNIVERSAL_CONSTANTS_HPP

#include <boost/units/quantity.hpp>
#include <boost/units/static_constant.hpp>

#include <boost/units/systems/detail/constants.hpp>
#include <boost/units/systems/si/capacitance.hpp>
#include <boost/units/systems/si/current.hpp>
#include <boost/units/systems/si/energy.hpp>
#include <boost/units/systems/si/force.hpp>
#include <boost/units/systems/si/length.hpp>
#include <boost/units/systems/si/mass.hpp>
#include <boost/units/systems/si/resistance.hpp>
#include <boost/units/systems/si/temperature.hpp>
#include <boost/units/systems/si/time.hpp>
#include <boost/units/systems/si/velocity.hpp>
#include <boost/units/systems/si/volume.hpp>
#include <boost/units/systems/si/codata/typedefs.hpp>

/// \file
/// 2018 CODATA recommended values of fundamental universal constants as of 2019/06/10

namespace boost {

namespace units {

namespace si {

namespace constants {

namespace codata {

// UNIVERSAL
/// speed of light in vacuum
BOOST_UNITS_PHYSICAL_CONSTANT(c, quantity<velocity>, 299792458.0*meters/second, 0.0*meters/second);
/// vacuum magnetic permeability
BOOST_UNITS_PHYSICAL_CONSTANT(mu_0, quantity<force_over_current_squared>, 1.25663706212e-6*newtons/ampere/ampere, 1.9e-16*newtons/ampere/ampere);
/// vacuum electric permittivity
BOOST_UNITS_PHYSICAL_CONSTANT(epsilon_0, quantity<capacitance_over_length>, 8.8541878128e-12*farad/meter, 1.3e-21*farad/meter);
/// characteristic impedance of vacuum @deprecated
BOOST_UNITS_PHYSICAL_CONSTANT(Z_0, quantity<resistance>, 376.73031367*ohm, 5.7e-8*ohm);
/// Newtonian constant of gravitation
BOOST_UNITS_PHYSICAL_CONSTANT(G, quantity<volume_over_mass_time_squared>, 6.67430e-11*cubic_meters/kilogram/second/second, 1.5e-15*cubic_meters/kilogram/second/second);
/// Planck constant
BOOST_UNITS_PHYSICAL_CONSTANT(h, quantity<energy_time>, 6.62607015e-34*joule*seconds, 0.0*joule*seconds);
/// reduced Planck constant; Dirac constant
BOOST_UNITS_PHYSICAL_CONSTANT(hbar, quantity<energy_time>, 1.054571817646156e-34*joule*seconds, 0.0*joule*seconds);
/// Planck mass
BOOST_UNITS_PHYSICAL_CONSTANT(m_P, quantity<mass>, 2.176434e-8*kilograms, 2.4e-13*kilograms);
/// Planck temperature
BOOST_UNITS_PHYSICAL_CONSTANT(T_P, quantity<temperature>, 1.416784e+32*kelvin, 1.6e+27*kelvin);
/// Planck length
BOOST_UNITS_PHYSICAL_CONSTANT(l_P, quantity<length>, 1.616255e-35*meters, 1.8e-40*meters);
/// Planck time
BOOST_UNITS_PHYSICAL_CONSTANT(t_P, quantity<time>, 5.391247e-44*seconds, 6.0e-49*seconds);

} // namespace codata

} // namespace constants

} // namespace si

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_CODATA_UNIVERSAL_CONSTANTS_HPP
