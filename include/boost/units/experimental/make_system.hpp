// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_MAKE_SYSTEM_HPP_INCLUDED
#define BOOST_UNITS_MAKE_SYSTEM_HPP_INCLUDED

#include <boost/mpl/list/list10.hpp>

#include <boost/units/config.hpp>
#include <boost/units/experimental/sort.hpp>

#ifdef BOOST_UNITS_CHECK_HOMOGENEOUS_UNITS

#include <boost/is_same.hpp>
#include <boost/mpl/not.hpp>

#include <boost/units/experimental/linear_algebra.hpp>

#endif

namespace boost {

namespace units {

template<class L>
struct homogeneous_system {
    typedef L type;
};

template<class L, long N, long D>
struct static_power<homogeneous_system<L>, static_rational<N,D> > {
    typedef homogeneous_system<L> type;
};

template<class L, long N, long D>
struct static_root<homogeneous_system<L>, static_rational<N,D> > {
    typedef homogeneous_system<L> type;
};

namespace detail {

template<class System, class Dimensions>
struct check_system;

#ifdef BOOST_UNITS_CHECK_HOMOGENEOUS_UNITS

template<class L, class Dimensions>
struct check_system<homogeneous_system<L>, Dimensions> :
    boost::mpl::not_<
        boost::is_same<
            typename calculate_base_unit_exponents<
                L,
                Dimensions
            >::type,
            inconsistant
        >
    > {};

#else

template<class L, class Dimensions>
struct check_system<homogeneous_system<L>, Dimensions> : mpl::true_ {
};

#endif

}

struct na {};

template<
    class U0 = na,
    class U1 = na,
    class U2 = na,
    class U3 = na,
    class U4 = na,
    class U5 = na,
    class U6 = na,
    class U7 = na,
    class U8 = na,
    class U9 = na
>
struct make_system;

template<>
struct make_system<> {
    typedef homogeneous_system<mpl::list0<> > type;
};

template<class T0>
struct make_system<T0> {
    typedef homogeneous_system<typename detail::bubble_sort<mpl::list1<T0> >::type> type;
};

template<class T0, class T1>
struct make_system<T0, T1> {
    typedef homogeneous_system<typename detail::bubble_sort<mpl::list2<T0, T1> >::type> type;
};

template<class T0, class T1, class T2>
struct make_system<T0, T1, T2> {
    typedef homogeneous_system<typename detail::bubble_sort<mpl::list3<T0, T1, T2> >::type> type;
};

template<class T0, class T1, class T2, class T3>
struct make_system<T0, T1, T2, T3> {
    typedef homogeneous_system<typename detail::bubble_sort<mpl::list4<T0, T1, T2, T3> >::type> type;
};

template<class T0, class T1, class T2, class T3, class T4>
struct make_system<T0, T1, T2, T3, T4> {
    typedef homogeneous_system<typename detail::bubble_sort<mpl::list5<T0, T1, T2, T3, T4> >::type> type;
};

template<class T0, class T1, class T2, class T3, class T4, class T5>
struct make_system<T0, T1, T2, T3, T4, T5> {
    typedef homogeneous_system<typename detail::bubble_sort<mpl::list6<T0, T1, T2, T3, T4, T5> >::type> type;
};

template<class T0, class T1, class T2, class T3, class T4, class T5, class T6>
struct make_system<T0, T1, T2, T3, T4, T5, T6> {
    typedef homogeneous_system<typename detail::bubble_sort<mpl::list7<T0, T1, T2, T3, T4, T5, T6> >::type> type;
};

template<class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7>
struct make_system<T0, T1, T2, T3, T4, T5, T6, T7> {
    typedef homogeneous_system<typename detail::bubble_sort<mpl::list8<T0, T1, T2, T3, T4, T5, T6, T7> >::type> type;
};

template<class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8>
struct make_system<T0, T1, T2, T3, T4, T5, T6, T7, T8> {
    typedef homogeneous_system<typename detail::bubble_sort<mpl::list9<T0, T1, T2, T3, T4, T5, T6, T7, T8> >::type> type;
};

template<class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9>
struct make_system {
    typedef homogeneous_system<typename detail::bubble_sort<mpl::list10<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9> >::type> type;
};

} // namespace units

} // namespace boost

#if BOOST_UNITS_HAS_BOOST_TYPEOF

#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

BOOST_TYPEOF_REGISTER_TEMPLATE(boost::units::homogeneous_system, (class))

#endif

#endif
