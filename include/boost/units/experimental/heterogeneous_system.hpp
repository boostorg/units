// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_EXPERIMENTAL_HETEROGENEOUS_SYSTEM_HPP
#define BOOST_UNITS_EXPERIMENTAL_HETEROGENEOUS_SYSTEM_HPP

namespace boost {

namespace units {

namespace detail {

// A normal system is a sorted list of base units.
// A heterogeneous system is a sorted list of base unit/exponent pairs.
// As long as we don't need to convert heterogeneous systems
// directly everything is cool

template<class T>
struct is_zero : mpl::false_ {};

template<>
struct is_zero<static_rational<0> > : mpl::true_ {};

template<bool>
struct push_front_if;

template<>
struct push_front_if<true> {
    template<class L, class T>
    struct apply {
        typedef typename mpl::push_front<L, T>::type type;
    };
};

template<>
struct push_front_if<false> {
    template<class L, class T>
    struct apply {
        typedef L type;
    };
};

}

template<class L, class Dimensions>
struct heterogeneous_system_pair {
    typedef L type;
    typedef Dimensions dimensions;
};

template<class T>
struct heterogeneous_system : T {
};

struct heterogeneous_system_dim_tag {};

template<class Unit, class Exponent>
struct heterogeneous_system_dim {
    typedef heterogeneous_system_dim_tag tag;
    typedef heterogeneous_system_dim type;
    typedef Unit tag_type;
    typedef Exponent value_type;
};

template<class Unit1, class Exponent1, class Unit2, class Exponent2>
struct less<heterogeneous_system_dim<Unit1,Exponent1>,heterogeneous_system_dim<Unit2,Exponent2> > :
    mpl::less<Unit1, Unit2> {
};

template<class Unit1, class Exponent1>
struct is_empty_dim<heterogeneous_system_dim<Unit1,Exponent1> > : detail::is_zero<Exponent1> {};

} // namespace units

namespace mpl {

struct plus_impl<boost::units::heterogeneous_system_dim_tag, boost::units::heterogeneous_system_dim_tag> {
    template<class T0, class T1>
    struct apply {
        typedef boost::units::heterogeneous_system_dim<
            typename T0::tag_type,
            typename mpl::plus<typename T0::value_type,typename T1::value_type>::type
        > type;
    };
};

} // namespace mpl

namespace units {

namespace detail {

template<int N>
struct make_heterogeneous_system_impl {
    template<class UnitsBegin, class ExponentsBegin>
    struct apply {
        typedef typename push_front_if<is_zero<typename mpl::deref<ExponentsBegin>::type>::value>::template apply<
            typename make_heterogeneous_system<N-1>::template apply<
                typename mpl::next<UnitsBegin>::type,
                typename mpl::next<ExponentsBegin>::type
            >::type,
            heterogeneous_system_dim<typename mpl::deref<UnitsBegin>::type, typename mpl::deref<UnitsBegin>::type>
        >::type type;
    };
};

template<>
struct make_heterogeneous_system_impl<0> {
    template<class UnitsBegin, class ExponentsBegin>
    struct apply {
        typedef dimensionless_type type;
    };
};

template<class Dimensions, class System>
struct make_heterogeneous_system {
    typedef typename calculate_base_unit_exponents<typename System::type, Dimensions>::type exponents;
    typedef typename make_heterogeneous_system_impl<mpl::size<typename System::type>::value>::template apply<
        typename mpl::begin<typename System::type>::type,
        typename mpl::begin<exponents>::type
    >::type unit_list;
    typedef heterogeneous_system<heterogeneous_system_pair<unit_list,Dimensions> > type;
};

template<class Dimensions, class T>
struct make_heterogeneous_system<Dimensions, heterogeneous_system<T> > {
    typedef heterogeneous_system<T> type;
};

} // namespace detail

template<class Unit>
struct reduce_unit {
    typedef unit<
        typename Unit::dimension_type,
        typename detail::make_heterogeneous_system<
            typename Unit::dimension_type,
            typename Unit::system_type
        >::type
    > type;
};

namespace detail {

template<int N>
struct unscale_heterogeneous_system_impl {
    template<class Begin>
    struct apply {
        typedef typename mpl::push_front<
            typename unscale_heterogeneous_system_impl<N-1>::template apply<
                typename mpl::next<Begin>::type
            >::type,
            typename unscale<typename mpl::deref<Begin>::type>::type
        >::type type;
    };
};

template<>
struct unscale_heterogeneous_system_impl<0> {
    template<class Begin>
    struct apply {
        typedef dimensionless_type type;
    };
};

}

template<class T>
struct unscale<heterogeneous_system<T> > {
    typedef heterogeneous_system<
        heterogeneous_system_pair<
            typename detail::unscale_heterogeneous_system_impl<
                mpl::size<typename T::type>::value
            >::template apply<
                typename mpl::begin<typename T::type>::type
            >::type,
            typename T::dimensions
        >
    > type;
};

}

}

#endif
