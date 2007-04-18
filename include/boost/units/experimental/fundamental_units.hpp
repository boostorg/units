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

namespace boost {

namespace units {

struct meter_tag : public ordinal<1> {};
struct foot_tag : public ordinal<2> {};
struct inch_tag : public ordinal<3> {};
struct yard_tag : public ordinal<4> {};
struct mile_tag : public ordinal<5> {};

struct gram_tag : public ordinal<6> {};
struct slug_tag : public ordinal<7> {};

struct second_tag : public ordinal<8> {};
struct minute_tag : public ordinal<9> {};
struct hour_tag : public ordinal<10> {};

struct ampere_tag : public ordinal<11> {};
struct biot_tag : public ordinal<12> {};

struct kelvin_tag : public ordinal<13> {};

struct mole_tag : public ordinal<14> {};

struct candela_tag : public ordinal<15> {};

struct radian_tag : public ordinal<16> {};
struct degree_tag : public ordinal<17> {};
struct gradian_tag : public ordinal<18> {};

struct steradian_tag : public ordinal<19> {};

}

}

#endif
