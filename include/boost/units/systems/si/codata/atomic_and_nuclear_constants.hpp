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

#include <boost/units/systems/si.hpp>

#if BOOST_UNITS_HAS_TYPEOF

#include <boost/units/static_constant.hpp>

/// \file
/// CODATA recommended values of fundamental atomic and nuclear constants: NIST SP 961

namespace boost {

namespace units { 

namespace SI {
                            
namespace constants {

namespace CODATA {

/// CODATA recommended values of the fundamental physical constants: NIST SP 961
typedef dimensionless_quantity<SI::system,double>::type    dimensionless_constant;

// ATOMIC AND NUCLEAR
/// fine structure constant
BOOST_UNITS_STATIC_CONSTANT(alpha,dimensionless_constant) = 7.297352568e-3;
/// Rydberg constant
BOOST_UNITS_AUTO_STATIC_CONSTANT(R_infinity,(10973731.568525/meter));
/// Bohr radius
BOOST_UNITS_AUTO_STATIC_CONSTANT(a_0,(0.5291772108e-10*meters));
/// Hartree energy
BOOST_UNITS_AUTO_STATIC_CONSTANT(E_h,(4.35974417e-18*joules));

/// electron mass
BOOST_UNITS_AUTO_STATIC_CONSTANT(m_e,(9.1093826e-31*kilograms));
/// electron-muon mass ratio
BOOST_UNITS_STATIC_CONSTANT(m_e_over_m_mu,dimensionless_constant) = 4.83633167e-3;
/// electron-tau mass ratio
BOOST_UNITS_STATIC_CONSTANT(m_e_over_m_tau,dimensionless_constant) = 2.87564e-4;
/// electron-proton mass ratio
BOOST_UNITS_STATIC_CONSTANT(m_e_over_m_p,dimensionless_constant) = 5.4461702173e-4;
/// electron-neutron mass ratio
BOOST_UNITS_STATIC_CONSTANT(m_e_over_m_n,dimensionless_constant) = 5.4386734481e-4;
/// electron-deuteron mass ratio
BOOST_UNITS_STATIC_CONSTANT(m_e_over_m_d,dimensionless_constant) = 2.7244371095e-4;
/// electron-alpha particle mass ratio
BOOST_UNITS_STATIC_CONSTANT(m_e_over_m_alpha,dimensionless_constant) = 1.37093355575e-4;
/// electron charge to mass ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(e_over_m_e,(1.75882012e11*coulombs/kilogram));
/// electron molar mass
BOOST_UNITS_AUTO_STATIC_CONSTANT(M_e,(5.4857990945e-7*kilograms/mole));
/// Compton wavelength
BOOST_UNITS_AUTO_STATIC_CONSTANT(lambda_C,(2.426310238e-12*meters));
/// classical electron radius
BOOST_UNITS_AUTO_STATIC_CONSTANT(r_e,(2.817940325e-15*meters));
/// Thompson cross section
BOOST_UNITS_AUTO_STATIC_CONSTANT(sigma_e,(0.665245873e-28*square_meters));
/// electron magnetic moment
BOOST_UNITS_AUTO_STATIC_CONSTANT(mu_e,(-928.476412e-26*joules/tesla));
/// electron magnetic moment anomaly
BOOST_UNITS_STATIC_CONSTANT(a_e,dimensionless_constant) = 1.1596521859e-3;
/// electron g-factor
BOOST_UNITS_STATIC_CONSTANT(g_e,dimensionless_constant) = -2.0023193043718;
/// electron-muon magnetic moment ratio
BOOST_UNITS_STATIC_CONSTANT(mu_e_over_mu_mu,dimensionless_constant) = 206.7669894;
/// electron-proton magnetic moment ratio
BOOST_UNITS_STATIC_CONSTANT(mu_e_over_mu_p,dimensionless_constant) = -658.2106862;
/// electron-shielded proton magnetic moment ratio
BOOST_UNITS_STATIC_CONSTANT(mu_e_over_mu_p_prime,dimensionless_constant) = -658.2275956;
/// electron-neutron magnetic moment ratio
BOOST_UNITS_STATIC_CONSTANT(mu_e_over_mu_n,dimensionless_constant) = 960.92050;
/// electron-deuteron magnetic moment ratio
BOOST_UNITS_STATIC_CONSTANT(mu_e_over_mu_d,dimensionless_constant) = -2143.923493;
/// electron-shielded helion magnetic moment ratio
BOOST_UNITS_STATIC_CONSTANT(mu_e_over_mu_h_prime,dimensionless_constant) = 864.058255;
/// electron gyromagnetic ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(gamma_e,(1.76085974/second/tesla));

/// muon mass
BOOST_UNITS_AUTO_STATIC_CONSTANT(m_mu,(1.88353140e-28*kilograms));
/// muon-electron mass ratio
BOOST_UNITS_STATIC_CONSTANT(m_mu_over_m_e,dimensionless_constant) = 206.7682838;
/// muon-tau mass ratio
BOOST_UNITS_STATIC_CONSTANT(m_mu_over_m_tau,dimensionless_constant) = 5.94592e-2;
/// muon-proton mass ratio
BOOST_UNITS_STATIC_CONSTANT(m_mu_over_m_p,dimensionless_constant) = 0.1126095269;
/// muon-neutron mass ratio
BOOST_UNITS_STATIC_CONSTANT(m_mu_over_m_n,dimensionless_constant) = 0.1124545175;
/// muon molar mass
BOOST_UNITS_AUTO_STATIC_CONSTANT(M_mu,(0.1134289264e-3*kilograms/mole));
/// muon Compton wavelength
BOOST_UNITS_AUTO_STATIC_CONSTANT(lambda_C_mu,(11.73444105e-15*meters));
/// muon magnetic moment
BOOST_UNITS_AUTO_STATIC_CONSTANT(mu_m,(-4.49044799e-26*joules/tesla));
/// muon magnetic moment anomaly
BOOST_UNITS_STATIC_CONSTANT(a_mu,dimensionless_constant) = 1.16591981e-3;
/// muon g-factor
BOOST_UNITS_STATIC_CONSTANT(g_mu,dimensionless_constant) = -2.0023318396;
/// muon-proton magnetic moment ratio
BOOST_UNITS_STATIC_CONSTANT(mu_mu_over_mu_p,dimensionless_constant) = -3.183345118;

/// tau mass
BOOST_UNITS_AUTO_STATIC_CONSTANT(m_tau,(3.16777e-27*kilograms));
/// tau-electron mass ratio
BOOST_UNITS_STATIC_CONSTANT(m_tau_over_m_e,dimensionless_constant) = 3477.48;
/// tau-muon mass ratio
BOOST_UNITS_STATIC_CONSTANT(m_tau_over_m_mu,dimensionless_constant) = 16.8183;
/// tau-proton mass ratio
BOOST_UNITS_STATIC_CONSTANT(m_tau_over_m_p,dimensionless_constant) = 1.89390;
/// tau-neutron mass ratio
BOOST_UNITS_STATIC_CONSTANT(m_tau_over_m_n,dimensionless_constant) = 1.89129;
/// tau molar mass
BOOST_UNITS_AUTO_STATIC_CONSTANT(M_tau,(1.907698e-3*kilograms/mole));
/// tau Compton wavelength
BOOST_UNITS_AUTO_STATIC_CONSTANT(lambda_C_tau,(0.69772e-15*meters));

/// proton mass
BOOST_UNITS_AUTO_STATIC_CONSTANT(m_p,(1.67262171e-27*kilograms));
/// proton-electron mass ratio
BOOST_UNITS_STATIC_CONSTANT(m_p_over_m_e,dimensionless_constant) = 1836.15267261;
/// proton-muon mass ratio
BOOST_UNITS_STATIC_CONSTANT(m_p_over_m_mu,dimensionless_constant) = 8.88024333;
/// proton-tau mass ratio
BOOST_UNITS_STATIC_CONSTANT(m_p_over_m_tau,dimensionless_constant) = 0.528012;
/// proton-neutron mass ratio
BOOST_UNITS_STATIC_CONSTANT(m_p_over_m_n,dimensionless_constant) = 0.99862347872;
/// proton charge to mass ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(e_over_m_p,(9.57883376e7*coulombs/kilogram));
/// proton molar mass
BOOST_UNITS_AUTO_STATIC_CONSTANT(M_p,(1.00727646688e-3*kilograms/mole));
/// proton rms charge radius
BOOST_UNITS_AUTO_STATIC_CONSTANT(R_p,(0.8750e-15*meters)) = 0.8750e-15*meters;
/// proton magnetic moment
BOOST_UNITS_AUTO_STATIC_CONSTANT(mu_p,(1.41060671e-26*joules/tesla));
/// proton g-factor
BOOST_UNITS_STATIC_CONSTANT(g_p,dimensionless_constant) = 5.585694701;
/// proton-neutron magnetic moment ratio
BOOST_UNITS_STATIC_CONSTANT(mu_p_over_mu_n,dimensionless_constant) = -1.45989805;
/// shielded proton magnetic moment
BOOST_UNITS_AUTO_STATIC_CONSTANT(mu_p_prime,(1.41057047e-26*joules/tesla));
/// proton gyromagnetic ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(gamma_p,(2.67522205e8/second/tesla));
/// shielded proton gyromagnetic ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(gamma_p_prime,(2.67515333e8/second/tesla));

/// neutron mass
BOOST_UNITS_AUTO_STATIC_CONSTANT(m_n,(1.67492728e-27*kilograms));
/// neutron-electron mass ratio
BOOST_UNITS_STATIC_CONSTANT(m_n_over_m_e,dimensionless_constant) = 1838.6836598;
/// neutron-muon mass ratio
BOOST_UNITS_STATIC_CONSTANT(m_n_over_m_mu,dimensionless_constant) = 8.89248402;
/// neutron-tau mass ratio
BOOST_UNITS_STATIC_CONSTANT(m_n_over_m_tau,dimensionless_constant) = 0.528740;
/// neutron-proton mass ratio
BOOST_UNITS_STATIC_CONSTANT(m_n_over_m_p,dimensionless_constant) = 1.00137841870;
/// neutron Compton wavelength
BOOST_UNITS_AUTO_STATIC_CONSTANT(lambda_C_n,(1.3195909067e-15*meters));
/// neutron molar mass
BOOST_UNITS_AUTO_STATIC_CONSTANT(M_n,(1.00866491560e-3*kilograms/mole));
/// neutron magnetic moment
BOOST_UNITS_AUTO_STATIC_CONSTANT(mu_n,(-0.96623645e-26*joules/tesla));
/// neutron g-factor
BOOST_UNITS_STATIC_CONSTANT(g_n,dimensionless_constant) = -3.82608546;
/// neutron-proton magnetic moment ratio
BOOST_UNITS_STATIC_CONSTANT(mu_n_over_mu_p,dimensionless_constant) = -0.68497934;
/// neutron-shielded proton magnetic moment ratio
BOOST_UNITS_STATIC_CONSTANT(mu_n_over_mu_p_prime,dimensionless_constant) = -0.68499694;
/// neutron gyromagnetic ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(gamma_n,(1.83247183e8/second/tesla));

/// deuteron mass
BOOST_UNITS_AUTO_STATIC_CONSTANT(m_d,(3.34358335e-27*kilograms));
/// deuteron-electron mass ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(m_d_over_m_e,(1.0*kilograms/kilograms)) = 3670.4829652;
/// deuteron-proton mass ratio
BOOST_UNITS_AUTO_STATIC_CONSTANT(m_d_over_m_p,(1.0*kilograms/kilograms)) = 1.99900750082;
/// deuteron molar mass
BOOST_UNITS_AUTO_STATIC_CONSTANT(M_d,(2.01355321270e-3*kilograms/mole));
/// deuteron rms charge radius
BOOST_UNITS_AUTO_STATIC_CONSTANT(R_d,(2.1394e-15*meters)) = 2.1394e-15*meters;
/// deuteron magnetic moment
BOOST_UNITS_AUTO_STATIC_CONSTANT(mu_d,(0.43307073482e-26*joules/tesla));
/// deuteron-electron magnetic moment ratio
BOOST_UNITS_STATIC_CONSTANT(mu_d_over_mu_e,dimensionless_constant) = -4.664345584e-4;
/// deuteron-proton magnetic moment ratio
BOOST_UNITS_STATIC_CONSTANT(mu_d_over_mu_p,dimensionless_constant) = 0.3070122084;
/// deuteron-neutron magnetic moment ratio
BOOST_UNITS_STATIC_CONSTANT(mu_d_over_mu_n,dimensionless_constant) = -0.44820652;

/// helion mass
BOOST_UNITS_AUTO_STATIC_CONSTANT(m_h,(5.00641214e-27*kilograms));

/// alpha particle mass
BOOST_UNITS_AUTO_STATIC_CONSTANT(m_alpha,(6.6446565e-27*kilograms));

} // namespace CODATA

} // namespace constants    

} // namespace SI

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_HAS_TYPEOF

#endif // BOOST_UNITS_CODATA_ATOMIC_AND_NUCLEAR_CONSTANTS_HPP
