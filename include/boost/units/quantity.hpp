// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_QUANTITY_HPP
#define BOOST_UNITS_QUANTITY_HPP

#include <algorithm>

#include <boost/config.hpp>
#include <boost/mpl/bool_fwd.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_convertible.hpp>

#include <boost/units/unit.hpp>

namespace boost {

namespace units {

template<class Q1,class Q2> class conversion_helper;
template<class Unit,class Y = double> class quantity;

/// class declaration
//template<class System,class Dim,class Y>
//class quantity<unit<Dim,System>,Y>
//{
//    public:
//        typedef quantity<unit<Dim,System>,Y>            this_type;
template<class Unit,class Y>
class quantity
{
    public:
        typedef quantity<Unit,Y>                        this_type;
        typedef typename get_dimension<Unit>::type      Dim;
        typedef typename get_system<Unit>::type         System;

        BOOST_STATIC_ASSERT((detail::check_system<System, Dim>::value == true));
        
        typedef Y                                       value_type;
        typedef System                                  system_type;
        typedef Dim                                     dimension_type;
        typedef unit<dimension_type,system_type>        unit_type;
         
        quantity() : val_() { }
        quantity(const this_type& source) : val_(source.val_) { }
        //~quantity() { }
        
        this_type& operator=(const this_type& source) 
        { 
             if (this == &source) return *this;
              
             val_ = source.val_; 
             
             return *this; 
        }

        /// implicit conversion between value types is allowed if allowed for value types themselves
        template<class YY>
        quantity(const quantity<unit<dimension_type,system_type>,YY>& source) :
            val_(source.value())
        { 
            BOOST_STATIC_ASSERT((boost::is_convertible<YY, Y>::value == true));
        }
        
        /// implicit assignment between value types is allowed if allowed for value types themselves
        template<class YY>
        this_type& operator=(const quantity<unit<dimension_type,system_type>,YY>& source)
        {
            BOOST_STATIC_ASSERT((boost::is_convertible<YY, Y>::value == true));

            *this = this_type(source);
            
            return *this;
        }

#ifndef BOOST_NO_SFINAE

        /// explicit conversion between different unit systems is allowed if implicit conversion is disallowed
        template<class System2,class Dim2,class YY> 
        explicit
        quantity(const quantity<unit<Dim2,System2>,YY>& source, 
                 typename boost::disable_if<typename is_implicitly_convertible<unit<Dim2,System2>,unit<Dim,System> >::type>::type* = 0)
             : val_(conversion_helper<quantity<unit<Dim2,System2>,YY>,this_type>::convert(source).value())
        {
            BOOST_STATIC_ASSERT((boost::is_convertible<YY, Y>::value == true));
        }

        /// implicit conversion between different unit systems is allowed if each fundamental dimension is implicitly convertible
        template<class System2,class Dim2,class YY> 
        quantity(const quantity<unit<Dim2,System2>,YY>& source, 
                 typename boost::enable_if<typename is_implicitly_convertible<unit<Dim2,System2>,unit<Dim,System> >::type>::type* = 0)
             : val_(conversion_helper<quantity<unit<Dim2,System2>,YY>,this_type>::convert(source).value())
        {
            BOOST_STATIC_ASSERT((boost::is_convertible<YY, Y>::value == true));
        }

#else

        /// without SFINAE we can't distinguish between explicit and implicit conversions
        template<class System2,class Dim2,class YY> 
        quantity(const quantity<unit<Dim2,System2>,YY>& source)
             : val_(conversion_helper<quantity<unit<Dim2,System2>,YY>,this_type>::convert(source).value())
        {
            BOOST_STATIC_ASSERT((boost::is_convertible<YY, Y>::value == true));
            BOOST_STATIC_ASSERT((is_implicitly_convertible<unit<Dim2,System2>,unit<Dim,System> >::value == true));
        }

#endif
        
