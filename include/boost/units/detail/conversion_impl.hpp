// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_CONVERSION_IMPL_HPP
#define BOOST_UNITS_CONVERSION_IMPL_HPP

#include <cmath>

#include <boost/type_traits/is_base_and_derived.hpp>
#include <boost/type_traits/is_same.hpp>

#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/begin.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/next.hpp>
#include <boost/mpl/size.hpp>

#include <boost/units/static_rational.hpp>

namespace boost {

namespace units {

struct one { };

template<class T>
struct multiply_typeof_helper<one, T>
{
    typedef T type;
};

template<class T>
struct multiply_typeof_helper<T, one>
{
    typedef T type;
};

template<>
struct multiply_typeof_helper<one, one>
{
    typedef one type;
};

template<class T>
inline T operator*(const one&, const T& t)
{
    return(t);
}

template<class T>
inline T operator*(const T& t, const one&)
{
    return(t);
}

inline one operator*(const one&, const one&)
{
    return(one());
}

template<class T>
inline T operator/(const T& t, const one&)
{
    return(t);
}

template<class T>
inline T operator/(const one&, const T& t)
{
    return(1/t);
}

inline one operator/(const one&, const one&)
{
    return(one());
}

// tag class to indicate that implicit conversions are allowed
struct implicitly_convertible { };

// tag class to indicate that conversion is trivial
struct trivial_conversion
{
    typedef one type;
    static one value() { return one(); }
};

struct identity_conversion : 
    public trivial_conversion, implicitly_convertible 
{ };

struct trivial_inverse_conversion { };

struct undefined_conversion { };

template<class Converter>
struct reverse_conversion :
    public mpl::if_<is_base_and_derived<implicitly_convertible, Converter>, implicitly_convertible, undefined_conversion>::type 
{
    typedef typename Converter::type type;
    
    static type value() 
    {
        return(one()/Converter::value());
    }
};

template<class Dimension, class Tag1, class Tag2>
struct base_unit_converter :
    public mpl::eval_if<is_same<Tag1, Tag2>,
        mpl::identity<identity_conversion>,
        mpl::if_<
            is_base_and_derived<
                trivial_inverse_conversion,
                base_unit_converter<Dimension,Tag2,Tag1>
            >,
            reverse_conversion<base_unit_converter<Dimension,Tag2,Tag1> >,
            undefined_conversion
        >
    >::type 
{ };

template<class Tag,class System1,class System2>
struct base_unit_is_implicitly_convertible :
    public boost::is_base_and_derived<implicitly_convertible,
                                      base_unit_converter<Tag,System1,System2> >
{ };

namespace detail {

template<class R, class Y>
struct static_rational_power_impl
{
    static Y apply(const Y& y)
    {
        return(std::pow(y, value<Y>(R())));
    }
};

template<integer_type N, bool = (N % 2 == 0)>
struct static_int_power_impl;

template<integer_type N>
struct static_int_power_impl<N, true>
{
    template<class Y, class R>
    static Y apply(const Y& y, const R& r) {
        const Y square = y * y;
        return(static_int_power_impl<(N >> 1)>::apply(square, r));
    }
};

template<integer_type N>
struct static_int_power_impl<N, false>
{
    template<class Y, class R>
    static Y apply(const Y& y, const R& r)
    {
        const Y square = y * y;
        return(static_int_power_impl<(N >> 1)>::apply(square, y * r));
    }
};

template<>
struct static_int_power_impl<1, false>
{
    template<class Y, class R>
    static Y apply(const Y& y, const R& r)
    {
        return(y * r);
    }
};

template<>
struct static_int_power_impl<0, true>
{
    template<class Y, class R>
    static Y apply(const Y&, const R& r)
    {
        return(r);
    }
};

template<int N, bool = (N < 0)>
struct static_int_power_sign_impl;

template<int N>
struct static_int_power_sign_impl<N, false>
{
    template<class Y>
    static Y apply(const Y& y)
    {
        return(static_int_power_impl<N>::apply(y, one()));
    }
};

template<int N>
struct static_int_power_sign_impl<N, true>
{
    template<class Y>
    static Y apply(const Y& y)
    {
        return(one()/static_int_power_impl<-N>::apply(y, one()));
    }
};

template<integer_type N, class Y>
struct static_rational_power_impl<static_rational<N>, Y>
{
    static Y apply(const Y& y)
    {
        return(static_int_power_sign_impl<N>::apply(y));
    }
};

template<class R, class Y>
Y static_rational_power(const Y& y)
{
    return(detail::static_rational_power_impl<R, Y>::apply(y));
}

// convert between homogeneous systems
template<int N>
struct quantity_conversion_homo_to_homo_impl
{
    template<class Begin, class system1_type, class system2_type>
    struct apply
    {
        typedef typename detail::get_tag<typename mpl::deref<Begin>::type>::type        dim_tag_type;
        typedef typename detail::get_value<typename mpl::deref<Begin>::type>::type      value_type;

