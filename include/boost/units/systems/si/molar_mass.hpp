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

#ifndef BOOST_UNITS_SI_MOLAR_MASS_HPP
#define BOOST_UNITS_SI_MOLAR_MASS_HPP

#include <boost/units/systems/si/base.hpp>
#include <boost/units/physical_dimensions/molar_mass.hpp>

namespace boost {

namespace units { 

namespace si {

typedef unit<molar_mass_dimension,si::system>  molar_mass;

BOOST_UNITS_STATIC_CONSTANT(kilogram_per_mole, molar_mass);
BOOST_UNITS_STATIC_CONSTANT(kilograms_per_mole, molar_mass);
BOOST_UNITS_STATIC_CONSTANT(kilogramme_per_mole, molar_mass);
BOOST_UNITS_STATIC_CONSTANT(kilogrammes_per_mole, molar_mass);

} // namespace si

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_SI_MASS_DENSITY_HPP
