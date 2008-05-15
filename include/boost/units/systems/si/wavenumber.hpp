// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_SI_WAVENUMBER_HPP
#define BOOST_UNITS_SI_WAVENUMBER_HPP

#include <boost/units/systems/si/base.hpp>
#include <boost/units/systems/physical_dimensions/wavenumber.hpp>

namespace boost {

namespace units { 

namespace SI {

typedef unit<wavenumber_dimension,SI::system>    wavenumber;
    
BOOST_UNITS_STATIC_CONSTANT(reciprocal_meter,wavenumber);   
BOOST_UNITS_STATIC_CONSTANT(reciprocal_meters,wavenumber);  
BOOST_UNITS_STATIC_CONSTANT(reciprocal_metre,wavenumber);   
BOOST_UNITS_STATIC_CONSTANT(reciprocal_metres,wavenumber);  

} // namespace SI

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_SI_WAVENUMBER_HPP
