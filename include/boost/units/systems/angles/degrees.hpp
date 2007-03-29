// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_DEGREES_HPP
#define BOOST_UNITS_DEGREES_HPP

#include <cmath>

#include <boost/units/conversion.hpp>
#include <boost/units/io.hpp>
#include <boost/units/quantity.hpp>
#include <boost/units/static_constant.hpp>
#include <boost/units/system.hpp>
#include <boost/units/systems/physical_units.hpp>

namespace boost {

namespace units { 

namespace degree_ns {

struct system_tag : public ordinal<-3> { };   ///< unit system tag for angles in degrees

}

}

}

#if BOOST_UNITS_HAS_BOOST_TYPEOF

#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

BOOST_TYPEOF_REGISTER_TYPE(boost::units::degree_ns::system_tag)

#endif

namespace boost {

namespace units {

namespace degree_ns {

typedef homogeneous_system<system_tag>      system;         ///< degree unit system

} // namespace degree_ns

namespace angle {

typedef unit<dimensionless_type,degree_ns::system>      dimensionless_degree;
typedef unit<angle_type,degree_ns::system>              degree;         ///< angle degree unit constant

} // namespace angle

BOOST_UNITS_STATIC_CONSTANT(degree,angle::degree);
BOOST_UNITS_STATIC_CONSTANT(degrees,angle::degree);

template<> 
struct base_unit_info<angle_tag,degree_ns::system_tag> 
{ 
    static std::string name()       { return "degree"; }
    static std::string symbol()     { return "deg"; }
};

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_DEGREES_HPP
