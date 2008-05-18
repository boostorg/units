// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2007-2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

/** 
\file
    
\brief test_scaled_conversion.cpp

\detailed
Test unit scaling

Output:
@verbatim
@endverbatim
**/

#define BOOST_TEST_MAIN

#include <boost/units/systems/si/prefixes.hpp>
#include <boost/units/systems/si/time.hpp>

#include <sstream>

#include <boost/test/unit_test.hpp>

namespace bu = boost::units;
namespace SI = boost::units::SI;

BOOST_AUTO_TEST_CASE(test_floating_point) {
    bu::quantity<SI::time> s1 = 12.5 * SI::seconds;
    bu::quantity<SI::time> s2(SI::nano * s1);
    BOOST_CHECK_CLOSE_FRACTION(1e-9 * s1.value(), s2.value(), 0.000000001);
}

BOOST_AUTO_TEST_CASE(test_output) {
    std::stringstream stream;
    stream << SI::nano * 12.5 * SI::seconds;
    BOOST_CHECK_EQUAL(stream.str(), "12.5 10^-9 s");
}
