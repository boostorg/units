// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_ORDINAL_HPP
#define BOOST_UNITS_ORDINAL_HPP

#include <boost/mpl/long.hpp>

#include <boost/units/config.hpp>

namespace boost {

namespace units {

/// Class for defining a cardinal ordering of tags to faciliate compile-time sorting.
template<long N> struct ordinal { typedef typename boost::mpl::long_<N> value; };

} // namespace units

} // namespace boost

#if BOOST_UNITS_HAS_BOOST_TYPEOF

#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

BOOST_TYPEOF_REGISTER_TEMPLATE(boost::units::ordinal, (long))

#endif

#endif // BOOST_UNITS_ORDINAL_HPP