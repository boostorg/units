// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_CONVERT_RADIANS_TO_DEGREES_HPP
#define BOOST_UNITS_CONVERT_RADIANS_TO_DEGREES_HPP

#include <boost/units/conversion.hpp>
#include <boost/units/systems/angles/degrees.hpp>
#include <boost/units/systems/angles/radians.hpp>

namespace boost {

namespace units { 

// conversions from radians to degrees

template<>
struct base_unit_converter<angle_tag,angle::radian_system_tag,angle::degree_system_tag>
#ifdef BOOST_UNITS_ENABLE_IMPLICIT_UNIT_CONVERSION
    : public implicitly_convertible, trivial_inverse_conversion
#endif
{
    typedef double type;
    static type value() { return 180.0/3.1415926535897932385; }
};
        
} // namespace units

} // namespace boost

#endif // BOOST_UNITS_CONVERT_RADIANS_TO_DEGREES_HPP
