// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_BASE_DIMENSION_HPP
#define BOOST_UNITS_BASE_DIMENSION_HPP

#include <boost/mpl/long.hpp>

#include <boost/units/config.hpp>
#include <boost/units/static_rational.hpp>
#include <boost/units/dim.hpp>
#include <boost/units/dimension_list.hpp>
#include <boost/units/units_fwd.hpp>

namespace boost {

namespace units {

namespace detail {

typedef char no;
struct yes { no dummy[2]; };

template<bool>
struct ordinal_has_already_been_defined;

template<>
struct ordinal_has_already_been_defined<true> {};

template<>
struct ordinal_has_already_been_defined<false> { typedef void type; };

}

/// This must be in namespace boost::units so that ADL
/// will work with friend functions defined inline.
/// INTERNAL ONLY
template<long N>
struct long_ {};

/// Ditto.
/// INTERNAL ONLY
template<class T, long N>
struct base_dimension_pair {};

/// Again this needs to be in the same namespace as long_
/// we need a mangled name because it must be found by ADL
/// INTERNAL ONLY
template<class T>
detail::no boost_units_prevent_double_definition(const T&) { return(detail::no()); }

/// Defines a base dimension.  To define a dimension you need to provide
/// the derived class (CRTP) and a unique integer.
/// struct my_dimension : boost::units::base_dimension<my_dimension, 1> {};
/// It is designed so that you will get an error message if you try
/// to use the same value in multiple definitions.
template<class Derived,
         long N,
         class = typename detail::ordinal_has_already_been_defined<
             sizeof(boost_units_prevent_double_definition(units::long_<N>())) == sizeof(detail::yes) &&
             sizeof(boost_units_prevent_double_definition(units::base_dimension_pair<Derived, N>())) != sizeof(detail::yes)
         >::type>
struct base_dimension : mpl::long_<N> {
    /// Register this ordinal
    /// INTERNAL ONLY
    friend detail::yes boost_units_prevent_double_definition(const units::long_<N>&) { return(detail::yes()); }
    /// But make sure we can identify the current instantiation!
    /// INTERNAL ONLY
    friend detail::yes boost_units_prevent_double_definition(const units::base_dimension_pair<Derived, N>&) { return(detail::yes()); }
    typedef base_dimension this_type;
    typedef mpl::long_<N> value;
    typedef dimension_list<dim<Derived,static_rational<1> >, dimensionless_type> type;
};

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_BASE_DIMENSION_HPP
