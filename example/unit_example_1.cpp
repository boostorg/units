// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

/** 
\file
    
\brief unit_example_1.cpp

\detailed
Test dimension list manipulation.

Output:
@verbatim

//[unit_example_1_output
length_type  = l_item<long_<1L>, dim<length_tag, static_rational<1L, 1L> > >
mass_type    = l_item<long_<1L>, dim<mass_tag, static_rational<1L, 1L> > >
time_type    = l_item<long_<1L>, dim<time_tag, static_rational<1L, 1L> > >
energy_type  = l_item<long_<3L>, dim<length_tag, static_rational<2L, 1L> >, l_item<long_<2L>, dim<mass_tag, static_rational<1L, 1L> >, l_item<long_<1L>, dim<time_tag, static_rational<-2L, 1L> > > > >
LM_type      = l_item<long_<2L>, dim<length_tag, static_rational<1L, 1L> >, l_item<long_<1L>, dim<mass_tag, static_rational<1L, 1L> > > >
L_T_type     = l_item<long_<2L>, dim<length_tag, static_rational<1L, 1L> >, l_item<long_<1L>, dim<time_tag, static_rational<-1L, 1L> > > >
V_type       = l_item<long_<2L>, dim<length_tag, static_rational<1L, 1L> >, l_item<long_<1L>, dim<time_tag, static_rational<-1L, 1L> > > >
//]

@endverbatim
**/

// undefine this if you don't want to demangle symbols
// need to link with libboost_regex to get demangling functionality
#define MCS_USE_DEMANGLING
//#define MCS_USE_BOOST_REGEX_DEMANGLING

#include <boost/type_traits/is_same.hpp>

#include <boost/mpl/assert.hpp>

#include <boost/units/detail/utility.hpp>

#include "test_system.hpp"

namespace mpl = boost::mpl;

int main(void)
{   
    using namespace boost::units;

    BOOST_MPL_ASSERT((boost::is_same<length_type, mpl::push_front<dimensionless_type, dim<length_tag, static_rational<1L, 1L> > >::type>));
    BOOST_MPL_ASSERT((boost::is_same<mass_type, mpl::push_front<dimensionless_type, dim<mass_tag, static_rational<1L, 1L> > >::type>));
    BOOST_MPL_ASSERT((boost::is_same<energy_type, 
        mpl::push_front<
        mpl::push_front<
        mpl::push_front<
        dimensionless_type,
        dim<time_tag, static_rational<-2L, 1L> > >::type,
        dim<mass_tag, static_rational<1L, 1L> > >::type,
        dim<length_tag, static_rational<2L, 1L> > >::type>));
                              
    std::cout << "length_type  = " << simplify_mpl_typename(length_type()) << std::endl
              << "mass_type    = " << simplify_mpl_typename(mass_type()) << std::endl
              << "time_type    = " << simplify_mpl_typename(time_type()) << std::endl
              << "energy_type  = " << simplify_mpl_typename(energy_type()) << std::endl;
    
    //[unit_example_1_snippet_1
    typedef static_multiply<length_type,mass_type>::type                                       LM_type;
    typedef static_divide<length_type,time_type>::type                                         L_T_type;
    typedef static_root<static_divide<energy_type,mass_type>::type,static_rational<2> >::type  V_type;
    //]
    
    BOOST_MPL_ASSERT((boost::is_same<LM_type, 
        mpl::push_front<
        mpl::push_front<
        dimensionless_type,
        dim<mass_tag, static_rational<1L, 1L> > >::type,
        dim<length_tag, static_rational<1L, 1L> > >::type>));

    BOOST_MPL_ASSERT((boost::is_same<L_T_type, 
        mpl::push_front<
        mpl::push_front<
        dimensionless_type,
        dim<time_tag, static_rational<-1L, 1L> > >::type,
        dim<length_tag, static_rational<1L, 1L> > >::type>));

    BOOST_MPL_ASSERT((boost::is_same<V_type, 
        mpl::push_front<
        mpl::push_front<
        dimensionless_type,
        dim<time_tag, static_rational<-1L, 1L> > >::type,
        dim<length_tag, static_rational<1L, 1L> > >::type>));
    
    std::cout << "LM_type      = " << simplify_mpl_typename(LM_type()) << std::endl
              << "L_T_type     = " << simplify_mpl_typename(L_T_type()) << std::endl
              << "V_type       = " << simplify_mpl_typename(V_type()) << std::endl;
              
    return 0;
}
