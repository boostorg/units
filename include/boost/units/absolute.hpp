// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_ABSOLUTE_HPP
#define BOOST_UNITS_ABSOLUTE_HPP

#include <iosfwd>

#include <boost/type_traits/is_base_and_derived.hpp>

#include <boost/units/config.hpp>
#include <boost/units/conversion.hpp>
#include <boost/units/heterogeneous_system.hpp>
#include <boost/units/units_fwd.hpp>

namespace boost {

namespace units {

/// A wrapper to represent absolute units.  Intended
/// originally for temperatures, this template causes
/// absolute<T> +/- T -> absolute<T>
/// absolute<T> - absolute<T> -> T
template<class Y>
class absolute
{
    public:
        typedef absolute<Y>     this_type;
        typedef Y               value_type;
        
        absolute() : val_() { }
        absolute(const value_type& val) : val_(val) { }
        absolute(const this_type& source) : val_(source.val_) { }
   
        this_type& operator=(const this_type& source)           { val_ = source.val_; return *this; }
        
        const value_type& value() const                         { return val_; }
        
        const this_type& operator+=(const value_type& val)      { val_ += val; return *this; }
        const this_type& operator-=(const value_type& val)      { val_ -= val; return *this; }
        
    private:
        value_type   val_;
};

} // namespace units

} // namespace boost

#if BOOST_UNITS_HAS_BOOST_TYPEOF

#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

BOOST_TYPEOF_REGISTER_TEMPLATE(boost::units::absolute, (class))

#endif

namespace boost {

namespace units {

namespace detail {

struct undefined_affine_conversion_base {};

}

/// INTERNAL ONLY
template<class From, class To>
struct affine_conversion_helper : detail::undefined_affine_conversion_base {};

namespace detail {

template<bool IsDefined, bool ReverseIsDefined>
struct affine_conversion_impl;

template<bool ReverseIsDefined>
struct affine_conversion_impl<true, ReverseIsDefined>
{
    template<class Unit1, class Unit2, class T0, class T1>
    struct apply {
        static T1 value(const T0& t0)
        {
            return(
                t0 * 
                conversion_factor(Unit1(), Unit2()) +
                affine_conversion_helper<typename reduce_unit<Unit1>::type, typename reduce_unit<Unit2>::type>::value());
        }
    };
};

template<>
struct affine_conversion_impl<false, true>
{
    template<class Unit1, class Unit2, class T0, class T1>
    struct apply
    {
        static T1 value(const T0& t0)
        {
            return(
                (t0 - affine_conversion_helper<typename reduce_unit<Unit2>::type, typename reduce_unit<Unit1>::type>::value()) * 
                conversion_factor(Unit1(), Unit2()));
        }
    };
};

}

/// INTERNAL ONLY
template<class Unit1, class T1, class Unit2, class T2>
struct conversion_helper<quantity<absolute<Unit1>, T1>, quantity<absolute<Unit2>, T2> >
{
    typedef quantity<absolute<Unit1>, T1> from_quantity_type;
    typedef quantity<absolute<Unit2>, T2> to_quantity_type;
    static to_quantity_type convert(const from_quantity_type& source)
    {
        return(
            to_quantity_type::from_value(
                detail::affine_conversion_impl<
                    !boost::is_base_and_derived<
                        detail::undefined_affine_conversion_base, 
                        affine_conversion_helper<typename reduce_unit<Unit1>::type, typename reduce_unit<Unit2>::type>
                    >::value,
                    !boost::is_base_and_derived<
                        detail::undefined_affine_conversion_base,
                        affine_conversion_helper<typename reduce_unit<Unit2>::type, typename reduce_unit<Unit1>::type>
                    >::value
                >::template apply<Unit1, Unit2, T1, T2>::value(source.value())
            )
        );
    }
};

/// Defines the offset between two absolute units.
/// Requires the value to be in the destination units e.g
/// @code
/// BOOST_UNITS_DEFINE_AFFINE_CONVERSION(celsius_base_unit, fahrenheit_base_unit::unit_type, double, 32.0);
/// @endcode
/// @c BOOST_UNITS_DEFINE_CONVERSION is also necessary to
/// specify the conversion factor.  Like @c BOOST_UNITS_DEFINE_CONVERSION
/// defining celsius->fahrenheit as above will be sufficient
/// to get fahrenheit->celsius also.
#define BOOST_UNITS_DEFINE_AFFINE_CONVERSION(From, To, type_, value_)   \
    namespace boost {                                                   \
    namespace units {                                                   \
    template<>                                                          \
    struct affine_conversion_helper<From, To>                           \
    {                                                                   \
        typedef type_ type;                                             \
        static type value() { return(value_); }                         \
    };                                                                  \
    }                                                                   \
    }                                                                   \
    void boost_units_require_semicolon()

/// add a relative value to an absolute one
template<class Y>
absolute<Y> operator+(const absolute<Y>& aval,const Y& rval)
{
    return absolute<Y>(aval.value()+rval);
}

/// add a relative value to an absolute one
template<class Y>
absolute<Y> operator+(const Y& rval,const absolute<Y>& aval)
{
    return absolute<Y>(aval.value()+rval);
}

/// subtract a relative value from an absolute one
template<class Y>
absolute<Y> operator-(const absolute<Y>& aval,const Y& rval)
{
    return absolute<Y>(aval.value()-rval);
}

/// subtracting two absolutes gives a difference (Like pointers)
template<class Y>
Y operator-(const absolute<Y>& aval1,const absolute<Y>& aval2)
{
    return Y(aval1.value()-aval2.value());
}

/// INTERNAL ONLY
template<class D, class S>
struct reduce_unit<absolute<unit<D, S> > >
{
    typedef absolute<typename reduce_unit<unit<D, S> >::type> type;
};

/// multiplying an absolute unit by a scalar gives a quantity
/// just like an ordinary unit
template<class D, class S, class T>
quantity<absolute<unit<D, S> >, T> operator*(const T& t, const absolute<unit<D, S> >&)
{
    return(quantity<absolute<unit<D, S> >, T>::from_value(t));
}
/// multiplying an absolute unit by a scalar gives a quantity
/// just like an ordinary unit
template<class D, class S, class T>
quantity<absolute<unit<D, S> >, T> operator*(const absolute<unit<D, S> >&, const T& t)
{
    return(quantity<absolute<unit<D, S> >, T>::from_value(t));
}

/// Print an absolute unit
template<class Y>
std::ostream& operator<<(std::ostream& os,const absolute<Y>& aval)
{

    os << "absolute " << aval.value();
    
    return os;
}

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_ABSOLUTE_HPP
