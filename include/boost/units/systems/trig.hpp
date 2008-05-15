// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_TRIG_HPP
#define BOOST_UNITS_TRIG_HPP

#include <cmath>

#include <boost/units/dimensionless_quantity.hpp>
#include <boost/units/quantity.hpp>
#include <boost/units/systems/si/plane_angle.hpp>

namespace boost {

namespace units { 

/// cos of theta in radians
template<class Y>
typename dimensionless_quantity<SI::system,Y>::type 
cos(const quantity<SI::plane_angle,Y>& theta)
{
    return std::cos(theta.value());
}

/// sin of theta in radians
template<class Y>
typename dimensionless_quantity<SI::system,Y>::type 
sin(const quantity<SI::plane_angle,Y>& theta)
{
    return std::sin(theta.value());
}

/// tan of theta in radians
template<class Y>
typename dimensionless_quantity<SI::system,Y>::type 
tan(const quantity<SI::plane_angle,Y>& theta)
{
    return std::tan(theta.value());
}

/// cos of theta in other angular units 
template<class System,class Y>
typename dimensionless_quantity<System,Y>::type 
cos(const quantity<unit<plane_angle_dimension,System>,Y>& theta)
{
    return cos(quantity<SI::plane_angle,Y>(theta));
}

/// sin of theta in other angular units 
template<class System,class Y>
typename dimensionless_quantity<System,Y>::type 
sin(const quantity<unit<plane_angle_dimension,System>,Y>& theta)
{
    return sin(quantity<SI::plane_angle,Y>(theta));
}

/// tan of theta in other angular units 
template<class System,class Y>
typename dimensionless_quantity<System,Y>::type 
tan(const quantity<unit<plane_angle_dimension,System>,Y>& theta)
{
    return tan(quantity<SI::plane_angle,Y>(theta));
}

/// acos of @c value_type returning angle in radians
template<class Y>
quantity<SI::plane_angle,Y>
acos(const Y& val)
{
    return quantity<SI::plane_angle,Y>(std::acos(val)*SI::radians);
}

/// acos of dimensionless quantity returning angle in same system
template<class Y,class System>
quantity<unit<plane_angle_dimension,System>,Y>
acos(const quantity<unit<dimensionless_type,System>,Y>& val)
{
    return quantity<unit<plane_angle_dimension,System>,Y>(std::acos(val)*SI::radians);
}

/// asin of @c value_type returning angle in radians
template<class Y>
quantity<SI::plane_angle,Y>
asin(const Y& val)
{
    return quantity<SI::plane_angle,Y>(std::asin(val)*SI::radians);
}

/// asin of dimensionless quantity returning angle in same system
template<class Y,class System>
quantity<unit<plane_angle_dimension,System>,Y>
asin(const quantity<unit<dimensionless_type,System>,Y>& val)
{
    return quantity<unit<plane_angle_dimension,System>,Y>(std::asin(val)*SI::radians);
}

/// atan of @c value_type returning angle in radians
template<class Y>
quantity<SI::plane_angle,Y>
atan(const Y& val)
{
    return quantity<SI::plane_angle,Y>(std::atan(val)*SI::radians);
}

/// atan of dimensionless quantity returning angle in same system
template<class Y,class System>
quantity<unit<plane_angle_dimension,System>,Y>
atan(const quantity<unit<dimensionless_type,System>,Y>& val)
{
    return quantity<unit<plane_angle_dimension,System>,Y>(std::atan(val)*SI::radians);
}

/// atan2 of @c value_type returning angle in radians
template<class Y>
quantity<SI::plane_angle,Y>
atan2(const Y& y,const Y& x)
{
    return quantity<SI::plane_angle,Y>(std::atan2(y,x)*SI::radians);
}

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_TRIG_HPP
