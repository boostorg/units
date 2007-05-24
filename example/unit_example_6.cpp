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
    
\brief unit_example_6.cpp

\detailed
Demonstrate interoperability with UDT for scientific notation with heterogeneous algebra.

Output:
@verbatim

//[unit_example_6_output_1
L                                 = 4 x 10^3 m
T                                 = 0.1 s
L+L                               = 8 x 10^3 m
T+T                               = 0.2 s
L*T                               = 400 m s
L/T                               = 40 x 10^3 m s^-1
L*seconds                         = 4 x 10^3 m s
kilograms*(L/T)*(L/T)             = 1.6 x 10^9 m^2 kg s^-2
kilograms*(L/T)^2                 = 4 x 10^9 m^2 kg s^-2
(L/T)^3                           = 0.4 x 10^15 m^3 s^-3
(L/T)^(3/2)                       = 0.632456 x 10^15 m^(3/2) s^(-3/2)
2v(L/T)                           = 63.2456 x 10^3 m^(1/2) s^(-1/2)
(3/2)v(L/T)                       = 7.36806 x 10^9 m^(2/3) s^(-2/3)
//]

20 x 10^3
20 x 10^3
0.2 x 10^-3
5 x 10^3

1 x 2^10 (kibi)
1 x 2^20 (mebi)
1 x 2^30 (gibi)
1 x 2^40 (tebi)
1 x 2^50 (pebi)
1 x 2^60 (exbi)
1 x 10^-24 (yocto) 
1 x 10^-21 (zepto) 
1 x 10^-18 (atto) 
1 x 10^-15 (femto) 
1 x 10^-12 (pico) 
1 x 10^-9 (nano) 
1 x 10^-6 (micro) 
1 x 10^-3 (milli) 
0.01 (centi) 
0.1 (deci) 
10 (deka) 
100 (hecto) 
1 x 10^3 (kilo) 
1 x 10^6 (mega) 
1 x 10^9 (giga) 
1 x 10^12 (tera) 
1 x 10^15 (peta) 
1 x 10^18 (exa) 
1 x 10^21 (zetta) 
1 x 10^24 (yotta) 

@endverbatim
**/

#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>

#include <boost/mpl/list.hpp>

#include <boost/units/quantity.hpp>
#include <boost/units/io.hpp>

#include "scaled_value.hpp"
#include "test_system.hpp"

#if BOOST_UNITS_HAS_TYPEOF

