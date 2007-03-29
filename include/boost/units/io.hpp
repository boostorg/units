// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_IO_HPP
#define BOOST_UNITS_IO_HPP

#include <iosfwd>
#include <locale>
#include <string>

#include <boost/config.hpp>

#include <boost/units/quantity.hpp>
#include <boost/units/detail/io_impl.hpp>

/// \file
/// \brief Code for input/output.

namespace boost {

namespace serialization {

/// Boost Serialization library support for units.
template<class Archive,class System,class Dim>
inline void serialize(Archive& ar,boost::units::unit<Dim,System>&,const unsigned int version)
{ }

/// Boost Serialization library support for quantities.
template<class Archive,class Unit,class Y>
inline void serialize(Archive& ar,boost::units::quantity<Unit,Y>& q,const unsigned int version)
{
    ar & quantity_reinterpret_cast<Y&>(q);
}
        
} // namespace serialization

namespace units { 

/// Write integral-valued @c static_rational to @c std::basic_ostream.
template<class Char, class Traits, integer_type N>
inline std::basic_ostream<Char, Traits>& operator<<(std::basic_ostream<Char, Traits>& os,const static_rational<N>& val)
{
    detail::static_rational_print_impl<(N > 0)>::apply(os,val);
    return os;
}

/// Write @c static_rational to @c std::basic_ostream.
template<class Char, class Traits, integer_type N, integer_type D>
inline std::basic_ostream<Char, Traits>& operator<<(std::basic_ostream<Char, Traits>& os,const static_rational<N, D>& val)
{
    os << '(' << val.numerator() << '/' << val.denominator() << ')';
    return os;
}

/// Write @c unit to @c std::basic_ostream.
template<class Char, class Traits, class System,class Dim>
std::basic_ostream<Char, Traits>& operator<<(std::basic_ostream<Char, Traits>& os,const unit<Dim,System>& u)
{
    detail::output_impl(os, u);
    return os;
}

/// Write @c quantity to @c std::basic_ostream.
template<class Char, class Traits, class System,class Dim,class Y>
std::basic_ostream<Char, Traits>& operator<<(std::basic_ostream<Char, Traits>& os,
                                             const quantity<unit<Dim,System>,Y>& val)
{
    const unit<Dim,System> u;
    
    os << val.value() << ' ' << u;
    
    return os;
}

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_IO_HPP
