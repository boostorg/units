// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_SI_PREFIXES_HPP
#define BOOST_UNITS_SI_PREFIXES_HPP

#include <boost/units/static_constant.hpp>

namespace boost {

namespace units { 

namespace SI {

BOOST_UNITS_STATIC_CONSTANT(yocto,long double) = (1e-24);       ///< metric prefix for 1.0e-24
BOOST_UNITS_STATIC_CONSTANT(zepto,long double) = (1e-21);       ///< metric prefix for 1.0e-21
BOOST_UNITS_STATIC_CONSTANT(atto,long double) = (1e-18);        ///< metric prefix for 1.0e-18
BOOST_UNITS_STATIC_CONSTANT(femto,long double) = (1e-15);       ///< metric prefix for 1.0e-15
BOOST_UNITS_STATIC_CONSTANT(pico,long double) = (1e-12);        ///< metric prefix for 1.0e-12
BOOST_UNITS_STATIC_CONSTANT(nano,long double) = (1e-9);         ///< metric prefix for 1.0e-9
BOOST_UNITS_STATIC_CONSTANT(micro,long double) = (1e-6);        ///< metric prefix for 1.0e-6
BOOST_UNITS_STATIC_CONSTANT(milli,long double) = (1e-3);        ///< metric prefix for 1.0e-3
BOOST_UNITS_STATIC_CONSTANT(centi,long double) = (1e-2);        ///< metric prefix for 1.0e-2
BOOST_UNITS_STATIC_CONSTANT(deci,long double) = (1e-1);         ///< metric prefix for 1.0e-1
BOOST_UNITS_STATIC_CONSTANT(deka,long double) = (1e1);          ///< metric prefix for 1.0e+1
BOOST_UNITS_STATIC_CONSTANT(hecto,long double) = (1e2);         ///< metric prefix for 1.0e+2
BOOST_UNITS_STATIC_CONSTANT(kilo,long double) = (1e3);          ///< metric prefix for 1.0e+3
BOOST_UNITS_STATIC_CONSTANT(mega,long double) = (1e6);          ///< metric prefix for 1.0e+6
BOOST_UNITS_STATIC_CONSTANT(giga,long double) = (1e9);          ///< metric prefix for 1.0e+9
BOOST_UNITS_STATIC_CONSTANT(tera,long double) = (1e12);         ///< metric prefix for 1.0e+12
BOOST_UNITS_STATIC_CONSTANT(peta,long double) = (1e15);         ///< metric prefix for 1.0e+15
BOOST_UNITS_STATIC_CONSTANT(exa,long double) = (1e18);          ///< metric prefix for 1.0e+18
BOOST_UNITS_STATIC_CONSTANT(zetta,long double) = (1e21);        ///< metric prefix for 1.0e+21
BOOST_UNITS_STATIC_CONSTANT(yotta,long double) = (1e24);        ///< metric prefix for 1.0e+24  

} // namespace SI

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_SI_PREFIXES_HPP