        /// implicit assignment between different unit systems is allowed if each fundamental dimension is implicitly convertible 
        template<class System2,class Dim2,class YY>
        this_type& operator=(const quantity<unit<Dim2,System2>,YY>& source)
        {
            typedef unit<Dim,System>                unit1_type;
            typedef unit<Dim2,System2>              unit2_type;
            
            BOOST_STATIC_ASSERT((is_implicitly_convertible<unit2_type,unit1_type>::value == true));
            BOOST_STATIC_ASSERT((boost::is_convertible<YY,Y>::value == true));
            
            *this = this_type(source);
            
            return *this;
        }

        value_type& value()                                 { return val_; }                        ///< mutating accessor to value
        const value_type& value() const                     { return val_; }                        ///< constant accessor to value
        
        // need to check that add_typeof_helper<value_type,value_type>==value_type
        this_type& operator+=(const this_type& source)      { val_ += source.val_; return *this; }  ///< can add quantity of same type

        // need to check that subtract_typeof_helper<value_type,value_type>==value_type
        this_type& operator-=(const this_type& source)      { val_ -= source.val_; return *this; }  ///< can subtract quantity of same type

        this_type& operator*=(const value_type& val)        { val_ *= val; return *this; }          ///< can multiply quantity by scalar
        this_type& operator/=(const value_type& val)        { val_ /= val; return *this; }          ///< can divide quantity by scalar
    
        /// Construct quantity directly from @c value_type (potentially dangerous).
        static this_type from_value(const value_type& val)  { return this_type(val); }

    protected:
        explicit quantity(const value_type& val) : val_(val) { }
        
    private:
        value_type    val_;
};

/// Specialization for dimensionless quantities. Implicit conversions between 
/// unit systems are allowed because all dimensionless quantities are equivalent.
/// Implicit construction and assignment from and conversion to @c value_type is
/// also allowed.
template<class System,class Y>
class quantity<unit<dimensionless_type,System>,Y>
{
    public:
        typedef quantity<unit<dimensionless_type,System>,Y>    this_type;
                                   
        typedef Y                                   value_type;
        typedef System                              system_type;
        typedef dimensionless_type                  dimension_type;
        typedef unit<dimension_type,system_type>    unit_type;
         
        quantity() : val_() { }
        quantity(value_type val) : val_(val) { }                    ///< construction from raw @c value_type is allowed
        quantity(const this_type& source) : val_(source.val_) { }
        //~quantity() { }
        
        this_type& operator=(const this_type& source) 
        { 
            if (this == &source) return *this;
            
            val_ = source.val_; 
                
            return *this; 
        }
        
        /// implicit conversion between value types is allowed if allowed for value types themselves
        template<class YY>
        quantity(const quantity<unit<dimension_type,system_type>,YY>& source) :
            val_(source.value())
        { 
            BOOST_STATIC_ASSERT((boost::is_convertible<YY, Y>::value == true));
        }
        
        /// implicit assignment between value types is allowed if allowed for value types themselves
        template<class YY>
        this_type& operator=(const quantity<unit<dimension_type,system_type>,YY>& source)
        {
            BOOST_STATIC_ASSERT((boost::is_convertible<YY, Y>::value == true));

            *this = this_type(source);
            
            return *this;
        }

        /// implicit conversion between different unit systems is allowed
        template<class System2> 
        quantity(const quantity<unit<dimensionless_type,System2>,Y>& source) :
            val_(source.value()) 
        { }

        /// implicit assignment between different unit systems is allowed
        template<class System2>
        this_type& operator=(const quantity<unit<dimensionless_type,System2>,Y>& source)
        {
            *this = this_type(source);
            
            return *this;
        }
        
        /// implicit conversion to @c value_type is allowed
        operator value_type() const                         { return val_; }
        
        value_type& value()                                 { return val_; }                        ///< mutating accessor to value
        value_type value() const                            { return val_; }                        ///< constant accessor to value
        
