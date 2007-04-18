#include <boost/mpl/list.hpp>
#include <boost/mpl/vector.hpp>

#include <boost/units/base_dimension.hpp>
#include <boost/units/derived_dimension.hpp>
#include <boost/units/io.hpp>
#include <boost/units/ordinal.hpp>
#include <boost/units/quantity.hpp>
#include <boost/units/static_constant.hpp>
#include <boost/units/unit.hpp>

struct length_base_dim : boost::units::base_dimension<length_base_dim, 1> { };                        ///> base dimension of length
struct mass_base_dim : boost::units::base_dimension<mass_base_dim,2> { };                             ///> base dimension of mass
struct time_base_dim : boost::units::base_dimension<time_base_dim,3> { };                             ///> base dimension of time
struct current_base_dim : boost::units::base_dimension<current_base_dim,4> { };                       ///> base dimension of current
struct temperature_base_dim : boost::units::base_dimension<temperature_base_dim,5> { };               ///> base dimension of temperature
struct amount_base_dim : boost::units::base_dimension<amount_base_dim,6> { };                         ///> base dimension of amount
struct luminous_intensity_base_dim : boost::units::base_dimension<luminous_intensity_base_dim,7> { }; ///> base dimension of luminous intensity

struct charge_base_dim : boost::units::base_dimension<charge_base_dim,8> { };                         ///> base dimension of charge

struct velocity_base_dim : boost::units::base_dimension<velocity_base_dim,9> { };                     ///> base dimension of velocity
struct action_base_dim : boost::units::base_dimension<action_base_dim,10> { };                        ///> base dimension of action

typedef derived_dimension<length_base_dim,1,time_base_dim,-1>::type     velocity_derived_dim;
typedef derived_dimension<mass_base_dim,1,
                          length_base_dim,-1,
                          time_base_dim,-2>::type                       pressure_derived_dim;

struct meter_base_unit : boost::units::base_unit<length_base_dim,1> { };
struct kilogram_base_unit : boost::units::base_unit<mass_base_dim,2> { };
struct second_base_unit : boost::units::base_unit<time_base_dim,3> { };
struct ampere_base_unit : boost::units::base_unit<current_base_dim,4> { };
struct kelvin_base_unit : boost::units::base_unit<temperature_base_dim,5> { };
struct mole_base_unit : boost::units::base_unit<amount_base_dim,6> { };
struct candela_base_unit : boost::units::base_unit<luminous_intensity_base_dim,7> { };

struct centimeter_base_unit : boost::units::base_unit<length_base_dim,8> { };
struct gram_base_unit : boost::units::base_unit<mass_base_dim,9> { };

struct nu_velocity_base_unit : boost::units::base_unit<velocity_base_dim,10> { };
struct nu_action_base_unit : boost::units::base_unit<action_base_dim,11> { };
struct nu_mass_base_unit : boost::units::base_unit<mass_base_dim,12> { };

struct mmHg_base_unit : boost::units::base_unit<pressure_derived_dim,13> { };

namespace cgs {

typedef make_system<centimeter_base_unit,
                    gram_base_unit,
                    second_base_unit>::type         system;

typedef unit<length_base_dim,system>                length;
typedef unit<mass_base_dim,system>                  mass;
typedef unit<time_base_dim,system>                  time;

typedef unit<velocity_derived_dim,system>           velocity;
typedef unit<pressure_derived_dim,system>           pressure;

} // namespace cgs

namespace mks {

typedef make_system<meter_base_unit,
                    kilogram_base_unit,
                    second_base_unit>::type         system;

typedef unit<length_base_dim,system>                length;
typedef unit<mass_base_dim,system>                  mass;
typedef unit<time_base_dim,system>                  time;

typedef unit<velocity_derived_dim,system>           velocity;
typedef unit<pressure_derived_dim,system>           pressure;

} // namespace mks

namespace si {

typedef make_system<meter_base_unit,
                    kilogram_base_unit,
                    second_base_unit,
                    ampere_base_unit,
                    kelvin_base_unit,
                    mole_base_unit,
                    candela_base_unit>::type        system;
                    
typedef unit<length_base_dim,system>                length;
typedef unit<mass_base_dim,system>                  mass;
typedef unit<time_base_dim,system>                  time;
typedef unit<current_base_dim,system>               current;
typedef unit<temperature_base_dim,system>           temperature;
typedef unit<amount_base_dim,system>                amount;
typedef unit<luminous_intensity_base_dim,system>    luminous_intensity;

typedef unit<velocity_derived_dim,system>           velocity;
typedef unit<pressure_derived_dim,system>           pressure;

} // namespace si

namespace nu {

typedef make_system<nu_velocity_base_unit,
                    nu_action_base_unit,
                    nu_mass_base_unit>::type        system;

typedef unit<velocity_base_dim,system>              velocity;
typedef unit<action_base_dim,system>                action;
typedef unit<mass_base_dim,system>                  mass;

typedef derived_dimension<velocity_base_dim,-2,
                          action_base_dim,1,
                          mass_base_dim,-1>::type   time_derived_dim;

typedef unit<time_derived_dim,system>               time;

} // namespace nu

namespace my_system {

typedef make_system<mmHg_base_unit>::type           system;

typedef unit<pressure_derived_dim,system>           pressure;

}

namespace boost {

namespace units {

template<class Dim,class Sys1,class Sys2> struct base_unit_converter<Dim,Sys1,Sys2>;

// implicit base unit conversion
template<>
struct base_unit_converter<time_base_dim,cgs::system,si::system> :
    public trivial_conversion,
    public trivial_inverse_conversion
{ 
    typedef time_base_dim           converted_dimension_type;
};

// explicit base unit conversion
template<>
struct base_unit_converter<length_base_dim,cgs::system,si::system> :
    public trivial_inverse_conversion
{
    typedef length_base_dim         converted_dimension_type;
    typedef double                  type;

    static type value() { return(.01); }
};

// explicit derived unit conversion
template<>
struct base_unit_converter<pressure_derived_dim,si::system,my_system::system> :
    public trivial_inverse_conversion
{
    typedef pressure_derived_dim    converted_dimension_type;
    typedef double                  type;
    
    static type value()
    {
        return 760.0/1.01325e5;
    }
};

// explicit conversion between two units with different but equivalent dimensions
template<>
struct base_unit_converter<velocity_base_dim,nu::system,si::system>
{
    typedef velocity_derived_dim    converted_dimension_type;
    typedef double                  type;
    
    static type value()
    {
        return 2.998e8;
    }
};

} // namespace units

} // namespace boost

int main()
{
    const quantity<si::pressure>    p(quantity<my_system::pressure>(1.0));
    
    // uses direct unit_converter
    const quantity<si::velocity>    v(quantity<nu::velocity>(1.0));
    const quantity<nu::velocity>    v(quantity<si::velocity>(1.0));
    
    return 0;
}
