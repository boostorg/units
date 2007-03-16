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

#include <boost/mpl/and.hpp>
#include <boost/mpl/begin_end.hpp>
#include <boost/mpl/bool_fwd.hpp>
#include <boost/mpl/is_sequence.hpp>
#include <boost/mpl/list.hpp>
#include <boost/mpl/size.hpp>

#include <boost/units/dim.hpp>
#include <boost/units/operators.hpp>
#include <boost/units/static_rational.hpp>
#include <boost/units/detail/dimension_impl.hpp>

/// \file 
/// \brief Core metaprogramming utilities for compile-time dimensional analysis.

namespace boost {

namespace units {

/// Dimension lists in which all exponents resolve to zero reduce to @c dimensionless_type.
struct dimensionless_type
{
    typedef detail::dimension_list_tag  tag;
    typedef mpl::long_<0>               size;
};

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

/// Check that a type is a valid dimension list.
template<typename Seq>
struct is_dimension_list :
    public mpl::false_
{ };

template<typename Item, typename Next>
struct is_dimension_list<dimension_list<Item, Next> > :
    public mpl::true_
{ };

template<>
struct is_dimension_list<dimensionless_type> :
    public mpl::true_
{ };

// All the static_* metafunctions in this file assume
// that their parameters are sorted dimension lists.
// 
// should we static assert is_dimension_list here?

/// Negate dimension list.
template<typename DL>
struct static_negate
{
    typedef DL type;
};

/// Add two dimension list, only permitted if they are commensurate.
template<typename DL1,typename DL2>
struct static_add
{
    BOOST_STATIC_ASSERT((is_same<DL1,DL2>::value == true));
    typedef DL1 type;
};

/// Subtract two dimension sequences, only permitted if they are commensurate.
template<typename DL1,typename DL2>
struct static_subtract
{
    BOOST_STATIC_ASSERT((is_same<DL1,DL2>::value == true));
    typedef DL2 type;
};

/// Multiply two dimension sequences.
template<typename DL1,typename DL2>
struct static_multiply
{
    typedef typename detail::merge_dimensions<DL1,DL2>::type type;
};

/// Divide two dimension lists.
template<typename DL1,typename DL2> 
struct static_divide
{
    typedef typename detail::merge_dimensions<
        DL1,
        typename detail::static_inverse_impl<
            mpl::size<DL2>::value
        >::template apply<
            typename mpl::begin<DL2>::type
        >::type
    >::type type;
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

/// A utility class for defining fundamental dimensions.
template<class DT>
struct fundamental_dimension
{
    typedef typename make_dimension_list< boost::mpl::list< dim< DT,static_rational<1> > > >::type    type;
};

/// A utility class for defining composite dimensions with integer powers.
template<class DT1 = dimensionless_type,int E1 = 0,
         class DT2 = dimensionless_type,int E2 = 0,
         class DT3 = dimensionless_type,int E3 = 0,
         class DT4 = dimensionless_type,int E4 = 0,
         class DT5 = dimensionless_type,int E5 = 0,
         class DT6 = dimensionless_type,int E6 = 0,
         class DT7 = dimensionless_type,int E7 = 0,
         class DT8 = dimensionless_type,int E8 = 0>
struct composite_dimension
{
    typedef typename 
    make_dimension_list< boost::mpl::list< dim< DT1,static_rational<E1> >,
                                           dim< DT2,static_rational<E2> >,
                                           dim< DT3,static_rational<E3> >,
                                           dim< DT4,static_rational<E4> >,
                                           dim< DT5,static_rational<E5> >,
                                           dim< DT6,static_rational<E6> >,
                                           dim< DT7,static_rational<E7> >,
                                           dim< DT8,static_rational<E8> > > >::type type;
};

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_DIMENSION_HPP
