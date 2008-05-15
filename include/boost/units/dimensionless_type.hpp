// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_DIMENSIONLESS_TYPE_HPP
#define BOOST_UNITS_DIMENSIONLESS_TYPE_HPP

#include <boost/mpl/long.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/arithmetic.hpp>

#include <boost/units/config.hpp>

namespace boost {

namespace units {

namespace detail {

struct dimension_list_tag;

}

/// Dimension lists in which all exponents resolve to zero reduce to @c dimensionless_type.
struct dimensionless_type
{
    typedef dimensionless_type          type;
    typedef detail::dimension_list_tag  tag;
    typedef mpl::long_<0>               size;
};

} // namespace units

#ifndef BOOST_UNITS_DOXYGEN

namespace mpl {

/// INTERNAL ONLY
template<> struct deref<units::dimensionless_type> { };

/// INTERNAL ONLY
template<>
struct plus<units::dimensionless_type, units::dimensionless_type>
{
    typedef units::dimensionless_type type;
};

/// INTERNAL ONLY
template<>
struct minus<units::dimensionless_type, units::dimensionless_type>
{
    typedef units::dimensionless_type type;
};

/// INTERNAL ONLY
template<>
struct times<units::dimensionless_type, units::dimensionless_type>
{
    typedef units::dimensionless_type type;
};

/// INTERNAL ONLY
template<>
struct divides<units::dimensionless_type, units::dimensionless_type>
{
    typedef units::dimensionless_type type;
};

/// INTERNAL ONLY
template<>
struct negate<units::dimensionless_type>
{
    typedef units::dimensionless_type type;
};

} // namespace mpl

#endif

} // namespace boost

#if BOOST_UNITS_HAS_BOOST_TYPEOF

#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

BOOST_TYPEOF_REGISTER_TYPE(boost::units::dimensionless_type)

#endif

#endif // BOOST_UNITS_DIMENSIONLESS_TYPE_HPP
