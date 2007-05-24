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
    
\brief unit_example_10.cpp

\detailed
Demonstrate angle unit systems, trigonometric functions, and 

Output:
@verbatim

//[unit_example_10_output
thetad                 = 30 deg
thetag                 = 33.3333 grad
thetar                 = 0.523599 rad
cos(thetad)            = 0.866025 dimensionless
cos(thetag)            = 0.866025 dimensionless
cos(thetar)            = 0.866025 dimensionless
acos(cos(thetad))      = 30 deg
acos(cos(thetag))      = 33.3333 grad
acos(cos(thetar))      = 0.523599 rad
std::acos(cos(thetar)) = 0.523599

thetad                 = 30 deg
thetag                 = 33.3333 grad
thetar                 = 0.523599 rad
sin(thetad)            = 0.5 dimensionless
sin(thetag)            = 0.5 dimensionless
sin(thetar)            = 0.5 dimensionless
asin(sin(thetad))      = 30 deg
asin(sin(thetag))      = 33.3333 grad
asin(sin(thetar))      = 0.523599 rad
std::asin(sin(thetar)) = 0.523599

thetad                 = 30 deg
thetag                 = 33.3333 grad
thetar                 = 0.523599 rad
tan(thetad)            = 0.57735 dimensionless
tan(thetag)            = 0.57735 dimensionless
tan(thetar)            = 0.57735 dimensionless
atan(tan(thetad))      = 30 deg
atan(tan(thetag))      = 33.3333 grad
atan(tan(thetar))      = 0.523599 rad
std::atan(tan(thetar)) = 0.523599
//]

@endverbatim
**/

#include <iostream>
#include <sstream>
#include <algorithm>

#include <boost/units/io.hpp>
#include <boost/units/quantity.hpp>
#include <boost/units/conversion.hpp>
#include <boost/units/systems/si.hpp>
#include <boost/units/systems/angle/degrees.hpp>
#include <boost/units/systems/angle/gradians.hpp>
#include <boost/units/systems/si/plane_angle.hpp>
#include <boost/units/systems/trig.hpp>

//#include <boost/units/systems/conversions/convert_degrees_to_radians.hpp>
//#include <boost/units/systems/conversions/convert_gradians_to_radians.hpp>

