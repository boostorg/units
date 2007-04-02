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

#if BOOST_UNITS_HAS_TYPEOF

#include <boost/units/measurement.hpp>
#include <boost/units/static_constant.hpp>
#include <boost/units/systems/si.hpp>

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
BOOST_UNITS_AUTO_STATIC_CONSTANT(alpha,(measurement<double>(7.2973525376e-3,5.0e-12)*dimensionless()));
/// Rydberg constant
BOOST_UNITS_AUTO_STATIC_CONSTANT(R_infinity,(measurement<double>(10973731.568527,7.3e-5)/meter));
/// Bohr radius
BOOST_UNITS_AUTO_STATIC_CONSTANT(a_0,(measurement<double>(0.52917720859e-10,3.6e-20)*meters));
/// Hartree energy
BOOST_UNITS_AUTO_STATIC_CONSTANT(E_h,(measurement<double>(4.35974394e-18,2.2e-25)*joules));

/// electron mass
BOOST_UNITS_AUTO_STATIC_CONSTANT(m_e,(measurement<double>(9.10938215e-31,4.5e-38)*kilograms));
/// electron-muon mass ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(m_e_over_m_mu,(measurement<double>(4.83633171e-3,1.2e-10)*dimensionless()));
/// electron-tau mass ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(m_e_over_m_tau,(measurement<double>(2.87564e-4,4.7e-8)*dimensionless()));
/// electron-proton mass ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(m_e_over_m_p,(measurement<double>(5.4461702177e-4,2.4e-13)*dimensionless()));
/// electron-neutron mass ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(m_e_over_m_n,(measurement<double>(5.4386734459e-4,3.3e-13)*dimensionless()));
/// electron-deuteron mass ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(m_e_over_m_d,(measurement<double>(2.7244371093e-4,1.2e-13)*dimensionless()));
/// electron-alpha particle mass ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(m_e_over_m_alpha,(measurement<double>(1.37093355570e-4,5.8e-14)*dimensionless()));
/// electron charge to mass ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(e_over_m_e,(measurement<double>(1.758820150e11,4.4e3)*coulombs/kilogram));
/// electron molar mass
BOOST_UNITS_AUTO_STATIC_CONSTANT(M_e,(measurement<double>(5.4857990943e-7,2.3e-16)*kilograms/mole));
/// Compton wavelength
BOOST_UNITS_AUTO_STATIC_CONSTANT(lambda_C,(measurement<double>(2.4263102175e-12,3.3e-21)*meters));
/// classical electron radius
BOOST_UNITS_AUTO_STATIC_CONSTANT(r_e,(measurement<double>(2.8179402894e-15,5.8e-24)*meters));
/// Thompson cross section
BOOST_UNITS_AUTO_STATIC_CONSTANT(sigma_e,(measurement<double>(0.6652458558e-28,2.7e-37)*square_meters));
/// electron magnetic moment
BOOST_UNITS_AUTO_STATIC_CONSTANT(mu_e,(measurement<double>(-928.476377e-26,2.3e-31)*joules/tesla));
/// electron-Bohr magenton moment ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(mu_e_over_mu_B,(measurement<double>(-1.00115965218111,7.4e-13)*dimensionless()));
/// electron-nuclear magneton moment ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(mu_e_over_mu_N,(measurement<double>(-183.28197092,8.0e-7)*dimensionless()));
/// electron magnetic moment anomaly
BOOST_UNITS_AUTO_STATIC_CONSTANT(a_e,(measurement<double>(1.15965218111e-3,7.4e-13)*dimensionless()));
/// electron g-factor
BOOST_UNITS_AUTO_STATIC_CONSTANT(g_e,(measurement<double>(-2.0023193043622,1.5e-12)*dimensionless()));
/// electron-muon magnetic moment ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(mu_e_over_mu_mu,(measurement<double>(206.7669877,5.2e-6)*dimensionless()));
/// electron-proton magnetic moment ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(mu_e_over_mu_p,(measurement<double>(-658.2106848,5.4e-6)*dimensionless()));
/// electron-shielded proton magnetic moment ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(mu_e_over_mu_p_prime,(measurement<double>(-658.2275971,7.2e-6)*dimensionless()));
/// electron-neutron magnetic moment ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(mu_e_over_mu_n,(measurement<double>(960.92050,2.3e-4)*dimensionless()));
/// electron-deuteron magnetic moment ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(mu_e_over_mu_d,(measurement<double>(-2143.923498,1.8e-5)*dimensionless()));
/// electron-shielded helion magnetic moment ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(mu_e_over_mu_h_prime,(measurement<double>(864.058257,1.0e-5)*dimensionless()));
/// electron gyromagnetic ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(gamma_e,(measurement<double>(1.760859770e11,4.4e3)/second/tesla));

