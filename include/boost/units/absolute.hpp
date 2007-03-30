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