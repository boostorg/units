// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/units/quantity.hpp>
#include <boost/units/systems/cgs.hpp>
#include <boost/units/io.hpp>
#include <iostream>

namespace boost {

namespace units {

//[composite_output_snippet_1

std::ostream& operator<<(std::ostream& os, const boost::units::cgs::force&) {
    return(os << "dyn");
}

//]

}

}

int main() {
    std::cout << 2.0 * boost::units::cgs::dyne << std::endl;
}
