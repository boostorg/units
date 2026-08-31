// Boost.Units - A C++ library for zero-overhead dimensional analysis and
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_CODATA_PROTON_CONSTANTS_HPP
#define BOOST_UNITS_CODATA_PROTON_CONSTANTS_HPP

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

/// proton mass
BOOST_UNITS_PHYSICAL_CONSTANT(m_p, quantity<mass>, 1.67262192369e-27*kilograms, 5.1e-37*kilograms);
/// proton-electron mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_p_over_m_e, quantity<dimensionless>, 1836.15267343*dimensionless(), 1.0e-7*dimensionless());
/// proton-muon mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_p_over_m_mu, quantity<dimensionless>, 8.88024337*dimensionless(), 2.0e-7*dimensionless());
/// proton-tau mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_p_over_m_tau, quantity<dimensionless>, 0.528051*dimensionless(), 3.0e-5*dimensionless());
/// proton-neutron mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_p_over_m_n, quantity<dimensionless>, 0.99862347812*dimensionless(), 4.0e-10*dimensionless());
/// proton charge to mass quotient
BOOST_UNITS_PHYSICAL_CONSTANT(e_over_m_p, quantity<electric_charge_over_mass>, 9.5788331560e+7*coulombs/kilogram, 2.9e-2*coulombs/kilogram);
/// proton molar mass
BOOST_UNITS_PHYSICAL_CONSTANT(M_p, quantity<mass_over_amount>, 1.00727646627e-3*kilograms/mole, 3.1e-13*kilograms/mole);
/// proton Compton wavelength
BOOST_UNITS_PHYSICAL_CONSTANT(lambda_C_p, quantity<length>, 1.32140985539e-15*meters, 4.0e-25*meters);
/// proton rms charge radius
BOOST_UNITS_PHYSICAL_CONSTANT(R_p, quantity<length>, 8.414e-16*meters, 1.9e-18*meters);
/// proton magnetic moment
BOOST_UNITS_PHYSICAL_CONSTANT(mu_p, quantity<energy_over_magnetic_flux_density>, 1.41060679736e-26*joules/tesla, 6.0e-36*joules/tesla);
/// proton magnetic moment to Bohr magneton ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_p_over_mu_B, quantity<dimensionless>, 1.52103220230e-3*dimensionless(), 4.6e-13*dimensionless());
/// proton magnetic moment to nuclear magneton ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_p_over_mu_N, quantity<dimensionless>, 2.79284734463*dimensionless(), 8.0e-10*dimensionless());
/// proton g factor
BOOST_UNITS_PHYSICAL_CONSTANT(g_p, quantity<dimensionless>, 5.5856946893*dimensionless(), 1.0e-9*dimensionless());
/// proton-neutron magnetic moment ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_p_over_mu_n, quantity<dimensionless>, -1.45989805*dimensionless(), 3.0e-7*dimensionless());
/// shielded proton magnetic moment
BOOST_UNITS_PHYSICAL_CONSTANT(mu_p_prime, quantity<energy_over_magnetic_flux_density>, 1.410570560e-26*joules/tesla, 1.5e-34*joules/tesla);
/// shielded proton magnetic moment to Bohr magneton ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_p_prime_over_mu_B, quantity<dimensionless>, 1.520993128e-3*dimensionless(), 1.7e-11*dimensionless());
/// shielded proton magnetic moment to nuclear magneton ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_p_prime_over_mu_N, quantity<dimensionless>, 2.792775599*dimensionless(), 3.0e-8*dimensionless());
/// proton magnetic shielding correction
BOOST_UNITS_PHYSICAL_CONSTANT(sigma_p_prime, quantity<dimensionless>, 2.5689e-5*dimensionless(), 1.1e-8*dimensionless());
/// proton gyromagnetic ratio
BOOST_UNITS_PHYSICAL_CONSTANT(gamma_p, quantity<frequency_over_magnetic_flux_density>, 2.6752218744e+8/second/tesla, 1.1e-1/second/tesla);
/// shielded proton gyromagnetic ratio
BOOST_UNITS_PHYSICAL_CONSTANT(gamma_p_prime, quantity<frequency_over_magnetic_flux_density>, 2.675153151e+8/second/tesla, 2.9e0/second/tesla);

} // namespace codata

} // namespace constants

} // namespace si

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_CODATA_PROTON_CONSTANTS_HPP
