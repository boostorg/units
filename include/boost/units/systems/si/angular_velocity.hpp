// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_SI_ANGULAR_VELOCITY_HPP
#define BOOST_UNITS_SI_ANGULAR_VELOCITY_HPP

#include <iostream>
#include <boost/units/io.hpp>

#include <boost/units/systems/si/base.hpp>
#include <boost/units/physical_dimensions/angular_velocity.hpp>

namespace boost {

namespace units { 

namespace si {

typedef unit<angular_velocity_dimension,si::system>      angular_velocity;
    
BOOST_UNITS_STATIC_CONSTANT(radian_per_second,angular_velocity); 
BOOST_UNITS_STATIC_CONSTANT(radians_per_second,angular_velocity);    

} // namespace si

std::ostream& operator<<(std::ostream& os, const boost::units::si::angular_velocity&) 
{
    return(os << "rad/s");
}

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_SI_ANGULAR_VELOCITY_HPP
