// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_SI_MAGNETIC_FIELD_INTENSITY_HPP
#define BOOST_UNITS_SI_MAGNETIC_FIELD_INTENSITY_HPP

#include <boost/units/derived_dimension.hpp>
#include <boost/units/systems/si/base.hpp>

namespace boost {

namespace units { 

namespace SI {

/// magnetic field intensity : L^-1 I
typedef derived_dimension<length_base_dimension,-1,current_base_dimension,1>::type                          magnetic_field_intensity_type;

typedef unit<SI::magnetic_field_intensity_type,SI::system>                              magnetic_field_intensity;
                                            
} // namespace SI

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_SI_MAGNETIC_FIELD_INTENSITY_HPP
