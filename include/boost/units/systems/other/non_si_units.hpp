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

// SI conversion factors for various non-SI units

#include <boost/units/systems/si.hpp>

namespace boost {

namespace units { 

namespace SI {
                            
namespace constants {

// common astronomical units
namespace astronomical {

// units of length
BOOST_UNITS_STATIC_CONSTANT(astronomical_unit,length) = 149597870691.0*meters;
BOOST_UNITS_STATIC_CONSTANT(light_day,length) = 2.59020683712e13*meters;
BOOST_UNITS_STATIC_CONSTANT(light_hour,length) = 1.0792528488e12*meters;
BOOST_UNITS_STATIC_CONSTANT(light_minute,length) = 1.798754748e10*meters;
BOOST_UNITS_STATIC_CONSTANT(light_second,length) = 2.99792458e8*meters;
BOOST_UNITS_STATIC_CONSTANT(light_year,length) = 9.460730472580e15*meters;
BOOST_UNITS_STATIC_CONSTANT(parsec,length) = 3.0856775813e16*meters;

} // namespace astronomical

// British imperial units
namespace imperial {

} // namespace imperial

// non-SI metric units
namespace metric {

// units of length
BOOST_UNITS_STATIC_CONSTANT(angstrom,length) = 1.0e-10*meters;
BOOST_UNITS_STATIC_CONSTANT(angstroms,length) = 1.0e-10*meters;

BOOST_UNITS_STATIC_CONSTANT(fermi,length) = 1.0e-15*meters;
BOOST_UNITS_STATIC_CONSTANT(fermis,length) = 1.0e-15*meters;

BOOST_UNITS_STATIC_CONSTANT(micron,length) = 1.0e-6*meters;
BOOST_UNITS_STATIC_CONSTANT(microns,length) = 1.0e-6*meters;

// units of mass
BOOST_UNITS_STATIC_CONSTANT(ton,mass) = 1.0e3*kilograms;
BOOST_UNITS_STATIC_CONSTANT(tons,mass) = 1.0e3*kilograms;
BOOST_UNITS_STATIC_CONSTANT(tonne,mass) = 1.0e3*kilograms;
BOOST_UNITS_STATIC_CONSTANT(tonnes,mass) = 1.0e3*kilograms;

// units of time
BOOST_UNITS_STATIC_CONSTANT(day,time) = 86400.0*seconds;
BOOST_UNITS_STATIC_CONSTANT(days,time) = 86400.0*seconds;

BOOST_UNITS_STATIC_CONSTANT(hour,time) = 3600.0*seconds;
BOOST_UNITS_STATIC_CONSTANT(hours,time) = 3600.0*seconds;

BOOST_UNITS_STATIC_CONSTANT(minute,time) = 60.0*seconds;
BOOST_UNITS_STATIC_CONSTANT(minutes,time) = 60.0*seconds;

// units of planar angle
//BOOST_UNITS_STATIC_CONSTANT(arc_degree,angle) = (pi/180)*radians;
//BOOST_UNITS_STATIC_CONSTANT(arc_minute,angle) = (pi/10800)*radians;
//BOOST_UNITS_STATIC_CONSTANT(arc_second,angle) = (pi/648000)*radians;

// units of area
BOOST_UNITS_STATIC_CONSTANT(are,area) = 1.0e2*square_meters;
BOOST_UNITS_STATIC_CONSTANT(are,area) = 1.0e2*square_meters;

BOOST_UNITS_STATIC_CONSTANT(barn,area) = 1.0e-28*square_meters;
BOOST_UNITS_STATIC_CONSTANT(barns,area) = 1.0e-28*square_meters;

BOOST_UNITS_STATIC_CONSTANT(hectare,area) = 1.0e4*square_meters;
BOOST_UNITS_STATIC_CONSTANT(hectares,area) = 1.0e4*square_meters;

// units of volume
BOOST_UNITS_STATIC_CONSTANT(liter,volume) = 1.0e-3*cubic_meters;
BOOST_UNITS_STATIC_CONSTANT(liters,volume) = 1.0e-3*cubic_meters;
BOOST_UNITS_STATIC_CONSTANT(litre,volume) = 1.0e-3*cubic_meters;
BOOST_UNITS_STATIC_CONSTANT(litres,volume) = 1.0e-3*cubic_meters;

// units of pressure
BOOST_UNITS_STATIC_CONSTANT(bar,pressure) = 1.0e5*pascals;

} // namespace metric 

// nautical units
namespace nautical {

// units of length
BOOST_UNITS_STATIC_CONSTANT(fathom,length) = 1.852*meters;
BOOST_UNITS_STATIC_CONSTANT(fathoms,length) = 1.852*meters;

BOOST_UNITS_STATIC_CONSTANT(knot,velocity) = (1852.0/3600.0)*meters_per_second;
BOOST_UNITS_STATIC_CONSTANT(knots,velocity) = (1852.0/3600.0)*meters_per_second;

BOOST_UNITS_STATIC_CONSTANT(league,length) = 5556.0*meters;
BOOST_UNITS_STATIC_CONSTANT(leagues,length) = 5556.0*meters;

BOOST_UNITS_STATIC_CONSTANT(mile,length) = 1852.0*meters;
BOOST_UNITS_STATIC_CONSTANT(miles,length) = 1852.0*meters;

} // namespace nautical

// US customary units 
namespace us { 

// conversions from http://ts.nist.gov/WeightsAndMeasures/Publications/appxc.cfm#2

// units of length
BOOST_UNITS_STATIC_CONSTANT(inch,length) = 25.4e-3*meters;
BOOST_UNITS_STATIC_CONSTANT(inches,length) = 25.4e-3*meters;

BOOST_UNITS_STATIC_CONSTANT(foot,length) = 0.3048*meters;
BOOST_UNITS_STATIC_CONSTANT(feet,length) = 0.3048*meters;

BOOST_UNITS_STATIC_CONSTANT(yard,length) = 0.9144*meters;
BOOST_UNITS_STATIC_CONSTANT(yards,length) = 0.9144*meters;

BOOST_UNITS_STATIC_CONSTANT(mile,length) = 1609.344*meters;
BOOST_UNITS_STATIC_CONSTANT(miles,length) = 1609.344*meters;

// units of area
BOOST_UNITS_STATIC_CONSTANT(square_inch,area) = 645.16e-6*square_meters; 
BOOST_UNITS_STATIC_CONSTANT(square_inches,area) = 645.16e-6*square_meters;

BOOST_UNITS_STATIC_CONSTANT(square_foot,area) = 9.290304e-2*square_meters;
BOOST_UNITS_STATIC_CONSTANT(square_feet,area) = 9.290304e-2*square_meters;

BOOST_UNITS_STATIC_CONSTANT(square_yard,area) = 0.83612736*square_meters;
BOOST_UNITS_STATIC_CONSTANT(square_yards,area) = 0.83612736*square_meters;

BOOST_UNITS_STATIC_CONSTANT(square_mile,area) = 2589988.110336*square_meters;
BOOST_UNITS_STATIC_CONSTANT(square_miles,area) = 2589988.110336*square_meters;

// units of volume
BOOST_UNITS_STATIC_CONSTANT(cubic_inch,volume) = 16.387064e-6*cubic_meters;
BOOST_UNITS_STATIC_CONSTANT(cubic_inches,volume) = 16.387064e-6*cubic_meters;

BOOST_UNITS_STATIC_CONSTANT(cubic_foot,volume) = 2.8316846592e-2*cubic_meters;
BOOST_UNITS_STATIC_CONSTANT(cubic_feet,volume) = 2.8316846592e-2*cubic_meters;

BOOST_UNITS_STATIC_CONSTANT(cubic_yard,volume) = 0.764554857984*cubic_meters;
BOOST_UNITS_STATIC_CONSTANT(cubic_yards,volume) = 0.764554857984*cubic_meters;

BOOST_UNITS_STATIC_CONSTANT(minim,volume) = 6.161152e-8*cubic_meters;
BOOST_UNITS_STATIC_CONSTANT(minims,volume) = 6.161152e-8*cubic_meters;

BOOST_UNITS_STATIC_CONSTANT(fluid_dram,volume) = 3.696691e-6*cubic_meters;
BOOST_UNITS_STATIC_CONSTANT(fluid_drams,volume) = 3.696691e-6*cubic_meters;

BOOST_UNITS_STATIC_CONSTANT(fluid_ounce,volume) = 2.957353e-5*cubic_meters;
BOOST_UNITS_STATIC_CONSTANT(fluid_ounces,volume) = 2.957353e-5*cubic_meters;

BOOST_UNITS_STATIC_CONSTANT(gill,volume) = 1.182941e-4*cubic_meters;
BOOST_UNITS_STATIC_CONSTANT(gills,volume) = 1.182941e-4*cubic_meters;

BOOST_UNITS_STATIC_CONSTANT(liquid_pint,volume) = 4.731765e-4*cubic_meters;
BOOST_UNITS_STATIC_CONSTANT(liquid_pints,volume) = 4.731765e-4*cubic_meters;

BOOST_UNITS_STATIC_CONSTANT(liquid_quart,volume) = 9.463529e-4*cubic_meters;
BOOST_UNITS_STATIC_CONSTANT(liquid_quarts,volume) = 9.463529e-4*cubic_meters;

BOOST_UNITS_STATIC_CONSTANT(gallon,volume) = 3.785412e-3*cubic_meters;
BOOST_UNITS_STATIC_CONSTANT(gallons,volume) = 3.785412e-3*cubic_meters;

BOOST_UNITS_STATIC_CONSTANT(dry_pint,volume) = 5.506105e-4*cubic_meters;
BOOST_UNITS_STATIC_CONSTANT(dry_pints,volume) = 5.506105e-4*cubic_meters;

BOOST_UNITS_STATIC_CONSTANT(dry_quart,volume) = 1.101221e-3*cubic_meters;
BOOST_UNITS_STATIC_CONSTANT(dry_quarts,volume) = 1.101221e-3*cubic_meters;

BOOST_UNITS_STATIC_CONSTANT(peck,volume) = 8.809768e-3*cubic_meters;
BOOST_UNITS_STATIC_CONSTANT(pecks,volume) = 8.809768e-3*cubic_meters;

BOOST_UNITS_STATIC_CONSTANT(bushel,volume) = 3.523907e-2*cubic_meters;
BOOST_UNITS_STATIC_CONSTANT(bushels,volume) = 3.523907e-2*cubic_meters;

// units of mass
BOOST_UNITS_STATIC_CONSTANT(avoirdupois_dram,mass) = 1.7718451953125e-3*kilograms;
BOOST_UNITS_STATIC_CONSTANT(avoirdupois_drams,mass) = 1.7718451953125e-3*kilograms;
BOOST_UNITS_STATIC_CONSTANT(dram,mass) = 1.7718451953125e-3*kilograms;
BOOST_UNITS_STATIC_CONSTANT(drams,mass) = 1.7718451953125e-3*kilograms;

BOOST_UNITS_STATIC_CONSTANT(avoirdupois_ounce,mass) = 2.8349523125e-2*kilograms;
BOOST_UNITS_STATIC_CONSTANT(avoirdupois_ounces,mass) = 2.8349523125e-2*kilograms;
BOOST_UNITS_STATIC_CONSTANT(ounce,mass) = 2.8349523125e-2*kilograms;
BOOST_UNITS_STATIC_CONSTANT(ounces,mass) = 2.8349523125e-2*kilograms;

BOOST_UNITS_STATIC_CONSTANT(avoirdupois_pound,mass) = 4.5359237e-1*kilograms;
BOOST_UNITS_STATIC_CONSTANT(avoirdupois_pounds,mass) = 4.5359237e-1*kilograms;
BOOST_UNITS_STATIC_CONSTANT(pound,mass) = 4.5359237e-1*kilograms;
BOOST_UNITS_STATIC_CONSTANT(pounds,mass) = 4.5359237e-1*kilograms;

BOOST_UNITS_STATIC_CONSTANT(short_hundredweight,mass) = 4.5359237e1*kilograms;
BOOST_UNITS_STATIC_CONSTANT(short_hundredweights,mass) = 4.5359237e1*kilograms;

BOOST_UNITS_STATIC_CONSTANT(short_ton,mass) = 9.0718474e2*kilograms;
BOOST_UNITS_STATIC_CONSTANT(short_tons,mass) = 9.0718474e2*kilograms;
BOOST_UNITS_STATIC_CONSTANT(ton,mass) = 9.0718474e2*kilograms;
BOOST_UNITS_STATIC_CONSTANT(tons,mass) = 9.0718474e2*kilograms;

BOOST_UNITS_STATIC_CONSTANT(long_ton,mass) = 1.0160469088e3*kilograms;
BOOST_UNITS_STATIC_CONSTANT(long_tons,mass) = 1.0160469088e3*kilograms;

BOOST_UNITS_STATIC_CONSTANT(grain,mass) = 6.479891e-5*kilograms;
BOOST_UNITS_STATIC_CONSTANT(grains,mass) = 6.479891e-5*kilograms;

BOOST_UNITS_STATIC_CONSTANT(apothecaries_scruple,mass) = 1.2959782e-3*kilograms;
BOOST_UNITS_STATIC_CONSTANT(apothecaries_scruples,mass) = 1.2959782e-3*kilograms;

BOOST_UNITS_STATIC_CONSTANT(pennyweight,mass) = 1.55517384e-3*kilograms;
BOOST_UNITS_STATIC_CONSTANT(pennyweights,mass) = 1.55517384e-3*kilograms;

BOOST_UNITS_STATIC_CONSTANT(apothecaries_dram,mass) = 3.8879346e-3*kilograms;
BOOST_UNITS_STATIC_CONSTANT(apothecaries_drams,mass) = 3.8879346e-3*kilograms;

BOOST_UNITS_STATIC_CONSTANT(apothecaries_ounce,mass) = 3.11034768e-2*kilograms;
BOOST_UNITS_STATIC_CONSTANT(apothecaries_ounces,mass) = 3.11034768e-2*kilograms;
BOOST_UNITS_STATIC_CONSTANT(troy_ounce,mass) = 3.11034768e-2*kilograms;
BOOST_UNITS_STATIC_CONSTANT(troy_ounces,mass) = 3.11034768e-2*kilograms;

BOOST_UNITS_STATIC_CONSTANT(apothecaries_pound,mass) = 3.732417216e-1*kilograms;
BOOST_UNITS_STATIC_CONSTANT(apothecaries_pounds,mass) = 3.732417216e-1*kilograms;
BOOST_UNITS_STATIC_CONSTANT(troy_pound,mass) = 3.732417216e-1*kilograms;
BOOST_UNITS_STATIC_CONSTANT(troy_pounds,mass) = 3.732417216e-1*kilograms;

// units of velocity
BOOST_UNITS_STATIC_CONSTANT(miles_per_hour,velocity) = (1609.344/3600.0)*meters_per_second;

} // namespace us

// US survey units
namespace us {

namespace survey {

// conversions from http://ts.nist.gov/WeightsAndMeasures/Publications/appxc.cfm#2

// units of length
BOOST_UNITS_STATIC_CONSTANT(link,length) = 0.2011684*meters;
BOOST_UNITS_STATIC_CONSTANT(links,length) = 0.2011684*meters;

BOOST_UNITS_STATIC_CONSTANT(foot,length) = 0.3048006*meters;
BOOST_UNITS_STATIC_CONSTANT(feet,length) = 0.3048006*meters;

BOOST_UNITS_STATIC_CONSTANT(rod,length) = 5.029210*meters;
BOOST_UNITS_STATIC_CONSTANT(rods,length) = 5.029210*meters;

BOOST_UNITS_STATIC_CONSTANT(chain,length) = 20.11684*meters;
BOOST_UNITS_STATIC_CONSTANT(chains,length) = 20.11684*meters;

BOOST_UNITS_STATIC_CONSTANT(mile,length) = 1609.347*meters;
BOOST_UNITS_STATIC_CONSTANT(miles,length) = 1609.347*meters;

// units of area
BOOST_UNITS_STATIC_CONSTANT(square_foot,area) = 0.09290341*square_meters;
BOOST_UNITS_STATIC_CONSTANT(square_feet,area) = 0.09290341*square_meters;

BOOST_UNITS_STATIC_CONSTANT(square_rod,area) = 25.29295*square_meters;
BOOST_UNITS_STATIC_CONSTANT(square_rods,area) = 25.29295*square_meters;

BOOST_UNITS_STATIC_CONSTANT(square_chain,area) = 404.6873*square_meters;
BOOST_UNITS_STATIC_CONSTANT(square_chains,area) = 404.6873*square_meters;

BOOST_UNITS_STATIC_CONSTANT(acre,area) = 4046.873*square_meters;
BOOST_UNITS_STATIC_CONSTANT(acres,area) = 4046.873*square_meters;

BOOST_UNITS_STATIC_CONSTANT(square_mile,area) = 2589998.0*square_meters;
BOOST_UNITS_STATIC_CONSTANT(square_miles,area) = 2589998.0*square_meters;

} // namespace survey

} // namespace us

/*
namespace english {

/// barleycorn
BOOST_UNITS_STATIC_CONSTANT(barleycorn,length) = 8.466667e-3*meters;
/// cubit
BOOST_UNITS_STATIC_CONSTANT(cubit,length) = 0.4572*meters;
/// ell
BOOST_UNITS_STATIC_CONSTANT(ell,length) = 1.143*meters;
/// fathom
BOOST_UNITS_STATIC_CONSTANT(fathom,length) = 1.8288*meters;
/// finger
BOOST_UNITS_STATIC_CONSTANT(finger,length) = 22.225e-3*meters;
/// furlong
BOOST_UNITS_STATIC_CONSTANT(furlong,length) = 201.168*meters;
/// hand
BOOST_UNITS_STATIC_CONSTANT(hand,length) = 0.1016*meters;
/// league
BOOST_UNITS_STATIC_CONSTANT(league,length) = 4828.032*meters;
/// palm
BOOST_UNITS_STATIC_CONSTANT(palm,length) = 76.2e-3*meters;
/// rod
BOOST_UNITS_STATIC_CONSTANT(rod,length) = 5.0292*meters;

} // namespace english

namespace imperial {

/// cable (Imperial)
BOOST_UNITS_STATIC_CONSTANT(cable,length) = 185.3184*meters;

} // namespace imperial

/// atomic unit
BOOST_UNITS_STATIC_CONSTANT(atomic_unit,length) = 5.291772083e-11*meters;
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
/// mile, geographical
BOOST_UNITS_STATIC_CONSTANT(geographical_mile,length) = 1853.7936*meters;
/// line
BOOST_UNITS_STATIC_CONSTANT(line,length) = 2.116667e-3*meters;
/// link (surveyor's)
BOOST_UNITS_STATIC_CONSTANT(surveyors_link,length) = 0.201168*meters;
/// link (engineer's)
BOOST_UNITS_STATIC_CONSTANT(engineers_link,length) = 0.3048*meters;
/// mickey
BOOST_UNITS_STATIC_CONSTANT(mickey,length) = 1.27e-4*meters;
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
/// rope
BOOST_UNITS_STATIC_CONSTANT(rope,length) = 6.096*meters;
/// span
BOOST_UNITS_STATIC_CONSTANT(span,length) = 0.1524*meters;
/// span (cloth)
BOOST_UNITS_STATIC_CONSTANT(cloth_span,length) = 0.2286*meters;
/// stick
BOOST_UNITS_STATIC_CONSTANT(stick,length) = 50.8e-3*meters;
*/
} // constants                                                                                  

} // namespace SI

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_NON_SI_CONSTANTS_HPP
