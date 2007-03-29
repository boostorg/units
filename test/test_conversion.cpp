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
    
\brief test_conversion.cpp

\detailed
Test conversion between quantities.

Output:
@verbatim
@endverbatim
**/

#include <boost/units/quantity.hpp>
#include <boost/units/systems/si.hpp>
#include <boost/units/systems/cgs.hpp>
#include <boost/units/systems/conversions/convert_si_to_cgs.hpp>
#include <boost/units/systems/conversions/convert_cgs_to_si.hpp>

#include <iostream>

#include <boost/test/minimal.hpp>

namespace bu = boost::units;

typedef bu::SI::length si_length;
typedef bu::SI::time    si_time;
typedef bu::SI::mass    si_mass;
typedef bu::SI::area    si_area;

typedef bu::CGS::length cgs_length;
typedef bu::CGS::time   cgs_time;
typedef bu::CGS::mass   cgs_mass;
typedef bu::CGS::area   cgs_area;

typedef bu::multiply_typeof_helper<si_length, cgs_length>::type     mixed_length;
typedef bu::multiply_typeof_helper<si_time, cgs_time>::type         mixed_time;

typedef bu::divide_typeof_helper<bu::multiply_typeof_helper<si_mass,cgs_area>::type, mixed_time>::type  mixed_energy_1;
typedef bu::divide_typeof_helper<bu::multiply_typeof_helper<cgs_mass,mixed_length>::type, 
                                 bu::multiply_typeof_helper<cgs_time,cgs_time>::type >::type            mixed_energy_2;

int test_main(int,char *[])
{
    bu::quantity<mixed_length> a1(2.0 * mixed_length());
    bu::quantity<si_area> a2(a1);

    BOOST_CHECK((std::abs(a2.value() - .02) < .0001));

    bu::quantity<mixed_length> a3(a2);

    BOOST_CHECK((std::abs(a3.value() - 2.0) < .0001));

    bu::quantity<mixed_energy_1> e1(2.0 * mixed_energy_1());
    bu::quantity<mixed_energy_2> e2(e1);

    BOOST_CHECK((std::abs(e2.value() - 20.0) < .0001));

    bu::quantity<bu::SI::energy> e3(e1);
    BOOST_CHECK((std::abs(e3.value() - .0002) < .0001));
    bu::quantity<mixed_energy_2> e4(e3);
    BOOST_CHECK((std::abs(e4.value() - 20.0) < .0001));



    bu::quantity<bu::CGS::force> F0 = 20 * bu::CGS::dyne;
    BOOST_CHECK((std::abs(F0.value() - 20.0) < .0001));

    bu::quantity<bu::SI::force> F1 = bu::quantity_cast<bu::quantity<bu::SI::force> >(F0);
    BOOST_CHECK((std::abs(F1.value() - 2.0e-4) < .000000001));
	bu::quantity<bu::SI::force> F2 = bu::quantity_cast<bu::quantity<bu::SI::force> >(20 * bu::CGS::dyne);
    BOOST_CHECK((std::abs(F2.value() - 2.0e-4) < .000000001));

	bu::quantity<bu::SI::force> F3(F0);
    BOOST_CHECK((std::abs(F3.value() - 2.0e-4) < .000000001));
	//quantity<SI::force> F4 = F0;

	bu::quantity<bu::SI::force> F5(20 * bu::CGS::dyne);
    BOOST_CHECK((std::abs(F5.value() - 2.0e-4) < .000000001));
	//quantity<SI::force> F6 = 20 * CGS::dyne;

    return(0);
}

