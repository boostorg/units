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
/*
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
*/
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

multiplying ublas::matrix<double>(1000, 1000) : 25.03 seconds
multiplying ublas::matrix<quantity>(1000, 1000) : 24.49 seconds
tiled_matrix_multiply<double>(1000, 1000) : 1.12 seconds
tiled_matrix_multiply<quantity>(1000, 1000) : 1.16 seconds
solving y' = 1 - x + 4 * y with double: 1.97 seconds
solving y' = 1 - x + 4 * y with quantity: 1.84 seconds

@endverbatim
**/
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <iomanip>

#include <boost/timer.hpp>
#include <boost/utility/result_of.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/units/quantity.hpp>
#include <boost/units/systems/si.hpp>
#include <boost/units/cmath.hpp>

enum {
    tile_block_size = 24
};

template<class T0, class T1, class Out>
void tiled_multiply_carray_inner(T0* first, T1* second, Out* out, int totalwidth, int width2, int height1, int common) {
    for(int j = 0; j < height1; ++j) {
        for(int i = 0; i < width2; ++i) {
            Out value = out[j * totalwidth + i];
            for(int k = 0; k < common; ++k) {
                value += first[k + totalwidth * j] * second[k * totalwidth + i];
            }
            out[j * totalwidth + i] = value;
        }
    }
}

template<class T0, class T1, class Out>
void tiled_multiply_carray_outer(T0* first, T1* second, Out* out, int width2, int height1, int common) {
    std::fill_n(out, width2 * height1, Out());
    int j = 0;
    for(; j < height1 - tile_block_size; j += tile_block_size) {
        int i = 0;
        for(; i < width2 - tile_block_size; i += tile_block_size) {
            int k = 0;
            for(; k < common - tile_block_size; k += tile_block_size) {
                tiled_multiply_carray_inner(&first[k + width2 * j], &second[k * width2 + i], &out[j * width2 + i], width2, tile_block_size, tile_block_size, tile_block_size);
            }
            tiled_multiply_carray_inner(&first[k + width2 * j], &second[k * width2 + i], &out[j * width2 + i], width2, tile_block_size, tile_block_size, common - k);
        }
        int k = 0;
        for(; k < common - tile_block_size; k += tile_block_size) {
            tiled_multiply_carray_inner(&first[k + width2 * j], &second[k * width2 + i], &out[j * width2 + i], width2, width2 - i, tile_block_size, tile_block_size);
        }
        tiled_multiply_carray_inner(&first[k + width2 * j], &second[k * width2 + i], &out[j * width2 + i], width2, width2 - i, tile_block_size, common - k);
    }
    int i = 0;
    for(; i < width2 - tile_block_size; i += tile_block_size) {
        int k = 0;
        for(; k < common - tile_block_size; k += tile_block_size) {
            tiled_multiply_carray_inner(&first[k + width2 * j], &second[k * width2 + i], &out[j * width2 + i], width2, tile_block_size, height1 - j, tile_block_size);
        }
        tiled_multiply_carray_inner(&first[k + width2 * j], &second[k * width2 + i], &out[j * width2 + i], width2, tile_block_size, height1 - j, common - k);
    }
    int k = 0;
    for(; k < common - tile_block_size; k += tile_block_size) {
        tiled_multiply_carray_inner(&first[k + width2 * j], &second[k * width2 + i], &out[j * width2 + i], width2, width2 - i, height1 - j, tile_block_size);
    }
    tiled_multiply_carray_inner(&first[k + width2 * j], &second[k * width2 + i], &out[j * width2 + i], width2, width2 - i, height1 - j, common - k);
}

enum { max_value = 1000};

template<class F, class T, class N, class R>
R solve_differential_equation(F f, T lower, T upper, N steps, R start) {
    T h = (upper - lower) / steps;
    for(N i = N(); i < steps; ++i) {
        R y = start;
        T x = lower + h * i;
        typename F::template result<T, R>::type k1 = f(x, y);
        typename F::template result<T, R>::type k2 = f(x + h/2, y + h * k1 / 2);
        typename F::template result<T, R>::type k3 = f(x + h/2, y + h * k2 / 2);
        typename F::template result<T, R>::type k4 = f(x + h, y + h * k3);
        start = y + h * (k1 + 2 * k2 + 2 * k3 + k4) / 6;
    }
    return(start);
}

using namespace boost::units;

//y' = 1 - x + 4 * y
struct f {
    template<class Arg1, class Arg2> struct result;
    
    double operator()(const double& x, const double& y) const {
        return(1 - x + 4 * y);
    }

    boost::units::quantity<boost::units::SI::velocity>
    operator()(const quantity<SI::time>& x, const quantity<SI::length>& y) const {
        using namespace boost::units;
        using namespace SI;
        return(1 * meters / second - x * meters / pow<2>(seconds) + 4 * y / seconds );
    }
};

template<> 
struct f::result<double,double> {
    typedef double type;
};

template<>
struct f::result<quantity<SI::time>, quantity<SI::length> > {
    typedef quantity<SI::velocity> type;
};



//y' = 1 - x + 4 * y
//y' - 4 * y = 1 - x
//e^(-4 * x) * (dy - 4 * y * dx) = e^(-4 * x) * (1 - x) * dx
//d/dx(y * e ^ (-4 * x)) = e ^ (-4 * x) (1 - x) * dx

//d/dx(y * e ^ (-4 * x)) = e ^ (-4 * x) * dx - x * e ^ (-4 * x) * dx
//d/dx(y * e ^ (-4 * x)) = d/dx((-3/16 + 1/4 * x) * e ^ (-4 * x))
//y * e ^ (-4 * x) = (-3/16 + 1/4 * x) * e ^ (-4 * x) + C
//y = (-3/16 + 1/4 * x) + C/e ^ (-4 * x)
//y = 1/4 * x - 3/16 + C * e ^ (4 * x)

