// Boost.Units - A C++ library for zero-overhead dimensional analysis and
// unit/quantity manipulation and conversion
//
// Copyright (C) 2018 Eisuke Kawashima
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_DIFFUSION_FLUX_DERIVED_DIMENSION_HPP
#define BOOST_UNITS_DIFFUSION_FLUX_DERIVED_DIMENSION_HPP

#include <boost/units/derived_dimension.hpp>
#include <boost/units/physical_dimensions/length.hpp>
#include <boost/units/physical_dimensions/time.hpp>
#include <boost/units/physical_dimensions/amount.hpp>

namespace boost {

namespace units {

/// derived dimension for diffusion flux : L^-2 T^-1 N
typedef derived_dimension<length_base_dimension,-2,
                          time_base_dimension,-1,
                          amount_base_dimension,1>::type diffusion_flux_dimension;

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_DIFFUSION_FLUX_DERIVED_DIMENSION_HPP