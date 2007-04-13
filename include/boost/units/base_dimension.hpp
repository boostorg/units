// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_BASE_DIMENSION_HPP
#define BOOST_UNITS_BASE_DIMENSION_HPP

#include <boost/mpl/int.hpp>
#include <boost/mpl/list.hpp>

#include <boost/units/static_rational.hpp>
#include <boost/units/units_fwd.hpp>

namespace boost {

namespace units {

/// A utility class for defining base dimensions.
template<long N> struct base_dimension;

/// each specialization must be separately instantiated in boost::units namespace to prevent duplication of tag values
#define BOOST_UNITS_REGISTER_BASE_DIMENSION(name, N)                                                        \
template<>                                                                                                  \
struct base_dimension<N> :                                                                                  \
    public mpl::int_<N>                                                                                     \
{                                                                                                           \
    typedef base_dimension<N>   this_type;                                                                  \
    typedef mpl::int_<N>        value;                                                                      \
                                                                                                            \
    typedef make_dimension_list< mpl::list< dim< this_type,static_rational<1> > > >::type type;             \
};                                                                                                          \
                                                                                                            \
typedef base_dimension<N>   name                                                                            \

} // namespace units

} // namespace boost

// doesn't work with g++ for some reason
//namespace boost {
//
//namespace units {
//
///// A utility class for defining base dimensions.
//template<long N> struct base_dimension;
//
//} // namespace units
//
//} // namespace boost
//
///// each specialization must be separately instantiated in boost::units namespace to prevent duplication of tag values
//#define BOOST_UNITS_REGISTER_BASE_DIMENSION(name, N)                                                        \
//template<>                                                                                                  \
//struct boost::units::base_dimension<N> :                                                                                  \
//    public boost::mpl::int_<N>                                                                                     \
//{                                                                                                           \
//    typedef boost::units::base_dimension<N>     this_type;                                                                  \
//    typedef boost::mpl::int_<N>                 value;                                                                      \
//                                                                                                            \
//    typedef boost::units::make_dimension_list< boost::mpl::list< boost::units::dim< this_type,boost::units::static_rational<1> > > >::type type;             \
//};                                                                                                          \
//                                                                                                            \
//typedef boost::units::base_dimension<N>   name                                                                            \

#endif // BOOST_UNITS_BASE_DIMENSION_HPP
