// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_SYSTEM_IMPL_HPP
#define BOOST_UNITS_SYSTEM_IMPL_HPP

#include <boost/mpl/begin.hpp>
#include <boost/mpl/bool_fwd.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/less.hpp>
#include <boost/mpl/size.hpp>

#include <boost/units/dim.hpp>

namespace boost {

namespace units {

/// Homogeneous unit system (unit system with all fundamental dimensions
/// measured in the same system of units).
template<class S> 
struct homogeneous_system
{ 
    typedef S   type;
};

/// Heterogeneous unit system (unit system in which fundamental dimensions
/// may be measured in different systems of units and fundamental dimensions
/// may be repeated for multiple systems). 
template<class S> 
struct heterogeneous_system
{ 
    typedef typename S::system_type type;
    typedef typename S::dimension_type dimension;
};

template<class UnitList, class Dimensions>
struct heterogeneous_system_pair
{
    typedef UnitList system_type;
    typedef Dimensions dimension_type;
};

namespace detail {

struct heterogeneous_system_element_tag {};

}

template<class System, class Dimensions>
struct heterogeneous_system_element
{
    typedef heterogeneous_system_element type;
    typedef detail::heterogeneous_system_element_tag tag;
    typedef System      tag_type;
    typedef Dimensions  value_type;
};

}

}

#if BOOST_UNITS_HAS_BOOST_TYPEOF

#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

BOOST_TYPEOF_REGISTER_TEMPLATE(boost::units::homogeneous_system, 1)
BOOST_TYPEOF_REGISTER_TEMPLATE(boost::units::heterogeneous_system, 1)
BOOST_TYPEOF_REGISTER_TEMPLATE(boost::units::heterogeneous_system_pair, 2)
BOOST_TYPEOF_REGISTER_TEMPLATE(boost::units::heterogeneous_system_element, 2)

#endif

namespace boost {

namespace units {

namespace detail {

template<class S,class DT> struct get_system_tag_of_dim;

template<class S,class DT>
struct get_system_tag_of_dim< homogeneous_system<S>,DT >
{
    // this will need to check if DT is in the system
    typedef typename homogeneous_system<S>::type    type;
};

template<class T1,class V1,class T2,class V2>
struct less< heterogeneous_system_element<T1,V1>,heterogeneous_system_element<T2,V2> >
{
    typedef typename boost::mpl::less<typename T1::value,typename T2::value>::type  type;
    
    static const bool   value = boost::is_same<type,boost::mpl::true_>::value;
};

template<class System, class L>
struct is_empty_dim<heterogeneous_system_element<System, L> > :
    boost::mpl::false_ 
{ };

template<class System>
struct is_empty_dim<heterogeneous_system_element<System, dimensionless_type> > :
    boost::mpl::true_ 
{ };

template<class System, class Dimension>
struct check_system : mpl::true_
{
};

template<class System, class Dim1, class Dim2>
struct check_system<heterogeneous_system<heterogeneous_system_pair<System, Dim1> >, Dim2> : mpl::false_
{
};

template<class System, class Dim1>
struct check_system<heterogeneous_system<heterogeneous_system_pair<System, Dim1> >, Dim1> : mpl::true_
{
};

template<bool one_system>
struct make_system;

template<>
struct make_system<false>
{
    template<class L, class Dimension>
    struct apply
    {
        typedef heterogeneous_system<heterogeneous_system_pair<L, Dimension> > type;
    };
};

template<>
struct make_system<true>
{
    template<class L, class Dimension>
    struct apply
    {
        typedef homogeneous_system<typename detail::get_tag<typename mpl::front<L>::type>::type> type;
    };
};

template<class S1, class S2>
struct multiply_systems
{
    typedef typename detail::merge_dimensions<typename S1::type, typename S2::type>::type   type1;
    typedef typename mpl::times<typename S1::dimension, typename S2::dimension>::type dimension;
    typedef typename make_system<mpl::size<type1>::value == 1>::template apply<type1,dimension>::type type;
};

template<class S1, class S2>
struct divide_systems
{
    typedef typename S2::type                                                       s2;
    typedef typename detail::static_inverse_impl<mpl::size<s2>::value>::template 
        apply<typename mpl::begin<s2>::type>::type                                  inverse;
    typedef typename detail::merge_dimensions<typename S1::type, inverse>::type     type1;
    typedef typename mpl::divides<typename S1::dimension, typename S2::dimension>::type dimension;
    typedef typename make_system<mpl::size<type1>::value == 1>::template apply<type1, dimension>::type type;
};

} // namespace detail

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_SYSTEM_IMPL_HPP
