// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_CONSTANTS_HPP
#define BOOST_UNITS_CONSTANTS_HPP

#include <cmath>
#include <iosfwd>
#include <iomanip>

#include <boost/io/ios_state.hpp>

namespace boost {

namespace units {

template<class Y>
class value_and_uncertainty
{    
    public:
        typedef value_and_uncertainty<Y>        this_type;
        typedef Y                               value_type;
        
        value_and_uncertainty(const value_type& val = value_type(),
                              const value_type& err = value_type()) : 
            value_(val),
            uncertainty_(std::abs(err)) 
        { }
        
        value_and_uncertainty(const this_type& source) : 
            value_(source.value_),
            uncertainty_(source.uncertainty_) 
        { }
        
        //~value_and_uncertainty() { }
        
        this_type& operator=(const this_type& source)
        {
            value_ = source.value_;
            uncertainty_ = source.uncertainty_;
            
            return *this;
        }
        
        operator value_type() const                     { return value_; }
        
        value_type value() const                        { return value_; }
        value_type uncertainty() const                  { return uncertainty_; }
        value_type lower_bound() const                  { return value_-uncertainty_; }
        value_type upper_bound() const                  { return value_+uncertainty_; }

    private:
        value_type          value_,
                            uncertainty_;
};

// stream output
template<class Y>
inline
std::ostream& operator<<(std::ostream& os,const value_and_uncertainty<Y>& val)
{
    boost::io::ios_precision_saver precision_saver(os);
    boost::io::ios_width_saver width_saver(os);
    boost::io::ios_flags_saver flags_saver(os);

    os << std::setw(21);
    
    if (val.uncertainty() > Y(0))
    {
        const Y relative_uncertainty = std::abs(val.uncertainty()/val.value());
    
        const double  exponent = std::log10(relative_uncertainty);
        const long digits_of_precision = static_cast<long>(std::ceil(std::abs(exponent)))+3;
        
        // should try to replicate NIST CODATA syntax 
        os << std::setprecision(digits_of_precision) 
           //<< std::setw(digits_of_precision+8) 
           //<< std::scientific
           << val.value();
//           << long(10*(relative_uncertainty/std::pow(Y(10),Y(exponent))));

        os << " (rel. unc. = " 
           << std::setprecision(1) 
           << std::setw(7) 
           << std::scientific
           << relative_uncertainty << ")";
    }
    else
    {
        os << val.value() << " (exact)";
    }
    
    return os;
}

} // namespace units

} // namespace boost

#include <boost/units/systems/si/codata_constants.hpp>

#endif // BOOST_UNITS_CONSTANTS_HPP
