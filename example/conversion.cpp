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
    
\brief conversion.cpp

\detailed
Test explicit and implicit unit conversion.

Output:
@verbatim

//[conversion_output_1
L1 = 2 m
L2 = 2 m
L3 = 2 m
L4 = 200 cm
L5 = 5 m
L6 = 4 m
L7 = 200 cm
//]

//[conversion_output_2
volume (m^3)  = 1 m^3
volume (cm^3) = 1e+06 cm^3
volume (m^3)  = 1 m^3

energy (joules) = 1 m^2 kg s^-2
energy (ergs)   = 1e+07 cm^2 g s^-2
energy (joules) = 1 m^2 kg s^-2

velocity (2 m/s)  = 2 m s^-1
velocity (2 cm/s) = 0.02 m s^-1
//]

//[conversion_output_3
implicit conversions enabled
volume (m^3)  = 1 m^3
volume (cm^3) = 1e+06 cm^3

energy (joules) = 1 m^2 kg s^-2
energy (ergs)   = 1e+07 cm^2 g s^-2

velocity (2 m/s)  = 2 m s^-1
velocity (2 cm/s) = 0.02 m s^-1
//]

@endverbatim
**/

#define BOOST_UNITS_ENABLE_IMPLICIT_UNIT_CONVERSION

#include <iostream>
#include <sstream>
#include <algorithm>

#include <boost/units/io.hpp>
#include <boost/units/systems/cgs.hpp>
#include <boost/units/systems/si.hpp>

using namespace boost::units;

int main()
{

    std::stringstream sstream1, sstream2;

    // test quantity_cast
    {
    // implicit value_type conversions
    //[conversion_snippet_1
    quantity<SI::length>        L1 = quantity<SI::length,int>(int(2.5)*SI::meters);
    quantity<SI::length,int>    L2(quantity<SI::length,double>(2.5*SI::meters));
    //]
    
    //[conversion_snippet_3
    quantity<SI::length,int>    L3 = static_cast<quantity<SI::length,int> >(L1);
    //]
    
    //[conversion_snippet_4
    quantity<CGS::length>       L4 = static_cast<quantity<CGS::length> >(L1);
    //]
    
    quantity<SI::length,int>    L5(4*SI::meters),
                                L6(5*SI::meters);
    quantity<CGS::length>       L7(L1);
    
    swap(L5,L6);
    
    sstream1  << "L1 = " << L1 << std::endl
              << "L2 = " << L2 << std::endl
              << "L3 = " << L3 << std::endl
              << "L4 = " << L4 << std::endl
              << "L5 = " << L5 << std::endl
              << "L6 = " << L6 << std::endl
              << "L7 = " << L7 << std::endl
              << std::endl;
    }
    
    // test explicit unit system conversion
    {
    //[conversion_snippet_5
    quantity<SI::volume>    vs(1.0*pow<3>(SI::meter));      
    quantity<CGS::volume>   vc(vs);
    quantity<SI::volume>    vs2(vc);
                        
    quantity<SI::energy>    es(1.0*SI::joule);      
    quantity<CGS::energy>   ec(es);
    quantity<SI::energy>    es2(ec);
                        
    quantity<SI::velocity>  v1 = 2.0*SI::meters/SI::second,     
                            v2(quantity<CGS::velocity>(2.0*CGS::centimeters/CGS::second));
    //]
    
    sstream1 << "volume (m^3)  = " << vs << std::endl
             << "volume (cm^3) = " << vc << std::endl
             << "volume (m^3)  = " << vs2 << std::endl
             << std::endl;
            
    sstream1 << "energy (joules) = " << es << std::endl
             << "energy (ergs)   = " << ec << std::endl
             << "energy (joules) = " << es2 << std::endl
             << std::endl;
            
    sstream1 << "velocity (2 m/s)  = " << v1 << std::endl
             << "velocity (2 cm/s) = " << v2 << std::endl
             << std::endl;
    }
        
    // test implicit unit system conversion
    {
    sstream1 << std::endl
             << "implicit conversions enabled"
             << std::endl;
              
    //[conversion_snippet_6
    quantity<SI::volume>     vs(1.0*pow<3>(SI::meter));      
    quantity<CGS::volume>    vc;
    
    vc = vs;
            
    quantity<SI::energy>     es(1.0*SI::joule);      
    quantity<CGS::energy>    ec;
    
    ec = es;
    
    quantity<SI::velocity>  v1 = 2.0*SI::meters/SI::second,
                            v2 = 2.0*CGS::centimeters/CGS::second; 
    //]
                        
    sstream1 << "volume (m^3)  = " << vs << std::endl
             << "volume (cm^3) = " << vc << std::endl
             << std::endl;
    
    sstream1 << "energy (joules) = " << es << std::endl
             << "energy (ergs)   = " << ec << std::endl
             << std::endl;
    
    sstream1 << "velocity (2 m/s)  = " << v1 << std::endl
             << "velocity (2 cm/s) = " << v2 << std::endl
             << std::endl;
    }
    
    sstream2  << "L1 = 2 m" << std::endl;
    sstream2  << "L2 = 2 m" << std::endl;
    sstream2  << "L3 = 2 m" << std::endl;
    sstream2  << "L4 = 200 cm" << std::endl;
    sstream2  << "L5 = 5 m" << std::endl;
    sstream2  << "L6 = 4 m" << std::endl;
    sstream2  << "L7 = 200 cm" << std::endl;
    sstream2  << std::endl;
    sstream2  << "volume (m^3)  = 1 m^3" << std::endl;
    sstream2  << "volume (cm^3) = " << 1e6 << " cm^3" << std::endl;
    sstream2  << "volume (m^3)  = 1 m^3" << std::endl;
    sstream2  << std::endl;
    sstream2  << "energy (joules) = 1 m^2 kg s^-2" << std::endl;
    sstream2  << "energy (ergs)   = " << 1e7 << " cm^2 g s^-2" << std::endl;
    sstream2  << "energy (joules) = 1 m^2 kg s^-2" << std::endl;
    sstream2  << std::endl;
    sstream2  << "velocity (2 m/s)  = 2 m s^-1" << std::endl;
    sstream2  << "velocity (2 cm/s) = 0.02 m s^-1" << std::endl;
    sstream2  << std::endl;
#ifdef BOOST_UNITS_ENABLE_IMPLICIT_UNIT_CONVERSION
    sstream2  << std::endl;
    sstream2  << "implicit conversions enabled" << std::endl;
    sstream2  << "volume (m^3)  = 1 m^3" << std::endl;
    sstream2  << "volume (cm^3) = " << 1e6 << " cm^3" << std::endl;
    sstream2  << std::endl;
    sstream2  << "energy (joules) = 1 m^2 kg s^-2" << std::endl;
    sstream2  << "energy (ergs)   = " << 1e7 << " cm^2 g s^-2" << std::endl;
    sstream2  << std::endl;
    sstream2  << "velocity (2 m/s)  = 2 m s^-1" << std::endl;
    sstream2  << "velocity (2 cm/s) = 0.02 m s^-1" << std::endl;
    sstream2  << std::endl;
#endif

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
