// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_SI_IO_HPP
#define BOOST_UNITS_SI_IO_HPP

#include <boost/units/io.hpp>

#include <boost/units/systems/si.hpp>

namespace boost {

namespace units { 

// gray and sievert are indistinguishable
inline std::string name_string(const si::absorbed_dose&) { return "gray"; }
inline std::string symbol_string(const si::absorbed_dose&) { return "Gy"; }

// activity and frequency are indistinguishable - would need a "decays" base unit
//inline std::string name_string(const si::activity&) { return "becquerel"; }
//inline std::string symbol_string(const si::activity&) { return "Bq"; }

inline std::string name_string(const si::capacitance&)   { return "farad"; }
inline std::string symbol_string(const si::capacitance&) { return "F"; }

inline std::string name_string(const si::catalytic_activity&) { return "katal"; }
inline std::string symbol_string(const si::catalytic_activity&) { return "kat"; }

inline std::string name_string(const si::conductance&) { return "siemen"; }
inline std::string symbol_string(const si::conductance&) { return "S"; }

// gray and sievert are indistinguishable
//inline std::string name_string(const si::dose_equivalent&) { return "sievert"; }
//inline std::string symbol_string(const si::dose_equivalent&) { return "Sv"; }

inline std::string name_string(const si::electric_charge&) { return "coulomb"; }
inline std::string symbol_string(const si::electric_charge&) { return "C"; }

inline std::string name_string(const si::electric_potential&) { return "volt"; }
inline std::string symbol_string(const si::electric_potential&) { return "V"; }

inline std::string name_string(const si::energy&) { return "joule"; }
inline std::string symbol_string(const si::energy&) { return "J"; }

inline std::string name_string(const si::force&) { return "newton"; }
inline std::string symbol_string(const si::force&) { return "N"; }

inline std::string name_string(const si::frequency&) { return "hertz"; }
inline std::string symbol_string(const si::frequency&) { return "Hz"; }

inline std::string name_string(const si::illuminance&) { return "lux"; }
inline std::string symbol_string(const si::illuminance&) { return "lx"; }

inline std::string name_string(const si::inductance&) { return "henry"; }
inline std::string symbol_string(const si::inductance&) { return "H"; }

inline std::string name_string(const si::luminous_flux&) { return "lumen"; }
inline std::string symbol_string(const si::luminous_flux&) { return "lm"; }

inline std::string name_string(const si::magnetic_flux&) { return "weber"; }
inline std::string symbol_string(const si::magnetic_flux&) { return "Wb"; }

inline std::string name_string(const si::magnetic_flux_density&) { return "tesla"; }
inline std::string symbol_string(const si::magnetic_flux_density&) { return "T"; }

inline std::string name_string(const si::power&) { return "watt"; }
inline std::string symbol_string(const si::power&) { return "W"; }

inline std::string name_string(const si::pressure&) { return "pascal"; }
inline std::string symbol_string(const si::pressure&) { return "Pa"; }

inline std::string name_string(const si::resistance&) { return "ohm"; }
inline std::string symbol_string(const si::resistance&) { return "Ω"; }


} // namespace units

} // namespace boost

#endif // BOOST_UNITS_SI_IO_HPP
