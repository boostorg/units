// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/test/minimal.hpp>

#include <boost/units/base_dimension.hpp>
#include <boost/units/base_unit.hpp>
#include <boost/units/conversion.hpp>
#include <boost/units/unit.hpp>

struct dimension_tag : boost::units::base_dimension<dimension_tag, 1> {};

typedef dimension_tag::dimension_type dimension;

struct unit1_tag : boost::units::base_unit<unit1_tag, dimension, 1> {}; 

struct unit2_tag : boost::units::base_unit<unit2_tag, dimension, 2> {};

struct unit3_tag : boost::units::base_unit<unit3_tag, dimension, 3> {};

BOOST_UNITS_DEFINE_BASE_CONVERSION(unit1_tag, unit2_tag, double, 2.0);

BOOST_UNITS_DEFINE_BASE_CONVERSION(unit2_tag, unit3_tag, double, 3.0);

BOOST_UNITS_DEFAULT_CONVERSION(unit1_tag, unit2_tag::unit_type);

BOOST_UNITS_DEFAULT_CONVERSION(unit3_tag, unit2_tag::unit_type);

int test_main(int, char*[]) {
    double value = boost::units::conversion_factor(unit3_tag::unit_type(), unit1_tag::unit_type());
    BOOST_CHECK(std::abs(value - 1.0/6.0) < .0000000001);
    return(0);
}
