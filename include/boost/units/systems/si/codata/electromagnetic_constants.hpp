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

#if BOOST_UNITS_HAS_TYPEOF

#include <boost/units/measurement.hpp>
#include <boost/units/static_constant.hpp>
#include <boost/units/systems/si.hpp>

/// \file
/// CODATA recommended values of fundamental electromagnetic constants
/// CODATA 2006 values as of 2007/03/30

namespace boost {

namespace units { 

namespace SI {
                            
namespace constants {

namespace CODATA {

/// CODATA recommended values of the fundamental physical constants: NIST SP 961

// ELECTROMAGNETIC
/// elementary charge
BOOST_UNITS_AUTO_STATIC_CONSTANT(e,(measurement<double>(1.602176487e-19,4.0e-27)*coulombs));
/// elementary charge to Planck constant ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(e_over_h,(measurement<double>(2.417989454e14,6.0e6)*amperes/joule));
/// magnetic flux quantum
BOOST_UNITS_AUTO_STATIC_CONSTANT(Phi_0,(measurement<double>(2.067833667e-15,5.2e-23)*webers));
/// conductance quantum
BOOST_UNITS_AUTO_STATIC_CONSTANT(G_0,(measurement<double>(7.7480917004e-5,5.3e-14)*siemens));
/// Josephson constant
BOOST_UNITS_AUTO_STATIC_CONSTANT(K_J,(measurement<double>(483597.891e9,1.2e7)*hertz/volt));
/// von Klitzing constant
BOOST_UNITS_AUTO_STATIC_CONSTANT(R_K,(measurement<double>(25812.807557,1.8e-5)*ohms));
/// Bohr magneton
BOOST_UNITS_AUTO_STATIC_CONSTANT(mu_B,(measurement<double>(927.400915e-26,2.3e-31)*joules/tesla));
/// nuclear magneton
BOOST_UNITS_AUTO_STATIC_CONSTANT(mu_N,(measurement<double>(5.05078324e-27,1.3e-34)*joules/tesla));

} // namespace CODATA

} // namespace constants    

} // namespace SI

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_HAS_TYPEOF

#endif // BOOST_UNITS_CODATA_ELECTROMAGNETIC_CONSTANTS_HPP
