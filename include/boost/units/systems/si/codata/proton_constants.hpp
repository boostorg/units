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
/// 2014 CODATA recommended values of fundamental atomic and nuclear constants as of 2018/07/21

namespace boost {

namespace units {

namespace si {

namespace constants {

namespace codata {

/// proton mass
BOOST_UNITS_PHYSICAL_CONSTANT(m_p,quantity<mass>,1.672621898e-27*kilograms,2.1e-35*kilograms);
/// proton-electron mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_p_over_m_e,quantity<dimensionless>,1836.15267389*dimensionless(),1.7e-7*dimensionless());
/// proton-muon mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_p_over_m_mu,quantity<dimensionless>,8.88024338*dimensionless(),2.0e-7*dimensionless());
/// proton-tau mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_p_over_m_tau,quantity<dimensionless>,0.528063*dimensionless(),4.8e-5*dimensionless());
/// proton-neutron mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_p_over_m_n,quantity<dimensionless>,0.99862347844*dimensionless(),5.1e-10*dimensionless());
/// proton charge to mass quotient
BOOST_UNITS_PHYSICAL_CONSTANT(e_over_m_p,quantity<electric_charge_over_mass>,9.578833226e7*coulombs/kilogram,5.9e-1*coulombs/kilogram);
/// proton molar mass
BOOST_UNITS_PHYSICAL_CONSTANT(M_p,quantity<mass_over_amount>,1.007276466879e-3*kilograms/mole,9.1e-14*kilograms/mole);
/// proton Compton wavelength
BOOST_UNITS_PHYSICAL_CONSTANT(lambda_C_p,quantity<length>,1.32140985396e-15*meters,6.1e-25*meters);
/// proton rms charge radius
BOOST_UNITS_PHYSICAL_CONSTANT(R_p,quantity<length>,0.8751e-15*meters,6.1e-18*meters);
/// proton magnetic moment
BOOST_UNITS_PHYSICAL_CONSTANT(mu_p,quantity<energy_over_magnetic_flux_density>,1.4106067873e-26*joules/tesla,9.7e-35*joules/tesla);
/// proton-Bohr magneton ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_p_over_mu_B,quantity<dimensionless>,1.5210322053e-3*dimensionless(),4.6e-12*dimensionless());
/// proton-nuclear magneton ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_p_over_mu_N,quantity<dimensionless>,2.7928473508*dimensionless(),8.5e-9*dimensionless());
/// proton g-factor
BOOST_UNITS_PHYSICAL_CONSTANT(g_p,quantity<dimensionless>,5.585694702*dimensionless(),1.7e-8*dimensionless());
/// proton-neutron magnetic moment ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_p_over_mu_n,quantity<dimensionless>,-1.45989805*dimensionless(),3.4e-7*dimensionless());
/// shielded proton magnetic moment
BOOST_UNITS_PHYSICAL_CONSTANT(mu_p_prime,quantity<energy_over_magnetic_flux_density>,1.410570547e-26*joules/tesla,1.8e-34*joules/tesla);
/// shielded proton-Bohr magneton ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_p_prime_over_mu_B,quantity<dimensionless>,1.520993128e-3*dimensionless(),1.7e-11*dimensionless());
/// shielded proton-nuclear magneton ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_p_prime_over_mu_N,quantity<dimensionless>,2.792775600*dimensionless(),3.0e-8*dimensionless());
/// proton magnetic shielding correction
BOOST_UNITS_PHYSICAL_CONSTANT(sigma_p_prime,quantity<dimensionless>,25.691e-6*dimensionless(),1.1e-8*dimensionless());
/// proton gyromagnetic ratio
BOOST_UNITS_PHYSICAL_CONSTANT(gamma_p,quantity<frequency_over_magnetic_flux_density>,2.675221900e8/second/tesla,1.8e0/second/tesla);
/// shielded proton gyromagnetic ratio
BOOST_UNITS_PHYSICAL_CONSTANT(gamma_p_prime,quantity<frequency_over_magnetic_flux_density>,2.675153171e8/second/tesla,3.3e0/second/tesla);

} // namespace codata

} // namespace constants

} // namespace si

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_CODATA_PROTON_CONSTANTS_HPP
