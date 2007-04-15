// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_DIMENSION_HPP
#define BOOST_UNITS_DIMENSION_HPP

#include <boost/static_assert.hpp>

#include <boost/mpl/arithmetic.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/begin_end.hpp>
#include <boost/mpl/bool_fwd.hpp>
#include <boost/mpl/is_sequence.hpp>
#include <boost/mpl/list.hpp>
#include <boost/mpl/long.hpp>
#include <boost/mpl/size.hpp>

#include <boost/units/dim.hpp>
#include <boost/units/dimensionless_type.hpp>
#include <boost/units/operators.hpp>
#include <boost/units/static_rational.hpp>
#include <boost/units/detail/dimension_impl.hpp>

/// \file 
/// \brief Core metaprogramming utilities for compile-time dimensional analysis.

namespace boost {

namespace units {

/// Reduce dimension list to cardinal form. This algorithm collapses duplicate unit 
/// tags, strips dimensionless tags, and sorts the resulting list. Sorting of homogeneous
/// units is by the tag ordinal value. Heterogeneous units are sorted by... 
/// Dimension lists that resolve to the same dimension are guaranteed to be  
/// represented by an identical type.
template<typename Seq>
struct make_dimension_list
{
    typedef typename detail::remove_dimensionless<boost::mpl::size<Seq>::value>::template 
        apply<typename boost::mpl::begin<Seq>::type, detail::sort_dims_list_end>::type      sequence;
    
    typedef typename detail::sort_dims_forward<sequence, detail::sort_dims_list_end>::type  type2;

    typedef typename detail::sort_dims_to_mpl_list<type2>::type                             type;
};

/// Raise a dimension list to a scalar power.
template<typename DL,typename Ex> 
struct static_power
{
    typedef typename detail::static_power_impl<mpl::size<DL>::value>::template apply<
        typename mpl::begin<DL>::type,
        Ex
    >::type type;    
};

/// @c static_power specialized to a @c static_rational exponent.
template<typename DL,long N,long D> 
struct static_power< DL,static_rational<N,D> >
{
    typedef typename detail::static_power_impl<mpl::size<DL>::value>::template apply<
        typename mpl::begin<DL>::type,
        static_rational<N,D>
    >::type type;    
};

/// Take a scalar root of a dimension list.
template<typename DL,typename Rt> 
struct static_root
{
    typedef typename detail::static_root_impl<mpl::size<DL>::value>::template apply<
        typename mpl::begin<DL>::type,
        Rt
    >::type type;    
};

/// @c static_root specialized to a @c static_rational root.
template<typename DL,long N,long D> 
struct static_root< DL,static_rational<N,D> >
{
    typedef typename detail::static_root_impl<mpl::size<DL>::value>::template apply<
        typename mpl::begin<DL>::type,
        static_rational<N,D>
    >::type type; 
};

} // namespace units

namespace mpl {

template<>
struct plus_impl<boost::units::detail::dimension_list_tag,boost::units::detail::dimension_list_tag>
{
    template<class T0, class T1>
    struct apply
    {
        BOOST_STATIC_ASSERT((boost::is_same<T0,T1>::value == true));
        typedef T0 type;
    };
};

template<>
struct minus_impl<boost::units::detail::dimension_list_tag,boost::units::detail::dimension_list_tag>
{
    template<class T0, class T1>
    struct apply
    {
        BOOST_STATIC_ASSERT((boost::is_same<T0,T1>::value == true));
        typedef T0 type;
    };
};

template<>
struct times_impl<boost::units::detail::dimension_list_tag,boost::units::detail::dimension_list_tag>
{
    template<class T0, class T1>
    struct apply
    {
        typedef typename boost::units::detail::merge_dimensions<T0,T1>::type type;
    };
};

template<>
struct divides_impl<boost::units::detail::dimension_list_tag,boost::units::detail::dimension_list_tag>
{
    template<class T0, class T1>
    struct apply
    {
        typedef typename boost::units::detail::merge_dimensions<
            T0,
            typename boost::units::detail::static_inverse_impl<
                mpl::size<T1>::value
            >::template apply<
                typename mpl::begin<T1>::type
            >::type
        >::type type;
    };
};

template<>
struct negate_impl<boost::units::detail::dimension_list_tag>
{
    template<class T0>
    struct apply
    {
        typedef T0 type;
    };
};

} // namespace mpl

} // namespace boost

#endif // BOOST_UNITS_DIMENSION_HPP
