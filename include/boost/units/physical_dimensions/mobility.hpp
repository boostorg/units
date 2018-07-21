// Boost.Units - A C++ library for zero-overhead dimensional analysis and
// unit/quantity manipulation and conversion
//
// Copyright (C) 2018 Eisuke Kawashima
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_MOBILITY_DERIVED_DIMENSION_HPP
#define BOOST_UNITS_MOBILITY_DERIVED_DIMENSION_HPP

#include <boost/units/derived_dimension.hpp>
#include <boost/units/physical_dimensions/mass.hpp>
#include <boost/units/physical_dimensions/time.hpp>
#include <boost/units/physical_dimensions/current.hpp>

namespace boost {

namespace units {
/// derived dimension for mobility : M^-1 T^2 I
typedef derived_dimension<mass_base_dimension,-1,
                          time_base_dimension,2,
                          current_base_dimension,1>::type mobility_dimension;

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_MOBILITY_DERIVED_DIMENSION_HPP
