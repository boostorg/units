// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_DIM_IMPL_HPP
#define BOOST_UNITS_DIM_IMPL_HPP

#include <boost/mpl/bool_fwd.hpp>
#include <boost/mpl/less.hpp>

#include <boost/units/units_fwd.hpp>

/// \file 
/// \brief Class encapsulating a dimension tag/value pair

//namespace boost {
//
//namespace units {
//
//namespace detail {
//
//struct dim_tag { };
//
//} // namespace detail
//
///// \brief Dimension tag/exponent pair for a single fundamental dimension.
/////
///// \detailed 
///// The dim class represents a single dimension tag/dimension exponent pair.
///// That is, @c dim<tag_type,value_type> is a pair where @c tag_type represents the
///// fundamental dimension being represented and @c value_type represents the 
///// exponent of that fundamental dimension as a @c static_rational or other type 
///// providing the required compile-time arithmetic operations. @c tag_type must 
///// provide an ordinal value to allow sorting of lists of dims at compile-time.
///// This can be easily accomplished by inheriting from @c ordinal<N>. Otherwise,
///// @c tag_type may be any type. 
//template<typename T,typename V> 
//struct dim
//{
//    typedef dim             type;
//    typedef detail::dim_tag tag;
//    typedef T               tag_type;
//    typedef V               value_type;
//};
//
//} // namespace units
//
//} // namespace boost
//
//#if BOOST_UNITS_HAS_BOOST_TYPEOF
//
//#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()
//
//BOOST_TYPEOF_REGISTER_TEMPLATE(boost::units::dim, 2)
//
//#endif

namespace boost {

namespace units {

namespace detail {

/// Less than comparison for sorting @c dim.
template<typename T,typename V> struct less;

template<typename T1,typename V1,typename T2,typename V2>
struct less< dim<T1,V1>,dim<T2,V2> >
{
    typedef typename boost::mpl::less<typename T1::value,typename T2::value>::type  type;
    
    static const bool   value = boost::is_same<type,boost::mpl::true_>::value;
};

/// Extract @c tag_type from a @c dim.
template<typename T>
struct get_tag
{
    typedef typename T::tag_type    type;
};

/// Extract @c value_type from a @c dim.
template<typename T>
struct get_value
{
    typedef typename T::value_type    type;
};

/// Determine if a @c dim is empty (has a zero exponent).
template<class T>
struct is_empty_dim;

template<typename T>
struct is_empty_dim< dim<T, static_rational<0> > > :
    mpl::true_ 
{ };

template<typename T, typename V>
struct is_empty_dim< dim<T, V> > :
    mpl::false_ 
{ };

} // namespace detail

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_DIM_IMPL_HPP
