// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_TEMPERATURE_FAHRENHEIT_HPP
#define BOOST_UNITS_TEMPERATURE_FAHRENHEIT_HPP

#include <string>

#include <boost/units/io.hpp>
#include <boost/units/static_constant.hpp>
#include <boost/units/system.hpp>
#include <boost/units/systems/physical_units.hpp>

namespace boost {

namespace units {

template<class Y = double>
class absolute
{
    public:
        typedef absolute<Y>     this_type;
        typedef Y               value_type;
        
        absolute() : val_() { }
        absolute(const value_type& val) : val_(val) { }
        absolute(const this_type& source) : val_(source.val_) { }
   
        value_type& value()                 { return val_; }
        const value_type& value() const     { return val_; }
        
        const this_type& operator+=(const Y& val);
        const this_type& operator-=(const Y& val);
        
    private:
        Y   val_;
};

template<class Y>
absolute<Y> operator+(const absolute<Y>& aval,const Y& rval)
{
    return absolute<Y>(aval.value()+rval.value());
}

template<class Y>
absolute<Y> operator-(const absolute<Y>& aval,const Y& rval)
{
    return absolute<Y>(aval.value()-rval.value());
}

template<class Y>
Y operator-(const absolute<Y>& aval1,const absolute<Y>& aval2)
{
    return Y(aval1.value()-aval2.value());
}

template<class Y>
std::ostream& operator<<(std::ostream& os,const absolute<Y>& aval)
{
    using namespace std;
    
    os << aval.value();
    
    return os;
}

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
class conversion_helper< quantity<unit<temperature_type,fahrenheit::system>,Y >,
                         quantity<unit<temperature_type,SI::system>,Y > >
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

#endif // BOOST_UNITS_TEMPERATURE_FAHRENHEIT_HPP