        typedef typename detail::get_system_tag_of_dim<system1_type,dim_tag_type>::type system1_tag_type;
        typedef typename detail::get_system_tag_of_dim<system2_type,dim_tag_type>::type system2_tag_type;

        typedef base_unit_converter<dim_tag_type,system1_tag_type,system2_tag_type>     buc_t;
        typedef typename mpl::next<Begin>::type                                         next;
        
        typedef typename quantity_conversion_homo_to_homo_impl<N - 1>::template 
            apply<next, system1_type, system2_type>                                     next_iteration;
        
        typedef typename multiply_typeof_helper<typename buc_t::type, 
                                                typename next_iteration::type>::type    type;

        static type value()
        {
            return(
                static_rational_power<value_type>(buc_t::value()) *
                next_iteration::value()
            );
        }
    };
};

template<>
struct quantity_conversion_homo_to_homo_impl<0>
{
    template<class Begin, class system1_type, class system2_type>
    struct apply
    {
        typedef one type;
        static one value()
        {
            return(one());
        }
    };
};

// convert between homogeneous and heterogeneous systems
template<int N>
struct quantity_conversion_homo_to_hetero_impl
{
    template<class Begin, class system1_type>
    struct apply 
    {
        typedef homogeneous_system<typename detail::get_tag<typename mpl::deref<Begin>::type>::type>    system2_type;
        typedef typename detail::get_value<typename mpl::deref<Begin>::type>::type                      value_type;

        typedef typename mpl::next<Begin>::type                                                         next;
        typedef typename mpl::begin<value_type>::type                                                   begin;

        typedef typename quantity_conversion_homo_to_homo_impl<mpl::size<value_type>::value>::template 
            apply<begin, system1_type, system2_type>                                                    convert_system;
        
        typedef typename quantity_conversion_homo_to_hetero_impl<N - 1>::template 
            apply<next, system1_type>                                                                   next_iteration;
        
        typedef typename multiply_typeof_helper<typename convert_system::type, 
                                                typename next_iteration::type>::type                    type;

        static type value()
        {
            return(
                convert_system::value() *
                next_iteration::value()
            );
        }
    };
};

template<>
struct quantity_conversion_homo_to_hetero_impl<0>
{
    template<class Begin, class system2_type>
    struct apply
    {
        typedef one type;
        static one value()
        {
            return(one());
        }
    };
};

// convert between heterogeneous and homogeneous systems
template<int N>
struct quantity_conversion_hetero_to_homo_impl
{
    template<class Begin, class system2_type>
    struct apply
    {
        typedef homogeneous_system<typename detail::get_tag<typename mpl::deref<Begin>::type>::type>    system1_type;
        typedef typename detail::get_value<typename mpl::deref<Begin>::type>::type                      value_type;

        typedef typename mpl::next<Begin>::type next;
        typedef typename mpl::begin<value_type>::type begin;

        typedef typename quantity_conversion_homo_to_homo_impl<mpl::size<value_type>::value>::template 
            apply<begin, system1_type, system2_type>                                                    convert_system;
        
        typedef typename quantity_conversion_hetero_to_homo_impl<N - 1>::template 
            apply<next, system2_type>                                                                   next_iteration;
        
