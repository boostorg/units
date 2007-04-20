// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_CODATA_ATOMIC_AND_NUCLEAR_CONSTANTS_HPP
#define BOOST_UNITS_CODATA_ATOMIC_AND_NUCLEAR_CONSTANTS_HPP

#include <boost/units/static_constant.hpp>

#include <boost/units/systems/si/constants.hpp>
#include <boost/units/systems/si/amount.hpp>
#include <boost/units/systems/si/area.hpp>
#include <boost/units/systems/si/electric_charge.hpp>
#include <boost/units/systems/si/energy.hpp>
#include <boost/units/systems/si/frequency.hpp>
#include <boost/units/systems/si/length.hpp>
#include <boost/units/systems/si/mass.hpp>
#include <boost/units/systems/si/magnetic_flux_density.hpp>
#include <boost/units/systems/si/time.hpp>
#include <boost/units/systems/si/wavenumber.hpp>

#include <boost/units/systems/si/codata/typedefs.hpp>

/// \file
/// CODATA recommended values of fundamental atomic and nuclear constants
/// CODATA 2006 values as of 2007/03/30

namespace boost {

namespace units { 

namespace SI {
                            
namespace constants {

namespace CODATA {

/// CODATA recommended values of the fundamental physical constants: NIST SP 961

// ATOMIC AND NUCLEAR
/// fine structure constant
BOOST_UNITS_PHYSICAL_CONSTANT(alpha,quantity<dimensionless>,7.2973525376e-3*dimensionless(),5.0e-12*dimensionless());
/// Rydberg constant
BOOST_UNITS_PHYSICAL_CONSTANT(R_infinity,quantity<wavenumber>,10973731.568527/meter,7.3e-5/meter);
/// Bohr radius
BOOST_UNITS_PHYSICAL_CONSTANT(a_0,quantity<length>,0.52917720859e-10*meters,3.6e-20*meters);
/// Hartree energy
BOOST_UNITS_PHYSICAL_CONSTANT(E_h,quantity<energy>,4.35974394e-18*joules,2.2e-25*joules);

/// electron mass
BOOST_UNITS_PHYSICAL_CONSTANT(m_e,quantity<mass>,9.10938215e-31*kilograms,4.5e-38*kilograms);
/// electron-muon mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_e_over_m_mu,quantity<dimensionless>,4.83633171e-3*dimensionless(),1.2e-10*dimensionless());
/// electron-tau mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_e_over_m_tau,quantity<dimensionless>,2.87564e-4*dimensionless(),4.7e-8*dimensionless());
/// electron-proton mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_e_over_m_p,quantity<dimensionless>,5.4461702177e-4*dimensionless(),2.4e-13*dimensionless());
/// electron-neutron mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_e_over_m_n,quantity<dimensionless>,5.4386734459e-4*dimensionless(),3.3e-13*dimensionless());
/// electron-deuteron mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_e_over_m_d,quantity<dimensionless>,2.7244371093e-4*dimensionless(),1.2e-13*dimensionless());
/// electron-alpha particle mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_e_over_m_alpha,quantity<dimensionless>,1.37093355570e-4*dimensionless(),5.8e-14*dimensionless());
/// electron charge to mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(e_over_m_e,quantity<electric_charge_over_mass>,1.758820150e11*coulombs/kilogram,4.4e3*coulombs/kilogram);
/// electron molar mass
BOOST_UNITS_PHYSICAL_CONSTANT(M_e,quantity<mass_over_amount>,5.4857990943e-7*kilograms/mole,2.3e-16*kilograms/mole);
/// Compton wavelength
BOOST_UNITS_PHYSICAL_CONSTANT(lambda_C,quantity<length>,2.4263102175e-12*meters,3.3e-21*meters);
/// classical electron radius
BOOST_UNITS_PHYSICAL_CONSTANT(r_e,quantity<length>,2.8179402894e-15*meters,5.8e-24*meters);
/// Thompson cross section
BOOST_UNITS_PHYSICAL_CONSTANT(sigma_e,quantity<area>,0.6652458558e-28*square_meters,2.7e-37*square_meters);
/// electron magnetic moment
BOOST_UNITS_PHYSICAL_CONSTANT(mu_e,quantity<energy_over_magnetic_flux_density>,-928.476377e-26*joules/tesla,2.3e-31*joules/tesla);
/// electron-Bohr magenton moment ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_e_over_mu_B,quantity<dimensionless>,-1.00115965218111*dimensionless(),7.4e-13*dimensionless());
/// electron-nuclear magneton moment ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_e_over_mu_N,quantity<dimensionless>,-183.28197092*dimensionless(),8.0e-7*dimensionless());
/// electron magnetic moment anomaly
BOOST_UNITS_PHYSICAL_CONSTANT(a_e,quantity<dimensionless>,1.15965218111e-3*dimensionless(),7.4e-13*dimensionless());
/// electron g-factor
BOOST_UNITS_PHYSICAL_CONSTANT(g_e,quantity<dimensionless>,-2.0023193043622*dimensionless(),1.5e-12*dimensionless());
/// electron-muon magnetic moment ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_e_over_mu_mu,quantity<dimensionless>,206.7669877*dimensionless(),5.2e-6*dimensionless());
/// electron-proton magnetic moment ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_e_over_mu_p,quantity<dimensionless>,-658.2106848*dimensionless(),5.4e-6*dimensionless());
/// electron-shielded proton magnetic moment ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_e_over_mu_p_prime,quantity<dimensionless>,-658.2275971*dimensionless(),7.2e-6*dimensionless());
/// electron-neutron magnetic moment ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_e_over_mu_n,quantity<dimensionless>,960.92050*dimensionless(),2.3e-4*dimensionless());
/// electron-deuteron magnetic moment ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_e_over_mu_d,quantity<dimensionless>,-2143.923498*dimensionless(),1.8e-5*dimensionless());
/// electron-shielded helion magnetic moment ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_e_over_mu_h_prime,quantity<dimensionless>,864.058257*dimensionless(),1.0e-5*dimensionless());
/// electron gyromagnetic ratio
BOOST_UNITS_PHYSICAL_CONSTANT(gamma_e,quantity<frequency_over_magnetic_flux_density>,1.760859770e11/second/tesla,4.4e3/second/tesla);

/// muon mass
BOOST_UNITS_PHYSICAL_CONSTANT(m_mu,quantity<mass>,1.88353130e-28*kilograms,1.1e-35*kilograms);
/// muon-electron mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_mu_over_m_e,quantity<dimensionless>,206.7682823*dimensionless(),5.2e-6*dimensionless());
/// muon-tau mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_mu_over_m_tau,quantity<dimensionless>,5.94592e-2*dimensionless(),9.7e-6*dimensionless());
/// muon-proton mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_mu_over_m_p,quantity<dimensionless>,0.1126095261*dimensionless(),2.9e-9*dimensionless());
/// muon-neutron mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_mu_over_m_n,quantity<dimensionless>,0.1124545167*dimensionless(),2.9e-9*dimensionless());
/// muon molar mass
BOOST_UNITS_PHYSICAL_CONSTANT(M_mu,quantity<mass_over_amount>,0.1134289256e-3*kilograms/mole,2.9e-12*kilograms/mole);
/// muon Compton wavelength
BOOST_UNITS_PHYSICAL_CONSTANT(lambda_C_mu,quantity<length>,11.73444104e-15*meters,3.0e-22*meters);
/// muon magnetic moment
BOOST_UNITS_PHYSICAL_CONSTANT(mu_mu,quantity<energy_over_magnetic_flux_density>,-4.49044786e-26*joules/tesla,1.6e-33*joules/tesla);
/// muon-Bohr magneton ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_mu_over_mu_B,quantity<dimensionless>,-4.84197049e-3*dimensionless(),1.2e-10*dimensionless());
/// muon-nuclear magneton ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_mu_over_mu_N,quantity<dimensionless>,-8.89059705*dimensionless(),2.3e-7*dimensionless());
/// muon magnetic moment anomaly
BOOST_UNITS_PHYSICAL_CONSTANT(a_mu,quantity<dimensionless>,1.16592069e-3*dimensionless(),6.0e-10*dimensionless());
/// muon g-factor
BOOST_UNITS_PHYSICAL_CONSTANT(g_mu,quantity<dimensionless>,-2.0023318414*dimensionless(),1.2e-9*dimensionless());
/// muon-proton magnetic moment ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_mu_over_mu_p,quantity<dimensionless>,-3.183345137*dimensionless(),8.5e-8*dimensionless());

/// tau mass
BOOST_UNITS_PHYSICAL_CONSTANT(m_tau,quantity<mass>,3.16777e-27*kilograms,5.2e-31*kilograms);
/// tau-electron mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_tau_over_m_e,quantity<dimensionless>,3477.48*dimensionless(),5.7e-1*dimensionless());
/// tau-muon mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_tau_over_m_mu,quantity<dimensionless>,16.8183*dimensionless(),2.7e-3*dimensionless());
/// tau-proton mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_tau_over_m_p,quantity<dimensionless>,1.89390*dimensionless(),3.1e-4*dimensionless());
/// tau-neutron mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_tau_over_m_n,quantity<dimensionless>,1.89129*dimensionless(),3.1e-4*dimensionless());
/// tau molar mass
BOOST_UNITS_PHYSICAL_CONSTANT(M_tau,quantity<mass_over_amount>,1.90768e-3*kilograms/mole,3.1e-7*kilograms/mole);
/// tau Compton wavelength
BOOST_UNITS_PHYSICAL_CONSTANT(lambda_C_tau,quantity<length>,0.69772e-15*meters,1.1e-19*meters);

/// proton mass
BOOST_UNITS_PHYSICAL_CONSTANT(m_p,quantity<mass>,1.672621637e-27*kilograms,8.3e-35*kilograms);
/// proton-electron mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_p_over_m_e,quantity<dimensionless>,1836.15267247*dimensionless(),8.0e-7*dimensionless());
/// proton-muon mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_p_over_m_mu,quantity<dimensionless>,8.88024339*dimensionless(),2.3e-7*dimensionless());
/// proton-tau mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_p_over_m_tau,quantity<dimensionless>,0.528012*dimensionless(),8.6e-5*dimensionless());
/// proton-neutron mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_p_over_m_n,quantity<dimensionless>,0.99862347824*dimensionless(),4.6e-10*dimensionless());
/// proton charge to mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(e_over_m_p,quantity<electric_charge_over_mass>,9.57883392e7*coulombs/kilogram,2.4e0*coulombs/kilogram);
/// proton molar mass
BOOST_UNITS_PHYSICAL_CONSTANT(M_p,quantity<mass_over_amount>,1.00727646677e-3*kilograms/mole,1.0e-13*kilograms/mole);
/// proton Compton wavelength
BOOST_UNITS_PHYSICAL_CONSTANT(lambda_C_p,quantity<length>,1.3214098446e-15*meters,1.9e-24*meters);
/// proton rms charge radius
BOOST_UNITS_PHYSICAL_CONSTANT(R_p,quantity<length>,0.8768e-15*meters,6.9e-18*meters);
/// proton magnetic moment
BOOST_UNITS_PHYSICAL_CONSTANT(mu_p,quantity<energy_over_magnetic_flux_density>,1.410606662e-26*joules/tesla,3.7e-34*joules/tesla);
/// proton-Bohr magneton ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_p_over_mu_B,quantity<dimensionless>,1.521032209e-3*dimensionless(),1.2e-11*dimensionless());
/// proton-nuclear magneton ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_p_over_mu_N,quantity<dimensionless>,2.792847356*dimensionless(),2.3e-8*dimensionless());
/// proton g-factor
BOOST_UNITS_PHYSICAL_CONSTANT(g_p,quantity<dimensionless>,5.585694713*dimensionless(),4.6e-8*dimensionless());
/// proton-neutron magnetic moment ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_p_over_mu_n,quantity<dimensionless>,-1.45989806*dimensionless(),3.4e-7*dimensionless());
/// shielded proton magnetic moment
BOOST_UNITS_PHYSICAL_CONSTANT(mu_p_prime,quantity<energy_over_magnetic_flux_density>,1.410570419e-26*joules/tesla,3.8e-34*joules/tesla);
/// shielded proton-Bohr magneton ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_p_prime_over_mu_B,quantity<dimensionless>,1.520993128e-3*dimensionless(),1.7e-11*dimensionless());
/// shielded proton-nuclear magneton ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_p_prime_over_mu_N,quantity<dimensionless>,2.792775598*dimensionless(),3.0e-8*dimensionless());
/// proton magnetic shielding correction
BOOST_UNITS_PHYSICAL_CONSTANT(sigma_p_prime,quantity<dimensionless>,25.694e-6*dimensionless(),1.4e-8*dimensionless());
/// proton gyromagnetic ratio
BOOST_UNITS_PHYSICAL_CONSTANT(gamma_p,quantity<frequency_over_magnetic_flux_density>,2.675222099e8/second/tesla,7.0e0/second/tesla);
/// shielded proton gyromagnetic ratio
BOOST_UNITS_PHYSICAL_CONSTANT(gamma_p_prime,quantity<frequency_over_magnetic_flux_density>,2.675153362e8/second/tesla,7.3e0/second/tesla);

/// neutron mass
BOOST_UNITS_PHYSICAL_CONSTANT(m_n,quantity<mass>,1.674927211e-27*kilograms,8.4e-35*kilograms);
/// neutron-electron mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_n_over_m_e,quantity<dimensionless>,1838.6836605*dimensionless(),1.1e-6*dimensionless());
/// neutron-muon mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_n_over_m_mu,quantity<dimensionless>,8.89248409*dimensionless(),2.3e-7*dimensionless());
/// neutron-tau mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_n_over_m_tau,quantity<dimensionless>,0.528740*dimensionless(),8.6e-5*dimensionless());
/// neutron-proton mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_n_over_m_p,quantity<dimensionless>,1.00137841918*dimensionless(),4.6e-10*dimensionless());
/// neutron molar mass
BOOST_UNITS_PHYSICAL_CONSTANT(M_n,quantity<mass_over_amount>,1.00866491597e-3*kilograms/mole,4.3e-13*kilograms/mole);
/// neutron Compton wavelength
BOOST_UNITS_PHYSICAL_CONSTANT(lambda_C_n,quantity<length>,1.3195908951e-15*meters,2.0e-24*meters);
/// neutron magnetic moment
BOOST_UNITS_PHYSICAL_CONSTANT(mu_n,quantity<energy_over_magnetic_flux_density>,-0.96623641e-26*joules/tesla,2.3e-33*joules/tesla);
/// neutron g-factor
BOOST_UNITS_PHYSICAL_CONSTANT(g_n,quantity<dimensionless>,-3.82608545*dimensionless(),9.0e-7*dimensionless());
/// neutron-electron magnetic moment ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_n_over_mu_e,quantity<dimensionless>,1.04066882e-3*dimensionless(),2.5e-10*dimensionless());
/// neutron-proton magnetic moment ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_n_over_mu_p,quantity<dimensionless>,-0.68497934*dimensionless(),1.6e-7*dimensionless());
/// neutron-shielded proton magnetic moment ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_n_over_mu_p_prime,quantity<dimensionless>,-0.68499694*dimensionless(),1.6e-7*dimensionless());
/// neutron gyromagnetic ratio
BOOST_UNITS_PHYSICAL_CONSTANT(gamma_n,quantity<frequency_over_magnetic_flux_density>,1.83247185e8/second/tesla,4.3e1/second/tesla);

/// deuteron mass
BOOST_UNITS_PHYSICAL_CONSTANT(m_d,quantity<mass>,3.34358320e-27*kilograms,1.7e-34*kilograms);
/// deuteron-electron mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_d_over_m_e,quantity<dimensionless>,3670.4829654*dimensionless(),1.6e-6*dimensionless());
/// deuteron-proton mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_d_over_m_p,quantity<dimensionless>,1.99900750108*dimensionless(),2.2e-10*dimensionless());
/// deuteron molar mass
BOOST_UNITS_PHYSICAL_CONSTANT(M_d,quantity<mass_over_amount>,2.013553212724e-3*kilograms/mole,7.8e-14*kilograms/mole);
/// deuteron rms charge radius
BOOST_UNITS_PHYSICAL_CONSTANT(R_d,quantity<length>,2.1402e-15*meters,2.8e-18*meters);
/// deuteron magnetic moment
BOOST_UNITS_PHYSICAL_CONSTANT(mu_d,quantity<energy_over_magnetic_flux_density>,0.433073465e-26*joules/tesla,1.1e-34*joules/tesla);
/// deuteron-Bohr magneton ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_d_over_mu_B,quantity<dimensionless>,0.4669754556e-3*dimensionless(),3.9e-12*dimensionless());
/// deuteron-nuclear magneton ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_d_over_mu_N,quantity<dimensionless>,0.8574382308*dimensionless(),7.2e-9*dimensionless());
/// deuteron g-factor
BOOST_UNITS_PHYSICAL_CONSTANT(g_d,quantity<dimensionless>,0.8574382308*dimensionless(),7.2e-9*dimensionless());
/// deuteron-electron magnetic moment ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_d_over_mu_e,quantity<dimensionless>,-4.664345537e-4*dimensionless(),3.9e-12*dimensionless());
/// deuteron-proton magnetic moment ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_d_over_mu_p,quantity<dimensionless>,0.3070122070*dimensionless(),2.4e-9*dimensionless());
/// deuteron-neutron magnetic moment ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_d_over_mu_n,quantity<dimensionless>,-0.44820652*dimensionless(),1.1e-7*dimensionless());

/// triton mass
BOOST_UNITS_PHYSICAL_CONSTANT(m_t,quantity<mass>,5.00735588e-27*kilograms,2.5e-34*kilograms);
/// triton-electron mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_t_over_m_e,quantity<dimensionless>,5496.9215269*dimensionless(),5.1e-6*dimensionless());
/// triton-proton mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_t_over_m_p,quantity<dimensionless>,2.9937170309*dimensionless(),2.5e-9*dimensionless());
/// triton molar mass
BOOST_UNITS_PHYSICAL_CONSTANT(M_t,quantity<mass_over_amount>,3.0155007134e-3*kilograms/mole,2.5e-12*kilograms/mole);
/// triton magnetic moment
BOOST_UNITS_PHYSICAL_CONSTANT(mu_t,quantity<energy_over_magnetic_flux_density>,1.504609361e-26*joules/tesla,4.2e-34*joules/tesla);
/// triton-Bohr magneton ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_t_over_mu_B,quantity<dimensionless>,1.622393657e-3*dimensionless(),2.1e-11*dimensionless());
/// triton-nuclear magneton ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_t_over_mu_N,quantity<dimensionless>,2.978962448*dimensionless(),3.8e-8*dimensionless());
/// triton g-factor
BOOST_UNITS_PHYSICAL_CONSTANT(g_t,quantity<dimensionless>,5.957924896*dimensionless(),7.6e-8*dimensionless());
/// triton-electron magnetic moment ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_t_over_mu_e,quantity<dimensionless>,-1.620514423e-3*dimensionless(),2.1e-11*dimensionless());
/// triton-proton magnetic moment ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_t_over_mu_p,quantity<dimensionless>,1.066639908*dimensionless(),1.0e-8*dimensionless());
/// triton-neutron magnetic moment ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_t_over_mu_n,quantity<dimensionless>,-1.55718553*dimensionless(),3.7e-7*dimensionless());

/// helion mass
BOOST_UNITS_PHYSICAL_CONSTANT(m_h,quantity<mass>,5.00641192e-27*kilograms,2.5e-34*kilograms);
/// helion-electron mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_h_over_m_e,quantity<dimensionless>,5495.8852765*dimensionless(),5.2e-6*dimensionless());
/// helion-proton mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_h_over_m_p,quantity<dimensionless>,2.9931526713*dimensionless(),2.6e-9*dimensionless());
/// helion molar mass
BOOST_UNITS_PHYSICAL_CONSTANT(M_h,quantity<mass_over_amount>,3.0149322473e-3*kilograms/mole,2.6e-12*kilograms/mole);
/// helion shielded magnetic moment
BOOST_UNITS_PHYSICAL_CONSTANT(mu_h_prime,quantity<energy_over_magnetic_flux_density>,-1.074552982e-26*joules/tesla,3.0e-34*joules/tesla);
/// shielded helion-Bohr magneton ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_h_prime_over_mu_B,quantity<dimensionless>,-1.158671471e-3*dimensionless(),1.4e-11*dimensionless());
/// shielded helion-nuclear magneton ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_h_prime_over_mu_N,quantity<dimensionless>,-2.127497718*dimensionless(),2.5e-8*dimensionless());
/// shielded helion-proton magnetic moment ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_h_prime_over_mu_p,quantity<dimensionless>,-0.761766558*dimensionless(),1.1e-8*dimensionless());
/// shielded helion-shielded proton magnetic moment ratio
BOOST_UNITS_PHYSICAL_CONSTANT(mu_h_prime_over_mu_p_prime,quantity<dimensionless>,-0.7617861313*dimensionless(),3.3e-8*dimensionless());
/// shielded helion gyromagnetic ratio
BOOST_UNITS_PHYSICAL_CONSTANT(gamma_h_prime,quantity<frequency_over_magnetic_flux_density>,2.037894730e8/second/tesla,5.6e-0/second/tesla);

/// alpha particle mass
BOOST_UNITS_PHYSICAL_CONSTANT(m_alpha,quantity<mass>,6.64465620e-27*kilograms,3.3e-34*kilograms);
/// alpha-electron mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_alpha_over_m_e,quantity<dimensionless>,7294.2995365*dimensionless(),3.1e-6*dimensionless());
/// alpha-proton mass ratio
BOOST_UNITS_PHYSICAL_CONSTANT(m_alpha_over_m_p,quantity<dimensionless>,3.97259968951*dimensionless(),4.1e-10*dimensionless());
/// alpha molar mass
BOOST_UNITS_PHYSICAL_CONSTANT(M_alpha,quantity<mass_over_amount>,4.001506179127e-3*kilograms/mole,6.2e-14*kilograms/mole);

} // namespace CODATA

} // namespace constants    

} // namespace SI

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_CODATA_ATOMIC_AND_NUCLEAR_CONSTANTS_HPP
