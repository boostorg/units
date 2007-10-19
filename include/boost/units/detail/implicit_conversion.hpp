/// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_IMPLICIT_CONVERSION_HPP
#define BOOST_UNITS_IMPLICIT_CONVERSION_HPP

#include <boost/mpl/begin.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/next.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/bool.hpp>

#include <boost/units/operators.hpp>
#include <boost/units/heterogeneous_system.hpp>
#include <boost/units/units_fwd.hpp>

namespace boost {

namespace units {

namespace detail {

template<int N>
struct implicit_conversion_impl;

template<class From, class To>
struct base_unit_is_implicitly_convertible : mpl::false_ {};

template<class From>
struct base_unit_is_implicitly_convertible<From, BOOST_UNITS_MAKE_HETEROGENEOUS_UNIT(From, typename From::dimension_type)> : mpl::true_ {};

template<bool condition>
struct implicit_conversion_func;

template<>
struct implicit_conversion_func<true>
{
    template<int N, class Begin, class System>
    struct apply
    {
        enum { value = implicit_conversion_impl<N-1>::template apply<typename mpl::next<Begin>::type, System>::value};
    };
};

template<>
struct implicit_conversion_func<false>
{
    template<int N, class Begin, class System>
    struct apply
    {
        enum { value = false };
    };
};

template<int N>
struct implicit_conversion_impl
{
    template<class Begin, class System>
    struct apply
    {
        typedef typename mpl::deref<Begin>::type::tag_type current;
        typedef typename reduce_unit<unit<typename current::dimension_type, System> >::type target_unit;
        enum { value = (implicit_conversion_func<base_unit_is_implicitly_convertible<current, target_unit>::value>::template apply<N, Begin, System>::value) };
    };
};

template<>
struct implicit_conversion_impl<0>
{
    template<class Begin, class System>
    struct apply
    {
        enum { value = true };
    };
};

template<class From, class To>
struct unit_is_implicitly_convertible {
    typedef typename reduce_unit<From>::type::system_type::type list;
    typedef mpl::bool_<(implicit_conversion_impl<mpl::size<list>::value>::template apply<typename mpl::begin<list>::type, typename To::system_type>::value)> type;
};

} // namespace detail

#define BOOST_UNITS_IMPLICIT_CONVERSION(From, To)                           \
    namespace boost {                                                       \
    namespace units {                                                       \
    namespace detail {                                                      \
    template<>                                                              \
    struct base_unit_is_implicitly_convertible<From, To> : mpl::true_ {};   \
    }                                                                       \
    }                                                                       \
    }

#define BOOST_UNITS_BASE_IMPLICIT_CONVERSION(From, To)                      \
    namespace boost {                                                       \
    namespace units {                                                       \
    namespace detail {                                                      \
    template<>                                                              \
    struct base_unit_is_implicitly_convertible<                             \
        From,                                                               \
        BOOST_UNITS_MAKE_HETEROGENEOUS_UNIT(To, From::dimension_type)       \
    > : mpl::true_ {};                                                      \
    }                                                                       \
    }                                                                       \
    }

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_IMPLICIT_CONVERSION_HPP
