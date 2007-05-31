// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef MCS_SCALED_VALUE_HPP
#define MCS_SCALED_VALUE_HPP

#include <cmath>
#include <iostream>

#include <boost/units/static_constant.hpp>
#include <boost/units/static_rational.hpp>
#include <boost/units/operators.hpp>

namespace boost {

namespace units {

//template<long Base = 10,long Exp = 0> 
//struct scale
//{
//    typedef long    base_type;
//    typedef long    exponent_type;
//    
//    static base_type base()         { return Base; }
//    static exponent_type exponent() { return Exp; }
//    
//    scale() { }
//    ~scale() { }
//};

/// scaled_value
template<class Y = double,class Z = scale<10,static_rational<0> > > class scaled_value;

template<class Y,long Base,long Exp>
class scaled_value< Y,scale<Base,static_rational<Exp> > >
{    
    public:
        typedef scaled_value< Y,scale<Base,static_rational<Exp> > >   this_type;
        typedef Y                                   value_type;
        typedef scale<Base,static_rational<Exp> >                     scale_type;
        //typedef typename scale_type::base_type      base_type;
        //typedef typename scale_type::exponent_type  exponent_type;
        
        scaled_value(const value_type& val = value_type()) : 
            value_(val) 
        { }
        
        scaled_value(const this_type& source) : 
            value_(source.value_) 
        { }
        
        ~scaled_value()
        { }
        
        this_type& operator=(const this_type& source)
        {
            if (this == &source) return *this;
            
            value_ = source.value_;
            
            return *this;
        }
        
        //base_type base() const                          { return scale_type::base(); }
        //exponent_type exponent() const                  { return scale_type::exponent(); }
        const value_type& value() const                 { return value_; }
        
        this_type& operator*=(value_type val)            
        { 
            value_ *= val; 
            return *this; 
        }
        
        this_type& operator/=(value_type val)            
        { 
            value_ /= val; 
            return *this; 
        }
        
        this_type& operator+=(const this_type& source)  { value_ += source.value_; return *this; }
        this_type& operator-=(const this_type& source)  { value_ -= source.value_; return *this; }

