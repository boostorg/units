// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007-2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNIT_SYSTEMS_OTHER_ARCDEGREE_HPP_INCLUDED
#define BOOST_UNIT_SYSTEMS_OTHER_ARCDEGREE_HPP_INCLUDED

#include <boost/units/systems/other/non_si_unit.hpp>
#include <boost/units/systems/base_units/radian.hpp>

BOOST_UNITS_NON_SI_UNIT(metric, arcdegree, argdegree, (3.14159265358979323846264338328/180), radian_base_unit, 7);

#endif
