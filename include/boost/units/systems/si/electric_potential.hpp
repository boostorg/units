// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_SI_ELECTRIC_POTENTIAL_HPP
#define BOOST_UNITS_SI_ELECTRIC_POTENTIAL_HPP

#include <boost/units/derived_dimension.hpp>
#include <boost/units/systems/si/base.hpp>

namespace boost {

namespace units { 

namespace SI {

/// electric potential : L^2 M T^-3 I^-1
typedef derived_dimension<length_base_dimension,2,mass_base_dimension,1,time_base_dimension,-3,current_base_dimension,-1>::type   electric_potential_type;        

typedef unit<SI::electric_potential_type,SI::system>                                    electric_potential;
    
BOOST_UNITS_STATIC_CONSTANT(volt,electric_potential);   
BOOST_UNITS_STATIC_CONSTANT(volts,electric_potential);  

} // namespace SI

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_SI_ELECTRIC_POTENTIAL_HPP
