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

#ifndef BOOST_UNITS_SI_SPECIFIC_GAS_CONSTANT_HPP
#define BOOST_UNITS_SI_SPECIFIC_GAS_CONSTANT_HPP

#include <boost/units/systems/si/base.hpp>
#include <boost/units/physical_dimensions/specific_gas_constant.hpp>

namespace boost {

namespace units { 

namespace si {

typedef unit<specific_gas_constant_dimension,si::system>  specific_gas_constant;

BOOST_UNITS_STATIC_CONSTANT(joule_per_kilogram_kelvins, specific_gas_constant);
BOOST_UNITS_STATIC_CONSTANT(joules_per_kilogram_kelvins, specific_gas_constant);
BOOST_UNITS_STATIC_CONSTANT(joule_per_kilogramme_kelvins, specific_gas_constant);
BOOST_UNITS_STATIC_CONSTANT(joules_per_kilogrammes_kelvins, specific_gas_constant);

} // namespace si

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_SI_SPECIFIC_GAS_CONSTANT_HPP
