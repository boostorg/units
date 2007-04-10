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

#include <boost/units/systems/si/area.hpp>
#include <boost/units/systems/si/length.hpp>
#include <boost/units/systems/si/mass.hpp>
#include <boost/units/systems/si/plane_angle.hpp>
#include <boost/units/systems/si/pressure.hpp>
#include <boost/units/systems/si/time.hpp>
#include <boost/units/systems/si/velocity.hpp>
#include <boost/units/systems/si/volume.hpp>

namespace boost {

namespace units { 

namespace SI {
                            
namespace constants {

// common astronomical units
namespace astronomical {

// units of length
BOOST_UNITS_AUTO_STATIC_CONSTANT(astronomical_unit,149597870691.0*meters);
BOOST_UNITS_AUTO_STATIC_CONSTANT(light_day,2.59020683712e13*meters);
BOOST_UNITS_AUTO_STATIC_CONSTANT(light_hour,1.0792528488e12*meters);
BOOST_UNITS_AUTO_STATIC_CONSTANT(light_minute,1.798754748e10*meters);
BOOST_UNITS_AUTO_STATIC_CONSTANT(light_second,2.99792458e8*meters);
BOOST_UNITS_AUTO_STATIC_CONSTANT(light_year,9.460730472580e15*meters);
BOOST_UNITS_AUTO_STATIC_CONSTANT(parsec,3.0856775813e16*meters);

} // namespace astronomical

// British imperial units
namespace imperial {

} // namespace imperial

// non-SI metric units
namespace metric {

// units of length
BOOST_UNITS_AUTO_STATIC_CONSTANT(angstrom,1.0e-10*meters);
BOOST_UNITS_AUTO_STATIC_CONSTANT(angstroms,1.0e-10*meters);

BOOST_UNITS_AUTO_STATIC_CONSTANT(fermi,1.0e-15*meters);
BOOST_UNITS_AUTO_STATIC_CONSTANT(fermis,1.0e-15*meters);

BOOST_UNITS_AUTO_STATIC_CONSTANT(micron,1.0e-6*meters);
BOOST_UNITS_AUTO_STATIC_CONSTANT(microns,1.0e-6*meters);

// units of mass
BOOST_UNITS_AUTO_STATIC_CONSTANT(ton,1.0e3*kilograms);
BOOST_UNITS_AUTO_STATIC_CONSTANT(tons,1.0e3*kilograms);
BOOST_UNITS_AUTO_STATIC_CONSTANT(tonne,1.0e3*kilograms);
BOOST_UNITS_AUTO_STATIC_CONSTANT(tonnes,1.0e3*kilograms);

// units of time
BOOST_UNITS_AUTO_STATIC_CONSTANT(day,86400.0*seconds);
BOOST_UNITS_AUTO_STATIC_CONSTANT(days,86400.0*seconds);

BOOST_UNITS_AUTO_STATIC_CONSTANT(hour,3600.0*seconds);
BOOST_UNITS_AUTO_STATIC_CONSTANT(hours,3600.0*seconds);

BOOST_UNITS_AUTO_STATIC_CONSTANT(minute,60.0*seconds);
BOOST_UNITS_AUTO_STATIC_CONSTANT(minutes,60.0*seconds);

// units of planar angle
BOOST_UNITS_AUTO_STATIC_CONSTANT(arcdegree,(3.14159265358979323846264338328/180)*radians);
BOOST_UNITS_AUTO_STATIC_CONSTANT(arcdegrees,(3.14159265358979323846264338328/180)*radians);

BOOST_UNITS_AUTO_STATIC_CONSTANT(arcminute,(3.14159265358979323846264338328/10800)*radians);
BOOST_UNITS_AUTO_STATIC_CONSTANT(arcminutes,(3.14159265358979323846264338328/10800)*radians);

BOOST_UNITS_AUTO_STATIC_CONSTANT(arcsecond,(3.14159265358979323846264338328/648000)*radians);
BOOST_UNITS_AUTO_STATIC_CONSTANT(arcseconds,(3.14159265358979323846264338328/648000)*radians);

// units of area
BOOST_UNITS_AUTO_STATIC_CONSTANT(are,1.0e2*square_meters);
BOOST_UNITS_AUTO_STATIC_CONSTANT(ares,1.0e2*square_meters);

BOOST_UNITS_AUTO_STATIC_CONSTANT(barn,1.0e-28*square_meters);
BOOST_UNITS_AUTO_STATIC_CONSTANT(barns,1.0e-28*square_meters);

BOOST_UNITS_AUTO_STATIC_CONSTANT(hectare,1.0e4*square_meters);
BOOST_UNITS_AUTO_STATIC_CONSTANT(hectares,1.0e4*square_meters);

// units of volume
BOOST_UNITS_AUTO_STATIC_CONSTANT(liter,1.0e-3*cubic_meters);
BOOST_UNITS_AUTO_STATIC_CONSTANT(liters,1.0e-3*cubic_meters);
BOOST_UNITS_AUTO_STATIC_CONSTANT(litre,1.0e-3*cubic_meters);
BOOST_UNITS_AUTO_STATIC_CONSTANT(litres,1.0e-3*cubic_meters);

// units of pressure
BOOST_UNITS_AUTO_STATIC_CONSTANT(bar,1.0e5*pascals);

} // namespace metric 

// nautical units
namespace nautical {

// units of length
BOOST_UNITS_AUTO_STATIC_CONSTANT(fathom,1.852*meters);
BOOST_UNITS_AUTO_STATIC_CONSTANT(fathoms,1.852*meters);

BOOST_UNITS_AUTO_STATIC_CONSTANT(knot,(1852.0/3600.0)*meters_per_second);
BOOST_UNITS_AUTO_STATIC_CONSTANT(knots,(1852.0/3600.0)*meters_per_second);

BOOST_UNITS_AUTO_STATIC_CONSTANT(league,5556.0*meters);
BOOST_UNITS_AUTO_STATIC_CONSTANT(leagues,5556.0*meters);

BOOST_UNITS_AUTO_STATIC_CONSTANT(mile,1852.0*meters);
BOOST_UNITS_AUTO_STATIC_CONSTANT(miles,1852.0*meters);

} // namespace nautical

// US customary units 
namespace us { 

// conversions from http://ts.nist.gov/WeightsAndMeasures/Publications/appxc.cfm#2

// units of length
BOOST_UNITS_AUTO_STATIC_CONSTANT(inch,25.4e-3*meters);
BOOST_UNITS_AUTO_STATIC_CONSTANT(inches,25.4e-3*meters);

BOOST_UNITS_AUTO_STATIC_CONSTANT(foot,0.3048*meters);
BOOST_UNITS_AUTO_STATIC_CONSTANT(feet,0.3048*meters);

BOOST_UNITS_AUTO_STATIC_CONSTANT(yard,0.9144*meters);
BOOST_UNITS_AUTO_STATIC_CONSTANT(yards,0.9144*meters);

BOOST_UNITS_AUTO_STATIC_CONSTANT(mile,1609.344*meters);
BOOST_UNITS_AUTO_STATIC_CONSTANT(miles,1609.344*meters);

// units of area
BOOST_UNITS_AUTO_STATIC_CONSTANT(square_inch,645.16e-6*square_meters); 
BOOST_UNITS_AUTO_STATIC_CONSTANT(square_inches,645.16e-6*square_meters);

BOOST_UNITS_AUTO_STATIC_CONSTANT(square_foot,9.290304e-2*square_meters);
BOOST_UNITS_AUTO_STATIC_CONSTANT(square_feet,9.290304e-2*square_meters);

BOOST_UNITS_AUTO_STATIC_CONSTANT(square_yard,0.83612736*square_meters);
BOOST_UNITS_AUTO_STATIC_CONSTANT(square_yards,0.83612736*square_meters);

BOOST_UNITS_AUTO_STATIC_CONSTANT(square_mile,2589988.110336*square_meters);
BOOST_UNITS_AUTO_STATIC_CONSTANT(square_miles,2589988.110336*square_meters);

// units of volume
BOOST_UNITS_AUTO_STATIC_CONSTANT(cubic_inch,16.387064e-6*cubic_meters);
BOOST_UNITS_AUTO_STATIC_CONSTANT(cubic_inches,16.387064e-6*cubic_meters);

BOOST_UNITS_AUTO_STATIC_CONSTANT(cubic_foot,2.8316846592e-2*cubic_meters);
BOOST_UNITS_AUTO_STATIC_CONSTANT(cubic_feet,2.8316846592e-2*cubic_meters);

BOOST_UNITS_AUTO_STATIC_CONSTANT(cubic_yard,0.764554857984*cubic_meters);
BOOST_UNITS_AUTO_STATIC_CONSTANT(cubic_yards,0.764554857984*cubic_meters);

BOOST_UNITS_AUTO_STATIC_CONSTANT(minim,6.161152e-8*cubic_meters);
BOOST_UNITS_AUTO_STATIC_CONSTANT(minims,6.161152e-8*cubic_meters);

BOOST_UNITS_AUTO_STATIC_CONSTANT(fluid_dram,3.696691e-6*cubic_meters);
BOOST_UNITS_AUTO_STATIC_CONSTANT(fluid_drams,3.696691e-6*cubic_meters);

BOOST_UNITS_AUTO_STATIC_CONSTANT(fluid_ounce,2.957353e-5*cubic_meters);
BOOST_UNITS_AUTO_STATIC_CONSTANT(fluid_ounces,2.957353e-5*cubic_meters);

BOOST_UNITS_AUTO_STATIC_CONSTANT(gill,1.182941e-4*cubic_meters);
BOOST_UNITS_AUTO_STATIC_CONSTANT(gills,1.182941e-4*cubic_meters);

BOOST_UNITS_AUTO_STATIC_CONSTANT(liquid_pint,4.731765e-4*cubic_meters);
BOOST_UNITS_AUTO_STATIC_CONSTANT(liquid_pints,4.731765e-4*cubic_meters);

BOOST_UNITS_AUTO_STATIC_CONSTANT(liquid_quart,9.463529e-4*cubic_meters);
BOOST_UNITS_AUTO_STATIC_CONSTANT(liquid_quarts,9.463529e-4*cubic_meters);

BOOST_UNITS_AUTO_STATIC_CONSTANT(gallon,3.785412e-3*cubic_meters);
BOOST_UNITS_AUTO_STATIC_CONSTANT(gallons,3.785412e-3*cubic_meters);

BOOST_UNITS_AUTO_STATIC_CONSTANT(dry_pint,5.506105e-4*cubic_meters);
BOOST_UNITS_AUTO_STATIC_CONSTANT(dry_pints,5.506105e-4*cubic_meters);

BOOST_UNITS_AUTO_STATIC_CONSTANT(dry_quart,1.101221e-3*cubic_meters);
BOOST_UNITS_AUTO_STATIC_CONSTANT(dry_quarts,1.101221e-3*cubic_meters);

BOOST_UNITS_AUTO_STATIC_CONSTANT(peck,8.809768e-3*cubic_meters);
BOOST_UNITS_AUTO_STATIC_CONSTANT(pecks,8.809768e-3*cubic_meters);

BOOST_UNITS_AUTO_STATIC_CONSTANT(bushel,3.523907e-2*cubic_meters);
BOOST_UNITS_AUTO_STATIC_CONSTANT(bushels,3.523907e-2*cubic_meters);

// units of mass
BOOST_UNITS_AUTO_STATIC_CONSTANT(avoirdupois_dram,1.7718451953125e-3*kilograms);
BOOST_UNITS_AUTO_STATIC_CONSTANT(avoirdupois_drams,1.7718451953125e-3*kilograms);
BOOST_UNITS_AUTO_STATIC_CONSTANT(dram,1.7718451953125e-3*kilograms);
BOOST_UNITS_AUTO_STATIC_CONSTANT(drams,1.7718451953125e-3*kilograms);

BOOST_UNITS_AUTO_STATIC_CONSTANT(avoirdupois_ounce,2.8349523125e-2*kilograms);
BOOST_UNITS_AUTO_STATIC_CONSTANT(avoirdupois_ounces,2.8349523125e-2*kilograms);
BOOST_UNITS_AUTO_STATIC_CONSTANT(ounce,2.8349523125e-2*kilograms);
BOOST_UNITS_AUTO_STATIC_CONSTANT(ounces,2.8349523125e-2*kilograms);

BOOST_UNITS_AUTO_STATIC_CONSTANT(avoirdupois_pound,4.5359237e-1*kilograms);
BOOST_UNITS_AUTO_STATIC_CONSTANT(avoirdupois_pounds,4.5359237e-1*kilograms);
BOOST_UNITS_AUTO_STATIC_CONSTANT(pound,4.5359237e-1*kilograms);
BOOST_UNITS_AUTO_STATIC_CONSTANT(pounds,4.5359237e-1*kilograms);

BOOST_UNITS_AUTO_STATIC_CONSTANT(short_hundredweight,4.5359237e1*kilograms);
BOOST_UNITS_AUTO_STATIC_CONSTANT(short_hundredweights,4.5359237e1*kilograms);

BOOST_UNITS_AUTO_STATIC_CONSTANT(short_ton,9.0718474e2*kilograms);
BOOST_UNITS_AUTO_STATIC_CONSTANT(short_tons,9.0718474e2*kilograms);
BOOST_UNITS_AUTO_STATIC_CONSTANT(ton,9.0718474e2*kilograms);
BOOST_UNITS_AUTO_STATIC_CONSTANT(tons,9.0718474e2*kilograms);

BOOST_UNITS_AUTO_STATIC_CONSTANT(long_ton,1.0160469088e3*kilograms);
BOOST_UNITS_AUTO_STATIC_CONSTANT(long_tons,1.0160469088e3*kilograms);

BOOST_UNITS_AUTO_STATIC_CONSTANT(grain,6.479891e-5*kilograms);
BOOST_UNITS_AUTO_STATIC_CONSTANT(grains,6.479891e-5*kilograms);

BOOST_UNITS_AUTO_STATIC_CONSTANT(apothecaries_scruple,1.2959782e-3*kilograms);
BOOST_UNITS_AUTO_STATIC_CONSTANT(apothecaries_scruples,1.2959782e-3*kilograms);

BOOST_UNITS_AUTO_STATIC_CONSTANT(pennyweight,1.55517384e-3*kilograms);
BOOST_UNITS_AUTO_STATIC_CONSTANT(pennyweights,1.55517384e-3*kilograms);

BOOST_UNITS_AUTO_STATIC_CONSTANT(apothecaries_dram,3.8879346e-3*kilograms);
BOOST_UNITS_AUTO_STATIC_CONSTANT(apothecaries_drams,3.8879346e-3*kilograms);

BOOST_UNITS_AUTO_STATIC_CONSTANT(apothecaries_ounce,3.11034768e-2*kilograms);
BOOST_UNITS_AUTO_STATIC_CONSTANT(apothecaries_ounces,3.11034768e-2*kilograms);
BOOST_UNITS_AUTO_STATIC_CONSTANT(troy_ounce,3.11034768e-2*kilograms);
BOOST_UNITS_AUTO_STATIC_CONSTANT(troy_ounces,3.11034768e-2*kilograms);

BOOST_UNITS_AUTO_STATIC_CONSTANT(apothecaries_pound,3.732417216e-1*kilograms);
BOOST_UNITS_AUTO_STATIC_CONSTANT(apothecaries_pounds,3.732417216e-1*kilograms);
BOOST_UNITS_AUTO_STATIC_CONSTANT(troy_pound,3.732417216e-1*kilograms);
BOOST_UNITS_AUTO_STATIC_CONSTANT(troy_pounds,3.732417216e-1*kilograms);

// units of velocity
BOOST_UNITS_AUTO_STATIC_CONSTANT(miles_per_hour,(1609.344/3600.0)*meters_per_second);

} // namespace us

// US survey units
namespace us {

namespace survey {

// conversions from http://ts.nist.gov/WeightsAndMeasures/Publications/appxc.cfm#2

// units of length
BOOST_UNITS_AUTO_STATIC_CONSTANT(link,0.2011684*meters);
BOOST_UNITS_AUTO_STATIC_CONSTANT(links,0.2011684*meters);

BOOST_UNITS_AUTO_STATIC_CONSTANT(foot,0.3048006*meters);
BOOST_UNITS_AUTO_STATIC_CONSTANT(feet,0.3048006*meters);

BOOST_UNITS_AUTO_STATIC_CONSTANT(rod,5.029210*meters);
BOOST_UNITS_AUTO_STATIC_CONSTANT(rods,5.029210*meters);

BOOST_UNITS_AUTO_STATIC_CONSTANT(chain,20.11684*meters);
BOOST_UNITS_AUTO_STATIC_CONSTANT(chains,20.11684*meters);

BOOST_UNITS_AUTO_STATIC_CONSTANT(mile,1609.347*meters);
BOOST_UNITS_AUTO_STATIC_CONSTANT(miles,1609.347*meters);

// units of area
BOOST_UNITS_AUTO_STATIC_CONSTANT(square_foot,0.09290341*square_meters);
BOOST_UNITS_AUTO_STATIC_CONSTANT(square_feet,0.09290341*square_meters);

BOOST_UNITS_AUTO_STATIC_CONSTANT(square_rod,25.29295*square_meters);
BOOST_UNITS_AUTO_STATIC_CONSTANT(square_rods,25.29295*square_meters);

BOOST_UNITS_AUTO_STATIC_CONSTANT(square_chain,404.6873*square_meters);
BOOST_UNITS_AUTO_STATIC_CONSTANT(square_chains,404.6873*square_meters);

BOOST_UNITS_AUTO_STATIC_CONSTANT(acre,4046.873*square_meters);
BOOST_UNITS_AUTO_STATIC_CONSTANT(acres,4046.873*square_meters);

BOOST_UNITS_AUTO_STATIC_CONSTANT(square_mile,2589998.0*square_meters);
BOOST_UNITS_AUTO_STATIC_CONSTANT(square_miles,2589998.0*square_meters);

} // namespace survey

} // namespace us

/*
namespace english {

/// barleycorn
BOOST_UNITS_AUTO_STATIC_CONSTANT(barleycorn,8.466667e-3*meters);
/// cubit
BOOST_UNITS_AUTO_STATIC_CONSTANT(cubit,0.4572*meters);
/// ell
BOOST_UNITS_AUTO_STATIC_CONSTANT(ell,1.143*meters);
/// fathom
BOOST_UNITS_AUTO_STATIC_CONSTANT(fathom,1.8288*meters);
/// finger
BOOST_UNITS_AUTO_STATIC_CONSTANT(finger,22.225e-3*meters);
/// furlong
BOOST_UNITS_AUTO_STATIC_CONSTANT(furlong,201.168*meters);
/// hand
BOOST_UNITS_AUTO_STATIC_CONSTANT(hand,0.1016*meters);
/// league
BOOST_UNITS_AUTO_STATIC_CONSTANT(league,4828.032*meters);
/// palm
BOOST_UNITS_AUTO_STATIC_CONSTANT(palm,76.2e-3*meters);
/// rod
BOOST_UNITS_AUTO_STATIC_CONSTANT(rod,5.0292*meters);

} // namespace english

namespace imperial {

/// cable (Imperial)
BOOST_UNITS_AUTO_STATIC_CONSTANT(cable,185.3184*meters);

} // namespace imperial

/// atomic unit
BOOST_UNITS_AUTO_STATIC_CONSTANT(atomic_unit,5.291772083e-11*meters);
/// Bohr radius
BOOST_UNITS_AUTO_STATIC_CONSTANT(bohr_radius,atomic_unit);
/// cable (US)
BOOST_UNITS_AUTO_STATIC_CONSTANT(us_cable,219.456*meters);
/// calibre
BOOST_UNITS_AUTO_STATIC_CONSTANT(calibre,25.4e-3*meters);
/// chain (surveyor's)
BOOST_UNITS_AUTO_STATIC_CONSTANT(surveyors_chain,20.1168*meters);
/// chain (engineer's)
BOOST_UNITS_AUTO_STATIC_CONSTANT(engineers_chain,30.48*meters);
/// finger (cloth)
BOOST_UNITS_AUTO_STATIC_CONSTANT(cloth_finger,0.1143*meters);
/// foot (Benoit)
BOOST_UNITS_AUTO_STATIC_CONSTANT(benoit_foot,0.304799735*meters);
/// foot (Clarke's)
BOOST_UNITS_AUTO_STATIC_CONSTANT(clarkes_foot,0.3047972654*meters);
/// foot (Indian)
BOOST_UNITS_AUTO_STATIC_CONSTANT(indian_foot,0.304799514*meters);
/// foot (Sear's)
BOOST_UNITS_AUTO_STATIC_CONSTANT(sears_foot,0.30479947*meters);
/// foot (US Survey)
BOOST_UNITS_AUTO_STATIC_CONSTANT(us_foot,(1200.0/3937.0)*meters);
/// mile, geographical
BOOST_UNITS_AUTO_STATIC_CONSTANT(geographical_mile,1853.7936*meters);
/// line
BOOST_UNITS_AUTO_STATIC_CONSTANT(line,2.116667e-3*meters);
/// link (surveyor's)
BOOST_UNITS_AUTO_STATIC_CONSTANT(surveyors_link,0.201168*meters);
/// link (engineer's)
BOOST_UNITS_AUTO_STATIC_CONSTANT(engineers_link,0.3048*meters);
/// mickey
BOOST_UNITS_AUTO_STATIC_CONSTANT(mickey,1.27e-4*meters);
/// mil
BOOST_UNITS_AUTO_STATIC_CONSTANT(mil,2.54e-5*meters);
/// mile (US survey)
BOOST_UNITS_AUTO_STATIC_CONSTANT(mile_us,1609.347219*meters);
/// nail (cloth)
BOOST_UNITS_AUTO_STATIC_CONSTANT(nail,57.15e-3*meters);
/// mile (Admiralty nautical)
BOOST_UNITS_AUTO_STATIC_CONSTANT(admiralty_nautical_mile,1853.184*meters);
/// pace
BOOST_UNITS_AUTO_STATIC_CONSTANT(pace,0.762*meters);
/// point (ATA)
BOOST_UNITS_AUTO_STATIC_CONSTANT(ata_point,0.3514598e-3*meters);
/// point (Didot)
BOOST_UNITS_AUTO_STATIC_CONSTANT(didot_point,0.376065e-3*meters);
/// point (metric)
BOOST_UNITS_AUTO_STATIC_CONSTANT(point,0.375e-3*meters);
/// point (PostScript)
BOOST_UNITS_AUTO_STATIC_CONSTANT(postscript_point,0.352778e-3*meters);
/// quarter
BOOST_UNITS_AUTO_STATIC_CONSTANT(quarter,0.2286*meters);
/// rope
BOOST_UNITS_AUTO_STATIC_CONSTANT(rope,6.096*meters);
/// span
BOOST_UNITS_AUTO_STATIC_CONSTANT(span,0.1524*meters);
/// span (cloth)
BOOST_UNITS_AUTO_STATIC_CONSTANT(cloth_span,0.2286*meters);
/// stick
BOOST_UNITS_AUTO_STATIC_CONSTANT(stick,50.8e-3*meters);
*/
} // constants                                                                                  

} // namespace SI

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_NON_SI_CONSTANTS_HPP
