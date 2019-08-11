// Boost.Units - A C++ library for zero-overhead dimensional analysis and
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_CODATA_ALPHA_CONSTANTS_HPP
#define BOOST_UNITS_CODATA_ALPHA_CONSTANTS_HPP

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

/// alpha particle mass
BOOST_UNITS_PHYSICAL_CONSTANT(m_alpha, quantity<mass>, 6.6446573357e-27*kilograms, 2.0e-36*kilograms);
/// alpha particle-electron mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_alpha_over_m_e, quantity<dimensionless>, 7294.29954142*dimensionless(), 2.0e-7*dimensionless());
/// alpha particle-proton mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_alpha_over_m_p, quantity<dimensionless>, 3.97259969009*dimensionless(), 2.0e-10*dimensionless());
/// alpha particle molar mass
BOOST_UNITS_PHYSICAL_CONSTANT(M_alpha, quantity<mass_over_amount>, 4.0015061777e-3*kilograms/mole, 1.2e-12*kilograms/mole);

} // namespace codata

} // namespace constants

} // namespace si

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_CODATA_ALPHA_CONSTANTS_HPP
