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

#ifndef BOOST_UNITS_SPECIFIC_GAS_CONSTANT_DERIVED_DIMENSION_HPP
#define BOOST_UNITS_SPECIFIC_GAS_CONSTANT_DERIVED_DIMENSION_HPP

#include <boost/units/derived_dimension.hpp>
#include <boost/units/physical_dimensions/length.hpp>
#include <boost/units/physical_dimensions/time.hpp>
#include <boost/units/physical_dimensions/temperature.hpp>

//#include <boost/units/physical_dimensions/energy.hpp>
//#include <boost/units/physical_dimensions/mass.hpp>

namespace boost {

namespace units {

///// derived dimension for specific gas constant : J M^-1 Theta^-1
//typedef derived_dimension<energy_dimension,1,
//                          mass_base_dimension,-1,
//                          temperature_base_dimension,-1>::type specific_gas_constant_dimension;

/// derived dimension for specific gas constant : J M^-1 Theta^-1
/// which effectively reduces to                : L^-2 T^-2 Theta^-1
typedef derived_dimension<length_base_dimension,2,
                          temperature_base_dimension,-1,
                          time_base_dimension,-2>::type specific_gas_constant_dimension;

//typedef derived_dimension<energy_dimension, 1,
//                          mass_base_dimension, -1,
//                          temperature_base_dimension, -1>::type specific_gas_constant_dimension2;

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_SPECIFIC_GAS_CONSTANT_DERIVED_DIMENSION_HPP
