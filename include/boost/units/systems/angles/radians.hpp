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

namespace radian_ns {

struct system_tag : public ordinal<-1> { };   ///< unit system tag for angles in radians

}

}

}

#if BOOST_UNITS_HAS_BOOST_TYPEOF

#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

BOOST_TYPEOF_REGISTER_TYPE(boost::units::radian_ns::system_tag)

#endif

namespace boost {

namespace units {

namespace radian_ns {

typedef homogeneous_system<system_tag>       system;                ///< radian unit system

} // namespace radian_ns

namespace angle {

typedef unit<dimensionless_type,radian_ns::system>      dimensionless_radian;
typedef unit<angle_type,radian_ns::system>              radian;                ///< angle radian unit constant

} // namespace angle

BOOST_UNITS_STATIC_CONSTANT(radian,angle::radian);
BOOST_UNITS_STATIC_CONSTANT(radians,angle::radian);

template<> 
struct base_unit_info<angle_tag,radian_ns::system_tag> 
{ 
    static std::string name()       { return "radian"; }
    static std::string symbol()     { return "rad"; }
};

} // namespace units

} // namespace boost

#include <boost/units/systems/conversions/conversion_headers.hpp>

#endif // BOOST_UNITS_RADIANS_HPP
