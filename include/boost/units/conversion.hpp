// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_CONVERSION_HPP
#define BOOST_UNITS_CONVERSION_HPP

#include <boost/units/experimental/conversion.hpp>

//#include <boost/mpl/begin.hpp>
//#include <boost/mpl/size.hpp>
//#include <boost/mpl/bool.hpp>
//
//#include <boost/units/operators.hpp>
//#include <boost/units/quantity.hpp>
//
///// \file 
///// \brief Quantity conversion classes

namespace boost {

namespace units {

//template<class Q1,class Q2> class conversion_helper;
//
///// Convert quantity between homogeneous systems
//template<class S1,
//         class S2,
//         class Dim1,
//         class Y1,
//         class Y2>
//class conversion_helper< quantity<unit<Dim1,homogeneous_system<S1> >,Y1>,
//                         quantity<unit<Dim1,homogeneous_system<S2> >,Y2> >
//{
//    public:
//        typedef homogeneous_system<S1>              system1_type;
//        typedef homogeneous_system<S2>              system2_type;
//        
//        typedef unit<Dim1,system1_type>             unit1_type;
//        typedef unit<Dim1,system2_type>             unit2_type;
//        
//        typedef quantity<unit1_type,Y1>              from_quantity_type;
//        typedef quantity<unit2_type,Y2>              to_quantity_type;
//        
//        static
//        to_quantity_type
//        convert(const from_quantity_type& source)
//        {
//            return to_quantity_type::from_value(source.value()*
//                detail::quantity_conversion_homo_to_homo_impl<mpl::size<Dim1>::value>::template
//                    apply<typename mpl::begin<Dim1>::type, system1_type, system2_type>::value());
//        }
//};
//
///// Convert quantity from homogeneous system to heterogeneous system
//template<class S1,
//         class S2,
//         class Dim1,
//         class Y1,
//         class Y2>
//class conversion_helper< quantity<unit<Dim1,homogeneous_system<S1> >,Y1>,
//                         quantity<unit<Dim1,heterogeneous_system<S2> >,Y2> >
//{
//    public:
//        typedef homogeneous_system<S1>              system1_type;
//        typedef heterogeneous_system<S2>            system2_type;
//        
//        typedef unit<Dim1,system1_type>             unit1_type;
//        typedef unit<Dim1,system2_type>             unit2_type;
//        
//        typedef quantity<unit1_type,Y1>              from_quantity_type;
//        typedef quantity<unit2_type,Y2>              to_quantity_type;
//        
//        static
//        to_quantity_type
//        convert(const from_quantity_type& source)
//        {
//            typedef typename mpl::begin<typename system2_type::type>::type begin;
//            return to_quantity_type::from_value(source.value()*
//                detail::quantity_conversion_homo_to_hetero_impl<mpl::size<typename system2_type::type>::value>::template 
//                    apply<begin, system1_type>::value());
//        }
//};
//
///// Convert quantity from heterogeneous system to homogeneous system
//template<class S1,
//         class S2,
//         class Dim1,
//         class Y1,
//         class Y2>
//class conversion_helper< quantity<unit<Dim1,heterogeneous_system<S1> >,Y1>,
//                         quantity<unit<Dim1,homogeneous_system<S2> >,Y2> >
//{
//    public:
//        typedef heterogeneous_system<S1>    system1_type;
//        typedef homogeneous_system<S2>      system2_type;
//        
//        typedef unit<Dim1,system1_type>     unit1_type;
//        typedef unit<Dim1,system2_type>     unit2_type;
//        
//        typedef quantity<unit1_type,Y1>      from_quantity_type;
//        typedef quantity<unit2_type,Y2>      to_quantity_type;
//        
//        static
//        to_quantity_type
//        convert(const from_quantity_type& source)
//        {
//            typedef typename mpl::begin<typename system1_type::type>::type begin;
//            return to_quantity_type::from_value(source.value()*
//                detail::quantity_conversion_hetero_to_homo_impl<mpl::size<typename system1_type::type>::value>::template
//                apply<begin, system2_type>::value());
//        }
//};
//
///// Convert quantity between heterogeneous systems
//template<class S1,
//         class S2,
//         class Dim1,
//         class Y1,
//         class Y2>
// class conversion_helper< quantity<unit<Dim1,heterogeneous_system<S1> >,Y1>,
//                          quantity<unit<Dim1,heterogeneous_system<S2> >,Y2> >
// {
//    public:
//        typedef heterogeneous_system<S1>    system1_type;
//        typedef heterogeneous_system<S2>    system2_type;
//        
//        typedef unit<Dim1,system1_type>     unit1_type;
//        typedef unit<Dim1,system2_type>     unit2_type;
//        
//        typedef quantity<unit1_type,Y1>      from_quantity_type;
//        typedef quantity<unit2_type,Y2>      to_quantity_type;
//
//        static
//        to_quantity_type
//        convert(const from_quantity_type& source)
//        {   
//            return to_quantity_type::from_value(source.value()*
//                detail::quantity_conversion_hetero_to_hetero<typename system1_type::type,typename system2_type::type>::value());
//        }
//};

template<class Y,class FromUnit,class ToUnit>
inline
Y
conversion_factor(const FromUnit&,const ToUnit&)
{
    // dangerous if conversion is not regular...don't know how to deal with this yet
    return quantity<ToUnit,Y>(Y(1)*FromUnit()).value();
}

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_CONVERSION_HPP
