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
/*
#include <iostream>

#include <boost/units/io.hpp>
#include <boost/units/unit.hpp>
#include <boost/units/quantity.hpp>
#include <boost/units/systems/si.hpp>

using namespace boost::units;
using namespace boost::units::SI;

typedef quantity<power>         power_t;
typedef quantity<area>          area_t;
typedef quantity<temperature>   temp_diff_t;

typedef typeof(watts/kelvin/pow<2>(meter))  heat_transfer_coefficient_unit_type;

typedef quantity<heat_transfer_coefficient_unit_type>   heat_transfer_coefficient_t;

int main()
{
    const heat_transfer_coefficient_t watts_per_square_meter_per_kelvin = 1.0*watts/square_meter/kelvin;
    
    std::cout << watts/kelvin/pow<2>(meter) << std::endl;
    std::cout << heat_transfer_coefficient_unit_type() << std::endl
              << watts_per_square_meter_per_kelvin << std::endl
              << std::endl;
    
    return 0;
}
*/
/*
#include <iostream>

#include <boost/numeric/ublas/vector.hpp>

//#include <boost/test/test_tools.hpp>
//#include <boost/test/floating_point_comparison.hpp>

#include <boost/units/io.hpp>
#include <boost/units/unit.hpp>
#include <boost/units/quantity.hpp>
#include <boost/units/systems/si.hpp>

using namespace boost::units;
using namespace boost::units::SI;

int main()
{
//    quantity<SI::length>    a,b;
//    
//    BOOST_CHECK_CLOSE(a.value(),b.value(),0.1);
    
    //typedef double                  Type;
    typedef quantity<SI::length>    Type;
    
    boost::numeric::ublas::vector<Type> v(3);
    
    v *= 2.0;
    //v*2.0;
    
    return 0;
}
*/
/*
#include <iostream>

#include <boost/any.hpp>
#include <boost/numeric/ublas/vector.hpp>

#include <boost/units/io.hpp>
#include <boost/units/unit.hpp>
#include <boost/units/quantity.hpp>
#include <boost/units/systems/si.hpp>

using namespace boost::units;
using namespace boost::units::SI;

int main()
{
    boost::numeric::ublas::vector<boost::any> v(3);
    
    v(0) = boost::any(quantity<SI::length>(3.0*meters));
    v(1) = boost::any(quantity<SI::mass>(3.0*kilograms));
    v(2) = boost::any(quantity<SI::time>(3.0*seconds));
    
    std::cout << boost::any_cast< quantity<SI::length> >(v(0)) << std::endl;
    std::cout << boost::any_cast< quantity<SI::mass> >(v(1)) << std::endl;
    std::cout << boost::any_cast< quantity<SI::time> >(v(2)) << std::endl;

    std::cout << boost::any_cast< quantity<SI::mass> >(v(0)) << std::endl;
    
    return 0;
}
*/
#include <iostream>
#include <boost/units/io.hpp>
#include <boost/units/systems/si.hpp>
#include <boost/units/systems/cgs.hpp>
#include <boost/units/systems/si/prefixes.hpp>

using namespace boost::units;

int main()
{

	quantity<CGS::force>    F0 = 20 * CGS::dyne;

	quantity<SI::force>     F1 = quantity<SI::force>(F0);
	quantity<SI::force>     F2 = quantity<SI::force>(20 * CGS::dyne);

	quantity<SI::force>     F3(F0);
//	quantity<SI::force>     F4 = F0;

	quantity<SI::force>     F5(20 * CGS::dyne);
//	quantity<SI::force>     F6 = 20 * CGS::dyne;

	std::cout << F1 << std::endl
              << F2 << std::endl
              << F3 << std::endl
              << F5 << std::endl
              << std::endl;
    
    quantity_reinterpret_cast<double&>(F1) = 1.5;
    
    std::cout << F1 << std::endl;
    
    quantity<SI::length,double>     q(1.5*SI::meters);
    quantity<SI::length,int>		r(2*SI::meters);
    quantity<CGS::length,double>    s(2.5*CGS::centimeters);
    quantity<CGS::length,int>		t(3*CGS::centimeters);

    std::cout << q << std::endl
              << r << std::endl
              << s << std::endl
              << t << std::endl
              << std::endl;
              
    q = quantity<SI::length,double>(r); 
    
    std::cout << q << std::endl;
    
    q = quantity<SI::length,double>(s);
    
    std::cout << q << std::endl;
    
    q = quantity<SI::length,double>(t);
    
    std::cout << q << std::endl;
    
    return 0;
}



