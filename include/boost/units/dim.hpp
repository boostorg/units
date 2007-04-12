// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_DIM_HPP
#define BOOST_UNITS_DIM_HPP

#include <boost/mpl/bool_fwd.hpp>
#include <boost/mpl/int.hpp>

#include <boost/units/static_rational.hpp>
#include <boost/units/detail/dim_impl.hpp>

/// \file 
/// \brief Handling of fundamental dimension/exponent pairs.

namespace boost {

namespace units {

/// Class for defining a cardinal ordering of tags to faciliate compile-time sorting.
template<long N> struct ordinal { typedef typename boost::mpl::int_<N> value; };

}

}

#if BOOST_UNITS_HAS_BOOST_TYPEOF

#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

BOOST_TYPEOF_REGISTER_TEMPLATE(boost::units::ordinal, (long))

#endif

namespace boost {

namespace units {

/// Check that a type is a valid @c dim.
template<typename T> 
struct is_dim :
    public mpl::false_
{ };

template<typename T,typename V>
struct is_dim< dim<T,V> > :
    public mpl::true_
{ };

///// \brief Negate a @c dim.
/////
///// \detailed @c static_negate operation delegates to @c value_type.
//template<typename T,typename V>
//struct static_negate< dim<T,V> >
//{
//    typedef dim<T,typename static_negate<V>::type>    type;
//};
//
///// \brief Add two dims.
/////
///// \detailed 
///// @c static_add operations on dim are only defined between dims having identical
///// @c tag_type. Operation delegates to @c value_type.
//template<typename T,typename V1,typename V2>
//struct static_add< dim<T,V1>,dim<T,V2> >
//{
//    typedef dim<T,typename static_add<V1,V2>::type>    type;
//};
//
///// \brief Subtract two dims.
/////
///// \detailed 
///// @c static_subtract operations on dim are only defined between dims having identical
///// @c tag_type. Operation delegates to @c value_type.
//template<typename T,typename V1,typename V2>
//struct static_subtract< dim<T,V1>,dim<T,V2> >
//{
//    typedef dim<T,typename static_subtract<V1,V2>::type>    type;
//};
//
///// \brief Multiply a @c dim and a @c value_type.
/////
///// \detailed 
///// @c static_multiply operations on @c dim are only defined between @c dim and 
///// @c value_type or @c value_type and @c dim. Operation delegates to @c value_type.
//template<typename T,typename V,typename X>
//struct static_multiply< dim<T,V>,X >
//{
//    typedef dim<T,typename static_multiply<V,X>::type>    type;
//};
//
///// \brief Multipy a @c value_type and a @c dim.
/////
///// \detailed 
///// @c static_multiply operations on @c dim are only defined between @c dim and 
///// @c value_type or @c value_type and @c dim. Operation delegates to @c value_type.
//template<typename T,typename V,typename X>
//struct static_multiply< X,dim<T,V> >
//{
//    typedef dim<T,typename static_multiply<X,V>::type>    type;
//};
//
///// \brief Divide a @c dim by a @c value_type.
/////
///// \detailed 
///// @c static_divide operations on dim are only defined between @c dim and @c value_type or 
///// @c value_type and @c dim. Operation delegates to @c value_type.
//template<typename T,typename V,typename X>
//struct static_divide< dim<T,V>,X >
//{
//    typedef dim<T,typename static_divide<V,X>::type>    type;
//};
//
///// \brief Divide a @c value_type by a @c dim.
/////
///// \detailed 
///// @c static_divide operations on dim are only defined between @c dim and @c value_type or 
///// @c value_type and @c dim. Operation delegates to @c value_type, negating to account 
///// for the resulting inverse unit tag.
//template<typename T,typename V,typename X>
//struct static_divide< X,dim<T,V> >
//{
//    typedef dim<T,typename static_negate<typename static_divide<X,V>::type>::type>    type;
//};

} // namespace units

namespace mpl {

template<>
struct plus_impl<boost::units::detail::dim_tag,boost::units::detail::dim_tag>
{
    template<class T0, class T1>
    struct apply
    {
        BOOST_STATIC_ASSERT((boost::is_same<typename T0::tag_type,typename T1::tag_type>::value == true));
        typedef boost::units::dim<typename T0::tag_type, typename mpl::plus<typename T0::value_type, typename T1::value_type>::type> type;
    };
};

template<>
struct minus_impl<boost::units::detail::dim_tag,boost::units::detail::dim_tag>
{
    template<class T0, class T1>
    struct apply
    {
        BOOST_STATIC_ASSERT((boost::is_same<typename T0::tag_type,typename T1::tag_type>::value == true));
        typedef boost::units::dim<typename T0::tag_type, typename mpl::minus<typename T0::value_type, typename T1::value_type>::type> type;
    };
};

template<>
struct times_impl<boost::units::detail::dim_tag,boost::units::detail::static_rational_tag>
{
    template<class T0, class T1>
    struct apply
    {
        typedef boost::units::dim<typename T0::tag_type, typename mpl::times<typename T0::value_type, T1>::type> type;
    };
};

template<>
struct times_impl<boost::units::detail::static_rational_tag,boost::units::detail::dim_tag>
{
    template<class T0, class T1>
    struct apply
    {
        typedef boost::units::dim<typename T1::tag_type, typename mpl::times<T0, typename T1::value_type>::type> type;
    };
};

template<>
struct divides_impl<boost::units::detail::dim_tag,boost::units::detail::static_rational_tag>
{
    template<class T0, class T1>
    struct apply
    {
        typedef boost::units::dim<typename T0::tag_type, typename mpl::divides<typename T0::value_type, T1>::type> type;
    };
};

template<>
struct divides_impl<boost::units::detail::static_rational_tag,boost::units::detail::dim_tag>
{
    template<class T0, class T1>
    struct apply
    {
        typedef boost::units::dim<typename T1::tag_type, typename mpl::divides<T0, typename T1::value_type>::type> type;
    };
};

template<>
struct negate_impl<boost::units::detail::dim_tag>
{
    template<class T0>
    struct apply
    {
        typedef boost::units::dim<typename T0::tag_type,typename mpl::negate<typename T0::value_type>::type> type;
    };
};

} // namespace mpl

} // namespace boost

#endif // BOOST_UNITS_DIM_HPP
