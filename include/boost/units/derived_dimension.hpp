// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_DERIVED_DIMENSION_HPP
#define BOOST_UNITS_DERIVED_DIMENSION_HPP

#include <boost/mpl/list.hpp>

#include <boost/units/static_rational.hpp>
#include <boost/units/units_fwd.hpp>

namespace boost {

namespace units {

/// A utility class for defining composite dimensions with integer powers.
template<class DT1 = dimensionless_type,long E1 = 0,
         class DT2 = dimensionless_type,long E2 = 0,
         class DT3 = dimensionless_type,long E3 = 0,
         class DT4 = dimensionless_type,long E4 = 0,
         class DT5 = dimensionless_type,long E5 = 0,
         class DT6 = dimensionless_type,long E6 = 0,
         class DT7 = dimensionless_type,long E7 = 0,
         class DT8 = dimensionless_type,long E8 = 0>
struct derived_dimension
{
    typedef typename 
    make_dimension_list< mpl::list< dim< DT1,static_rational<E1> >,
                                    dim< DT2,static_rational<E2> >,
                                    dim< DT3,static_rational<E3> >,
                                    dim< DT4,static_rational<E4> >,
                                    dim< DT5,static_rational<E5> >,
                                    dim< DT6,static_rational<E6> >,
                                    dim< DT7,static_rational<E7> >,
                                    dim< DT8,static_rational<E8> > > >::type type;
};

} // namespace units

} // namespace boost                                                                   

#endif // BOOST_UNITS_DERIVED_DIMENSION_HPP
