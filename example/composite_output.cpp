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
#include <boost/units/scale.hpp>

#include <boost/units/detail/utility.hpp>

#include <boost/units/systems/si/capacitance.hpp>
#include <boost/units/systems/si/io.hpp>
#include <boost/units/systems/si/prefixes.hpp>

#include <iostream>
#include <sstream>

namespace boost {

namespace units {

//[composite_output_snippet_1

template<>
std::string name_string(const cgs::force&)
{
	return "dyne";
}

template<>
std::string symbol_string(const cgs::force&)
{
	return "dyn";
}

//]

}

}

int main() 
{
	using namespace boost::units;
	using boost::units::cgs::centimeter;
	using boost::units::cgs::gram;
	using boost::units::cgs::second;
	using boost::units::cgs::dyne;
		
	si::nano*si::farad;
	1.0*si::nano*si::farad;
	
    std::cout << 2.0 * dyne << std::endl;

    std::cout << symbol_format << 2.0 * dyne << std::endl;
    std::cout << name_format << 2.0 * dyne << std::endl;
	
	std::cout << symbol_string(dyne) << std::endl;
	std::cout << name_string(dyne) << std::endl;
	
	std::cout << symbol_string(gram*centimeter/second) << std::endl;
	std::cout << name_string(gram*centimeter/second) << std::endl;
	
	std::cout << symbol_string(gram*centimeter/(second*second)) << std::endl;
	std::cout << name_string(gram*centimeter/(second*second)) << std::endl;
	
	std::cout << symbol_string(scale<10,static_rational<-9> >()) << std::endl;
	std::cout << name_string(scale<10,static_rational<-9> >()) << std::endl;

	// wrong! - should output "n" and "nano", respectively
	std::cout << simplify_typename(si::nano) << std::endl;
	
	std::cout << symbol_string(si::nano) << std::endl;
	std::cout << name_string(si::nano) << std::endl;
	
	std::cout << name_format << si::farad << std::endl;
	std::cout << symbol_format << si::farad << std::endl;
	
	std::cout << name_format << 1.0*si::farad << std::endl;
	std::cout << symbol_format << 1.0*si::farad << std::endl;
	
	// wrong! - should output "nF" and "nanofarad", respectively
	std::cout << symbol_string(si::farad*si::nano) << std::endl;
	std::cout << name_string(si::farad*si::nano) << std::endl;
	
	// doesn't work because we can't make assumptions about how user wants value() to be formatted
//	std::cout << symbol_string(si::nano*1.0*si::farad) << std::endl;
//	std::cout << name_string(1.0*si::nano*si::farad) << std::endl;

	// wrong! - should output "n(cm g s^-1)" and "nano(centimeter gram second^-1)", respectively
	std::cout << symbol_string(si::nano*gram*centimeter/second) << std::endl;
	std::cout << name_string(si::nano*gram*centimeter/second) << std::endl;
}
