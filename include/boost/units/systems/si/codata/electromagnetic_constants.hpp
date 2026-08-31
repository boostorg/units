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
/// 2018 CODATA recommended values of fundamental electromagnetic constants as of 2019/06/10

namespace boost {

namespace units {

namespace si {

namespace constants {

namespace codata {

// ELECTROMAGNETIC
/// elementary charge
BOOST_UNITS_PHYSICAL_CONSTANT(e, quantity<electric_charge>, 1.602176634e-19*coulombs, 0.0*coulombs);
/// elementary charge over Planck constant @deprecated
BOOST_UNITS_PHYSICAL_CONSTANT(e_over_h, quantity<current_over_energy>, 2.4179892420849181e+14*amperes/joule, 0.0*amperes/joule);
/// magnetic flux quantum
BOOST_UNITS_PHYSICAL_CONSTANT(Phi_0, quantity<magnetic_flux>, 2.067833848461929e-15*webers, 0.0*webers);
/// conductance quantum
BOOST_UNITS_PHYSICAL_CONSTANT(G_0, quantity<conductance>, 7.748091729863650e-5*siemens, 0.0*siemens);
/// Josephson constant
BOOST_UNITS_PHYSICAL_CONSTANT(K_J, quantity<frequency_over_electric_potential>, 4.835978484169836e+14*hertz/volt, 0.0*hertz/volt);
/// von Klitzing constant
BOOST_UNITS_PHYSICAL_CONSTANT(R_K, quantity<resistance>, 25812.80745930451*ohms, 0.0*ohms);
/// Bohr magneton
BOOST_UNITS_PHYSICAL_CONSTANT(mu_B, quantity<energy_over_magnetic_flux_density>, 9.2740100783e-24*joules/tesla, 2.8e-33*joules/tesla);
/// nuclear magneton
BOOST_UNITS_PHYSICAL_CONSTANT(mu_N, quantity<energy_over_magnetic_flux_density>, 5.0507837461e-27*joules/tesla, 1.5e-36*joules/tesla);

} // namespace codata

} // namespace constants

} // namespace si

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_CODATA_ELECTROMAGNETIC_CONSTANTS_HPP
