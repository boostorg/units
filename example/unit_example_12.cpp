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
    
\brief unit_example_12.cpp

\detailed
Test interoperability with Boost.Interval.

Output:
@verbatim

i0    = [ 1.1 , 1.2 ]
i1    = [ 2.5 , 2.75 ]

i0+i1     : [ 3.6 , 3.95 ]
i0-i1     : [ -1.65 , -1.3 ]

//[unit_example_12_output_1
i0 = [ 1.1 , 1.2 ] m
i1 = [ 2.5 , 2.75 ] m

i0+i1     : [ 3.6 , 3.95 ] m
i0-i1     : [ -1.65 , -1.3 ] m
//]

@endverbatim
**/

#include <iostream>
#include <sstream>
#include <algorithm>

#include <boost/numeric/interval.hpp>

#include <boost/units/io.hpp>
#include <boost/units/quantity.hpp>
#include <boost/units/systems/si.hpp>

#if BOOST_UNITS_HAS_BOOST_TYPEOF

#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

BOOST_TYPEOF_REGISTER_TEMPLATE(boost::numeric::interval, 1)

#endif

namespace boost {

namespace numeric {

template<class Y,class Z>
std::ostream& operator<<(std::ostream& os,const interval<Y,Z>& val)
{    
    os << "[ " << val.lower() << " , " << val.upper() << " ]";
    
    return os;
}

} // namespace numeric

} // namespace boost

int main(void)
{
    using namespace boost::numeric;
    using namespace boost::units;

    std::stringstream sstream1, sstream2;

    {
    const double    q0 = 1.1,
                    q1 = 1.2,
                    q2 = 2.5,
                    q3 = 2.75;
                    
    const interval<double>  i0(q0,q1),
                            i1(q2,q3);
                                        
    sstream1  << "i0    = " << i0 << std::endl
              << "i1    = " << i1 << std::endl
              << std::endl;
              
    sstream1  << "i0+i1     : " << i0+i1 << std::endl
              << "i0-i1     : " << i0-i1 << std::endl
              << std::endl;
    }
                  
    {
    //[unit_example_12_snippet_1
    typedef interval<double>    interval_type;
    
    const quantity<SI::length,interval_type>    i0(interval_type(1.1,1.2)*SI::meters),
                                                i1(interval_type(2.5,2.75)*SI::meters);
    //]
        
    sstream1  << "i0 = " << i0 << std::endl
              << "i1 = " << i1 << std::endl
              << std::endl;
              
    sstream1  << "i0+i1     : " << i0+i1 << std::endl
              << "i0-i1     : " << i0-i1 << std::endl
              << std::endl;
    }

    sstream2 << "i0    = [ 1.1 , 1.2 ]" << std::endl;
    sstream2 << "i1    = [ 2.5 , 2.75 ]" << std::endl;
    sstream2 << std::endl;
    sstream2 << "i0+i1     : [ 3.6 , 3.95 ]" << std::endl;
    sstream2 << "i0-i1     : [ -1.65 , -1.3 ]" << std::endl;
    sstream2 << std::endl;
    sstream2 << "i0 = [ 1.1 , 1.2 ] m" << std::endl;
    sstream2 << "i1 = [ 2.5 , 2.75 ] m" << std::endl;
    sstream2 << std::endl;
    sstream2 << "i0+i1     : [ 3.6 , 3.95 ] m" << std::endl;
    sstream2 << "i0-i1     : [ -1.65 , -1.3 ] m" << std::endl;
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
