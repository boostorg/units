// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_SI_MAGNETIC_FLUX_HPP
#define BOOST_UNITS_SI_MAGNETIC_FLUX_HPP

#include <boost/units/systems/si/base.hpp>

namespace boost {

namespace units { 

namespace SI {

/// magnetic flux : L^2 M T^-2 C^-1
typedef composite_dimension<length_tag,2,mass_tag,1,time_tag,-2,current_tag,-1>::type   magnetic_flux_type;            

typedef unit<SI::magnetic_flux_type,SI::system>                                         magnetic_flux;
    
BOOST_UNITS_STATIC_CONSTANT(weber,magnetic_flux);   
BOOST_UNITS_STATIC_CONSTANT(webers,magnetic_flux);  

} // namespace SI

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_SI_MAGNETIC_FLUX_HPP
