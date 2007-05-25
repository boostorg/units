// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_EXPERIMENTAL_CONVERSION_HPP
#define BOOST_UNITS_EXPERIMENTAL_CONVERSION_HPP

#include <boost/mpl/bool.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/begin.hpp>
#include <boost/mpl/next.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/divides.hpp>

#include <boost/units/experimental/scaled_base_unit.hpp>
#include <boost/units/experimental/make_system.hpp>
#include <boost/units/experimental/heterogeneous_system.hpp>
#include <boost/units/experimental/one.hpp>
#include <boost/units/experimental/static_rational_power.hpp>

namespace boost {

namespace units {

template<class Dimension, class System>
class unit;

template<class Unit, class T>
class quantity;

template<class From, class To>
struct conversion_helper;

template<class Source, class Destination>
struct select_base_unit_converter {
    typedef Source source_type;
    typedef Destination destination_type;
};

template<class Source, class Destination>
struct base_unit_converter {
    typedef select_base_unit_converter<typename unscale<Source>::type, typename unscale<Destination>::type> selector;
    typedef typename selector::source_type source_type;
    typedef typename selector::destination_type destination_type;
    typedef base_unit_converter<source_type, destination_type> converter;
    typedef typename mpl::divides<typename get_scale_list<Source>::type, typename get_scale_list<source_type>::type>::type source_factor;
    typedef typename mpl::divides<typename get_scale_list<Destination>::type, typename get_scale_list<destination_type>::type>::type destination_factor;
    typedef typename mpl::divides<source_factor, destination_factor>::type factor;
    typedef eval_scale_list<factor> eval_factor;
    typedef typename multiply_typeof_helper<typename converter::type, typename eval_factor::type>::type type;
    static type value() {
        return(converter::value() * eval_factor::value());
    }
};

template<bool try_inverse, bool trivial>
struct inverse_base_unit_converter_impl;

template<>
struct inverse_base_unit_converter_impl<false, false> {
    template<class Source, class Destination>
    struct apply {
        typedef select_base_unit_converter<typename unscale<Source>::type, typename unscale<typename Destination::unit_type>::type> selector;
        typedef typename selector::source_type source_type;
        typedef typename selector::destination_type destination_type;
        typedef base_unit_converter<source_type, destination_type> converter;
        typedef typename mpl::divides<typename get_scale_list<Source>::type, typename get_scale_list<source_type>::type>::type source_factor;
        typedef typename mpl::divides<typename get_scale_list<Destination>::type, typename get_scale_list<destination_type>::type>::type destination_factor;
        typedef typename mpl::divides<source_factor, destination_factor>::type factor;
        typedef eval_scale_list<factor> eval_factor;
        typedef typename multiply_typeof_helper<typename converter::type, typename eval_factor::type>::type type;
        static type value() {
            return(converter::value() * eval_factor::value());
        }
    };
};

template<>
struct inverse_base_unit_converter_impl<true, false> {
    template<class Source, class Destination>
    struct apply {
        typedef base_unit_converter<Destination, typename Source::unit_type> inverse;
        typedef typename inverse::type type;
        static type value() {
            return(1/inverse::value());
        }
    };
};

template<bool dummy>
struct inverse_base_unit_converter_impl<dummy, true> {
    template<class Source, class Destination>
    struct apply {
        typedef one type;
        static type value() { return(type()); }
    };
};

template<class Source, class Dest>
struct use_inverse_conversion {
    typedef select_base_unit_converter<typename unscale<Source>::type, typename unscale<typename Dest::unit_type>::type> selector;
    enum { value = (boost::is_same<Source, typename selector::source_type>::value) &&
        (boost::is_same<typename Dest::unit_type, typename selector::destination_type>::value) };
};

template<class Source, class Dest>
struct base_unit_converter<
    Source,
    unit<
        typename Source::dimension_type,
        heterogeneous_system<
            heterogeneous_system_pair<
                dimension_list<heterogeneous_system_dim<Dest, static_rational<1> >, dimensionless_type>,
                typename Source::dimension_type
            >
        >
    >
> : inverse_base_unit_converter_impl<use_inverse_conversion<Source, Dest>::value, boost::is_same<Source, Dest>::value>::template apply<Source, Dest> {
};

#define BOOST_UNITS_DEFINE_CONVERSION(Source, Destination, type_, value_)\
namespace boost {\
namespace units {\
template<>\
struct select_base_unit_converter<unscale<Source>::type,unscale<reduce_unit<Destination>::type>::type> {\
    typedef Source source_type;\
    typedef Destination destination_type;\
};\
template<>\
struct base_unit_converter<Source, reduce_unit<Destination>::type> {\
    typedef type_ type;\
    static type value() { return(value_); }\
};\
}\
}\
void boost_units_require_semicolon()

namespace detail {

template<int N>
struct conversion_impl {
    template<class Begin, class DestinationSystem>
    struct apply {
        typedef typename conversion_impl<N-1>::template apply<
            typename mpl::next<Begin>::type,
            DestinationSystem
        > next_iteration;
        typedef typename mpl::deref<Begin>::type unit_pair;
        typedef typename unit_pair::tag_type unit;
        typedef typename unit::dimension_type dimensions;
        typedef typename reduce_unit<units::unit<dimensions, DestinationSystem> >::type reduced_unit;
        typedef base_unit_converter<unit, reduced_unit> converter;
        typedef typename multiply_typeof_helper<typename converter::type, typename next_iteration::type>::type type;
        static type value() { return(static_rational_power<typename unit_pair::value_type>(converter::value()) * next_iteration::value()); }
    };
};

template<>
struct conversion_impl<0> {
    template<class Begin, class DestinationSystem>
    struct apply {
        typedef one type;
        static type value() { return(one()); }
    };
};

} // namespace detail

template<class D, class L1, class T1, class L2, class T2>
struct conversion_helper<quantity<unit<D, homogeneous_system<L1> >, T1>, quantity<unit<D, homogeneous_system<L2> >, T2> > {
    typedef quantity<unit<D, homogeneous_system<L2> >, T2> destination_type;
    typedef typename reduce_unit<unit<D, homogeneous_system<L1> > >::type source_unit;
    typedef typename source_unit::system_type::type unit_list;
    static destination_type convert(const quantity<unit<D, homogeneous_system<L1> >, T1>& source) {
        return(destination_type::from_value(source.value() * 
            detail::conversion_impl<mpl::size<unit_list>::value>::template apply<
                typename mpl::begin<unit_list>::type,
                homogeneous_system<L2>
            >::value()
            ));
    }
};

template<class D, class L1, class T1, class L2, class T2>
struct conversion_helper<quantity<unit<D, heterogeneous_system<L1> >, T1>, quantity<unit<D, homogeneous_system<L2> >, T2> > {
    typedef quantity<unit<D, homogeneous_system<L2> >, T2> destination_type;
    static destination_type convert(const quantity<unit<D, heterogeneous_system<L1> >, T1>& source) {
        return(destination_type::from_value(source.value() * 
            detail::conversion_impl<mpl::size<typename L1::type>::value>::template apply<
                typename mpl::begin<typename L1::type>::type,
                homogeneous_system<L2>
            >::value()
            ));
    }
};

// There is no simple algorithm for doing this conversion
// other than just defining it as the reverse of the
// heterogeneous->homogeneous case
template<class D, class L1, class T1, class L2, class T2>
struct conversion_helper<quantity<unit<D, homogeneous_system<L1> >, T1>, quantity<unit<D, heterogeneous_system<L2> >, T2> > {
    typedef quantity<unit<D, heterogeneous_system<L2> >, T2> destination_type;
    static destination_type convert(const quantity<unit<D, homogeneous_system<L1> >, T1>& source) {
        return(destination_type::from_value(source.value() /
            detail::conversion_impl<mpl::size<typename L2::type>::value>::template apply<
                typename mpl::begin<typename L2::type>::type,
                homogeneous_system<L1>
            >::value()
            ));
    }
};

} //namespace units

} // namespace boost

#endif
