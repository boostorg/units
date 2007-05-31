// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_TEMPERATURE_FAHRENHEIT_HPP
#define BOOST_UNITS_TEMPERATURE_FAHRENHEIT_HPP

#include <string>

#include <boost/units/absolute.hpp>
#include <boost/units/io.hpp>
#include <boost/units/static_constant.hpp>
#include <boost/units/system.hpp>
#include <boost/units/systems/physical_units.hpp>

namespace boost {

namespace units {

namespace fahrenheit {

struct system_tag : public ordinal<110> { };

typedef homogeneous_system<system_tag>  system;

typedef fundamental_dimension<temperature_tag>::type    temperature_dimension;

typedef unit<temperature_dimension,system>                   temperature;

BOOST_UNITS_STATIC_CONSTANT(degree,temperature);
BOOST_UNITS_STATIC_CONSTANT(degrees,temperature);

} // fahrenheit

template<> struct unit_info<fahrenheit::system_tag,temperature_tag>
{
    static std::string name()               { return "Fahrenheit"; }
    static std::string symbol()             { return "F"; }
};

template<>
struct is_implicitly_convertible< unit<temperature_dimension,fahrenheit::system>,
                                  unit<temperature_dimension,SI::system> > : 
    public mpl::true_
{ };

template<class Y>
class conversion_helper< quantity<unit<temperature_dimension,fahrenheit::system>,absolute<Y> >,
                         quantity<unit<temperature_dimension,SI::system>,absolute<Y> > >
{
    public:
        typedef unit<temperature_dimension,fahrenheit::system>   unit1_type;
        typedef unit<temperature_dimension,SI::system>           unit2_type;
        
        typedef quantity<unit1_type,absolute<Y> >           from_quantity_type;
        typedef quantity<unit2_type,absolute<Y> >           to_quantity_type;

        static
        to_quantity_type
        convert(const from_quantity_type& source)
        {
            const typename from_quantity_type::value_type&   in(source.value());
            
            return to_quantity_type::from_value((in.value()-32)*(5.0/9.0) + 273.16);
        }
};

template<class Y>
class conversion_helper< quantity<unit<temperature_dimension,fahrenheit::system>,Y >,
                         quantity<unit<temperature_dimension,SI::system>,Y > >
{
    public:
        typedef unit<temperature_dimension,fahrenheit::system>   unit1_type;
        typedef unit<temperature_dimension,SI::system>           unit2_type;
        
        typedef quantity<unit1_type,relative<Y> >           from_quantity_type;
        typedef quantity<unit2_type,relative<Y> >           to_quantity_type;

        static
        to_quantity_type
        convert(const from_quantity_type& source)
        {
            const typename from_quantity_type::value_type&   in(source.value());
            
            return to_quantity_type::from_value(in.value()*(5.0/9.0));
        }
};

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_TEMPERATURE_FAHRENHEIT_HPP