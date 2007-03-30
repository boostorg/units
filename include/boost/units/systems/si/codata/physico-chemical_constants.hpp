// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_CODATA_PHYSICO_CHEMICAL_CONSTANTS_HPP
#define BOOST_UNITS_CODATA_PHYSICO_CHEMICAL_CONSTANTS_HPP

#include <boost/units/systems/si.hpp>

#if BOOST_UNITS_HAS_TYPEOF

#include <boost/units/measurement.hpp>
#include <boost/units/static_constant.hpp>

/// \file
/// CODATA recommended values of fundamental physico-chemical constants: NIST SP 961

namespace boost {

namespace units { 

namespace SI {
                            
namespace constants {

namespace CODATA {

// PHYSICO-CHEMICAL
/// Avogadro constant
BOOST_UNITS_AUTO_STATIC_CONSTANT(N_A,(6.0221415e23/mole));
/// atomic mass constant
BOOST_UNITS_AUTO_STATIC_CONSTANT(m_u,(1.66053886e-27*kilograms));
/// Faraday constant
BOOST_UNITS_AUTO_STATIC_CONSTANT(F,(96485.3383*coulombs/mole));
/// molar gas constant
BOOST_UNITS_AUTO_STATIC_CONSTANT(R,(measurement<double>(8.314472)*joules/kelvin/mole));
/// Boltzmann constant
BOOST_UNITS_AUTO_STATIC_CONSTANT(k_B,(1.3806505e-23*joules/kelvin));
/// molar volume of ideal gas
BOOST_UNITS_AUTO_STATIC_CONSTANT(V_m,(22.413996e-3*cubic_meters/mole));
/// Stefan-Boltzmann constant
BOOST_UNITS_AUTO_STATIC_CONSTANT(sigma_SB,(5.670400e-8*watts/square_meter/pow<4>(kelvin)));
/// first radiation constant
BOOST_UNITS_AUTO_STATIC_CONSTANT(c_1,(3.74177138e-16*watt*square_meters));
/// second radiation constant
BOOST_UNITS_AUTO_STATIC_CONSTANT(c_2,(1.4387752e-2*meter*kelvin));
/// Wien displacement law constant
BOOST_UNITS_AUTO_STATIC_CONSTANT(b,(2.8977685e-3*meter*kelvin));

} // namespace CODATA

} // namespace constants    

} // namespace SI

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_HAS_TYPEOF

#endif // BOOST_UNITS_CODATA_PHYSICO_CHEMICAL_CONSTANTS_HPP
