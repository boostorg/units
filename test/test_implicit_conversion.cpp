// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

/** 
\file
    
\brief test_implicit_conversion.cpp

\detailed
Test implicit conversions for quantity.

Output:
@verbatim
@endverbatim
**/

#include <boost/test/minimal.hpp>

#include <boost/units/static_constant.hpp>
#include <boost/units/quantity.hpp>
#include <boost/units/systems/si.hpp>
#include <boost/units/systems/cgs.hpp>
//#include <boost/units/systems/conversions/convert_si_to_cgs.hpp>
//#include <boost/units/systems/conversions/convert_cgs_to_si.hpp>

namespace bu = boost::units;

int test_main(int,char *[])
{
    //// SI->SI always true
    //BOOST_CHECK((bu::base_unit_is_implicitly_convertible<bu::length_base_dimension,bu::SI::system_tag,bu::SI::system_tag>::value == true));
    //BOOST_CHECK((bu::base_unit_is_implicitly_convertible<bu::mass_base_dimension,bu::SI::system_tag,bu::SI::system_tag>::value == true));
    //BOOST_CHECK((bu::base_unit_is_implicitly_convertible<bu::time_base_dimension,bu::SI::system_tag,bu::SI::system_tag>::value == true));
    //BOOST_CHECK((bu::base_unit_is_implicitly_convertible<bu::current_base_dimension,bu::SI::system_tag,bu::SI::system_tag>::value == true));
    //BOOST_CHECK((bu::base_unit_is_implicitly_convertible<bu::temperature_base_dimension,bu::SI::system_tag,bu::SI::system_tag>::value == true));
    //BOOST_CHECK((bu::base_unit_is_implicitly_convertible<bu::amount_base_dimension,bu::SI::system_tag,bu::SI::system_tag>::value == true));
    //BOOST_CHECK((bu::base_unit_is_implicitly_convertible<bu::luminous_intensity_base_dimension,bu::SI::system_tag,bu::SI::system_tag>::value == true));
    //BOOST_CHECK((bu::base_unit_is_implicitly_convertible<bu::plane_angle_base_dimension,bu::SI::system_tag,bu::SI::system_tag>::value == true));
    //BOOST_CHECK((bu::base_unit_is_implicitly_convertible<bu::solid_angle_base_dimension,bu::SI::system_tag,bu::SI::system_tag>::value == true));

    //// CGS->CGS always true
    //BOOST_CHECK((bu::base_unit_is_implicitly_convertible<bu::length_base_dimension,bu::CGS::system_tag,bu::CGS::system_tag>::value == true));
    //BOOST_CHECK((bu::base_unit_is_implicitly_convertible<bu::mass_base_dimension,bu::CGS::system_tag,bu::CGS::system_tag>::value == true));
    //BOOST_CHECK((bu::base_unit_is_implicitly_convertible<bu::time_base_dimension,bu::CGS::system_tag,bu::CGS::system_tag>::value == true));
    //BOOST_CHECK((bu::base_unit_is_implicitly_convertible<bu::current_base_dimension,bu::CGS::system_tag,bu::CGS::system_tag>::value == true));
    //BOOST_CHECK((bu::base_unit_is_implicitly_convertible<bu::temperature_base_dimension,bu::CGS::system_tag,bu::CGS::system_tag>::value == true));
    //BOOST_CHECK((bu::base_unit_is_implicitly_convertible<bu::amount_base_dimension,bu::CGS::system_tag,bu::CGS::system_tag>::value == true));
    //BOOST_CHECK((bu::base_unit_is_implicitly_convertible<bu::luminous_intensity_base_dimension,bu::CGS::system_tag,bu::CGS::system_tag>::value == true));
    //BOOST_CHECK((bu::base_unit_is_implicitly_convertible<bu::plane_angle_base_dimension,bu::CGS::system_tag,bu::CGS::system_tag>::value == true));
    //BOOST_CHECK((bu::base_unit_is_implicitly_convertible<bu::solid_angle_base_dimension,bu::CGS::system_tag,bu::CGS::system_tag>::value == true));

    //// SI->CGS
    //BOOST_CHECK((bu::base_unit_is_implicitly_convertible<bu::length_base_dimension,bu::SI::system_tag,bu::CGS::system_tag>::value == false));
    //BOOST_CHECK((bu::base_unit_is_implicitly_convertible<bu::mass_base_dimension,bu::SI::system_tag,bu::CGS::system_tag>::value == false));
    //BOOST_CHECK((bu::base_unit_is_implicitly_convertible<bu::time_base_dimension,bu::SI::system_tag,bu::CGS::system_tag>::value == true));
    
    BOOST_CHECK((bu::is_implicitly_convertible<bu::SI::length,bu::CGS::length>::value == false));
    BOOST_CHECK((bu::is_implicitly_convertible<bu::SI::mass,bu::CGS::mass>::value == false));
    BOOST_CHECK((bu::is_implicitly_convertible<bu::SI::time,bu::CGS::time>::value == true));

    BOOST_CHECK((bu::is_implicitly_convertible<bu::SI::acceleration,bu::CGS::acceleration>::value == false));
    BOOST_CHECK((bu::is_implicitly_convertible<bu::SI::area,bu::CGS::area>::value == false));
    BOOST_CHECK((bu::is_implicitly_convertible<bu::SI::energy,bu::CGS::energy>::value == false));
    BOOST_CHECK((bu::is_implicitly_convertible<bu::SI::force,bu::CGS::force>::value == false));
    BOOST_CHECK((bu::is_implicitly_convertible<bu::SI::frequency,bu::CGS::frequency>::value == true));
    BOOST_CHECK((bu::is_implicitly_convertible<bu::SI::mass_density,bu::CGS::mass_density>::value == false));
    BOOST_CHECK((bu::is_implicitly_convertible<bu::SI::momentum,bu::CGS::momentum>::value == false));
    BOOST_CHECK((bu::is_implicitly_convertible<bu::SI::power,bu::CGS::power>::value == false));
    BOOST_CHECK((bu::is_implicitly_convertible<bu::SI::pressure,bu::CGS::pressure>::value == false));
    BOOST_CHECK((bu::is_implicitly_convertible<bu::SI::velocity,bu::CGS::velocity>::value == false));
    BOOST_CHECK((bu::is_implicitly_convertible<bu::SI::wavenumber,bu::CGS::wavenumber>::value == false));
    
    //// CGS->SI
    //BOOST_CHECK((bu::base_unit_is_implicitly_convertible<bu::length_base_dimension,bu::CGS::system_tag,bu::SI::system_tag>::value == false));
    //BOOST_CHECK((bu::base_unit_is_implicitly_convertible<bu::mass_base_dimension,bu::CGS::system_tag,bu::SI::system_tag>::value == false));
    //BOOST_CHECK((bu::base_unit_is_implicitly_convertible<bu::time_base_dimension,bu::CGS::system_tag,bu::SI::system_tag>::value == true));
              
    BOOST_CHECK((bu::is_implicitly_convertible<bu::CGS::length,bu::SI::length>::value == false));
    BOOST_CHECK((bu::is_implicitly_convertible<bu::CGS::mass,bu::SI::mass>::value == false));
    BOOST_CHECK((bu::is_implicitly_convertible<bu::CGS::time,bu::SI::time>::value == true));

    BOOST_CHECK((bu::is_implicitly_convertible<bu::CGS::acceleration,bu::SI::acceleration>::value == false));
    BOOST_CHECK((bu::is_implicitly_convertible<bu::CGS::area,bu::SI::area>::value == false));
    BOOST_CHECK((bu::is_implicitly_convertible<bu::CGS::energy,bu::SI::energy>::value == false));
    BOOST_CHECK((bu::is_implicitly_convertible<bu::CGS::force,bu::SI::force>::value == false));
    BOOST_CHECK((bu::is_implicitly_convertible<bu::CGS::frequency,bu::SI::frequency>::value == true));
    BOOST_CHECK((bu::is_implicitly_convertible<bu::CGS::mass_density,bu::SI::mass_density>::value == false));
    BOOST_CHECK((bu::is_implicitly_convertible<bu::CGS::momentum,bu::SI::momentum>::value == false));
    BOOST_CHECK((bu::is_implicitly_convertible<bu::CGS::power,bu::SI::power>::value == false));
    BOOST_CHECK((bu::is_implicitly_convertible<bu::CGS::pressure,bu::SI::pressure>::value == false));
    BOOST_CHECK((bu::is_implicitly_convertible<bu::CGS::velocity,bu::SI::velocity>::value == false));
    BOOST_CHECK((bu::is_implicitly_convertible<bu::CGS::wavenumber,bu::SI::wavenumber>::value == false));
    
    const bu::quantity<bu::SI::time>    S1(2.0*bu::SI::seconds);
    const bu::quantity<bu::CGS::time>   S2 = S1;

    BOOST_CHECK((S1.value() == S2.value()));
    
    const bu::quantity<bu::SI::catalytic_activity>  S3(2.0*bu::SI::catalytic_activity());
    
    
    const bu::quantity<bu::CGS::time>   C1(2.0*bu::CGS::seconds);
    const bu::quantity<bu::SI::time>    C2 = C1;

    BOOST_CHECK((C1.value() == C2.value()));

    return 0;
}
