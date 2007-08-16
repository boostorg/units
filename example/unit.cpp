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
    
\brief unit.cpp

\detailed
Test unit algebra.

Output:
@verbatim

//[unit_output
L             = m
L+L           = m
L-L           = m
L/L           = dimensionless 
meter*meter   = m^2
M*(L/T)*(L/T) = m^2 kg s^-2
M*(L/T)^2     = m^2 kg s^-2
L^3           = m^3
L^(3/2)       = m^(3/2)
2vM           = kg^(1/2)
(3/2)vM       = kg^(2/3)
//]

@endverbatim
**/

#include <iostream>
#include <sstream>
#include <algorithm>

#include "test_system.hpp"

int main()
{
    using namespace boost::units;
    using namespace boost::units::test;

    //[unit_snippet_1
    const length                    L;
    const mass                      M;
    // needs to be namespace-qualified because of global time definition
    const boost::units::test::time  T;
    const energy                    E;
    //]
    
    std::stringstream sstream1, sstream2;
    
    sstream1  << "L             = " << L << std::endl
              << "L+L           = " << L+L << std::endl
              << "L-L           = " << L-L << std::endl
              << "L/L           = " << L/L << std::endl
              << "meter*meter   = " << meter*meter << std::endl
              << "M*(L/T)*(L/T) = " << M*(L/T)*(L/T) << std::endl
              << "M*(L/T)^2     = " << M*pow<2>(L/T) << std::endl
              << "L^3           = " << pow<3>(L) << std::endl
              << "L^(3/2)       = " << pow<static_rational<3,2> >(L) << std::endl
              << "2vM           = " << root<2>(M) << std::endl
              << "(3/2)vM       = " << root<static_rational<3,2> >(M) << std::endl;

    sstream2  << "L             = m" << std::endl
              << "L+L           = m" << std::endl
              << "L-L           = m" << std::endl
              << "L/L           = dimensionless" << std::endl
              << "meter*meter   = m^2" << std::endl
              << "M*(L/T)*(L/T) = m^2 kg s^-2" << std::endl
              << "M*(L/T)^2     = m^2 kg s^-2" << std::endl
              << "L^3           = m^3" << std::endl
              << "L^(3/2)       = m^(3/2)" << std::endl
              << "2vM           = kg^(1/2)" << std::endl
              << "(3/2)vM       = kg^(2/3)" << std::endl;

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
