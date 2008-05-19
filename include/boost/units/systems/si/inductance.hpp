// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_SI_INDUCTANCE_HPP
#define BOOST_UNITS_SI_INDUCTANCE_HPP

#include <boost/units/derived_dimension.hpp>
#include <boost/units/systems/si/base.hpp>

namespace boost {

namespace units { 

namespace si {

/// inductance : L^2 M T^-2 I^-2
typedef derived_dimension<length_base_dimension,2,mass_base_dimension,1,time_base_dimension,-2,current_base_dimension,-2>::type   inductance_type;                

typedef unit<si::inductance_type,si::system>                                            inductance;
    
BOOST_UNITS_STATIC_CONSTANT(henry,inductance);  
BOOST_UNITS_STATIC_CONSTANT(henrys,inductance); 

} // namespace si

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_SI_INDUCTANCE_HPP