        typedef typename multiply_typeof_helper<typename convert_system::type, 
                                                typename next_iteration::type>::type                    type;

        static type value()
        {
            return(
                convert_system::value() *
                next_iteration::value()
            );
        }
    };
};

template<>
struct quantity_conversion_hetero_to_homo_impl<0>
{
    template<class Begin, class system1_type>
    struct apply
    {
        typedef one type;
        static one value()
        {
            return(one());
        }
    };
};

struct heterogeneous_system_by_dimension_dim_tag {};

// the hardest case: heterogeneous->heterogeneous
template<class Tag, class Value>
struct heterogeneous_system_by_dimension_dim
{
    typedef heterogeneous_system_by_dimension_dim type;
    typedef heterogeneous_system_by_dimension_dim_tag tag;
    typedef Tag tag_type;
    typedef Value value_type;
};

template<class T1, class V1, class T2, class V2>
struct less<heterogeneous_system_by_dimension_dim<T1, V1>, heterogeneous_system_by_dimension_dim<T2, V2> >
    : mpl::less<T1, T2>
{ };

template<class Tag, class L>
struct is_empty_dim<heterogeneous_system_by_dimension_dim<Tag, L> > :
    boost::mpl::false_ 
{ };

template<class Tag>
struct is_empty_dim<heterogeneous_system_by_dimension_dim<Tag, dimensionless_type> > :
    boost::mpl::true_ 
{ };

} // namespace detail

} // namespace units

namespace mpl {

template<>
struct plus_impl<
    boost::units::detail::heterogeneous_system_by_dimension_dim_tag,
    boost::units::detail::heterogeneous_system_by_dimension_dim_tag
>
{
    template<class T0, class T1>
    struct apply {
        BOOST_STATIC_ASSERT((boost::is_same<typename T0::tag_type, typename T1::tag_type>::value == true));
        typedef boost::units::detail::heterogeneous_system_by_dimension_dim<
            typename T0::tag_type,
            typename boost::units::detail::merge_dimensions<
                typename T0::value_type,
                typename T1::value_type
            >::type
        > type;
    };
};

template<>
struct negate_impl<boost::units::detail::heterogeneous_system_by_dimension_dim_tag>
{
    template<class T0>
    struct apply {
        typedef typename boost::units::detail::static_inverse_impl<mpl::size<typename T0::value_type>::value>::template apply<
            typename mpl::begin<typename T0::value_type>::type
        >::type inverse;
        typedef boost::units::detail::heterogeneous_system_by_dimension_dim<typename T0::tag_type, inverse> type;
    };
};

} // namespace mpl

namespace units {

namespace detail {

struct heterogeneous_system_by_dimension_value_tag {};

template<class SystemTag, class Value>
struct heterogeneous_system_by_dimension_value
{
    typedef heterogeneous_system_by_dimension_value type;
    typedef heterogeneous_system_by_dimension_value_tag tag;
    typedef SystemTag tag_type;
    typedef Value value_type;
};

template<class T1, class V1, class T2, class V2>
struct less<heterogeneous_system_by_dimension_value<T1, V1>, heterogeneous_system_by_dimension_value<T2, V2> >
    : mpl::less<T1, T2>
{ };

template<class Tag, class L>
struct is_empty_dim<heterogeneous_system_by_dimension_value<Tag, L> > :
    boost::mpl::false_ 
{ };

template<class Tag>
struct is_empty_dim<heterogeneous_system_by_dimension_value<Tag, dimensionless_type> > :
    boost::mpl::true_ 
{ };

} // namespace detail

} // namespace units

namespace mpl {

template<>
struct plus_impl<
    boost::units::detail::heterogeneous_system_by_dimension_value_tag,
    boost::units::detail::heterogeneous_system_by_dimension_value_tag
>
{
    template<class T0, class T1>
    struct apply {
        BOOST_STATIC_ASSERT((boost::is_same<typename T0::tag_type, typename T1::tag_type>::value == true));
        typedef boost::units::detail::heterogeneous_system_by_dimension_value<
            typename T0::tag_type,
            typename plus<typename T0::value_type, typename T1::value_type>::type
        > type;
    };
};

template<>
struct negate_impl<boost::units::detail::heterogeneous_system_by_dimension_value_tag>
{
    template<class T0>
    struct apply {
        typedef boost::units::detail::heterogeneous_system_by_dimension_value<typename T0::tag_type, typename negate<typename T0::value_type>::type> type;
    };
};

} // namespace mpl

namespace units {

namespace detail {

template<int N>
struct convert_dimension_to_system_dimension_pairs_impl
{
    template<class Begin, class System>
    struct apply
    {
        typedef typename mpl::deref<Begin>::type dim;
        typedef typename mpl::push_front<
            typename convert_dimension_to_system_dimension_pairs_impl<N-1>::template 
                apply<typename mpl::next<Begin>::type, System>::type,
            heterogeneous_system_by_dimension_dim<
                typename dim::tag_type,
                typename mpl::push_front<dimensionless_type, heterogeneous_system_by_dimension_value<System, typename dim::value_type> >::type
            >
        >::type type;
    };
};
template<>
struct convert_dimension_to_system_dimension_pairs_impl<0>
{
    template<class Begin, class System>
    struct apply
    {
        typedef dimensionless_type type;
    };
};

template<int N>
struct sort_heterogeneous_system_by_dimension_tag_impl
{
    template<class Begin>
    struct apply
    {
        typedef typename mpl::deref<Begin>::type element;
        typedef typename convert_dimension_to_system_dimension_pairs_impl<mpl::size<typename element::value_type>::value>::template apply<
            typename mpl::begin<typename element::value_type>::type,
            typename element::tag_type
        >::type converted;
        typedef typename detail::merge_dimensions<
            converted,
            typename sort_heterogeneous_system_by_dimension_tag_impl<N - 1>::template apply<typename mpl::next<Begin>::type>::type
        >::type type;
    };
};

template<>
struct sort_heterogeneous_system_by_dimension_tag_impl<0>
{
    template<class Begin>
    struct apply
    {
        typedef dimensionless_type type;
    };
};

template<class System>
struct sort_heterogeneous_system_by_dimension_tag
{
    typedef typename sort_heterogeneous_system_by_dimension_tag_impl<mpl::size<System>::value>::template apply<typename mpl::begin<System>::type>::type type;
};

//one->many
template<int N>
struct fundamental_dimension_convert_homo_to_hetero_impl
{
    template<class Begin, class Tag, class system1_type>
    struct apply
    {
        typedef typename detail::get_tag<typename mpl::deref<Begin>::type>::type                        system2_type;
        typedef typename detail::get_value<typename mpl::deref<Begin>::type>::type                      value_type;

