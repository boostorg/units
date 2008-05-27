// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2007-2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_IO_HPP
#define BOOST_UNITS_IO_HPP

#include <cassert>
#include <string>
#include <iosfwd>
#include <ios>
#include <sstream>

#include <boost/mpl/size.hpp>
#include <boost/mpl/begin.hpp>
#include <boost/mpl/next.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/serialization/nvp.hpp>

#include <boost/units/units_fwd.hpp>
#include <boost/units/heterogeneous_system.hpp>
#include <boost/units/quantity.hpp>
#include <boost/units/scale.hpp>
#include <boost/units/static_rational.hpp>
#include <boost/units/unit.hpp>

namespace boost {

namespace serialization {

/// Boost Serialization library support for units.
template<class Archive,class System,class Dim>
inline void serialize(Archive& ar,boost::units::unit<Dim,System>&,const unsigned int /*version*/)
{ }

/// Boost Serialization library support for quantities.
template<class Archive,class Unit,class Y>
inline void serialize(Archive& ar,boost::units::quantity<Unit,Y>& q,const unsigned int /*version*/)
{
    ar & boost::serialization::make_nvp("value", units::quantity_cast<Y&>(q));
}
        
} // namespace serialization

namespace units {

// get string representation of arbitrary type
template<class T> std::string to_string(const T& t)
{
    std::stringstream sstr;
    
    sstr << t;
    
    return sstr.str();
}

// get string representation of integral-valued @c static_rational
template<integer_type N> std::string to_string(const static_rational<N>&)
{
    return to_string(N);
}

// get string representation of @c static_rational
template<integer_type N, integer_type D> std::string to_string(const static_rational<N,D>&)
{
    return '(' + to_string(N) + '/' + to_string(D) + ')';
}

/// Write @c static_rational to @c std::basic_ostream.
template<class Char, class Traits, integer_type N, integer_type D>
inline std::basic_ostream<Char, Traits>& operator<<(std::basic_ostream<Char, Traits>& os,const static_rational<N,D>& r)
{
    os << to_string(r);
    return os;
}

/// traits template for unit names
template<class BaseUnit>
struct base_unit_info
{
    /// The full name of the unit (returns BaseUnit::name() by default)
    static std::string name()
    {
        return(BaseUnit::name());
    }
    
