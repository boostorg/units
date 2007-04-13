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

#include <boost/units/base_dimension.hpp>
#include <boost/units/derived_dimension.hpp>
#include <boost/units/static_constant.hpp>
#include <boost/units/system.hpp>
#include <boost/units/unit.hpp>

/// \file 
/// \brief Various definitions to simplify systems of physical units.
///
/// \detailed This file includes the seven SI-defined base dimensions as
/// well as derived dimensions for a number of commonly encountered
/// physical unit types. Angles and solid angles are technically dimensionless. 
/// However, incorrect use of degrees and radians is a common source of errors, 
/// so we treat them on the same footing as the seven physical dimensions.

namespace boost {

namespace units { 

BOOST_UNITS_REGISTER_BASE_DIMENSION(length_dim,-9);               ///> base dimension of length
BOOST_UNITS_REGISTER_BASE_DIMENSION(mass_dim,-8);                 ///> base dimension of mass
BOOST_UNITS_REGISTER_BASE_DIMENSION(time_dim,-7);                 ///> base dimension of time
BOOST_UNITS_REGISTER_BASE_DIMENSION(current_dim,-6);              ///> base dimension of current
BOOST_UNITS_REGISTER_BASE_DIMENSION(temperature_dim,-5);          ///> base dimension of temperature
BOOST_UNITS_REGISTER_BASE_DIMENSION(amount_dim,-4);               ///> base dimension of amount
BOOST_UNITS_REGISTER_BASE_DIMENSION(luminous_intensity_dim,-3);   ///> base dimension of luminous intensity
BOOST_UNITS_REGISTER_BASE_DIMENSION(plane_angle_dim,-2);          ///> base dimension of plane angle
BOOST_UNITS_REGISTER_BASE_DIMENSION(solid_angle_dim,-1);          ///> base dimension of solid angle

} // namespace units

} // namespace boost

#if BOOST_UNITS_HAS_BOOST_TYPEOF

#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

BOOST_TYPEOF_REGISTER_TYPE(boost::units::length_dim)
BOOST_TYPEOF_REGISTER_TYPE(boost::units::mass_dim)
BOOST_TYPEOF_REGISTER_TYPE(boost::units::time_dim)
BOOST_TYPEOF_REGISTER_TYPE(boost::units::current_dim)
BOOST_TYPEOF_REGISTER_TYPE(boost::units::temperature_dim)
BOOST_TYPEOF_REGISTER_TYPE(boost::units::amount_dim)
BOOST_TYPEOF_REGISTER_TYPE(boost::units::luminous_intensity_dim)
BOOST_TYPEOF_REGISTER_TYPE(boost::units::plane_angle_dim)
BOOST_TYPEOF_REGISTER_TYPE(boost::units::solid_angle_dim)

#endif

namespace boost {

namespace units {

/// base dimension of length (L)
typedef length_dim::type                                                                    length_type;

/// base dimension of mass (M)
typedef mass_dim::type                                                                      mass_type;

/// base dimension of time (T)
typedef time_dim::type                                                                      time_type;

/// base dimension of electric current (I)
typedef current_dim::type                                                                   current_type;

/// base dimension of temperature (Theta)
typedef temperature_dim::type                                                               temperature_type;

/// base dimension of amount of substance (N)
typedef amount_dim::type                                                                    amount_type;

/// base dimension of luminous intensity (J)
typedef luminous_intensity_dim::type                                                        luminous_intensity_type;

/// base dimension of planar angle (QP)
typedef plane_angle_dim::type                                                               plane_angle_type;

/// base dimension of solid angle (QS)
typedef solid_angle_dim::type                                                               solid_angle_type;
    
/// derived dimension for absorbed dose : L^2 T^-2
typedef derived_dimension<length_dim,2,time_dim,-2>::type                                   absorbed_dose_type;  

/// derived dimension for acceleration : L T^-2
typedef derived_dimension<length_dim,1,time_dim,-2>::type                                   acceleration_type;  

/// derived dimension for action : L^2 M T^-1
typedef derived_dimension<length_dim,2,mass_dim,1,time_dim,-1>::type                        action_type;

/// derived dimension for activity : T^-1
typedef derived_dimension<time_dim,-1>::type                                                activity_type; 

/// derived dimension for angular velocity : T^-1 QP
typedef derived_dimension<time_dim,-1,plane_angle_dim,1>::type                              angular_velocity_type; 

/// derived dimension for area : L^2
typedef derived_dimension<length_dim,2>::type                                               area_type; 

/// derived dimension for dose equivalent : L^2 T^-2
typedef derived_dimension<length_dim,2,time_dim,-2>::type                                   dose_equivalent_type;  

/// derived dimension for dynamic viscosity : M L^-1 T^-1
typedef derived_dimension<mass_dim,1,length_dim,-1,time_dim,-1>::type                       dynamic_viscosity_type;

/// derived dimension for energy : L^2 M T^-2
typedef derived_dimension<length_dim,2,mass_dim,1,time_dim,-2>::type                        energy_type;                

/// derived dimension for force : L M T^-2
typedef derived_dimension<length_dim,1,mass_dim,1,time_dim,-2>::type                        force_type;                    

/// derived dimension for frequency : T^-1
typedef derived_dimension<time_dim,-1>::type                                                frequency_type;                

/// derived dimension for illuminance : L^-2 I QS
typedef derived_dimension<length_dim,-2,luminous_intensity_dim,1,solid_angle_dim,1>::type   illuminance_type;

/// derived dimension for kinematic viscosity : L^2 T^-1
typedef derived_dimension<length_dim,2,time_dim,-1>::type                                   kinematic_viscosity_type;

/// derived dimension for luminance : L^-2 I
typedef derived_dimension<length_dim,-2,luminous_intensity_dim,1>::type                     luminance_type;

/// derived dimension for luminous flux : I QS
typedef derived_dimension<luminous_intensity_dim,1,solid_angle_dim,1>::type                 luminous_flux_type;

/// derived dimension for mass density : L^-3 M
typedef derived_dimension<length_dim,-3,mass_dim,1>::type                                   mass_density_type;            

/// derived dimension for linear momentum : L M T^-1
typedef derived_dimension<length_dim,1,mass_dim,1,time_dim,-1>::type                        momentum_type;                

/// derived dimension for power : L^2 M T^-3
typedef derived_dimension<length_dim,2,mass_dim,1,time_dim,-3>::type                        power_type;                    

/// derived dimension for pressure : L^-1 M T^-2
typedef derived_dimension<length_dim,-1,mass_dim,1,time_dim,-2>::type                       pressure_type;                

/// derived dimension for specific volume : L^3 M^-1
typedef derived_dimension<length_dim,3,mass_dim,-1>::type                                   specific_volume_type;            

/// derived dimension for stress : L^-1 M T^-2
typedef derived_dimension<length_dim,-1,mass_dim,1,time_dim,-2>::type                       stress_type;     

/// derived dimension for surface density : L^-2 M
typedef derived_dimension<length_dim,-2,mass_dim,1>::type                                   surface_density_type;

/// derived dimension for velocity : L T^-1
typedef derived_dimension<length_dim,1,time_dim,-1>::type                                   velocity_type;                

/// derived dimension for volume : l^3
typedef derived_dimension<length_dim,3>::type                                               volume_type;

/// derived dimension for wavenumber : L^-1
typedef derived_dimension<length_dim,-1>::type                                              wavenumber_type;                 

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_PHYSICAL_UNITS_HPP
