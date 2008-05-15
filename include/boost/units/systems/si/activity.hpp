// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_SI_ACTIVITY_HPP
#define BOOST_UNITS_SI_ACTIVITY_HPP

#include <boost/units/systems/si/base.hpp>
#include <boost/units/systems/physical_dimensions/activity.hpp>

namespace boost {

namespace units { 

namespace SI {

typedef unit<activity_dimension,SI::system>  activity;

BOOST_UNITS_STATIC_CONSTANT(becquerel,activity);
BOOST_UNITS_STATIC_CONSTANT(becquerels,activity);

} // namespace SI

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_SI_ACTIVITY_HPP
