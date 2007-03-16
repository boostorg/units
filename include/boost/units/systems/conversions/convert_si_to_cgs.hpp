// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_SI_CONVERT_SI_TO_CGS_HPP
#define BOOST_UNITS_SI_CONVERT_SI_TO_CGS_HPP

#include <boost/units/conversion.hpp>
#include <boost/units/systems/si/base.hpp>
#include <boost/units/systems/cgs/base.hpp>

namespace boost {

namespace units { 

/// convert meters to centimeters
template<>
struct base_unit_converter<length_tag,SI::system_tag,CGS::system_tag>
#ifdef BOOST_UNITS_ENABLE_IMPLICIT_UNIT_CONVERSION
    : public implicitly_convertible
#endif
{
    typedef double type;
    static type value() { return(100); }
};

/// convert kilograms to grams
template<>
struct base_unit_converter<mass_tag,SI::system_tag,CGS::system_tag>
#ifdef BOOST_UNITS_ENABLE_IMPLICIT_UNIT_CONVERSION
    : public implicitly_convertible
#endif
{
    typedef double type;
    static type value() { return(1000); }
};

/// convert SI seconds to CGS seconds
template<>
struct base_unit_converter<time_tag,SI::system_tag,CGS::system_tag> :
    public implicitly_convertible,
    public trivial_conversion
{ };

/// convert amperes to biots
template<>
struct base_unit_converter<current_tag,SI::system_tag,CGS::system_tag> 
#ifdef BOOST_UNITS_ENABLE_IMPLICIT_UNIT_CONVERSION
    : public implicitly_convertible
#endif
{
    typedef double type;
    static type value() { return(0.1); }
};

/// convert SI kelvin to CGS kelvin
template<>
struct base_unit_converter<temperature_tag,SI::system_tag,CGS::system_tag> :
    public implicitly_convertible,
    public trivial_conversion
{ };
    
/// convert SI moles to CGS moles
template<>
struct base_unit_converter<amount_tag,SI::system_tag,CGS::system_tag> :
    public implicitly_convertible,
    public trivial_conversion
{ };

/// convert SI candelas to CGS candelas
template<>
struct base_unit_converter<intensity_tag,SI::system_tag,CGS::system_tag> :
    public implicitly_convertible,
    public trivial_conversion
{ };

/// convert SI radians to CGS radians   
template<>
struct base_unit_converter<angle_tag,SI::system_tag,CGS::system_tag> :
    public implicitly_convertible,
    public trivial_conversion
{ };
    
/// convert SI steradians to CGS steradians
template<>
struct base_unit_converter<solid_angle_tag,SI::system_tag,CGS::system_tag> :
    public implicitly_convertible,
    public trivial_conversion
{ };
    
} // namespace units

} // namespace boost

#endif // BOOST_UNITS_SI_CONVERT_SI_TO_CGS_HPP
