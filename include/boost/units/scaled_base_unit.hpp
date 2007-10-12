// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_SCALED_SYSTEM_HPP_INCLUDED
#define BOOST_UNITS_SCALED_SYSTEM_HPP_INCLUDED

#include <string>

#include <boost/mpl/bool.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/begin.hpp>
#include <boost/mpl/next.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/times.hpp>
#include <boost/mpl/negate.hpp>
#include <boost/mpl/less.hpp>
#include <boost/type_traits/is_same.hpp>

#include <boost/units/config.hpp>
#include <boost/units/dimension.hpp>
#include <boost/units/static_rational.hpp>
#include <boost/units/units_fwd.hpp>
#include <boost/units/detail/one.hpp>
#include <boost/units/detail/static_rational_power.hpp>

namespace boost {

namespace units {

template<class T>
struct heterogeneous_system;

template<class T, class D>
struct heterogeneous_system_pair;

template<class T, class E>
struct heterogeneous_system_dim;

template<long Base, class Exponent>
struct scale
{
    enum { base = Base };
    typedef Exponent exponent;
    typedef double value_type;
    static value_type value() { return(detail::static_rational_power<Exponent>(static_cast<double>(base))); }
};

/// INTERNAL ONLY
template<long Base>
struct scale<Base, static_rational<0> >
{
    static const long base = Base;
    typedef static_rational<0> exponent;
    typedef one value_type;
    static one value() { return(one()); }
    static std::string name_prefix() { return(std::string()); }
    static std::string symbol_prefix() { return(std::string()); }
};

#ifndef BOOST_UNITS_DOXYGEN

#define BOOST_UNITS_SCALE_SPECIALIZATION(base_,exponent_,val,name,symbol)   \
template<>                                                                  \
struct scale<base_, exponent_ >                                             \
{                                                                           \
    static const long base = base_;                                         \
    typedef exponent_ exponent;                                             \
    typedef double value_type;                                              \
    static value_type value() { return(val); }                              \
    static std::string name_prefix() { return(#name); }                     \
    static std::string symbol_prefix() { return(#symbol); }                 \
}

#define BOOST_UNITS_SCALE_DEF(exponent,value,name,symbol) \
    BOOST_UNITS_SCALE_SPECIALIZATION(10,static_rational<exponent>,value, name, symbol)

BOOST_UNITS_SCALE_DEF(-24, 1e-24 ,yocto, y);
BOOST_UNITS_SCALE_DEF(-21, 1e-21, zepto, z);
BOOST_UNITS_SCALE_DEF(-18, 1e-18, atto, a);
BOOST_UNITS_SCALE_DEF(-15, 1e-15, femto, f);
BOOST_UNITS_SCALE_DEF(-12, 1e-12, pico, p);
BOOST_UNITS_SCALE_DEF(-9, 1e-9, nano, n);
BOOST_UNITS_SCALE_DEF(-6, 1e-6, micro, u);
BOOST_UNITS_SCALE_DEF(-3, 1e-3, milli, m);
BOOST_UNITS_SCALE_DEF(-2, 1e-2, centi, c);
BOOST_UNITS_SCALE_DEF(-1, 1e-1, deci, d);

BOOST_UNITS_SCALE_DEF(1, 1e1, deka, da);
BOOST_UNITS_SCALE_DEF(2, 1e2, hecto, h);
BOOST_UNITS_SCALE_DEF(3, 1e3, kilo, k);
BOOST_UNITS_SCALE_DEF(6, 1e6, mega, M);
BOOST_UNITS_SCALE_DEF(9, 1e9, giga, G);
BOOST_UNITS_SCALE_DEF(12, 1e12, tera, T);
BOOST_UNITS_SCALE_DEF(15, 1e15, peta, P);
BOOST_UNITS_SCALE_DEF(18, 1e18, exa, E);
BOOST_UNITS_SCALE_DEF(21, 1e21, zetta, Z);
BOOST_UNITS_SCALE_DEF(24, 1e24, yotta, Y);

BOOST_UNITS_SCALE_SPECIALIZATION(2, static_rational<10>, 1024.0, kibi, Ki);
BOOST_UNITS_SCALE_SPECIALIZATION(2, static_rational<20>, 1048576.0, mebi, Mi);
BOOST_UNITS_SCALE_SPECIALIZATION(2, static_rational<30>, 1073741824.0, gibi, Gi);
BOOST_UNITS_SCALE_SPECIALIZATION(2, static_rational<40>, 1099511627776.0, tebi, Ti);
BOOST_UNITS_SCALE_SPECIALIZATION(2, static_rational<50>, 1125899906842624.0, pebi, Pi);
BOOST_UNITS_SCALE_SPECIALIZATION(2, static_rational<60>, 1152921504606846976.0, exbi, Ei);

#undef BOOST_UNITS_SCALE_DEF
#undef BOOST_UNITS_SCALE_SPECIALIZATION

#endif

/// INTERNAL ONLY
struct scaled_base_unit_tag {};

template<class S, class Scale>
struct scaled_base_unit
{
    typedef scaled_base_unit type;
    typedef scaled_base_unit_tag tag;
    typedef S system_type;
    typedef Scale scale_type;
    typedef typename S::dimension_type dimension_type;
    typedef unit<
        dimension_type,
        heterogeneous_system<
            heterogeneous_system_pair<
                dimension_list<
                    heterogeneous_system_dim<scaled_base_unit,static_rational<1> >,
                    dimensionless_type
                >,
                dimension_type
            >
        >
    > unit_type;

    static std::string symbol()
    {
        return(Scale::symbol_prefix() + S::symbol());
    }
    static std::string name()
    {
        return(Scale::name_prefix() + S::name());
    }
};

} // namespace units

} // namespace boost

#if BOOST_UNITS_HAS_BOOST_TYPEOF

#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

BOOST_TYPEOF_REGISTER_TEMPLATE(boost::units::scale, (long)(class))
BOOST_TYPEOF_REGISTER_TEMPLATE(boost::units::scaled_base_unit, (class)(class))

#endif

namespace boost {

namespace units {

namespace detail {

struct unspecified;

}

/// removes all scaling from a unit or a base unit.
template<class T>
struct unscale
{
#ifndef BOOST_UNITS_DOXYGEN
    typedef T type;
#else
    typedef detail::unspecified type;
#endif
};

/// INTERNAL ONLY
template<class S, class Scale>
struct unscale<scaled_base_unit<S, Scale> >
{
    typedef typename unscale<S>::type type;
};

/// INTERNAL ONLY
template<class D, class S>
struct unscale<unit<D, S> >
{
    typedef unit<D, typename unscale<S>::type> type;
};

/// INTERNAL ONLY
template<class Scale>
struct scale_list_dim;

/// INTERNAL ONLY
template<class T>
struct get_scale_list
{
    typedef dimensionless_type type;
};

/// INTERNAL ONLY
template<class S, class Scale>
struct get_scale_list<scaled_base_unit<S, Scale> >
{
    typedef typename mpl::times<dimension_list<scale_list_dim<Scale>, dimensionless_type>, typename get_scale_list<S>::type>::type type;
};

/// INTERNAL ONLY
template<class D, class S>
struct get_scale_list<unit<D, S> >
{
    typedef typename get_scale_list<S>::type type;
};

/// INTERNAL ONLY
struct scale_dim_tag {};

/// INTERNAL ONLY
template<class Scale>
struct scale_list_dim : Scale
{
    typedef scale_dim_tag tag;
    typedef scale_list_dim type;
};

} // namespace units

namespace mpl {

/// INTERNAL ONLY
template<>
struct less_impl<boost::units::scale_dim_tag, boost::units::scale_dim_tag>
{
    template<class T0, class T1>
    struct apply : mpl::bool_<((T0::base) < (T1::base))> {};
};

}

namespace units {

namespace detail {

template<int N>
struct eval_scale_list_impl
{
    template<class Begin>
    struct apply
    {
        typedef typename eval_scale_list_impl<N-1>::template apply<typename mpl::next<Begin>::type> next_iteration;
        typedef typename multiply_typeof_helper<typename next_iteration::type, typename mpl::deref<Begin>::type::value_type>::type type;
        static type value()
        {
            return(next_iteration::value() * mpl::deref<Begin>::type::value());
        }
    };
};

template<>
struct eval_scale_list_impl<0>
{
    template<class Begin>
    struct apply
    {
        typedef one type;
        static type value()
        {
            return(type());
        }
    };
};

}

/// INTERNAL ONLY
template<class T>
struct eval_scale_list : detail::eval_scale_list_impl<mpl::size<T>::value>::template apply<typename mpl::begin<T>::type> {};

} // namespace units

namespace mpl {

/// INTERNAL ONLY
template<>
struct plus_impl<boost::units::scale_dim_tag, boost::units::scale_dim_tag>
{
    template<class T0, class T1>
    struct apply
    {
        typedef boost::units::scale_list_dim<
            boost::units::scale<
                (T0::base),
                typename mpl::plus<typename T0::exponent, typename T1::exponent>::type
            >
        > type;
    };
};

/// INTERNAL ONLY
template<>
struct negate_impl<boost::units::scale_dim_tag>
{
    template<class T0>
    struct apply
    {
        typedef boost::units::scale_list_dim<
            boost::units::scale<
                (T0::base),
                typename mpl::negate<typename T0::exponent>::type
            >
        > type;
    };
};

/// INTERNAL ONLY
template<>
struct times_impl<boost::units::scale_dim_tag, boost::units::detail::static_rational_tag>
{
    template<class T0, class T1>
    struct apply
    {
        typedef boost::units::scale_list_dim<
            boost::units::scale<
                (T0::base),
                typename mpl::times<typename T0::exponent, T1>::type
            >
        > type;
    };
};

/// INTERNAL ONLY
template<class Tag>
struct less_impl<boost::units::scaled_base_unit_tag, Tag>
{
    template<class T0, class T1>
    struct apply : mpl::bool_<
        ((mpl::less<typename T0::system_type, T1>::value) ||
        ((boost::is_same<typename T0::system_type, T1>::value) && ((T0::scale_type::exponent::Numerator) < 0)))> {};
};

/// INTERNAL ONLY
template<class Tag>
struct less_impl<Tag, boost::units::scaled_base_unit_tag>
{
    template<class T0, class T1>
    struct apply : mpl::bool_<
        ((mpl::less<T0, typename T1::system_type>::value) ||
        ((boost::is_same<T0, typename T1::system_type>::value) && ((T1::scale_type::exponent::Numerator) > 0)))> {};
};

/// INTERNAL ONLY
template<>
struct less_impl<boost::units::scaled_base_unit_tag, boost::units::scaled_base_unit_tag>
{
    template<class T0, class T1>
    struct apply : mpl::bool_<
        ((mpl::less<typename T0::system_type, typename T1::system_type>::value) ||
        ((boost::is_same<typename T0::system_type, typename T1::system_type>::value) &&
            (((T0::scale_type::base) < (T1::scale_type::base)) ||
        (((T0::scale_type::base) == (T1::scale_type::base)) &&
        (mpl::less<typename T0::scale_type::exponent,typename T1::scale_type::exponent>::value)))))> {};
};

} // namespace mpl

} // namespace boost

#endif
