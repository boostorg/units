// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_CGS_IO_HPP
#define BOOST_UNITS_CGS_IO_HPP

#include <boost/units/io.hpp>
#include <boost/units/systems/cgs.hpp>

namespace boost {

namespace units { 

inline std::string name_string(const cgs::acceleration&) { return "galileo"; }
inline std::string symbol_string(const cgs::acceleration&) { return "Gal"; }

inline std::string name_string(const cgs::current&)   { return "biot"; }
inline std::string symbol_string(const cgs::current&) { return "Bi"; }

inline std::string name_string(const cgs::dynamic_viscosity&) { return "poise"; }
inline std::string symbol_string(const cgs::dynamic_viscosity&) { return "P"; }

inline std::string name_string(const cgs::energy&) { return "erg"; }
inline std::string symbol_string(const cgs::energy&) { return "erg"; }

inline std::string name_string(const cgs::force&) { return "dyne"; }
inline std::string symbol_string(const cgs::force&) { return "dyn"; }

inline std::string name_string(const cgs::kinematic_viscosity&) { return "stoke"; }
inline std::string symbol_string(const cgs::kinematic_viscosity&) { return "St"; }

inline std::string name_string(const cgs::pressure&) { return "barye"; }
inline std::string symbol_string(const cgs::pressure&) { return "Ba"; }

inline std::string name_string(const cgs::wavenumber&) { return "kayser"; }
inline std::string symbol_string(const cgs::wavenumber&) { return "K"; }

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_CGS_IO_HPP
