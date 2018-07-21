// Boost.Units - A C++ library for zero-overhead dimensional analysis and
// unit/quantity manipulation and conversion
//
// Copyright (C) 2018 Eisuke Kawashima
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_AMOUNT_CONCENTRATION_DERIVED_DIMENSION_HPP
#define BOOST_UNITS_AMOUNT_CONCENTRATION_DERIVED_DIMENSION_HPP

#include <boost/units/derived_dimension.hpp>
#include <boost/units/physical_dimensions/length.hpp>
#include <boost/units/physical_dimensions/amount.hpp>

namespace boost {

namespace units {

/// derived dimension for amount concentration : L^-3 N
typedef derived_dimension<length_base_dimension,-3,
                          amount_base_dimension,1>::type amount_concentration_dimension;

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_AMOUNT_CONCENTRATION_DERIVED_DIMENSION_HPP