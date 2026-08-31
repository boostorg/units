// Boost.Units - A C++ library for zero-overhead dimensional analysis and
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_CODATA_ELECTRON_CONSTANTS_HPP
#define BOOST_UNITS_CODATA_ELECTRON_CONSTANTS_HPP

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

/// electron mass
BOOST_UNITS_PHYSICAL_CONSTANT(m_e, quantity<mass>, 9.1093837015e-31*kilograms, 2.8e-40*kilograms);
/// electron-muon mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_e_over_m_mu, quantity<dimensionless>, 4.83633169e-3*dimensionless(), 1.1e-10*dimensionless());
/// electron-tau mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_e_over_m_tau, quantity<dimensionless>, 2.87585e-4*dimensionless(), 1.9e-8*dimensionless());
/// electron-proton mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_e_over_m_p, quantity<dimensionless>, 5.44617021487e-4*dimensionless(), 3.3e-14*dimensionless());
/// electron-neutron mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_e_over_m_n, quantity<dimensionless>, 5.4386734424e-4*dimensionless(), 2.6e-13*dimensionless());
/// electron-deuteron mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_e_over_m_d, quantity<dimensionless>, 2.724437107462e-4*dimensionless(), 9.6e-15*dimensionless());
/// electron to alpha particle mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_e_over_m_alpha, quantity<dimensionless>, 1.370933554787e-4*dimensionless(), 4.5e-15*dimensionless());
/// electron charge to mass quotient
BOOST_UNITS_PHYSICAL_CONSTANT(e_over_m_e, quantity<electric_charge_over_mass>, -1.75882001076e+11*coulombs/kilogram, 5.3e+1*coulombs/kilogram);
/// electron molar mass
BOOST_UNITS_PHYSICAL_CONSTANT(M_e, quantity<mass_over_amount>, 5.4857990888e-7*kilograms/mole, 1.7e-16*kilograms/mole);
/// Compton wavelength
BOOST_UNITS_PHYSICAL_CONSTANT(lambda_C, quantity<length>, 2.42631023867e-12*meters, 7.3e-22*meters);
/// classical electron radius
BOOST_UNITS_PHYSICAL_CONSTANT(r_e, quantity<length>, 2.8179403262e-15*meters, 1.3e-24*meters);
/// Thompson cross section
BOOST_UNITS_PHYSICAL_CONSTANT(sigma_e, quantity<area>, 6.6524587321e-29*square_meters, 6.0e-38*square_meters);
/// electron magnetic moment
BOOST_UNITS_PHYSICAL_CONSTANT(mu_e, quantity<energy_over_magnetic_flux_density>, -9.2847647043e-24*joules/tesla, 2.8e-33*joules/tesla);
/// electron magnetic moment to Bohr magneton ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_e_over_mu_B, quantity<dimensionless>, -1.00115965218128*dimensionless(), 1.0e-13*dimensionless());
/// electron magnetic moment to nuclear magneton ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_e_over_mu_N, quantity<dimensionless>, -1838.28197188*dimensionless(), 1.0e-7*dimensionless());
/// electron magnetic moment anomaly
BOOST_UNITS_PHYSICAL_CONSTANT(a_e, quantity<dimensionless>, 1.15965218128e-3*dimensionless(), 1.8e-13*dimensionless());
/// electron g factor
BOOST_UNITS_PHYSICAL_CONSTANT(g_e, quantity<dimensionless>, -2.00231930436256*dimensionless(), 3.0e-13*dimensionless());
/// electron-muon magnetic moment ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_e_over_mu_mu, quantity<dimensionless>, 206.7669883*dimensionless(), 4.0e-6*dimensionless());
/// electron-proton magnetic moment ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_e_over_mu_p, quantity<dimensionless>, -658.21068789*dimensionless(), 2.0e-7*dimensionless());
/// electron to shielded proton magnetic moment ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_e_over_mu_p_prime, quantity<dimensionless>, -658.2275971*dimensionless(), 7.0e-6*dimensionless());
/// electron-neutron magnetic moment ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_e_over_mu_n, quantity<dimensionless>, 960.92050*dimensionless(), 2.0e-4*dimensionless());
/// electron-deuteron magnetic moment ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_e_over_mu_d, quantity<dimensionless>, -2143.9234915*dimensionless(), 5.0e-6*dimensionless());
/// electron to shielded helion magnetic moment ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_e_over_mu_h_prime, quantity<dimensionless>, 864.058257*dimensionless(), 1.0e-5*dimensionless());
/// electron gyromagnetic ratio
BOOST_UNITS_PHYSICAL_CONSTANT(gamma_e, quantity<frequency_over_magnetic_flux_density>, 1.76085963023e+11/second/tesla, 5.3e+1/second/tesla);

} // namespace codata

} // namespace constants

} // namespace si

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_CODATA_ELECTRON_CONSTANTS_HPP
