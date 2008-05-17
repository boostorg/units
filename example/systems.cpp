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
    
\brief systems.cpp

\detailed
Test various non-SI units

Output:
@verbatim

//[radar_beam_height_output
***
//]

@endverbatim
**/

#include <iostream>
#include <sstream>
#include <algorithm>

#include <boost/units/conversion.hpp>
#include <boost/units/io.hpp>
#include <boost/units/pow.hpp>

#include <boost/units/systems/si.hpp>

#include <boost/units/systems/angle/base_units/arcminute.hpp>
#include <boost/units/systems/angle/base_units/arcsecond.hpp>
#include <boost/units/systems/angle/base_units/degree.hpp>
#include <boost/units/systems/angle/base_units/gradian.hpp>
#include <boost/units/systems/angle/base_units/revolution.hpp>
#include <boost/units/systems/angle/base_units/radian.hpp>
#include <boost/units/systems/angle/base_units/steradian.hpp>

#include <boost/units/systems/astronomical/base_units/astronomical_unit.hpp>
#include <boost/units/systems/astronomical/base_units/light_second.hpp>
#include <boost/units/systems/astronomical/base_units/light_minute.hpp>
#include <boost/units/systems/astronomical/base_units/light_hour.hpp>
#include <boost/units/systems/astronomical/base_units/light_day.hpp>
#include <boost/units/systems/astronomical/base_units/light_year.hpp>
#include <boost/units/systems/astronomical/base_units/parsec.hpp>

#include <boost/units/systems/imperial/base_units/thou.hpp>
#include <boost/units/systems/imperial/base_units/inch.hpp>
#include <boost/units/systems/imperial/base_units/foot.hpp>
#include <boost/units/systems/imperial/base_units/yard.hpp>
#include <boost/units/systems/imperial/base_units/furlong.hpp>
#include <boost/units/systems/imperial/base_units/mile.hpp>
#include <boost/units/systems/imperial/base_units/league.hpp>

#include <boost/units/systems/imperial/base_units/grain.hpp>
#include <boost/units/systems/imperial/base_units/drachm.hpp>
#include <boost/units/systems/imperial/base_units/ounce.hpp>
#include <boost/units/systems/imperial/base_units/pound.hpp>
#include <boost/units/systems/imperial/base_units/stone.hpp>
#include <boost/units/systems/imperial/base_units/quarter.hpp>
#include <boost/units/systems/imperial/base_units/hundredweight.hpp>
#include <boost/units/systems/imperial/base_units/ton.hpp>

#include <boost/units/systems/imperial/base_units/fluid_ounce.hpp>
#include <boost/units/systems/imperial/base_units/gill.hpp>
#include <boost/units/systems/imperial/base_units/pint.hpp>
#include <boost/units/systems/imperial/base_units/quart.hpp>
#include <boost/units/systems/imperial/base_units/gallon.hpp>

#include <boost/units/systems/metric/base_units/angstrom.hpp>
#include <boost/units/systems/metric/base_units/fermi.hpp>
#include <boost/units/systems/metric/base_units/micron.hpp>

#include <boost/units/systems/metric/base_units/ton.hpp>

#include <boost/units/systems/metric/base_units/day.hpp>
#include <boost/units/systems/metric/base_units/hour.hpp>
#include <boost/units/systems/metric/base_units/minute.hpp>
#include <boost/units/systems/metric/base_units/year.hpp>

#include <boost/units/systems/metric/base_units/are.hpp>
#include <boost/units/systems/metric/base_units/barn.hpp>
#include <boost/units/systems/metric/base_units/hectare.hpp>

#include <boost/units/systems/metric/base_units/liter.hpp>

#include <boost/units/systems/metric/base_units/atmosphere.hpp>
#include <boost/units/systems/metric/base_units/bar.hpp>
#include <boost/units/systems/metric/base_units/torr.hpp>

