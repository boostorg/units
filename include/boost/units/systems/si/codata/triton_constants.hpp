// Boost.Units - A C++ library for zero-overhead dimensional analysis and
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_CODATA_TRITON_CONSTANTS_HPP
#define BOOST_UNITS_CODATA_TRITON_CONSTANTS_HPP

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

/// triton mass
BOOST_UNITS_PHYSICAL_CONSTANT(m_t, quantity<mass>, 5.0073567446e-27*kilograms, 1.5e-36*kilograms);
/// triton-electron mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_t_over_m_e, quantity<dimensionless>, 5496.92153573*dimensionless(), 2.0e-7*dimensionless());
/// triton-proton mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_t_over_m_p, quantity<dimensionless>, 2.99371703414*dimensionless(), 1.0e-10*dimensionless());
/// triton molar mass
BOOST_UNITS_PHYSICAL_CONSTANT(M_t, quantity<mass_over_amount>, 3.01550071517e-3*kilograms/mole, 9.2e-13*kilograms/mole);
/// triton magnetic moment
BOOST_UNITS_PHYSICAL_CONSTANT(mu_t, quantity<energy_over_magnetic_flux_density>, 1.5046095202e-26*joules/tesla, 3.0e-35*joules/tesla);
/// triton magnetic moment to Bohr magneton ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_t_over_mu_B, quantity<dimensionless>, 1.6223936651e-3*dimensionless(), 3.2e-12*dimensionless());
/// triton magnetic moment to nuclear magneton ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_t_over_mu_N, quantity<dimensionless>, 2.9789624656*dimensionless(), 5.0e-9*dimensionless());
/// triton g factor
BOOST_UNITS_PHYSICAL_CONSTANT(g_t, quantity<dimensionless>, 5.957924931*dimensionless(), 1.0e-8*dimensionless());
/// triton-electron magnetic moment ratio @deprecated
BOOST_UNITS_PHYSICAL_CONSTANT(mu_t_over_mu_e, quantity<dimensionless>, -1.6205144321e-3*dimensionless(), 3.3e-12*dimensionless());
/// triton-proton magnetic moment ratio @deprecated
BOOST_UNITS_PHYSICAL_CONSTANT(mu_t_over_mu_p, quantity<dimensionless>, 1.0666399191*dimensionless(), 2.2e-9*dimensionless());
/// triton-neutron magnetic moment ratio @deprecated
BOOST_UNITS_PHYSICAL_CONSTANT(mu_t_over_mu_n, quantity<dimensionless>, -1.55718554*dimensionless(), 3.7e-7*dimensionless());

} // namespace codata

} // namespace constants

} // namespace si

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_CODATA_TRITON_CONSTANTS_HPP
