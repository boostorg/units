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

#if BOOST_UNITS_HAS_TYPEOF

#include <boost/units/measurement.hpp>
#include <boost/units/static_constant.hpp>
#include <boost/units/systems/si.hpp>

/// \file
/// CODATA recommended values of fundamental universal constants
/// CODATA 2006 values as of 2007/03/30

namespace boost {

namespace units { 

namespace SI {
                            
namespace constants {

namespace CODATA {

/// CODATA recommended values of the fundamental physical constants: NIST SP 961

// UNIVERSAL
/// speed of light
BOOST_UNITS_AUTO_STATIC_CONSTANT(c,(measurement<double>(299792458.0,0.0)*meters/second));
/// magnetic constant (exactly 4 pi x 10^(-7) - error is due to finite precision of pi)
BOOST_UNITS_AUTO_STATIC_CONSTANT(mu_0,(measurement<double>(12.56637061435917295385057353311801153679e-7,0.0)*newtons/ampere/ampere));
/// electric constant
BOOST_UNITS_AUTO_STATIC_CONSTANT(epsilon_0,(measurement<double>(8.854187817620389850536563031710750260608e-12,0.0)*farad/meter));
/// characteristic impedance of vacuum
BOOST_UNITS_AUTO_STATIC_CONSTANT(Z_0,(measurement<double>(376.7303134617706554681984004203193082686,0.0)*ohm));
/// Newtonian constant of gravitation
BOOST_UNITS_AUTO_STATIC_CONSTANT(G,(measurement<double>(6.67428e-11,6.7e-15)*cubic_meters/kilogram/second/second));
/// Planck constant
BOOST_UNITS_AUTO_STATIC_CONSTANT(h,(measurement<double>(6.62606896e-34,3.3e-41)*joule*seconds));
/// Dirac constant
BOOST_UNITS_AUTO_STATIC_CONSTANT(hbar,(measurement<double>(1.054571628e-34,5.3e-42)*joule*seconds));
/// Planck mass
BOOST_UNITS_AUTO_STATIC_CONSTANT(m_P,(measurement<double>(2.17644e-8,1.1e-12)*kilograms));
/// Planck temperature
BOOST_UNITS_AUTO_STATIC_CONSTANT(T_P,(measurement<double>(1.416785e32,7.1e27)*kelvin));
/// Planck length
BOOST_UNITS_AUTO_STATIC_CONSTANT(l_P,(measurement<double>(1.616252e-35,8.1e-40)*meters));
/// Planck time
BOOST_UNITS_AUTO_STATIC_CONSTANT(t_P,(measurement<double>(5.39124e-44,2.7e-48)*seconds));

} // namespace CODATA

} // namespace constants    

} // namespace SI

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_HAS_TYPEOF

#endif // BOOST_UNITS_CODATA_UNIVERSAL_CONSTANTS_HPP