        // can add or subtract same quantity type
        this_type& operator+=(const this_type& source)      { val_ += source.val_; return *this; }  ///< can add quantity of same type
        this_type& operator-=(const this_type& source)      { val_ -= source.val_; return *this; }  ///< can subtract quantity of same type
        // consider adding *=,/= for dimensionless_type
        
        // can multiply or divide by value_type
        this_type& operator*=(const value_type& val)        { val_ *= val; return *this; }          ///< can multiply quantity by scalar
        this_type& operator/=(const value_type& val)        { val_ /= val; return *this; }          ///< can divide quantity by scalar
        // consider adding +=,-= for dimensionless_type

        /// Construct quantity directly from @c value_type.
        static this_type from_value(const value_type& val)  { return this_type(val); }

   private:
        value_type    val_;
};

}

}

#if BOOST_UNITS_HAS_BOOST_TYPEOF

#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

BOOST_TYPEOF_REGISTER_TEMPLATE(boost::units::quantity, 2)

#endif

namespace boost {

namespace units {

/// swap quantities
template<class Unit,class Y>
inline void swap(quantity<Unit,Y>& rhs, quantity<Unit,Y>& lhs)
{
    using std::swap;
    swap(rhs.value(),lhs.value());
}

/// utility class to simplify construction of dimensionless quantities
template<class System,class Y>
struct dimensionless_quantity
{
    typedef quantity<typename dimensionless_unit<System>::type,Y>   type;
};

/// check that a type is a quantity
template<typename T>
struct is_quantity :
    public mpl::false_
{ };

template<class Unit,
         class Y>
struct is_quantity< quantity<Unit,Y> > : 
    public mpl::true_
{ };

/// check that a type is a quantity in a specified system
template<class T,class System>
struct is_quantity_of_system :
    public mpl::false_
{ };

template<class Dim,
         class System,
         class Y>
struct is_quantity_of_system< quantity< unit<Dim,System>,Y>,System > :
    public mpl::true_
{ };

/// check that a type is a quantity of the specified dimension
template<class T,class Dim>
struct is_quantity_of_dimension :
    public mpl::false_
{ };

template<class Dim,class System,class Y>
struct is_quantity_of_dimension< quantity< unit<Dim,System>,Y>,Dim > :
    public mpl::true_
{ };

/// check that a type is dimensionless
template<class System,class Y>
struct is_dimensionless< quantity<unit<dimensionless_type,System>,Y> > :
    public mpl::true_
{ };

/// check that a type is a dimensionless quantity
template<class T>
struct is_dimensionless_quantity :
    public is_quantity_of_dimension<T,dimensionless_type>
{ };

/// get dimension
template<class Unit,class Y>
struct get_dimension< quantity<Unit,Y> >
{
    typedef typename get_dimension<Unit>::type  type;
};

/// get system
template<class Unit,class Y>
struct get_system< quantity<Unit,Y> >
{
    typedef typename get_system<Unit>::type     type;
};

/// helper class for quantity_cast
template<class X,class Y> struct quantity_cast_helper;

/// specialization for construction of quantity from raw value_type
template<class Unit,class X,class Y>
struct quantity_cast_helper< quantity<Unit,X>,Y >
{
    typedef quantity<Unit,X>    type;
    
    type operator()(const Y& source)                                { return type::from_value(source); }
};

/// specialization for casting from one value_type to another
template<class Unit,class X,class Y>
struct quantity_cast_helper< X,quantity<Unit,Y> >
{
    typedef quantity<Unit,X>    type;
    
    type operator()(const quantity<Unit,Y>& source)                 { return type::from_value(source.value()); }
};

/// specialization for casting from one unit system to another
template<class X,class System,class Dim,class Unit2>
struct quantity_cast_helper< unit<Dim,System>,quantity<Unit2,X> >
{
    typedef quantity<unit<Dim,System>,X>    type;
    
