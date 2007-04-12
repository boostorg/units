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
    
\brief test_predicates.cpp

\detailed
Test metafunctions is_unit, is_quantity, is_dimension_list ....

Output:
@verbatim
@endverbatim
**/

#include <boost/mpl/assert.hpp>
#include <boost/mpl/list/list0.hpp>

#include <boost/units/dimension.hpp>
#include <boost/units/quantity.hpp>
#include <boost/units/unit.hpp>

namespace bu = boost::units;

BOOST_UNITS_REGISTER_BASE_DIMENSION(dimension_tag, 0);

struct system1 : bu::ordinal<100> {};
struct system2 : bu::ordinal<101> {};

typedef dimension_tag::type dimension;

int main(int,char *[])
{
    BOOST_MPL_ASSERT((bu::is_dimension_list<bu::dimensionless_type>));
    BOOST_MPL_ASSERT((bu::is_dimension_list<dimension>));
    BOOST_MPL_ASSERT_NOT((bu::is_dimension_list<boost::mpl::list0<> >));
    BOOST_MPL_ASSERT_NOT((bu::is_dimension_list<int>));

    BOOST_MPL_ASSERT((bu::is_unit<bu::unit<bu::dimensionless_type, system1> >));
    BOOST_MPL_ASSERT((bu::is_unit<bu::unit<dimension, system1> >));
    BOOST_MPL_ASSERT_NOT((bu::is_unit<int>));

    BOOST_MPL_ASSERT((bu::is_unit_of_system<bu::unit<bu::dimensionless_type, system1>, system1>));
    BOOST_MPL_ASSERT((bu::is_unit_of_system<bu::unit<dimension, system1>, system1>));
    BOOST_MPL_ASSERT_NOT((bu::is_unit_of_system<bu::unit<bu::dimensionless_type, system1>, system2>));
    BOOST_MPL_ASSERT_NOT((bu::is_unit_of_system<bu::unit<dimension, system1>, system2>));
    BOOST_MPL_ASSERT_NOT((bu::is_unit_of_system<int, system1>));
    BOOST_MPL_ASSERT_NOT((bu::is_unit_of_system<int, system2>));

    BOOST_MPL_ASSERT((bu::is_unit_of_dimension<bu::unit<bu::dimensionless_type, system1>, bu::dimensionless_type>));
    BOOST_MPL_ASSERT((bu::is_unit_of_dimension<bu::unit<dimension, system1>, dimension>));
    BOOST_MPL_ASSERT_NOT((bu::is_unit_of_dimension<bu::unit<bu::dimensionless_type, system1>, dimension>));
    BOOST_MPL_ASSERT_NOT((bu::is_unit_of_dimension<bu::unit<dimension, system1>, bu::dimensionless_type>));
    BOOST_MPL_ASSERT_NOT((bu::is_unit_of_dimension<int, bu::dimensionless_type>));
    BOOST_MPL_ASSERT_NOT((bu::is_unit_of_dimension<int, dimension>));

    BOOST_MPL_ASSERT((bu::is_quantity<bu::quantity<bu::unit<bu::dimensionless_type, system1> > >));
    BOOST_MPL_ASSERT((bu::is_quantity<bu::quantity<bu::unit<dimension, system1> > >));
    BOOST_MPL_ASSERT_NOT((bu::is_quantity<int>));

    BOOST_MPL_ASSERT((bu::is_quantity<bu::quantity<bu::unit<bu::dimensionless_type, system1>, int> >));
    BOOST_MPL_ASSERT((bu::is_quantity<bu::quantity<bu::unit<dimension, system1>, int> >));

    BOOST_MPL_ASSERT((bu::is_quantity_of_system<bu::quantity<bu::unit<bu::dimensionless_type, system1> >, system1>));
    BOOST_MPL_ASSERT((bu::is_quantity_of_system<bu::quantity<bu::unit<dimension, system1> >, system1>));
    BOOST_MPL_ASSERT_NOT((bu::is_quantity_of_system<bu::quantity<bu::unit<bu::dimensionless_type, system1> >, system2>));
    BOOST_MPL_ASSERT_NOT((bu::is_quantity_of_system<bu::quantity<bu::unit<dimension, system1> >, system2>));
    BOOST_MPL_ASSERT_NOT((bu::is_quantity_of_system<int, system1>));
    BOOST_MPL_ASSERT_NOT((bu::is_quantity_of_system<int, system2>));

    BOOST_MPL_ASSERT((bu::is_quantity_of_dimension<bu::quantity<bu::unit<bu::dimensionless_type, system1> >, bu::dimensionless_type>));
    BOOST_MPL_ASSERT((bu::is_quantity_of_dimension<bu::quantity<bu::unit<dimension, system1> >, dimension>));
    BOOST_MPL_ASSERT_NOT((bu::is_quantity_of_dimension<bu::quantity<bu::unit<bu::dimensionless_type, system1> >, dimension>));
    BOOST_MPL_ASSERT_NOT((bu::is_quantity_of_dimension<bu::quantity<bu::unit<dimension, system1> >, bu::dimensionless_type>));
    BOOST_MPL_ASSERT_NOT((bu::is_quantity_of_dimension<int, bu::dimensionless_type>));
    BOOST_MPL_ASSERT_NOT((bu::is_quantity_of_dimension<int, dimension>));

    return 0;
}
