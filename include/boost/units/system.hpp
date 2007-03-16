// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_SYSTEM_HPP
#define BOOST_UNITS_SYSTEM_HPP

#include <boost/mpl/begin.hpp>
#include <boost/mpl/bool_fwd.hpp>
#include <boost/mpl/push_front.hpp>
#include <boost/mpl/size.hpp>

#include <boost/units/operators.hpp>
#include <boost/units/sys.hpp>
#include <boost/units/detail/system_impl.hpp>

namespace boost {

namespace units {

/// check if a class is a valid unit system
template<class S> struct is_system;

template<class S>
struct is_system< homogeneous_system<S> >
{
    typedef boost::mpl::true_   type;
    
    static const bool   value = true;
};

template<class S>
struct is_system< heterogeneous_system<S> >
{
    typedef boost::mpl::true_   type;
    
    static const bool   value = true;
};

/// check if a class is a homogeneous unit system
template<class S> struct is_homogeneous_system;

template<class S>
struct is_homogeneous_system< homogeneous_system<S> >
{
    typedef boost::mpl::true_   type;
    
    static const bool   value = true;
};

template<class S>
struct is_homogeneous_system< heterogeneous_system<S> >
{
    typedef boost::mpl::false_  type;
    
    static const bool   value = false;
};

/// check if a class is a heterogeneous unit system
template<class S> struct is_heterogeneous_system;

template<class S>
struct is_heterogeneous_system< homogeneous_system<S> >
{
    typedef boost::mpl::false_  type;
    
    static const bool   value = false;
};

template<class S>
struct is_heterogeneous_system< heterogeneous_system<S> >
{
    typedef boost::mpl::true_   type;
    
    static const bool   value = true;
};

template<class S1, class E1, class E2>
struct static_add<heterogeneous_system_element<S1, E1>, heterogeneous_system_element<S1, E2> >
{
    typedef heterogeneous_system_element<S1, typename static_multiply<E1, E2>::type> type;
};

template<class S1, class E1>
struct static_negate<heterogeneous_system_element<S1, E1> >
{
    typedef typename detail::static_inverse_impl<mpl::size<E1>::value>::template apply<typename mpl::begin<E1>::type>::type inverse;
    typedef heterogeneous_system_element<S1, inverse> type;
};

template<class System, class Dimensions>
struct heterogeneous_system_view
{
    typedef typename mpl::push_front<dimensionless_type, heterogeneous_system_element<System, Dimensions> >::type type;
    typedef Dimensions dimension;
};

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_SYSTEM_HPP
