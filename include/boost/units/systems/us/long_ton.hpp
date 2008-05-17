// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2007-2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNIT_SYSTEMS_OTHER_LONG_TON_HPP_INCLUDED
#define BOOST_UNIT_SYSTEMS_OTHER_LONG_TON_HPP_INCLUDED

//#include <boost/units/systems/detail/non_si_unit.hpp>
//#include <boost/units/systems/base_units/kilogram.hpp>
//
//BOOST_UNITS_DEFINE_BASE_UNIT_WITH_CONVERSIONS(us, long_ton, long_ton, 1.0160469088e3, kilogram_base_unit, 22);

#include <boost/units/scaled_base_unit.hpp>
#include <boost/units/static_rational.hpp>
#include <boost/units/scale.hpp>
#include <boost/units/units_fwd.hpp>
#include <boost/units/systems/us/avoirdupois_pound.hpp>

namespace boost {
namespace units {
namespace us {

typedef scaled_base_unit<avoirdupois_pound_base_unit, scale<2240, static_rational<1> > > long_ton_base_unit; //9.0718474e2*kilograms

}

template<>
struct base_unit_info<us::long_ton_base_unit> {
    static const char* name() { return("long ton"); }
    static const char* symbol() { return("long ton"); }
};

}
}

#endif
