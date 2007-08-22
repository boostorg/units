// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_SI_CATALYTIC_ACTIVITY_HPP
#define BOOST_UNITS_SI_CATALYTIC_ACTIVITY_HPP

#include <boost/units/derived_dimension.hpp>
#include <boost/units/systems/si/base.hpp>

namespace boost {

namespace units { 

namespace SI {

/// catalytic activity : T^-1 A^1
typedef derived_dimension<time_base_dimension,-1,amount_base_dimension,1>::type                             catalytic_activity_dim;    

typedef unit<SI::catalytic_activity_dim,SI::system>                                    catalytic_activity;

BOOST_UNITS_STATIC_CONSTANT(katal,catalytic_activity);
BOOST_UNITS_STATIC_CONSTANT(katals,catalytic_activity);

} // namespace SI

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_SI_CATALYTIC_ACTIVITY_HPP
