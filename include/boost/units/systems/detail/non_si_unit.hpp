// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2007-2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNIT_SYSTEMS_OTHER_NON_SI_UNIT_HPP_INCLUDED
#define BOOST_UNIT_SYSTEMS_OTHER_NON_SI_UNIT_HPP_INCLUDED

#include <boost/units/conversion.hpp>

//#define BOOST_UNITS_NON_SI_UNIT(namespace_, name_, symbol_, factor, unit, id)\
//namespace boost {                                                           \
//namespace units {                                                           \
//namespace namespace_ {                                                      \
//struct name_ ## _base_unit                                                  \
//  : base_unit<name_ ## _base_unit, unit::dimension_type, id - 100> {        \
//    static const char* name() { return(#name_); }                           \
//    static const char* symbol() { return(#symbol_); };                      \
//};                                                                          \
//}                                                                           \
//}                                                                           \
//}                                                                           \
//BOOST_UNITS_DEFINE_CONVERSION_FACTOR(namespace_::name_ ## _base_unit, unit, double, factor); \
//BOOST_UNITS_DEFAULT_CONVERSION(namespace_::name_ ## _base_unit, unit)

#define BOOST_UNITS_NON_SI_UNIT(namespace_, name_, name_string_, symbol_string_, factor, unit, id)\
namespace boost {                                                           \
namespace units {                                                           \
namespace namespace_ {                                                      \
struct name_ ## _base_unit                                                  \
  : base_unit<name_ ## _base_unit, unit::dimension_type, id - 100> {        \
    static const char* name() { return(name_string_); }                     \
    static const char* symbol() { return(symbol_string_); };                \
};                                                                          \
}                                                                           \
}                                                                           \
}                                                                           \
BOOST_UNITS_DEFINE_CONVERSION_FACTOR(namespace_::name_ ## _base_unit, unit, double, factor); \
BOOST_UNITS_DEFAULT_CONVERSION(namespace_::name_ ## _base_unit, unit)

#endif
