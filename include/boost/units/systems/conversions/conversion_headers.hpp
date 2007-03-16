// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// No include guard.
// This header is intended to be included multiple times.

#if defined(BOOST_UNITS_SI_BASE_HPP) && defined(BOOST_UNITS_CGS_BASE_HPP)
    #include <boost/units/systems/conversions/convert_cgs_to_si.hpp>
    #include <boost/units/systems/conversions/convert_si_to_cgs.hpp>
#endif

#if defined(BOOST_UNITS_SI_BASE_HPP) && defined(BOOST_UNITS_TRIG_HPP)
    #include <boost/units/systems/conversions/convert_trig_to_si.hpp>
    #include <boost/units/systems/conversions/convert_si_to_trig.hpp>
#endif

#if defined(BOOST_UNITS_TRIG_HPP) && defined(BOOST_UNITS_CGS_BASE_HPP)
    #include <boost/units/systems/conversions/convert_cgs_to_trig.hpp>
    #include <boost/units/systems/conversions/convert_trig_to_cgs.hpp>
#endif
