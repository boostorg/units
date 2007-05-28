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
    
\brief unit_example_20.cpp

\detailed
Conversions between Fahrenheit and Kelvin for absolute temperatures and 
temperature differences.

Output:
@verbatim

{ 32 } F
{ 273.15 } K
{ 273.15 } K
{ 273.15 } K
[ 32 ] F
[ 17.7778 ] K
[ 17.7778 ] K
[ 17.7778 ] K

@endverbatim
**/

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>

#include <boost/units/absolute.hpp>
#include <boost/units/io.hpp>
#include <boost/units/unit.hpp>
#include <boost/units/quantity.hpp>
#include <boost/units/systems/si/temperature.hpp>
#include <boost/units/detail/utility.hpp>

BOOST_UNITS_DEFINE_AFFINE_CONVERSION(boost::units::fahrenheit_tag::unit_type, boost::units::kelvin_tag::unit_type, double, 273.15 + 5.0 / 9.0 * 32.0);

using namespace boost::units;

namespace boost {

namespace units {

namespace fahrenheit {

typedef make_system<fahrenheit_tag>::type  system;

typedef unit<temperature_type,system>                   temperature;

BOOST_UNITS_STATIC_CONSTANT(degree,temperature);
BOOST_UNITS_STATIC_CONSTANT(degrees,temperature);

} // fahrenheit

template<>
struct is_implicitly_convertible< unit<temperature_type,fahrenheit::system>,
                                  unit<temperature_type,SI::system> > : 
    public mpl::true_
{ };

template<>
struct is_implicitly_convertible<absolute< unit<temperature_type,fahrenheit::system> >,
                                  absolute< unit<temperature_type,SI::system> > > : 
    public mpl::true_
{ };

//template<class Y>
//class conversion_helper< quantity<unit<temperature_type,fahrenheit::system>,absolute<Y> >,
//                         quantity<unit<temperature_type,SI::system>,absolute<Y> > >
//{
//    public:
//        typedef unit<temperature_type,fahrenheit::system>   unit1_type;
//        typedef unit<temperature_type,SI::system>           unit2_type;
//        
//        typedef quantity<unit1_type,absolute<Y> >           from_quantity_type;
//        typedef quantity<unit2_type,absolute<Y> >           to_quantity_type;
//
//        static
//        to_quantity_type
//        convert(const from_quantity_type& source)
//        {
//            const typename from_quantity_type::value_type&   in(source.value());
//            
//            return to_quantity_type::from_value((in.value()-32)*(5.0/9.0) + 273.15);
//        }
//};
//
//template<class Y>
//class conversion_helper< quantity<unit<temperature_type,fahrenheit::system>,Y>,
//                         quantity<unit<temperature_type,SI::system>,Y> >
//{
//    public:
//        typedef unit<temperature_type,fahrenheit::system>   unit1_type;
//        typedef unit<temperature_type,SI::system>           unit2_type;
//        
//        typedef quantity<unit1_type,Y>                      from_quantity_type;
//        typedef quantity<unit2_type,Y>                      to_quantity_type;
//
//        static
//        to_quantity_type
//        convert(const from_quantity_type& source)
//        {
//            const typename from_quantity_type::value_type&   in(source.value());
//            
//            return to_quantity_type::from_value(in*(5.0/9.0));
//        }
//};

} // namespace units

} // namespace boost

int main()
{
    std::stringstream sstream1, sstream2;
    
    quantity<absolute<fahrenheit::temperature> >   T1p(32.0*absolute<fahrenheit::temperature>());
    quantity<fahrenheit::temperature>               T1v(32.0*fahrenheit::degrees);
    
    quantity<absolute<SI::temperature> >           T2p(T1p);
    quantity<absolute<SI::temperature> >           T3p = T1p;
    quantity<SI::temperature>                       T2v(T1v);
    quantity<SI::temperature>                       T3v = T1v;
    
    typedef conversion_helper<quantity<absolute<fahrenheit::temperature> >,
                              quantity<absolute<SI::temperature> > >           absolute_conv_type;
    typedef conversion_helper<quantity<fahrenheit::temperature,double>,
                              quantity<SI::temperature,double> >                relative_conv_type;
    
    sstream1  << T1p << std::endl
              << absolute_conv_type::convert(T1p) << std::endl
              << T2p << std::endl
              << T3p << std::endl
              << T1v << std::endl
              << relative_conv_type::convert(T1v) << std::endl
              << T2v << std::endl
              << T3v << std::endl
              << std::endl;
    
    sstream2  << "32 absolute F" << std::endl
              << "273.15 absolute K" << std::endl
              << "273.15 absolute K" << std::endl
              << "273.15 absolute K" << std::endl
              << "32 F" << std::endl
              << "17.7778 K" << std::endl
              << "17.7778 K" << std::endl
              << "17.7778 K" << std::endl
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

