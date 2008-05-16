// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2007-2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// No include guards.  This header is intended to be included
// multiple times.

// units of length

#if defined(BOOST_UNITS_METER_BASE_UNIT_HPP) && defined(BOOST_UNITS_FOOT_BASE_UNIT_HPP) &&\
    !defined(BOOST_UNITS_SYSTEMS_FOOT_TO_METER_CONVERSION_DEFINED)
    #define BOOST_UNITS_SYSTEMS_FOOT_TO_METER_CONVERSION_DEFINED
    #include <boost/units/conversion.hpp>
    BOOST_UNITS_DEFINE_CONVERSION_FACTOR(boost::units::foot_base_unit, boost::units::meter_base_unit, double, 0.3048);
#endif

#if defined(BOOST_UNITS_METER_BASE_UNIT_HPP) && defined(BOOST_UNITS_INCH_BASE_UNIT_HPP) &&\
    !defined(BOOST_UNITS_SYSTEMS_INCH_TO_METER_CONVERSION_DEFINED)
    #define BOOST_UNITS_SYSTEMS_INCH_TO_METER_CONVERSION_DEFINED
    #include <boost/units/conversion.hpp>
    BOOST_UNITS_DEFINE_CONVERSION_FACTOR(boost::units::inch_base_unit, boost::units::meter_base_unit, double, 25.4e-3);
#endif

#if defined(BOOST_UNITS_METER_BASE_UNIT_HPP) && defined(BOOST_UNITS_YARD_BASE_UNIT_HPP) &&\
    !defined(BOOST_UNITS_SYSTEMS_YARD_TO_METER_CONVERSION_DEFINED)
    #define BOOST_UNITS_SYSTEMS_YARD_TO_METER_CONVERSION_DEFINED
    #include <boost/units/conversion.hpp>
    BOOST_UNITS_DEFINE_CONVERSION_FACTOR(boost::units::yard_base_unit, boost::units::meter_base_unit, double, 0.9144);
#endif

#if defined(BOOST_UNITS_METER_BASE_UNIT_HPP) && defined(BOOST_UNITS_MILE_BASE_UNIT_HPP) &&\
    !defined(BOOST_UNITS_SYSTEMS_MILE_TO_METER_CONVERSION_DEFINED)
    #define BOOST_UNITS_SYSTEMS_MILE_TO_METER_CONVERSION_DEFINED
    #include <boost/units/conversion.hpp>
    BOOST_UNITS_DEFINE_CONVERSION_FACTOR(boost::units::mile_base_unit, boost::units::meter_base_unit, double, 1609.344);
#endif

#if defined(BOOST_UNITS_MILE_BASE_UNIT_HPP) && defined(BOOST_UNITS_YARD_BASE_UNIT_HPP) &&\
    !defined(BOOST_UNITS_SYSTEMS_MILE_TO_YARD_CONVERSION_DEFINED)
    #define BOOST_UNITS_SYSTEMS_MILE_TO_YARD_CONVERSION_DEFINED
    #include <boost/units/conversion.hpp>
    BOOST_UNITS_DEFINE_CONVERSION_FACTOR(boost::units::mile_base_unit, boost::units::yard_base_unit, double, 1760.0);
#endif

#if defined(BOOST_UNITS_MILE_BASE_UNIT_HPP) && defined(BOOST_UNITS_FOOT_BASE_UNIT_HPP) &&\
    !defined(BOOST_UNITS_SYSTEMS_MILE_TO_FOOT_CONVERSION_DEFINED)
    #define BOOST_UNITS_SYSTEMS_MILE_TO_FOOT_CONVERSION_DEFINED
    #include <boost/units/conversion.hpp>
    BOOST_UNITS_DEFINE_CONVERSION_FACTOR(boost::units::mile_base_unit, boost::units::foot_base_unit, double, 5280.0);
#endif

#if defined(BOOST_UNITS_MILE_BASE_UNIT_HPP) && defined(BOOST_UNITS_INCH_BASE_UNIT_HPP) &&\
    !defined(BOOST_UNITS_SYSTEMS_MILE_TO_INCH_CONVERSION_DEFINED)
    #define BOOST_UNITS_SYSTEMS_MILE_TO_INCH_CONVERSION_DEFINED
    #include <boost/units/conversion.hpp>
    BOOST_UNITS_DEFINE_CONVERSION_FACTOR(boost::units::mile_base_unit, boost::units::inch_base_unit, double, 63360.0);
#endif

#if defined(BOOST_UNITS_YARD_BASE_UNIT_HPP) && defined(BOOST_UNITS_FOOT_BASE_UNIT_HPP) &&\
    !defined(BOOST_UNITS_SYSTEMS_YARD_TO_FOOT_CONVERSION_DEFINED)
    #define BOOST_UNITS_SYSTEMS_YARD_TO_FOOT_CONVERSION_DEFINED
    #include <boost/units/conversion.hpp>
    BOOST_UNITS_DEFINE_CONVERSION_FACTOR(boost::units::yard_base_unit, boost::units::foot_base_unit, double, 3.0);
