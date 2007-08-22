// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_SI_ELECTRIC_CHARGE_HPP
#define BOOST_UNITS_SI_ELECTRIC_CHARGE_HPP

#include <boost/units/derived_dimension.hpp>
#include <boost/units/systems/si/base.hpp>

namespace boost {

namespace units { 

namespace SI {

/// electric charge : T^1 I^1
typedef derived_dimension<time_base_dimension,1,current_base_dimension,1>::type     electric_charge_type;        

typedef unit<SI::electric_charge_type,SI::system>               electric_charge;
    
BOOST_UNITS_STATIC_CONSTANT(coulomb,electric_charge);   
BOOST_UNITS_STATIC_CONSTANT(coulombs,electric_charge);  

} // namespace SI

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_SI_ELECTRIC_CHARGE_HPP
