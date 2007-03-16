// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_CGS_CATALYTIC_ACTIVITY_HPP
#define BOOST_UNITS_CGS_CATALYTIC_ACTIVITY_HPP

#include <boost/units/systems/cgs/base.hpp>

namespace boost {

namespace units { 

namespace CGS {

/// catalytic activity : T^-1 A^1
typedef composite_dimension<time_tag,-1,amount_tag,1>::type                             catalytic_activity_type;    

typedef unit<CGS::catalytic_activity_type,CGS::system>                                  catalytic_activity;

} // namespace SI

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_CGS_CATALYTIC_ACTIVITY_HPP
