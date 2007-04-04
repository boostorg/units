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
/*
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
    
    quantity_cast<double&>(F1) = 1.5;
    
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
*/
/*
//// main.cpp
////
//// Copyright (c) 2007
//// Steven Watanabe
////
//// Disributed under the Boost Software License, Version 1.0. (See
//// accompanying file LICENSE_1_0.txt or copy at
//// http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_NO_SFINAE

#include <boost/units/quantity.hpp>
#include <boost/units/systems/si.hpp>

#include <iostream>

using namespace boost::units;

namespace boost { namespace units {

template<int N>
struct f {
    typedef typename derived_dimension<length_tag, (1<<N) >::type dim1;
    typedef typename derived_dimension<mass_tag, (1<<N) >::type dim2;
    template<class T>
    static void apply(const T& t) {
        f<N - 1>::apply(t * unit<dim1, SI::system>());
        f<N - 1>::apply(t * unit<dim2, SI::system>());
    }
};
template<>
struct f<0> {
    template<class T>
    static void apply(const T&) {
    }
};

} }

int main()
{
    f<7>::apply(1.0 * SI::meters);
    f<7>::apply(1.0 * SI::kilograms);
    return(0);
}
*/
/*
#include <iostream>
#include <boost/units/io.hpp>
#include <boost/units/systems/si.hpp>
#include <boost/units/systems/cgs.hpp>
#include <boost/units/systems/si/prefixes.hpp>

using namespace boost::units;

template<class System,class Y>
typeof(quantity<unit<length_type,System>,Y>()*quantity<unit<length_type,System>,Y>())
compute_area(const quantity<unit<length_type,System>,Y>& L)
{
    return L*L;
}

int main()
{
    std::cout << compute_area(2.0*SI::meters) << std::endl
              << compute_area(20.0*root<2>(SI::meters)*root<2>(CGS::centimeters)) << std::endl
              << quantity<SI::area>(compute_area(20.0*root<2>(SI::meters)*root<2>(CGS::centimeters))) << std::endl
              << std::endl;
    
    return 0;
}
*/
/*
#include <iostream>

#include <boost/units/io.hpp>
#include <boost/units/absolute.hpp>
#include <boost/units/systems/si/temperature.hpp>
#include <boost/units/systems/temperature/celsius.hpp>
#include <boost/units/systems/temperature/fahrenheit.hpp>
#include <boost/units/systems/conversions/conversion_headers.hpp>

using namespace boost::units;

int main()
{
//    quantity<SI::temperature>                       KTR(273.15*SI::kelvin);
//    quantity<SI::temperature,absolute<> >           KTA(absolute<>(273.15)*SI::kelvin);
//              
//    quantity<celsius::temperature>                  CTR(0.0*celsius::degrees);
//    quantity<celsius::temperature,absolute<> >      CTA(absolute<>(0.0)*celsius::degrees);
//    
//    quantity<fahrenheit::temperature>               FTR(32.0*fahrenheit::degrees);
//    quantity<fahrenheit::temperature,absolute<> >   FTA(absolute<>(32.0)*fahrenheit::degrees);

    quantity<SI::temperature>                       KTR(373.15*SI::kelvin);
    quantity<SI::temperature,absolute<> >           KTA(absolute<>(373.15)*SI::kelvin);
              
    quantity<celsius::temperature>                  CTR(100.0*celsius::degrees);
    quantity<celsius::temperature,absolute<> >      CTA(absolute<>(100.0)*celsius::degrees);
    
    quantity<fahrenheit::temperature>               FTR(212.0*fahrenheit::degrees);
    quantity<fahrenheit::temperature,absolute<> >   FTA(absolute<>(212.0)*fahrenheit::degrees);
    
    std::cout << KTR << std::endl
              << KTA << std::endl
              << std::endl;
    
    std::cout << CTR << std::endl
              << CTA << std::endl
              << std::endl;
              
    std::cout << FTR << std::endl
              << FTA << std::endl
              << std::endl;
    
    // kelvin->celsius
    quantity<celsius::temperature>                  CTR2(KTR);
    quantity<celsius::temperature,absolute<> >      CTA2(KTA);
    
    std::cout << KTR << " = " << CTR2 << std::endl
              << KTA << " = " << CTA2 << std::endl
              << std::endl;
    
    // celsius->kelvin
    quantity<SI::temperature>                       KTR2(CTR);
    quantity<SI::temperature,absolute<> >           KTA2(CTA);
    
    std::cout << CTR << " = " << KTR2 << std::endl
              << CTA << " = " << KTA2 << std::endl
              << std::endl;
    
    // kelvin->fahrenheit
    quantity<fahrenheit::temperature>               FTR2(KTR);
    quantity<fahrenheit::temperature,absolute<> >   FTA2(KTA);
    
    std::cout << KTR << " = " << FTR2 << std::endl
              << KTA << " = " << FTA2 << std::endl
              << std::endl;
    
    // fahrenheit->kelvin
    quantity<SI::temperature>                       KTR3(FTR);
    quantity<SI::temperature,absolute<> >           KTA3(FTA);
    
    std::cout << FTR << " = " << KTR3 << std::endl
              << FTA << " = " << KTA3 << std::endl
              << std::endl;
    
    // fahrenheit->celsius
    quantity<celsius::temperature>                  CTR3(FTR);
    quantity<celsius::temperature,absolute<> >      CTA3(FTA);
    
    std::cout << FTR << " = " << CTR3 << std::endl
              << FTA << " = " << CTA3 << std::endl
              << std::endl;
    
    // celsius->fahrenheit
    quantity<fahrenheit::temperature>               FTR3(CTR);
    quantity<fahrenheit::temperature,absolute<> >   FTA3(CTA);
    
    std::cout << CTR << " = " << FTR3 << std::endl
              << CTA << " = " << FTA3 << std::endl
              << std::endl;
                                      
    return 0;
}
*/

#include <iostream>

#include <boost/units/io.hpp>
#include <boost/units/systems/si/energy.hpp>
#include <boost/units/systems/si/power.hpp>

namespace boost { 

namespace units {

template<class Char, class Traits>
std::basic_ostream<Char, Traits>& operator<<(std::basic_ostream<Char, Traits>& os,
                                             const SI::energy& u)
{
    os << "J";
    return os;
}

template<class Char, class Traits>
std::basic_ostream<Char, Traits>& operator<<(std::basic_ostream<Char, Traits>& os,
                                             const SI::power& u)
{
    os << "W";
    return os;
}

} 

}

int main()
{
    using namespace boost::units;
    
    std::cout << quantity<SI::energy>(1.0*SI::joules) << std::endl
              << quantity<SI::power>(2.0*SI::watts) << std::endl
              << std::endl;
              
    return 0;
}

/*
#define MCS_USE_BOOST_REGEX_DEMANGLING

#include <iostream>

#include <boost/units/io.hpp>
#include <boost/units/quantity.hpp>
#include <boost/units/experimental/make_system.hpp>
#include <boost/units/experimental/fundamental_units.hpp>
#include <boost/units/detail/utility.hpp>

int main()
{
    using namespace boost;
    using namespace boost::units;
    
    typedef make_system<mpl::list<meter_tag,gram_tag,second_tag> >::type   system1_type;
    
    std::cout << simplify_typename(system1_type()) << std::endl;
    
    return 0;
}
*/