        typedef typename mpl::next<Begin>::type                                                         next;
        typedef typename mpl::begin<value_type>::type                                                   begin;

        typedef base_unit_converter<Tag, system1_type, system2_type>                                    converter;
        
        typedef typename fundamental_dimension_convert_homo_to_hetero_impl<N - 1>::template 
            apply<next, Tag, system1_type>                                                             next_iteration;
        
        typedef typename multiply_typeof_helper<typename converter::type, 
                                                typename next_iteration::type>::type                   type;

        static type value()
        {
            return (static_rational_power<value_type>(converter::value())*next_iteration::value());
        }
    };
};

template<>
struct fundamental_dimension_convert_homo_to_hetero_impl<0>
{
    template<class Begin, class Tag, class system1_type>
    struct apply
    {
        typedef one type;
        static one value()
        {
            return(one());
        }
    };
};

//many->one
template<int N>
struct fundamental_dimension_convert_hetero_to_homo_impl
{
    template<class Begin, class Tag, class system2_type>
    struct apply
    {
        typedef typename detail::get_tag<typename mpl::deref<Begin>::type>::type    system1_type;
        typedef typename detail::get_value<typename mpl::deref<Begin>::type>::type                      value_type;

        typedef typename mpl::next<Begin>::type next;
        typedef typename mpl::begin<value_type>::type begin;

        typedef base_unit_converter<Tag, system1_type, system2_type> converter;
        
