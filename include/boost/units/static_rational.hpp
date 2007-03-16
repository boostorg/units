// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_STATIC_RATIONAL_HPP 
#define BOOST_UNITS_STATIC_RATIONAL_HPP

#include <cmath>
#include <complex>

#include <boost/math/common_factor.hpp>

#include <boost/units/operators.hpp>

/// \file 
/// \brief Compile-time rational numbers and operators.

namespace boost {

namespace units { 

typedef long   integer_type;

/// Compile time absolute value.
template<integer_type Value>
struct static_abs
{
    BOOST_STATIC_CONSTANT(integer_type,value) = Value < 0 ? -Value : Value;
};

/// Compile time rational number.
/** 
This is an implementation of a compile time rational number, where @c static_rational<N,D> represents
a rational number with numerator @c N and denominator @c D. Because of the potential for ambiguity arising 
from multiple equivalent values of @c static_rational (e.g. @c static_rational<6,2>==static_rational<3>), 
static rationals should always be accessed through @c static_rational<N,D>::type. Template specialization 
prevents instantiation of zero denominators (i.e. @c static_rational<N,0>). The following compile-time 
arithmetic operators are provided for static_rational variables only (no operators are defined between 
long and static_rational):
    - @c static_negate
    - @c static_add
    - @c static_subtract
    - @c static_multiply
    - @c static_divide

Neither @c static_power nor @c static_root are defined for @c static_rational. This is because template types 
may not be floating point values, while powers and roots of rational numbers can produce floating point 
values. 
*/
template<integer_type N,integer_type D = 1>
class static_rational
{
    private:
        static const integer_type   nabs = static_abs<N>::value,
                                    dabs = static_abs<D>::value;
        
        /// greatest common divisor of N and D
        // need cast to signed because static_gcd returns unsigned long
        static const integer_type   den = 
            static_cast<integer_type>(boost::math::static_gcd<nabs,dabs>::value);
        
    public:   
        static const integer_type   Numerator = N/den,
                                    Denominator = D/den;
        
        typedef static_rational<N,D>    this_type;
        
        /// static_rational<N,D> reduced by GCD
        typedef static_rational<Numerator,Denominator>  type;
                                 
        static integer_type numerator()      { return Numerator; }
        static integer_type denominator()    { return Denominator; }
        
        static_rational() { }
        //~static_rational() { }
};

}

}

#if BOOST_UNITS_HAS_BOOST_TYPEOF

#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

BOOST_TYPEOF_REGISTER_TEMPLATE(boost::units::static_rational, (long)(long))

#endif

namespace boost {

namespace units {

// prohibit zero denominator
template<integer_type N> class static_rational<N,0>;

/// get decimal value of @c static_rational
template<class T,integer_type N,integer_type D>
typename divide_typeof_helper<T,T>::type 
value(const static_rational<N,D>& r)
{
    return T(N)/T(D);
}

/// negate @c static_rational
template<integer_type N,integer_type D> 
struct static_negate< static_rational<N,D> >    
{ 
    typedef typename static_rational<-N,D>::type    type; 
};

/// add @c static_rational
template<integer_type N1,integer_type D1,
         integer_type N2,integer_type D2> 
struct static_add< static_rational<N1,D1>,static_rational<N2,D2> >    
{ 
    typedef typename static_rational<N1*D2+N2*D1,D1*D2>::type    type; 
};

/// subtract @c static_rational
template<integer_type N1,integer_type D1,
         integer_type N2,integer_type D2> 
struct static_subtract< static_rational<N1,D1>,static_rational<N2,D2> >
{ 
    typedef typename static_rational<N1*D2-N2*D1,D1*D2>::type    type; 
};

/// multiply @c static_rational
template<integer_type N1,integer_type D1,
         integer_type N2,integer_type D2> 
struct static_multiply< static_rational<N1,D1>,static_rational<N2,D2> >    
{ 
    typedef typename static_rational<N1*N2,D1*D2>::type    type; 
};

/// divide @c static_rational
template<integer_type N1,integer_type D1,
         integer_type N2,integer_type D2> 
struct static_divide< static_rational<N1,D1>,static_rational<N2,D2> >    
{ 
    typedef typename static_rational<N1*D2,D1*N2>::type    type; 
};

/// raise @c int to a @c static_rational power
template<long N,long D> 
struct power_typeof_helper<int,static_rational<N,D> >                
{ 
    typedef double    type; 
    
