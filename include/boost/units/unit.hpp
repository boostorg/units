// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_UNIT_HPP
#define BOOST_UNITS_UNIT_HPP

#include <boost/mpl/bool_fwd.hpp>

#include <boost/units/dimension.hpp>
#include <boost/units/system.hpp>
#include <boost/units/units_fwd.hpp>
#include <boost/units/detail/unit_impl.hpp>

namespace boost {

namespace units { 

/// class representing a model-dependent unit with no associated value

/// (e.g. meters, Kelvin, feet, etc...)
template<class Dim,class System>
class unit
{
    public:
        typedef unit<Dim,System>    this_type;
        typedef Dim                 dimension_type; 
        typedef System              system_type;
        
        unit() { }
        unit(const this_type&) { }
        //~unit() { }  
       
        this_type& operator=(const this_type&) { }
        
    private:
        BOOST_STATIC_ASSERT((detail::check_system<System, Dim>::value == true));
};

}

}

#if BOOST_UNITS_HAS_BOOST_TYPEOF

#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

BOOST_TYPEOF_REGISTER_TEMPLATE(boost::units::unit, 2)

#endif

namespace boost {

namespace units {

/// class to specialize for IO
//template<class SystemTag,class DimensionTag> struct unit_info;
//
///// utility class to simplify construction of dimensionless units in a system
//template<class System>
//struct dimensionless_unit
//{
//    typedef unit<dimensionless_type,System> type;
//};
//
//template<class T>
//struct is_unit : 
//    public mpl::false_
//{ };
//
///// check that a type is a unit
//template<class Dim,class System>
//struct is_unit< unit<Dim,System> > :
//    public mpl::true_
//{ };
//
//template<class T,class System>
//struct is_unit_of_system :
//    public mpl::false_
//{ };
//
//template<class T,class Dim>
//struct is_unit_of_dimension :
//    public mpl::false_
//{ };
//
///// check that a type is a unit of the specified dimension
//template<class Dim,class System>
//struct is_unit_of_dimension< unit<Dim,System>,Dim > :
//    public mpl::true_
//{ };
//
///// check that a type is a dimensionless unit
//template<class T>
//struct is_dimensionless_unit :
//    public is_unit_of_dimension<T,dimensionless_type>
//{ };
//    
///// check that a type is a unit in a specified system
//template<class Dim,class System>
//struct is_unit_of_system< unit<Dim,System>,System > :
//    public mpl::true_
//{ };

//template<class T>
//struct is_dimensionless :
//    public mpl::false_
//{ };
//
///// check if a unit is dimensionless
//template<class System>
//struct is_dimensionless< unit<dimensionless_type,System> > :
//    public mpl::true_
//{ };

//template<class S1,class S2> struct is_implicitly_convertible;

template<class S1,class S2> 
struct is_implicitly_convertible :
    public mpl::false_
{ };

/// Determine if two homogeneous units are implicitly convertible
template<class S1,
         class S2,
         class Dim1>
struct is_implicitly_convertible< unit<Dim1,homogeneous_system<S1> >,
                                  unit<Dim1,homogeneous_system<S2> > > :
    mpl::bool_<detail::implicit_conversion_homo_to_homo_impl<mpl::size<Dim1>::value>::template
                apply<typename mpl::begin<Dim1>::type, homogeneous_system<S1>, homogeneous_system<S2> >::value>
{        
    typedef homogeneous_system<S1>              system1_type;
    typedef homogeneous_system<S2>              system2_type;
};

/// Determine if a homogeneous unit is implicitly convertible to a heterogeneous unit
template<class S1,
         class S2,
         class Dim1>
struct is_implicitly_convertible< unit<Dim1,homogeneous_system<S1> >,
                                  unit<Dim1,heterogeneous_system<S2> > > :
    mpl::false_
{        
    typedef homogeneous_system<S1>          system1_type;
    typedef heterogeneous_system<S2>        system2_type;
};

/// Determine if a heterogeneous unit is implicitly convertible to a homogeneous unit
template<class S1,
         class S2,
         class Dim1>
struct is_implicitly_convertible< unit<Dim1,heterogeneous_system<S1> >,
                                  unit<Dim1,homogeneous_system<S2> > > :
    mpl::false_
{
    typedef heterogeneous_system<S1>        system1_type;
    typedef homogeneous_system<S2>          system2_type;
};

/// Determine if two heterogeneous units are implicitly convertible
template<class S1,
         class S2,
         class Dim1>
struct is_implicitly_convertible< unit<Dim1,heterogeneous_system<S1> >,
                                  unit<Dim1,heterogeneous_system<S2> > > :
    //mpl::and_<
    //    is_implicitly_convertible<
    //        unit<Dim1,heterogeneous_system<S1> >,
    //        unit<Dim1,homogeneous_system<typename mpl::front<typename system1_type::type>::type::tag_type> >
    //    >,
    //    is_implicitly_convertible<
    //        unit<Dim1,homogeneous_system<typename mpl::front<typename system1_type::type>::type::tag_type> >,
    //        unit<Dim1,heterogeneous_system<S2> >
    //    >
    //>
    mpl::false_
{        
    typedef heterogeneous_system<S1>        system1_type;
    typedef heterogeneous_system<S2>        system2_type;
};

//template<class T> struct get_dimension;
//
///// get the dimension of a unit
//template<class Dim,class System>
//struct get_dimension< unit<Dim,System> >
//{
//    typedef Dim type;
//};

//template<class T> struct get_system;
//
///// get the system of a unit
//template<class Dim,class System>
//struct get_system< unit<Dim,System> >
//{
//    typedef System type;
//};

/// unit unary plus typeof helper
template<class Dim,class System>
struct unary_plus_typeof_helper< unit<Dim,System> >
{
    typedef unit<typename make_dimension_list<Dim>::type,System>    type;
};

/// unit unary minus typeof helper
template<class Dim,class System>
struct unary_minus_typeof_helper< unit<Dim,System> >
{
    typedef unit<typename make_dimension_list<Dim>::type,System>    type;
};

/// unit add typeof helper
template<class Dim1,
         class Dim2,
         class System>
struct add_typeof_helper< unit<Dim1,System>,unit<Dim2,System> >
{
    // ensure dimension lists are commensurate
    BOOST_STATIC_ASSERT((is_same<Dim1,Dim2>::value == true));

