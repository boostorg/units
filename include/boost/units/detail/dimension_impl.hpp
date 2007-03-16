// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_DIMENSION_IMPL_HPP
#define BOOST_UNITS_DIMENSION_IMPL_HPP

#include <boost/mpl/begin_end.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/list.hpp>
#include <boost/mpl/next.hpp>
#include <boost/mpl/push_front.hpp>
#include <boost/mpl/size.hpp>

#include <boost/units/static_rational.hpp>

/// \file 
/// \brief Core class and metaprogramming utilities for compile-time dimensional analysis.
///
/// \detailed 

namespace boost {

namespace units {

struct dimensionless_type;

}

}

#if BOOST_UNITS_HAS_BOOST_TYPEOF

#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

BOOST_TYPEOF_REGISTER_TYPE(boost::units::dimensionless_type)

#endif

namespace boost {

namespace units {

namespace detail {

struct dimension_list_tag { };

} // namespace detail

template<class Item, class Next>
struct dimension_list
{
    typedef detail::dimension_list_tag tag;
    typedef dimension_list type;
    typedef Item item;
    typedef Next next;
    typedef typename mpl::next<typename Next::size>::type size;
};

}

}

#if BOOST_UNITS_HAS_BOOST_TYPEOF

#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

BOOST_TYPEOF_REGISTER_TEMPLATE(boost::units::dimension_list, 2)

#endif

