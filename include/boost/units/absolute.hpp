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

template<class From, class To>
struct affine_conversion_helper {
    //F = 9/5 C + 32
    //5/9 F = C + 32 * 5/9
    //C = 5/9 F - 32 * 5/9
    typedef typename affine_conversion_helper<To, From>::type type;
    static type value() { return(-affine_conversion_helper<To, From>::value() * conversion_factor<type>(From(), To())); }
};

template<class Unit1, class T1, class Unit2, class T2>
struct conversion_helper<quantity<absolute<Unit1>, T1>, quantity<absolute<Unit2>, T2> > {
    typedef quantity<absolute<Unit1>, T1> from_quantity_type;
    typedef quantity<absolute<Unit2>, T2> to_quantity_type;
    static to_quantity_type convert(const from_quantity_type& source) {
        return(
            to_quantity_type::from_value(
                source.value() *
                conversion_factor(Unit1(), Unit2()) +
                affine_conversion_helper<typename reduce_unit<Unit1>::type, typename reduce_unit<Unit2>::type>::value()));
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
    
    os << aval.value() << " absolute";
    
    return os;
}

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_ABSOLUTE_HPP
