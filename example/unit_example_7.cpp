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
    
\brief unit_example_7.cpp

\detailed
Demonstrate interoperability with array class and built-in arrays.

Output:
@verbatim

//[unit_example_7_output_1
Using mcs::array...

data1 : 

    0 m     1 m     2 m 
   10 m    11 m    12 m 
   20 m    21 m    22 m 

data2 : 

    0 m   0.1 m   0.2 m 
    1 m   1.1 m   1.2 m 
    2 m   2.1 m   2.2 m 

data3 : 

    0 m   1.1 m   2.2 m 
   11 m  12.1 m  13.2 m 
   22 m  23.1 m  24.2 m 

data4 : 

    0 m   0.9 m   1.8 m 
    9 m   9.9 m  10.8 m 
   18 m  18.9 m  19.8 m 

data5 : 

    0 m^2     0.1 m^2     0.4 m^2   
   10 m^2    12.1 m^2    14.4 m^2   
   40 m^2    44.1 m^2    48.4 m^2   

data6 : 

  nan dimensionless        10 dimensionless        10 dimensionless     
   10 dimensionless        10 dimensionless        10 dimensionless     
   10 dimensionless        10 dimensionless        10 dimensionless     
//]

@endverbatim

...or...

@verbatim

//[unit_example_7_output_2
Using C++ array...

data1 : 

    0 m     1 m     2 m 
   10 m    11 m    12 m 
   20 m    21 m    22 m 

data2 : 

    0 m   0.1 m   0.2 m 
    1 m   1.1 m   1.2 m 
    2 m   2.1 m   2.2 m 

data3 : 

    0 m   1.1 m   2.2 m 
   11 m  12.1 m  13.2 m 
   22 m  23.1 m  24.2 m 

data4 : 

    0 m   0.9 m   1.8 m 
    9 m   9.9 m  10.8 m 
   18 m  18.9 m  19.8 m 

data5 : 

    0 m^2     0.1 m^2     0.4 m^2   
   10 m^2    12.1 m^2    14.4 m^2   
   40 m^2    44.1 m^2    48.4 m^2   

data6 : 

  nan dimensionless        10 dimensionless        10 dimensionless     
   10 dimensionless        10 dimensionless        10 dimensionless     
   10 dimensionless        10 dimensionless        10 dimensionless     
//]

@endverbatim
**/

#include <iomanip>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <limits>

#include <boost/mpl/list.hpp>

#include <boost/units/unit.hpp>
#include <boost/units/io.hpp>

#include "test_system.hpp"

#if (BOOST_UNITS_HAS_TYPEOF && MCS_HAS_ARRAY)

#include <mcs/array/array.hpp>

