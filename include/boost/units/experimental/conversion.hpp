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

template<class D, class L1, class T1, class L2, class T2>
struct conversion_helper<quantity<unit<D, compound_system<L1> >, T1>, quantity<unit<D, compound_system<L2> >, T2> > {
    typedef quantity<unit<D, compound_system<L2> >, T2> destination_type;
    typedef typename calculate_base_unit_exponents<L1, D>::type exponents;
    static destination_type convert(const quantity<unit<D, compound_system<L1> >, T1>& source) {
        return(destination_type::from_value(source.value() * 
            detail::conversion_impl<mpl::size<L1>::value>::template apply<
                typename mpl::begin<L1>::type,
                typename mpl::begin<exponents>::type,
                L2
            >::value()
            ));
    }
};

namespace detail {

template<int N>
struct conversion_impl {
    template<class Begin, class DestinationSystem>
    struct apply {
        typedef typename convert_heterogeneous_to_homogeneous_impl<N-1>::template apply<
            typename mpl::next<Begin>::type,
            DestinationSystem
        > next_iteration;
        typedef typename mpl::deref<Begin>::type unit_pair;
        typedef typename unit_pair::tag_type unit;
        typedef typename unit::dimensions dimensions;
        typedef typename reduce_unit<unit<dimensions, DestinationSystem> >::type reduced_unit;
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

}

template<class D, class L1, class T1, class L2, class T2>
struct conversion_helper<quantity<unit<D, compound_system<L1> >, T1>, quantity<unit<D, compound_system<L2> >, T2> > {
    typedef quantity<unit<D, compound_system<L2> >, T2> destination_type;
    typedef typename reduce_unit<unit<D, compound_system<L1> > >::type source_type;
    typedef typename source_unit::system_type::type unit_list;
    static destination_type convert(const quantity<unit<D, compound_system<L1> >, T1>& source) {
        return(destination_type::from_value(source.value() * 
            detail::conversion_impl<mpl::size<unit_list>::value>::template apply<
                typename mpl::begin<unit_list>::type,
                compound_system<L2>
            >::value()
            ));
    }
};

template<class D, class L1, class T1, class L2, class T2>
struct conversion_helper<quantity<unit<D, heterogeneous_system<L1> >, T1>, quantity<unit<D, compound_system<L2> >, T2> > {
    typedef quantity<unit<D, compound_system<L2> >, T2> destination_type;
    static destination_type convert(const quantity<unit<D, heterogeneous_system<L1> >, T1>& source) {
        return(destination_type::from_value(source.value() * 
            detail::conversion_impl<mpl::size<typename L1::type>::value>::template apply<
                typename mpl::begin<typename L1::type>::type,
                compound_system<L2>
            >::value()
            ));
    }
};

// There is no simple algorithm for doing this conversion
// other than just defining it as the reverse of the
// heterogeneous->homogeneous case
template<class D, class L1, class T1, class L2, class T2>
struct conversion_helper<quantity<unit<D, compound_system<L1> >, T1>, quantity<unit<D, heterogeneous_system<L2> >, T2> > {
    typedef quantity<unit<D, heterogeneous_system<L2> >, T2> destination_type;
    static destination_type convert(const quantity<unit<D, heterogeneous_system<L1> >, T1>& source) {
        return(destination_type::from_value(source.value() /
            detail::conversion_impl<mpl::size<typename L2::type>::value>::template apply<
                typename mpl::begin<typename L2::type>::type,
                compound_system<L1>
            >::value()
            ));
    }
};

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

} //namespace units

} // namespace boost

#endif
