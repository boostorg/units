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
/// 2014 CODATA recommended values of fundamental atomic and nuclear constants as of 2018/07/21

namespace boost {

namespace units {

namespace si {

namespace constants {

namespace codata {

/// deuteron mass
BOOST_UNITS_PHYSICAL_CONSTANT(m_d,quantity<mass>,3.343583719e-27*kilograms,4.1e-35*kilograms);
/// deuteron-electron mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_d_over_m_e,quantity<dimensionless>,3670.48296785*dimensionless(),1.3e-7*dimensionless());
/// deuteron-proton mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_d_over_m_p,quantity<dimensionless>,1.99900750087*dimensionless(),1.9e-10*dimensionless());
/// deuteron molar mass
BOOST_UNITS_PHYSICAL_CONSTANT(M_d,quantity<mass_over_amount>,2.013553212745e-3*kilograms/mole,4.0e-14*kilograms/mole);
/// deuteron rms charge radius
BOOST_UNITS_PHYSICAL_CONSTANT(R_d,quantity<length>,2.1413e-15*meters,2.5e-18*meters);
/// deuteron magnetic moment
BOOST_UNITS_PHYSICAL_CONSTANT(mu_d,quantity<energy_over_magnetic_flux_density>,0.4330735040e-26*joules/tesla,3.6e-35*joules/tesla);
/// deuteron-Bohr magneton ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_d_over_mu_B,quantity<dimensionless>,0.4669754554e-3*dimensionless(),2.6e-12*dimensionless());
/// deuteron-nuclear magneton ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_d_over_mu_N,quantity<dimensionless>,0.8574382311*dimensionless(),4.8e-9*dimensionless());
/// deuteron g-factor
BOOST_UNITS_PHYSICAL_CONSTANT(g_d,quantity<dimensionless>,0.8574382311*dimensionless(),4.8e-9*dimensionless());
/// deuteron-electron magnetic moment ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_d_over_mu_e,quantity<dimensionless>,-4.664345535e-4*dimensionless(),2.6e-12*dimensionless());
/// deuteron-proton magnetic moment ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_d_over_mu_p,quantity<dimensionless>,0.3070122077*dimensionless(),1.5e-9*dimensionless());
/// deuteron-neutron magnetic moment ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_d_over_mu_n,quantity<dimensionless>,-0.44820652*dimensionless(),1.1e-7*dimensionless());

} // namespace codata

} // namespace constants

} // namespace si

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_CODATA_DEUTERON_CONSTANTS_HPP
