// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_RADIANS_HPP
#define BOOST_UNITS_RADIANS_HPP

#include <cmath>

#include <boost/units/conversion.hpp>
#include <boost/units/io.hpp>
#include <boost/units/quantity.hpp>
#include <boost/units/static_constant.hpp>
#include <boost/units/system.hpp>
#include <boost/units/systems/physical_units.hpp>

namespace boost {

namespace units { 

namespace angle {

struct radian_system_tag : public ordinal<-1> { };   ///< unit system tag for angles in radians

}

}

}

#if BOOST_UNITS_HAS_BOOST_TYPEOF

#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

BOOST_TYPEOF_REGISTER_TYPE(boost::units::angle::radian_system_tag)

#endif

namespace boost {

namespace units {

namespace angle {

typedef homogeneous_system<radian_system_tag>       radian_system;      ///< radian unit system

typedef unit<dimensionless_type,radian_system>      dimensionless_radian;

typedef unit<angle_type,radian_system>              radian;     ///< angle radian unit constant

} // namespace angle

BOOST_UNITS_STATIC_CONSTANT(radian,angle::radian);
BOOST_UNITS_STATIC_CONSTANT(radians,angle::radian);

template<> 
struct base_unit_info<angle_tag,angle::radian_system_tag> 
{ 
    static std::string name()       { return "radian"; }
    static std::string symbol()     { return "rad"; }
};

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_RADIANS_HPP
