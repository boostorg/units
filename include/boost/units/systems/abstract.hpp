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
#include <boost/units/system.hpp>
#include <boost/units/systems/physical_units.hpp>

namespace boost {

namespace units { 

namespace abstract {

/// abstract unit system for pure dimensional analysis
struct system_tag : public ordinal<-6>   { };

}

}

}

#if BOOST_UNITS_HAS_BOOST_TYPEOF

#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

BOOST_TYPEOF_REGISTER_TYPE(boost::units::abstract::system_tag)

#endif

namespace boost {

namespace units {

namespace abstract {

typedef homogeneous_system<system_tag>      system;

typedef unit<length_type,system>            length;         ///< abstract unit of length
typedef unit<mass_type,system>              mass;           ///< abstract unit of mass
typedef unit<time_type,system>              time;           ///< abstract unit of time
typedef unit<current_type,system>           current;        ///< abstract unit of current
typedef unit<temperature_type,system>       temperature;    ///< abstract unit of temperature
typedef unit<amount_type,system>            amount;         ///< abstract unit of amount
typedef unit<intensity_type,system>         intensity;      ///< abstract unit of intensity
typedef unit<angle_type,system>             angle;          ///< abstract unit of angle
typedef unit<solid_angle_type,system>       solid_angle;    ///< abstract unit of solid angle

} // namespace abstract

template<> 
struct base_unit_info<length_tag,abstract::system_tag> 
{ 
    static std::string name()       { return "[Length]"; }
    static std::string symbol()     { return "[L]"; }
};

template<> 
struct base_unit_info<mass_tag,abstract::system_tag> 
{ 
    static std::string name()       { return "[Mass]"; }
    static std::string symbol()     { return "[M]"; }
};

template<> 
struct base_unit_info<time_tag,abstract::system_tag> 
{ 
    static std::string name()       { return "[Time]"; }
    static std::string symbol()     { return "[T]"; }
};

template<> 
struct base_unit_info<current_tag,abstract::system_tag> 
{ 
    static std::string name()       { return "[Current]"; }
    static std::string symbol()     { return "[C]"; }
};

template<> 
struct base_unit_info<temperature_tag,abstract::system_tag> 
{ 
    static std::string name()       { return "[Temperature]"; }
    static std::string symbol()     { return "[K]"; }
};

template<> 
struct base_unit_info<amount_tag,abstract::system_tag> 
{ 
    static std::string name()       { return "[Amount]"; }
    static std::string symbol()     { return "[A]"; }
};

template<> 
struct base_unit_info<intensity_tag,abstract::system_tag> 
{ 
    static std::string name()       { return "[Intensity]"; }
    static std::string symbol()     { return "[I]"; }
};

template<> 
struct base_unit_info<angle_tag,abstract::system_tag> 
{ 
    static std::string name()       { return "[Planar Angle]"; }
    static std::string symbol()     { return "[QP]"; }
};

template<> 
struct base_unit_info<solid_angle_tag,abstract::system_tag> 
{ 
    static std::string name()       { return "[Solid Angle]"; }
    static std::string symbol()     { return "[QS]"; }
};

/// prevent conversions from abstract quantities to any other system
template<typename DimTag,typename SysTag>
struct base_unit_converter<DimTag,abstract::system_tag,SysTag> { };

/// prevent conversions from any other system to abstract quantities
template<typename DimTag,typename SysTag>
struct base_unit_converter<DimTag,SysTag,abstract::system_tag> { };

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_ABSTRACT_HPP
