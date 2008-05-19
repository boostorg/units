// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_SI_PERMEABILITY_HPP
#define BOOST_UNITS_SI_PERMEABILITY_HPP

#include <iostream>
#include <boost/units/io.hpp>

#include <boost/units/derived_dimension.hpp>
#include <boost/units/systems/si/base.hpp>

namespace boost {

namespace units { 

namespace si {

/// permeability : L M T^-2 I^-2
typedef derived_dimension<length_base_dimension,1,mass_base_dimension,1,time_base_dimension,-2,current_base_dimension,-2>::type   permeability_type;

typedef unit<si::permeability_type,si::system>                                          permeability;

} // namespace si

std::ostream& operator<<(std::ostream& os, const boost::units::si::permeability&) 
{
    return(os << "H/m");
}

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_SI_PERMEABILITY_HPP
