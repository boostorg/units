// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_SI_BASE_HPP
#define BOOST_UNITS_SI_BASE_HPP

#include <string>

#include <boost/units/io.hpp>
#include <boost/units/static_constant.hpp>
#include <boost/units/unit.hpp>
#include <boost/units/system.hpp>
#include <boost/units/systems/physical_units.hpp>

namespace boost {

namespace units { 

namespace SI {

/// placeholder class defining SI unit system
struct system_tag : public ordinal<-5> { };

}

}

}

#if BOOST_UNITS_HAS_BOOST_TYPEOF

#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

BOOST_TYPEOF_REGISTER_TYPE(boost::units::SI::system_tag)

#endif

namespace boost {

namespace units {

namespace SI {
    
typedef homogeneous_system<system_tag>  system;

/// dimensionless SI unit
typedef unit<dimensionless_type,system>         dimensionless;

} // namespace SI
                                                    
template<> 
struct base_unit_info<length_dim,SI::system_tag> 
{ 
    static std::string name()       { return "meter"; }
    static std::string symbol()     { return "m"; }
};
    
template<> 
struct base_unit_info<mass_dim,SI::system_tag> 
{ 
    static std::string name()       { return "kilogram"; }
    static std::string symbol()     { return "kg"; }
};
    
template<> 
struct base_unit_info<time_dim,SI::system_tag> 
{ 
    static std::string name()       { return "second"; }
    static std::string symbol()     { return "s"; }
};
    
template<> 
struct base_unit_info<current_dim,SI::system_tag> 
{ 
    static std::string name()       { return "ampere"; }
    static std::string symbol()     { return "A"; }
};
    
template<> 
struct base_unit_info<temperature_dim,SI::system_tag> 
{ 
    static std::string name()       { return "kelvin"; }
    static std::string symbol()     { return "K"; }
};
    
template<> 
struct base_unit_info<amount_dim,SI::system_tag> 
{ 
    static std::string name()       { return "mole"; }
    static std::string symbol()     { return "mol"; }
};
    
template<> 
struct base_unit_info<luminous_intensity_dim,SI::system_tag> 
{ 
    static std::string name()       { return "candela"; }
    static std::string symbol()     { return "cd"; }
};

template<> 
struct base_unit_info<plane_angle_dim,SI::system_tag> 
{ 
    static std::string name()       { return "radian"; }
    static std::string symbol()     { return "rad"; }
};

template<> 
struct base_unit_info<solid_angle_dim,SI::system_tag> 
{ 
    static std::string name()       { return "steradian"; }
    static std::string symbol()     { return "sr"; }
};

} // namespace units

} // namespace boost

#include <boost/units/systems/conversions/conversion_headers.hpp>

#endif // BOOST_UNITS_SI_BASE_HPP
