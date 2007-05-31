// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_CGS_MOMENTUM_HPP
#define BOOST_UNITS_CGS_MOMENTUM_HPP

#include <boost/units/systems/cgs/base.hpp>
#include <boost/units/systems/derived_dimensions/momentum_derived_dimension.hpp>

namespace boost {

namespace units { 

namespace CGS {

typedef unit<momentum_dimension,CGS::system>     momentum;

} // namespace CGS

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_CGS_MOMENTUM_HPP
