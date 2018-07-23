// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2007-2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_IMPERIAL_FOOT_BASE_UNIT_HPP
#define BOOST_UNITS_IMPERIAL_FOOT_BASE_UNIT_HPP

#include <boost/units/scaled_base_unit.hpp>
#include <boost/units/static_rational.hpp>
#include <boost/units/scale.hpp>
#include <boost/units/base_units/imperial/yard.hpp>
#include <boost/units/systems/single_unit_system.hpp>

namespace boost {

namespace units {

namespace imperial {

typedef scaled_base_unit<yard_base_unit, scale<3, static_rational<-1> > > foot_base_unit;

} // namespace imperial

template<>
struct base_unit_info<imperial::foot_base_unit> {
    static BOOST_CONSTEXPR const char* name()   { return("foot"); }
    static BOOST_CONSTEXPR const char* symbol() { return("ft"); }
};

} // namespace units

} // namespace boost

BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(imperial, foot, length)

#endif // BOOST_UNITS_IMPERIAL_FOOT_BASE_UNIT_HPP
