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
//
///// Dimension lists in which all exponents resolve to zero reduce to @c dimensionless_type.
//struct dimensionless_type
//{
//    typedef dimensionless_type          type;
//    typedef detail::dimension_list_tag  tag;
//    typedef mpl::long_<0>               size;
//};

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
//
///// Check that a type is a valid dimension list.
//template<typename Seq>
//struct is_dimension_list :
//    public mpl::false_
//{ };
//
//template<typename Item, typename Next>
//struct is_dimension_list<dimension_list<Item, Next> > :
//    public mpl::true_
//{ };
//
//template<>
//struct is_dimension_list<dimensionless_type> :
//    public mpl::true_
//{ };

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
//
///// A utility class for defining base dimensions.
//template<long N> struct base_dimension;
//
///// each specialization must be separately instantiated in boost::units namespace to prevent duplication of tag values
//#define BOOST_UNITS_REGISTER_BASE_DIMENSION(name, N)                                                        \
//template<>                                                                                                  \
//struct base_dimension<N> :                                                                                  \
//    public mpl::int_<N>                                                                                     \
//{                                                                                                           \
//    typedef base_dimension<N>   this_type;                                                                  \
//    typedef mpl::int_<N>        value;                                                                      \
//                                                                                                            \
//    typedef make_dimension_list< mpl::list< dim< this_type,static_rational<1> > > >::type type;             \
//};                                                                                                          \
//                                                                                                            \
//typedef base_dimension<N>   name                                                                            \

//// gcc doesn't like this for some reason...
///// each specialization must be separately instantiated in boost::units namespace to prevent duplication of tag values
//#define BOOST_UNITS_REGISTER_BASE_DIMENSION(name, N)                                                        \
//template<>                                                                                                  \
//struct boost::units::base_dimension<N> :                                                                    \
//    public boost::mpl::int_<N>                                                                              \
//{                                                                                                           \
//    typedef boost::units::base_dimension<N>   this_type;                                                    \
//    typedef boost::mpl::int_<N>        value;                                                               \
//                                                                                                            \
//    typedef boost::units::make_dimension_list< boost::mpl::list< boost::units::dim< this_type,boost::units::static_rational<1> > > >::type type;\
//};                                                                                                          \
//                                                                                                            \
//typedef boost::units::base_dimension<N>   name                                                              \
//
///// A utility class for defining composite dimensions with integer powers.
//template<class DT1 = dimensionless_type,int E1 = 0,
//         class DT2 = dimensionless_type,int E2 = 0,
//         class DT3 = dimensionless_type,int E3 = 0,
//         class DT4 = dimensionless_type,int E4 = 0,
//         class DT5 = dimensionless_type,int E5 = 0,
//         class DT6 = dimensionless_type,int E6 = 0,
//         class DT7 = dimensionless_type,int E7 = 0,
//         class DT8 = dimensionless_type,int E8 = 0>
//struct derived_dimension
//{
//    typedef typename 
//    make_dimension_list< mpl::list< dim< DT1,static_rational<E1> >,
//                                    dim< DT2,static_rational<E2> >,
//                                    dim< DT3,static_rational<E3> >,
//                                    dim< DT4,static_rational<E4> >,
//                                    dim< DT5,static_rational<E5> >,
//                                    dim< DT6,static_rational<E6> >,
//                                    dim< DT7,static_rational<E7> >,
//                                    dim< DT8,static_rational<E8> > > >::type type;
//};

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
