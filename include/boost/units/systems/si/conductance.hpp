// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_SI_CONDUCTANCE_HPP
#define BOOST_UNITS_SI_CONDUCTANCE_HPP

#include <iostream>
#include <boost/units/io.hpp>

#include <boost/units/derived_dimension.hpp>
#include <boost/units/systems/si/base.hpp>

namespace boost {

namespace units { 

namespace si {

/// conductance : L^-2 M^-1 T^3 I^2
typedef derived_dimension<length_base_dimension,-2,mass_base_dimension,-1,time_base_dimension,3,current_base_dimension,2>::type   conductance_type;                    

typedef unit<si::conductance_type,si::system>                                           conductance;

BOOST_UNITS_STATIC_CONSTANT(siemen,conductance);    
BOOST_UNITS_STATIC_CONSTANT(siemens,conductance);   
BOOST_UNITS_STATIC_CONSTANT(mho,conductance);   
BOOST_UNITS_STATIC_CONSTANT(mhos,conductance);  

} // namespace si

std::ostream& operator<<(std::ostream& os, const boost::units::si::conductance&) 
{
    return(os << "S");
}

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_SI_CONDUCTANCE_HPP
