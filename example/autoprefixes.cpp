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
    
\brief Example of using autoprefixes.

\details
Example of using engineering (10^3) and binary (2^10) autoprefixes.

Output:
@verbatim

//[autoprefixes_output
L             = m
meter*meter   = m^2
M*(L/T)*(L/T) = m^2 kg s^-2
M*(L/T)^2     = m^2 kg s^-2
L^3           = m^3
L^(3/2)       = m^(3/2)
2vM           = kg^(1/2)
(3/2)vM       = kg^(2/3)
//] [/autoprefixes_output

@endverbatim
**/

#include <iostream>

#include <boost/units/io.hpp>
#include <boost/units/pow.hpp>
#include <boost/units/systems/si.hpp>
#include <boost/units/systems/si/io.hpp>
#include <boost/units/quantity.hpp>

struct byte_base_unit : boost::units::base_unit<byte_base_unit, boost::units::dimensionless_type, 3>
{
    static const char* name() { return("byte"); }
    static const char* symbol() { return("b"); }
};

int main()
{
  using std::cout;
  using std::endl;
  using namespace boost::units;
  using namespace boost::units::si;

  using boost::units::binary_prefix;
  using boost::units::engineering_prefix;

 //[autoprefixes_snippet_1
  quantity<length> l = 2.345 * meters;   // A quantity of length, in units of meters.
  cout << boost::units::engineering_prefix << l << endl; // Outputs "2.345 m".
  //l = l * 1000; // Increase it by 1000, so expect a k prefix.// Note Fails if integer.

  l =  1000. * l; // Increase it by 1000, so expect a k prefix.
  cout << boost::units::engineering_prefix << l << endl; // Output autoprefixed with k to "2.345 km".

  quantity<energy> e = kilograms * pow<2>(l / seconds); // A quantity of energy.
  cout << boost::units::engineering_prefix << e << endl; // 5.49902 MJ
  cout << name_format << boost::units::engineering_prefix << e << endl; // 5.49902 megaJoule

  //] [/autoprefixes_snippet_1]

 
  //[autoprefixes_snippet_2
  // Don't forget that the name or symbol format specification is persistent.
  cout << symbol_format << endl; // So this resets the format to the default symbol.

  quantity<byte_base_unit, dimensionless> b = 2048. * byte_base_unit::unit_type();

  cout << b << endl; 
  cout << symbol_format << binary_prefix << b << endl; //  "2 kibibyte" 


  //] [/autoprefixes_snippet_2]

  //[autoprefixes_snippet_3
  // Note that scalar dimensionless values are *not* prefixed automatically by the engineering_prefix or binary_prefix iostream manipulators.
  const double s1 = 2345.6;
  const long x1 = 23456;
  cout << boost::units::engineering_prefix << s1 << endl; // 2345.6
  cout << boost::units::engineering_prefix << x1 << endl; // 23456

  cout << boost::units::binary_prefix << s1 << endl; // 2345.6
  cout << boost::units::binary_prefix << x1 << endl; // 23456

  const length L; // A unit of length (but not a quantity of length).
  cout << L << endl; // default length unit is meter,
  // but default is symbol format so output is just "m".
  cout << name_format << L << endl; // default length name is "meter".
  //] [/autoprefixes_snippet_3]

 
    return 0;
} // int main()