        typedef typename fundamental_dimension_convert_hetero_to_homo_impl<N - 1>::template 
            apply<next, Tag, system2_type>                                                             next_iteration;
        
        typedef typename multiply_typeof_helper<typename converter::type, 
                                                typename next_iteration::type>::type                    type;

        static type value()
        {
            return(
                static_rational_power<value_type>(converter::value()) *
                next_iteration::value()
            );
        }
    };
};

template<>
struct fundamental_dimension_convert_hetero_to_homo_impl<0>
{
    template<class Begin, class Tag, class system2_type>
    struct apply
    {
        typedef one type;
        static one value()
        {
            return(one());
        }
    };
};

template<int N1, int N2>
struct quantity_conversion_hetero_to_hetero_impl_func;

template<int N2>
struct quantity_conversion_hetero_to_hetero_impl_func<1, N2>
{
    template<class Dim1, class Dim2>
    struct apply
    {
        typedef typename fundamental_dimension_convert_homo_to_hetero_impl<N2>::template apply<
            typename mpl::begin<typename Dim2::value_type>::type,
            typename Dim1::tag_type,
            typename mpl::front<typename Dim1::value_type>::type::tag_type
        > type;
    };
};
template<int N1>
struct quantity_conversion_hetero_to_hetero_impl_func<N1, 1>
{
    template<class Dim1, class Dim2>
    struct apply
    {
        typedef typename fundamental_dimension_convert_hetero_to_homo_impl<N1>::template apply<
            typename mpl::begin<typename Dim1::value_type>::type,
            typename Dim1::tag_type,
            typename mpl::front<typename Dim2::value_type>::type::tag_type
        > type;
    };
};
template<>
struct quantity_conversion_hetero_to_hetero_impl_func<1, 1>
{
    template<class Dim1, class Dim2>
    struct apply
    {
        struct type_xxx : 
            base_unit_converter<
                typename Dim1::tag_type,
                typename mpl::front<typename Dim1::value_type>::type::tag_type,
                typename mpl::front<typename Dim2::value_type>::type::tag_type
            >
        {
        };
        typedef type_xxx type;
    };
};

template<int N1, int N2>
struct quantity_conversion_hetero_to_hetero_impl;

template<bool less, bool greater>
struct quantity_conversion_hetero_to_hetero_impl_compare_test;

// both systems contain this dimension
template<>
struct quantity_conversion_hetero_to_hetero_impl_compare_test<false, false> {
    template<class Begin1, class Begin2, int N1, int N2>
    struct apply {
        typedef homogeneous_system<typename detail::get_tag<typename mpl::deref<Begin1>::type>::type> dim_type;

        typedef typename detail::get_value<typename mpl::deref<Begin1>::type>::type                   value_type1;
        typedef typename detail::get_value<typename mpl::deref<Begin2>::type>::type                   value_type2;

        typedef typename mpl::next<Begin1>::type next1;
        typedef typename mpl::next<Begin2>::type next2;
        
        typedef typename quantity_conversion_hetero_to_hetero_impl_func<
            mpl::size<value_type1>::value,
            mpl::size<value_type2>::value
        >::template apply<typename mpl::deref<Begin1>::type,typename mpl::deref<Begin2>::type>::type converter;

        typedef typename quantity_conversion_hetero_to_hetero_impl<N2 - 1, N2 - 1>::template apply<next1, next2> next_iteration;
        
        typedef typename multiply_typeof_helper<typename converter::type, 
                                                typename next_iteration::type>::type                    type;

        static type value()
        {
            return(
                converter::value() *
                next_iteration::value()
            );
        }
    };
};

// only the source contains the current fundamental dimension
template<>
struct quantity_conversion_hetero_to_hetero_impl_compare_test<true, false> {
    template<class Begin1, class Begin2, int N1, int N2>
    struct apply {
        typedef typename detail::get_tag<typename mpl::deref<Begin1>::type>::type dim_type;

        typedef typename detail::get_value<typename mpl::deref<Begin1>::type>::type                   value_type1;

