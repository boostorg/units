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

#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>

#include <boost/units/config.hpp>

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

#if BOOST_UNITS_HAS_TYPEOF

// to avoid need for default constructor and eliminate divide by zero errors
namespace typeof_ {

/// INTERNAL ONLY
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

#elif (BOOST_UNITS_HAS_GNU_TYPEOF) || defined(BOOST_UNITS_DOXYGEN)

template<typename X> struct unary_plus_typeof_helper            { typedef typeof((+typeof_::make<X>())) type; };
template<typename X> struct unary_minus_typeof_helper           { typedef typeof((-typeof_::make<X>())) type; };

template<typename X,typename Y> struct add_typeof_helper        { typedef typeof((typeof_::make<X>()+typeof_::make<Y>())) type; };
template<typename X,typename Y> struct subtract_typeof_helper   { typedef typeof((typeof_::make<X>()-typeof_::make<Y>())) type; };
template<typename X,typename Y> struct multiply_typeof_helper   { typedef typeof((typeof_::make<X>()*typeof_::make<Y>())) type; };
template<typename X,typename Y> struct divide_typeof_helper     { typedef typeof((typeof_::make<X>()/typeof_::make<Y>())) type; };

#endif

#else // BOOST_UNITS_HAS_TYPEOF

template<typename X> struct unary_plus_typeof_helper            { typedef X type; };
template<typename X> struct unary_minus_typeof_helper           { typedef X type; };

template<typename X,typename Y> struct add_typeof_helper        { BOOST_STATIC_ASSERT((is_same<X,Y>::value == true)); typedef X type; };
template<typename X,typename Y> struct subtract_typeof_helper   { BOOST_STATIC_ASSERT((is_same<X,Y>::value == true)); typedef X type; };
template<typename X,typename Y> struct multiply_typeof_helper   { BOOST_STATIC_ASSERT((is_same<X,Y>::value == true)); typedef X type; };
template<typename X,typename Y> struct divide_typeof_helper     { BOOST_STATIC_ASSERT((is_same<X,Y>::value == true)); typedef X type; };

#endif // BOOST_UNITS_HAS_TYPEOF

template<typename X,typename Y> struct power_dimof_helper;
template<typename X,typename Y> struct root_typeof_helper;

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_OPERATORS_HPP
