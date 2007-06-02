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
    
\brief unit_example_22.cpp

\detailed Another example of defining units.

Output:
@verbatim

//[unit_example_22_output
kg s^(-3) K^(-1)
kg s^(-3) K^(-1)
1 kg s^(-3) K^(-1)
//]

@endverbatim
**/

#include <iostream>

#include <boost/units/cmath.hpp>
#include <boost/units/io.hpp>
#include <boost/units/quantity.hpp>
#include <boost/units/systems/cgs/acceleration.hpp>
#include <boost/units/systems/si/acceleration.hpp>
#include <boost/units/systems/si/force.hpp>
#include <boost/units/systems/cgs/force.hpp>
#include <boost/units/systems/si/mass.hpp>
#include <boost/units/systems/cgs/mass.hpp>
#include <boost/units/systems/si/momentum.hpp>
#include <boost/units/systems/cgs/momentum.hpp>

#include <boost/units/systems/other/non_si_units.hpp>

struct blah { };
struct blahblah { };

blahblah operator+(const blah&) { return blahblah(); }

template<typename I,I N,I D> 
class static_rational
{ };

int main()
{
    using namespace boost;
    using namespace boost::units;
    
    std::cout << quantity<SI::dimensionless>(1.0*CGS::dyne/SI::newton) << std::endl;
//    std::cout << exp(1.0*(SI::newtons*CGS::dynes)/(SI::newtons*CGS::dynes)) << std::endl;
    std::cout << exp(quantity<SI::dimensionless>(1.0*(SI::newtons*CGS::dynes)/(SI::newtons*CGS::dynes))) << std::endl;
    std::cout << conversion_factor<double>(CGS::dyne,SI::newton) << std::endl;
    std::cout << conversion_factor<double>(SI::newton/SI::kilogram,CGS::dyne/CGS::gram) << std::endl;
    std::cout << conversion_factor<double>(CGS::momentum(),SI::momentum()) << std::endl;
    std::cout << conversion_factor<double>(SI::momentum()/SI::mass(),CGS::momentum()/CGS::mass()) << std::endl;
    std::cout << conversion_factor<double>(CGS::gal,SI::meter_per_second_squared) << std::endl;
    
    blah    b;
    
    std::cout << typeid(+b).name() << std::cout;
    
    return 0;
}