    typedef unit<typename make_dimension_list<Dim1>::type,System>   type;
};

/// unit subtract typeof helper
template<class Dim1,
         class Dim2,
         class System>
struct subtract_typeof_helper< unit<Dim1,System>,unit<Dim2,System> >
{
    // ensure dimension lists are commensurate
    BOOST_STATIC_ASSERT((is_same<Dim1,Dim2>::value == true));

    typedef unit<typename make_dimension_list<Dim1>::type,System>   type;
};

/// unit multiply typeof helper for two identical homogeneous systems
template<class Dim1,
         class Dim2,
         class System>
struct multiply_typeof_helper< unit<Dim1,homogeneous_system<System> >,
                               unit<Dim2,homogeneous_system<System> > >
{
    typedef unit<typename mpl::times<Dim1,Dim2>::type,homogeneous_system<System> >    type;
};

/// unit multiply typeof helper for two different homogeneous systems
template<class Dim1,
         class Dim2,
         class System1,
         class System2>
struct multiply_typeof_helper< unit<Dim1,homogeneous_system<System1> >,
                               unit<Dim2,homogeneous_system<System2> > >
{
    typedef unit<
        typename mpl::times<Dim1,Dim2>::type,
        typename detail::multiply_systems<
            heterogeneous_system_view<System1, Dim1>,
            heterogeneous_system_view<System2, Dim2>
        >::type
    > type;
};

/// unit multiply typeof helper for a heterogeneous and a homogeneous system
template<class Dim1,
         class Dim2,
         class System1,
         class System2>
struct multiply_typeof_helper< unit<Dim1,heterogeneous_system<System1> >,
                               unit<Dim2,homogeneous_system<System2> > >
{
    typedef unit<
        typename mpl::times<Dim1,Dim2>::type,
        typename detail::multiply_systems<
            heterogeneous_system<System1>,
            heterogeneous_system_view<System2, Dim2>
        >::type
    > type;
};

/// unit multiply typeof helper for a homogeneous and a heterogeneous system
template<class Dim1,
         class Dim2,
         class System1,
         class System2>
struct multiply_typeof_helper< unit<Dim1,homogeneous_system<System1> >,
                               unit<Dim2,heterogeneous_system<System2> > >
{
    typedef unit<
        typename mpl::times<Dim1,Dim2>::type,
        typename detail::multiply_systems<
            heterogeneous_system_view<System1, Dim1>,
            heterogeneous_system<System2>
        >::type
    > type;
};

/// unit multiply typeof helper for two heterogeneous systems
template<class Dim1,
         class Dim2,
         class System1,
         class System2>
struct multiply_typeof_helper< unit<Dim1,heterogeneous_system<System1> >,
                               unit<Dim2,heterogeneous_system<System2> > >
{
    typedef unit<
        typename mpl::times<Dim1,Dim2>::type,
        typename detail::multiply_systems<
            heterogeneous_system<System1>,
            heterogeneous_system<System2>
        >::type
    > type;
};

/// unit divide typeof helper for two identical homogeneous systems
template<class Dim1,
         class Dim2,
         class System>
struct divide_typeof_helper< unit<Dim1,homogeneous_system<System> >,
                             unit<Dim2,homogeneous_system<System> > >
{
    typedef unit<typename mpl::divides<Dim1,Dim2>::type,homogeneous_system<System> >    type;
};

/// unit divide typeof helper for two different homogeneous systems
template<class Dim1,
         class Dim2,
         class System1,
         class System2>
struct divide_typeof_helper< unit<Dim1,homogeneous_system<System1> >,
                             unit<Dim2,homogeneous_system<System2> > >
{
    typedef unit<
        typename mpl::divides<Dim1,Dim2>::type,
        typename detail::divide_systems<
            heterogeneous_system_view<System1, Dim1>,
            heterogeneous_system_view<System2, Dim2>
        >::type
    > type;
};

/// unit divide typeof helper for a heterogeneous and a homogeneous system
template<class Dim1,
         class Dim2,
         class System1,
         class System2>
struct divide_typeof_helper< unit<Dim1,heterogeneous_system<System1> >,
                             unit<Dim2,homogeneous_system<System2> > >
{
    typedef unit<
        typename mpl::divides<Dim1,Dim2>::type,
        typename detail::divide_systems<
            heterogeneous_system<System1>,
            heterogeneous_system_view<System2, Dim2>
        >::type
    > type;
};

/// unit divide typeof helper for a homogeneous and a heterogeneous system
template<class Dim1,
         class Dim2,
         class System1,
         class System2>
struct divide_typeof_helper< unit<Dim1,homogeneous_system<System1> >,
                             unit<Dim2,heterogeneous_system<System2> > >
{
    typedef unit<
        typename mpl::divides<Dim1,Dim2>::type,
        typename detail::divide_systems<
            heterogeneous_system_view<System1, Dim1>,
            heterogeneous_system<System2>
        >::type
    > type;
};

/// unit divide typeof helper for two heterogeneous systems
template<class Dim1,
         class Dim2,
         class System1,
         class System2>
struct divide_typeof_helper< unit<Dim1,heterogeneous_system<System1> >,
                             unit<Dim2,heterogeneous_system<System2> > >
{
    typedef unit<
        typename mpl::divides<Dim1,Dim2>::type,
        typename detail::divide_systems<
            heterogeneous_system<System1>,
            heterogeneous_system<System2>
        >::type
    > type;
};

/// raise unit to a @c static_rational power
template<class Dim,class System,long N,long D> 
struct power_typeof_helper<unit<Dim,System>,static_rational<N,D> >                
{ 
    typedef unit<typename static_power<Dim,static_rational<N,D> >::type,System>     type; 
    
