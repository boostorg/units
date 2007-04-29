// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_BASE_UNIT_HPP
#define BOOST_UNITS_BASE_UNIT_HPP

#include <boost/units/config.hpp>
#include <boost/units/dim.hpp>
#include <boost/units/dimension_list.hpp>
#include <boost/units/static_rational.hpp>
#include <boost/units/units_fwd.hpp>

#include <boost/units/detail/prevent_ordinal_redefinition_impl.hpp>

namespace boost {

namespace units {

/// This must be in namespace boost::units so that ADL
/// will work with friend functions defined inline.
/// Base dimensions and base units are independent.
/// INTERNAL ONLY
template<long N> struct base_unit_ordinal { };

/// INTERNAL ONLY
template<class T, long N> struct base_unit_pair { };

/// Defines a base dimension.  To define a unit you need to provide
/// the derived class (CRTP), a dimension list and a unique integer.
/// struct my_unit : boost::units::base_unit<my_dimension, length_type, 1> {};
/// It is designed so that you will get an error message if you try
/// to use the same value in multiple definitions.
template<class Derived,
         class Dim,
         long N,
         class = typename detail::ordinal_has_already_been_defined<
             sizeof(boost_units_is_registered(units::base_unit_ordinal<N>())) == sizeof(detail::yes) &&
             sizeof(boost_units_is_registered(units::base_unit_pair<Derived, N>())) != sizeof(detail::yes)
         >::type>
class base_unit : 
    public mpl::long_<N> 
{
    public:
        typedef base_unit           this_type;
        //typedef mpl::long_<N>       value;
        typedef Dim                 dimension_type;

    private:
        /// Register this ordinal
        /// INTERNAL ONLY
        friend detail::yes 
        boost_units_is_registered(const units::base_unit_ordinal<N>&) 
        { return(detail::yes()); }
        
        /// But make sure we can identify the current instantiation!
        /// INTERNAL ONLY
        friend detail::yes 
        boost_units_is_registered(const units::base_unit_pair<Derived, N>&) 
        { return(detail::yes()); }
};

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_BASE_UNIT_HPP
