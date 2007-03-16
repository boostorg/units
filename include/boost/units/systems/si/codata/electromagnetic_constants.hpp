// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_CODATA_ELECTROMAGNETIC_CONSTANTS_HPP
#define BOOST_UNITS_CODATA_ELECTROMAGNETIC_CONSTANTS_HPP

#include <boost/units/systems/si.hpp>

#if BOOST_UNITS_HAS_TYPEOF

#include <boost/units/static_constant.hpp>

/// \file
/// CODATA recommended values of fundamental electromagnetic constants: NIST SP 961

namespace boost {

namespace units { 

namespace SI {
                            
namespace constants {

namespace CODATA {

/// CODATA recommended values of the fundamental physical constants: NIST SP 961

// ELECTROMAGNETIC
/// elementary charge
BOOST_UNITS_AUTO_STATIC_CONSTANT(e,(1.60217653e-19*coulombs));
/// elementary charge to Planck constant ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(e_over_h,(2.41798940*amperes/joule));
/// magnetic flux quantum
BOOST_UNITS_AUTO_STATIC_CONSTANT(Phi_0,(2.06783372*webers));
/// conductance quantum
BOOST_UNITS_AUTO_STATIC_CONSTANT(G_0,(7.748091733e-5*siemens));
/// Josephson constant
BOOST_UNITS_AUTO_STATIC_CONSTANT(K_J,(483597.879e9*hertz/volt));
/// von Klitzing constant
BOOST_UNITS_AUTO_STATIC_CONSTANT(R_K,(25812.807449*ohms));
/// Bohr magneton
BOOST_UNITS_AUTO_STATIC_CONSTANT(mu_B,(927.400949e-26*joules/tesla));
/// nuclear magneton
BOOST_UNITS_AUTO_STATIC_CONSTANT(mu_N,(5.05078343e-27*joules/tesla));

} // namespace CODATA

} // namespace constants    

} // namespace SI

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_HAS_TYPEOF

#endif // BOOST_UNITS_CODATA_ELECTROMAGNETIC_CONSTANTS_HPP
