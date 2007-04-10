// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_CONVERT_CGS_TO_SI_HPP
#define BOOST_UNITS_CONVERT_CGS_TO_SI_HPP

#include <boost/units/conversion.hpp>
#include <boost/units/systems/cgs/base.hpp>
#include <boost/units/systems/si/base.hpp>

namespace boost {

namespace units { 

// conversions from CGS to SI units

template<>
struct base_unit_converter<length_dim,CGS::system_tag,SI::system_tag>
#ifdef BOOST_UNITS_ENABLE_IMPLICIT_UNIT_CONVERSION
    : public implicitly_convertible
#endif
{
    typedef double type;
    static type value() { return(.01); }
};

template<>
struct base_unit_converter<mass_dim,CGS::system_tag,SI::system_tag>
#ifdef BOOST_UNITS_ENABLE_IMPLICIT_UNIT_CONVERSION
    : public implicitly_convertible
#endif
{
    typedef double type;
    static type value() { return(.001); }
};

template<>
struct base_unit_converter<time_dim,CGS::system_tag,SI::system_tag> :
    public implicitly_convertible,
    public trivial_conversion
{ };
        
} // namespace units

} // namespace boost

#endif // BOOST_UNITS_CONVERT_CGS_TO_SI_HPP
