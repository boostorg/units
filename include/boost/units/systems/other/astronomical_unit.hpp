// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007-2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNIT_SYSTEMS_OTHER_ASTRONOMICAL_UNIT_HPP_INCLUDED
#define BOOST_UNIT_SYSTEMS_OTHER_ASTRONOMICAL_UNIT_HPP_INCLUDED

#include <boost/units/systems/detail/non_si_unit.hpp>
#include <boost/units/systems/base_units/meter.hpp>

// TODO: what is the symbol???
BOOST_UNITS_NON_SI_UNIT(astronomical, astronomical_unit, astronomical_unit, 149597870691.0, meter_base_unit, 0);

#endif