int main(void)
{
    using namespace boost::units;
    using namespace boost::units::test;
    
    std::stringstream sstream1, sstream2;
    
    // don't know why this is necessary...
    typedef boost::units::test::time    time_unit;
    
    //[unit_example_6_snippet_1
    typedef scaled_value<double,scale<10,static_rational<3> > >   type1;
    typedef scaled_value<double,scale<10,static_rational<-2> > >  type2;
        
    quantity<length,type1>      L(type1(4.0)*meters);
    quantity<time_unit,type2>   T(type2(10.0)*seconds);
    //]
    
    sstream1  << "L                                 = " << L << std::endl
              << "T                                 = " << T << std::endl
              << "L+L                               = " << L+L << std::endl
              << "T+T                               = " << T+T << std::endl
              << "L*T                               = " << L*T << std::endl
              << "L/T                               = " << L/T << std::endl
              << "L*seconds                         = " << L*seconds << std::endl
              << "kilograms*(L/T)*(L/T)             = " << kilograms*(L/T)*(L/T) << std::endl
              << "kilograms*(L/T)^2                 = " << kilograms*pow<2>(L/T) << std::endl
              << "(L/T)^3                           = " << pow<3>(L/T) << std::endl
              << "(L/T)^(3/2)                       = " << pow<static_rational<3,2> >(L/T) << std::endl
              << "2v(L/T)                           = " << root<2>(L/T) << std::endl
              << "(3/2)v(L/T)                       = " << root<static_rational<3,2> >(L/T) << std::endl
              << std::endl;
    
    sstream1  << 2.0*scale<10,static_rational<4> >() << std::endl
              << scale<10,static_rational<4> >()*2.0 << std::endl
              << 2.0/scale<10,static_rational<4> >() << std::endl
              << scale<10,static_rational<4> >()/2.0 << std::endl
              << std::endl;
              
    {
    using namespace boost::units::IEEE_1541;
    
    sstream1  << 1.0*kibi << " (kibi)" << std::endl
              << 1.0*mebi << " (mebi)" << std::endl
              << 1.0*gibi << " (gibi)" << std::endl
              << 1.0*tebi << " (tebi)" << std::endl
              << 1.0*pebi << " (pebi)" << std::endl
              << 1.0*exbi << " (exbi)" << std::endl
              << std::endl;
    }
    
    { 
    using namespace boost::units::metric;
    
    sstream1  << 1.0*yocto << " (yocto) " << std::endl
              << 1.0*zepto << " (zepto) " << std::endl
              << 1.0*atto  << " (atto) " << std::endl
              << 1.0*femto << " (femto) " << std::endl
              << 1.0*pico  << " (pico) " << std::endl
              << 1.0*nano  << " (nano) " << std::endl
              << 1.0*micro << " (micro) " << std::endl
              << 1.0*milli << " (milli) " << std::endl
              << 1.0*centi << " (centi) " << std::endl
              << 1.0*deci  << " (deci) " << std::endl
              << 1.0*deka  << " (deka) " << std::endl
              << 1.0*hecto << " (hecto) " << std::endl
              << 1.0*kilo  << " (kilo) " << std::endl
              << 1.0*mega  << " (mega) " << std::endl
              << 1.0*giga  << " (giga) " << std::endl
              << 1.0*tera  << " (tera) " << std::endl
              << 1.0*peta  << " (peta) " << std::endl
              << 1.0*exa   << " (exa) " << std::endl
              << 1.0*zetta << " (zetta) " << std::endl
              << 1.0*yotta << " (yotta) "  << std::endl
              << std::endl;
    }

    sstream2 << "L                                 = 4 x 10^3 m" << std::endl;
    sstream2 << "T                                 = 0.1 s" << std::endl;
    sstream2 << "L+L                               = 8 x 10^3 m" << std::endl;
    sstream2 << "T+T                               = 0.2 s" << std::endl;
    sstream2 << "L*T                               = 400 m s" << std::endl;
    sstream2 << "L/T                               = 40 x 10^3 m s^-1" << std::endl;
    sstream2 << "L*seconds                         = 4 x 10^3 m s" << std::endl;
    sstream2 << "kilograms*(L/T)*(L/T)             = 1.6 x 10^9 m^2 kg s^-2" << std::endl;
    sstream2 << "kilograms*(L/T)^2                 = 4 x 10^9 m^2 kg s^-2" << std::endl;
    sstream2 << "(L/T)^3                           = 0.4 x 10^15 m^3 s^-3" << std::endl;
    sstream2 << "(L/T)^(3/2)                       = 0.632456 x 10^15 m^(3/2) s^(-3/2)" << std::endl;
    sstream2 << "2v(L/T)                           = 63.2456 x 10^3 m^(1/2) s^(-1/2)" << std::endl;
    sstream2 << "(3/2)v(L/T)                       = 7.36806 x 10^9 m^(2/3) s^(-2/3)" << std::endl;
    sstream2  << std::endl;
    sstream2 << "20 x 10^3" << std::endl;
    sstream2 << "20 x 10^3" << std::endl;
    sstream2 << "0.2 x 10^-3" << std::endl;
    sstream2 << "5 x 10^3" << std::endl;
    sstream2  << std::endl;
    sstream2 << "1 x 2^10 (kibi)" << std::endl;
    sstream2 << "1 x 2^20 (mebi)" << std::endl;
    sstream2 << "1 x 2^30 (gibi)" << std::endl;
    sstream2 << "1 x 2^40 (tebi)" << std::endl;
    sstream2 << "1 x 2^50 (pebi)" << std::endl;
    sstream2 << "1 x 2^60 (exbi)" << std::endl;
    sstream2 << std::endl;
    sstream2 << "1 x 10^-24 (yocto) " << std::endl;
    sstream2 << "1 x 10^-21 (zepto) " << std::endl;
    sstream2 << "1 x 10^-18 (atto) " << std::endl;
    sstream2 << "1 x 10^-15 (femto) " << std::endl;
    sstream2 << "1 x 10^-12 (pico) " << std::endl;
    sstream2 << "1 x 10^-9 (nano) " << std::endl;
    sstream2 << "1 x 10^-6 (micro) " << std::endl;
    sstream2 << "1 x 10^-3 (milli) " << std::endl;
    sstream2 << "0.01 (centi) " << std::endl;
    sstream2 << "0.1 (deci) " << std::endl;
    sstream2 << "10 (deka) " << std::endl;
    sstream2 << "100 (hecto) " << std::endl;
    sstream2 << "1 x 10^3 (kilo) " << std::endl;
    sstream2 << "1 x 10^6 (mega) " << std::endl;
    sstream2 << "1 x 10^9 (giga) " << std::endl;
    sstream2 << "1 x 10^12 (tera) " << std::endl;
    sstream2 << "1 x 10^15 (peta) " << std::endl;
    sstream2 << "1 x 10^18 (exa) " << std::endl;
    sstream2 << "1 x 10^21 (zetta) " << std::endl;
    sstream2 << "1 x 10^24 (yotta) " << std::endl;
    sstream2  << std::endl;

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

#else

int main(void)
{
    std::cout << "No typeof enabled" << std::endl;
    
    return 0;
}

#endif // BOOST_UNITS_HAS_TYPEOF
