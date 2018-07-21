// Boost.Units - A C++ library for zero-overhead dimensional analysis and
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_CODATA_MUON_CONSTANTS_HPP
#define BOOST_UNITS_CODATA_MUON_CONSTANTS_HPP

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

/// muon mass
BOOST_UNITS_PHYSICAL_CONSTANT(m_mu,quantity<mass>,1.883531594e-28*kilograms,4.8e-36*kilograms);
/// muon-electron mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_mu_over_m_e,quantity<dimensionless>,206.7682826*dimensionless(),4.6e-6*dimensionless());
/// muon-tau mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_mu_over_m_tau,quantity<dimensionless>,5.94649e-2*dimensionless(),5.4e-6*dimensionless());
/// muon-proton mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_mu_over_m_p,quantity<dimensionless>,0.1126095262*dimensionless(),2.5e-9*dimensionless());
/// muon-neutron mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_mu_over_m_n,quantity<dimensionless>,0.1124545167*dimensionless(),2.5e-9*dimensionless());
/// muon molar mass
BOOST_UNITS_PHYSICAL_CONSTANT(M_mu,quantity<mass_over_amount>,0.1134289257e-3*kilograms/mole,2.5e-12*kilograms/mole);
/// muon Compton wavelength
BOOST_UNITS_PHYSICAL_CONSTANT(lambda_C_mu,quantity<length>,11.73444111e-15*meters,2.6e-22*meters);
/// muon magnetic moment
BOOST_UNITS_PHYSICAL_CONSTANT(mu_mu,quantity<energy_over_magnetic_flux_density>,-4.49044826e-26*joules/tesla,1.0e-33*joules/tesla);
/// muon-Bohr magneton ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_mu_over_mu_B,quantity<dimensionless>,-4.84197048e-3*dimensionless(),1.1e-10*dimensionless());
/// muon-nuclear magneton ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_mu_over_mu_N,quantity<dimensionless>,-8.89059705*dimensionless(),2.0e-7*dimensionless());
/// muon magnetic moment anomaly
BOOST_UNITS_PHYSICAL_CONSTANT(a_mu,quantity<dimensionless>,1.16592089e-3*dimensionless(),6.3e-10*dimensionless());
/// muon g-factor
BOOST_UNITS_PHYSICAL_CONSTANT(g_mu,quantity<dimensionless>,-2.0023318418*dimensionless(),1.3e-9*dimensionless());
/// muon-proton magnetic moment ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_mu_over_mu_p,quantity<dimensionless>,-3.183345142*dimensionless(),7.1e-8*dimensionless());

} // namespace codata

} // namespace constants

} // namespace si

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_CODATA_MUON_CONSTANTS_HPP
