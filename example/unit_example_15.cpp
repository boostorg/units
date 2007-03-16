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
    
\brief unit_example_15.cpp

\detailed
Demonstrate very simple unit systems for coordinate transformations

Output:
@verbatim


@endverbatim
**/

#include <iostream>

#include <boost/array.hpp>

#include <boost/units/quantity.hpp>

namespace boost {

namespace units {

namespace wo {

struct world_space_tag : public ordinal<101> { }; 
struct object_space_tag : public ordinal<102> { };

typedef fundamental_dimension<world_space_tag>::type    world_space_type;
typedef fundamental_dimension<object_space_tag>::type   object_space_type;

/// placeholder class defining test unit system
struct system { };

/// unit typedefs
typedef unit<system,dimensionless_type>     dimensionless;

typedef unit<system,world_space_type>       world_space_unit;
typedef unit<system,object_space_type>      object_space_unit;

static const world_space_unit   world_space;
static const object_space_unit  object_space;

} // namespace wo

} // namespace units

} // namespace boost

int main(void)
{
    using namespace boost::units;
    using namespace boost::units::wo;
    
    {
    typedef boost::array<double,3>  vector;
    
    const vector    vec1 = { 0, 0, 0 },
                    vec2 = { 1, 1, 1 };
                    
    quantity<world_space_unit,vector>   wsv1(vec1*world_space),
                                        wsv2(vec2*world_space);
    quantity<object_space_unit,vector>  osv1(vec1*object_space),
                                        osv2(vec2*object_space);
    
    quantity<world_space_unit,vector>   wsv3(wsv1);
    quantity<object_space_unit,vector>  osv3(osv1);

#if defined(BOOST_UNITS_EXAMPLE_15_FAIL) && BOOST_UNITS_EXAMPLE_15_FAIL == 1    
    // compile-time error if either of these is uncommented
    quantity<world_space_unit,vector>   wsv4(osv1);
    quantity<object_space_unit,vector>  osv4(wsv1);

#endif
    }
    
    {
    typedef quantity<world_space_unit>  world_space_quantity;
    typedef quantity<object_space_unit> object_space_quantity;
    
    typedef boost::array<world_space_quantity,3>    world_space_vector;
    typedef boost::array<object_space_quantity,3>   object_space_vector;
    
    world_space_vector  wsv1 = { 0*world_space, 0*world_space, 0*world_space },
                        wsv2 = { 1*world_space, 1*world_space, 1*world_space };
    object_space_vector osv1 = { 0*object_space, 0*object_space, 0*object_space },
                        osv2 = { 1*object_space, 1*object_space, 1*object_space };
    
    world_space_vector  wsv3(wsv1);
    object_space_vector osv3(osv1);
    
#if defined(BOOST_UNITS_EXAMPLE_15_FAIL) && BOOST_UNITS_EXAMPLE_15_FAIL == 2
    // compile-time error if either of these is uncommented
    world_space_vector  wsv4(osv1);
    object_space_vector osv4(wsv1);
#endif
    }
    
    return 0;
}
