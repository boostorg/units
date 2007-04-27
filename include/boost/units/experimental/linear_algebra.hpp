// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_LINEAR_ALGEBRA_HPP
#define BOOST_UNITS_LINEAR_ALGEBRA_HPP

#include <boost/units/static_rational.hpp>
#include <boost/mpl/list.hpp>
#include <boost/mpl/push_front.hpp>
#include <boost/mpl/pop_front.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/begin.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/next.hpp>
#include <boost/mpl/arithmetic.hpp>
#include <boost/mpl/sort.hpp>
#include <boost/mpl/front_inserter.hpp>
#include <boost/mpl/set.hpp>
#include <boost/mpl/insert.hpp>
#include <boost/mpl/greater.hpp>
#include <boost/mpl/reverse.hpp>
#include <boost/mpl/advance.hpp>
#include <boost/mpl/erase.hpp>

namespace boost {

namespace units {

namespace detail {

template<int N>
struct eliminate_from_pair_of_equations_impl;

template<class E1, class E2>
struct eliminate_from_pair_of_equations;

template<int N>
struct elimination_impl;

template<bool is_zero, bool element_is_last>
struct elimination_skip_leading_zeros_impl;

template<class Equation, class Vars>
struct substitute;

template<int N>
struct substitute_impl;

template<bool is_end>
struct solve_impl;

template<class T>
struct solve;

template<int N>
struct check_extra_equations_impl;

template<int N>
struct solve_linear_equations_impl;

struct inconsistant {};

template<int N>
struct eliminate_from_pair_of_equations_impl {
    template<class Begin1, class Begin2, class X1, class X2>
    struct apply {
        typedef typename mpl::push_front<
            typename eliminate_from_pair_of_equations_impl<N - 1>::template apply<
                typename mpl::next<Begin1>::type,
                typename mpl::next<Begin2>::type,
                X1,
                X2
            >::type,
            typename mpl::minus<
                typename mpl::times<typename mpl::deref<Begin1>::type, X2>::type,
                typename mpl::times<typename mpl::deref<Begin2>::type, X1>::type
            >::type
        >::type type;
    };
};

template<>
struct eliminate_from_pair_of_equations_impl<0> {
    template<class Begin1, class Begin2, class X1, class X2>
    struct apply {
        typedef mpl::list0<> type;
    };
};

template<class E1, class E2>
struct eliminate_from_pair_of_equations {
    typedef typename mpl::begin<E1>::type begin1;
    typedef typename mpl::begin<E2>::type begin2;
    typedef typename eliminate_from_pair_of_equations_impl<mpl::size<E1>::value - 1>::template apply<
        typename mpl::next<begin1>::type,
        typename mpl::next<begin2>::type,
        typename mpl::deref<begin1>::type,
        typename mpl::deref<begin2>::type
    >::type type;
};

template<int N>
struct elimination_impl {
    template<class Begin, class Prev, class L>
    struct apply {
        typedef typename mpl::push_front<
            typename elimination_impl<N-1>::template apply<typename mpl::next<Begin>::type, Prev, L>::type,
            typename eliminate_from_pair_of_equations<typename mpl::deref<Begin>::type,Prev>::type
        >::type type;
    };
};

template<>
struct elimination_impl<0> {
    template<class Begin, class Prev, class L>
    struct apply {
        typedef L type;
    };
};

template<>
struct elimination_skip_leading_zeros_impl<true, true> {
    template<class Begin, int N, class L>
    struct apply {
        typedef inconsistant type;
    };
};

template<>
struct elimination_skip_leading_zeros_impl<true, false> {
    template<class Begin, int N, class L>
    struct apply {
        typedef typename mpl::next<Begin>::type next;
        typedef typename elimination_skip_leading_zeros_impl<
            boost::is_same<
                typename mpl::deref<
                    typename mpl::begin<typename mpl::deref<next>::type>::type
                >::type,
                static_rational<0>
            >::value,
            N == 2
        >::template apply<
            next,
            N-1,
            typename mpl::push_front<
                L,
                typename mpl::pop_front<typename mpl::deref<Begin>::type>::type
            >::type
        >::type type;
    };
};

template<class S>
struct combine_solutions {
    template<class Iterator>
    struct apply {
        typedef typename substitute<typename mpl::deref<Iterator>::type, S>::type x;
        typedef typename mpl::push_front<S, x>::type type;
    };
};

template<>
struct combine_solutions<inconsistant> {
    template<class Iterator>
    struct apply {
        typedef inconsistant type;
    };
};

template<>
struct elimination_skip_leading_zeros_impl<false, true> {
    template<class Begin, int N, class L>
    struct apply {
        typedef typename elimination_impl<N - 1>::template apply<
            typename mpl::next<Begin>::type,
            typename mpl::deref<Begin>::type,
            L
        >::type list_type;
        typedef typename solve<list_type>::type next;
        typedef typename combine_solutions<next>::template apply<Begin>::type type;
    };
};

template<>
struct elimination_skip_leading_zeros_impl<false, false> {
    template<class Begin, int N, class L>
    struct apply {
        typedef typename elimination_impl<N - 1>::template apply<
            typename mpl::next<Begin>::type,
            typename mpl::deref<Begin>::type,
            L
        >::type list_type;
        typedef typename solve<list_type>::type next;
        typedef typename combine_solutions<next>::template apply<Begin>::type type;
    };
};

template<int N>
struct substitute_impl {
    template<class Begin1, class Begin2>
    struct apply {
        typedef typename mpl::minus<
            typename substitute_impl<N-1>::template apply<
                typename mpl::next<Begin1>::type,
                typename mpl::next<Begin2>::type
            >::type,
            typename mpl::times<
                typename mpl::deref<Begin1>::type,
                typename mpl::deref<Begin2>::type
            >::type
        >::type type;
    };
};

template<>
struct substitute_impl<0> {
    template<class Begin1, class Begin2>
    struct apply {
        typedef typename mpl::deref<Begin1>::type type;
    };
};

template<class Equation, class Vars>
struct substitute {
    typedef typename mpl::begin<Equation>::type begin;
    typedef typename mpl::divides<
        typename substitute_impl<mpl::size<Vars>::value>::template apply<
            typename mpl::next<begin>::type,
            typename mpl::begin<Vars>::type
        >::type,
        typename mpl::deref<begin>::type
    >::type type;
};

template<>
struct solve_impl<true> {
    template<class T>
    struct apply {
        typedef mpl::list0<> type;
    };
};

template<class T>
struct check_extra_equations_func {
    template<class Begin, int N>
    struct apply {
        typedef inconsistant type;
    };
};

template<>
struct check_extra_equations_func<static_rational<0> > {
    template<class Begin, int N>
    struct apply {
        typedef typename check_extra_equations_impl<N - 1>::template apply<typename mpl::next<Begin>::type>::type type;
    };
};

template<int N>
struct check_extra_equations_impl {
    template<class Begin>
    struct apply {
        typedef typename check_extra_equations_func<
            typename mpl::deref<typename mpl::begin<typename mpl::deref<Begin>::type>::type>::type
        >::template apply<Begin, N>::type type;
    };
};

template<>
struct check_extra_equations_impl<0> {
    template<class Begin>
    struct apply {
        typedef mpl::list0<> type;
    };
};

template<bool is_end>
struct check_extra_equations;

template<>
struct check_extra_equations<true> {
    template<class T>
    struct apply {
        typedef typename check_extra_equations_impl<mpl::size<T>::value>::template apply<
            typename mpl::begin<T>::type
        >::type type;
    };
};

template<>
struct check_extra_equations<false> {
    template<class T>
    struct apply {
        typedef typename mpl::begin<T>::type begin;
        typedef typename elimination_skip_leading_zeros_impl<
            boost::is_same<
                typename mpl::deref<
                    typename mpl::begin<typename mpl::deref<begin>::type>::type
                >::type,
                static_rational<0>
            >::value,
            mpl::size<T>::value == 1
        >::template apply<
            begin,
            mpl::size<T>::value,
            mpl::list0<>
        >::type type;
    };
};

template<>
struct solve_impl<false> {
    template<class T>
    struct apply {
        typedef typename mpl::begin<T>::type begin;
        typedef typename check_extra_equations<
            mpl::size<typename mpl::deref<begin>::type>::value == 1
        >::template apply<
            T
        >::type type;
    };
};

template<class T>
struct solve {
    typedef typename solve_impl<mpl::size<T>::value == 0>::template apply<T>::type type;
};

template<int N>
struct find_base_dimensions_impl_impl {
    template<class Begin, class S>
    struct apply {
        typedef typename mpl::insert<
            typename find_base_dimensions_impl_impl<N-1>::template apply<
                typename mpl::next<Begin>::type,
                S
            >::type,
            typename mpl::deref<Begin>::type::tag_type
        >::type type;
    };
};

template<>
struct find_base_dimensions_impl_impl<0> {
    template<class Begin, class S>
    struct apply {
        typedef S type;
    };
};

template<int N>
struct find_base_dimensions_impl {
    template<class Begin>
    struct apply {
        typedef typename find_base_dimensions_impl_impl<mpl::size<typename mpl::deref<Begin>::type::dimension_type>::value>::template apply<
            typename mpl::begin<typename mpl::deref<Begin>::type::dimension_type>::type,
            typename find_base_dimensions_impl<N-1>::template apply<typename mpl::next<Begin>::type>::type
        >::type type;
    };
};

template<>
struct find_base_dimensions_impl<0> {
    template<class Begin>
    struct apply {
        typedef mpl::set0<> type;
    };
};

template<class T>
struct find_base_dimensions {
    typedef typename mpl::sort<
        typename find_base_dimensions_impl<
            mpl::size<T>::value
        >::template apply<typename mpl::begin<T>::type>::type,
        mpl::greater<>,
        mpl::front_inserter<mpl::list0<> >
    >::type type;
};

template<bool>
struct calculate_base_dimension_coefficients_func;

template<>
struct calculate_base_dimension_coefficients_func<true> {
    template<class T>
    struct apply {
        typedef typename mpl::deref<T>::type::value_type type;
        typedef typename mpl::next<T>::type next;
    };
};

template<>
struct calculate_base_dimension_coefficients_func<false> {
    template<class T>
    struct apply {
        typedef static_rational<0> type;
        typedef typename T next;
    };
};

template<int N>
struct calculate_base_dimension_coefficients_impl {
    template<class BaseUnitDimensions,class Dim,class T>
    struct apply {
        typedef typename calculate_base_dimension_coefficients_func<
            boost::is_same<
                Dim,
                typename mpl::deref<typename mpl::deref<BaseUnitDimensions>::type>::type::tag_type
            >::value
        >::template apply<
            typename mpl::deref<BaseUnitDimensions>::type
        > result;
        typedef typename calculate_base_dimension_coefficients_impl<N-1>::template apply<
            typename mpl::next<BaseUnitDimensions>::type,
            Dim,
            typename mpl::push_front<T, typename result::type>::type
        > next_;
        typedef typename next_::type type;
        typedef typename mpl::push_front<typename next_::next, typename result::next>::type next;
    };
};

template<>
struct calculate_base_dimension_coefficients_impl<0> {
    template<class Begin, class BaseUnitDimensions, class T>
    struct apply {
        typedef T type;
        typedef mpl::list0<> next;
    };
};

// returns the result in reverse order
template<int N>
struct solve_for_base_dimension_impl {
    template<class Begin, class Units>
    struct apply {
        typedef typename calculate_base_dimension_coefficients_impl<mpl::size<Units>::value>::template apply<
            typename mpl::begin<Units>::type,
            typename mpl::deref<Begin>::type,
            mpl::list0<>
        > x;
        typedef typename mpl::push_front<
            typename solve_for_base_dimension_impl<N-1>::template apply<
                typename mpl::next<Begin>::type,
                typename x::next
            >::type,
            typename x::type
        >::type type;
    };
};

template<>
struct solve_for_base_dimension_impl<0> {
    template<class Begin, class Units>
    struct apply {
        typedef mpl::list0<> type;
    };
};

template<int N>
struct get_dimension_iterators_impl {
    template<class Begin>
    struct apply {
        typedef typename mpl::push_front<
            typename get_dimension_iterators_impl<N-1>::template apply<typename mpl::next<Begin>::type>::type,
            typename mpl::begin<typename mpl::deref<Begin>::type::dimension_type>::type
        >::type type;
    };
};

template<>
struct get_dimension_iterators_impl<0> {
    template<class Begin>
    struct apply {
        typedef mpl::list0<> type;
    };
};

template<int N>
struct prepare_equations_impl {
    template<class Begin, int M>
    struct apply {
        typedef typename mpl::push_front<
            typename prepare_equations_impl<N-1>::template apply<typename mpl::next<Begin>::type, M - 1>::type,
            typename mpl::reverse<typename mpl::push_front<typename mpl::deref<Begin>::type, static_rational<(M == 0 ? 1 : 0)> >::type>::type
        >::type type;
    };
};

template<>
struct prepare_equations_impl<0> {
    template<class Begin, int M>
    struct apply {
        typedef mpl::list0<> type;
    };
};

template<int N>
struct add_zeroes_impl {
    template<class T>
    struct apply {
        typedef typename mpl::push_front<
            typename add_zeroes_impl<N-1>::template apply<T>::type,
            static_rational<0>
        >::type type;
    };
};

template<>
struct add_zeroes_impl<0> {
    template<class T>
    struct apply {
        typedef T type;
    };
};

template<int N>
struct add_solutions_impl {
    template<class Begin, class T, class Solution>
    struct apply {
        typedef typename add_solutions_impl<N-1>::template apply<
            typename mpl::next<Begin>::type,
            typename mpl::push_front<
                T,
                typename substitute_impl<mpl::size<Solution>::value>::template apply<
                    typename mpl::begin<typename mpl::deref<Begin>::type>::type,
                    typename mpl::begin<Solution>::type
                >::type
            >::type
        >::type type;
    };
};

template<>
struct add_solutions_impl<0> {
    template<class Begin, class T, class Solution>
    struct apply {
        typedef T type;
    };
};

template<class S>
struct solve_linear_equations_func {
    template<class ReverseEquations, int M, class DimensionIterator, int N, int Extra, int I,class ExtraEquations>
    struct apply {
        typedef typename add_zeroes_impl<Extra-mpl::size<ExtraEquations>::value>::template apply<S>::type result1;
        typedef typename add_solutions_impl<mpl::size<ExtraEquations>::value>::template apply<
            typename mpl::begin<ExtraEquations>::type,
            result1,
            S
        >::type result;
        typedef typename mpl::push_front<
            typename solve_linear_equations_impl<N-1>::template apply<
                ReverseEquations,
                M+1,
                typename mpl::next<DimensionIterator>::type,
                Extra,
                I+1,
                ExtraEquations
            >::type,
            result
        >::type type;
    };
};

template<>
struct solve_linear_equations_func<inconsistant> {
    template<class ReverseEquations, int M, class DimensionIterator, int N, int Extra, int I, class ExtraEquations>
    struct apply {
        typedef typename typename mpl::advance_c<typename mpl::begin<ReverseEquations>::type, M>::type pos;
        typedef typename solve_linear_equations_impl<N-1>::template apply<
            typename mpl::erase<
                ReverseEquations,
                pos
            >::type,
            M,
            typename mpl::next<DimensionIterator>::type,
            Extra,
            I+1,
            typename mpl::push_front<
                ExtraEquations,
                typename mpl::reverse<
                    typename mpl::push_front<typename mpl::deref<pos>::type, static_rational<0> >::type
                >::type
            >::type
        > next;
        typedef typename mpl::push_front<
            typename add_zeroes_impl<N-1>::template apply<mpl::list0<> >::type,
            static_rational<1>
        >::type result1;
        typedef typename add_zeroes_impl<I>::template apply<result1>::type result;
        typedef typename mpl::push_front<typename next::type, result>::type type;
    };
};

template<int N>
struct solve_linear_equations_impl {
    template<class ReverseEquations, int M, class DimensionIterator, int Extra, int I, class ExtraEquations>
    struct apply {
        typedef typename solve<
            typename prepare_equations_impl<
                mpl::size<ReverseEquations>::value
            >::template apply<
                typename mpl::begin<ReverseEquations>::type,
                M
            >::type
        >::type solution;
        typedef typename solve_linear_equations_func<solution>::template apply<
            ReverseEquations,
            M,
            DimensionIterator,
            N,
            Extra,
            I,
            ExtraEquations
        >::type type;
    };
};

template<>
struct solve_linear_equations_impl<0> {
    template<class ReverseEquations, int M, class DimensionIterator, int Extra, int I, class ExtraEquations>
    struct apply {
        typedef mpl::list0<> type;
    };
};

template<class T>
struct solve_linear_equations {
    typedef typename find_base_dimensions<T>::type dimensions;
    typedef typename get_dimension_iterators_impl<mpl::size<T>::value>::template apply<typename mpl::begin<T>::type>::type iterators;
    typedef typename solve_for_base_dimension_impl<
        mpl::size<dimensions>::value
    >::template apply<
        typename mpl::begin<dimensions>::type,
        iterators
    >::type reverse_equations;
    typedef typename solve_linear_equations_impl<mpl::size<reverse_equations>::value>::template apply<
        reverse_equations,
        0,
        typename mpl::begin<dimensions>::type,
        mpl::size<reverse_equations>::value - mpl::size<T>::value,
        0,
        mpl::list0<>
    >::type type;
};

} // namespace detail

} // namespace units

} // namespace boost

#endif
