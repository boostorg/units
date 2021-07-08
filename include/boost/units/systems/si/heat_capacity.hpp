// Boost.Units - A C++ library for zero-overhead dimensional analysis and
// unit/quantity manipulation and conversion
//
// Copyright (C) 2018 Eisuke Kawashima
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_SI_HEAT_CAPACITY_HPP
#define BOOST_UNITS_SI_HEAT_CAPACITY_HPP

#include <boost/units/systems/si/base.hpp>
#include <boost/units/physical_dimensions/heat_capacity.hpp>

namespace boost {

namespace units {

namespace si {

typedef unit<heat_capacity_dimension,si::system> heat_capacity;

} // namespace si

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_SI_HEAT_CAPACITY_HPP
