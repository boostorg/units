// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2007-2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNIT_SYSTEMS_OTHER_MINIM_HPP_INCLUDED
#define BOOST_UNIT_SYSTEMS_OTHER_MINIM_HPP_INCLUDED

#include <boost/units/systems/detail/non_si_unit.hpp>
#include <boost/units/systems/si/volume.hpp>

BOOST_UNITS_NON_SI_UNIT(us, minim, "minim", "minim", 6.161152e-8, SI::volume, 19);

//#include <boost/units/scaled_base_unit.hpp>
//#include <boost/units/static_rational.hpp>
//#include <boost/units/scale.hpp>
//#include <boost/units/units_fwd.hpp>
//#include <boost/units/systems/us/fluid_ounce.hpp>
//
//namespace boost {
//namespace units {
//namespace us {
//
//typedef scaled_base_unit<fluid_ounce_base_unit, scale<480, static_rational<-1> > > minim_base_unit; //9.463529e-4*cubic_meters
//
//}
//
//template<>
//struct base_unit_info<us::minim_base_unit> {
//    static const char* name() { return("minim"); }
//    static const char* symbol() { return("minim"); }
//};
//
//}

#endif
