// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_OPERATORS_HPP 
#define BOOST_UNITS_OPERATORS_HPP

#include <cmath>
#include <complex>

#include <boost/static_assert.hpp>
#include <boost/version.hpp>
#include <boost/type_traits/is_same.hpp>

#if (BOOST_VERSION >= 103400)
    #define BOOST_UNITS_HAS_BOOST_TYPEOF    1
#else
    #define BOOST_UNITS_HAS_BOOST_TYPEOF    0
#endif

// uncomment this to test without Boost Typeof
//#undef BOOST_UNITS_HAS_BOOST_TYPEOF
//#define BOOST_UNITS_HAS_BOOST_TYPEOF      0   

#if (BOOST_UNITS_HAS_BOOST_TYPEOF)
    #include <boost/typeof/typeof.hpp>   
    #include <boost/typeof/std/complex.hpp>   
    #define BOOST_UNITS_HAS_TYPEOF          1
#else    
    #if (__GNUC__ && __cplusplus && __GNUC__ >= 3)
        #define BOOST_UNITS_HAS_TYPEOF          1
        #define BOOST_UNITS_HAS_GNU_TYPEOF      1
    #elif defined(__MWERKS__)
        #define BOOST_UNITS_HAS_TYPEOF          1
        #define BOOST_UNITS_HAS_MWERKS_TYPEOF   1
    #else
        #define BOOST_UNITS_HAS_TYPEOF          0
    #endif
#endif

// uncomment this to test without typeof support at all
//#undef BOOST_UNITS_HAS_TYPEOF
//#define BOOST_UNITS_HAS_TYPEOF          0

/// \file 
/// \brief Compile time operators and typeof helper classes.
///
/// \detailed 
/// These operators declare the compile-time operators needed to support dimensional
/// analysis algebra. Specializations must be defined for all desired operand types. 
/// Typeof helper classes define result type for heterogeneous operators on value types. 
/// These must be defined through specialization for powers and roots.

namespace boost {

namespace units { 

/// Compile time negate.
template<typename R> struct static_negate;

/// Compile time add.
template<typename R1,typename R2> struct static_add;

/// Compile time subtract.
template<typename R1,typename R2> struct static_subtract;

/// Compile time multiply.
template<typename R1,typename R2> struct static_multiply;

/// Compile time divide.
template<typename R1,typename R2> struct static_divide;

/// Compile time power.
template<typename R1,typename R2> struct static_power;

/// Compile time root.
template<typename R1,typename R2> struct static_root;

#if BOOST_UNITS_HAS_TYPEOF

// to avoid need for default constructor and eliminate divide by zero errors
namespace typeof_ {

template<class T> T make();

} // namespace typeof_

#if (BOOST_UNITS_HAS_BOOST_TYPEOF)

template<typename X> struct unary_plus_typeof_helper            
{
    BOOST_TYPEOF_NESTED_TYPEDEF_TPL(nested, (+typeof_::make<X>()))
    typedef typename nested::type type;
};

template<typename X> struct unary_minus_typeof_helper           
{
    BOOST_TYPEOF_NESTED_TYPEDEF_TPL(nested, (-typeof_::make<X>()))
    typedef typename nested::type type;
};

template<typename X,typename Y> struct add_typeof_helper        
{
    BOOST_TYPEOF_NESTED_TYPEDEF_TPL(nested, (typeof_::make<X>()+typeof_::make<Y>()))
    typedef typename nested::type type;
};

template<typename X,typename Y> struct subtract_typeof_helper   
{
    BOOST_TYPEOF_NESTED_TYPEDEF_TPL(nested, (typeof_::make<X>()-typeof_::make<Y>()))
    typedef typename nested::type type;
};

template<typename X,typename Y> struct multiply_typeof_helper   
{
    BOOST_TYPEOF_NESTED_TYPEDEF_TPL(nested, (typeof_::make<X>()*typeof_::make<Y>()))
    typedef typename nested::type type;
};

template<typename X,typename Y> struct divide_typeof_helper     
{
    BOOST_TYPEOF_NESTED_TYPEDEF_TPL(nested, (typeof_::make<X>()/typeof_::make<Y>()))
    typedef typename nested::type type;
};

#elif (BOOST_UNITS_HAS_MWERKS_TYPEOF)

template<typename X> struct unary_plus_typeof_helper            { typedef __typeof__((+typeof_::make<X>())) type; };
template<typename X> struct unary_minus_typeof_helper           { typedef __typeof__((-typeof_::make<X>())) type; };

template<typename X,typename Y> struct add_typeof_helper        { typedef __typeof__((typeof_::make<X>()+typeof_::make<Y>())) type; };
template<typename X,typename Y> struct subtract_typeof_helper   { typedef __typeof__((typeof_::make<X>()-typeof_::make<Y>())) type; };
template<typename X,typename Y> struct multiply_typeof_helper   { typedef __typeof__((typeof_::make<X>()*typeof_::make<Y>())) type; };
template<typename X,typename Y> struct divide_typeof_helper     { typedef __typeof__((typeof_::make<X>()/typeof_::make<Y>())) type; };

#elif (BOOST_UNITS_HAS_GNU_TYPEOF)

template<typename X> struct unary_plus_typeof_helper            { typedef typeof((+typeof_::make<X>())) type; };
template<typename X> struct unary_minus_typeof_helper           { typedef typeof((-typeof_::make<X>())) type; };

template<typename X,typename Y> struct add_typeof_helper        { typedef typeof((typeof_::make<X>()+typeof_::make<Y>())) type; };
template<typename X,typename Y> struct subtract_typeof_helper   { typedef typeof((typeof_::make<X>()-typeof_::make<Y>())) type; };
template<typename X,typename Y> struct multiply_typeof_helper   { typedef typeof((typeof_::make<X>()*typeof_::make<Y>())) type; };
template<typename X,typename Y> struct divide_typeof_helper     { typedef typeof((typeof_::make<X>()/typeof_::make<Y>())) type; };

#endif

//template<typename X> struct unary_plus_typeof_helper            { typedef typeof(+X()) type; };
//template<typename X> struct unary_minus_typeof_helper           { typedef typeof(-X()) type; };
//
//template<typename X,typename Y> struct add_typeof_helper        { typedef typeof(X()+Y()) type; };
//template<typename X,typename Y> struct subtract_typeof_helper   { typedef typeof(X()-Y()) type; };
//template<typename X,typename Y> struct multiply_typeof_helper   { typedef typeof(X()*Y()) type; };
//template<typename X,typename Y> struct divide_typeof_helper     { typedef typeof(X()/Y()) type; };

#else // BOOST_UNITS_HAS_TYPEOF

template<typename X> struct unary_plus_typeof_helper            { typedef X type; };
template<typename X> struct unary_minus_typeof_helper           { typedef X type; };

template<typename X,typename Y> struct add_typeof_helper        { BOOST_STATIC_ASSERT((is_same<X,Y>::value == true)); typedef X type; };
template<typename X,typename Y> struct subtract_typeof_helper   { BOOST_STATIC_ASSERT((is_same<X,Y>::value == true)); typedef X type; };
template<typename X,typename Y> struct multiply_typeof_helper   { BOOST_STATIC_ASSERT((is_same<X,Y>::value == true)); typedef X type; };
template<typename X,typename Y> struct divide_typeof_helper     { BOOST_STATIC_ASSERT((is_same<X,Y>::value == true)); typedef X type; };

#endif // BOOST_UNITS_HAS_TYPEOF

template<typename X,typename Y> struct power_typeof_helper;
template<typename X,typename Y> struct root_typeof_helper;

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_OPERATORS_HPP
