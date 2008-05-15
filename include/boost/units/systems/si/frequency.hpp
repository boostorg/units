// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_SI_FREQUENCY_HPP
#define BOOST_UNITS_SI_FREQUENCY_HPP

#include <boost/units/systems/si/base.hpp>
#include <boost/units/systems/physical_dimensions/frequency.hpp>

namespace boost {

namespace units { 

namespace SI {

typedef unit<frequency_dimension,SI::system>     frequency;
    
BOOST_UNITS_STATIC_CONSTANT(hertz,frequency);   

} // namespace SI

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_SI_FREQUENCY_HPP
