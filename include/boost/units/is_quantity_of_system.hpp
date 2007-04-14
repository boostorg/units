// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_IS_QUANTITY_OF_SYSTEM_HPP
#define BOOST_UNITS_IS_QUANTITY_OF_SYSTEM_HPP

#include <boost/mpl/bool.hpp>
#include <boost/units/units_fwd.hpp>

namespace boost {

namespace units {

/// check that a type is a quantity in a specified system
template<class T,class System>
struct is_quantity_of_system :
    public mpl::false_
{ };

template<class Dim,
         class System,
         class Y>
struct is_quantity_of_system< quantity< unit<Dim,System>,Y>,System > :
    public mpl::true_
{ };

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_IS_QUANTITY_OF_SYSTEM_HPP
