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
    
\brief fail_implicit_conversion.cpp

\detailed
Test implicit conversions for quantity.

Output:
@verbatim
@endverbatim
**/

#include <boost/units/quantity.hpp>
#include <boost/units/systems/si.hpp>
#include <boost/units/systems/cgs.hpp>
#include <boost/units/systems/conversions/convert_si_to_cgs.hpp>
#include <boost/units/systems/conversions/convert_cgs_to_si.hpp>

namespace bu = boost::units;

int main(int argc,char *argv[])
{
    #ifndef BOOST_UNITS_ENABLE_IMPLICIT_UNIT_CONVERSION
    const bu::quantity<bu::SI::length>  T1(2.0 * bu::SI::meters);
    const bu::quantity<bu::CGS::length> T2 = T1;
    #endif // BOOST_UNITS_ENABLE_IMPLICIT_UNIT_CONVERSION
    
    return 0;
}
