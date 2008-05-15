// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_UTILITY_HPP
#define BOOST_UNITS_UTILITY_HPP

#include <cstdlib>
#include <complex>
#include <iostream>
#include <typeinfo>
#include <string>

#include <boost/assert.hpp>
#include <boost/cstdint.hpp>
#include <boost/limits.hpp>

#ifdef MCS_USE_BOOST_REGEX_DEMANGLING
#include <boost/regex.hpp>
#ifdef __GNUC__
#define MCS_USE_DEMANGLING
#endif // __GNUC__
#endif // MCS_USE_BOOST_REGEX_DEMANGLING

#ifdef MCS_USE_DEMANGLING

#ifdef __GNUC__
#include <cxxabi.h>
#endif // __GNUC__

namespace boost {

namespace units {

namespace detail {

inline
std::string
demangle(const char* name)
{
    #ifdef __GNUC__
    // need to demangle C++ symbols
    char*       realname;
    std::size_t len; 
    int         stat;
     
    realname = abi::__cxa_demangle(name,NULL,&len,&stat);
    
    if (realname != NULL)
    {
        const std::string   out(realname);
        std::free(realname);
        
        return out;
    }
    
    return std::string("demangle :: error - unable to demangle specified symbol");
    #else
    return name;
    #endif
}

} // namespace detail

template<class L>
std::string simplify_typename(const L& /*source*/)
{
    const std::string   demangled = detail::demangle(typeid(L).name());
    
    #ifdef MCS_USE_BOOST_REGEX_DEMANGLING
    boost::regex    ns_regex("boost::units::detail::|boost::units::");
    
    const std::string   tmp(boost::regex_replace(demangled,ns_regex,""));
    
    return tmp;
    #else // MCS_USE_BOOST_REGEX_DEMANGLING
    return demangled;
    #endif // MCS_USE_BOOST_REGEX_DEMANGLING
}

} // namespace units

} // namespace boost

#else // MCS_USE_DEMANGLING

namespace boost {

namespace units {

namespace detail {

inline
std::string
demangle(const char* name)
{
    return name;
}

} // namespace detail

template<class L>
std::string simplify_typename(const L& source)
{
    return std::string(typeid(source).name());
}

} // namespace units

} // namespace boost

// To get system-specific predefined macros:
// gcc -arch ppc -dM -E - < /dev/null | sort 

#endif // MCS_USE_DEMANGLING

#endif // BOOST_UNITS_UTILITY_HPP