    static type value(const int& x)  
    { 
        const static_rational<N,D>  rat;
        
        return std::pow(double(x),double(rat.numerator())/double(rat.denominator())); 
    }
};

/// raise @c float to a @c static_rational power
template<long N,long D> 
struct power_typeof_helper<float,static_rational<N,D> >                
{ 
    typedef double    type; 
    
    static type value(const float& x)  
    { 
        const static_rational<N,D>  rat;
        
        return std::pow(x,float(rat.numerator())/float(rat.denominator())); 
    }
};

/// raise @c double to a @c static_rational power
template<long N,long D> 
struct power_typeof_helper<double,static_rational<N,D> >                
{ 
    typedef double    type; 
    
    static type value(const double& x)  
    { 
        const static_rational<N,D>  rat;
        
        return std::pow(x,double(rat.numerator())/double(rat.denominator())); 
    }
};

/// raise @c std::complex<float> to a @c static_rational power
template<long N,long D> 
struct power_typeof_helper<std::complex<float>,static_rational<N,D> >  
{ 
    typedef std::complex<float>    type; 
    
    static type value(const std::complex<float>& x)  
    { 
        const static_rational<N,D>  rat;
        
        return std::pow(x,std::complex<float>(rat.numerator())/std::complex<float>(rat.denominator())); 
    }
};

/// raise @c std::complex<double> to a @c static_rational power
template<long N,long D> 
struct power_typeof_helper<std::complex<double>,static_rational<N,D> >  
{ 
    typedef std::complex<double>    type; 
    
    static type value(const std::complex<double>& x)  
    { 
        const static_rational<N,D>  rat;
        
        return std::pow(x,std::complex<double>(rat.numerator())/std::complex<double>(rat.denominator())); 
    }
};

/// take @c static_rational root of an @c int
template<long N,long D> 
struct root_typeof_helper<int,static_rational<N,D> >                
{ 
    typedef double    type; 
    
    static type value(const int& x)  
    { 
        const static_rational<N,D>  rat;
        
        return std::pow(double(x),double(rat.denominator())/double(rat.numerator())); 
    }
};

/// take @c static_rational root of a @c float
template<long N,long D> 
struct root_typeof_helper<float,static_rational<N,D> >                
{ 
    typedef float    type; 
    
    static type value(const float& x)  
    { 
        const static_rational<N,D>  rat;
        
        return std::pow(x,float(rat.denominator())/float(rat.numerator())); 
    }
};

/// take @c static_rational root of a @c double
template<long N,long D> 
struct root_typeof_helper<double,static_rational<N,D> >                
{ 
    typedef double    type; 
    
    static type value(const double& x)  
    { 
        const static_rational<N,D>  rat;
        
        return std::pow(x,double(rat.denominator())/double(rat.numerator())); 
    }
};

/// take @c static_rational root of a @c std::complex<float>
template<long N,long D> 
struct root_typeof_helper<std::complex<float>,static_rational<N,D> >  
{ 
    typedef std::complex<float>    type; 
    
    static type value(const std::complex<float>& x)  
    { 
        const static_rational<N,D>  rat;
        
        return std::pow(x,std::complex<float>(rat.denominator())/std::complex<float>(rat.numerator())); 
    }
};

/// take @c static_rational root of a @c std::complex<double>
template<long N,long D> 
struct root_typeof_helper<std::complex<double>,static_rational<N,D> >  
{ 
    typedef std::complex<double>    type; 
    
    static type value(const std::complex<double>& x)  
    { 
        const static_rational<N,D>  rat;
        
        return std::pow(x,std::complex<double>(rat.denominator())/std::complex<double>(rat.numerator())); 
    }
};

// need powers and roots of char, short, long long, unsigned integers...

/// raise a value to a @c static_rational power
template<class Rat,class Y>
typename power_typeof_helper<Y,Rat>::type
pow(const Y& x)
{
    return power_typeof_helper<Y,Rat>::value(x);
}

/// raise a value to an integer power
template<long N,class Y>
typename power_typeof_helper<Y,static_rational<N> >::type
pow(const Y& x)
{
    return power_typeof_helper<Y,static_rational<N> >::value(x);
}

/// take the @c static_rational root of a value
template<class Rat,class Y>
typename root_typeof_helper<Y,Rat>::type
root(const Y& x)
{
    return root_typeof_helper<Y,Rat>::value(x);
}

/// take the integer root of a value
template<long N,class Y>
typename root_typeof_helper<Y,static_rational<N> >::type
root(const Y& x)
{
    return root_typeof_helper<Y,static_rational<N> >::value(x);
}

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_STATIC_RATIONAL_HPP