#endif

#if defined(BOOST_UNITS_YARD_BASE_UNIT_HPP) && defined(BOOST_UNITS_INCH_BASE_UNIT_HPP) &&\
    !defined(BOOST_UNITS_SYSTEMS_YARD_TO_INCH_CONVERSION_DEFINED)
    #define BOOST_UNITS_SYSTEMS_YARD_TO_INCH_CONVERSION_DEFINED
    #include <boost/units/conversion.hpp>
    BOOST_UNITS_DEFINE_CONVERSION_FACTOR(boost::units::yard_base_unit, boost::units::inch_base_unit, double, 36.0);
#endif

#if defined(BOOST_UNITS_FOOT_BASE_UNIT_HPP) && defined(BOOST_UNITS_INCH_BASE_UNIT_HPP) &&\
    !defined(BOOST_UNITS_SYSTEMS_FOOT_TO_INCH_CONVERSION_DEFINED)
    #define BOOST_UNITS_SYSTEMS_FOOT_TO_INCH_CONVERSION_DEFINED
    #include <boost/units/conversion.hpp>
    BOOST_UNITS_DEFINE_CONVERSION_FACTOR(boost::units::foot_base_unit, boost::units::inch_base_unit, double, 12.0);
#endif

// units of time

#if defined(BOOST_UNITS_HOUR_BASE_UNIT_HPP) && defined(BOOST_UNITS_MINUTE_BASE_UNIT_HPP) &&\
    !defined(BOOST_UNITS_SYSTEMS_HOUR_TO_MINUTE_CONVERSION_DEFINED)
    #define BOOST_UNITS_SYSTEMS_HOUR_TO_MINUTE_CONVERSION_DEFINED
    #include <boost/units/conversion.hpp>
    BOOST_UNITS_DEFINE_CONVERSION_FACTOR(boost::units::hour_base_unit, boost::units::minute_base_unit, double, 60.0);
#endif

#if defined(BOOST_UNITS_HOUR_BASE_UNIT_HPP) && defined(BOOST_UNITS_SECOND_BASE_UNIT_HPP) &&\
    !defined(BOOST_UNITS_SYSTEMS_HOUR_TO_SECOND_CONVERSION_DEFINED)
    #define BOOST_UNITS_SYSTEMS_HOUR_TO_SECOND_CONVERSION_DEFINED
    #include <boost/units/conversion.hpp>
    BOOST_UNITS_DEFINE_CONVERSION_FACTOR(boost::units::hour_base_unit, boost::units::second_base_unit, double, 3600.0);
#endif

#if defined(BOOST_UNITS_MINUTE_BASE_UNIT_HPP) && defined(BOOST_UNITS_SECOND_BASE_UNIT_HPP) &&\
    !defined(BOOST_UNITS_SYSTEMS_MINUTE_TO_SECOND_CONVERSION_DEFINED)
    #define BOOST_UNITS_SYSTEMS_MINUTE_TO_SECOND_CONVERSION_DEFINED
    #include <boost/units/conversion.hpp>
    BOOST_UNITS_DEFINE_CONVERSION_FACTOR(boost::units::minute_base_unit, boost::units::second_base_unit, double, 60.0);
#endif

// units of temperature

#if defined(BOOST_UNITS_KELVIN_BASE_UNIT_HPP) && defined(BOOST_UNITS_CELSIUS_BASE_UNIT_HPP) &&\
    !defined(BOOST_UNITS_SYSTEMS_KELVIN_TO_CELSIUS_CONVERSION_DEFINED)
    #define BOOST_UNITS_SYSTEMS_KELVIN_TO_CELSIUS_CONVERSION_DEFINED
    #include <boost/units/conversion.hpp>
    #include <boost/units/absolute.hpp>
    BOOST_UNITS_DEFINE_CONVERSION_FACTOR(boost::units::kelvin_base_unit, boost::units::celsius_base_unit, one, one());
    BOOST_UNITS_DEFINE_CONVERSION_OFFSET(boost::units::kelvin_base_unit, boost::units::celsius_base_unit, double, -273.15);
#endif

#if defined(BOOST_UNITS_KELVIN_BASE_UNIT_HPP) && defined(BOOST_UNITS_FAHRENHEIT_BASE_UNIT_HPP) &&\
    !defined(BOOST_UNITS_SYSTEMS_KELVIN_TO_FAHRENHEIT_CONVERSION_DEFINED)
    #define BOOST_UNITS_SYSTEMS_KELVIN_TO_FAHRENHEIT_CONVERSION_DEFINED
    #include <boost/units/conversion.hpp>
    #include <boost/units/absolute.hpp>
    BOOST_UNITS_DEFINE_CONVERSION_FACTOR(boost::units::kelvin_base_unit, boost::units::fahrenheit_base_unit, double, 9.0/5.0);
    BOOST_UNITS_DEFINE_CONVERSION_OFFSET(boost::units::kelvin_base_unit, boost::units::fahrenheit_base_unit, double, -273.15 * 9.0 / 5.0 + 32.0);
