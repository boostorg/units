// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_TRIG_HPP
#define BOOST_UNITS_TRIG_HPP

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

struct degree_system_tag : public ordinal<-3> { };   ///< unit system tag for angles in degrees
struct gradian_system_tag : public ordinal<-2> { };  ///< unit system tag for angles in gradians
struct radian_system_tag : public ordinal<-1> { };   ///< unit system tag for angles in radians

}

}

}

#if BOOST_UNITS_HAS_BOOST_TYPEOF

#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

BOOST_TYPEOF_REGISTER_TYPE(boost::units::angle::degree_system_tag)
BOOST_TYPEOF_REGISTER_TYPE(boost::units::angle::gradian_system_tag)
BOOST_TYPEOF_REGISTER_TYPE(boost::units::angle::radian_system_tag)

#endif

namespace boost {

namespace units {

namespace angle {

typedef homogeneous_system<degree_system_tag>   degree_system;      ///< degree unit system
typedef homogeneous_system<gradian_system_tag>  gradian_system;     ///< gradian unit system
typedef homogeneous_system<radian_system_tag>   radian_system;      ///< radian unit system

typedef unit<angle_type,degree_system>  degree;     ///< degree unit constant
typedef unit<angle_type,gradian_system> gradian;    ///< gradian unit constant
typedef unit<angle_type,radian_system>  radian;     ///< radian unit constant

} // namespace angle

BOOST_UNITS_STATIC_CONSTANT(degree,angle::degree);
BOOST_UNITS_STATIC_CONSTANT(degrees,angle::degree);
BOOST_UNITS_STATIC_CONSTANT(gradian,angle::gradian);
BOOST_UNITS_STATIC_CONSTANT(gradians,angle::gradian);
BOOST_UNITS_STATIC_CONSTANT(radian,angle::radian);
BOOST_UNITS_STATIC_CONSTANT(radians,angle::radian);

template<> 
struct base_unit_info<angle_tag,angle::degree_system_tag> 
{ 
    static std::string name()       { return "degree"; }
    static std::string symbol()     { return "deg"; }
};
    
template<> 
struct base_unit_info<angle_tag,angle::gradian_system_tag> 
{ 
    static std::string name()       { return "gradian"; }
    static std::string symbol()     { return "grad"; }
};
    
template<> 
struct base_unit_info<angle_tag,angle::radian_system_tag> 
{ 
    static std::string name()       { return "radian"; }
    static std::string symbol()     { return "rad"; }
};

/// convert degrees to radians
template<>
struct base_unit_converter<angle_tag,angle::degree_system_tag,angle::radian_system_tag>
{
    typedef double type;
    static type value() { return 3.1415926535897932385/180.0; }
};

/// convert radians to degrees
template<>
struct base_unit_converter<angle_tag,angle::radian_system_tag,angle::degree_system_tag>
{
    typedef double type;
    static type value() { return 180.0/3.1415926535897932385; }
};

/// convert degrees to gradians
template<>
struct base_unit_converter<angle_tag,angle::degree_system_tag,angle::gradian_system_tag>
{
    typedef double type;
    static type value() { return 180.0/200.0; }
};

/// convert gradians to degrees
template<>
struct base_unit_converter<angle_tag,angle::gradian_system_tag,angle::degree_system_tag>
{
    typedef double type;
    static type value() { return 200.0/180.0; }
};

/// convert radians to gradians
template<>
struct base_unit_converter<angle_tag,angle::radian_system_tag,angle::gradian_system_tag>
{
    typedef double type;
    static type value() { return 200.0/3.1415926535897932385; }
};

/// convert gradians to radians
template<>
struct base_unit_converter<angle_tag,angle::gradian_system_tag,angle::radian_system_tag>
{
    typedef double type;
    static type value() { return 3.1415926535897932385/200.0; }
};

/// cos of theta in radians
template<class Y>
typename dimensionless_quantity<angle::radian,Y>::type 
cos(const quantity<angle::radian,Y>& theta)
{
    return std::cos(theta.value());
}

/// sin of theta in radians
template<class Y>
typename dimensionless_quantity<angle::radian,Y>::type 
sin(const quantity<angle::radian,Y>& theta)
{
    return std::sin(theta.value());
}

/// tan of theta in radians
template<class Y>
typename dimensionless_quantity<angle::radian,Y>::type 
tan(const quantity<angle::radian,Y>& theta)
{
    return std::tan(theta.value());
}

/// cos of theta in other angular units 
template<class Unit,class Y>
typename dimensionless_quantity<Unit,Y>::type 
cos(const quantity<Unit,Y>& theta)
{
    return cos(quantity<angle::radian,Y>(theta));
}

/// sin of theta in other angular units 
template<class Unit,class Y>
typename dimensionless_quantity<Unit,Y>::type 
sin(const quantity<Unit,Y>& theta)
{
    return sin(quantity<angle::radian,Y>(theta));
}

/// tan of theta in other angular units 
template<class Unit,class Y>
typename dimensionless_quantity<Unit,Y>::type 
tan(const quantity<Unit,Y>& theta)
{
    return tan(quantity<angle::radian,Y>(theta));
}

/// acos of @c value_type returning angle in radians
template<class Y>
quantity<angle::radian,Y>
acos(const Y& val)
{
    return quantity<angle::radian,Y>(std::acos(val)*radians);
}

/// acos of dimensionless quantity returning angle in same system
template<class Y,class System>
quantity<unit<angle_type,System>,Y>
acos(const quantity<unit<dimensionless_type,System>,Y>& val)
{
    return quantity<unit<angle_type,System>,Y>(std::acos(val)*radians);
}

/// asin of @c value_type returning angle in radians
template<class Y>
quantity<angle::radian,Y>
asin(const Y& val)
{
    return quantity<angle::radian,Y>(std::asin(val)*radians);
}

/// asin of dimensionless quantity returning angle in same system
template<class Y,class System>
quantity<unit<angle_type,System>,Y>
asin(const quantity<unit<dimensionless_type,System>,Y>& val)
{
    return quantity<unit<angle_type,System>,Y>(std::asin(val)*radians);
}

/// atan of @c value_type returning angle in radians
template<class Y>
quantity<angle::radian,Y>
atan(const Y& val)
{
    return quantity<angle::radian,Y>(std::atan(val)*radians);
}

/// atan of dimensionless quantity returning angle in same system
template<class Y,class System>
quantity<unit<angle_type,System>,Y>
atan(const quantity<unit<dimensionless_type,System>,Y>& val)
{
    return quantity<unit<angle_type,System>,Y>(std::atan(val)*radians);
}

/// atan2 of @c value_type returning angle in radians
template<class Y>
quantity<angle::radian,Y>
atan2(const Y& y,const Y& x)
{
    return quantity<angle::radian,Y>(std::atan2(y,x)*radians);
}

} // namespace units

} // namespace boost

#include <boost/units/systems/conversions/conversion_headers.hpp>

#endif // BOOST_UNITS_TRIG_HPP
