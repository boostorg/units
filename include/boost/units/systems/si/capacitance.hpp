// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_SI_CAPACITANCE_HPP
#define BOOST_UNITS_SI_CAPACITANCE_HPP

#include <boost/units/derived_dimension.hpp>
#include <boost/units/systems/si/base.hpp>

namespace boost {

namespace units { 

namespace SI {

/// capacitance : L^-2 M^-1 T^4 I^2
typedef derived_dimension<length_base_dimension,-2,mass_base_dimension,-1,time_base_dimension,4,current_base_dimension,2>::type   capacitance_type;            

typedef unit<SI::capacitance_type,SI::system>                                           capacitance;
    
BOOST_UNITS_STATIC_CONSTANT(farad,capacitance);
BOOST_UNITS_STATIC_CONSTANT(farads,capacitance);

} // namespace SI

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_SI_CAPACITANCE_HPP