    static type value(const unit<Dim,System>&)  
    { 
        return type();
    }
};

/// take the @c static_rational root of a unit
template<class Dim,class System,long N,long D> 
struct root_typeof_helper<unit<Dim,System>,static_rational<N,D> >                
{ 
    typedef unit<typename static_root<Dim,static_rational<N,D> >::type,System>      type; 
    
    static type value(const unit<Dim,System>&)  
    { 
        return type();
    }
};

/// unit runtime unary plus
template<class Dim,class System>
typename unary_plus_typeof_helper< unit<Dim,System> >::type
operator+(const unit<Dim,System>&)
{ 
    typedef typename unary_plus_typeof_helper< unit<Dim,System> >::type type;
    
    return type();
}

/// unit runtime unary minus
template<class Dim,class System>
typename unary_minus_typeof_helper< unit<Dim,System> >::type
operator-(const unit<Dim,System>&)
{ 
    typedef typename unary_minus_typeof_helper< unit<Dim,System> >::type    type;
    
    return type();
}

/// runtime add two units
template<class Dim1,
         class Dim2,
         class System1,
         class System2>
typename add_typeof_helper< unit<Dim1,System1>,
                            unit<Dim2,System2> >::type
operator+(const unit<Dim1,System1>&,const unit<Dim2,System2>&)
{
    BOOST_STATIC_ASSERT((boost::is_same<System1,System2>::value == true));
    
    typedef System1                                                     system_type;
    typedef typename add_typeof_helper< unit<Dim1,system_type>,
                                        unit<Dim2,system_type> >::type  type;
    
    return type();
}

/// runtime subtract two units
template<class Dim1,
         class Dim2,
         class System1,
         class System2>
typename subtract_typeof_helper< unit<Dim1,System1>,
                                 unit<Dim2,System2> >::type
operator-(const unit<Dim1,System1>&,const unit<Dim2,System2>&)
{
    BOOST_STATIC_ASSERT((boost::is_same<System1,System2>::value == true));
    
    typedef System1                                                         system_type;
    typedef typename subtract_typeof_helper< unit<Dim1,system_type>,
                                             unit<Dim2,system_type> >::type type;
    
    return type();
}

/// runtime multiply two units
template<class Dim1,
         class Dim2,
         class System1,
         class System2>
typename multiply_typeof_helper< unit<Dim1,System1>,
                                 unit<Dim2,System2> >::type
operator*(const unit<Dim1,System1>&,const unit<Dim2,System2>&)
{
    typedef typename multiply_typeof_helper< unit<Dim1,System1>,
                                             unit<Dim2,System2> >::type type;
    
    return type();
}

/// runtime divide two units
template<class Dim1,
         class Dim2,
         class System1,
         class System2>
typename divide_typeof_helper< unit<Dim1,System1>,
                               unit<Dim2,System2> >::type
operator/(const unit<Dim1,System1>&,const unit<Dim2,System2>&)
{
    typedef typename divide_typeof_helper< unit<Dim1,System1>,
                                           unit<Dim2,System2> >::type   type;
    
    return type();
}

/// unit runtime @c operator==
template<class Dim1,
         class Dim2,
         class System1,
         class System2>
inline
bool 
operator==(const unit<Dim1,System1>&,const unit<Dim2,System2>&)
{
    return boost::is_same<Dim1,Dim2>::value && boost::is_same<System1,System2>::value;
}

/// unit runtime @c operator!=
template<class Dim1,
         class Dim2,
         class System1,
         class System2>
inline
bool 
operator!=(const unit<Dim1,System1>&,const unit<Dim2,System2>&)
{
    return !boost::is_same<Dim1,Dim2>::value || !boost::is_same<System1,System2>::value;
}

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_UNIT_HPP
