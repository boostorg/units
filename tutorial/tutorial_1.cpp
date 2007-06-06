// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>

#include <boost/units/base_dimension.hpp>
#include <boost/units/derived_dimension.hpp>
#include <boost/units/io.hpp>
#include <boost/units/quantity.hpp>
#include <boost/units/static_constant.hpp>
#include <boost/units/unit.hpp>
#include <boost/units/base_unit.hpp>
#include <boost/units/make_system.hpp>

namespace boost {

namespace units {

struct length_base_dimension : boost::units::base_dimension<length_base_dimension,1> { };       ///> base dimension of length
struct mass_base_dimension : boost::units::base_dimension<mass_base_dimension,2> { };           ///> base dimension of mass
struct time_base_dimension : boost::units::base_dimension<time_base_dimension,3> { };           ///> base dimension of time

typedef length_base_dimension::type    length_dimension;
typedef mass_base_dimension::type      mass_dimension;
typedef time_base_dimension::type      time_dimension;

struct centimeter_base_unit : base_unit<centimeter_base_unit,length_dimension,1> { };
struct gram_base_unit : base_unit<gram_base_unit,mass_dimension,2> { };
struct second_base_unit : base_unit<second_base_unit,time_dimension,3> { };

namespace CG {

typedef make_system<centimeter_base_unit,
                    gram_base_unit>::type   system;

/// unit typedefs
typedef unit<dimensionless_type,system>     dimensionless;

typedef unit<length_dimension,system>       length;
typedef unit<mass_dimension,system>         mass;

/// unit constants 
BOOST_UNITS_STATIC_CONSTANT(centimeter,length);
BOOST_UNITS_STATIC_CONSTANT(gram,mass);

} // namespace CGS

namespace CGS {

typedef make_system<centimeter_base_unit,
                    gram_base_unit,
                    second_base_unit>::type system;

/// unit typedefs
typedef unit<dimensionless_type,system>     dimensionless;

typedef unit<length_dimension,system>       length;
typedef unit<mass_dimension,system>         mass;
typedef unit<time_dimension,system>         time;

/// unit constants 
BOOST_UNITS_STATIC_CONSTANT(centimeter,length);
BOOST_UNITS_STATIC_CONSTANT(gram,mass);
BOOST_UNITS_STATIC_CONSTANT(second,time);

} // namespace CGS

namespace esu {

/// derived dimension for charge in electrostatic units : L^3/2 M^1/2 T^-1
typedef make_dimension_list< mpl::list< dim<length_base_dimension,static_rational<3,2> >,
                                        dim<mass_base_dimension,static_rational<1,2> >,
                                        dim<time_base_dimension,static_rational<-1> > > >::type    charge_dimension; 

typedef unit<charge_dimension,CGS::system>  charge;

} // namespace esu

template<> struct base_unit_info<centimeter_base_unit>
{
    static std::string name()               { return "centimeter"; }
    static std::string symbol()             { return "cm"; }
};

template<> struct base_unit_info<gram_base_unit>
{
    static std::string name()               { return "gram"; }
    static std::string symbol()             { return "g"; }
};

template<> struct base_unit_info<second_base_unit>
{
    static std::string name()               { return "second"; }
    static std::string symbol()             { return "s"; }
};

} // namespace units

} // namespace boost

int main(void)
{
    using namespace boost::units;
    using namespace boost::units::CGS;

    quantity<CG::length>    cg_length(1.5*CG::centimeter);
    quantity<CGS::length>   cgs_length(1.5*CGS::centimeter);
    
    std::cout << cg_length/cgs_length << std::endl;

    //std::cout << root<2>(gram*pow<3>(centimeter)/pow<2>(second)) << std::endl;
    
    return 0;
}

