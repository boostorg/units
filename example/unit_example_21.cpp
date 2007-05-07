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
#include <boost/units/ordinal.hpp>
#include <boost/units/unit.hpp>
#include <boost/units/quantity.hpp>
#include <boost/units/systems/physical_units.hpp>

namespace boost {

namespace units {

struct imperial : public ordinal<1000> { };

typedef unit<volume_type,imperial>	imperial_gallon;

struct us : public ordinal<1001> { };

typedef unit<volume_type,us>			us_gallon;

/// convert imperial gallons to us gallons
template<class Y>
class conversion_helper< quantity<unit<volume_type,imperial>,Y>,
                         quantity<unit<volume_type,us>,Y> >
{
    public:
        typedef quantity<unit<volume_type,imperial>,Y>    from_quantity_type;
        typedef quantity<unit<volume_type,us>,Y>          to_quantity_type;

        static
        to_quantity_type
        convert(const from_quantity_type& source)
        {
            return to_quantity_type::from_value(source.value()*1.2009499255);
        }
};

/// convert us gallons to imperial gallons
template<class Y>
class conversion_helper< quantity<unit<volume_type,us>,Y>,
                         quantity<unit<volume_type,imperial>,Y> >
{
    public:
        typedef quantity<unit<volume_type,us>,Y>          from_quantity_type;
        typedef quantity<unit<volume_type,imperial>,Y>    to_quantity_type;

        static
        to_quantity_type
        convert(const from_quantity_type& source)
        {
            return to_quantity_type::from_value(source.value()/1.2009499255);
        }
};

template<>
struct is_implicitly_convertible<unit<volume_type,imperial>,
                                 unit<volume_type,us> > :
    public mpl::true_
{ };

template<>
struct is_implicitly_convertible<unit<volume_type,us>,
                                 unit<volume_type,imperial> > :
    public mpl::true_
{ };

} // namespace units

} // namespace boost

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
