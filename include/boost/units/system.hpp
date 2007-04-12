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

} // namespace units

namespace mpl {

template<>
struct plus_impl<boost::units::detail::heterogeneous_system_element_tag, boost::units::detail::heterogeneous_system_element_tag>
{
    template<class T0, class T1>
    struct apply {
        BOOST_STATIC_ASSERT((boost::is_same<typename T0::tag_type, typename T1::tag_type>::value == true));
        typedef boost::units::heterogeneous_system_element<typename T0::tag_type, typename times<typename T0::value_type, typename T1::value_type>::type> type;
    };
};

template<>
struct negate_impl<boost::units::detail::heterogeneous_system_element_tag>
{
    template<class T0>
    struct apply {
        typedef typename boost::units::detail::static_inverse_impl<
            mpl::size<typename T0::value_type>::value
        >::template apply<typename mpl::begin<typename T0::value_type>::type>::type inverse;
        typedef boost::units::heterogeneous_system_element<typename T0::tag_type, inverse> type;
    };
};

} // namespace mpl

namespace units {

template<class System, class Dimensions>
struct heterogeneous_system_view
{
    typedef typename mpl::push_front<dimensionless_type, heterogeneous_system_element<System, Dimensions> >::type type;
    typedef Dimensions dimension;
};

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_SYSTEM_HPP
