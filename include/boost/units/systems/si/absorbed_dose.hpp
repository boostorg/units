// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_SI_ABSORBED_DOSE_HPP
#define BOOST_UNITS_SI_ABSORBED_DOSE_HPP

#include <boost/units/systems/si/base.hpp>
#include <boost/units/systems/derived_dimensions/absorbed_dose_derived_dimension.hpp>

namespace boost {

namespace units { 

namespace SI {

typedef unit<absorbed_dose_dimension,SI::system>     absorbed_dose;
    
BOOST_UNITS_STATIC_CONSTANT(gray,absorbed_dose);  
BOOST_UNITS_STATIC_CONSTANT(grays,absorbed_dose); 

} // namespace SI

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_SI_ABSORBED_DOSE_HPP
