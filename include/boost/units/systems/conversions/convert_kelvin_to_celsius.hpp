// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_CONVERT_KELVIN_TO_CELSIUS_HPP
#define BOOST_UNITS_CONVERT_KELVIN_TO_CELSIUS_HPP

#include <boost/units/conversion.hpp>
#include <boost/units/systems/si/temperature.hpp>
#include <boost/units/systems/temperature/celsius.hpp>

#include <boost/units/systems/conversions/convert_celsius_to_kelvin.hpp>

namespace boost {

namespace units { 

// convert absolute temperature in Kelvin to Celsius
        
template<class Y>
class conversion_helper< quantity<unit<temperature_type,SI::system>,absolute<Y> >,
                         quantity<unit<temperature_type,celsius::system>,absolute<Y> > >
{
    public:
        typedef unit<temperature_type,SI::system>           unit1_type;
        typedef unit<temperature_type,celsius::system>      unit2_type;
        
        typedef quantity<unit1_type,absolute<Y> >           from_quantity_type;
        typedef quantity<unit2_type,absolute<Y> >           to_quantity_type;

        static
        to_quantity_type
        convert(const from_quantity_type& source)
        {
            const typename from_quantity_type::value_type&   in(source.value());
            
            return to_quantity_type::from_value(in.value() - 273.15);
        }
};

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_CONVERT_KELVIN_TO_CELSIUS_HPP