    private:
        value_type  value_;
};

//// non-member operators
//inline std::string getLongPrefix(const scale<10,-24>&)      { return "yocto"; }
//inline std::string getLongPrefix(const scale<10,-21>&)      { return "zepto"; }
//inline std::string getLongPrefix(const scale<10,-18>&)      { return "atto"; }
//inline std::string getLongPrefix(const scale<10,-15>&)      { return "femto"; }
//inline std::string getLongPrefix(const scale<10,-12>&)      { return "pico"; }
//inline std::string getLongPrefix(const scale<10,-9>&)       { return "nano"; }
//inline std::string getLongPrefix(const scale<10,-6>&)       { return "micro"; }
//inline std::string getLongPrefix(const scale<10,-3>&)       { return "milli"; }
//inline std::string getLongPrefix(const scale<10,-2>&)       { return "centi"; }
//inline std::string getLongPrefix(const scale<10,-1>&)       { return "deci"; }
//inline std::string getLongPrefix(const scale<10,0>&)        { return ""; }
//inline std::string getLongPrefix(const scale<10,1>&)        { return "deka"; }
//inline std::string getLongPrefix(const scale<10,2>&)        { return "hecto"; }
//inline std::string getLongPrefix(const scale<10,3>&)        { return "kilo"; }
//inline std::string getLongPrefix(const scale<10,6>&)        { return "mega"; }
//inline std::string getLongPrefix(const scale<10,9>&)        { return "giga"; }
//inline std::string getLongPrefix(const scale<10,12>&)       { return "tera"; }
//inline std::string getLongPrefix(const scale<10,15>&)       { return "peta"; }
//inline std::string getLongPrefix(const scale<10,18>&)       { return "exa"; }
//inline std::string getLongPrefix(const scale<10,21>&)       { return "zetta"; }
//inline std::string getLongPrefix(const scale<10,24>&)       { return "yotta"; }
//
//inline std::string getShortPrefix(const scale<10,-24>&)     { return "y"; }
//inline std::string getShortPrefix(const scale<10,-21>&)     { return "z"; }
//inline std::string getShortPrefix(const scale<10,-18>&)     { return "a"; }
//inline std::string getShortPrefix(const scale<10,-15>&)     { return "f"; }
//inline std::string getShortPrefix(const scale<10,-12>&)     { return "p"; }
//inline std::string getShortPrefix(const scale<10,-9>&)      { return "n"; }
//inline std::string getShortPrefix(const scale<10,-6>&)      { return "u"; }
//inline std::string getShortPrefix(const scale<10,-3>&)      { return "m"; }
//inline std::string getShortPrefix(const scale<10,-2>&)      { return "c"; }
//inline std::string getShortPrefix(const scale<10,-1>&)      { return "d"; }
//inline std::string getShortPrefix(const scale<10,0>&)       { return ""; }
//inline std::string getShortPrefix(const scale<10,1>&)       { return "da"; }
//inline std::string getShortPrefix(const scale<10,2>&)       { return "h"; }
//inline std::string getShortPrefix(const scale<10,3>&)       { return "k"; }
//inline std::string getShortPrefix(const scale<10,6>&)       { return "M"; }
//inline std::string getShortPrefix(const scale<10,9>&)       { return "G"; }
//inline std::string getShortPrefix(const scale<10,12>&)      { return "T"; }
//inline std::string getShortPrefix(const scale<10,15>&)      { return "P"; }
//inline std::string getShortPrefix(const scale<10,18>&)      { return "E"; }
//inline std::string getShortPrefix(const scale<10,21>&)      { return "Z"; }
//inline std::string getShortPrefix(const scale<10,24>&)      { return "Y"; }
//
//inline std::string getLongPrefix(const scale<2,10>&)        { return "kibi"; }
//inline std::string getLongPrefix(const scale<2,20>&)        { return "mebi"; }
//inline std::string getLongPrefix(const scale<2,30>&)        { return "gibi"; }
//inline std::string getLongPrefix(const scale<2,40>&)        { return "tebi"; }
//inline std::string getLongPrefix(const scale<2,50>&)        { return "pebi"; }
//inline std::string getLongPrefix(const scale<2,60>&)        { return "exbi"; }
//
//inline std::string getShortPrefix(const scale<2,10>&)       { return "Ki"; }
//inline std::string getShortPrefix(const scale<2,20>&)       { return "Mi"; }
//inline std::string getShortPrefix(const scale<2,30>&)       { return "Gi"; }
//inline std::string getShortPrefix(const scale<2,40>&)       { return "Ti"; }
//inline std::string getShortPrefix(const scale<2,50>&)       { return "Pi"; }
//inline std::string getShortPrefix(const scale<2,60>&)       { return "Ei"; }

template<class Scale>
std::string getLongPrefix(const Scale&) { return(Scale::name_prefix()); }
template<class Scale>
std::string getShortPrefix(const Scale&) { return(Scale::symbol_prefix()); }

template<class Scale> struct reduced_scale;

template<long Exp> struct reduced_scale<scale<2,static_rational<Exp> > >      { typedef scale<2,static_rational<10*(Exp/10)> >  type; };
template<long Exp> struct reduced_scale<scale<10,static_rational<Exp> > >      { typedef scale<10,static_rational<3*(Exp/3)> >  type; };

template<class Y,class Scale>
std::ostream& operator<<(std::ostream& os,const scaled_value< Y,Scale>& val)
{
    typedef typename reduced_scale<Scale>::type  reduced_scale;
    
    //static const long   reduced_exponent = reduced_scale::exponent(),
    //                    remainder_exponent = Exp-reduced_exponent;
    typedef typename mpl::minus<typename Scale::exponent, typename reduced_scale::exponent>::type remainder_exponent;
    
    if (boost::is_same<typename reduced_scale::exponent, static_rational<0> >())
    {
        os << val.value()*Scale::value();
    }
    else
    {
//      os << val.value() << " x " << val.base() << "^" << Exp;
        os << val.value()*scale<(Scale::base), remainder_exponent>::value() << " x " << reduced_scale::base << "^" << typename reduced_scale::exponent();
//        os << val.value()*std::pow(Y(val.base()),Y(remainder_exponent)) << " " << getShortPrefix(reduced_scale());
    }
    
    return os;
}

// value_type op scale
template<class Y,long Base,class Exp>
scaled_value< Y,scale<Base,Exp> >
operator*(const Y& lhs,const scale<Base,Exp>&)
{
    return scaled_value< Y,scale<Base,Exp> >(lhs);
}

template<class Y,long Base,class Exp>
scaled_value< Y,scale<Base,typename mpl::negate<Exp>::type> >
operator/(const Y& lhs,const scale<Base,Exp>&)
{
    return scaled_value< Y,scale<Base,typename mpl::negate<Exp>::type> >(lhs);
}

//msvc can't find the template operator/ ???
scaled_value< double,scale<10,static_rational<-4> > >
inline operator/(const double& lhs,const scale<10,static_rational<4> >&)
{
    return scaled_value< double,scale<10,static_rational<-4> > >(lhs);
}

// scale op value_type
template<class Y,long Base,class Exp>
scaled_value< Y,scale<Base,Exp> >
operator*(const scale<Base,Exp>&,const Y& rhs)
{
    return scaled_value< Y,scale<Base,Exp> >(rhs);
}

template<class Y,long Base,class Exp>
scaled_value< Y,scale<Base,Exp> >
operator/(const scale<Base,Exp>&,const Y& rhs)
{
    return scaled_value< Y,scale<Base,Exp> >(Y(1)/rhs);
}

// value_type op scaled_value
template<class Y,long Base,class Exp>
scaled_value< Y,scale<Base,Exp> >
operator*(const Y& lhs,const scaled_value< Y,scale<Base,Exp> >& rhs)
{
    return scaled_value< Y,scale<Base,Exp> >(lhs*rhs.value());
}

template<class Y,long Base,class Exp>
scaled_value< Y,scale<Base,typename mpl::negate<Exp>::type> >
operator/(const Y& lhs,const scaled_value< Y,scale<Base,Exp> >& rhs)
{
    return scaled_value< Y,scale<Base,typename mpl::negate<Exp>::type> >(lhs/rhs.value());
}

// scaled_value op value_type
template<class Y,long Base,class Exp>
scaled_value< Y,scale<Base,Exp> >
operator*(const scaled_value< Y,scale<Base,Exp> >& lhs,const Y& rhs)
{
    return scaled_value< Y,scale<Base,Exp> >(lhs.value()*rhs);
}

template<class Y,long Base,class Exp>
scaled_value< Y,scale<Base,Exp> >
operator/(const scaled_value< Y,scale<Base,Exp> >& lhs,const Y& rhs)
{
    return scaled_value< Y,scale<Base,Exp> >(lhs.value()/rhs);
}

// scaled_value op scaled_value
template<class Y,long Base,class Exp>
scaled_value< Y,scale<Base,Exp> >
operator+(const scaled_value< Y,scale<Base,Exp> >& lhs,
          const scaled_value< Y,scale<Base,Exp> >& rhs)
{
    return scaled_value< Y,scale<Base,Exp> >(lhs.value()+rhs.value());
}

template<class Y,long Base,class Exp>
scaled_value< Y,scale<Base,Exp> >
operator-(const scaled_value< Y,scale<Base,Exp> >& lhs,
          const scaled_value< Y,scale<Base,Exp> >& rhs)
{
    return scaled_value< Y,scale<Base,Exp> >(lhs.value()-rhs.value());
}

template<class Y,long Base,class Exp1,class Exp2>
scaled_value< Y,scale<Base,typename mpl::plus<Exp1,Exp2>::type> >
operator*(const scaled_value< Y,scale<Base,Exp1> >& lhs,
          const scaled_value< Y,scale<Base,Exp2> >& rhs)
{
    return scaled_value< Y,scale<Base,typename mpl::plus<Exp1,Exp2>::type> >(lhs.value()*rhs.value());
}

template<class Y,long Base,class Exp1,class Exp2>
scaled_value< Y,scale<Base,typename mpl::minus<Exp1,Exp2>::type> >
operator/(const scaled_value< Y,scale<Base,Exp1> >& lhs,
          const scaled_value< Y,scale<Base,Exp2> >& rhs)
{
    return scaled_value< Y,scale<Base,typename mpl::minus<Exp1,Exp2>::type> >(lhs.value()/rhs.value());
}

/// specialize power typeof helper
template<class Y,long Base,class Exp,long N,long D> 
struct power_dimof_helper<scaled_value<Y,scale<Base,Exp> >,static_rational<N,D> >                
{ 
    typedef scaled_value<Y,scale<Base,typename mpl::times<Exp,static_rational<N> >::type> >    type; 
    
