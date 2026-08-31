// Boost.Units - A C++ library for zero-overhead dimensional analysis and
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_CODATA_ELECTROMAGNETIC_CONSTANTS_HPP
#define BOOST_UNITS_CODATA_ELECTROMAGNETIC_CONSTANTS_HPP

#include <boost/units/quantity.hpp>
#include <boost/units/static_constant.hpp>

#include <boost/units/systems/detail/constants.hpp>
#include <boost/units/systems/si/conductance.hpp>
#include <boost/units/systems/si/current.hpp>
#include <boost/units/systems/si/electric_charge.hpp>
#include <boost/units/systems/si/electric_potential.hpp>
#include <boost/units/systems/si/energy.hpp>
#include <boost/units/systems/si/frequency.hpp>
#include <boost/units/systems/si/magnetic_flux.hpp>
#include <boost/units/systems/si/magnetic_flux_density.hpp>
#include <boost/units/systems/si/resistance.hpp>

#include <boost/units/systems/si/codata/typedefs.hpp>

/// \file
/// 2014 CODATA recommended values of fundamental electromagnetic constants as of 2018/07/21

namespace boost {

namespace units {

namespace si {

namespace constants {

namespace codata {

// ELECTROMAGNETIC
/// elementary charge
BOOST_UNITS_PHYSICAL_CONSTANT(e,quantity<electric_charge>,1.6021766208e-19*coulombs,9.8e-28*coulombs);
/// elementary charge over Planck constant
BOOST_UNITS_PHYSICAL_CONSTANT(e_over_h,quantity<current_over_energy>,2.417989262e14*amperes/joule,1.5e6*amperes/joule);
/// magnetic flux quantum
BOOST_UNITS_PHYSICAL_CONSTANT(Phi_0,quantity<magnetic_flux>,2.067833831e-15*webers,1.3e-23*webers);
/// conductance quantum
BOOST_UNITS_PHYSICAL_CONSTANT(G_0,quantity<conductance>,7.7480917310e-5*siemens,1.8e-14*siemens);
/// Josephson constant
BOOST_UNITS_PHYSICAL_CONSTANT(K_J,quantity<frequency_over_electric_potential>,483597.8525e9*hertz/volt,3.0e6*hertz/volt);
/// von Klitzing constant
BOOST_UNITS_PHYSICAL_CONSTANT(R_K,quantity<resistance>,25812.8074555*ohms,5.9e-6*ohms);
/// Bohr magneton
BOOST_UNITS_PHYSICAL_CONSTANT(mu_B,quantity<energy_over_magnetic_flux_density>,927.4009994e-26*joules/tesla,5.7e-32*joules/tesla);
/// nuclear magneton
BOOST_UNITS_PHYSICAL_CONSTANT(mu_N,quantity<energy_over_magnetic_flux_density>,5.050783699e-27*joules/tesla,3.1e-35*joules/tesla);

} // namespace codata

} // namespace constants

} // namespace si

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_CODATA_ELECTROMAGNETIC_CONSTANTS_HPP