    /// The symbol for the base unit (Returns BaseUnit::symbol() by default)
    static std::string symbol()
    {
        return(BaseUnit::symbol());
    }
};

enum format_mode 
{
	raw,
    symbol,
    name
};

namespace detail {

template<bool>
struct xalloc_key_holder 
{
    static int value;
    static bool initialized;
};

template<bool b>
int xalloc_key_holder<b>::value = 0;

template<bool b>
bool xalloc_key_holder<b>::initialized = 0;

struct xalloc_key_initializer_t 
{
    xalloc_key_initializer_t() 
    {
        if (!xalloc_key_holder<true>::initialized) 
        {
            xalloc_key_holder<true>::value = std::ios_base::xalloc();
            xalloc_key_holder<true>::initialized = true;
        }
    }
};

namespace /**/ {
    
xalloc_key_initializer_t xalloc_key_initializer;

} // namespace

} // namespace detail

inline format_mode get_format(std::ios_base& ios) 
{
    return(static_cast<format_mode>(ios.iword(detail::xalloc_key_holder<true>::value)));
}

inline void set_format(std::ios_base& ios, format_mode new_mode) 
{
    ios.iword(detail::xalloc_key_holder<true>::value) = static_cast<long>(new_mode);
}

inline std::ios_base& raw_format(std::ios_base& ios) 
{
    (set_format)(ios, raw);
    return(ios);
}

inline std::ios_base& symbol_format(std::ios_base& ios) 
{
    (set_format)(ios, symbol);
    return(ios);
}

inline std::ios_base& name_format(std::ios_base& ios) 
{
    (set_format)(ios, name);
    return(ios);
}

namespace detail {

template<integer_type N, integer_type D>
inline std::string exponent_string(const static_rational<N,D>& r)
{
    return '^' + to_string(r);
}

template<>
inline std::string exponent_string(const static_rational<1>&)
{
    return "";
}

template<class T>
inline std::string base_unit_symbol_string(const T&)
{
    return base_unit_info<typename T::tag_type>::symbol() + exponent_string(typename T::value_type());
}

template<class T>    
inline std::string base_unit_name_string(const T&)
{
    return base_unit_info<typename T::tag_type>::name() + exponent_string(typename T::value_type());
}

// stringify with symbols
template<int N>
struct symbol_string_impl
{
    template<class Begin>
    struct apply
    {
        typedef typename symbol_string_impl<N-1>::template apply<typename mpl::next<Begin>::type> next;
        static void value(std::string& str)
        {
            str += base_unit_symbol_string(typename mpl::deref<Begin>::type()) + ' ';
            next::value(str);
        }
    };
};

template<>
struct symbol_string_impl<1>
{
    template<class Begin>
    struct apply
    {
        static void value(std::string& str)
        {
            str += base_unit_symbol_string(typename mpl::deref<Begin>::type());
        };
    };
};

template<>
struct symbol_string_impl<0>
{
    template<class Begin>
    struct apply
    {
        static void value(std::string& str)
        {
            // better shorthand for dimensionless?
            str += "dimensionless";
        }
    };
};

template<int N>
struct scale_symbol_string_impl 
{
    template<class Begin>
    struct apply 
    {
        static void value(std::string& str) 
        {
            str += mpl::deref<Begin>::type::symbol();
            scale_symbol_string_impl<N - 1>::template apply<typename mpl::next<Begin>::type>::value(str);
        }
    };
};

template<>
struct scale_symbol_string_impl<0>
{
    template<class Begin>
    struct apply 
    {
        static void value(std::string&) { }
    };
};

// stringify with names
template<int N>
struct name_string_impl
{
    template<class Begin>
    struct apply
    {
        typedef typename name_string_impl<N-1>::template apply<typename mpl::next<Begin>::type> next;
        static void value(std::string& str)
        {
            str += base_unit_name_string(typename mpl::deref<Begin>::type()) + ' ';
            next::value(str);
        }
    };
};

template<>
struct name_string_impl<1>
{
    template<class Begin>
    struct apply
    {
        static void value(std::string& str)
        {
            str += base_unit_name_string(typename mpl::deref<Begin>::type());
        };
    };
};

template<>
struct name_string_impl<0>
{
    template<class Begin>
    struct apply
    {
        static void value(std::string& str)
        {
            str += "dimensionless";
        }
    };
};

template<int N>
struct scale_name_string_impl 
{
    template<class Begin>
    struct apply 
    {
        static void value(std::string& str) 
        {
            str += mpl::deref<Begin>::type::name();
            scale_name_string_impl<N - 1>::template apply<typename mpl::next<Begin>::type>::value(str);
        }
    };
};

template<>
struct scale_name_string_impl<0>
{
    template<class Begin>
    struct apply 
    {
        static void value(std::string&) { }
    };
};

} // namespace detail

namespace io_impl {

template<class Dimension,class System>
inline std::string
symbol_string(const unit<Dimension,System>&)
{
    return symbol_string(typename reduce_unit<unit<Dimension, System> >::type());
}

template<class Dimension,class System>
inline std::string
name_string(const unit<Dimension,System>&)
{
    return name_string(typename reduce_unit<unit<Dimension, System> >::type());
}

/// INTERNAL ONLY
template<class Dimension,class Units>
inline std::string
symbol_string(const unit<Dimension, heterogeneous_system<heterogeneous_system_impl<Units, Dimension, dimensionless_type> > >&)
{
    std::string str;
    
    detail::symbol_string_impl<mpl::size<Units>::value>::template apply<
        typename mpl::begin<Units>::type>::value(str);

    return(str);
}

/// INTERNAL ONLY
inline std::string
symbol_string(const unit<dimensionless_type, heterogeneous_system<heterogeneous_system_impl<dimensionless_type, dimensionless_type, dimensionless_type> > >&)
{
    return("dimensionless");
}

/// INTERNAL ONLY
template<class Scale>
inline std::string
symbol_string(const unit<dimensionless_type, heterogeneous_system<heterogeneous_system_impl<dimensionless_type, dimensionless_type, Scale> > >&)
{
    std::string str;
    
    detail::scale_symbol_string_impl<mpl::size<Scale>::value>::template apply<
        typename mpl::begin<Scale>::type>::value(str);

    return(str);
}

/// INTERNAL ONLY
template<class Dimension,class Units,class Scale>
inline std::string
symbol_string(const unit<Dimension, heterogeneous_system<heterogeneous_system_impl<Units, Dimension, Scale> > >&)
{
    std::string str;
    
    detail::scale_symbol_string_impl<mpl::size<Scale>::value>::template apply<
        typename mpl::begin<Scale>::type>::value(str);

    std::string without_scale = symbol_string(unit<Dimension, heterogeneous_system<heterogeneous_system_impl<Units, Dimension, dimensionless_type> > >());
    if(without_scale == boost::units::io_impl::symbol_string(unit<Dimension, heterogeneous_system<heterogeneous_system_impl<Units, Dimension, dimensionless_type> > >())) {
        str += "(";
        str += without_scale;
        str += ")";
    } else {
        str += without_scale;
    }

    return(str);
}

/// INTERNAL ONLY
template<class Dimension,class Unit,class Scale>
inline std::string
symbol_string(const unit<Dimension, heterogeneous_system<heterogeneous_system_impl<list<heterogeneous_system_dim<Unit, static_rational<1> >,dimensionless_type>, Dimension, Scale> > >&)
{
    std::string str;
    
    detail::scale_symbol_string_impl<mpl::size<Scale>::value>::template apply<
        typename mpl::begin<Scale>::type>::value(str);

    str += symbol_string(unit<Dimension, heterogeneous_system<heterogeneous_system_impl<list<heterogeneous_system_dim<Unit, static_rational<1> >, dimensionless_type>, Dimension, dimensionless_type> > >());

    return(str);
}

/// INTERNAL ONLY
template<class Dimension,class Unit>
inline std::string
symbol_string(const unit<Dimension, heterogeneous_system<heterogeneous_system_impl<list<heterogeneous_system_dim<Unit, static_rational<1> >,dimensionless_type>, Dimension, dimensionless_type> > >&)
{
    std::string str;
    
    detail::symbol_string_impl<mpl::size<list<heterogeneous_system_dim<Unit, static_rational<1> >,dimensionless_type> >::value>::template apply<
        typename mpl::begin<list<heterogeneous_system_dim<Unit, static_rational<1> >,dimensionless_type> >::type>::value(str);

    return(str);
}

/// INTERNAL ONLY
template<class Dimension,class Unit,class UnitScale, class Scale>
inline std::string
symbol_string(const unit<Dimension, heterogeneous_system<heterogeneous_system_impl<list<heterogeneous_system_dim<scaled_base_unit<Unit, UnitScale>, static_rational<1> >, dimensionless_type>, Dimension, Scale> > >&)
{
    return(symbol_string(
        unit<
            Dimension,
            heterogeneous_system<
                heterogeneous_system_impl<
                    list<heterogeneous_system_dim<Unit, static_rational<1> >, dimensionless_type>,
                    Dimension,
                    typename mpl::times<Scale, list<UnitScale, dimensionless_type> >::type
                >
            >
        >()));
}

/// INTERNAL ONLY
// disambiguate
template<class Dimension,class Unit,class UnitScale>
inline std::string
symbol_string(const unit<Dimension, heterogeneous_system<heterogeneous_system_impl<list<heterogeneous_system_dim<scaled_base_unit<Unit, UnitScale>, static_rational<1> >, dimensionless_type>, Dimension, dimensionless_type> > >&)
{
    std::string str;
    
    detail::symbol_string_impl<mpl::size<list<heterogeneous_system_dim<scaled_base_unit<Unit, UnitScale>, static_rational<1> >, dimensionless_type> >::value>::template apply<
        typename mpl::begin<list<heterogeneous_system_dim<scaled_base_unit<Unit, UnitScale>, static_rational<1> >, dimensionless_type> >::type>::value(str);

    return(str);
}

/// INTERNAL ONLY
template<class Dimension,class Units>
inline std::string
name_string(const unit<Dimension, heterogeneous_system<heterogeneous_system_impl<Units, Dimension, dimensionless_type> > >&)
{
    std::string str;
    
    detail::name_string_impl<mpl::size<Units>::value>::template apply<
        typename mpl::begin<Units>::type>::value(str);

    return(str);
}

/// INTERNAL ONLY
inline std::string
name_string(const unit<dimensionless_type, heterogeneous_system<heterogeneous_system_impl<dimensionless_type, dimensionless_type, dimensionless_type> > >&)
{
    return("dimensionless");
}

/// INTERNAL ONLY
template<class Scale>
inline std::string
name_string(const unit<dimensionless_type, heterogeneous_system<heterogeneous_system_impl<dimensionless_type, dimensionless_type, Scale> > >&)
{
    std::string str;
    
    detail::scale_name_string_impl<mpl::size<Scale>::value>::template apply<
        typename mpl::begin<Scale>::type>::value(str);

    return(str);
}

/// INTERNAL ONLY
template<class Dimension,class Units,class Scale>
inline std::string
name_string(const unit<Dimension, heterogeneous_system<heterogeneous_system_impl<Units, Dimension, Scale> > >&)
{
    std::string str;
    
    detail::scale_name_string_impl<mpl::size<Scale>::value>::template apply<
        typename mpl::begin<Scale>::type>::value(str);

    std::string without_scale = name_string(unit<Dimension, heterogeneous_system<heterogeneous_system_impl<Units, Dimension, dimensionless_type> > >());
    if(without_scale == boost::units::io_impl::name_string(unit<Dimension, heterogeneous_system<heterogeneous_system_impl<Units, Dimension, dimensionless_type> > >())) {
        str += "(";
        str += without_scale;
        str += ")";
    } else {
        str += without_scale;
    }

    return(str);
}

/// INTERNAL ONLY
template<class Dimension,class Unit,class Scale>
inline std::string
name_string(const unit<Dimension, heterogeneous_system<heterogeneous_system_impl<list<heterogeneous_system_dim<Unit, static_rational<1> >,dimensionless_type>, Dimension, Scale> > >&)
{
    std::string str;
    
    detail::scale_name_string_impl<mpl::size<Scale>::value>::template apply<
        typename mpl::begin<Scale>::type>::value(str);

    str += name_string(unit<Dimension, heterogeneous_system<heterogeneous_system_impl<list<heterogeneous_system_dim<Unit, static_rational<1> >, dimensionless_type>, Dimension, dimensionless_type> > >());

    return(str);
}

/// INTERNAL ONLY
template<class Dimension,class Unit>
inline std::string
name_string(const unit<Dimension, heterogeneous_system<heterogeneous_system_impl<list<heterogeneous_system_dim<Unit, static_rational<1> >,dimensionless_type>, Dimension, dimensionless_type> > >&)
{
    std::string str;
    
    detail::name_string_impl<mpl::size<list<heterogeneous_system_dim<Unit, static_rational<1> >,dimensionless_type> >::value>::template apply<
        typename mpl::begin<list<heterogeneous_system_dim<Unit, static_rational<1> >,dimensionless_type> >::type>::value(str);

    return(str);
}

/// INTERNAL ONLY
template<class Dimension,class Unit,class UnitScale, class Scale>
inline std::string
name_string(const unit<Dimension, heterogeneous_system<heterogeneous_system_impl<list<heterogeneous_system_dim<scaled_base_unit<Unit, UnitScale>, static_rational<1> >, dimensionless_type>, Dimension, Scale> > >&)
{
    return(name_string(
        unit<
            Dimension,
            heterogeneous_system<
                heterogeneous_system_impl<
                    list<heterogeneous_system_dim<Unit, static_rational<1> >, dimensionless_type>,
                    Dimension,
                    typename mpl::times<Scale, list<UnitScale, dimensionless_type> >::type
                >
            >
        >()));
}

/// INTERNAL ONLY
// disambiguate
template<class Dimension,class Unit,class UnitScale>
inline std::string
name_string(const unit<Dimension, heterogeneous_system<heterogeneous_system_impl<list<heterogeneous_system_dim<scaled_base_unit<Unit, UnitScale>, static_rational<1> >, dimensionless_type>, Dimension, dimensionless_type> > >&)
{
    std::string str;
    
    detail::name_string_impl<mpl::size<list<heterogeneous_system_dim<scaled_base_unit<Unit, UnitScale>, static_rational<1> >, dimensionless_type> >::value>::template apply<
        typename mpl::begin<list<heterogeneous_system_dim<scaled_base_unit<Unit, UnitScale>, static_rational<1> >, dimensionless_type> >::type>::value(str);
    return(str);
}

template<class Dimension,class System>
inline std::string
name_string(const unit<Dimension, heterogeneous_system<System> >&)
{
    std::string str;
    
    detail::scale_name_string_impl<mpl::size<typename System::scale>::value>::template apply<
        typename mpl::begin<typename System::scale>::type>::value(str);
    detail::name_string_impl<mpl::size<typename System::type>::value>::template apply<
        typename mpl::begin<typename System::type>::type>::value(str);

    return(str);
}

} // namespace io_impl

using io_impl::symbol_string;
using io_impl::name_string;

/// Print an @c unit as a list of base units and exponents e.g "m s^-1"
template<class Char, class Traits, class Dimension, class System>
inline std::basic_ostream<Char, Traits>& operator<<(std::basic_ostream<Char, Traits>& os, const unit<Dimension, System>& u)
{
    if (units::get_format(os) == raw) 
    {
		// need to replace this with raw string
        os << symbol_string(u);
    } 
    else if (units::get_format(os) == symbol) 
    {
        os << symbol_string(u);
    } 
    else if (units::get_format(os) == name) 
    {
        os << name_string(u);
    } 
    else 
    {
        assert(!"The format mode must be either name or symbol");
    }
    
    return(os);
}

/// INTERNAL ONLY
/// Print a @c quantity. Prints the value followed by the unit
template<class Char, class Traits, class Unit, class T>
inline std::basic_ostream<Char, Traits>& operator<<(std::basic_ostream<Char, Traits>& os, const quantity<Unit, T>& q)
{
    os << q.value() << ' ' << Unit();
    return(os);
}

} // namespace units

} // namespace boost

#endif
