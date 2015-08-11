// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
// Copyright (C) 2015 Michael William Powell
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_SI_DRAG_FACTOR_HPP
#define BOOST_UNITS_SI_DRAG_FACTOR_HPP

#include <boost/units/systems/si/base.hpp>
#include <boost/units/physical_dimensions/drag_factor.hpp>

namespace boost {

namespace units { 

namespace si {

typedef unit<drag_factor_dimension,si::system>  drag_factor;

BOOST_UNITS_STATIC_CONSTANT(dragfactor, drag_factor);

// "K"

} // namespace si

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_SI_DRAG_FACTOR_HPP