        // we are going to arbitrarily decide to convert everything to the
        // system with the lowest ordinal
        typedef typename get_tag<typename mpl::front<value_type1>::type>::type result_system_type;

        typedef typename mpl::next<Begin1>::type next1;
        typedef Begin2 next2;
        
        typedef typename fundamental_dimension_convert_hetero_to_homo_impl<
            mpl::size<value_type1>::value
        >::template apply<typename mpl::begin<value_type1>::type,dim_type,result_system_type> converter;

        typedef typename quantity_conversion_hetero_to_hetero_impl<N1 - 1, N2>::template apply<next1, next2> next_iteration;
        
        typedef typename multiply_typeof_helper<typename converter::type, 
                                                typename next_iteration::type>::type                    type;

        static type value()
        {
            return(
                converter::value() *
                next_iteration::value()
            );
        }
    };
};

// only the destination contains the current fundamental dimension
template<>
struct quantity_conversion_hetero_to_hetero_impl_compare_test<false, true> {
    template<class Begin1, class Begin2, int N1, int N2>
    struct apply {
        typedef typename detail::get_tag<typename mpl::deref<Begin2>::type>::type dim_type;

        typedef typename detail::get_value<typename mpl::deref<Begin2>::type>::type  value_type2;

        // we are going to arbitrarily decide to convert everything to the
        // system with the lowest ordinal
        typedef typename get_tag<typename mpl::front<value_type2>::type>::type source_system_type;

        typedef Begin1 next1;
        typedef typename mpl::next<Begin2>::type next2;
        
        typedef typename fundamental_dimension_convert_homo_to_hetero_impl<
            mpl::size<value_type2>::value
        >::template apply<typename mpl::begin<value_type2>::type,dim_type,source_system_type> converter;

        typedef typename quantity_conversion_hetero_to_hetero_impl<N1, N2 - 1>::template apply<next1, next2> next_iteration;
        
        typedef typename multiply_typeof_helper<typename converter::type, 
                                                typename next_iteration::type>::type                    type;

        static type value()
        {
            return(
                converter::value() *
                next_iteration::value()
            );
        }
    };
};

template<int N1, int N2>
struct quantity_conversion_hetero_to_hetero_impl
{
    template<class Begin1, class Begin2>
    struct apply :
        quantity_conversion_hetero_to_hetero_impl_compare_test<
            less<typename mpl::deref<Begin1>::type, typename mpl::deref<Begin2>::type>::value,
            less<typename mpl::deref<Begin2>::type, typename mpl::deref<Begin1>::type>::value
        >::template apply<Begin1, Begin2, N1, N2>
    {};
};

template<int N2>
struct quantity_conversion_hetero_to_hetero_impl<0, N2>
{
    template<class Begin1, class Begin2>
    struct apply :
        quantity_conversion_hetero_to_hetero_impl_compare_test<
            false, true
        >::template apply<Begin1, Begin2, 0, N2>
    {};
};

template<int N1>
struct quantity_conversion_hetero_to_hetero_impl<N1, 0>
{
    template<class Begin1, class Begin2>
    struct apply :
        quantity_conversion_hetero_to_hetero_impl_compare_test<
            true, false
        >::template apply<Begin1, Begin2, N1, 0>
    {};
};

template<>
struct quantity_conversion_hetero_to_hetero_impl<0, 0>
{
    template<class Begin1, class Begin2>
    struct apply
    {
        typedef one type;
        static one value()
        {
            return(one());
        }
    };
};

template<class System1, class System2>
struct quantity_conversion_hetero_to_hetero
{
    typedef typename sort_heterogeneous_system_by_dimension_tag<System1>::type S1;
    typedef typename sort_heterogeneous_system_by_dimension_tag<System2>::type S2;
    typedef typename quantity_conversion_hetero_to_hetero_impl<
        mpl::size<S1>::value,
        mpl::size<S2>::value
    >::template apply<
        typename mpl::begin<S1>::type,
        typename mpl::begin<S2>::type
    > converter;
    typedef typename converter::type type;
    static type value() 
    {
        return(converter::value());
    }
};

} // namespace detail

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_CONVERSION_IMPL_HPP
