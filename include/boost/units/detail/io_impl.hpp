// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_IO_IMPL_HPP
#define BOOST_UNITS_IO_IMPL_HPP

#include <iosfwd>
#include <string>

#include <boost/config.hpp>

#include <boost/units/quantity.hpp>

namespace boost {

namespace units { 

template<class Tag, class System> struct base_unit_info;

namespace detail {

template<bool positive>
struct static_rational_print_impl;

template<>
struct static_rational_print_impl<true>
{
    template<class Char, class Traits, integer_type N>
    static void apply(std::basic_ostream<Char, Traits>& os,const static_rational<N>&)
    {
        os << N;
    }
};

template<>
struct static_rational_print_impl<false>
{
    template<class Char, class Traits, integer_type N>
    static void apply(std::basic_ostream<Char, Traits>& os,const static_rational<N>&)
    {
        os << '(' << N << ')';
    }
};

template<class Os, class Char, class Traits, class Allocator>
void print_string(Os& os, const std::basic_string<Char, Traits, Allocator>& s) 
{
    os << s.c_str();
}

template<class Os, class Char>
void print_string(Os& os, const char* s) 
{
    os << s;
}

template<int N>
struct unit_output_helper
{
    template<class System, class Os, class Begin>
    static void apply(Os& os, Begin)
    {
        typedef typename mpl::deref<Begin>::type                                    D;
        typedef typename detail::get_tag<D>::type                                   dim_tag_type;
        typedef typename detail::get_value<D>::type                                 value_type;
        typedef typename detail::get_system_tag_of_dim<System,dim_tag_type>::type   system_tag_type;
        
        typedef base_unit_info<dim_tag_type,system_tag_type>      m_type;

        detail::print_string(os, m_type::symbol());
        
        if (!boost::is_same<value_type, static_rational<1> >())
        {
            os << '^' << value_type();
        }
        
        os << ' ';

        unit_output_helper<N - 1>::template apply<System>(os, typename mpl::next<Begin>::type());
    }
};

template<>
struct unit_output_helper<1>
{
    template<class System, class Os, class Begin>
    static void apply(Os& os, Begin)
    {
        typedef typename mpl::deref<Begin>::type                                    D;
        typedef typename detail::get_tag<D>::type                                   dim_tag_type;
        typedef typename detail::get_value<D>::type                                 value_type;
        typedef typename detail::get_system_tag_of_dim<System,dim_tag_type>::type   system_tag_type;
        
        typedef base_unit_info<dim_tag_type,system_tag_type>      m_type;

        detail::print_string(os, m_type::symbol());
        
        if (!boost::is_same<value_type, static_rational<1> >())
        {
            os << '^' << value_type();
        }
    }
};

template<>
struct unit_output_helper<0>
{
    //should never be called
};

template<int N>
struct heterogeneous_unit_output_helper
{
    template<class Os, class Begin>
    static void apply(Os& os, Begin)
    {
        typedef typename mpl::deref<Begin>::type D;
        typedef homogeneous_system<typename detail::get_tag<D>::type> System;
        typedef typename detail::get_value<D>::type value_type;
        
        typedef typename mpl::begin<value_type>::type begin;

        unit_output_helper<mpl::size<value_type>::value>::template apply<System>(os, begin());
        
        os << ' ';

        heterogeneous_unit_output_helper<N - 1>::template apply(os, typename mpl::next<Begin>::type());
    }
};

template<>
struct heterogeneous_unit_output_helper<1>
{
    template<class Os, class Begin>
    static void apply(Os& os, Begin)
    {
        typedef typename mpl::deref<Begin>::type D;
        typedef homogeneous_system<typename detail::get_tag<D>::type> System;
        typedef typename detail::get_value<D>::type value_type;
        
        typedef typename mpl::begin<value_type>::type begin;

        unit_output_helper<mpl::size<value_type>::value>::template apply<System>(os, begin());
    }
};

template<>
struct heterogeneous_unit_output_helper<0>
{
    //should never be called
};

template<class Char, class Traits, class System,class Dim>
void output_impl(std::basic_ostream<Char, Traits>& os,const unit<Dim,System>&)
{
    unit_output_helper<mpl::size<Dim>::value>::template apply<System>(
        os, typename mpl::begin<Dim>::type());
}

template<class Char, class Traits, class System,class Dim>
void output_impl(std::basic_ostream<Char, Traits>& os,const unit<Dim,heterogeneous_system<System> >&)
{
    heterogeneous_unit_output_helper<mpl::size<typename heterogeneous_system<System>::type>::value>::template apply(
        os, typename mpl::begin<typename heterogeneous_system<System>::type>::type());
}

template<class Char, class Traits, class System>
void output_impl(std::basic_ostream<Char, Traits>& os,const unit<dimensionless_type,homogeneous_system<System> >&)
{
    os << "dimensionless";
}

} // namespace detail

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_IO_IMPL_HPP
