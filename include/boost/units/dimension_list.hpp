// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_DIMENSION_LIST_HPP
#define BOOST_UNITS_DIMENSION_LIST_HPP

#include <boost/mpl/next.hpp>

#include <boost/units/config.hpp>

namespace boost {

namespace units {

namespace detail {

struct dimension_list_tag { };

} // namespace detail

template<class Item, class Next>
struct dimension_list
{
    typedef detail::dimension_list_tag  tag;
    typedef dimension_list              type;
    typedef Item                        item;
    typedef Next                        next;
    typedef typename mpl::next<typename Next::size>::type size;
};

} // namespace units

} // namespace boost

#if BOOST_UNITS_HAS_BOOST_TYPEOF

#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

BOOST_TYPEOF_REGISTER_TEMPLATE(boost::units::dimension_list, 2)

#endif

#endif // BOOST_UNITS_DIMENSION_LIST_HPP