int main(void)
{
    using namespace boost::units;

    std::stringstream sstream1, sstream2;
    
    //[unit_example_10_snippet_1
    quantity<degree::plane_angle>       thetad((180.0/6.0)*degree::degrees);
    quantity<gradian::plane_angle>      thetag((200.0/6.0)*gradian::gradians);
    quantity<SI::plane_angle>           thetar((3.1415926/6.0)*SI::radians);
    //]

    /// test cos 
    {
    quantity<degree::dimensionless>     cos_thetad(cos(thetad));
    quantity<gradian::dimensionless>    cos_thetag(cos(thetag));
    quantity<SI::dimensionless>         cos_thetar(cos(thetar));
    
    sstream1  << "thetad                 = " << thetad << std::endl
              << "thetag                 = " << thetag << std::endl
              << "thetar                 = " << thetar << std::endl
              << "cos(thetad)            = " << cos_thetad << std::endl
              << "cos(thetag)            = " << cos_thetag << std::endl
              << "cos(thetar)            = " << cos_thetar << std::endl
              << "acos(cos(thetad))      = " << acos(cos_thetad) << std::endl
              << "acos(cos(thetag))      = " << acos(cos_thetag) << std::endl
              << "acos(cos(thetar))      = " << acos(cos_thetar) << std::endl
              << "std::acos(cos(thetar)) = " << std::acos(cos_thetar) << std::endl
              << std::endl;
    }
    
    /// test sin 
    {
    quantity<degree::dimensionless>     sin_thetad(sin(thetad));
    quantity<gradian::dimensionless>    sin_thetag(sin(thetag));
    quantity<SI::dimensionless>         sin_thetar(sin(thetar));
    
    sstream1  << "thetad                 = " << thetad << std::endl
              << "thetag                 = " << thetag << std::endl
              << "thetar                 = " << thetar << std::endl
              << "sin(thetad)            = " << sin_thetad << std::endl
              << "sin(thetag)            = " << sin_thetag << std::endl
              << "sin(thetar)            = " << sin_thetar << std::endl
              << "asin(sin(thetad))      = " << asin(sin_thetad) << std::endl
              << "asin(sin(thetag))      = " << asin(sin_thetag) << std::endl
              << "asin(sin(thetar))      = " << asin(sin_thetar) << std::endl
              << "std::asin(sin(thetar)) = " << std::asin(sin_thetar) << std::endl
              << std::endl;
    }
    
    /// test tan 
    {
    quantity<degree::dimensionless>     tan_thetad(tan(thetad));
    quantity<gradian::dimensionless>    tan_thetag(tan(thetag));
    quantity<SI::dimensionless>         tan_thetar(tan(thetar));
    
    sstream1  << "thetad                 = " << thetad << std::endl
              << "thetag                 = " << thetag << std::endl
              << "thetar                 = " << thetar << std::endl
              << "tan(thetad)            = " << tan_thetad << std::endl
              << "tan(thetag)            = " << tan_thetag << std::endl
              << "tan(thetar)            = " << tan_thetar << std::endl
              << "atan(tan(thetad))      = " << atan(tan_thetad) << std::endl
              << "atan(tan(thetag))      = " << atan(tan_thetag) << std::endl
              << "atan(tan(thetar))      = " << atan(tan_thetar) << std::endl
              << "std::atan(tan(thetar)) = " << std::atan(tan_thetar) << std::endl
              << std::endl;
    }
    
    sstream2 << "thetad                 = 30 deg" << std::endl;
    sstream2 << "thetag                 = 33.3333 grad" << std::endl;
    sstream2 << "thetar                 = 0.523599 rad" << std::endl;
    sstream2 << "cos(thetad)            = 0.866025 dimensionless" << std::endl;
    sstream2 << "cos(thetag)            = 0.866025 dimensionless" << std::endl;
    sstream2 << "cos(thetar)            = 0.866025 dimensionless" << std::endl;
    sstream2 << "acos(cos(thetad))      = 30 deg" << std::endl;
    sstream2 << "acos(cos(thetag))      = 33.3333 grad" << std::endl;
    sstream2 << "acos(cos(thetar))      = 0.523599 rad" << std::endl;
    sstream2 << "std::acos(cos(thetar)) = 0.523599" << std::endl;
    sstream2 << std::endl;
    sstream2 << "thetad                 = 30 deg" << std::endl;
    sstream2 << "thetag                 = 33.3333 grad" << std::endl;
    sstream2 << "thetar                 = 0.523599 rad" << std::endl;
    sstream2 << "sin(thetad)            = 0.5 dimensionless" << std::endl;
    sstream2 << "sin(thetag)            = 0.5 dimensionless" << std::endl;
    sstream2 << "sin(thetar)            = 0.5 dimensionless" << std::endl;
    sstream2 << "asin(sin(thetad))      = 30 deg" << std::endl;
    sstream2 << "asin(sin(thetag))      = 33.3333 grad" << std::endl;
    sstream2 << "asin(sin(thetar))      = 0.523599 rad" << std::endl;
    sstream2 << "std::asin(sin(thetar)) = 0.523599" << std::endl;
    sstream2 << std::endl;
    sstream2 << "thetad                 = 30 deg" << std::endl;
    sstream2 << "thetag                 = 33.3333 grad" << std::endl;
    sstream2 << "thetar                 = 0.523599 rad" << std::endl;
    sstream2 << "tan(thetad)            = 0.57735 dimensionless" << std::endl;
    sstream2 << "tan(thetag)            = 0.57735 dimensionless" << std::endl;
    sstream2 << "tan(thetar)            = 0.57735 dimensionless" << std::endl;
    sstream2 << "atan(tan(thetad))      = 30 deg" << std::endl;
    sstream2 << "atan(tan(thetag))      = 33.3333 grad" << std::endl;
    sstream2 << "atan(tan(thetar))      = 0.523599 rad" << std::endl;
    sstream2 << "std::atan(tan(thetar)) = 0.523599" << std::endl;
    sstream2 << std::endl;

    std::string str1(sstream1.str());
    std::string str2(sstream2.str());

    std::cout << str1;
    
    if(str1 == str2) 
    {
        return(0);
    } 
    else 
    {
        std::cout << std::endl << str2 << std::endl;
        
        if(str1.size() < str2.size()) 
        {
            std::string::iterator iter = std::mismatch(str1.begin(), str1.end(), str2.begin()).first;
            
            std::cout << iter - str1.begin() << std::endl;
            std::cout << std::count(str1.begin(), iter, '\n') << std::endl;
        } 
        else 
        {
            std::string::iterator iter = std::mismatch(str2.begin(), str2.end(), str1.begin()).first;
            
            std::cout << iter - str2.begin() << std::endl;
            std::cout << std::count(str2.begin(), iter, '\n') << std::endl;
        }
        
        return(-1);
    }
}
