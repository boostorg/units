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
    
\brief unit_example_21.cpp

\detailed
Another example of user-defined units with conversions.

Output:
@verbatim

//[unit_example_21_output
//]

@endverbatim
**/

#include <iostream>

#include <boost/units/io.hpp>
#include <boost/units/conversion.hpp>
#include <boost/units/unit.hpp>
#include <boost/units/quantity.hpp>
#include <boost/units/systems/physical_units.hpp>
#include <boost/units/base_unit.hpp>
#include <boost/units/make_system.hpp>

namespace boost {

namespace units {

struct imperial_gallon_tag : base_unit<imperial_gallon_tag, volume_dim, 1> { };

typedef make_system<imperial_gallon_tag>::type imperial;

typedef unit<volume_dim,imperial>	imperial_gallon;

struct us_gallon_tag : base_unit<us_gallon_tag, volume_dim, 2> { };

typedef make_system<us_gallon_tag>::type us;

typedef unit<volume_dim,us>			us_gallon;

///// convert imperial gallons to us gallons
//template<class Y>
//class conversion_helper< quantity<unit<volume_dim,imperial>,Y>,
//                         quantity<unit<volume_dim,us>,Y> >
//{
//    public:
//        typedef quantity<unit<volume_dim,imperial>,Y>    from_quantity_type;
//        typedef quantity<unit<volume_dim,us>,Y>          to_quantity_type;
//
//        static
//        to_quantity_type
//        convert(const from_quantity_type& source)
//        {
//            return to_quantity_type::from_value(source.value()*1.2009499255);
//        }
//};
//
///// convert us gallons to imperial gallons
//template<class Y>
//class conversion_helper< quantity<unit<volume_dim,us>,Y>,
//                         quantity<unit<volume_dim,imperial>,Y> >
//{
//    public:
//        typedef quantity<unit<volume_dim,us>,Y>          from_quantity_type;
//        typedef quantity<unit<volume_dim,imperial>,Y>    to_quantity_type;
//
//        static
//        to_quantity_type
//        convert(const from_quantity_type& source)
//        {
//            return to_quantity_type::from_value(source.value()/1.2009499255);
//        }
//};

template<>
struct is_implicitly_convertible<unit<volume_dim,imperial>,
                                 unit<volume_dim,us> > :
    public mpl::true_
{ };

template<>
struct is_implicitly_convertible<unit<volume_dim,us>,
                                 unit<volume_dim,imperial> > :
    public mpl::true_
{ };

} // namespace units

} // namespace boost

BOOST_UNITS_DEFINE_CONVERSION(boost::units::imperial_gallon_tag, boost::units::us_gallon_tag::unit_type, double, 1.2009499255);

using namespace boost::units;

int main(void)
{
    quantity<imperial_gallon>   ig1(1.0*imperial_gallon());
    quantity<us_gallon>         ug1(1.0*us_gallon());
    
    quantity<imperial_gallon>   ig2;
    quantity<us_gallon>         ug2;
    
    ig2 = ug1;
    ug2 = ig1;
    
    return 0;
}
