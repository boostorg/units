// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_PHYSICAL_UNITS_HPP
#define BOOST_UNITS_PHYSICAL_UNITS_HPP

#include <boost/units/system.hpp>
#include <boost/units/unit.hpp>

/// \file 
/// \brief Various definitions to simplify systems of physical units.
///
/// \detailed This file includes the six SI-defined fundamental dimensions as
/// well as composite dimensions for a number of commonly encountered
/// physical unit types. Angles and solid angles are technically dimensionless. 
/// However, incorrect use of degrees and radians is a common source of errors, 
/// so we treat them on the same footing as the seven physical dimensions.

namespace boost {

namespace units { 

/// tag representing length
struct length_tag : public ordinal<-9> { };

/// tag representing mass
struct mass_tag : public ordinal<-8> { };

/// tag representing time
struct time_tag : public ordinal<-7> { };

/// tag representing electrical current
struct current_tag : public ordinal<-6> { };

/// tag representing temperature
struct temperature_tag : public ordinal<-5> { };

/// tag representing amount of substance
struct amount_tag : public ordinal<-4> { };

/// tag representing luminous intensity - demoted from status as a fundamental SI unit in 1979
struct luminous_intensity_tag : public ordinal<-3> { };

/// tag representing plane angle
struct plane_angle_tag : public ordinal<-2> { };

/// tag representing solid angle
struct solid_angle_tag : public ordinal<-1> { };

}

}

#if BOOST_UNITS_HAS_BOOST_TYPEOF

#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

BOOST_TYPEOF_REGISTER_TYPE(boost::units::length_tag)
BOOST_TYPEOF_REGISTER_TYPE(boost::units::mass_tag)
BOOST_TYPEOF_REGISTER_TYPE(boost::units::time_tag)
BOOST_TYPEOF_REGISTER_TYPE(boost::units::current_tag)
BOOST_TYPEOF_REGISTER_TYPE(boost::units::temperature_tag)
BOOST_TYPEOF_REGISTER_TYPE(boost::units::amount_tag)
BOOST_TYPEOF_REGISTER_TYPE(boost::units::luminous_intensity_tag)
BOOST_TYPEOF_REGISTER_TYPE(boost::units::plane_angle_tag)
BOOST_TYPEOF_REGISTER_TYPE(boost::units::solid_angle_tag)

#endif

namespace boost {

namespace units {

/// fundamental dimension of length (L)
typedef fundamental_dimension<length_tag>::type                                                 length_type;

/// fundamental dimension of mass (M)
typedef fundamental_dimension<mass_tag>::type                                                   mass_type;

/// fundamental dimension of time (T)
typedef fundamental_dimension<time_tag>::type                                                   time_type;

/// fundamental dimension of electric current (C)
typedef fundamental_dimension<current_tag>::type                                                current_type;

/// fundamental dimension of temperature (K)
typedef fundamental_dimension<temperature_tag>::type                                            temperature_type;

/// fundamental dimension of amount of substance (A)
typedef fundamental_dimension<amount_tag>::type                                                 amount_type;

/// fundamental dimension of luminous intensity (I, deprecated by SI)
typedef fundamental_dimension<luminous_intensity_tag>::type                                     luminous_intensity_type;

/// fundamental dimension of planar angle (QP)
typedef fundamental_dimension<plane_angle_tag>::type                                            plane_angle_type;

/// fundamental dimension of solid angle (QS)
typedef fundamental_dimension<solid_angle_tag>::type                                            solid_angle_type;

    
/// composite dimension for absorbed dose : L^2 T^-2
typedef composite_dimension<length_tag,2,time_tag,-2>::type                                     absorbed_dose_type;  

/// composite dimension for acceleration : L T^-2
typedef composite_dimension<length_tag,1,time_tag,-2>::type                                     acceleration_type;  

/// composite dimension for activity : T^-1
typedef composite_dimension<time_tag,-1>::type                                                  activity_type; 

/// composite dimension for angular velocity : T^-1 QP
typedef composite_dimension<time_tag,-1,plane_angle_tag,1>::type                                angular_velocity_type; 

/// composite dimension for area : L^2
typedef composite_dimension<length_tag,2>::type                                                 area_type; 

/// composite dimension for dose equivalent : L^2 T^-2
typedef composite_dimension<length_tag,2,time_tag,-2>::type                                     dose_equivalent_type;  

/// composite dimension for dynamic viscosity : M L^-1 T^-1
typedef composite_dimension<mass_tag,1,length_tag,-1,time_tag,-1>::type                         dynamic_viscosity_type;

/// composite dimension for energy : L^2 M T^-2
typedef composite_dimension<length_tag,2,mass_tag,1,time_tag,-2>::type                          energy_type;                

/// composite dimension for force : L M T^-2
typedef composite_dimension<length_tag,1,mass_tag,1,time_tag,-2>::type                          force_type;                    

/// composite dimension for frequency : T^-1
typedef composite_dimension<time_tag,-1>::type                                                  frequency_type;                

/// composite dimension for illuminance : L^-2 I QS
typedef composite_dimension<length_tag,-2,luminous_intensity_tag,1,solid_angle_tag,1>::type     illuminance_type;

/// composite dimension for kinematic viscosity : L^2 T^-1
typedef composite_dimension<length_tag,2,time_tag,-1>::type                                     kinematic_viscosity_type;

/// composite dimension for luminous flux : I QS
typedef composite_dimension<luminous_intensity_tag,1,solid_angle_tag,1>::type                   luminous_flux_type;

/// composite dimension for mass density : L^-3 M
typedef composite_dimension<length_tag,-3,mass_tag,1>::type                                     mass_density_type;            

/// composite dimension for linear momentum : L M T^-1
typedef composite_dimension<length_tag,1,mass_tag,1,time_tag,-1>::type                          momentum_type;                

/// composite dimension for power : L^2 M T^-3
typedef composite_dimension<length_tag,2,mass_tag,1,time_tag,-3>::type                          power_type;                    

/// composite dimension for pressure : L^-1 M T^-2
typedef composite_dimension<length_tag,-1,mass_tag,1,time_tag,-2>::type                         pressure_type;                

/// composite dimension for specific volume : L^3 M^-1
typedef composite_dimension<length_tag,3,mass_tag,-1>::type                                     specific_volume_type;            

/// composite dimension for stress : L^-1 M T^-2
typedef composite_dimension<length_tag,-1,mass_tag,1,time_tag,-2>::type                         stress_type;     

/// composite dimension for surface density : L^-2 M
typedef composite_dimension<length_tag,-2,mass_tag,1>::type                                     surface_density_type;

/// composite dimension for velocity : L T^-1
typedef composite_dimension<length_tag,1,time_tag,-1>::type                                     velocity_type;                

/// composite dimension for volume : l^3
typedef composite_dimension<length_tag,3>::type                                                 volume_type;

/// composite dimension for wavenumber : L^-1
typedef composite_dimension<length_tag,-1>::type                                                wavenumber_type;                 

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_PHYSICAL_UNITS_HPP
