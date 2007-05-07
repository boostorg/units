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
    
\brief unit_example_11.cpp

\detailed
Test @c <cmath> functions.

Output:
@verbatim

//[unit_example_11_output
q0 = inf m
q1 = 1.5 m
q2 = -2.5 m
q3 = 20 m^2

isfinite(q0)          : false
isinf(q0)             : true
isnan(q0)             : false
isnormal(q0)          : false
isgreater(q1,q2)      : true
isgreaterequal(q1,q2) : true
isless(q1,q2)         : false
islessequal(q1,q2)    : false
islessgreater(q1,q2)  : true
isunordered(q1,q2)    : false
abs(q1)               : 1.5 m
ceil(q1)              : 2 m
copysign(q1,q2)       : -1.5 m
fabs(q1)              : 1.5 m
floor(q1)             : 1 m
fdim(q1,q2)           : 4 m
fmax(q1,q2)           : 1.5 m
fmin(q1,q2)           : -2.5 m
fma(q1,q2,q3)         : 16.25 m^2
fpclassify(q1)        : 4
hypot(q1,q2)          : 2.91548 m
nearbyint(q1)         : 2 m
nextafter(q1,q2)      : 1.5 m
nexttoward(q1,q2)     : 1.5 m
rint(q1)              : 2 m
round(q1)             : 2 m
signbit(q1)           : false
trunc(q1)             : 1 m
//]

@endverbatim
**/

#include <iostream>
#include <sstream>
#include <algorithm>
#include <limits>

#include <boost/units/cmath.hpp>
#include <boost/units/io.hpp>
#include <boost/units/quantity.hpp>
#include <boost/units/systems/si.hpp>

