// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_SYS_HPP
#define BOOST_UNITS_SYS_HPP

#include <boost/mpl/bool_fwd.hpp>

#include <boost/units/dim.hpp>
#include <boost/units/detail/sys_impl.hpp>

/// \file 
/// \brief Class encapsulating a system tag/dimension tag pair.

namespace boost {

namespace units {

/// check that a type is a valid @c sys
template<typename T> 
struct is_sys :
    public mpl::false_
{ };

template<typename ST,typename DT>
struct is_sys< sys<ST,DT> > :
    public mpl::true_
{ };

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_SYS_HPP
