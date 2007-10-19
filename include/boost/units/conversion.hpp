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

#include <boost/units/detail/conversion_impl.hpp>

namespace boost {

namespace units {

template<class From, class To>
struct conversion_helper;

#ifdef BOOST_UNITS_DOXYGEN

/// Template for defining conversions between
/// quantities.  This template should be specialized
/// for every quantity that allows conversions.
/// For example, if you have a two units
/// called pair and dozen you would write
/// @code
/// namespace boost {
/// namespace units {
/// template<class T0, class T1>
/// struct conversion_helper<quantity<dozen, T0>, quantity<pair, T1> >
/// {
///     static quantity<pair, T1> convert(const quantity<dozen, T0>& source)
///     {
///         return(quantity<pair, T1>::from_value(6 * source.value()));
///     }
/// };
/// }
/// }
/// @endcode
template<class From, class To>
struct conversion_helper
{
    static To convert(const From&);
};

#endif

/// Defines the conversion factor from a base unit to any other base
/// unit with the same dimensions.  Must appear at global scope.
/// The reverse need not be defined.
#define BOOST_UNITS_DEFINE_BASE_CONVERSION(Source, Destination, type_, value_)   \
    namespace boost {                                                       \
    namespace units {                                                       \
    template<>                                                              \
    struct select_base_unit_converter<                                      \
        unscale<Source>::type,                                              \
        BOOST_UNITS_MAKE_HETEROGENEOUS_UNIT(unscale<Destination>::type, Source::dimension_type)\
    >                                                                       \
    {                                                                       \
        typedef Source source_type;                                         \
        typedef BOOST_UNITS_MAKE_HETEROGENEOUS_UNIT(Destination, Source::dimension_type) destination_type;\
    };                                                                      \
    template<>                                                              \
    struct base_unit_converter<                                             \
        Source,                                                             \
        BOOST_UNITS_MAKE_HETEROGENEOUS_UNIT(Destination, Source::dimension_type)\
    >                                                                       \
    {                                                                       \
        typedef type_ type;                                                 \
        static type value() { return(value_); }                             \
    };                                                                      \
    }                                                                       \
    }                                                                       \
    void boost_units_require_semicolon()

/// Defines the conversion factor from a base unit to any other base
/// unit with the same dimensions.  Must appear at global scope.
/// The reverse need not be defined.  Neither base unit may be scaled.
#define BOOST_UNITS_DEFINE_BASE_CONVERSION_TEMPLATE(Params, Source, Destination, type_, value_)   \
    namespace boost {                                                       \
    namespace units {                                                       \
    template<BOOST_PP_SEQ_ENUM(Params)>                                     \
    struct base_unit_converter<                                             \
        Source,                                                             \
        BOOST_UNITS_MAKE_HETEROGENEOUS_UNIT(Destination, typename Source::dimension_type)\
    >                                                                       \
    {                                                                       \
        typedef type_ type;                                                 \
        static type value() { return(value_); }                             \
    };                                                                      \
    }                                                                       \
    }                                                                       \
    void boost_units_require_semicolon()

/// Defines the conversion factor from a base unit to any unit
/// with the correct dimensions.  Must appear at global scope.
/// If the destination unit is a unit that contains only one
/// base unit which is raised to the first power (e.g. feet->meters)
/// the reverse need not be defined.
#define BOOST_UNITS_DEFINE_CONVERSION_FACTOR(Source, Destination, type_, value_)   \
    namespace boost {                                                       \
    namespace units {                                                       \
    template<>                                                              \
    struct select_base_unit_converter<                                      \
        unscale<Source>::type,                                              \
        unscale<reduce_unit<Destination>::type>::type                       \
    >                                                                       \
    {                                                                       \
        typedef Source source_type;                                         \
        typedef Destination destination_type;                               \
    };                                                                      \
    template<>                                                              \
    struct base_unit_converter<Source, reduce_unit<Destination>::type>      \
    {                                                                       \
        typedef type_ type;                                                 \
        static type value() { return(value_); }                             \
    };                                                                      \
    }                                                                       \
    }                                                                       \
    void boost_units_require_semicolon()

/// Defines the conversion factor from a base unit to any unit
/// with the correct dimensions.  Must appear at global scope.
/// If the destination unit is a unit that contains only one
/// base unit which is raised to the first power (e.g. feet->meters)
/// the reverse need not be defined. Neither unit may be scaled.
/// The destination must be a heterogeneous unit.  These requirements
/// are rather difficult to check.  If they are not met the specialization
/// will probably vanish silently.
#define BOOST_UNITS_DEFINE_CONVERSION_FACTOR_TEMPLATE(Params, Source, Destination, type_, value_)   \
    namespace boost {                                                       \
    namespace units {                                                       \
    template<BOOST_PP_SEQ_ENUM(Params)>                                     \
    struct base_unit_converter<Source, Destination>                         \
    {                                                                       \
        typedef type_ type;                                                 \
        static type value() { return(value_); }                             \
    };                                                                      \
    }                                                                       \
    }                                                                       \
    void boost_units_require_semicolon()

/// Specifies the default conversion to be applied when
/// no direct conversion is available.
/// Source is a base unit.  Dest is any unit with the
/// same dimensions.
#define BOOST_UNITS_DEFAULT_CONVERSION(Source, Dest)                \
    namespace boost {                                               \
    namespace units {                                               \
    template<>                                                      \
    struct unscaled_get_default_conversion<unscale<Source>::type>   \
    {                                                               \
        typedef Dest type;                                          \
    };                                                              \
    }                                                               \
    }                                                               \
    void boost_units_require_semicolon()

/// Specifies the default conversion to be applied when
/// no direct conversion is available.
/// Params is a PP Sequence of template arguments.
/// Source is a base unit.  Dest is any unit with the
/// same dimensions.  The source must not be a scaled
/// base unit.
#define BOOST_UNITS_DEFAULT_CONVERSION_TEMPLATE(Params, Source, Dest)   \
    namespace boost {                                                   \
    namespace units {                                                   \
    template<BOOST_PP_SEQ_ENUM(Params)>                                 \
    struct unscaled_get_default_conversion<Source>                      \
    {                                                                   \
        typedef Dest type;                                              \
    };                                                                  \
    }                                                                   \
    }                                                                   \
    void boost_units_require_semicolon()

/// Find the conversion factor between two units.
template<class FromUnit,class ToUnit>
inline
typename detail::conversion_factor_helper<FromUnit, ToUnit>::type
conversion_factor(const FromUnit&,const ToUnit&)
{
    return(detail::conversion_factor_helper<FromUnit, ToUnit>::value());
}

#ifndef BOOST_UNITS_DOXYGEN

/// Find the conversion factor between two units with an explicit return type.
/// e.g. conversion_factor<int>(newton, dyne) returns 100000
template<class Y, class FromUnit,class ToUnit>
inline
Y
conversion_factor(const FromUnit&,const ToUnit&)
{
    return(static_cast<Y>(detail::conversion_factor_helper<FromUnit, ToUnit>::value()));
}

#else

/// Find the conversion factor between two units with an explicit return type.
/// e.g. conversion_factor<int>(newton, dyne) returns 100000
template<class Y, class FromUnit,class ToUnit>
inline
Y
conversion_factor<Y>(const FromUnit&,const ToUnit&)
{
    return(static_cast<Y>(detail::conversion_factor_helper<FromUnit, ToUnit>::value()));
}

#endif

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_CONVERSION_HPP