int main(void)
{
    using namespace boost::units;

    std::stringstream sstream1, sstream2;

    double  inf = std::numeric_limits<double>::infinity();

    const quantity<SI::length>  q0(inf*SI::meter),
                                q1(1.5*SI::meters),
                                q2(-2.5*SI::meters);
    const quantity<SI::area>    q3(20.0*SI::square_meters);
    
    sstream1  << "q0 = " << q0 << std::endl
              << "q1 = " << q1 << std::endl
              << "q2 = " << q2 << std::endl
              << "q3 = " << q3 << std::endl
              << std::endl;
    
    // BOOST_PREVENT_MACRO_SUBSTITUTION is needed on certain compilers that define some <cmath> functions as macros
    sstream1  << "isfinite(q0)          : " << std::boolalpha << isfinite BOOST_PREVENT_MACRO_SUBSTITUTION (q0) << std::endl
              << "isinf(q0)             : " << std::boolalpha << isinf BOOST_PREVENT_MACRO_SUBSTITUTION (q0) << std::endl
              << "isnan(q0)             : " << std::boolalpha << isnan BOOST_PREVENT_MACRO_SUBSTITUTION (q0) << std::endl
              << "isnormal(q0)          : " << std::boolalpha << isnormal BOOST_PREVENT_MACRO_SUBSTITUTION (q0) << std::endl
              << "isgreater(q1,q2)      : " << std::boolalpha << isgreater BOOST_PREVENT_MACRO_SUBSTITUTION (q1,q2) << std::endl
              << "isgreaterequal(q1,q2) : " << std::boolalpha << isgreaterequal BOOST_PREVENT_MACRO_SUBSTITUTION (q1,q2) << std::endl
              << "isless(q1,q2)         : " << std::boolalpha << isless BOOST_PREVENT_MACRO_SUBSTITUTION (q1,q2) << std::endl
              << "islessequal(q1,q2)    : " << std::boolalpha << islessequal BOOST_PREVENT_MACRO_SUBSTITUTION (q1,q2) << std::endl
              << "islessgreater(q1,q2)  : " << std::boolalpha << islessgreater BOOST_PREVENT_MACRO_SUBSTITUTION (q1,q2) << std::endl
              << "isunordered(q1,q2)    : " << std::boolalpha << isunordered BOOST_PREVENT_MACRO_SUBSTITUTION (q1,q2) << std::endl
              << "abs(q1)               : " << abs BOOST_PREVENT_MACRO_SUBSTITUTION (q1) << std::endl
              << "ceil(q1)              : " << ceil BOOST_PREVENT_MACRO_SUBSTITUTION (q1) << std::endl
              << "copysign(q1,q2)       : " << copysign BOOST_PREVENT_MACRO_SUBSTITUTION (q1,q2) << std::endl
              << "fabs(q1)              : " << fabs BOOST_PREVENT_MACRO_SUBSTITUTION (q1) << std::endl
              << "floor(q1)             : " << floor BOOST_PREVENT_MACRO_SUBSTITUTION (q1) << std::endl
              << "fdim(q1,q2)           : " << fdim BOOST_PREVENT_MACRO_SUBSTITUTION (q1,q2) << std::endl
              << "fmax(q1,q2)           : " << fmax BOOST_PREVENT_MACRO_SUBSTITUTION (q1,q2) << std::endl
              << "fmin(q1,q2)           : " << fmin BOOST_PREVENT_MACRO_SUBSTITUTION (q1,q2) << std::endl
              << "fma(q1,q2,q3)         : " << fma BOOST_PREVENT_MACRO_SUBSTITUTION (q1,q2,q3) << std::endl
              << "fpclassify(q1)        : " << fpclassify BOOST_PREVENT_MACRO_SUBSTITUTION (q1) << std::endl
              << "hypot(q1,q2)          : " << hypot BOOST_PREVENT_MACRO_SUBSTITUTION (q1,q2) << std::endl
              << "nearbyint(q1)         : " << nearbyint BOOST_PREVENT_MACRO_SUBSTITUTION (q1) << std::endl
              << "nextafter(q1,q2)      : " << nextafter BOOST_PREVENT_MACRO_SUBSTITUTION (q1,q2) << std::endl
              << "nexttoward(q1,q2)     : " << nexttoward BOOST_PREVENT_MACRO_SUBSTITUTION (q1,q2) << std::endl
              << "rint(q1)              : " << rint BOOST_PREVENT_MACRO_SUBSTITUTION (q1) << std::endl
              << "round(q1)             : " << round BOOST_PREVENT_MACRO_SUBSTITUTION (q1) << std::endl
              << "signbit(q1)           : " << signbit BOOST_PREVENT_MACRO_SUBSTITUTION (q1) << std::endl
              << "trunc(q1)             : " << trunc BOOST_PREVENT_MACRO_SUBSTITUTION (q1) << std::endl
              << std::endl;
    
    sstream2 << "q0 = " << inf << " m" << std::endl;
    sstream2 << "q1 = 1.5 m" << std::endl;
    sstream2 << "q2 = -2.5 m" << std::endl;
    sstream2 << "q3 = 20 m^2" << std::endl;
    sstream2 << std::endl;
    sstream2 << "isfinite(q0)          : false" << std::endl;
    sstream2 << "isinf(q0)             : true" << std::endl;
    sstream2 << "isnan(q0)             : false" << std::endl;
    sstream2 << "isnormal(q0)          : false" << std::endl;
    sstream2 << "isgreater(q1,q2)      : true" << std::endl;
    sstream2 << "isgreaterequal(q1,q2) : true" << std::endl;
    sstream2 << "isless(q1,q2)         : false" << std::endl;
    sstream2 << "islessequal(q1,q2)    : false" << std::endl;
    sstream2 << "islessgreater(q1,q2)  : true" << std::endl;
    sstream2 << "isunordered(q1,q2)    : false" << std::endl;
    sstream2 << "abs(q1)               : 1.5 m" << std::endl;
    sstream2 << "ceil(q1)              : 2 m" << std::endl;
    sstream2 << "copysign(q1,q2)       : -1.5 m" << std::endl;
    sstream2 << "fabs(q1)              : 1.5 m" << std::endl;
    sstream2 << "floor(q1)             : 1 m" << std::endl;
    sstream2 << "fdim(q1,q2)           : 4 m" << std::endl;
    sstream2 << "fmax(q1,q2)           : 1.5 m" << std::endl;
    sstream2 << "fmin(q1,q2)           : -2.5 m" << std::endl;
    sstream2 << "fma(q1,q2,q3)         : 16.25 m^2" << std::endl;
    sstream2 << "fpclassify(q1)        : "<< fpclassify BOOST_PREVENT_MACRO_SUBSTITUTION (q1) << std::endl;
    sstream2 << "hypot(q1,q2)          : 2.91548 m" << std::endl;
    sstream2 << "nearbyint(q1)         : 2 m" << std::endl;
    sstream2 << "nextafter(q1,q2)      : 1.5 m" << std::endl;
    sstream2 << "nexttoward(q1,q2)     : 1.5 m" << std::endl;
    sstream2 << "rint(q1)              : 2 m" << std::endl;
    sstream2 << "round(q1)             : 2 m" << std::endl;
    sstream2 << "signbit(q1)           : false" << std::endl;
    sstream2 << "trunc(q1)             : 1 m" << std::endl;
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