#define BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(namespace_,unit_name_,dimension_)				\
namespace boost {																			\
namespace units {																			\
namespace namespace_ {																		\
typedef make_system<unit_name_ ## _base_unit>::type	unit_name_ ## system_;					\
typedef unit<dimension_ ## _dimension,unit_name_ ## system_> unit_name_ ## _ ## dimension_;	\
static const unit_name_ ## _ ## dimension_	unit_name_ ## s;								\
}																							\
}																							\
}																							\

BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(angle,arcminute,plane_angle)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(angle,arcsecond,plane_angle)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(angle,degree,plane_angle)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(angle,gradian,plane_angle)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(angle,radian,plane_angle)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(angle,revolution,plane_angle)

BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(angle,steradian,solid_angle)

BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(astronomical,astronomical_unit,length)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(astronomical,light_second,length)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(astronomical,light_minute,length)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(astronomical,light_hour,length)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(astronomical,light_day,length)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(astronomical,light_year,length)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(astronomical,parsec,length)

BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(imperial,thou,length)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(imperial,inch,length)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(imperial,foot,length)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(imperial,yard,length)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(imperial,furlong,length)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(imperial,mile,length)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(imperial,league,length)

BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(imperial,grain,mass)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(imperial,drachm,mass)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(imperial,ounce,mass)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(imperial,pound,mass)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(imperial,stone,mass)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(imperial,quarter,mass)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(imperial,hundredweight,mass)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(imperial,ton,mass)

BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(imperial,fluid_ounce,volume)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(imperial,gill,volume)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(imperial,pint,volume)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(imperial,quart,volume)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(imperial,gallon,volume)

BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(metric,angstrom,length)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(metric,fermi,length)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(metric,micron,length)

BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(metric,ton,mass)

BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(metric,day,time)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(metric,hour,time)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(metric,minute,time)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(metric,year,time)

BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(metric,are,area)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(metric,barn,area)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(metric,hectare,area)

BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(metric,liter,volume)

BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(metric,atmosphere,pressure)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(metric,bar,pressure)
BOOST_UNITS_DEFINE_SINGLE_UNIT_SYSTEM(metric,torr,pressure)

