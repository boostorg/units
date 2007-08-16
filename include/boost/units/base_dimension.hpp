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
/// INTERNAL ONLY
template<long N> struct base_dimension_ordinal { };

/// INTERNAL ONLY
template<class T, long N> struct base_dimension_pair { };

/// INTERNAL ONLY
template<class T, long N>
struct check_base_dimension {
    enum {
        value = 
            sizeof(boost_units_is_registered(units::base_dimension_ordinal<N>())) == sizeof(detail::yes) &&
            sizeof(boost_units_is_registered(units::base_dimension_pair<T, N>())) != sizeof(detail::yes)
    };
};

/// Defines a base dimension.  To define a dimension you need to provide
/// the derived class (CRTP) and a unique integer.
/// struct my_dimension : boost::units::base_dimension<my_dimension, 1> {};
/// It is designed so that you will get an error message if you try
/// to use the same value in multiple definitions.
template<class Derived,
         long N
#ifndef BOOST_UNITS_DOXYGEN
         ,
         class = typename detail::ordinal_has_already_been_defined<
             check_base_dimension<Derived, N>::value
         >::type
#endif
>
class base_dimension : 
    public mpl::long_<N> 
{
    public:
        typedef base_dimension                                                          this_type;
        typedef dimension_list<dim<Derived,static_rational<1> >, dimensionless_type>    type;

    private:
        /// Register this ordinal
        /// INTERNAL ONLY
        friend detail::yes 
        boost_units_is_registered(const units::base_dimension_ordinal<N>&) 
        { return(detail::yes()); }
        
        /// But make sure we can identify the current instantiation!
        /// INTERNAL ONLY
        friend detail::yes 
        boost_units_is_registered(const units::base_dimension_pair<Derived, N>&) 
        { return(detail::yes()); }
};

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_BASE_DIMENSION_HPP