#endif

#if defined(BOOST_UNITS_CELSIUS_BASE_UNIT_HPP) && defined(BOOST_UNITS_FAHRENHEIT_BASE_UNIT_HPP) &&\
    !defined(BOOST_UNITS_SYSTEMS_CELSUIS_TO_FAHRENHEIT_CONVERSION_DEFINED)
    #define BOOST_UNITS_SYSTEMS_CELSUIS_TO_FAHRENHEIT_CONVERSION_DEFINED
    #include <boost/units/conversion.hpp>
    #include <boost/units/absolute.hpp>
    BOOST_UNITS_DEFINE_CONVERSION_FACTOR(boost::units::celsius_base_unit, boost::units::fahrenheit_base_unit, double, 9.0/5.0);
    BOOST_UNITS_DEFINE_CONVERSION_OFFSET(boost::units::celsius_base_unit, boost::units::fahrenheit_base_unit, double, 32.0);
#endif

// units of angle.

#if defined(BOOST_UNITS_RADIAN_BASE_UNIT_HPP) && defined(BOOST_UNITS_DEGREE_BASE_UNIT_HPP) &&\
    !defined(BOOST_UNITS_SYSTEMS_RADIAN_TO_DEGREE_CONVERSION_DEFINED)
    #define BOOST_UNITS_SYSTEMS_RADIAN_TO_DEGREE_CONVERSION_DEFINED
    #include <boost/units/conversion.hpp>
    BOOST_UNITS_DEFINE_CONVERSION_FACTOR(boost::units::radian_base_unit, boost::units::degree_base_unit, double, 180/3.14159265358979323846);
#endif

#if defined(BOOST_UNITS_RADIAN_BASE_UNIT_HPP) && defined(BOOST_UNITS_GRADIAN_BASE_UNIT_HPP) &&\
    !defined(BOOST_UNITS_SYSTEMS_RADIAN_TO_GRADIAN_CONVERSION_DEFINED)
    #define BOOST_UNITS_SYSTEMS_RADIAN_TO_GRADIAN_CONVERSION_DEFINED
    #include <boost/units/conversion.hpp>
    BOOST_UNITS_DEFINE_CONVERSION_FACTOR(boost::units::radian_base_unit, boost::units::gradian_base_unit, double, 200/3.14159265358979323846);
#endif

#if defined(BOOST_UNITS_RADIAN_BASE_UNIT_HPP) && defined(BOOST_UNITS_REVOLUTION_BASE_UNIT_HPP) &&\
    !defined(BOOST_UNITS_SYSTEMS_RADIAN_TO_REVOLUTION_CONVERSION_DEFINED)
    #define BOOST_UNITS_SYSTEMS_RADIAN_TO_REVOLUTION_CONVERSION_DEFINED
    #include <boost/units/conversion.hpp>
    BOOST_UNITS_DEFINE_CONVERSION_FACTOR(boost::units::radian_base_unit, boost::units::revolution_base_unit, double, 0.5/3.14159265358979323846);
#endif

#if defined(BOOST_UNITS_DEGREE_BASE_UNIT_HPP) && defined(BOOST_UNITS_GRADIAN_BASE_UNIT_HPP) &&\
    !defined(BOOST_UNITS_SYSTEMS_DEGREE_TO_GRADIAN_CONVERSION_DEFINED)
    #define BOOST_UNITS_SYSTEMS_DEGREE_TO_GRADIAN_CONVERSION_DEFINED
    #include <boost/units/conversion.hpp>
    BOOST_UNITS_DEFINE_CONVERSION_FACTOR(boost::units::degree_base_unit, boost::units::gradian_base_unit, double, 10/9.);
#endif

#if defined(BOOST_UNITS_DEGREE_BASE_UNIT_HPP) && defined(BOOST_UNITS_REVOLUTION_BASE_UNIT_HPP) &&\
    !defined(BOOST_UNITS_SYSTEMS_DEGREE_TO_REVOLUTION_CONVERSION_DEFINED)
    #define BOOST_UNITS_SYSTEMS_DEGREE_TO_REVOLUTION_CONVERSION_DEFINED
    #include <boost/units/conversion.hpp>
    BOOST_UNITS_DEFINE_CONVERSION_FACTOR(boost::units::degree_base_unit, boost::units::revolution_base_unit, double, 1/360.);
#endif

#if defined(BOOST_UNITS_GRADIAN_BASE_UNIT_HPP) && defined(BOOST_UNITS_REVOLUTION_BASE_UNIT_HPP) &&\
    !defined(BOOST_UNITS_SYSTEMS_GRADIAN_TO_REVOLUTION_CONVERSION_DEFINED)
    #define BOOST_UNITS_SYSTEMS_GRADIAN_TO_REVOLUTION_CONVERSION_DEFINED
    #include <boost/units/conversion.hpp>
    BOOST_UNITS_DEFINE_CONVERSION_FACTOR(boost::units::gradian_base_unit, boost::units::revolution_base_unit, double, 1/400.);
#endif
