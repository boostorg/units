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

#include <boost/units/conversion.hpp>

namespace boost {

namespace units {

template<class Y = double>
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

namespace detail {

struct undefined_affine_conversion_base {};

}

template<class From, class To>
struct affine_conversion_helper : detail::undefined_affine_conversion_base {};

namespace detail {

template<bool IsDefined, bool ReverseIsDefined>
struct affine_conversion_impl;

template<bool ReverseIsDefined>
struct affine_conversion_impl<true, ReverseIsDefined> {
    template<class Unit1, class Unit2, class T0, class T1>
    struct apply {
        static T1 value(const T0& t0) {
            return(
                t0 * 
                conversion_factor(Unit1(), Unit2()) +
                affine_conversion_helper<typename reduce_unit<Unit1>::type, typename reduce_unit<Unit2>::type>::value());
        }
    };
};

template<>
struct affine_conversion_impl<false, true> {
    template<class Unit1, class Unit2, class T0, class T1>
    struct apply {
        static T1 value(const T0& t0) {
            return(
                (t0 - affine_conversion_helper<typename reduce_unit<Unit2>::type, typename reduce_unit<Unit1>::type>::value()) * 
                conversion_factor(Unit1(), Unit2()));
        }
    };
};

}

template<class Unit1, class T1, class Unit2, class T2>
struct conversion_helper<quantity<absolute<Unit1>, T1>, quantity<absolute<Unit2>, T2> > {
    typedef quantity<absolute<Unit1>, T1> from_quantity_type;
    typedef quantity<absolute<Unit2>, T2> to_quantity_type;
    static to_quantity_type convert(const from_quantity_type& source) {
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

// a macro for consistancy
#define BOOST_UNITS_DEFINE_AFFINE_CONVERSION(From, To, type_, value_)\
    namespace boost {\
    namespace units {\
    template<>\
    struct affine_conversion_helper<From, To> {\
        typedef type_ type;\
        static type value() {return(value_);}\
    };\
    }\
    }\
    void boost_units_require_semicolon()

template<class Y>
absolute<Y> operator+(const absolute<Y>& aval,const Y& rval)
{
    return absolute<Y>(aval.value()+rval.value());
}

template<class Y>
absolute<Y> operator+(const Y& rval,const absolute<Y>& aval)
{
    return absolute<Y>(aval.value()+rval.value());
}

template<class Y>
absolute<Y> operator-(const absolute<Y>& aval,const Y& rval)
{
    return absolute<Y>(aval.value()-rval.value());
}

template<class Y>
Y operator-(const absolute<Y>& aval1,const absolute<Y>& aval2)
{
    return Y(aval1.value()-aval2.value());
}

template<class U, class T>
class quantity;

template<class D, class S>
class unit;

template<class Unit>
struct reduce_unit;

template<class D, class S>
struct reduce_unit<absolute<unit<D, S> > > {
    typedef absolute<typename reduce_unit<unit<D, S> >::type> type;
};

template<class D, class S, class T>
quantity<absolute<unit<D, S> >, T> operator*(const T& t, const absolute<unit<D, S> >&) {
    return(quantity<absolute<unit<D, S> >, T>::from_value(t));
}

template<class Y>
std::ostream& operator<<(std::ostream& os,const absolute<Y>& aval)
{
    using namespace std;
    
    os << "absolute " << aval.value();
    
    return os;
}

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_ABSOLUTE_HPP