//y(0) = 1
//1 = - 3/16 + C
//C = 19/16
//y(x) = 1/4 * x - 3/16 + 19/16 * e ^ (4 * x)



int main() {
    boost::numeric::ublas::matrix<double> ublas_result;
    {
        boost::numeric::ublas::matrix<double> m1(max_value, max_value);
        boost::numeric::ublas::matrix<double> m2(max_value, max_value);
        std::srand(1492);
        for(int i = 0; i < max_value; ++i) {
            for(int j = 0; j < max_value; ++j) {
                m1(i,j) = std::rand();
                m2(i,j) = std::rand();
            }
        }
        std::cout << "multiplying ublas::matrix<double>(" << max_value << ", " << max_value << ") : ";
        boost::timer timer;
        ublas_result = (prod(m1, m2));
        std::cout << timer.elapsed() << " seconds" << std::endl;
    }
    boost::numeric::ublas::matrix<boost::units::quantity<boost::units::SI::dimensionless> > ublas_resultq;
    {
        boost::numeric::ublas::matrix<boost::units::quantity<boost::units::SI::dimensionless> > m1(max_value, max_value);
        boost::numeric::ublas::matrix<boost::units::quantity<boost::units::SI::dimensionless> > m2(max_value, max_value);
        std::srand(1492);
        for(int i = 0; i < max_value; ++i) {
            for(int j = 0; j < max_value; ++j) {
                m1(i,j) = std::rand();
                m2(i,j) = std::rand();
            }
        }
        std::cout << "multiplying ublas::matrix<quantity>(" << max_value << ", " << max_value << ") : ";
        boost::timer timer;
        ublas_resultq = (prod(m1, m2));
        std::cout << timer.elapsed() << " seconds" << std::endl;
    }
    std::vector<double> cresult(max_value * max_value);
    {
        std::vector<double> m1(max_value * max_value);
        std::vector<double> m2(max_value * max_value);
        std::srand(1492);
        for(int i = 0; i < max_value * max_value; ++i) {
            m1[i] = std::rand();
            m2[i] = std::rand();
        }
        std::cout << "tiled_matrix_multiply<double>(" << max_value << ", " << max_value << ") : ";
        boost::timer timer;
        tiled_multiply_carray_outer(&m1[0], &m2[0], &cresult[0], max_value, max_value, max_value);
        std::cout << timer.elapsed() << " seconds" << std::endl;
    }
    std::vector<boost::units::quantity<boost::units::SI::energy> > cresultq(max_value * max_value);
    {
        std::vector<boost::units::quantity<boost::units::SI::force> > m1(max_value * max_value);
        std::vector<boost::units::quantity<boost::units::SI::length> > m2(max_value * max_value);
        std::srand(1492);
        for(int i = 0; i < max_value * max_value; ++i) {
            m1[i] = std::rand() * boost::units::SI::newtons;
            m2[i] = std::rand() * boost::units::SI::meters;
        }
        std::cout << "tiled_matrix_multiply<quantity>(" << max_value << ", " << max_value << ") : ";
        boost::timer timer;
        tiled_multiply_carray_outer(&m1[0], &m2[0], &cresultq[0], max_value, max_value, max_value);
        std::cout << timer.elapsed() << " seconds" << std::endl;
    }
    for(int i = 0; i < max_value; ++i) {
        for(int j = 0; j < max_value; ++j) {
            if(std::abs(ublas_result(i,j) - cresult[i * max_value + j]) > ublas_result(i,j) /1e14) {
                std::cout << std::setprecision(15) << "Uh Oh. ublas_result(" << i << "," << j << ") = " << ublas_result(i,j) << std::endl
                          << "cresult[" << i << " * " << max_value << " + " << j << "] = " << cresult[i * max_value + j] << std::endl;
                return(EXIT_FAILURE);
            }
        }
    }
    {
        std::vector<double> values(1000);
        std::cout << "solving y' = 1 - x + 4 * y with double: ";
        boost::timer timer;
        for(int i = 0; i < 1000; ++i) {
            double x = .1 * i;
            values[i] = solve_differential_equation(f(), 0.0, x, i * 100, 1.0);
        }
        std::cout << timer.elapsed() << " seconds" << std::endl;
        for(int i = 0; i < 1000; ++i) {
            double x = .1 * i;
            double value = 1.0/4.0 * x - 3.0/16.0 + 19.0/16.0 * std::exp(4 * x);
            if(std::abs(values[i] - value) > value / 1e9) {
                std::cout << std::setprecision(15) << "i = : " << i << ", value = " << value << " approx = "  << values[i] << std::endl;
                return(EXIT_FAILURE);
            }
        }
    }
    {
        using namespace boost::units;
        using namespace SI;
        std::vector<quantity<length> > values(1000);
        std::cout << "solving y' = 1 - x + 4 * y with quantity: ";
        boost::timer timer;
        for(int i = 0; i < 1000; ++i) {
            quantity<SI::time> x = .1 * i * seconds;
            values[i] = solve_differential_equation(f(), 0.0 * seconds, x, i * 100, 1.0 * meters);
        }
        std::cout << timer.elapsed() << " seconds" << std::endl;
        for(int i = 0; i < 1000; ++i) {
            double x = .1 * i;
            quantity<SI::length> value = (1.0/4.0 * x - 3.0/16.0 + 19.0/16.0 * std::exp(4 * x)) * meters;
            if(abs(values[i] - value) > value / 1e9) {
                std::cout << std::setprecision(15) << "i = : " << i << ", value = " << value << " approx = "  << values[i] << std::endl;
                return(EXIT_FAILURE);
            }
        }
    }
}
