// Boost.Units - A C++ library for zero-overhead dimensional analysis and
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_CODATA_DEUTERON_CONSTANTS_HPP
#define BOOST_UNITS_CODATA_DEUTERON_CONSTANTS_HPP

#include <boost/units/quantity.hpp>
#include <boost/units/static_constant.hpp>

#include <boost/units/systems/detail/constants.hpp>
#include <boost/units/systems/si/amount.hpp>
#include <boost/units/systems/si/area.hpp>
#include <boost/units/systems/si/electric_charge.hpp>
#include <boost/units/systems/si/energy.hpp>
#include <boost/units/systems/si/frequency.hpp>
#include <boost/units/systems/si/length.hpp>
#include <boost/units/systems/si/mass.hpp>
#include <boost/units/systems/si/magnetic_flux_density.hpp>
#include <boost/units/systems/si/time.hpp>
#include <boost/units/systems/si/wavenumber.hpp>

#include <boost/units/systems/si/codata/typedefs.hpp>

/// \file
/// 2018 CODATA recommended values of fundamental atomic and nuclear constants as of 2019/06/10

namespace boost {

namespace units {

namespace si {

namespace constants {

namespace codata {

/// deuteron mass
BOOST_UNITS_PHYSICAL_CONSTANT(m_d, quantity<mass>, 3.3435837724e-27*kilograms, 1.0e-36*kilograms);
/// deuteron-electron mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_d_over_m_e, quantity<dimensionless>, 3670.48296788*dimensionless(), 1.0e-7*dimensionless());
/// deuteron-proton mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_d_over_m_p, quantity<dimensionless>, 1.99900750139*dimensionless(), 1.0e-10*dimensionless());
/// deuteron molar mass
BOOST_UNITS_PHYSICAL_CONSTANT(M_d, quantity<mass_over_amount>, 2.01355321205e-3*kilograms/mole, 6.1e-13*kilograms/mole);
/// deuteron rms charge radius
BOOST_UNITS_PHYSICAL_CONSTANT(R_d, quantity<length>, 2.12799e-15*meters, 7.4e-19*meters);
/// deuteron magnetic moment
BOOST_UNITS_PHYSICAL_CONSTANT(mu_d, quantity<energy_over_magnetic_flux_density>, 4.330735094e-27*joules/tesla, 1.1e-35*joules/tesla);
/// deuteron magnetic moment to Bohr magneton ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_d_over_mu_B, quantity<dimensionless>, 4.669754570e-4*dimensionless(), 1.2e-12*dimensionless());
/// deuteron magnetic moment to nuclear magneton ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_d_over_mu_N, quantity<dimensionless>, 0.8574382338*dimensionless(), 2.0e-9*dimensionless());
/// deuteron g factor
BOOST_UNITS_PHYSICAL_CONSTANT(g_d, quantity<dimensionless>, 0.8574382338*dimensionless(), 2.0e-9*dimensionless());
/// deuteron-electron magnetic moment ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_d_over_mu_e, quantity<dimensionless>, -4.664345551e-4*dimensionless(), 1.2e-12*dimensionless());
/// deuteron-proton magnetic moment ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_d_over_mu_p, quantity<dimensionless>, 0.30701220939*dimensionless(), 7.0e-10*dimensionless());
/// deuteron-neutron magnetic moment ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_d_over_mu_n, quantity<dimensionless>, -0.44820653*dimensionless(), 1.0e-7*dimensionless());

} // namespace codata

} // namespace constants

} // namespace si

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_CODATA_DEUTERON_CONSTANTS_HPP