namespace boost {

namespace units {

namespace detail {

template<bool remove>
struct strip_zero_dims_func;

template<>
struct strip_zero_dims_func<true>
{
    template<typename Sequence, typename T>
    struct apply
    {
        typedef Sequence type;
    };
};

template<>
struct strip_zero_dims_func<false>
{
    template<typename Sequence, typename T>
    struct apply
    {
        typedef typename mpl::push_front<Sequence, T>::type type;
    };
};

template<int N>
struct strip_zero_dims_impl
{
    template<typename Begin>
    struct apply {
        typedef typename strip_zero_dims_func<
            boost::is_same<typename boost::mpl::deref<Begin>::type::tag_type, static_rational<0> >::value
        >::template apply<
            typename strip_zero_dims_impl<N-1>::template apply<
                typename boost::mpl::next<Begin>::type
            >::type,
            typename boost::mpl::deref<Begin>::type
        >::type type;
    };
};

/// remove all dimensionless dimensions
template<typename Seq>
struct strip_zero_dims
{
    typedef typename strip_zero_dims_impl<mpl::size<Seq>::value>::template apply<typename mpl::begin<Seq>::type>::type    type;
};

/// a more efficient type sequence than @c mpl::list
struct sort_dims_list_end
{
    enum { size = 0 };
};

template<typename T, typename Next = sort_dims_list_end>
struct sort_dims_list
{
    typedef T item;
    typedef Next next;
    enum { size = Next::size + 1 };
};

/// add an instantiation of dim to Sequence.
template<bool>
struct sort_dims_insert_impl;

template<>
struct sort_dims_insert_impl<true>
{
    template<typename Sequence, typename T>
    struct apply
    {
        typedef sort_dims_list<
            typename static_add<T, typename Sequence::item>::type,
            typename Sequence::next
        > type;
    };
};

template<>
struct sort_dims_insert_impl<false>
{
    template<typename Sequence, typename T>
    struct apply
    {
        typedef typename boost::mpl::if_<boost::is_same<typename Sequence::item::value_type, static_rational<0> >,
            typename Sequence::next,
            Sequence
        >::type type1;
        typedef sort_dims_list<T, type1> type;
    };
};

template<typename Sequence, typename T>
struct sort_dims_insert
{
    typedef typename sort_dims_insert_impl<boost::is_same<typename T::tag_type, typename Sequence::item::tag_type>::value>::template apply<
        Sequence,
        T
    >::type type;
};

template<typename T>
struct sort_dims_insert<sort_dims_list_end, T>
{
    typedef sort_dims_list<T> type;
};

/// a pair of output sequences
template<typename Out1, typename Out2>
struct partition_dims_state
{
    typedef Out1 out1;
    typedef Out2 out2;
};

/// determine which sequence to insert in
template<bool insert_in_first>
struct partition_dims_state_insert;

template<>
struct partition_dims_state_insert<true>
{
    template<typename State, typename T>
    struct apply
    {
        typedef partition_dims_state<sort_dims_list<T, typename State::out1>, typename State::out2> type;
    };
};

template<>
struct partition_dims_state_insert<false>
{
    template<typename State, typename T>
    struct apply
    {
        typedef partition_dims_state<typename State::out1, sort_dims_list<T, typename State::out2> > type;
    };
};

/// quicksort uses recusive partitioning
template<int N>
struct partition_dims_forward_impl
{
    template<typename Begin, typename State, typename Value>
    struct apply
    {
        typedef typename partition_dims_forward_impl<N - 1>::template apply<
            typename Begin::next,
            typename partition_dims_state_insert<less<typename Begin::item, Value>::type::value>::template apply<State, typename Begin::item>::type,
            Value
        >::type type;
    };
};

/// terminate the recursion
template<>
struct partition_dims_forward_impl<0>
{
    template<typename Begin, typename State, typename Value>
    struct apply
    {
        typedef State type;
    };
};

template<typename Sequence, typename Output>
struct sort_dims_forward;

/// primary template for the implementation of sort
template<int N>
struct sort_dims_forward_impl
{
    template<typename Begin, typename Output>
    struct apply
    {
        typedef typename 
            partition_dims_forward_impl<N - 1>::template apply<
                typename Begin::next,
                partition_dims_state<sort_dims_list_end, sort_dims_list_end>,
                typename Begin::item
            >::type partitioned;
        //we're using push_front so we have to push the elements in reverse order
        typedef typename sort_dims_forward<typename partitioned::out2, Output>::type step1;
        typedef typename sort_dims_insert<step1, typename Begin::item>::type step2;
        typedef typename sort_dims_forward<typename partitioned::out1, step2>::type type;
    };
};

/// sorting a zero element sequence returns a zero element sequence
template<>
struct sort_dims_forward_impl<0>
{
    template<typename Begin, typename Output>
    struct apply
    {
        typedef Output type;
    };
};

/// a single element sequence is trivial too
template<>
struct sort_dims_forward_impl<1>
{
    template<typename Begin, typename Output>
    struct apply
    {
        typedef typename sort_dims_insert<Output, typename Begin::item>::type type;
    };
};

/// basic quicksort (@c mpl::sort is horribly inefficient)
template<typename Sequence, typename Output>
struct sort_dims_forward
{
    typedef typename sort_dims_forward_impl<Sequence::size>::template apply<
        Sequence,
        Output
    >::type type;
};

/// convert an mpl sequence to a @c sort_dims_list removing @c dimensionless_type in the process
template<int N>
struct remove_dimensionless
{
    template<typename Begin, typename Out>
    struct apply
    {
        typedef typename boost::mpl::deref<Begin>::type deref;
        typedef typename boost::mpl::if_<boost::is_same<typename deref::tag_type, dimensionless_type>,
            Out,
            sort_dims_list<deref, Out>
        >::type type1;
        typedef typename remove_dimensionless<N - 1>::template 
            apply<typename boost::mpl::next<Begin>::type, type1>::type type;
    };
};

/// terminate the recursion
template<>
struct remove_dimensionless<0>
{
    template<typename Begin, typename Out>
    struct apply
    {
        typedef Out type;
    };
};

/// when we're finished with the computation we have to get back an @c mpl::list
template<typename Sequence>
struct sort_dims_to_mpl_list
{
    typedef typename boost::mpl::push_front<typename sort_dims_to_mpl_list<typename Sequence::next>::type, 
                                            typename Sequence::item>::type type;
};

template<>
struct sort_dims_to_mpl_list<sort_dims_list_end>
{
    typedef dimensionless_type type;
};

/// sorted sequences can be merged in linear time
template<bool less, bool greater>
struct merge_dimensions_func;

template<int N1, int N2>
struct merge_dimensions_impl;

template<>
struct merge_dimensions_func<true, false>
{
    template<typename Begin1, typename Begin2, int N1, int N2>
    struct apply
    {
        typedef typename mpl::push_front<
            typename merge_dimensions_impl<N1 - 1, N2>::template apply<
                typename boost::mpl::next<Begin1>::type,
                Begin2
            >::type,
            typename boost::mpl::deref<Begin1>::type
        >::type type;
    };
};

template<>
struct merge_dimensions_func<false, true> {
    template<typename Begin1, typename Begin2, int N1, int N2>
    struct apply
    {
        typedef typename mpl::push_front<
            typename merge_dimensions_impl<N2 - 1, N1>::template apply<
                typename boost::mpl::next<Begin2>::type,
                Begin1
            >::type,
            typename boost::mpl::deref<Begin2>::type
        >::type type;
    };
};

template<bool>
struct push_front_if;

template<>
struct push_front_if<true>
{
    template<typename Seq, typename T>
    struct apply
    {
        typedef typename mpl::push_front<Seq, T>::type type;
    };
};

template<>
struct push_front_if<false>
{
    template<typename Seq, typename T>
    struct apply
    {
        typedef Seq type;
    };
};

template<>
struct merge_dimensions_func<false, false> {
    template<typename Begin1, typename Begin2, int N1, int N2>
    struct apply
    {
        typedef typename static_add<typename boost::mpl::deref<Begin1>::type, typename boost::mpl::deref<Begin2>::type>::type combined;
        typedef typename push_front_if<!is_empty_dim<combined>::value>::template apply<
            typename merge_dimensions_impl<N1 - 1, N2 - 1>::template apply<
                typename boost::mpl::next<Begin1>::type,
                typename boost::mpl::next<Begin2>::type
            >::type,
            combined
        >::type type;
    };
};

template<int N1, int N2>
struct merge_dimensions_impl {
    template<typename Begin1, typename Begin2>
    struct apply
    {
        typedef typename boost::mpl::deref<Begin1>::type dim1;
        typedef typename boost::mpl::deref<Begin2>::type dim2;