    type operator()(const quantity<Unit2,X>& source)                { return type(source); }
};

/// quantity_cast supporting three types of casting:
///
/// 1) Casting from a @c value_type to a @c quantity :
/// @verbatim quantity<Unit,X> q = quantity_cast< quantity<Unit,X> >(const X&); @endverbatim
/// 2) Casting from one @c value_type to another @c value_type :
/// @verbatim quantity<Unit,X> q = quantity_cast<X>(const quantity<Unit,Y>&); @endverbatim
/// 3) Casting from one unit system to another :
/// @verbatim quantity<unit,X> q = quantity_cast< unit<Dim,System1> >(const quantity<unit<Dim,System2> >,X>&); @endverbatim
template<class X,class Y>
inline 
typename quantity_cast_helper<X,Y>::type
quantity_cast(const Y& source)
{
    quantity_cast_helper<X,Y>   qch;
    
    return qch(source);
}

/// specialize unary plus typeof helper
template<class Unit,class Y>
struct unary_plus_typeof_helper< quantity<Unit,Y> >
{
    typedef typename unary_plus_typeof_helper<Y>::type      value_type;
    typedef typename unary_plus_typeof_helper<Unit>::type   unit_type;
    typedef quantity<unit_type,value_type>                  type;
};

/// specialize unary minus typeof helper
template<class Unit,class Y>
struct unary_minus_typeof_helper< quantity<Unit,Y> >
{
    typedef typename unary_minus_typeof_helper<Y>::type     value_type;
    typedef typename unary_minus_typeof_helper<Unit>::type  unit_type;
    typedef quantity<unit_type,value_type>                  type;
};

/// specialize add typeof helper
template<class Unit1,
         class Unit2,
         class X,
         class Y>
struct add_typeof_helper< quantity<Unit1,X>,quantity<Unit2,Y> >
{
    typedef typename add_typeof_helper<X,Y>::type           value_type;
    typedef typename add_typeof_helper<Unit1,Unit2>::type   unit_type;
    typedef quantity<unit_type,value_type>                  type;
};

/// specialize subtract typeof helper
template<class Unit1,
         class Unit2,
         class X,
         class Y>
struct subtract_typeof_helper< quantity<Unit1,X>,quantity<Unit2,Y> >
{
    typedef typename subtract_typeof_helper<X,Y>::type          value_type;
    typedef typename subtract_typeof_helper<Unit1,Unit2>::type  unit_type;
    typedef quantity<unit_type,value_type>                      type;
};

/// scalar times unit typeof helper
template<class System,
         class Dim,
         class X>
struct multiply_typeof_helper< X,unit<Dim,System> >
{
    typedef X                               value_type;
    typedef unit<Dim,System>                unit_type;
    typedef quantity<unit_type,value_type>  type;
};

/// unit times scalar typeof helper
template<class System,
         class Dim,
         class X>
struct multiply_typeof_helper< unit<Dim,System>,X >
{
    typedef X                               value_type;
    typedef unit<Dim,System>                unit_type;
    typedef quantity<unit_type,value_type>  type;
};

/// scalar times quantity typeof helper
template<class Unit,
         class X,
         class Y>
struct multiply_typeof_helper< X,quantity<Unit,Y> >
{
    typedef typename multiply_typeof_helper<X,Y>::type  value_type;
    typedef Unit                                        unit_type;
    typedef quantity<unit_type,value_type>              type;
};

/// quantity times scalar typeof helper
template<class Unit,
         class X,
         class Y>
struct multiply_typeof_helper< quantity<Unit,X>,Y >
{
    typedef typename multiply_typeof_helper<X,Y>::type  value_type;
    typedef Unit                                        unit_type;
    typedef quantity<unit_type,value_type>              type;
};

/// unit times quantity typeof helper
template<class Unit,
         class System,
         class Dim,
         class X>
struct multiply_typeof_helper< unit<Dim,System>,quantity<Unit,X> >
{
    typedef X                                                               value_type;
    typedef typename multiply_typeof_helper< unit<Dim,System>,Unit >::type  unit_type;
    typedef quantity<unit_type,value_type>                                  type;
};

/// quantity times unit typeof helper
template<class Unit,
         class System,
         class Dim,
         class X>
struct multiply_typeof_helper< quantity<Unit,X>,unit<Dim,System> >
{
    typedef X                                                               value_type;
    typedef typename multiply_typeof_helper< Unit,unit<Dim,System> >::type  unit_type;
    typedef quantity<unit_type,value_type>                                  type;
};

/// quantity times quantity typeof helper
template<class Unit1,
         class Unit2,
         class X,
         class Y>
struct multiply_typeof_helper< quantity<Unit1,X>,quantity<Unit2,Y> >
{
    typedef typename multiply_typeof_helper<X,Y>::type          value_type;
    typedef typename multiply_typeof_helper<Unit1,Unit2>::type  unit_type;
    typedef quantity<unit_type,value_type>                      type;
};

/// scalar divided by unit typeof helper
template<class System,
         class Dim,
         class X>
struct divide_typeof_helper< X,unit<Dim,System> >
{
    typedef X                                                                           value_type;
    typedef typename power_typeof_helper< unit<Dim,System>,static_rational<-1> >::type  unit_type;
    typedef quantity<unit_type,value_type>                                              type;
};

/// unit divided by scalar typeof helper
template<class System,
         class Dim,
         class X>
struct divide_typeof_helper< unit<Dim,System>,X >
{
    typedef typename divide_typeof_helper<X,X>::type    value_type;
    typedef unit<Dim,System>                            unit_type;
    typedef quantity<unit_type,value_type>              type;
};

/// scalar divided by quantity typeof helper
template<class Unit,
         class X,
         class Y>
struct divide_typeof_helper< X,quantity<Unit,Y> >
{
    typedef typename divide_typeof_helper<X,Y>::type                        value_type;
    typedef typename power_typeof_helper< Unit,static_rational<-1> >::type  unit_type;
    typedef quantity<unit_type,value_type>                                  type;
};

/// quantity divided by scalar typeof helper
template<class Unit,
         class X,
         class Y>
struct divide_typeof_helper< quantity<Unit,X>,Y >
{
    typedef typename divide_typeof_helper<X,Y>::type    value_type;
    typedef Unit                                        unit_type;
    typedef quantity<unit_type,value_type>              type;
};

/// unit divided by quantity typeof helper
template<class Unit,
         class System,
         class Dim,
         class X>
struct divide_typeof_helper< unit<Dim,System>,quantity<Unit,X> >
{
    typedef typename divide_typeof_helper<X,X>::type                        value_type;
    typedef typename divide_typeof_helper< unit<Dim,System>,Unit >::type    unit_type;
    typedef quantity<unit_type,value_type>                                  type;
};

/// quantity divided by unit typeof helper
template<class Unit,
         class System,
         class Dim,
         class X>
struct divide_typeof_helper< quantity<Unit,X>,unit<Dim,System> >
{
    typedef X                                                               value_type;
    typedef typename divide_typeof_helper< Unit,unit<Dim,System> >::type    unit_type;
    typedef quantity<unit_type,value_type>                                  type;
};

/// quantity divided by quantity typeof helper
template<class Unit1,
         class Unit2,
         class X,
         class Y>
struct divide_typeof_helper< quantity<Unit1,X>,quantity<Unit2,Y> >
{
    typedef typename divide_typeof_helper<X,Y>::type            value_type;
    typedef typename divide_typeof_helper<Unit1,Unit2>::type    unit_type;
    typedef quantity<unit_type,value_type>                      type;
};

/// specialize power typeof helper
template<class Unit,long N,long D,class Y> 
struct power_typeof_helper< quantity<Unit,Y>,static_rational<N,D> >                
{ 
    typedef typename power_typeof_helper<Y,static_rational<N,D> >::type     value_type;
    typedef typename power_typeof_helper<Unit,static_rational<N,D> >::type  unit_type;
    typedef quantity<unit_type,value_type>                                  type; 
    
