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

#include <boost/units/conversion.hpp>
#include <boost/units/systems/si/area.hpp>
#include <boost/units/systems/si/length.hpp>
#include <boost/units/systems/si/mass.hpp>
#include <boost/units/systems/si/plane_angle.hpp>
#include <boost/units/systems/si/pressure.hpp>
#include <boost/units/systems/si/time.hpp>
#include <boost/units/systems/si/velocity.hpp>
#include <boost/units/systems/si/volume.hpp>
#include <boost/units/systems/si/force.hpp>

#ifdef BOOST_UNITS_DOXYGEN
///INTERNAL ONLY
#define BOOST_UNITS_DEFINE_CONVERSION(name, unit, type, factor)
///INTERNAL ONLY
#define BOOST_UNITS_DEFAULT_CONVERSION(name, unit)
#endif

///INTERNAL ONLY
#define BOOST_UNITS_NON_SI_UNIT(name, factor, unit, id)                     \
namespace boost {                                                           \
namespace units {                                                           \
namespace BOOST_UNITS_NAMESPACE {                                           \
struct name : base_unit<name, unit::dimension_type, id - 100> {};           \
}                                                                           \
}                                                                           \
}                                                                           \
BOOST_UNITS_DEFINE_CONVERSION(BOOST_UNITS_NAMESPACE::name, unit, double, factor); \
BOOST_UNITS_DEFAULT_CONVERSION(BOOST_UNITS_NAMESPACE::name, unit)

///INTERNAL ONLY
#define BOOST_UNITS_NAMESPACE astronomical

BOOST_UNITS_NON_SI_UNIT(astronomical_unit_base_unit, 149597870691.0, meter_base_unit::unit_type, 0);
BOOST_UNITS_NON_SI_UNIT(light_day_base_unit, 2.59020683712e13, meter_base_unit::unit_type, 1);
BOOST_UNITS_NON_SI_UNIT(light_hour_base_unit,1.0792528488e12, meter_base_unit::unit_type, 2);
BOOST_UNITS_NON_SI_UNIT(light_minute_base_unit,1.798754748e10, meter_base_unit::unit_type, 3);
BOOST_UNITS_NON_SI_UNIT(light_second_base_unit,2.99792458e8, meter_base_unit::unit_type, 4);
BOOST_UNITS_NON_SI_UNIT(light_year_base_unit,9.460730472580e15, meter_base_unit::unit_type, 5);
BOOST_UNITS_NON_SI_UNIT(parsec_base_unit,3.0856775813e16, meter_base_unit::unit_type, 6);

#undef BOOST_UNITS_NAMESPACE

#define BOOST_UNITS_NAMESPACE metric

namespace boost {
namespace units {
namespace metric {

// units of length
typedef scaled_base_unit<meter_base_unit, scale<10, static_rational<10> > > angstrom_base_unit;
typedef scaled_base_unit<meter_base_unit, scale<10, static_rational<15> > > fermi_base_unit;
typedef scaled_base_unit<meter_base_unit, scale<10, static_rational<6> > > micron_base_unit;

// units of mass
typedef scaled_base_unit<kilogram_base_unit, scale<10, static_rational<3> > > ton_base_unit;

// units of time
typedef scaled_base_unit<second_base_unit, scale<60, static_rational<1> > > minute_base_unit;
typedef scaled_base_unit<second_base_unit, scale<60, static_rational<2> > > hour_base_unit;
typedef scaled_base_unit<hour_base_unit, scale<24, static_rational<1> > > day_base_unit;

} // namespace metric
} // namespace units
} // namespace boost

// units of planar angle
BOOST_UNITS_NON_SI_UNIT(arcdegree_base_unit,(3.14159265358979323846264338328/180), radian_base_unit::unit_type, 7);
BOOST_UNITS_NON_SI_UNIT(arcminute_base_unit,(3.14159265358979323846264338328/10800), radian_base_unit::unit_type, 8);
BOOST_UNITS_NON_SI_UNIT(arcsecond_base_unit,(3.14159265358979323846264338328/648000), radian_base_unit::unit_type, 9);

// units of area
BOOST_UNITS_NON_SI_UNIT(are_base_unit,1.0e2, reduce_unit<SI::area>::type, 10);
BOOST_UNITS_NON_SI_UNIT(barn_base_unit,1.0e-28, reduce_unit<SI::area>::type, 11);
BOOST_UNITS_NON_SI_UNIT(hectare_base_unit,1.0e4, reduce_unit<SI::area>::type, 12);

// units of volume
BOOST_UNITS_NON_SI_UNIT(liter_base_unit,1.0e-3, reduce_unit<SI::volume>::type, 13);

// units of pressure
BOOST_UNITS_NON_SI_UNIT(bar_base_unit,1.0e5, reduce_unit<SI::force>::type, 14);

#undef BOOST_UNITS_NAMESPACE

#define BOOST_UNITS_NAMESPACE nautical

// units of length
BOOST_UNITS_NON_SI_UNIT(fathom_base_unit,1.852,meter_base_unit::unit_type, 15);

BOOST_UNITS_NON_SI_UNIT(knot_base_unit,(1852.0/3600.0), reduce_unit<SI::velocity>::type, 16);

BOOST_UNITS_NON_SI_UNIT(league_base_unit,5556.0, meter_base_unit::unit_type, 17);

BOOST_UNITS_NON_SI_UNIT(nautical_mile_base_unit,1852.0, meter_base_unit::unit_type, 18);

#undef BOOST_UNITS_NAMESPACE

// US customary units

