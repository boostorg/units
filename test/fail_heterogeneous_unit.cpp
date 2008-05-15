// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

/** 
\file
    
\brief fail_heterogeneous_unit.cpp

\detailed
make sure that trying to bind a heterogeneous system to a different dimension fails.

Output:
@verbatim
@endverbatim
**/

#include <boost/units/quantity.hpp>
#include <boost/units/systems/si.hpp>
#include <boost/units/systems/cgs.hpp>
//#include <boost/units/systems/conversions/convert_cgs_to_si.hpp>
//#include <boost/units/systems/conversions/convert_si_to_cgs.hpp>

namespace bu = boost::units;

template<class System>
bu::quantity<bu::unit<bu::energy_dimension, System> > f(bu::quantity<bu::unit<bu::length_dimension, System> > l) {
    return(static_cast<bu::quantity<bu::unit<bu::energy_dimension, System> > >(f(static_cast<bu::quantity<bu::SI::length> >(l))));
}
bu::quantity<bu::SI::energy> f(bu::quantity<bu::SI::length> l) {
    return(l * l * 2.0 * bu::SI::kilograms / bu::pow<2>(bu::SI::seconds));
}

int main() {

    f(1.0 * bu::pow<2>(bu::SI::meters) / bu::CGS::centimeters);

    return(0);
}
