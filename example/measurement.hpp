// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef MCS_MEASUREMENT_HPP
#define MCS_MEASUREMENT_HPP

#include <cmath>
#include <cstdlib>
#include <iostream>

#include <boost/units/static_rational.hpp>

namespace mcs {

namespace sqr_namespace {

template<class Y>
Y sqr(Y val)
{ return val*val; }

} // namespace

using sqr_namespace::sqr;

//[measurement_snippet_1
template<class Y>
class measurement
{    
    public:
        typedef measurement<Y>  this_type;
        typedef Y               value_type;
        
        measurement(const value_type& val = value_type(),
                    const value_type& err = value_type()) : 
            value_(val),
            error_(std::abs(err)) 
        { }
        
        measurement(const this_type& source) : 
            value_(source.value_),
            error_(source.error_) 
        { }
        
        ~measurement()
        { }
        
        this_type& operator=(const this_type& source)
        {
            if (this == &source) return *this;
            
            value_ = source.value_;
            error_ = source.error_;
            
            return *this;
        }
        
        operator value_type() const                     { return value_; }
        
        value_type value() const                        { return value_; }
        value_type error() const                        { return error_; }
        
        this_type& operator+=(const value_type& val)            
        { 
            value_ += val; 
            return *this; 
        }
        
        this_type& operator-=(const value_type& val)            
        { 
            value_ -= val; 
            return *this; 
        }
        
        this_type& operator*=(const value_type& val)            
        { 
            value_ *= val; 
            error_ *= val; 
            return *this; 
        }
        
        this_type& operator/=(const value_type& val)            
        { 
            value_ /= val; 
            error_ /= val; 
            return *this; 
        }
        
        this_type& operator+=(const this_type& /*source*/);
        this_type& operator-=(const this_type& /*source*/);        
        this_type& operator*=(const this_type& /*source*/);        
        this_type& operator/=(const this_type& /*source*/);

    private:
        value_type  value_,
                    error_;
};
//]

} // namespace mcs

#if BOOST_UNITS_HAS_BOOST_TYPEOF

BOOST_TYPEOF_REGISTER_TEMPLATE(mcs::measurement, 1)

#endif

namespace mcs {

template<class Y>
measurement<Y>&
measurement<Y>::operator+=(const this_type& source)
{
    error_ = std::sqrt(sqr(error_)+sqr(source.error_));
    value_ += source.value_;
    
    return *this;
}

template<class Y>
measurement<Y>&
measurement<Y>::operator-=(const this_type& source)
{
    error_ = std::sqrt(sqr(error_)+sqr(source.error_));
    value_ -= source.value_;
    
    return *this;
}

template<class Y>
measurement<Y>&
measurement<Y>::operator*=(const this_type& source)
{
    error_ = (value_*source.value_)*
              std::sqrt(sqr(error_/value_)+
                        sqr(source.error_/source.value_));
    value_ *= source.value_;
    
    return *this;
}

template<class Y>
measurement<Y>&
measurement<Y>::operator/=(const this_type& source)
{
    error_ = (value_/source.value_)*
              std::sqrt(sqr(error_/value_)+
                        sqr(source.error_/source.value_));
    value_ /= source.value_;
    
    return *this;
}

// non-member operators
template<class Y>
std::ostream& operator<<(std::ostream& os,const measurement<Y>& val)
{
    os << val.value() << "(+/-" << val.error() << ")";
    
    return os;
}

// value_type op measurement
template<class Y>
measurement<Y>
operator+(Y lhs,const measurement<Y>& rhs)
{
    return (measurement<Y>(lhs,Y(0))+=rhs);
}

template<class Y>
measurement<Y>
operator-(Y lhs,const measurement<Y>& rhs)
{
    return (measurement<Y>(lhs,Y(0))-=rhs);
}

template<class Y>
measurement<Y>
operator*(Y lhs,const measurement<Y>& rhs)
{
    return (measurement<Y>(lhs,Y(0))*=rhs);
}

template<class Y>
measurement<Y>
operator/(Y lhs,const measurement<Y>& rhs)
{
    return (measurement<Y>(lhs,Y(0))/=rhs);
}

// measurement op value_type
template<class Y>
measurement<Y>
operator+(const measurement<Y>& lhs,Y rhs)
{
    return (measurement<Y>(lhs)+=measurement<Y>(rhs,Y(0)));
}

template<class Y>
measurement<Y>
operator-(const measurement<Y>& lhs,Y rhs)
{
    return (measurement<Y>(lhs)-=measurement<Y>(rhs,Y(0)));
}

template<class Y>
measurement<Y>
operator*(const measurement<Y>& lhs,Y rhs)
{
    return (measurement<Y>(lhs)*=measurement<Y>(rhs,Y(0)));
}

template<class Y>
measurement<Y>
operator/(const measurement<Y>& lhs,Y rhs)
{
    return (measurement<Y>(lhs)/=measurement<Y>(rhs,Y(0)));
}

// measurement op measurement
template<class Y>
measurement<Y>
operator+(const measurement<Y>& lhs,const measurement<Y>& rhs)
{
    return (measurement<Y>(lhs)+=rhs);
}

template<class Y>
measurement<Y>
operator-(const measurement<Y>& lhs,const measurement<Y>& rhs)
{
    return (measurement<Y>(lhs)-=rhs);
}

template<class Y>
measurement<Y>
operator*(const measurement<Y>& lhs,const measurement<Y>& rhs)
{
    return (measurement<Y>(lhs)*=rhs);
}

template<class Y>
measurement<Y>
operator/(const measurement<Y>& lhs,const measurement<Y>& rhs)
{
    return (measurement<Y>(lhs)/=rhs);
}

} // namespace mcs

//[measurement_snippet_2
namespace boost {

namespace units {

/// specialize power typeof helper
template<class Y,long N,long D> 
struct power_typeof_helper<mcs::measurement<Y>,static_rational<N,D> >                
{ 
    typedef mcs::measurement<typename power_typeof_helper<Y,static_rational<N,D> >::type>    type; 
    
    static type value(const mcs::measurement<Y>& x)  
    { 
        const static_rational<N,D>  rat;

        const Y m = Y(rat.numerator())/Y(rat.denominator()),
                newval = std::pow(x.value(),m),
                err = newval*std::sqrt(std::pow(m*x.error()/x.value(),2));
        
        return type(newval,err);
    }
};

/// specialize root typeof helper
template<class Y,long N,long D> 
struct root_typeof_helper<mcs::measurement<Y>,static_rational<N,D> >                
{ 
    typedef mcs::measurement<typename root_typeof_helper<Y,static_rational<N,D> >::type>    type; 
    
    static type value(const mcs::measurement<Y>& x)  
    { 
        const static_rational<N,D>  rat;

        const Y m = Y(rat.denominator())/Y(rat.numerator()),
                newval = std::pow(x.value(),m),
                err = newval*std::sqrt(std::pow(m*x.error()/x.value(),2));
        
        return type(newval,err);
    }
};

} // namespace units

} // namespace boost
//]

#endif // MCS_MEASUREMENT_HPP
