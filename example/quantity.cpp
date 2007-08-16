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
    
\brief quantity.cpp

\detailed
Test quantity algebra.

Output:
@verbatim

//[quantity_output_double
L                                 = 2 m
L+L                               = 4 m
L-L                               = 0 m
L*L                               = 4 m^2
L/L                               = 1 dimensionless 
L*meter                           = 2 m^2
kilograms*(L/seconds)*(L/seconds) = 4 m^2 kg s^-2
kilograms*(L/seconds)^2           = 4 m^2 kg s^-2
L^3                               = 8 m^3
L^(3/2)                           = 2.82843 m^(3/2)
2vL                               = 1.41421 m^(1/2)
(3/2)vL                           = 1.5874 m^(2/3)
//]

//[quantity_output_complex
L                                 = (3,4) m
L+L                               = (6,8) m
L-L                               = (0,0) m
L*L                               = (-7,24) m^2
L/L                               = (1,0) dimensionless 
L*meter                           = (3,4) m^2
kilograms*(L/seconds)*(L/seconds) = (-7,24) m^2 kg s^-2
kilograms*(L/seconds)^2           = (-7,24) m^2 kg s^-2
L^3                               = (-117,44) m^3
L^(3/2)                           = (2,11) m^(3/2)
2vL                               = (2,1) m^(1/2)
(3/2)vL                           = (2.38285,1.69466) m^(2/3)
//]

@endverbatim
**/

#include <complex>
#include <iostream>
#include <sstream>
#include <algorithm>

#include <boost/mpl/list.hpp>

#include <boost/typeof/std/complex.hpp>

#include <boost/units/quantity.hpp>
#include <boost/units/io.hpp>

#include "test_system.hpp"

int main(void)
{
    using namespace boost::units;
    using namespace boost::units::test;

    std::stringstream sstream1, sstream2;
    
    {
    //[quantity_snippet_1
    quantity<length>        L = 2.0*meters;                     // quantity of length
    quantity<energy>        E = kilograms*pow<2>(L/seconds);    // quantity of energy
    //]
    
    sstream1  << "L                                 = " << L << std::endl
              << "L+L                               = " << L+L << std::endl
              << "L-L                               = " << L-L << std::endl
              << "L*L                               = " << L*L << std::endl
              << "L/L                               = " << L/L << std::endl
              << "L*meter                           = " << L*meter << std::endl
              << "kilograms*(L/seconds)*(L/seconds) = " << kilograms*(L/seconds)*(L/seconds) << std::endl
              << "kilograms*(L/seconds)^2           = " << kilograms*pow<2>(L/seconds) << std::endl
              << "L^3                               = " << pow<3>(L) << std::endl
              << "L^(3/2)                           = " << pow<static_rational<3,2> >(L) << std::endl
              << "2vL                               = " << root<2>(L) << std::endl
              << "(3/2)vL                           = " << root<static_rational<3,2> >(L) << std::endl
              << std::endl;
    }
    
    {
    //[quantity_snippet_2
    quantity<length,std::complex<double> >  L(std::complex<double>(3.0,4.0)*meters);
    quantity<energy,std::complex<double> >  E(kilograms*pow<2>(L/seconds));
    //]
    
    sstream1  << "L                                 = " << L << std::endl
              << "L+L                               = " << L+L << std::endl
              << "L-L                               = " << L-L << std::endl
              << "L*L                               = " << L*L << std::endl
              << "L/L                               = " << L/L << std::endl
              << "L*meter                           = " << L*meter << std::endl
              << "kilograms*(L/seconds)*(L/seconds) = " << kilograms*(L/seconds)*(L/seconds) << std::endl
              << "kilograms*(L/seconds)^2           = " << kilograms*pow<2>(L/seconds) << std::endl
              << "L^3                               = " << pow<3>(L) << std::endl
              << "L^(3/2)                           = " << pow<static_rational<3,2> >(L) << std::endl
              << "2vL                               = " << root<2>(L) << std::endl
              << "(3/2)vL                           = " << root<static_rational<3,2> >(L) << std::endl
              << std::endl;
    }

    sstream2  << "L                                 = 2 m" << std::endl
              << "L+L                               = 4 m" << std::endl
              << "L-L                               = 0 m" << std::endl
              << "L*L                               = 4 m^2" << std::endl
              << "L/L                               = 1 dimensionless" << std::endl
              << "L*meter                           = 2 m^2" << std::endl
              << "kilograms*(L/seconds)*(L/seconds) = 4 m^2 kg s^-2" << std::endl
              << "kilograms*(L/seconds)^2           = 4 m^2 kg s^-2" << std::endl
              << "L^3                               = 8 m^3" << std::endl
              << "L^(3/2)                           = 2.82843 m^(3/2)" << std::endl
              << "2vL                               = 1.41421 m^(1/2)" << std::endl
              << "(3/2)vL                           = 1.5874 m^(2/3)" << std::endl
              << std::endl
              << "L                                 = (3,4) m" << std::endl
              << "L+L                               = (6,8) m" << std::endl
              << "L-L                               = (0,0) m" << std::endl
              << "L*L                               = (-7,24) m^2" << std::endl
              << "L/L                               = (1,0) dimensionless" << std::endl
              << "L*meter                           = (3,4) m^2" << std::endl
              << "kilograms*(L/seconds)*(L/seconds) = (-7,24) m^2 kg s^-2" << std::endl
              << "kilograms*(L/seconds)^2           = (-7,24) m^2 kg s^-2" << std::endl
              << "L^3                               = (-117,44) m^3" << std::endl
              << "L^(3/2)                           = (2,11) m^(3/2)" << std::endl
              << "2vL                               = (2,1) m^(1/2)" << std::endl
              << "(3/2)vL                           = (2.38285,1.69466) m^(2/3)" << std::endl
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