int main(void)
{
    using namespace boost::units;
    using namespace boost::units::test;
    using namespace mcs;
    
    std::stringstream sstream1, sstream2;

    double  zero = 0.0,
            nan = 0.0/zero;
    
    sstream1 << "Using mcs::array..." << std::endl << std::endl;
    
    //[unit_example_7_snippet_1
    typedef quantity<dimensionless>     dimensionless_type;
    typedef quantity<length>            length_type;
    typedef quantity<area>              area_type;
    
    const std::size_t   xdim = 3,
                        ydim = 3;
                        
    Array<length_type,2>    data1(Index<2>(xdim,ydim)),
                            data2(Index<2>(xdim,ydim));
    
    for (std::size_t i=0;i<xdim;++i)
    {
        for (std::size_t j=0;j<ydim;++j)
        {
            data1(i,j) = length_type((10.0f*i+j)*meters);
            data2(i,j) = length_type((i+0.10f*j)*meters);
        }
    }
    //]
    
    sstream1 << "data1 : " << std::endl << std::endl;
    
    for (std::size_t i=0;i<xdim;++i)
    {
        for (std::size_t j=0;j<ydim;++j)
        {
            sstream1 << std::setw(5) << data1(i,j);
        }
        
        sstream1 << std::endl;
    }
    
    sstream1 << std::endl;
    
    sstream1 << "data2 : " << std::endl << std::endl;
    
    for (std::size_t i=0;i<xdim;++i)
    {
        for (std::size_t j=0;j<ydim;++j)
        {
            sstream1 << std::setw(5) << data2(i,j);
        }
        
        sstream1 << std::endl;
    }
    
    sstream1 << std::endl;
    
    //[unit_example_7_snippet_2
    mcs::Array<length_type,2>           data3(data1+data2),
                                        data4(data1-data2);
    mcs::Array<area_type,2>             data5(data1*data2);
    mcs::Array<dimensionless_type,2>    data6(data1/data2);
    //]
        
    sstream1 << "data3 : " << std::endl << std::endl;
    
    for (std::size_t i=0;i<xdim;++i)
    {
        for (std::size_t j=0;j<ydim;++j)
        {
            sstream1 << std::setw(5) << data3(i,j);
        }
        
        sstream1 << std::endl;
    }
    
    sstream1 << std::endl;
    
    sstream1 << "data4 : " << std::endl << std::endl;
    
    for (std::size_t i=0;i<xdim;++i)
    {
        for (std::size_t j=0;j<ydim;++j)
        {
            sstream1 << std::setw(5) << data4(i,j);
        }
        
        sstream1 << std::endl;
    }
    
    sstream1 << std::endl;
    
    sstream1 << "data5 : " << std::endl << std::endl;
    
    for (std::size_t i=0;i<xdim;++i)
    {
        for (std::size_t j=0;j<ydim;++j)
        {
            sstream1 << std::setw(5) << data5(i,j);
        }
        
        sstream1 << std::endl;
    }
    
    sstream1 << std::endl;
    
    sstream1 << "data6 : " << std::endl << std::endl;
    
    for (std::size_t i=0;i<xdim;++i)
    {
        for (std::size_t j=0;j<ydim;++j)
        {
            sstream1 << std::setw(5) << data6(i,j);
        }
        
        sstream1 << std::endl;
    }
    
    sstream1 << std::endl;

    sstream2 << "Using mcs::array..." << std::endl;
    sstream2 << std::endl;
    sstream2 << "data1 : " << std::endl;
    sstream2 << std::endl;
    sstream2 << "    0 m    1 m    2 m" << std::endl;
    sstream2 << "   10 m   11 m   12 m" << std::endl;
    sstream2 << "   20 m   21 m   22 m" << std::endl;
    sstream2 << std::endl;
    sstream2 << "data2 : " << std::endl;
    sstream2 << std::endl;
    sstream2 << "    0 m  0.1 m  0.2 m" << std::endl;
    sstream2 << "    1 m  1.1 m  1.2 m" << std::endl;
    sstream2 << "    2 m  2.1 m  2.2 m" << std::endl;
    sstream2 << std::endl;
    sstream2 << "data3 : " << std::endl;
    sstream2 << std::endl;
    sstream2 << "    0 m  1.1 m  2.2 m" << std::endl;
    sstream2 << "   11 m 12.1 m 13.2 m" << std::endl;
    sstream2 << "   22 m 23.1 m 24.2 m" << std::endl;
    sstream2 << std::endl;
    sstream2 << "data4 : " << std::endl;
    sstream2 << std::endl;
    sstream2 << "    0 m  0.9 m  1.8 m" << std::endl;
    sstream2 << "    9 m  9.9 m 10.8 m" << std::endl;
    sstream2 << "   18 m 18.9 m 19.8 m" << std::endl;
    sstream2 << std::endl;
    sstream2 << "data5 : " << std::endl;
    sstream2 << std::endl;
    sstream2 << "    0 m^2  0.1 m^2  0.4 m^2" << std::endl;
    sstream2 << "   10 m^2 12.1 m^2 14.4 m^2" << std::endl;
    sstream2 << "   40 m^2 44.1 m^2 48.4 m^2" << std::endl;
    sstream2 << std::endl;
    sstream2 << "data6 : " << std::endl;
    sstream2 << std::endl;
    sstream2 << std::setw(5) << nan << " dimensionless";
    sstream2 <<                    "   10 dimensionless   10 dimensionless" << std::endl;
    sstream2 << "   10 dimensionless   10 dimensionless   10 dimensionless" << std::endl;
    sstream2 << "   10 dimensionless   10 dimensionless   10 dimensionless" << std::endl;
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

/* Output:

Using mcs::array...

data1 : 

    0 m     1 m     2 m 
   10 m    11 m    12 m 
   20 m    21 m    22 m 

data2 : 

    0 m   0.1 m   0.2 m 
    1 m   1.1 m   1.2 m 
    2 m   2.1 m   2.2 m 

data3 : 

    0 m   1.1 m   2.2 m 
   11 m  12.1 m  13.2 m 
   22 m  23.1 m  24.2 m 

data4 : 

    0 m   0.9 m   1.8 m 
    9 m   9.9 m  10.8 m 
   18 m  18.9 m  19.8 m 

data5 : 

    0 m^2     0.1 m^2     0.4 m^2   
   10 m^2    12.1 m^2    14.4 m^2   
   40 m^2    44.1 m^2    48.4 m^2   

data6 : 

  nan dimensionless        10 dimensionless        10 dimensionless     
   10 dimensionless        10 dimensionless        10 dimensionless     
   10 dimensionless        10 dimensionless        10 dimensionless     

*/

#else // MCS_HAS_ARRAY

int main(void)
{
    using namespace boost::units;
    using namespace boost::units::test;
    
    std::stringstream sstream1, sstream2;

    double  zero = 0.0,
            nan = 0.0/zero;
    
    sstream1 << "Using C++ array..." << std::endl << std::endl;
        
    typedef quantity<dimensionless>     dimensionless_type;
    typedef quantity<length>            length_type;
    typedef quantity<area>              area_type;
    
    static const std::size_t    xdim = 3,
                                ydim = 3;
                        
    length_type         data1[xdim][ydim],
                        data2[xdim][ydim];
    
    for (std::size_t i=0;i<xdim;++i)
    {
        for (std::size_t j=0;j<ydim;++j)
        {
            data1[i][j] = length_type((10.0f*i+j)*meters);
            data2[i][j] = length_type((i+0.10f*j)*meters);
        }
    }
    
    sstream1 << "data1 : " << std::endl << std::endl;
    
    for (std::size_t i=0;i<xdim;++i)
    {
        for (std::size_t j=0;j<ydim;++j)
        {
            sstream1 << std::setw(5) << data1[i][j];
        }
        
        sstream1 << std::endl;
    }
    
    sstream1 << std::endl;
    
    sstream1 << "data2 : " << std::endl << std::endl;
    
    for (std::size_t i=0;i<xdim;++i)
    {
        for (std::size_t j=0;j<ydim;++j)
        {
            sstream1 << std::setw(5) << data2[i][j];
        }
        
        sstream1 << std::endl;
    }
    
    sstream1 << std::endl;
    
    length_type         data3[xdim][ydim],
                        data4[xdim][ydim];
    area_type           data5[xdim][ydim];
    dimensionless_type  data6[xdim][ydim];
    
    sstream1 << "data3 : " << std::endl << std::endl;
    
    for (std::size_t i=0;i<xdim;++i)
    {
        for (std::size_t j=0;j<ydim;++j)
        {
            data3[i][j] = data1[i][j]+data2[i][j];
            
            sstream1 << std::setw(5) << data3[i][j];
        }
        
        sstream1 << std::endl;
    }
    
    sstream1 << std::endl;
    
    sstream1 << "data4 : " << std::endl << std::endl;
    
    for (std::size_t i=0;i<xdim;++i)
    {
        for (std::size_t j=0;j<ydim;++j)
        {
            data4[i][j] = data1[i][j]-data2[i][j];
            
            sstream1 << std::setw(5) << data4[i][j];
        }
        
        sstream1 << std::endl;
    }
    
    sstream1 << std::endl;
    
    sstream1 << "data5 : " << std::endl << std::endl;
    
    for (std::size_t i=0;i<xdim;++i)
    {
        for (std::size_t j=0;j<ydim;++j)
        {
            data5[i][j] = data1[i][j]*data2[i][j];
            
            sstream1 << std::setw(5) << data5[i][j];
        }
        
        sstream1 << std::endl;
    }
    
    sstream1 << std::endl;
    
    sstream1 << "data6 : " << std::endl << std::endl;
    
    for (std::size_t i=0;i<xdim;++i)
    {
        for (std::size_t j=0;j<ydim;++j)
        {
            data6[i][j] = data1[i][j]/data2[i][j];
            
            sstream1 << std::setw(5) << data6[i][j];
        }
        
        sstream1 << std::endl;
    }
    
    sstream1 << std::endl;

    sstream2 << "Using C++ array..." << std::endl;
    sstream2 << std::endl;
    sstream2 << "data1 : " << std::endl;
    sstream2 << std::endl;
    sstream2 << "    0 m    1 m    2 m" << std::endl;
    sstream2 << "   10 m   11 m   12 m" << std::endl;
    sstream2 << "   20 m   21 m   22 m" << std::endl;
    sstream2 << std::endl;
    sstream2 << "data2 : " << std::endl;
    sstream2 << std::endl;
    sstream2 << "    0 m  0.1 m  0.2 m" << std::endl;
    sstream2 << "    1 m  1.1 m  1.2 m" << std::endl;
    sstream2 << "    2 m  2.1 m  2.2 m" << std::endl;
    sstream2 << std::endl;
    sstream2 << "data3 : " << std::endl;
    sstream2 << std::endl;
    sstream2 << "    0 m  1.1 m  2.2 m" << std::endl;
    sstream2 << "   11 m 12.1 m 13.2 m" << std::endl;
    sstream2 << "   22 m 23.1 m 24.2 m" << std::endl;
    sstream2 << std::endl;
    sstream2 << "data4 : " << std::endl;
    sstream2 << std::endl;
    sstream2 << "    0 m  0.9 m  1.8 m" << std::endl;
    sstream2 << "    9 m  9.9 m 10.8 m" << std::endl;
    sstream2 << "   18 m 18.9 m 19.8 m" << std::endl;
    sstream2 << std::endl;
    sstream2 << "data5 : " << std::endl;
    sstream2 << std::endl;
    sstream2 << "    0 m^2  0.1 m^2  0.4 m^2" << std::endl;
    sstream2 << "   10 m^2 12.1 m^2 14.4 m^2" << std::endl;
    sstream2 << "   40 m^2 44.1 m^2 48.4 m^2" << std::endl;
    sstream2 << std::endl;
    sstream2 << "data6 : " << std::endl;
    sstream2 << std::endl;
    sstream2 << std::setw(5) << nan << " dimensionless";
    sstream2 <<                    "   10 dimensionless   10 dimensionless" << std::endl;
    sstream2 << "   10 dimensionless   10 dimensionless   10 dimensionless" << std::endl;
    sstream2 << "   10 dimensionless   10 dimensionless   10 dimensionless" << std::endl;
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

#endif // MCS_HAS_ARRAY

