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

#if BOOST_UNITS_HAS_TYPEOF

#include <boost/units/measurement.hpp>
#include <boost/units/static_constant.hpp>
#include <boost/units/systems/si.hpp>

/// \file
/// CODATA recommended values of fundamental physico-chemical constants
/// CODATA 2006 values as of 2007/03/30

namespace boost {

namespace units { 

namespace SI {
                            
namespace constants {

namespace CODATA {

// PHYSICO-CHEMICAL
/// Avogadro constant
BOOST_UNITS_AUTO_STATIC_CONSTANT(N_A,(measurement<double>(6.02214179e23,3.0e16)/mole));
/// atomic mass constant
BOOST_UNITS_AUTO_STATIC_CONSTANT(m_u,(measurement<double>(1.660538782e-27,8.3e-35)*kilograms));
/// Faraday constant
BOOST_UNITS_AUTO_STATIC_CONSTANT(F,(measurement<double>(96485.3399,2.4e-3)*coulombs/mole));
/// molar gas constant
BOOST_UNITS_AUTO_STATIC_CONSTANT(R,(measurement<double>(8.314472,1.5e-5)*joules/kelvin/mole));
/// Boltzmann constant
BOOST_UNITS_AUTO_STATIC_CONSTANT(k_B,(measurement<double>(1.3806504e-23,2.4e-29)*joules/kelvin));
/// Stefan-Boltzmann constant
BOOST_UNITS_AUTO_STATIC_CONSTANT(sigma_SB,(measurement<double>(5.670400e-8,4.0e-13)*watts/square_meter/pow<4>(kelvin)));
/// first radiation constant
BOOST_UNITS_AUTO_STATIC_CONSTANT(c_1,(measurement<double>(3.74177118e-16,1.9e-23)*watt*square_meters));
/// first radiation constant for spectral radiance
BOOST_UNITS_AUTO_STATIC_CONSTANT(c_1L,(measurement<double>(1.191042759e-16,5.9e-24)*watt*square_meters/steradian));
/// second radiation constant
BOOST_UNITS_AUTO_STATIC_CONSTANT(c_2,(measurement<double>(1.4387752e-2,2.5e-8)*meter*kelvin));
/// Wien displacement law constant : lambda_max T
BOOST_UNITS_AUTO_STATIC_CONSTANT(b,(measurement<double>(2.8977685e-3,5.1e-9)*meter*kelvin));
/// Wien displacement law constant : nu_max/T
BOOST_UNITS_AUTO_STATIC_CONSTANT(b_prime,(measurement<double>(5.878933e10,1.0e15)*hertz/kelvin));

} // namespace CODATA

} // namespace constants    

} // namespace SI

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_HAS_TYPEOF

#endif // BOOST_UNITS_CODATA_PHYSICO_CHEMICAL_CONSTANTS_HPP
