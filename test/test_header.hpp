// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

/** 
\file
    
\brief test_header.hpp

\detailed
Unit system for test purposes.

Output:
@verbatim
@endverbatim
**/

#ifndef BOOST_UNITS_TEST_HEADER_HPP
#define BOOST_UNITS_TEST_HEADER_HPP

#include <boost/test/minimal.hpp>

#include <boost/units/static_constant.hpp>
#include <boost/units/quantity.hpp>
#include <boost/units/io.hpp>

#define BOOST_UNITS_CHECK_CLOSE(a, b) (BOOST_CHECK((std::abs((a) - (b)) < .0000001)))

namespace boost {

namespace units {

BOOST_UNITS_REGISTER_BASE_DIMENSION(length_dim, 1);
BOOST_UNITS_REGISTER_BASE_DIMENSION(mass_dim, 2);
BOOST_UNITS_REGISTER_BASE_DIMENSION(time_dim, 3);

typedef length_dim::type    length_type;
typedef mass_dim::type      mass_type;
typedef time_dim::type      time_type;

typedef derived_dimension<length_dim,2>::type area_type;
typedef derived_dimension<mass_dim,1,
                            length_dim,2,
                            time_dim,-2>::type  energy_type;
typedef derived_dimension<mass_dim,-1,
                            length_dim,-2,
                            time_dim,2>::type   inverse_energy_type;
typedef derived_dimension<length_dim,1,
                            time_dim,-1>::type  velocity_type;
typedef derived_dimension<length_dim,3>::type volume_type;

/// placeholder class defining test unit system
struct system_tag : public ordinal<101> { };

typedef homogeneous_system<system_tag>  system;

/// unit typedefs
typedef unit<dimensionless_type,system>     dimensionless;

typedef unit<length_type,system>            length;
typedef unit<mass_type,system>              mass;
typedef unit<time_type,system>              time;

typedef unit<area_type,system>              area;
typedef unit<energy_type,system>            energy;
typedef unit<inverse_energy_type,system>    inverse_energy;
typedef unit<velocity_type,system>          velocity;
typedef unit<volume_type,system>            volume;

/// unit constants 
BOOST_UNITS_STATIC_CONSTANT(meter,length);
BOOST_UNITS_STATIC_CONSTANT(meters,length);
BOOST_UNITS_STATIC_CONSTANT(kilogram,mass);
BOOST_UNITS_STATIC_CONSTANT(kilograms,mass);
BOOST_UNITS_STATIC_CONSTANT(second,time);
BOOST_UNITS_STATIC_CONSTANT(seconds,time);

BOOST_UNITS_STATIC_CONSTANT(square_meter,area);
BOOST_UNITS_STATIC_CONSTANT(square_meters,area);
BOOST_UNITS_STATIC_CONSTANT(joule,energy);
BOOST_UNITS_STATIC_CONSTANT(joules,energy);
BOOST_UNITS_STATIC_CONSTANT(meter_per_second,velocity);
BOOST_UNITS_STATIC_CONSTANT(meters_per_second,velocity);
BOOST_UNITS_STATIC_CONSTANT(cubic_meter,volume);
BOOST_UNITS_STATIC_CONSTANT(cubic_meters,volume);

template<> struct base_unit_info<length_dim,system_tag>
{
    static std::string name()               { return "meter"; }
    static std::string symbol()             { return "m"; }
};
//]

template<> struct base_unit_info<mass_dim,system_tag>
{
    static std::string name()               { return "kilogram"; }
    static std::string symbol()             { return "kg"; }
};

template<> struct base_unit_info<time_dim,system_tag>
{
    static std::string name()               { return "second"; }
    static std::string symbol()             { return "s"; }
};

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_TEST_HEADER_HPP
