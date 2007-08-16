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
    
\brief heterogeneous_unit.cpp

\detailed
Test heterogeneous units and quantities.

Output:
@verbatim

//[heterogeneous_unit_output_1
1.5 m
1 g
1.5 m g
1.5 m g^-1

1 m kg s^-2
1 kg s^-2

1 cm kg s^-2
1 cm m^-1 kg s^-2
//]

//[heterogeneous_unit_output_2
0.015 m^2
//]

@endverbatim
**/

#define MCS_USE_DEMANGLING
//#define MCS_USE_BOOST_REGEX_DEMANGLING

#include <iostream>
#include <sstream>
#include <algorithm>

#include <boost/units/io.hpp>
#include <boost/units/detail/utility.hpp>
#include <boost/units/systems/cgs.hpp>
#include <boost/units/systems/si.hpp>

using namespace boost::units;

int main()
{
    std::stringstream sstream1, sstream2;

    //[heterogeneous_unit_snippet_1
    quantity<SI::length>        L(1.5*SI::meter);
    quantity<CGS::mass>         M(1.0*CGS::gram);
    
    sstream1 << L << std::endl
             << M << std::endl
             << L*M << std::endl
             << L/M << std::endl
             << std::endl;
              
    sstream1 << 1.0*SI::meter*SI::kilogram/pow<2>(SI::second) << std::endl
             << 1.0*SI::meter*SI::kilogram/pow<2>(SI::second)/SI::meter << std::endl
             << std::endl;

    sstream1 << 1.0*CGS::centimeter*SI::kilogram/pow<2>(SI::second) << std::endl
             << 1.0*CGS::centimeter*SI::kilogram/pow<2>(SI::second)/SI::meter << std::endl
             << std::endl;
    //]
    
    //heterogeneous_unit_snippet_2
    quantity<SI::area>      A(1.5*SI::meter*CGS::centimeter);
    
    sstream1 << A << std::endl
             << std::endl;
    //]

    sstream2 << "1.5 m" << std::endl
             << "1 g" << std::endl
             << "1.5 m g" << std::endl
             << "1.5 m g^-1" << std::endl
             << std::endl
             << "1 m kg s^-2" << std::endl
             << "1 kg s^-2" << std::endl
             << std::endl
             << "1 cm kg s^-2" << std::endl
             << "1 cm m^-1 kg s^-2" << std::endl
             << std::endl
             << "0.015 m^2" << std::endl
             << std::endl;
            
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
