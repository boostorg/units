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
{ 273.16 } K
{ 273.16 } K
{ 273.16 } K
[ 32 ] F
[ 17.7778 ] K
[ 17.7778 ] K
[ 17.7778 ] K

@endverbatim
**/

#define MCS_USE_BOOST_REGEX_DEMANGLING

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>

#include <boost/units/io.hpp>
#include <boost/units/unit.hpp>
#include <boost/units/quantity.hpp>
#include <boost/units/systems/si/temperature.hpp>
#include <boost/units/detail/utility.hpp>

using namespace boost::units;

template<class Y = double>
class absolute
{
    public:
        typedef absolute<Y>     this_type;
        typedef Y               value_type;
        
        absolute() : val_() { }
        absolute(const value_type& val) : val_(val) { }
        absolute(const this_type& p) : val_(p.val_) { }
   
        value_type& value()                 { return val_; }
        const value_type& value() const     { return val_; }
        
    private:
        Y   val_;
};

template<class Y = double>
class relative
{
    public:
        typedef relative<Y>     this_type;
        typedef Y               value_type;
        
        relative() : val_() { }
        relative(const value_type& val) : val_(val) { }
        relative(const this_type& v) : val_(v.val_) { }
        
        value_type& value()                 { return val_; }
        const value_type& value() const     { return val_; }
        
    private:
        Y   val_;
};

template<class Y>
absolute<Y> operator+(const absolute<Y>& p,const relative<Y>& v)
{
    return absolute<Y>(p.value()+v.value());
}

template<class Y>
absolute<Y> operator-(const absolute<Y>& p,const relative<Y>& v)
{
    return absolute<Y>(p.value()-v.value());
}

template<class Y>
relative<Y> operator-(const absolute<Y>& p1,const absolute<Y>& p2)
{
    return relative<Y>(p1.value()-p2.value());
}

template<class Y>
relative<Y> operator+(const relative<Y>& v1,const relative<Y>& v2)
{
    return relative<Y>(v1.value()+v2.value());
}

template<class Y>
relative<Y> operator-(const relative<Y>& v1,const relative<Y>& v2)
{
    return relative<Y>(v1.value()-v2.value());
}

template<class Y>
std::ostream& operator<<(std::ostream& os,const absolute<Y>& p)
{
    os << "{ " << p.value() << " }";
    
    return os;
}

template<class Y>
std::ostream& operator<<(std::ostream& os,const relative<Y>& v)
{
    os << "[ " << v.value() << " ]";
    
    return os;
}

namespace boost {

namespace units {

namespace fahrenheit {

struct system_tag : public ordinal<110> { };

typedef homogeneous_system<system_tag>  system;

typedef fundamental_dimension<temperature_tag>::type    temperature_type;

typedef unit<temperature_type,system>                   temperature;

BOOST_UNITS_STATIC_CONSTANT(degree,temperature);
BOOST_UNITS_STATIC_CONSTANT(degrees,temperature);

} // fahrenheit

template<> struct unit_info<fahrenheit::system_tag,temperature_tag>
{
    static std::string name()               { return "Fahrenheit"; }
    static std::string symbol()             { return "F"; }
};

template<>
struct is_implicitly_convertible< unit<temperature_type,fahrenheit::system>,
                                  unit<temperature_type,SI::system> > : 
    public mpl::true_
{ };

template<class Y>
class conversion_helper< quantity<unit<temperature_type,fahrenheit::system>,absolute<Y> >,
                         quantity<unit<temperature_type,SI::system>,absolute<Y> > >
{
    public:
        typedef unit<temperature_type,fahrenheit::system>   unit1_type;
        typedef unit<temperature_type,SI::system>           unit2_type;
        
        typedef quantity<unit1_type,absolute<Y> >           from_quantity_type;
        typedef quantity<unit2_type,absolute<Y> >           to_quantity_type;

        static
        to_quantity_type
        convert(const from_quantity_type& source)
        {
            const typename from_quantity_type::value_type&   in(source.value());
            
            return to_quantity_type::from_value((in.value()-32)*(5.0/9.0) + 273.16);
        }
};

template<class Y>
class conversion_helper< quantity<unit<temperature_type,fahrenheit::system>,relative<Y> >,
                         quantity<unit<temperature_type,SI::system>,relative<Y> > >
{
    public:
        typedef unit<temperature_type,fahrenheit::system>   unit1_type;
        typedef unit<temperature_type,SI::system>           unit2_type;
        
        typedef quantity<unit1_type,relative<Y> >           from_quantity_type;
        typedef quantity<unit2_type,relative<Y> >           to_quantity_type;

        static
        to_quantity_type
        convert(const from_quantity_type& source)
        {
            const typename from_quantity_type::value_type&   in(source.value());
            
            return to_quantity_type::from_value(in.value()*(5.0/9.0));
        }
};

} // namespace units

} // namespace boost

int main()
{
    std::stringstream sstream1, sstream2;
    
    quantity<fahrenheit::temperature,absolute<> >   T1p(absolute<>(32)*fahrenheit::degrees);
    quantity<fahrenheit::temperature,relative<> >   T1v(relative<>(32)*fahrenheit::degrees);
    
    quantity<SI::temperature,absolute<> >           T2p(T1p);
    quantity<SI::temperature,absolute<> >           T3p = T1p;
    quantity<SI::temperature,relative<> >           T2v(T1v);
    quantity<SI::temperature,relative<> >           T3v = T1v;
    
    typedef conversion_helper<quantity<fahrenheit::temperature,absolute<> >,
                              quantity<SI::temperature,absolute<> > >           absolute_conv_type;
    typedef conversion_helper<quantity<fahrenheit::temperature,relative<> >,
                              quantity<SI::temperature,relative<> > >           relative_conv_type;
    
    sstream1  << T1p << std::endl
              << absolute_conv_type::convert(T1p) << std::endl
              << T2p << std::endl
              << T3p << std::endl
              << T1v << std::endl
              << relative_conv_type::convert(T1v) << std::endl
              << T2v << std::endl
              << T3v << std::endl
              << std::endl;
    
    sstream2  << "{ 32 } F" << std::endl
              << "{ 273.16 } K" << std::endl
              << "{ 273.16 } K" << std::endl
              << "{ 273.16 } K" << std::endl
              << "[ 32 ] F" << std::endl
              << "[ 17.7778 ] K" << std::endl
              << "[ 17.7778 ] K" << std::endl
              << "[ 17.7778 ] K" << std::endl
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
