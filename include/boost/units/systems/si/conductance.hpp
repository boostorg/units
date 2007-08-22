// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_SI_CONDUCTANCE_HPP
#define BOOST_UNITS_SI_CONDUCTANCE_HPP

#include <boost/units/derived_dimension.hpp>
#include <boost/units/systems/si/base.hpp>

namespace boost {

namespace units { 

namespace SI {

/// conductance : L^-2 M^-1 T^3 I^2
typedef derived_dimension<length_base_dimension,-2,mass_base_dimension,-1,time_base_dimension,3,current_base_dimension,2>::type   conductance_type;                    

typedef unit<SI::conductance_type,SI::system>                                           conductance;

BOOST_UNITS_STATIC_CONSTANT(siemen,conductance);    
BOOST_UNITS_STATIC_CONSTANT(siemens,conductance);   
BOOST_UNITS_STATIC_CONSTANT(mho,conductance);   
BOOST_UNITS_STATIC_CONSTANT(mhos,conductance);  

} // namespace SI

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_SI_CONDUCTANCE_HPP
