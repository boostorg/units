// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_NON_SI_CONSTANTS_HPP
#define BOOST_UNITS_NON_SI_CONSTANTS_HPP

#error "this file uses the wrong types"

#include <boost/units/systems/si.hpp>

namespace boost {

namespace units { 

namespace SI {
                            
namespace constants {

namespace astronomical {

/// astronomical unit
BOOST_UNITS_STATIC_CONSTANT(astronomical_unit,length) = 149597870691*meters;
/// light day
BOOST_UNITS_STATIC_CONSTANT(light_day,length) = 2.59020683712e13*meters;
/// light_hour
BOOST_UNITS_STATIC_CONSTANT(light_hour,length) = 1.0792528488e12*meters;
/// light minute
BOOST_UNITS_STATIC_CONSTANT(light_minute,length) = 1.798754748e10*meters;
/// light second
BOOST_UNITS_STATIC_CONSTANT(light_second,length) = 2.99792458e8*meters;
/// light year
BOOST_UNITS_STATIC_CONSTANT(light_year,length) = 9.460730472580e15*meters;
/// parsec
BOOST_UNITS_STATIC_CONSTANT(parsec,length) = 3.0856775813e16*meters;

} // namespace astronomical

namespace english {

} // namespace english

namespace international {

/// cable (International)
BOOST_UNITS_STATIC_CONSTANT(cable,length) = 185.2*meters;
/// foot (International)
BOOST_UNITS_STATIC_CONSTANT(foot,length) = 0.3048*meters;
/// inch
BOOST_UNITS_STATIC_CONSTANT(inch,length) = 25.4e-3*meters;
/// mile
BOOST_UNITS_STATIC_CONSTANT(mile,length) = 1609.344*meters;
/// yard
BOOST_UNITS_STATIC_CONSTANT(yard,length) = 0.9144*meters;

} // namespace international

namespace imperial {

/// cable (Imperial)
BOOST_UNITS_STATIC_CONSTANT(cable,length) = 185.3184*meters;

} // namespace imperial

namespace nautical {

/// fathom (nautical)
BOOST_UNITS_STATIC_CONSTANT(fathom,length) = 1.852*meters;
/// league (nautical)
BOOST_UNITS_STATIC_CONSTANT(league,length) = 5556.0*meters;
/// mile (nautical)
BOOST_UNITS_STATIC_CONSTANT(mile,length) = 1852.0*meters;

} // namespace nautical

/// angstrom
BOOST_UNITS_STATIC_CONSTANT(angstrom,length) = 1.0e-10*meters;
/// atomic unit
BOOST_UNITS_STATIC_CONSTANT(atomic_unit,length) = 5.291772083e-11*meters;
/// barleycorn
BOOST_UNITS_STATIC_CONSTANT(barleycorn,length) = 8.466667e-3*meters;
/// Bohr radius
BOOST_UNITS_STATIC_CONSTANT(bohr_radius,length) = atomic_unit;
/// cable (US)
BOOST_UNITS_STATIC_CONSTANT(us_cable,length) = 219.456*meters;
/// calibre
BOOST_UNITS_STATIC_CONSTANT(calibre,length) = 25.4e-3*meters;
/// chain (surveyor's)
BOOST_UNITS_STATIC_CONSTANT(surveyors_chain,length) = 20.1168*meters;
/// chain (engineer's)
BOOST_UNITS_STATIC_CONSTANT(engineers_chain,length) = 30.48*meters;
/// cubit
BOOST_UNITS_STATIC_CONSTANT(cubit,length) = 0.4572*meters;
/// ell
BOOST_UNITS_STATIC_CONSTANT(ell,length) = 1.143*meters;
/// fathom
BOOST_UNITS_STATIC_CONSTANT(fathom,length) = 1.8288*meters;
/// fermi
BOOST_UNITS_STATIC_CONSTANT(fermi,length) = 1.0e-15*meters;
/// finger
BOOST_UNITS_STATIC_CONSTANT(finger,length) = 22.225e-3*meters;
/// finger (cloth)
BOOST_UNITS_STATIC_CONSTANT(cloth_finger,length) = 0.1143*meters;
/// foot (Benoit)
BOOST_UNITS_STATIC_CONSTANT(benoit_foot,length) = 0.304799735*meters;
/// foot (Clarke's)
BOOST_UNITS_STATIC_CONSTANT(clarkes_foot,length) = 0.3047972654*meters;
/// foot (Indian)
BOOST_UNITS_STATIC_CONSTANT(indian_foot,length) = 0.304799514*meters;
/// foot (Sear's)
BOOST_UNITS_STATIC_CONSTANT(sears_foot,length) = 0.30479947*meters;
/// foot (US Survey)
BOOST_UNITS_STATIC_CONSTANT(us_foot,length) = (1200.0/3937.0)*meters;
/// furlong
BOOST_UNITS_STATIC_CONSTANT(furlong,length) = 201.168*meters;
/// mile, geographical
BOOST_UNITS_STATIC_CONSTANT(geographical_mile,length) = 1853.7936*meters;
/// hand
BOOST_UNITS_STATIC_CONSTANT(hand,length) = 0.1016*meters;
/// league
BOOST_UNITS_STATIC_CONSTANT(league,length) = 4828.032*meters;
/// line
BOOST_UNITS_STATIC_CONSTANT(line,length) = 2.116667e-3*meters;
/// link (surveyor's)
BOOST_UNITS_STATIC_CONSTANT(surveyors_link,length) = 0.201168*meters;
/// link (engineer's)
BOOST_UNITS_STATIC_CONSTANT(engineers_link,length) = 0.3048*meters;
/// mickey
BOOST_UNITS_STATIC_CONSTANT(mickey,length) = 1.27e-4*meters;
/// micron
BOOST_UNITS_STATIC_CONSTANT(micron,length) = 1.0e-6*meters;
/// mil
BOOST_UNITS_STATIC_CONSTANT(mil,length) = 2.54e-5*meters;
/// mile (US survey)
BOOST_UNITS_STATIC_CONSTANT(mile_us,length) = 1609.347219*meters;
/// nail (cloth)
BOOST_UNITS_STATIC_CONSTANT(nail,length) = 57.15e-3*meters;
/// mile (Admiralty nautical)
BOOST_UNITS_STATIC_CONSTANT(admiralty_nautical_mile,length) = 1853.184*meters;
/// pace
BOOST_UNITS_STATIC_CONSTANT(pace,length) = 0.762*meters;
/// palm
BOOST_UNITS_STATIC_CONSTANT(palm,length) = 76.2e-3*meters;
/// point (ATA)
BOOST_UNITS_STATIC_CONSTANT(ata_point,length) = 0.3514598e-3*meters;
/// point (Didot)
BOOST_UNITS_STATIC_CONSTANT(didot_point,length) = 0.376065e-3*meters;
/// point (metric)
BOOST_UNITS_STATIC_CONSTANT(point,length) = 0.375e-3*meters;
/// point (PostScript)
BOOST_UNITS_STATIC_CONSTANT(postscript_point,length) = 0.352778e-3*meters;
/// quarter
BOOST_UNITS_STATIC_CONSTANT(quarter,length) = 0.2286*meters;
/// rod
BOOST_UNITS_STATIC_CONSTANT(rod,length) = 5.0292*meters;
/// rope
BOOST_UNITS_STATIC_CONSTANT(rope,length) = 6.096*meters;
/// span
BOOST_UNITS_STATIC_CONSTANT(span,length) = 0.1524*meters;
/// span (cloth)
BOOST_UNITS_STATIC_CONSTANT(cloth_span,length) = 0.2286*meters;
/// stick
BOOST_UNITS_STATIC_CONSTANT(stick,length) = 50.8e-3*meters;

} // constants                                                                                  

} // namespace SI

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_NON_SI_CONSTANTS_HPP
