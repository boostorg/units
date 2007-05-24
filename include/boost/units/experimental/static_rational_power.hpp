// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_STATIC_RATIONAL_POWER_HPP
#define BOOST_UNITS_STATIC_RATIONAL_POWER_HPP

#include <cmath>

#include <boost/units/static_rational.hpp>
#include <boost/units/experimental/one.hpp>

namespace boost {

namespace units {

namespace detail {

template<class R, class Y>
struct static_rational_power_impl
{
    static Y apply(const Y& y)
    {
        return(std::pow(y, value<Y>(R())));
    }
};

template<class R>
struct static_rational_power_impl<R, one>
{
    static one apply(const one&)
    {
        return(one());
    }
};

template<long N>
struct static_rational_power_impl<static_rational<N>, one>
{
    static one apply(const one&)
    {
        return(one());
    }
};

template<integer_type N, bool = (N % 2 == 0)>
struct static_int_power_impl;

template<integer_type N>
struct static_int_power_impl<N, true>
{
    template<class Y, class R>
    static Y apply(const Y& y, const R& r) {
        const Y square = y * y;
        return(static_int_power_impl<(N >> 1)>::apply(square, r));
    }
};

template<integer_type N>
struct static_int_power_impl<N, false>
{
    template<class Y, class R>
    static Y apply(const Y& y, const R& r)
    {
        const Y square = y * y;
        return(static_int_power_impl<(N >> 1)>::apply(square, y * r));
    }
};

template<>
struct static_int_power_impl<1, false>
{
    template<class Y, class R>
    static Y apply(const Y& y, const R& r)
    {
        return(y * r);
    }
};

template<>
struct static_int_power_impl<0, true>
{
    template<class Y, class R>
    static Y apply(const Y&, const R& r)
    {
        return(r);
    }
};

template<int N, bool = (N < 0)>
struct static_int_power_sign_impl;

template<int N>
struct static_int_power_sign_impl<N, false>
{
    template<class Y>
    static Y apply(const Y& y)
    {
        return(static_int_power_impl<N>::apply(y, one()));
    }
};

template<int N>
struct static_int_power_sign_impl<N, true>
{
    template<class Y>
    static Y apply(const Y& y)
    {
        return(one()/static_int_power_impl<-N>::apply(y, one()));
    }
};

template<integer_type N, class Y>
struct static_rational_power_impl<static_rational<N>, Y>
{
    static Y apply(const Y& y)
    {
        return(static_int_power_sign_impl<N>::apply(y));
    }
};

template<class R, class Y>
Y static_rational_power(const Y& y)
{
    return(detail::static_rational_power_impl<R, Y>::apply(y));
}

} // namespace detail

} // namespace units

} // namespace boost

#endif
