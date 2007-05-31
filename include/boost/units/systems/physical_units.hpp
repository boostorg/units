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

/// \file 
/// \brief Various definitions to simplify systems of physical units.
///
/// \detailed This file includes the seven SI-defined base dimensions as
/// well as derived dimensions for a number of commonly encountered
/// physical unit types. Angles and solid angles are technically dimensionless. 
/// However, incorrect use of degrees and radians is a common source of errors, 
/// so we treat them on the same footing as the seven physical dimensions.

#include <boost/units/systems/base_dimensions/amount_base_dimension.hpp>
#include <boost/units/systems/base_dimensions/current_base_dimension.hpp>
#include <boost/units/systems/base_dimensions/length_base_dimension.hpp>
#include <boost/units/systems/base_dimensions/luminous_intensity_base_dimension.hpp>
#include <boost/units/systems/base_dimensions/mass_base_dimension.hpp>
#include <boost/units/systems/base_dimensions/plane_angle_base_dimension.hpp>
#include <boost/units/systems/base_dimensions/solid_angle_base_dimension.hpp>
#include <boost/units/systems/base_dimensions/temperature_base_dimension.hpp>
#include <boost/units/systems/base_dimensions/time_base_dimension.hpp>

#include <boost/units/systems/derived_dimensions/absorbed_dose_derived_dimension.hpp>
#include <boost/units/systems/derived_dimensions/acceleration_derived_dimension.hpp>
#include <boost/units/systems/derived_dimensions/action_derived_dimension.hpp>
#include <boost/units/systems/derived_dimensions/activity_derived_dimension.hpp>
#include <boost/units/systems/derived_dimensions/angular_velocity_derived_dimension.hpp>
#include <boost/units/systems/derived_dimensions/area_derived_dimension.hpp>
#include <boost/units/systems/derived_dimensions/dose_equivalent_derived_dimension.hpp>
#include <boost/units/systems/derived_dimensions/dynamic_viscosity_derived_dimension.hpp>
#include <boost/units/systems/derived_dimensions/energy_derived_dimension.hpp>
#include <boost/units/systems/derived_dimensions/force_derived_dimension.hpp>
#include <boost/units/systems/derived_dimensions/frequency_derived_dimension.hpp>
#include <boost/units/systems/derived_dimensions/illuminance_derived_dimension.hpp>
#include <boost/units/systems/derived_dimensions/kinematic_viscosity_derived_dimension.hpp>
#include <boost/units/systems/derived_dimensions/luminance_derived_dimension.hpp>
#include <boost/units/systems/derived_dimensions/luminous_flux_derived_dimension.hpp>
#include <boost/units/systems/derived_dimensions/mass_density_derived_dimension.hpp>
#include <boost/units/systems/derived_dimensions/momentum_derived_dimension.hpp>
#include <boost/units/systems/derived_dimensions/power_derived_dimension.hpp>
#include <boost/units/systems/derived_dimensions/pressure_derived_dimension.hpp>
#include <boost/units/systems/derived_dimensions/specific_volume_derived_dimension.hpp>
#include <boost/units/systems/derived_dimensions/stress_derived_dimension.hpp>
#include <boost/units/systems/derived_dimensions/surface_density_derived_dimension.hpp>
#include <boost/units/systems/derived_dimensions/velocity_derived_dimension.hpp>
#include <boost/units/systems/derived_dimensions/volume_derived_dimension.hpp>
#include <boost/units/systems/derived_dimensions/wavenumber_derived_dimension.hpp>

#endif // BOOST_UNITS_PHYSICAL_UNITS_HPP
