// Boost.Units - A C++ library for zero-overhead dimensional analysis and
// unit/quantity manipulation and conversion
//
// Copyright (C) 2016 Giel van Schijndel
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

/**
\file

\brief test_heterogenous_comparison.cpp

\details
Verify that comparing a quantity from a heterogenous system with a
quantity from a homogenous system works.

Output:
@verbatim
@endverbatim
**/

#include <boost/units/quantity.hpp>
#include <boost/units/systems/si/length.hpp>

namespace bu = boost::units;

int main(int,char *[])
{
    bu::quantity<bu::si::meter_base_unit::unit_type> x;
    int y = 0;

    x < y * bu::si::meter;

    return 0;
}

