// Boost.Units - A C++ library for zero-overhead dimensional analysis and
// unit/quantity manipulation and conversion
//
// Copyright (C) 2018 Eisuke Kawashima
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_CHARGE_DENSITY_DERIVED_DIMENSION_HPP
#define BOOST_UNITS_CHARGE_DENSITY_DERIVED_DIMENSION_HPP

#include <boost/units/derived_dimension.hpp>
#include <boost/units/physical_dimensions/length.hpp>
#include <boost/units/physical_dimensions/time.hpp>
#include <boost/units/physical_dimensions/current.hpp>

namespace boost {

namespace units {

/// derived dimension for charge density : L^-3 T I
typedef derived_dimension<length_base_dimension,-3,
                          time_base_dimension,1,
                          current_base_dimension,1>::type charge_density_dimension;

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_CHARGE_DENSITY_DERIVED_DIMENSION_HPP