// conversions from http://ts.nist.gov/WeightsAndMeasures/Publications/appxc.cfm#2

#define BOOST_UNITS_NAMESPACE us

// units of length

// inch, foot, yard, mile and elsewhere

// units of volume

BOOST_UNITS_NON_SI_UNIT(minim_base_unit,6.161152e-8, reduce_unit<SI::volume>::type, 19);

namespace boost {
namespace units {
namespace us {

typedef scaled_base_unit<minim_base_unit, scale<60, static_rational<1> > > fluid_dram_base_unit; //3.696691e-6*cubic_meters
typedef scaled_base_unit<fluid_dram_base_unit, scale<2, static_rational<3> > > fluid_once_base_unit; //2.957353e-5*cubic_meters
typedef scaled_base_unit<fluid_dram_base_unit, scale<2, static_rational<5> > > gill_base_unit; //1.182941e-4*cubic_meters
typedef scaled_base_unit<fluid_dram_base_unit, scale<2, static_rational<7> > > liquid_pint_base_unit; //4.731765e-4*cubic_meters
typedef scaled_base_unit<fluid_dram_base_unit, scale<2, static_rational<8> > > liquid_quart_base_unit; //9.463529e-4*cubic_meters
typedef scaled_base_unit<fluid_dram_base_unit, scale<2, static_rational<10> > > gallon_base_unit; //3.785412e-3*cubic_meters

}
}
}

BOOST_UNITS_NON_SI_UNIT(dry_pint_base_unit,5.506105e-4, reduce_unit<SI::volume>::type, 20);

namespace boost {
namespace units {
namespace us {

typedef scaled_base_unit<dry_pint_base_unit, scale<2, static_rational<1> > > dry_quart_base_unit; //1.101221e-3*cubic_meters
typedef scaled_base_unit<dry_pint_base_unit, scale<2, static_rational<4> > > peck_base_unit; //8.809768e-3*cubic_meters
typedef scaled_base_unit<dry_pint_base_unit, scale<2, static_rational<6> > > bushel_base_unit; //3.523907e-2*cubic_meters

}
}
}

// units of mass
BOOST_UNITS_NON_SI_UNIT(avoirdupois_dram_base_unit,1.7718451953125e-3, kilogram_base_unit::unit_type, 21);

namespace boost {
namespace units {
namespace us {

typedef scaled_base_unit<avoirdupois_dram_base_unit, scale<2, static_rational<4> > > avoirdupois_ounce_base_unit; //2.8349523125e-2*kilograms
typedef scaled_base_unit<avoirdupois_dram_base_unit, scale<2, static_rational<8> > > avoirdupois_pound_base_unit; //4.5359237e-1*kilograms
typedef scaled_base_unit<avoirdupois_pound_base_unit, scale<10, static_rational<2> > > short_hundredweight_base_unit; //4.5359237e1*kilograms
typedef scaled_base_unit<avoirdupois_pound_base_unit, scale<2000, static_rational<1> > > short_ton_base_unit; //9.0718474e2*kilograms

}
}
}

BOOST_UNITS_NON_SI_UNIT(long_ton_base_unit,1.0160469088e3,kilogram_base_unit::unit_type, 22);

BOOST_UNITS_NON_SI_UNIT(grain_base_unit,6.479891e-5,kilogram_base_unit::unit_type, 23);

namespace boost {
namespace units {
namespace us {

typedef scaled_base_unit<grain_base_unit, scale<20, static_rational<1> > > apothecaries_scruple_base_unit; //1.2959782e-3

typedef scaled_base_unit<grain_base_unit, scale<24, static_rational<1> > > pennyweight_base_unit; //1.55517384e-3*kilograms

typedef scaled_base_unit<grain_base_unit, scale<60, static_rational<1> > > apothecaries_dram_base_unit; //3.8879346e-3*kilograms

typedef scaled_base_unit<apothecaries_dram_base_unit, scale<2, static_rational<3> > > apothecaries_ounce_base_unit; //3.11034768e-2*kilograms
typedef scaled_base_unit<apothecaries_ounce_base_unit, scale<12, static_rational<1> > > apothecaries_pound_base_unit;//3.732417216e-1*kilograms

}
}
}

#undef BOOST_UNITS_NAMESPACE

#define BOOST_UNITS_NAMESPACE survey

// conversions from http://ts.nist.gov/WeightsAndMeasures/Publications/appxc.cfm#2

// units of length
BOOST_UNITS_NON_SI_UNIT(link_base_unit,0.2011684,meter_base_unit::unit_type, 24);

BOOST_UNITS_NON_SI_UNIT(foot_base_unit,0.3048006,meter_base_unit::unit_type, 25);

BOOST_UNITS_NON_SI_UNIT(rod_base_unit,5.029210,meter_base_unit::unit_type, 26);

BOOST_UNITS_NON_SI_UNIT(chain_base_unit,20.11684,meter_base_unit::unit_type, 27);

BOOST_UNITS_NON_SI_UNIT(mile_base_unit,1609.347,meter_base_unit::unit_type, 28);

// units of area

BOOST_UNITS_NON_SI_UNIT(acre_base_unit,4046.873,reduce_unit<SI::area>::type, 29);

#undef BOOST_UNITS_NAMESPACE
#undef BOOST_UNITS_END_NAMESPACE

/*
namespace boost {

namespace units { 

namespace SI {
                            
namespace constants {

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

} // constants                                                                                  

} // namespace SI

} // namespace units

} // namespace boost
*/

#endif // BOOST_UNITS_NON_SI_CONSTANTS_HPP