    static type value(const quantity<Unit,Y>& x)  
    { 
        return type::from_value(power_typeof_helper<Y,static_rational<N,D> >::value(x.value()));
    }
};

/// specialize root typeof helper
template<class Unit,long N,long D,class Y> 
struct root_typeof_helper< quantity<Unit,Y>,static_rational<N,D> >                
{ 
    typedef typename root_typeof_helper<Y,static_rational<N,D> >::type      value_type;
    typedef typename root_typeof_helper<Unit,static_rational<N,D> >::type   unit_type;
    typedef quantity<unit_type,value_type>                                  type;
    
    static type value(const quantity<Unit,Y>& x)  
    { 
        return type::from_value(root_typeof_helper<Y,static_rational<N,D> >::value(x.value()));
    }
};

/// runtime unit times scalar
template<class System,
         class Dim,
         class Y>
inline
typename multiply_typeof_helper< unit<Dim,System>,Y >::type
operator*(const unit<Dim,System>&,const Y& rhs)
{
    typedef typename multiply_typeof_helper< unit<Dim,System>,Y >::type type;
    
    return type::from_value(rhs);
}

/// runtime unit divided by scalar
template<class System,
         class Dim,
         class Y>
inline
typename divide_typeof_helper< unit<Dim,System>,Y >::type
operator/(const unit<Dim,System>&,const Y& rhs)
{
    typedef typename divide_typeof_helper<unit<Dim,System>,Y>::type type;
    
    return type::from_value(Y(1)/rhs);
}

/// runtime scalar times unit
template<class System,
         class Dim,
         class Y>
inline
typename multiply_typeof_helper< Y,unit<Dim,System> >::type
operator*(const Y& lhs,const unit<Dim,System>&)
{
    typedef typename multiply_typeof_helper< Y,unit<Dim,System> >::type type;
    
    return type::from_value(lhs);
}

/// runtime scalar divided by unit
template<class System,
         class Dim,
         class Y>
inline
typename divide_typeof_helper< Y,unit<Dim,System> >::type
operator/(const Y& lhs,const unit<Dim,System>&)
{
    typedef typename divide_typeof_helper< Y,unit<Dim,System> >::type   type;
    
    return type::from_value(lhs);
}

/// runtime quantity times scalar
template<class System,
         class Dim,
         class X,
         class Y>
inline
typename multiply_typeof_helper< quantity<unit<Dim,System>,X>,Y >::type
operator*(const quantity<unit<Dim,System>,X>& lhs,const Y& rhs)
{
    typedef typename multiply_typeof_helper< quantity<unit<Dim,System>,X>,Y >::type type;
    
    return type::from_value(lhs.value()*rhs);
}

/// runtime scalar times quantity
template<class System,
         class Dim,
         class X,
         class Y>
inline
typename multiply_typeof_helper< X,quantity<unit<Dim,System>,Y> >::type
operator*(const X& lhs,const quantity<unit<Dim,System>,Y>& rhs)
{
    typedef typename multiply_typeof_helper< X,quantity<unit<Dim,System>,Y> >::type type;
    
    return type::from_value(lhs*rhs.value());
}

/// runtime quantity divided by scalar
template<class System,
         class Dim,
         class X,
         class Y>
inline
typename divide_typeof_helper< quantity<unit<Dim,System>,X>,Y >::type
operator/(const quantity<unit<Dim,System>,X>& lhs,const Y& rhs)
{
    typedef typename divide_typeof_helper< quantity<unit<Dim,System>,X>,Y >::type   type;
    
    return type::from_value(lhs.value()/rhs);
}

/// runtime scalar divided by quantity
template<class System,
         class Dim,
         class X,
         class Y>
inline
typename divide_typeof_helper< X,quantity<unit<Dim,System>,Y> >::type
operator/(const X& lhs,const quantity<unit<Dim,System>,Y>& rhs)
{
    typedef typename divide_typeof_helper< X,quantity<unit<Dim,System>,Y> >::type   type;
    
    return type::from_value(lhs/rhs.value());
}

/// runtime unit times quantity
template<class System1,
         class System2,
         class Dim1,
         class Dim2,
         class Y>
inline
typename multiply_typeof_helper< unit<Dim1,System1>,quantity<unit<Dim2,System2>,Y> >::type
operator*(const unit<Dim1,System1>&,const quantity<unit<Dim2,System2>,Y>& rhs)
{
    typedef typename multiply_typeof_helper< unit<Dim1,System1>,quantity<unit<Dim2,System2>,Y> >::type  type;
    
    return type::from_value(rhs.value());
}

/// runtime unit divided by quantity
template<class System1,
         class System2,
         class Dim1,
         class Dim2,
         class Y>
inline
typename divide_typeof_helper< unit<Dim1,System1>,quantity<unit<Dim2,System2>,Y> >::type
operator/(const unit<Dim1,System1>&,const quantity<unit<Dim2,System2>,Y>& rhs)
{
    typedef typename divide_typeof_helper< unit<Dim1,System1>,quantity<unit<Dim2,System2>,Y> >::type    type;
    
    return type::from_value(Y(1)/rhs.value());
}

/// runtime quantity times unit
template<class System1,
         class System2,
         class Dim1,
         class Dim2,
         class Y>
inline
typename multiply_typeof_helper< quantity<unit<Dim1,System1>,Y>,unit<Dim2,System2> >::type
operator*(const quantity<unit<Dim1,System1>,Y>& lhs,const unit<Dim2,System2>&)
{
    typedef typename multiply_typeof_helper< quantity<unit<Dim1,System1>,Y>,unit<Dim2,System2> >::type  type;
    
    return type::from_value(lhs.value());
}

/// runtime quantity divided by unit
template<class System1,
         class System2,
         class Dim1,
         class Dim2,
         class Y>
inline
typename divide_typeof_helper< quantity<unit<Dim1,System1>,Y>,unit<Dim2,System2> >::type
operator/(const quantity<unit<Dim1,System1>,Y>& lhs,const unit<Dim2,System2>&)
{
    typedef typename divide_typeof_helper< quantity<unit<Dim1,System1>,Y>,unit<Dim2,System2> >::type    type;
    
    return type::from_value(lhs.value());
}

/// runtime unary plus quantity
template<class Unit,class Y>
typename unary_plus_typeof_helper< quantity<Unit,Y> >::type
operator+(const quantity<Unit,Y>& val)
{ 
    typedef typename unary_plus_typeof_helper< quantity<Unit,Y> >::type     type;
    
    return type::from_value(+val.value());
}

/// runtime unary minus quantity
template<class Unit,class Y>
typename unary_minus_typeof_helper< quantity<Unit,Y> >::type
operator-(const quantity<Unit,Y>& val)
{ 
    typedef typename unary_minus_typeof_helper< quantity<Unit,Y> >::type    type;
    
    return type::from_value(-val.value());
}

/// runtime quantity plus quantity
template<class Unit1,
         class Unit2,
         class X,
         class Y>
inline
typename add_typeof_helper< quantity<Unit1,X>,quantity<Unit2,Y> >::type
operator+(const quantity<Unit1,X>& lhs,
          const quantity<Unit2,Y>& rhs)
{
    typedef typename add_typeof_helper< quantity<Unit1,X>,quantity<Unit2,Y> >::type     type;
    
    return type::from_value(lhs.value()+rhs.value());
}

/// runtime quantity minus quantity
template<class Unit1,
         class Unit2,
         class X,
         class Y>
inline
typename subtract_typeof_helper< quantity<Unit1,X>,quantity<Unit2,Y> >::type
operator-(const quantity<Unit1,X>& lhs,
          const quantity<Unit2,Y>& rhs)
{
    typedef typename subtract_typeof_helper< quantity<Unit1,X>,quantity<Unit2,Y> >::type    type;
    
    return type::from_value(lhs.value()-rhs.value());
}

/// runtime quantity times quantity
template<class System1,
         class System2,
         class Dim1,
         class Dim2,
         class X,
         class Y>
inline
typename multiply_typeof_helper< quantity<unit<Dim1,System1>,X>,quantity<unit<Dim2,System2>,Y> >::type
operator*(const quantity<unit<Dim1,System1>,X>& lhs,
          const quantity<unit<Dim2,System2>,Y>& rhs)
{
    typedef typename multiply_typeof_helper< quantity<unit<Dim1,System1>,X>,
                                             quantity<unit<Dim2,System2>,Y> >::type type;
    
    return type::from_value(lhs.value()*rhs.value());
}

/// runtime quantity divided by quantity
template<class System1,
         class System2,
         class Dim1,
         class Dim2,
         class X,
         class Y>
inline
typename divide_typeof_helper< quantity<unit<Dim1,System1>,X>,quantity<unit<Dim2,System2>,Y> >::type
operator/(const quantity<unit<Dim1,System1>,X>& lhs,
          const quantity<unit<Dim2,System2>,Y>& rhs)
{
    typedef typename divide_typeof_helper< quantity<unit<Dim1,System1>,X>,
                                           quantity<unit<Dim2,System2>,Y> >::type   type;
    
    return type::from_value(lhs.value()/rhs.value());
}

/// runtime operator==
template<class System,
         class Dim1,
         class Dim2,
         class X,
         class Y>
inline
bool 
operator==(const quantity<unit<Dim1,System>,X>& val1,
           const quantity<unit<Dim2,System>,Y>& val2)
{
    // ensure dimension lists are commensurate
    BOOST_STATIC_ASSERT((is_same<Dim1,Dim2>::value == true));

    return val1.value() == val2.value();
}

/// runtime operator!=
template<class System,
         class Dim1,
         class Dim2,
         class X,
         class Y>
inline
bool 
operator!=(const quantity<unit<Dim1,System>,X>& val1,
           const quantity<unit<Dim2,System>,Y>& val2)
{
    // ensure dimension lists are commensurate
    BOOST_STATIC_ASSERT((is_same<Dim1,Dim2>::value == true));

    return val1.value() != val2.value();
}

/// runtime operator<
template<class System,
         class Dim1,
         class Dim2,
         class X,
         class Y>
inline
bool 
operator<(const quantity<unit<Dim1,System>,X>& val1,
          const quantity<unit<Dim2,System>,Y>& val2)
{
    // ensure dimension lists are commensurate
    BOOST_STATIC_ASSERT((is_same<Dim1,Dim2>::value == true));

    return val1.value() < val2.value();
}

/// runtime operator<=
template<class System,
         class Dim1,
         class Dim2,
         class X,
         class Y>
inline
bool 
operator<=(const quantity<unit<Dim1,System>,X>& val1,
           const quantity<unit<Dim2,System>,Y>& val2)
{
    // ensure dimension lists are commensurate
    BOOST_STATIC_ASSERT((is_same<Dim1,Dim2>::value == true));

    return val1.value() <= val2.value();
}

/// runtime operator>
template<class System,
         class Dim1,
         class Dim2,
         class X,
         class Y>
inline
bool 
operator>(const quantity<unit<Dim1,System>,X>& val1,
          const quantity<unit<Dim2,System>,Y>& val2)
{
    // ensure dimension lists are commensurate
    BOOST_STATIC_ASSERT((is_same<Dim1,Dim2>::value == true));

    return val1.value() > val2.value();
}

/// runtime operator>=
template<class System,
         class Dim1,
         class Dim2,
         class X,
         class Y>
inline
bool 
operator>=(const quantity<unit<Dim1,System>,X>& val1,
           const quantity<unit<Dim2,System>,Y>& val2)
{
    // ensure dimension lists are commensurate
    BOOST_STATIC_ASSERT((is_same<Dim1,Dim2>::value == true));

    return val1.value() >= val2.value();
}

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_QUANTITY_HPP
