/// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_UNIT_IMPL_HPP
#define BOOST_UNITS_UNIT_IMPL_HPP

#include <boost/mpl/begin.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/bool.hpp>

#include <boost/units/operators.hpp>
#include <boost/units/system.hpp>
#include <boost/units/detail/conversion_impl.hpp>

namespace boost {

namespace units {

template<class Dim,class System> class unit;

namespace detail {

// check if implicit conversion is allowed between homogeneous systems
template<int N>
struct implicit_conversion_homo_to_homo_impl
{
    template<class Begin, class system1_type, class system2_type>
    struct apply
    {
        typedef typename detail::get_tag<typename mpl::deref<Begin>::type>::type        dim_tag_type;
        typedef typename detail::get_value<typename mpl::deref<Begin>::type>::type      value_type;
        typedef typename mpl::next<Begin>::type                                         next;

        typedef typename detail::get_system_tag_of_dim<system1_type,dim_tag_type>::type system1_tag_type;
        typedef typename detail::get_system_tag_of_dim<system2_type,dim_tag_type>::type system2_tag_type;
        
        typedef base_unit_is_implicitly_convertible<dim_tag_type,
                                                    system1_tag_type,
                                                    system2_tag_type>                   convertible_type;
        
        typedef typename implicit_conversion_homo_to_homo_impl<N - 1>::template 
            apply<next, system1_type, system2_type>                                     next_iteration;

        static const bool   value = convertible_type::value && next_iteration::value;
    };
};

template<>
struct implicit_conversion_homo_to_homo_impl<0>
{
    template<class Begin, class system1_type, class system2_type>
    struct apply
    {
        typedef one type;
        
        static const bool   value = true;
    };
};

// check if implicit conversion is allowed between homogeneous and heterogeneous systems
// NB UNTESTED
template<int N>
struct implicit_conversion_homo_to_hetero_impl
{
    template<class Begin, class system1_type>
    struct apply
    {
        typedef homogeneous_system<typename detail::get_tag<typename mpl::deref<Begin>::type>::type>    system2_type;
        typedef typename detail::get_value<typename mpl::deref<Begin>::type>::type                      value_type;

        typedef typename mpl::next<Begin>::type                                                         next;
        typedef typename mpl::begin<value_type>::type                                                   begin;

        typedef typename implicit_conversion_homo_to_homo_impl<mpl::size<value_type>::value>::template 
            apply<begin, system1_type, system2_type>                                                    convert_system;
            
        typedef typename implicit_conversion_homo_to_hetero_impl<N - 1>::template 
            apply<next, system1_type>                                                                   next_iteration;

        static const bool   value = convert_system::value && next_iteration::value;
    };
};

template<>
struct implicit_conversion_homo_to_hetero_impl<0>
{
    template<class Begin, class system1_type, class system2_type>
    struct apply
    {
        typedef one type;
        
        static const bool   value = true;
    };
};

// check if implicit conversion is allowed between homogeneous and heterogeneous systems
/// NB UNTESTED
template<int N>
struct implicit_conversion_hetero_to_homo_impl
{
    template<class Begin, class system2_type>
    struct apply
    {
        typedef homogeneous_system<typename detail::get_tag<typename mpl::deref<Begin>::type>::type>    system1_type;
        typedef typename detail::get_value<typename mpl::deref<Begin>::type>::type                      value_type;

        typedef typename mpl::next<Begin>::type                                                         next;
        typedef typename mpl::begin<value_type>::type                                                   begin;

        typedef typename implicit_conversion_homo_to_homo_impl<mpl::size<value_type>::value>::template 
            apply<begin, system1_type, system2_type>                                                    convert_system;
        
        typedef typename implicit_conversion_hetero_to_homo_impl<N - 1>::template 
            apply<next, system2_type>                                                                   next_iteration;

        static const bool   value = convert_system::value && next_iteration::value;
    };
};

template<>
struct implicit_conversion_hetero_to_homo_impl<0>
{
    template<class Begin, class system1_type, class system2_type>
    struct apply
    {
        typedef one type;
        
        static const bool   value = true;
    };
};

} // namespace detail

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_UNIT_IMPL_HPP
