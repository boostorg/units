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
    
\brief unit_example_13.cpp

\detailed
Test interoperability with Boost.Serialization.

Output:
@verbatim

//[unit_example_13_output
volume (cm^3) = 1.35 cm^3

22 serialization::archive 4 0 0 1.3500000000000001
//]

@endverbatim
**/

#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

#include <boost/units/io.hpp>
#include <boost/units/systems/cgs.hpp>

using namespace boost::units;

int main()
{
//  std::ofstream   ofs("boost_units_serialize_test.txt");

    std::stringstream sstream1, sstream2;
    
    //[unit_example_13_snippet_1
    const quantity<CGS::volume>    vc(1.35*pow<3>(CGS::centimeter));
                        
    sstream1 << "volume (cm^3) = " << vc << std::endl
              << std::endl;
        
    boost::archive::text_oarchive   oa(sstream1);
    
    oa << vc;
    //]
    
    sstream2 << "volume (cm^3) = 1.35 cm^3" << std::endl;
    sstream2 << std::endl;
    sstream2 << "22 serialization::archive 4 0 0 1.3500000000000001";

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