    static type value(const scaled_value<Y,scale<Base,Exp> >& x)  
    { 
        const static_rational<N,D>  rat;

        return type(std::pow(x.value(),Y(1)/Y(rat.denominator())));
    }
};

/// specialize root typeof helper
template<class Y,long Base,class Exp,long N,long D> 
struct root_typeof_helper<scaled_value<Y,scale<Base,Exp> >,static_rational<N,D> >                
{ 
    typedef scaled_value<Y,scale<Base,typename mpl::times<Exp,static_rational<D> >::type> >    type;
    
    static type value(const scaled_value<Y,scale<Base,Exp> >& x)  
    { 
        const static_rational<N,D>  rat;

        return type(std::pow(x.value(),Y(1)/Y(rat.numerator())));
    }
};

namespace IEEE_1541 {

namespace _ {

typedef scale<2,static_rational<10> > scale_2_10;
typedef scale<2,static_rational<20> > scale_2_20;
typedef scale<2,static_rational<30> > scale_2_30;
typedef scale<2,static_rational<40> > scale_2_40;
typedef scale<2,static_rational<50> > scale_2_50;
typedef scale<2,static_rational<60> > scale_2_60;

} // namespace _

BOOST_UNITS_STATIC_CONSTANT(kibi,_::scale_2_10) = {};
BOOST_UNITS_STATIC_CONSTANT(mebi,_::scale_2_20) = {};
BOOST_UNITS_STATIC_CONSTANT(gibi,_::scale_2_30) = {};
BOOST_UNITS_STATIC_CONSTANT(tebi,_::scale_2_40) = {};
BOOST_UNITS_STATIC_CONSTANT(pebi,_::scale_2_50) = {};
BOOST_UNITS_STATIC_CONSTANT(exbi,_::scale_2_60) = {};

BOOST_UNITS_STATIC_CONSTANT(Ki,_::scale_2_10) = {};
BOOST_UNITS_STATIC_CONSTANT(Mi,_::scale_2_20) = {};
BOOST_UNITS_STATIC_CONSTANT(Gi,_::scale_2_30) = {};
BOOST_UNITS_STATIC_CONSTANT(Ti,_::scale_2_40) = {};
BOOST_UNITS_STATIC_CONSTANT(Pi,_::scale_2_50) = {};
BOOST_UNITS_STATIC_CONSTANT(Ei,_::scale_2_60) = {};

} // namespace IEEE_1541

namespace metric {

namespace _ {

typedef scale<10,static_rational<-24> >   scale_10_m24;
typedef scale<10,static_rational<-21> >   scale_10_m21;
typedef scale<10,static_rational<-18> >   scale_10_m18;
typedef scale<10,static_rational<-15> >   scale_10_m15;
typedef scale<10,static_rational<-12> >   scale_10_m12;
typedef scale<10,static_rational<-9> >    scale_10_m9;
typedef scale<10,static_rational<-6> >    scale_10_m6;
typedef scale<10,static_rational<-3> >    scale_10_m3;
typedef scale<10,static_rational<-2> >    scale_10_m2;
typedef scale<10,static_rational<-1> >    scale_10_m1;
typedef scale<10,static_rational<1> >     scale_10_1;
typedef scale<10,static_rational<2> >     scale_10_2;
typedef scale<10,static_rational<3> >     scale_10_3;
typedef scale<10,static_rational<6> >     scale_10_6;
typedef scale<10,static_rational<9> >     scale_10_9;
typedef scale<10,static_rational<12> >    scale_10_12;
typedef scale<10,static_rational<15> >    scale_10_15;
typedef scale<10,static_rational<18> >    scale_10_18;
typedef scale<10,static_rational<21> >    scale_10_21;
typedef scale<10,static_rational<24> >    scale_10_24;

} // namespace _

BOOST_UNITS_STATIC_CONSTANT(yocto,_::scale_10_m24) = {};
BOOST_UNITS_STATIC_CONSTANT(zepto,_::scale_10_m21) = {};
BOOST_UNITS_STATIC_CONSTANT(atto,_::scale_10_m18) = {};
BOOST_UNITS_STATIC_CONSTANT(femto,_::scale_10_m15) = {};
BOOST_UNITS_STATIC_CONSTANT(pico,_::scale_10_m12) = {};
BOOST_UNITS_STATIC_CONSTANT(nano,_::scale_10_m9) = {};
BOOST_UNITS_STATIC_CONSTANT(micro,_::scale_10_m6) = {};
BOOST_UNITS_STATIC_CONSTANT(milli,_::scale_10_m3) = {};
BOOST_UNITS_STATIC_CONSTANT(centi,_::scale_10_m2) = {};
BOOST_UNITS_STATIC_CONSTANT(deci,_::scale_10_m1) = {};
BOOST_UNITS_STATIC_CONSTANT(deka,_::scale_10_1) = {};
BOOST_UNITS_STATIC_CONSTANT(hecto,_::scale_10_2) = {};
BOOST_UNITS_STATIC_CONSTANT(kilo,_::scale_10_3) = {};
BOOST_UNITS_STATIC_CONSTANT(mega,_::scale_10_6) = {};
BOOST_UNITS_STATIC_CONSTANT(giga,_::scale_10_9) = {};
BOOST_UNITS_STATIC_CONSTANT(tera,_::scale_10_12) = {};
BOOST_UNITS_STATIC_CONSTANT(peta,_::scale_10_15) = {};
BOOST_UNITS_STATIC_CONSTANT(exa,_::scale_10_18) = {};
BOOST_UNITS_STATIC_CONSTANT(zetta,_::scale_10_21) = {};
BOOST_UNITS_STATIC_CONSTANT(yotta,_::scale_10_24) = {};

} // namespace metric

} // namespace units

} // namespace boost

#if BOOST_UNITS_HAS_BOOST_TYPEOF

#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

BOOST_TYPEOF_REGISTER_TEMPLATE(boost::units::scaled_value, 2)

#endif

#endif // MCS_SCALED_VALUE_HPP
