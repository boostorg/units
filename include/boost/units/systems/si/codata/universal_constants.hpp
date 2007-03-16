// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_CODATA_UNIVERSAL_CONSTANTS_HPP
#define BOOST_UNITS_CODATA_UNIVERSAL_CONSTANTS_HPP

#include <boost/units/systems/si.hpp>

#if BOOST_UNITS_HAS_TYPEOF

#include <boost/units/static_constant.hpp>

/// \file
/// CODATA recommended values of fundamental universal constants: NIST SP 961

namespace boost {

namespace units { 

namespace SI {
                            
namespace constants {

namespace CODATA {

/// CODATA recommended values of the fundamental physical constants: NIST SP 961

// UNIVERSAL
/// speed of light
BOOST_UNITS_AUTO_STATIC_CONSTANT(c,(299792458.0*meters/second));
/// magnetic constant
BOOST_UNITS_AUTO_STATIC_CONSTANT(mu_0,(12.566370614e-7*newtons/ampere/ampere));
/// electric constant
BOOST_UNITS_AUTO_STATIC_CONSTANT(epsilon_0,(8.854187817e-12*farad/meter));
/// characteristic impedance of vacuum
BOOST_UNITS_AUTO_STATIC_CONSTANT(Z_0,(376.730313461*ohm));
/// Newtonian constant of gravitation
BOOST_UNITS_AUTO_STATIC_CONSTANT(G,(6.6742e-11*cubic_meters/kilogram/second/second));
/// Planck constant
BOOST_UNITS_AUTO_STATIC_CONSTANT(h,(6.6260693e-34*joule*seconds));
/// Dirac constant
BOOST_UNITS_AUTO_STATIC_CONSTANT(hbar,(1.05457168e-34*joule*seconds));
/// Planck mass
BOOST_UNITS_AUTO_STATIC_CONSTANT(m_P,(2.17645e-8*kilograms));
/// Planck temperature
BOOST_UNITS_AUTO_STATIC_CONSTANT(T_P,(1.41679e32*kelvin));
/// Planck length
BOOST_UNITS_AUTO_STATIC_CONSTANT(l_P,(1.61624e-35*meters));
/// Planck time
BOOST_UNITS_AUTO_STATIC_CONSTANT(t_P,(5.39121e-44*seconds));

} // namespace CODATA

} // namespace constants    

} // namespace SI

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_HAS_TYPEOF

#endif // BOOST_UNITS_CODATA_UNIVERSAL_CONSTANTS_HPP