        typedef typename merge_dimensions_func<(less<dim1,dim2>::value == true),
                (less<dim2,dim1>::value == true)>::template apply<
            Begin1,
            Begin2,
            N1,
            N2
        >::type type;
    };
};

template<typename Sequence1, typename Sequence2>
struct merge_dimensions
{
    typedef typename detail::merge_dimensions_impl<boost::mpl::size<Sequence1>::value, 
                                                   boost::mpl::size<Sequence2>::value>::template 
        apply<
            typename boost::mpl::begin<Sequence1>::type,
            typename boost::mpl::begin<Sequence2>::type
        >::type type;
};

template<int N>
struct iterator_to_list
{
    template<typename Begin>
    struct apply
    {
        typedef typename mpl::push_front<
            typename iterator_to_list<N - 1>::template apply<
                typename boost::mpl::next<Begin>::type
            >::type,
            typename boost::mpl::deref<Begin>::type
        >::type type;
    };
};

template<>
struct iterator_to_list<0>
{
    template<typename Begin>
    struct apply {
        typedef dimensionless_type type;
    };
};

template<int N>
struct merge_dimensions_impl<N, 0>
{
    template<typename Begin1, typename Begin2>
    struct apply
    {
        typedef typename iterator_to_list<N>::template apply<Begin1>::type type;
    };
};

template<int N>
struct merge_dimensions_impl<0, N>
{
    template<typename Begin1, typename Begin2>
    struct apply
    {
        typedef typename iterator_to_list<N>::template apply<Begin2>::type type;
    };
};

template<>
struct merge_dimensions_impl<0, 0>
{
    template<typename Begin1, typename Begin2>
    struct apply
    {
        typedef dimensionless_type type;
    };
};

template<int N>
struct static_inverse_impl
{
    template<typename Begin>
    struct apply {
        typedef typename boost::mpl::push_front<
            typename static_inverse_impl<N - 1>::template apply<
                typename boost::mpl::next<Begin>::type
            >::type,
            typename static_negate<typename boost::mpl::deref<Begin>::type>::type
        >::type type;
    };
};

template<>
struct static_inverse_impl<0>
{
    template<typename Begin>
    struct apply
    {
        typedef dimensionless_type type;
    };
};

template<int N>
struct static_power_impl
{
    template<typename Begin, typename Ex>
    struct apply
    {
        typedef typename mpl::push_front<
            typename detail::static_power_impl<N - 1>::template apply<typename mpl::next<Begin>::type, Ex>::type,
            typename static_multiply<typename mpl::deref<Begin>::type, Ex>::type
        >::type type;
    };
};

template<>
struct static_power_impl<0>
{
    template<typename Begin, typename Ex>
    struct apply
    {
        typedef dimensionless_type type;
    };
};

template<int N>
struct static_root_impl {
    template<class Begin, class Ex>
    struct apply {
        typedef typename mpl::push_front<
            typename detail::static_root_impl<N - 1>::template apply<typename mpl::next<Begin>::type, Ex>::type,
            typename static_divide<typename mpl::deref<Begin>::type, Ex>::type
        >::type type;
    };
};

template<>
struct static_root_impl<0> {
    template<class Begin, class Ex>
    struct apply 
    {
        typedef dimensionless_type type;
    };
};

} // namespace detail

} // namespace units

namespace mpl {

template<>
struct size_impl<units::detail::dimension_list_tag>
{
    template<class L> struct apply : public L::size { };
};

template<>
struct begin_impl<units::detail::dimension_list_tag>
{
    template<class L>
    struct apply 
    {
        typedef L type;
    };
};

template<>
struct end_impl<units::detail::dimension_list_tag>
{
    template<class L>
    struct apply 
    {
        typedef units::dimensionless_type type;
    };
};

template<>
struct push_front_impl<units::detail::dimension_list_tag>
{
    template<class L, class T>
    struct apply 
    {
        typedef units::dimension_list<T, L> type;
    };
};

template<>
struct pop_front_impl<units::detail::dimension_list_tag>
{
    template<class L>
    struct apply 
    {
        typedef typename L::next type;
    };
};

template<>
struct front_impl<units::detail::dimension_list_tag>
{
    template<class L>
    struct apply 
    {
        typedef typename L::item type;
    };
};

template<class Item, class Next>
struct deref<units::dimension_list<Item, Next> >
{
    typedef Item type;
};

template<> struct deref<units::dimensionless_type> { };

} // namespace mpl

} // namespace boost

#endif // BOOST_UNITS_DIMENSION_IMPL_HPP
