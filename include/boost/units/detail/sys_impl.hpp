// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_SYS_IMPL_HPP
#define BOOST_UNITS_SYS_IMPL_HPP

#include <boost/mpl/bool_fwd.hpp>
#include <boost/mpl/less.hpp>

#include <boost/units/static_rational.hpp>

/// \file 
/// \brief Class encapsulating a dimension tag/value pair

namespace boost {

namespace units {

/// \brief System tag/dimension tag pair
///
/// \detailed 
/// The sys class represents a single system tag/dimension tag pair.
/// That is, @c sys<sys_tag,dim_tag> is a pair where @c sys_tag represents the
/// unit system  and @c dim_tag  represents the dimension corresponding to that
/// system. Both @c system_tag_type and @c dimension_tag_type must provide an ordinal
/// value to allow sorting of lists of dims at compile-time, which can be 
/// easily accomplished by inheriting from the @c ordinal class. 
template<typename ST,typename DT> 
struct sys
{
    typedef ST    system_tag_type;
    typedef DT    dimension_tag_type;
};

namespace detail {

template<typename ST1,typename DT1,typename ST2,typename DT2>
struct less< sys<ST1,DT1>,dim<ST2,DT2> > :
    mpl::if_<mpl::less<typename DT1::value,typename DT2::value>,
             mpl::true_,
             mpl::less<typename ST1::value,typename ST2::value> >
{ };

/// extract @c tag_type from a @c dim
template<typename T>
struct get_system_tag
{
    typedef typename T::system_tag_type     type;
};

/// extract @c value_type from a @c dim
template<typename T>
struct get_dimension_tag
{
    typedef typename T::dimension_tag_type  type;
};

} // namespace detail

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_SYS_IMPL_HPP