int main(void)
{
    using namespace boost::units;
    
	{
		using namespace boost::units::angle;
		
		quantity<arcminute_plane_angle>		an1(1.0*arcminutes);
		quantity<arcsecond_plane_angle>		an2(1.0*arcseconds);
		quantity<degree_plane_angle>		an3(1.0*degrees);
		quantity<gradian_plane_angle>		an4(1.0*gradians);
		quantity<radian_plane_angle>		an5(1.0*radians);
		quantity<revolution_plane_angle>	an6(1.0*revolutions);
		
		std::cout << an1 << std::endl
				  << an2 << std::endl
				  << an3 << std::endl
				  << an4 << std::endl
				  << an5 << std::endl
				  << an6 << std::endl
				  << quantity<SI::dimensionless>(an6/an1) << std::endl
				  << quantity<SI::dimensionless>(an6/an2) << std::endl
				  << quantity<SI::dimensionless>(an6/an3) << std::endl
				  << quantity<SI::dimensionless>(an6/an4) << std::endl
				  << quantity<SI::dimensionless>(an6/an5) << std::endl
				  << quantity<SI::plane_angle>(an1) << std::endl
				  << quantity<SI::plane_angle>(an2) << std::endl
				  << quantity<SI::plane_angle>(an3) << std::endl
				  << quantity<SI::plane_angle>(an4) << std::endl
				  << quantity<SI::plane_angle>(an5) << std::endl
				  << quantity<SI::plane_angle>(an6) << std::endl
				  << std::endl;
				  
		quantity<steradian_solid_angle>		sa1(1.0*steradians);
		
		std::cout << sa1 << std::endl
				  << quantity<SI::solid_angle>(sa1) << std::endl
				  << std::endl;
	}
	
	{
		using namespace boost::units::astronomical;

		quantity<astronomical_unit_length>	au(1.0*astronomical_units);
		quantity<light_second_length>		ls(1.0*light_seconds);
		quantity<light_minute_length>		lm(1.0*light_minutes);
		quantity<light_hour_length>			lh(1.0*light_hours);
		quantity<light_day_length>			ld(1.0*light_days);
		quantity<light_year_length>			ly(1.0*light_years);
		quantity<parsec_length>				ps(1.0*parsecs);
		
		std::cout << au << std::endl
				  << ls << std::endl
				  << lm << std::endl
				  << lh << std::endl
				  << ld << std::endl
				  << ly << std::endl
				  << ps << std::endl
				  << quantity<SI::dimensionless>(ly/au) << std::endl
				  << quantity<SI::dimensionless>(ly/ls) << std::endl
				  << quantity<SI::dimensionless>(ly/lm) << std::endl
				  << quantity<SI::dimensionless>(ly/ld) << std::endl
				  << quantity<SI::dimensionless>(ly/lh) << std::endl
				  << quantity<SI::dimensionless>(ly/ps) << std::endl
				  << quantity<SI::length>(au) << std::endl
				  << quantity<SI::length>(ls) << std::endl
				  << quantity<SI::length>(lm) << std::endl
				  << quantity<SI::length>(lh) << std::endl
				  << quantity<SI::length>(ld) << std::endl
				  << quantity<SI::length>(ly) << std::endl
				  << quantity<SI::length>(ps) << std::endl
				  << std::endl;
	}
	
	{
		using namespace boost::units::imperial;
		
		quantity<thou_length>			iml1(1.0*thous);
		quantity<inch_length>			iml2(1.0*inchs);
		quantity<foot_length>			iml3(1.0*foots);
		quantity<yard_length>			iml4(1.0*yards);
		quantity<furlong_length>		iml5(1.0*furlongs);
		quantity<mile_length>			iml6(1.0*miles);
		quantity<league_length>			iml7(1.0*leagues);
		
		std::cout << iml1 << std::endl
				  << iml2 << std::endl
				  << iml3 << std::endl
				  << iml4 << std::endl
				  << iml5 << std::endl
				  << iml6 << std::endl
				  << iml7 << std::endl
				  << quantity<SI::dimensionless>(iml7/iml1) << std::endl
				  << quantity<SI::dimensionless>(iml7/iml2) << std::endl
				  << quantity<SI::dimensionless>(iml7/iml3) << std::endl
				  << quantity<SI::dimensionless>(iml7/iml4) << std::endl
				  << quantity<SI::dimensionless>(iml7/iml5) << std::endl
				  << quantity<SI::dimensionless>(iml7/iml6) << std::endl
				  << quantity<SI::length>(iml1) << std::endl
				  << quantity<SI::length>(iml2) << std::endl
				  << quantity<SI::length>(iml3) << std::endl
				  << quantity<SI::length>(iml4) << std::endl
				  << quantity<SI::length>(iml5) << std::endl
				  << quantity<SI::length>(iml6) << std::endl
				  << quantity<SI::length>(iml7) << std::endl
				  << std::endl;

		quantity<grain_mass>			imm1(1.0*grains);
		quantity<drachm_mass>			imm2(1.0*drachms);
		quantity<ounce_mass>			imm3(1.0*ounces);
		quantity<pound_mass>			imm4(1.0*pounds);
		quantity<stone_mass>			imm5(1.0*stones);
		quantity<quarter_mass>			imm6(1.0*quarters);
		quantity<hundredweight_mass>	imm7(1.0*hundredweights);
		quantity<ton_mass>				imm8(1.0*tons);

		std::cout << imm1 << std::endl
				  << imm2 << std::endl
				  << imm3 << std::endl
				  << imm4 << std::endl
				  << imm5 << std::endl
				  << imm6 << std::endl
				  << imm7 << std::endl
				  << imm8 << std::endl
				  << quantity<SI::dimensionless>(imm8/imm1) << std::endl
				  << quantity<SI::dimensionless>(imm8/imm2) << std::endl
				  << quantity<SI::dimensionless>(imm8/imm3) << std::endl
				  << quantity<SI::dimensionless>(imm8/imm4) << std::endl
				  << quantity<SI::dimensionless>(imm8/imm5) << std::endl
				  << quantity<SI::dimensionless>(imm8/imm6) << std::endl
				  << quantity<SI::dimensionless>(imm8/imm7) << std::endl
				  << quantity<SI::mass>(imm1) << std::endl
				  << quantity<SI::mass>(imm2) << std::endl
				  << quantity<SI::mass>(imm3) << std::endl
				  << quantity<SI::mass>(imm4) << std::endl
				  << quantity<SI::mass>(imm5) << std::endl
				  << quantity<SI::mass>(imm6) << std::endl
				  << quantity<SI::mass>(imm7) << std::endl
				  << quantity<SI::mass>(imm8) << std::endl
				  << std::endl;
				  
		quantity<gallon_volume>			imv1(1.0*gallons);
		quantity<fluid_ounce_volume>	imv2(1.0*fluid_ounces);
		quantity<gill_volume>			imv3(1.0*gills);
		quantity<pint_volume>			imv4(1.0*pints);
		quantity<quart_volume>			imv5(1.0*quarts);
		
		//quantity<fluid_ounce_volume>	im6 = 1.0*gallons;	// why does this fail?
		
		std::cout << imv1 << std::endl
				  << imv2 << std::endl
				  << imv3 << std::endl
				  << imv4 << std::endl
				  << imv5 << std::endl
				  << quantity<SI::dimensionless>(imv1/imv2) << std::endl
				  << quantity<SI::dimensionless>(imv1/imv3) << std::endl
				  << quantity<SI::dimensionless>(imv1/imv4) << std::endl
				  << quantity<SI::dimensionless>(imv1/imv5) << std::endl
				  << quantity<SI::volume>(imv1) << std::endl
				  << quantity<SI::volume>(imv2) << std::endl
				  << quantity<SI::volume>(imv3) << std::endl
				  << quantity<SI::volume>(imv4) << std::endl
				  << quantity<SI::volume>(imv5) << std::endl
				  << std::endl;
	}
	
	{
		using namespace boost::units::metric;
		
		quantity<angstrom_length>	ml1(1.0*angstroms);
		quantity<fermi_length>		ml2(1.0*fermis);
		quantity<micron_length>		ml3(1.0*microns);
	
		std::cout << ml1 << std::endl
				  << ml2 << std::endl
				  << ml3 << std::endl
				  << quantity<SI::dimensionless>(ml3/ml1) << std::endl
				  << quantity<SI::dimensionless>(ml3/ml2) << std::endl
				  << quantity<SI::length>(ml1) << std::endl
				  << quantity<SI::length>(ml2) << std::endl
				  << quantity<SI::length>(ml3) << std::endl
				  << std::endl;

// probably more gram/kilogram business
//		quantity<ton_mass>	mm1(1.0*tons);
//		
//		std::cout << mm1 << std::endl
//				  << quantity<SI::mass>(mm1) << std::endl
//				  << std::endl;
				  
		quantity<day_time>		mt1(1.0*days);
		quantity<hour_time>		mt2(1.0*hours);
		quantity<minute_time>	mt3(1.0*minutes);
		quantity<year_time>		mt4(1.0*years);
		
		std::cout << mt1 << std::endl
				  << mt2 << std::endl
				  << mt3 << std::endl
				  << mt4 << std::endl
				  << quantity<SI::dimensionless>(mt4/mt1) << std::endl
				  << quantity<SI::dimensionless>(mt4/mt2) << std::endl
				  << quantity<SI::dimensionless>(mt4/mt3) << std::endl
				  << quantity<SI::time>(mt1) << std::endl
				  << quantity<SI::time>(mt2) << std::endl
				  << quantity<SI::time>(mt3) << std::endl
				  << quantity<SI::time>(mt4) << std::endl
				  << std::endl;
		
		quantity<are_area>		ma1(1.0*ares);
		quantity<barn_area>		ma2(1.0*barns);
		quantity<hectare_area>	ma3(1.0*hectares);
		
		quantity<liter_volume>	mv1(1.0*liters);
		
		quantity<atmosphere_pressure>	mp1(1.0*atmospheres);
		quantity<bar_pressure>			mp2(1.0*bars);
		quantity<torr_pressure>			mp3(1.0*torrs);
	}
	
	return 0;
}
