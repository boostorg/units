// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_COMPOUND_SYSTEM_HPP_INCLUDED
#define BOOST_UNITS_COMPOUND_SYSTEM_HPP_INCLUDED

#include <boost/mpl/size.hpp>
#include <boost/mpl/begin.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/next.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/push_front.hpp>

#include <boost/units/experimental/scaled_system.hpp>
#include <boost/units/system.hpp>
#include <boost/units/io.hpp>
#include <boost/units/conversion.hpp>
#include <boost/units/dim.hpp>

namespace boost {

namespace units {

template<class M>
struct compound_system {
    typedef M map_type;
};

template<class DimensionTag, class M, class System, class Scale>
struct base_unit_converter<DimensionTag, compound_system<M>, scaled_system<System, Scale> > 
    : base_unit_converter<DimensionTag, typename mpl::at<M, DimensionTag>::type, scaled_system<System, Scale> > {};
template<class DimensionTag, class System, class Scale, class M>
struct base_unit_converter<DimensionTag, scaled_system<System, Scale>, compound_system<M> > 
    : base_unit_converter<DimensionTag, scaled_system<System, Scale>, typename mpl::at<M, DimensionTag>::type> {};

template<class DimensionTag, class M, class System>
struct base_unit_converter<DimensionTag, compound_system<M>, System> 
    : base_unit_converter<DimensionTag, typename mpl::at<M, DimensionTag>::type, System> {};
template<class DimensionTag, class System, class M>
struct base_unit_converter<DimensionTag, System, compound_system<M> > 
    : base_unit_converter<DimensionTag, System, typename mpl::at<M, DimensionTag>::type> {};
template<class DimensionTag, class M1, class M2>
struct base_unit_converter<DimensionTag, compound_system<M1>, compound_system<M2> > 
    : base_unit_converter<DimensionTag, typename mpl::at<M1, DimensionTag>::type, typename mpl::at<M2, DimensionTag>::type> {};

template<class DimensionTag, class M>
struct base_unit_info<DimensionTag, compound_system<M> >
    : base_unit_info<DimensionTag, typename mpl::at<M, DimensionTag>::type> {};

template<int N>
struct compound_system_heterogeneous_system_view_impl
{
    template<class Begin, class M>
    struct apply {
        typedef typename detail::get_tag<typename mpl::deref<Begin>::type>::type    tag_type;
        typedef typename mpl::at<M,tag_type>::type  at_type;
        typedef typename mpl::push_front<dimensionless_type,heterogeneous_system_element<at_type,typename mpl::deref<Begin>::type> >::type current;
        typedef typename compound_system_heterogeneous_system_view_impl<N - 1>::template apply<typename mpl::next<Begin>::type, M>::type next;
        typedef typename detail::merge_dimensions<current, next>::type type;
    };
};
template<>
struct compound_system_heterogeneous_system_view_impl<0>
{
    template<class Begin, class M>
    struct apply {
        typedef dimensionless_type type;
    };
};

template<class M, class Dimensions>
struct heterogeneous_system_view<compound_system<M>, Dimensions>
{
    typedef typename compound_system_heterogeneous_system_view_impl<mpl::size<Dimensions>::value>::template apply<typename mpl::begin<Dimensions>::type, M>::type type;
    typedef Dimensions dimension;
};

template<class M>
struct make_system
{
    typedef homogeneous_system<compound_system<M> > type;
};

}

}

#endif
