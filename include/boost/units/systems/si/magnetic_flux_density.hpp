// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_SI_MAGNETIC_FLUX_DENSITY_HPP
#define BOOST_UNITS_SI_MAGNETIC_FLUX_DENSITY_HPP

#include <ostream>
#include <boost/units/io.hpp>

#include <boost/units/systems/si/base.hpp>
#include <boost/units/physical_dimensions/magnetic_flux_density.hpp>

namespace boost {

namespace units { 

namespace si {

typedef unit<magnetic_flux_density_type,si::system>    magnetic_flux_density;
    
BOOST_UNITS_STATIC_CONSTANT(tesla,magnetic_flux_density);   
BOOST_UNITS_STATIC_CONSTANT(teslas,magnetic_flux_density);  

} // namespace si

inline std::ostream& operator<<(std::ostream& os, const boost::units::si::magnetic_flux_density&) 
{
    return(os << "T");
}

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_SI_MAGNETIC_FLUX_DENSITY_HPP
