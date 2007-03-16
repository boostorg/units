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
    
\brief unit_example_14.cpp

\detailed
Test runtime performance.

Output:
@verbatim

f(x,y,z) took 0.26 seconds to run 5e+07 iterations with double = 7.69231e+08 flops
f(x,y,z) took 0.24 seconds to run 5e+07 iterations with quantity<double> = 8.33333e+08 flops
g(x,y,z) took 0.26 seconds to run 5e+07 iterations with double = 7.69231e+08 flops
g(x,y,z) took 0.25 seconds to run 5e+07 iterations with quantity<double> = 8e+08 flops

@endverbatim
**/

#include <iostream>
#include <cstdlib>

#include <boost/timer.hpp>

#include <boost/units/quantity.hpp>
#include <boost/units/io.hpp>
#include <boost/units/systems/si.hpp>
#include <boost/units/systems/si/constants.hpp>

using namespace boost::units;
using namespace boost::units::SI;

// faster if TEST_LIMIT is large and REPETITIONS is smalle
// because there are more function calls in the outer loop?
static const int    TEST_LIMIT = 1000000,
                    REPETITIONS = 1000;

inline
double f(double x,double y,double z)
{
    double  V = 0,
            C = 0;

    for (int i = 0; i < TEST_LIMIT; ++i)
    {   
        if (i % 100000 == 0)
            C = double(std::rand())/RAND_MAX;
        
        V = V + ((x + y) * z * C);
    }

    return V;
}

inline
double g(double x,double y,double z)
{
    double  V = 0,
            C = 0;

    for (int i = 0; i < TEST_LIMIT; ++i)
    {   
        if (i % 100000 == 0)
            C = double(std::rand())/RAND_MAX;
        
        V += ((x + y) * z * C);
    }

    return V;
}

inline
quantity<volume> f_mcs(const quantity<length>& x,const quantity<length>& y,const quantity<length>& z)
{
    quantity<volume>    V = 0 * cubic_meters;
    quantity<length>    C = 0 * meters;

    for (int i = 0; i < TEST_LIMIT; ++i)
    {   
        if (i % 100000 == 0)
            C = double(std::rand())/RAND_MAX * meters;
        
        V = V + ((x + y) * z * C);
    }

    return V;
}

inline
quantity<volume> g_mcs(const quantity<length>& x,const quantity<length>& y,const quantity<length>& z)
{
    quantity<volume>    V = 0 * cubic_meters;
    quantity<length>    C = 0 * meters;

    for (int i = 0; i < TEST_LIMIT; ++i)
    {   
        if (i % 100000 == 0)
            C = double(std::rand())/RAND_MAX * meters;
        
        V += ((x + y) * z * C);
    }

    return V;
}

int main()
{
    boost::timer    bench;
    
    {
    bench.restart();
    
    for (int i=0;i<REPETITIONS;++i)
        f(1.0,2.0,3.0);
    
    const double    elapsed = bench.elapsed(),
                    iterations = REPETITIONS*double(TEST_LIMIT),
                    flops = iterations*4/elapsed;
                    
    std::cout << "f(x,y,z) took " << elapsed
              << " seconds to run " << iterations
              << " iterations with double" 
              << " = " << flops << " flops" 
              << std::endl;
    }
    
    {
    bench.restart();
    
    for (int i=0;i<REPETITIONS;++i)
        f_mcs(1.0*meters,2.0*meters,3.0*meters);
    
    const double    elapsed = bench.elapsed(),
                    iterations = REPETITIONS*double(TEST_LIMIT),
                    flops = iterations*4/elapsed;
                    
    std::cout << "f(x,y,z) took " << elapsed
              << " seconds to run " << iterations
              << " iterations with quantity<double>" 
              << " = " << flops << " flops" 
              << std::endl;
    }
    
    {
    bench.restart();
    
    for (int i=0;i<REPETITIONS;++i)
        g(1.0,2.0,3.0);
    
    const double    elapsed = bench.elapsed(),
                    iterations = REPETITIONS*double(TEST_LIMIT),
                    flops = iterations*4/elapsed;
                    
    std::cout << "g(x,y,z) took " << elapsed
              << " seconds to run " << iterations
              << " iterations with double" 
              << " = " << flops << " flops" 
              << std::endl;
    }
    
    {
    bench.restart();
    
    for (int i=0;i<REPETITIONS;++i)
        g_mcs(1.0*meters,2.0*meters,3.0*meters);
    
    const double    elapsed = bench.elapsed(),
                    iterations = REPETITIONS*double(TEST_LIMIT),
                    flops = iterations*4/elapsed;
                    
    std::cout << "g(x,y,z) took " << elapsed
              << " seconds to run " << iterations
              << " iterations with quantity<double>" 
              << " = " << flops << " flops" 
              << std::endl;
    }
    
    return 0;
}
