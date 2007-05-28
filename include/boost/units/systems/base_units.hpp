// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_OTHER_UNITS_HPP_INCLUDED
#define BOOST_UNITS_OTHER_UNITS_HPP_INCLUDED

#include <string>

#include <boost/units/config.hpp>
#include <boost/units/base_unit.hpp>
#include <boost/units/scaled_base_unit.hpp>
#include <boost/units/systems/physical_units.hpp>

namespace boost {

namespace units {

struct meter_tag : public base_unit<meter_tag, length_type, -20> {
    static std::string name() { return("meter"); }
    static std::string symbol() { return("m"); }
};
struct foot_tag : public base_unit<foot_tag, length_type, -19> {
    static std::string name() { return("foot"); }
    static std::string symbol() { return("ft"); }
};
struct inch_tag : public base_unit<inch_tag, length_type, -18> {
    static std::string name() { return("inch"); }
    static std::string symbol() { return("in"); }
};
struct yard_tag : public base_unit<yard_tag, length_type, -17> {
    static std::string name() { return("yard"); }
    static std::string symbol() { return("yd"); }
};
struct mile_tag : public base_unit<mile_tag, length_type, -16> {
    static std::string name() { return("mile"); }
    static std::string symbol() { return("mi"); }
};
typedef scaled_base_unit<meter_tag, scale<10, static_rational<-2> > > centimeter_tag;

struct gram_tag : public base_unit<gram_tag, mass_type, -15> {
    static std::string name() { return("gram"); }
    static std::string symbol() { return("g"); }
};
typedef scaled_base_unit<gram_tag, scale<10, static_rational<3> > > kilogram_tag;

struct second_tag : public base_unit<second_tag, time_type, -14> {
    static std::string name() { return("second"); }
    static std::string symbol() { return("s"); }
};
struct minute_tag : public base_unit<minute_tag, time_type, -13> {
    static std::string name() { return("minute"); }
    static std::string symbol() { return("min"); }
};
struct hour_tag : public base_unit<hour_tag, time_type, -12> {
    static std::string name() { return("foot"); }
    static std::string symbol() { return("ft"); }
};

struct ampere_tag : public base_unit<ampere_tag, current_type, -11> {
    static std::string name() { return("ampere"); }
    static std::string symbol() { return("A"); }
};
struct biot_tag : public base_unit<biot_tag, current_type, -10> {
    static std::string name() { return("biot"); }
    //static std::string symbol() { return(""); }
};

struct kelvin_tag : public base_unit<kelvin_tag, temperature_type, -9> {
    static std::string name() { return("kelvin"); }
    static std::string symbol() { return("K"); }
};
struct fahrenheit_tag : public base_unit<fahrenheit_tag, temperature_type, -8> {
    static std::string name() { return("fahrenheit"); }
    static std::string symbol() { return("F"); }
};

struct mole_tag : public base_unit<mole_tag, amount_type, -7> {
    static std::string name() { return("mole"); }
    static std::string symbol() { return("mol"); }
};

struct candela_tag : public base_unit<candela_tag, luminous_intensity_type, -6> {
    static std::string name() { return("candela"); }
    static std::string symbol() { return("cd"); }
};

struct radian_tag : public base_unit<radian_tag, plane_angle_type, -5> {
    static std::string name() { return("radian"); }
    static std::string symbol() { return("rad"); }
};
struct degree_tag : public base_unit<degree_tag, plane_angle_type, -4> {
    static std::string name() { return("degree"); }
    static std::string symbol() { return("deg"); }
};
struct gradian_tag : public base_unit<gradian_tag, plane_angle_type, -3> {
    static std::string name() { return("gradian"); }
    static std::string symbol() { return("grad"); }
};

struct steradian_tag : public base_unit<steradian_tag, solid_angle_type, -2> {
    static std::string name() { return("steradian"); }
    static std::string symbol() { return("sr"); }
};

}

}

BOOST_UNITS_DEFINE_CONVERSION(boost::units::radian_tag, boost::units::degree_tag::unit_type, double, 180/3.14159265358979323846);
BOOST_UNITS_DEFINE_CONVERSION(boost::units::radian_tag, boost::units::gradian_tag::unit_type, double, 200/3.14159265358979323846);
BOOST_UNITS_DEFINE_CONVERSION(boost::units::degree_tag, boost::units::gradian_tag::unit_type, double, 10/9.);

#if BOOST_UNITS_HAS_BOOST_TYPEOF

#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

BOOST_TYPEOF_REGISTER_TYPE(boost::units::meter_tag)
BOOST_TYPEOF_REGISTER_TYPE(boost::units::foot_tag)
BOOST_TYPEOF_REGISTER_TYPE(boost::units::inch_tag)
BOOST_TYPEOF_REGISTER_TYPE(boost::units::yard_tag)
BOOST_TYPEOF_REGISTER_TYPE(boost::units::mile_tag)

BOOST_TYPEOF_REGISTER_TYPE(boost::units::gram_tag)

BOOST_TYPEOF_REGISTER_TYPE(boost::units::second_tag)
BOOST_TYPEOF_REGISTER_TYPE(boost::units::minute_tag)
BOOST_TYPEOF_REGISTER_TYPE(boost::units::hour_tag)

BOOST_TYPEOF_REGISTER_TYPE(boost::units::ampere_tag)
BOOST_TYPEOF_REGISTER_TYPE(boost::units::biot_tag)

BOOST_TYPEOF_REGISTER_TYPE(boost::units::kelvin_tag)
BOOST_TYPEOF_REGISTER_TYPE(boost::units::fahrenheit_tag)

BOOST_TYPEOF_REGISTER_TYPE(boost::units::mole_tag)

BOOST_TYPEOF_REGISTER_TYPE(boost::units::candela_tag)

BOOST_TYPEOF_REGISTER_TYPE(boost::units::radian_tag)
BOOST_TYPEOF_REGISTER_TYPE(boost::units::degree_tag)
BOOST_TYPEOF_REGISTER_TYPE(boost::units::gradian_tag)

BOOST_TYPEOF_REGISTER_TYPE(boost::units::steradian_tag)

#endif

#endif