/// muon mass
BOOST_UNITS_AUTO_STATIC_CONSTANT(m_mu,(measurement<double>(1.88353130e-28,1.1e-35)*kilograms));
/// muon-electron mass ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(m_mu_over_m_e,(measurement<double>(206.7682823,5.2e-6)*dimensionless()));
/// muon-tau mass ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(m_mu_over_m_tau,(measurement<double>(5.94592e-2,9.7e-6)*dimensionless()));
/// muon-proton mass ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(m_mu_over_m_p,(measurement<double>(0.1126095261,2.9e-9)*dimensionless()));
/// muon-neutron mass ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(m_mu_over_m_n,(measurement<double>(0.1124545167,2.9e-9)*dimensionless()));
/// muon molar mass
BOOST_UNITS_AUTO_STATIC_CONSTANT(M_mu,(measurement<double>(0.1134289256e-3,2.9e-12)*kilograms/mole));
/// muon Compton wavelength
BOOST_UNITS_AUTO_STATIC_CONSTANT(lambda_C_mu,(measurement<double>(11.73444104e-15,3.0e-22)*meters));
/// muon magnetic moment
BOOST_UNITS_AUTO_STATIC_CONSTANT(mu_mu,(measurement<double>(-4.49044786e-26,1.6e-33)*joules/tesla));
/// muon magnetic moment anomaly
BOOST_UNITS_AUTO_STATIC_CONSTANT(a_mu,(measurement<double>(1.16592069e-3,6.0e-10)*dimensionless()));
/// muon-Bohr magneton ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(mu_mu_over_mu_B,(measurement<double>(-4.84197049e-3,1.2e-10)*dimensionless()));
/// muon-nuclear magneton ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(mu_mu_over_mu_N,(measurement<double>(-8.89059705,2.3e-7)*dimensionless()));
/// muon g-factor
BOOST_UNITS_AUTO_STATIC_CONSTANT(g_mu,(measurement<double>(-2.0023318414,1.2e-9)*dimensionless()));
/// muon-proton magnetic moment ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(mu_mu_over_mu_p,(measurement<double>(-3.183345137,8.5e-8)*dimensionless()));

/// tau mass
BOOST_UNITS_AUTO_STATIC_CONSTANT(m_tau,(measurement<double>(3.16777e-27,5.2e-31)*kilograms));
/// tau-electron mass ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(m_tau_over_m_e,(measurement<double>(3477.48,5.7e-1)*dimensionless()));
/// tau-muon mass ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(m_tau_over_m_mu,(measurement<double>(16.8183,2.7e-3)*dimensionless()));
/// tau-proton mass ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(m_tau_over_m_p,(measurement<double>(1.89390,3.1e-4)*dimensionless()));
/// tau-neutron mass ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(m_tau_over_m_n,(measurement<double>(1.89129,3.1e-4)*dimensionless()));
/// tau molar mass
BOOST_UNITS_AUTO_STATIC_CONSTANT(M_tau,(measurement<double>(1.90768e-3,3.1e-7)*kilograms/mole));
/// tau Compton wavelength
BOOST_UNITS_AUTO_STATIC_CONSTANT(lambda_C_tau,(measurement<double>(0.69772e-15,1.1e-19)*meters));

/// proton mass
BOOST_UNITS_AUTO_STATIC_CONSTANT(m_p,(measurement<double>(1.672621637e-27,8.3e-35)*kilograms));
/// proton-electron mass ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(m_p_over_m_e,(measurement<double>(1836.15267247,8.0e-7)*dimensionless()));
/// proton-muon mass ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(m_p_over_m_mu,(measurement<double>(8.88024339,2.3e-7)*dimensionless()));
/// proton-tau mass ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(m_p_over_m_tau,(measurement<double>(0.528012,8.6e-5)*dimensionless()));
/// proton-neutron mass ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(m_p_over_m_n,(measurement<double>(0.99862347824,4.6e-10)*dimensionless()));
/// proton charge to mass ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(e_over_m_p,(measurement<double>(9.57883392e7,2.4e0)*coulombs/kilogram));
/// proton molar mass
BOOST_UNITS_AUTO_STATIC_CONSTANT(M_p,(measurement<double>(1.00727646677e-3,1.0e-13)*kilograms/mole));
/// proton Compton wavelength
BOOST_UNITS_AUTO_STATIC_CONSTANT(lambda_C_p,(measurement<double>(1.3214098446e-15,1.9e-24)*meters));
/// proton rms charge radius
BOOST_UNITS_AUTO_STATIC_CONSTANT(R_p,(measurement<double>(0.8768e-15,6.9e-18)*meters));
/// proton magnetic moment
BOOST_UNITS_AUTO_STATIC_CONSTANT(mu_p,(measurement<double>(1.410606662e-26,3.7e-34)*joules/tesla));
/// proton-Bohr magneton ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(mu_p_over_mu_B,(measurement<double>(1.521032209e-3,1.2e-11)*dimensionless()));
/// proton-nuclear magneton ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(mu_p_over_mu_N,(measurement<double>(2.792847356,2.3e-8)*dimensionless()));
/// proton g-factor
BOOST_UNITS_AUTO_STATIC_CONSTANT(g_p,(measurement<double>(5.585694713,4.6e-8)*dimensionless()));
/// proton-neutron magnetic moment ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(mu_p_over_mu_n,(measurement<double>(-1.45989806,3.4e-7)*dimensionless()));
/// shielded proton magnetic moment
BOOST_UNITS_AUTO_STATIC_CONSTANT(mu_p_prime,(measurement<double>(1.410570419e-26,3.8e-34)*joules/tesla));
/// proton gyromagnetic ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(gamma_p,(measurement<double>(2.675222099e8,7.0e0)/second/tesla));
/// shielded proton gyromagnetic ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(gamma_p_prime,(measurement<double>(2.675153362e8,7.3e0)/second/tesla));

