// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_CONVERT_SI_TO_TRIG_HPP
#define BOOST_UNITS_CONVERT_SI_TO_TRIG_HPP

#include <boost/units/systems/trig.hpp>
#include <boost/units/systems/si/angle.hpp>

namespace boost {

namespace units { 

/// implicitly convert SI system radians to angle system radians
template<>
struct base_unit_converter<angle_tag,SI::system_tag,angle::radian_system_tag> :
    public implicitly_convertible,
    public trivial_conversion
{ };

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_CONVERT_SI_TO_TRIG_HPP
