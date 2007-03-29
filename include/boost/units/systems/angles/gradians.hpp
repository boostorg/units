// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_GRADIANS_HPP
#define BOOST_UNITS_GRADIANS_HPP

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

struct gradian_system_tag : public ordinal<-2> { };   ///< unit system tag for angles in gradians

}

}

}

#if BOOST_UNITS_HAS_BOOST_TYPEOF

#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

BOOST_TYPEOF_REGISTER_TYPE(boost::units::angle::gradian_system_tag)

#endif

namespace boost {

namespace units {

namespace angle {

typedef homogeneous_system<gradian_system_tag>      gradian_system;      ///< gradian unit system

typedef unit<dimensionless_type,gradian_system>     dimensionless_gradian;

typedef unit<angle_type,gradian_system>             gradian;            ///< angle gradian unit constant

} // namespace angle

BOOST_UNITS_STATIC_CONSTANT(gradian,angle::gradian);
BOOST_UNITS_STATIC_CONSTANT(gradians,angle::gradian);

template<> 
struct base_unit_info<angle_tag,angle::gradian_system_tag> 
{ 
    static std::string name()       { return "gradian"; }
    static std::string symbol()     { return "grad"; }
};

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_GRADIANS_HPP
