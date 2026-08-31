// Boost.Units - A C++ library for zero-overhead dimensional analysis and
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_CODATA_ATOMIC_AND_NUCLEAR_CONSTANTS_HPP
#define BOOST_UNITS_CODATA_ATOMIC_AND_NUCLEAR_CONSTANTS_HPP

#include <boost/units/systems/si/codata/alpha_constants.hpp>
#include <boost/units/systems/si/codata/deuteron_constants.hpp>
#include <boost/units/systems/si/codata/electron_constants.hpp>
#include <boost/units/systems/si/codata/helion_constants.hpp>
#include <boost/units/systems/si/codata/muon_constants.hpp>
#include <boost/units/systems/si/codata/neutron_constants.hpp>
#include <boost/units/systems/si/codata/proton_constants.hpp>
#include <boost/units/systems/si/codata/tau_constants.hpp>
#include <boost/units/systems/si/codata/triton_constants.hpp>

/// \file
/// 2018 CODATA recommended values of fundamental atomic and nuclear constants as of 2019/06/10

namespace boost {

namespace units {

namespace si {

namespace constants {

namespace codata {

/// fine-structure constant
BOOST_UNITS_PHYSICAL_CONSTANT(alpha, quantity<dimensionless>, 7.2973525693e-3*dimensionless(), 1.1e-12*dimensionless());
/// Rydberg constant
BOOST_UNITS_PHYSICAL_CONSTANT(R_infinity, quantity<wavenumber>, 10973731.568160/meter, 2.1e-5/meter);
/// Bohr radius
BOOST_UNITS_PHYSICAL_CONSTANT(a_0, quantity<length>, 0.529177210903e-10*meters, 8.0e-21*meters);
/// Hartree energy
BOOST_UNITS_PHYSICAL_CONSTANT(E_h, quantity<energy>, 4.3597447222071e-18*joules, 8.5e-30*joules);

} // namespace codata

} // namespace constants

} // namespace si

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_CODATA_ATOMIC_AND_NUCLEAR_CONSTANTS_HPP
