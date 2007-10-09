// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <map>
#include <iostream>
#include <boost/lexical_cast.hpp>
#include <boost/units/quantity.hpp>
#include <boost/units/cmath.hpp>
#include <boost/units/systems/si/length.hpp>
#include <boost/units/systems/base_units.hpp>

//[runtime_unit_snippet_1

namespace {

std::map<std::string, boost::units::quantity<boost::units::SI::length> > known_units;

}

boost::units::quantity<boost::units::SI::length> calculate(const boost::units::quantity<boost::units::SI::length>& t) {
    return(boost::units::hypot(t, 2.0 * boost::units::SI::meters));
}

int main() {
    known_units["meter"] = 1.0 * boost::units::SI::meters;
    known_units["centimeter"] = .01 * boost::units::SI::meters;;
    known_units["foot"] = conversion_factor(boost::units::foot_base_unit::unit_type(), boost::units::SI::meter) * boost::units::SI::meters;;
    std::string output_type("meter");
    std::string input;
    while((std::cout << ">") && (std::cin >> input)) {
        if(input == "exit") break;
        else if(input == "help") {
            std::cout << "type \"exit\" to exit\n"
                "type \"return 'unit'\" to set the return units\n"
                "type \"'number' 'unit'\" to do a simple calculation" << std::endl;
        } else if(input == "return") {
            if(std::cin >> input) {
                if(known_units.find(input) != known_units.end()) {
                    output_type = input;
                    std::cout << "Done." << std::endl;
                } else {
                    std::cout << "Unknown unit \"" << input << "\"" << std::endl;
                }
            } else break;
        } else {
            try {
                double value = boost::lexical_cast<double>(input);
                if(std::cin >> input) {
                    if(known_units.find(input) != known_units.end()) {
                        std::cout << static_cast<double>(calculate(value * known_units[input]) / known_units[output_type]) << ' ' << output_type << std::endl;
                    } else {
                        std::cout << "Unknown unit \"" << input << "\"" << std::endl;
                    }
                } else break;
            } catch(...) {
                std::cout << "Input error" << std::endl;
            }
        }
    }
}

//]
