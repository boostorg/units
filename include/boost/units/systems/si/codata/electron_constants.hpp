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
/// 2014 CODATA recommended values of fundamental atomic and nuclear constants as of 2018/07/21

namespace boost {

namespace units {

namespace si {

namespace constants {

namespace codata {

/// electron mass
BOOST_UNITS_PHYSICAL_CONSTANT(m_e,quantity<mass>,9.10938356e-31*kilograms,1.1e-38*kilograms);
/// electron-muon mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_e_over_m_mu,quantity<dimensionless>,4.83633170e-3*dimensionless(),1.1e-10*dimensionless());
/// electron-tau mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_e_over_m_tau,quantity<dimensionless>,2.87592e-4*dimensionless(),2.6e-8*dimensionless());
/// electron-proton mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_e_over_m_p,quantity<dimensionless>,5.44617021352e-4*dimensionless(),5.2e-14*dimensionless());
/// electron-neutron mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_e_over_m_n,quantity<dimensionless>,5.4386734428e-4*dimensionless(),2.7e-13*dimensionless());
/// electron-deuteron mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_e_over_m_d,quantity<dimensionless>,2.724437107484e-4*dimensionless(),9.6e-15*dimensionless());
/// electron-alpha particle mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_e_over_m_alpha,quantity<dimensionless>,1.370933554798e-4*dimensionless(),4.5e-15*dimensionless());
/// electron charge to mass quotient
BOOST_UNITS_PHYSICAL_CONSTANT(e_over_m_e,quantity<electric_charge_over_mass>,1.758820024e11*coulombs/kilogram,1.1e3*coulombs/kilogram);
/// electron molar mass
BOOST_UNITS_PHYSICAL_CONSTANT(M_e,quantity<mass_over_amount>,5.48579909070e-7*kilograms/mole,1.6e-17*kilograms/mole);
/// Compton wavelength
BOOST_UNITS_PHYSICAL_CONSTANT(lambda_C,quantity<length>,2.4263102367e-12*meters,1.1e-21*meters);
/// classical electron radius
BOOST_UNITS_PHYSICAL_CONSTANT(r_e,quantity<length>,2.8179403227e-15*meters,1.9e-24*meters);
/// Thompson cross section
BOOST_UNITS_PHYSICAL_CONSTANT(sigma_e,quantity<area>,0.66524587158e-28*square_meters,9.1e-38*square_meters);
/// electron magnetic moment
BOOST_UNITS_PHYSICAL_CONSTANT(mu_e,quantity<energy_over_magnetic_flux_density>,-928.4764620e-26*joules/tesla,5.7e-32*joules/tesla);
/// electron-Bohr magenton moment ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_e_over_mu_B,quantity<dimensionless>,-1.00115965218091*dimensionless(),2.6e-13*dimensionless());
/// electron-nuclear magneton moment ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_e_over_mu_N,quantity<dimensionless>,-1838.28197234*dimensionless(),1.7e-7*dimensionless());
/// electron magnetic moment anomaly
BOOST_UNITS_PHYSICAL_CONSTANT(a_e,quantity<dimensionless>,1.15965218091e-3*dimensionless(),2.6e-13*dimensionless());
/// electron g-factor
BOOST_UNITS_PHYSICAL_CONSTANT(g_e,quantity<dimensionless>,-2.00231930436182*dimensionless(),5.2e-13*dimensionless());
/// electron-muon magnetic moment ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_e_over_mu_mu,quantity<dimensionless>,206.7669880*dimensionless(),4.6e-6*dimensionless());
/// electron-proton magnetic moment ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_e_over_mu_p,quantity<dimensionless>,-658.2106866*dimensionless(),2.0e-6*dimensionless());
/// electron-shielded proton magnetic moment ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_e_over_mu_p_prime,quantity<dimensionless>,-658.2275971*dimensionless(),7.2e-6*dimensionless());
/// electron-neutron magnetic moment ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_e_over_mu_n,quantity<dimensionless>,960.92050*dimensionless(),2.3e-4*dimensionless());
/// electron-deuteron magnetic moment ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_e_over_mu_d,quantity<dimensionless>,-2143.923499*dimensionless(),1.2e-5*dimensionless());
/// electron-shielded helion magnetic moment ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_e_over_mu_h_prime,quantity<dimensionless>,864.058257*dimensionless(),1.0e-5*dimensionless());
/// electron gyromagnetic ratio
BOOST_UNITS_PHYSICAL_CONSTANT(gamma_e,quantity<frequency_over_magnetic_flux_density>,1.760859644e11/second/tesla,1.1e3/second/tesla);

} // namespace codata

} // namespace constants

} // namespace si

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_CODATA_ELECTRON_CONSTANTS_HPP
