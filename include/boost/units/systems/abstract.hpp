// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_ABSTRACT_HPP
#define BOOST_UNITS_ABSTRACT_HPP

#include <string>

#include <boost/units/conversion.hpp>
#include <boost/units/ordinal.hpp>
#include <boost/units/system.hpp>
#include <boost/units/systems/physical_units.hpp>
#include <boost/units/quantity.hpp>

#include <boost/units/experimental/make_system.hpp>
#include <boost/units/experimental/base_unit.hpp>

//namespace boost {
//
//namespace units { 
//
//namespace abstract {
//
///// abstract unit system for pure dimensional analysis
//struct system_tag : public ordinal<-6>   { };
//
//}
//
//}
//
//}
//
//#if BOOST_UNITS_HAS_BOOST_TYPEOF
//
//#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()
//
//BOOST_TYPEOF_REGISTER_TYPE(boost::units::abstract::system_tag)
//
//#endif

namespace boost {

namespace units {

namespace abstract {

struct length_unit_tag : base_unit<length_unit_tag, length_type, -30> {};
struct mass_unit_tag : base_unit<mass_unit_tag, mass_type, -29> {};
struct time_unit_tag : base_unit<time_unit_tag, time_type, -28> {};
struct current_unit_tag : base_unit<current_unit_tag, current_type, -27> {};
struct temperature_unit_tag : base_unit<temperature_unit_tag, temperature_type, -26> {};
struct amount_unit_tag : base_unit<amount_unit_tag, amount_type, -25> {};
struct luminous_intensity_unit_tag : base_unit<luminous_intensity_unit_tag, luminous_intensity_type, -24> {};
struct plane_angle_unit_tag : base_unit<plane_angle_unit_tag, plane_angle_type, -23> {};
struct solid_angle_unit_tag : base_unit<solid_angle_unit_tag, solid_angle_type, -22> {};

typedef make_system<
    length_unit_tag,
    mass_unit_tag,
    time_unit_tag,
    current_unit_tag,
    temperature_unit_tag,
    amount_unit_tag,
    luminous_intensity_unit_tag,
    plane_angle_unit_tag,
    solid_angle_unit_tag
>::type system;

typedef unit<length_type,system>                length;                 ///< abstract unit of length
typedef unit<mass_type,system>                  mass;                   ///< abstract unit of mass
typedef unit<time_type,system>                  time;                   ///< abstract unit of time
typedef unit<current_type,system>               current;                ///< abstract unit of current
typedef unit<temperature_type,system>           temperature;            ///< abstract unit of temperature
typedef unit<amount_type,system>                amount;                 ///< abstract unit of amount
typedef unit<luminous_intensity_type,system>    luminous_intensity;     ///< abstract unit of luminous intensity
typedef unit<plane_angle_type,system>           plane_angle;            ///< abstract unit of plane angle
typedef unit<solid_angle_type,system>           solid_angle;            ///< abstract unit of solid angle

} // namespace abstract

template<> 
struct base_unit_info<abstract::length_unit_tag> 
{ 
    static std::string name()       { return "[Length]"; }
    static std::string symbol()     { return "[L]"; }
};

template<> 
struct base_unit_info<abstract::mass_unit_tag> 
{ 
    static std::string name()       { return "[Mass]"; }
    static std::string symbol()     { return "[M]"; }
};

template<> 
struct base_unit_info<abstract::time_unit_tag> 
{ 
    static std::string name()       { return "[Time]"; }
    static std::string symbol()     { return "[T]"; }
};

template<> 
struct base_unit_info<abstract::current_unit_tag> 
{ 
    static std::string name()       { return "[Electric Current]"; }
    static std::string symbol()     { return "[I]"; }
};

template<> 
struct base_unit_info<abstract::temperature_unit_tag> 
{ 
    static std::string name()       { return "[Temperature]"; }
    static std::string symbol()     { return "[Theta]"; }
};

template<> 
struct base_unit_info<abstract::amount_unit_tag> 
{ 
    static std::string name()       { return "[Amount]"; }
    static std::string symbol()     { return "[N]"; }
};

template<> 
struct base_unit_info<abstract::luminous_intensity_unit_tag> 
{ 
    static std::string name()       { return "[Luminous Intensity]"; }
    static std::string symbol()     { return "[J]"; }
};

template<> 
struct base_unit_info<abstract::plane_angle_unit_tag> 
{ 
    static std::string name()       { return "[Planar Angle]"; }
    static std::string symbol()     { return "[QP]"; }
};

template<> 
struct base_unit_info<abstract::solid_angle_unit_tag> 
{ 
    static std::string name()       { return "[Solid Angle]"; }
    static std::string symbol()     { return "[QS]"; }
};

///// prevent conversions from abstract quantities to any other system
//template<typename DimTag,typename SysTag>
//struct base_unit_converter<DimTag,abstract::system_tag,SysTag> { };
//
///// prevent conversions from any other system to abstract quantities
//template<typename DimTag,typename SysTag>
//struct base_unit_converter<DimTag,SysTag,abstract::system_tag> { };

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_ABSTRACT_HPP
