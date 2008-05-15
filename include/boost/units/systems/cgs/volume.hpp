// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_CGS_VOLUME_HPP
#define BOOST_UNITS_CGS_VOLUME_HPP

#include <boost/units/systems/cgs/base.hpp>
#include <boost/units/systems/physical_dimensions/volume.hpp>

namespace boost {

namespace units { 

namespace CGS {

typedef unit<volume_dimension,CGS::system>   volume;
    
BOOST_UNITS_STATIC_CONSTANT(cubic_centimeter,volume);   
BOOST_UNITS_STATIC_CONSTANT(cubic_centimeters,volume);  
BOOST_UNITS_STATIC_CONSTANT(cubic_centimetre,volume);   
BOOST_UNITS_STATIC_CONSTANT(cubic_centimetres,volume);  

} // namespace CGS

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_CGS_VOLUME_HPP
