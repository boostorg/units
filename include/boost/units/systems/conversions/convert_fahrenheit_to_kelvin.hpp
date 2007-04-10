// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_CONVERT_FAHRENHEIT_TO_KELVIN_HPP
#define BOOST_UNITS_CONVERT_FAHRENHEIT_TO_KELVIN_HPP

#include <boost/units/conversion.hpp>
#include <boost/units/systems/si/temperature.hpp>
#include <boost/units/systems/temperature/fahrenheit.hpp>

namespace boost {

namespace units { 

// convert temperature differences in Fahrenheit to Kelvin

template<>
struct base_unit_converter<temperature_dim,fahrenheit::system_tag,SI::system_tag> :
#ifdef BOOST_UNITS_ENABLE_IMPLICIT_UNIT_CONVERSION
    public implicitly_convertible, 
#endif
    public trivial_inverse_conversion
{
    typedef double type;
    static type value() { return (5.0/9.0); }
};

// convert absolute temperature in Fahrenheit to Kelvin

template<class Y>
class conversion_helper< quantity<unit<temperature_type,fahrenheit::system>,absolute<Y> >,
                         quantity<unit<temperature_type,SI::system>,absolute<Y> > >
{
    public:
        typedef unit<temperature_type,fahrenheit::system>   unit1_type;
        typedef unit<temperature_type,SI::system>           unit2_type;
        
        typedef quantity<unit1_type,absolute<Y> >           from_quantity_type;
        typedef quantity<unit2_type,absolute<Y> >           to_quantity_type;

        static
        to_quantity_type
        convert(const from_quantity_type& source)
        {
            const typename from_quantity_type::value_type&   in(source.value());
            
            return to_quantity_type::from_value((in.value()-32.0)*(5.0/9.0) + 273.15);
        }
};


} // namespace units

} // namespace boost

#endif // BOOST_UNITS_CONVERT_FAHRENHEIT_TO_KELVIN_HPP
