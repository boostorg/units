// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef MCS_TEST_SYSTEM_HPP
#define MCS_TEST_SYSTEM_HPP

#include <boost/mpl/list.hpp>
#include <boost/mpl/vector.hpp>

#include <boost/units/io.hpp>
#include <boost/units/quantity.hpp>
#include <boost/units/static_constant.hpp>
#include <boost/units/unit.hpp>

namespace boost {

namespace units {

//[test_system_snippet_1
struct length_tag : public ordinal<1> { }; 
struct mass_tag : public ordinal<2> { };
struct time_tag : public ordinal<3> { };
//]

#if 0
//[test_system_snippet_2
typedef make_dimension_list< boost::mpl::list< dim< length_tag,static_rational<1> > > >::type   length_type;
typedef make_dimension_list< boost::mpl::list< dim< mass_tag,static_rational<1> > > >::type     mass_type;
typedef make_dimension_list< boost::mpl::list< dim< time_tag,static_rational<1> > > >::type     time_type;
//]
#endif

//[test_system_snippet_3
typedef fundamental_dimension<length_tag>::type length_type;
typedef fundamental_dimension<mass_tag>::type   mass_type;
typedef fundamental_dimension<time_tag>::type   time_type;
//]

#if 0
//[test_system_snippet_4
typedef make_dimension_list< boost::mpl::list< dim< length_tag,static_rational<2> > > >::type   area_type;
typedef make_dimension_list< boost::mpl::list< dim< mass_tag,static_rational<1> >,
                                               dim< length_tag,static_rational<2> >,
                                               dim< time_tag,static_rational<-2> > > >::type    energy_type;
//]
#endif

//[test_system_snippet_5
typedef composite_dimension<length_tag,2>::type area_type;
typedef composite_dimension<mass_tag,1,
                            length_tag,2,
                            time_tag,-2>::type  energy_type;
//]

namespace test {

//[test_system_snippet_6
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
//]

//[test_system_snippet_7
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
//]

} // namespace test

//[test_system_snippet_8
template<> struct base_unit_info<length_tag,test::system_tag>
{
    static std::string name()               { return "meter"; }
    static std::string symbol()             { return "m"; }
};
//]

template<> struct base_unit_info<mass_tag,test::system_tag>
{
    static std::string name()               { return "kilogram"; }
    static std::string symbol()             { return "kg"; }
};

template<> struct base_unit_info<time_tag,test::system_tag>
{
    static std::string name()               { return "second"; }
    static std::string symbol()             { return "s"; }
};

} // namespace units

} // namespace boost

#endif // MCS_TEST_SYSTEM_HPP