/// neutron mass
BOOST_UNITS_AUTO_STATIC_CONSTANT(m_n,(measurement<double>(1.674927211e-27,8.4e-35)*kilograms));
/// neutron-electron mass ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(m_n_over_m_e,(measurement<double>(1838.6836605,1.1e-6)*dimensionless()));
/// neutron-muon mass ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(m_n_over_m_mu,(measurement<double>(8.89248409,2.3e-7)*dimensionless()));
/// neutron-tau mass ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(m_n_over_m_tau,(measurement<double>(0.528740,8.6e-5)*dimensionless()));
/// neutron-proton mass ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(m_n_over_m_p,(measurement<double>(1.00137841918,4.6e-10)*dimensionless()));
/// neutron Compton wavelength
BOOST_UNITS_AUTO_STATIC_CONSTANT(lambda_C_n,(measurement<double>(1.3195908951e-15,2.0e-24)*meters));
/// neutron molar mass
BOOST_UNITS_AUTO_STATIC_CONSTANT(M_n,(measurement<double>(1.00866491597e-3,4.3e-13)*kilograms/mole));
/// neutron magnetic moment
BOOST_UNITS_AUTO_STATIC_CONSTANT(mu_n,(measurement<double>(-0.96623641e-26,2.3e-33)*joules/tesla));
/// neutron g-factor
BOOST_UNITS_AUTO_STATIC_CONSTANT(g_n,(measurement<double>(-3.82608545,9.0e-7)*dimensionless()));
/// neutron-proton magnetic moment ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(mu_n_over_mu_p,(measurement<double>(-0.68497934,1.6e-7)*dimensionless()));
/// neutron-shielded proton magnetic moment ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(mu_n_over_mu_p_prime,(measurement<double>(-0.68499694,1.6e-7)*dimensionless()));
/// neutron gyromagnetic ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(gamma_n,(measurement<double>(1.83247185e8,4.3e1)/second/tesla));

/// deuteron mass
BOOST_UNITS_AUTO_STATIC_CONSTANT(m_d,(measurement<double>(3.34358320e-27,1.7e-34)*kilograms));
/// deuteron-electron mass ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(m_d_over_m_e,(measurement<double>(3670.4829654,1.6e-6)*kilograms/kilograms));
/// deuteron-proton mass ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(m_d_over_m_p,(measurement<double>(1.99900750108,2.2e-10)*kilograms/kilograms));
/// deuteron molar mass
BOOST_UNITS_AUTO_STATIC_CONSTANT(M_d,(measurement<double>(2.013553212724e-3,7.8e-14)*kilograms/mole));
/// deuteron rms charge radius
BOOST_UNITS_AUTO_STATIC_CONSTANT(R_d,(measurement<double>(2.1402e-15,2.8e-18)*meters));
/// deuteron magnetic moment
BOOST_UNITS_AUTO_STATIC_CONSTANT(mu_d,(measurement<double>(0.433073465e-26,1.1e-34)*joules/tesla));
/// deuteron-electron magnetic moment ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(mu_d_over_mu_e,(measurement<double>(-4.664345537e-4,3.9e-12)*dimensionless()));
/// deuteron-proton magnetic moment ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(mu_d_over_mu_p,(measurement<double>(0.3070122070,2.4e-9)*dimensionless()));
/// deuteron-neutron magnetic moment ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(mu_d_over_mu_n,(measurement<double>(-0.44820652,1.1e-7)*dimensionless()));

/// helion mass
BOOST_UNITS_AUTO_STATIC_CONSTANT(m_h,(measurement<double>(5.00641192e-27,2.5e-34)*kilograms));

/// alpha particle mass
BOOST_UNITS_AUTO_STATIC_CONSTANT(m_alpha,(measurement<double>(6.64465620e-27,3.3e-34)*kilograms));

} // namespace CODATA

} // namespace constants    

} // namespace SI

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_HAS_TYPEOF

#endif // BOOST_UNITS_CODATA_ATOMIC_AND_NUCLEAR_CONSTANTS_HPP
