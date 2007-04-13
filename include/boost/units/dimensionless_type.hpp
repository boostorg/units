// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_DIMENSIONLESS_TYPE_HPP
#define BOOST_UNITS_DIMENSIONLESS_TYPE_HPP

#include <boost/mpl/long.hpp>

#include <boost/units/detail/dimension_impl.hpp>

namespace boost {

namespace units {

/// Dimension lists in which all exponents resolve to zero reduce to @c dimensionless_type.
struct dimensionless_type
{
    typedef dimensionless_type          type;
    typedef detail::dimension_list_tag  tag;
    typedef mpl::long_<0>               size;
};

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_DIMENSIONLESS_TYPE_HPP