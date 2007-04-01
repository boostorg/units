// mcs::units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2007 Matthias Christian Schabel
// Copyright (C) 2007 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

/** 
\file
    
\brief unit_example_19.cpp

\detailed 
CODATA physical constants.

Output:
@verbatim

//[unit_example_19_output
CODATA physical constants:

Universal constants: 

c           :   2.99792e+08 m s^(-1)
mu_0        :   1.25664e-06 m kg s^(-2) A^(-2)
epsilon_0   :   8.85419e-12 m^(-3) kg^(-1) s^4 A^2
Z_0         :   376.73 m^2 kg s^(-3) A^(-2)
G           :   6.6742e-11 m^3 kg^(-1) s^(-2)
h           :   6.62607e-34 m^2 kg s^(-1)
hbar        :   1.05457e-34 m^2 kg s^(-1)
m_P         :   2.17645e-08 kg
T_P         :   1.41679e+32 K
l_P         :   1.61624e-35 m
t_P         :   5.39121e-44 s

Electromagnetic constants: 

e           :   1.60218e-19 s A
e/h         :   2.41799 m^(-2) kg^(-1) s^2 A
Phi_0       :   2.06783 m^2 kg s^(-2) A^(-1)
G_0         :   7.74809e-05 m^(-2) kg^(-1) s^3 A^2
K_J         :   4.83598e+14 m^(-2) kg^(-1) s^2 A
R_K         :   25812.8 m^2 kg s^(-3) A^(-2)
mu_B        :   9.27401e-24 m^2 A
mu_N        :   5.05078e-27 m^2 A

Physico-chemical constants: 

N_A         :   6.02214e+23 mol^(-1)
m_u         :   1.66054e-27 kg
F           :   96485.3 s A mol^(-1)
R           :   8.31447 m^2 kg s^(-2) K^(-1) mol^(-1)
k_B         :   1.38065e-23 m^2 kg s^(-2) K^(-1)
V_m         :   0.022414 m^3 mol^(-1)
sigma_SB    :   5.6704e-08 kg s^(-3) K^(-4)
c_1         :   3.74177e-16 m^4 kg s^(-3)
c_2         :   0.0143878 m K
b           :   0.00289777 m K

Atomic and nuclear constants: 

alpha       :   0.00729735 dimensionless
R_infinity  :   1.09737e+07 m^(-1)
a_0         :   5.29177e-11 m
E_h         :   4.35974e-18 m^2 kg s^(-2)

    electron: 

m_e         :   9.10938e-31 kg
m_e/m_mu    :   0.00483633 dimensionless
m_e/m_tau   :   0.000287564 dimensionless
m_e/m_p     :   0.000544617 dimensionless
m_e/m_n     :   0.000543867 dimensionless
m_e/m_d     :   0.000272444 dimensionless
m_e/m_alpha :   0.000137093 dimensionless
e/m_e       :   1.75882e+11 kg^(-1) s A
M_e         :   5.4858e-07 kg mol^(-1)
lambda_C    :   2.42631e-12 m
r_e         :   2.81794e-15 m
sigma_e     :   6.65246e-29 m^2
mu_e        :   -9.28476e-24 m^2 A
a_e         :   0.00115965 dimensionless
g_e         :   -2.00232 dimensionless
mu_e/mu_mu  :   206.767 dimensionless
mu_e/mu_p   :   -658.211 dimensionless
mu_e/mu_pp  :   -658.228 dimensionless
mu_e/mu_n   :   960.92 dimensionless
mu_e/mu_d   :   -2143.92 dimensionless
mu_e/mu_hp  :   864.058 dimensionless
gamma_e     :   1.76086 kg^(-1) s A

    muon: 

m_mu        :   1.88353e-28 kg
m_mu/m_e    :   206.768 dimensionless
m_mu/m_tau  :   0.0594592 dimensionless
m_mu/m_p    :   0.11261 dimensionless
m_mu/m_n    :   0.112455 dimensionless
M_mu        :   0.000113429 kg mol^(-1)
lambda_C_mu :   1.17344e-14 m
mu_m        :   -4.49045e-26 m^2 A
a_mu        :   0.00116592 dimensionless
g_mu        :   -2.00233 dimensionless
mu_mu/mu_p  :   -3.18335 dimensionless

    tau: 

m_tau       :   3.16777e-27 kg
m_tau/m_e   :   3477.48 dimensionless
m_tau/m_mu  :   16.8183 dimensionless
m_tau/m_p   :   1.8939 dimensionless
m_tau/m_n   :   1.89129 dimensionless
M_tau       :   0.0019077 kg mol^(-1)
lambda_C_tau:   6.9772e-16 m

    proton: 

m_p         :   1.67262e-27 kg
m_p/m_e     :   1836.15 dimensionless
m_p/m_mu    :   8.88024 dimensionless
m_p/m_tau   :   0.528012 dimensionless
m_p/m_n     :   0.998623 dimensionless
e/m_p       :   9.57883e+07 kg^(-1) s A
M_p         :   0.00100728 kg mol^(-1)
R_p         :   8.75e-16 m
mu_p        :   1.41061e-26 m^2 A
g_p         :   5.58569 dimensionless
mu_p/mu_n   :   -1.4599 dimensionless
mu_pp       :   1.41057e-26 m^2 A
gamma_p     :   2.67522e+08 kg^(-1) s A
gamma_pp    :   2.67515e+08 kg^(-1) s A

    neutron: 

m_n         :   1.67493e-27 kg
m_n/m_e     :   1838.68 dimensionless
m_n/m_mu    :   8.89248 dimensionless
m_n/m_tau   :   0.52874 dimensionless
m_n/m_p     :   1.00138 dimensionless
lambda_C_n  :   1.31959e-15 m
M_n         :   0.00100866 kg mol^(-1)
mu_n        :   -9.66236e-27 m^2 A
g_n         :   -3.82609 dimensionless
mu_n/mu_p   :   -0.684979 dimensionless
mu_n/mu_pp  :   -0.684997 dimensionless
gamma_n     :   1.83247e+08 kg^(-1) s A

    deuteron: 

m_d         :   3.34358e-27 kg
m_d/m_e     :   3670.48 dimensionless
m_d/m_p     :   1.99901 dimensionless
M_d         :   0.00201355 kg mol^(-1)
R_d         :   2.1394e-15 m
mu_d        :   4.33071e-27 m^2 A
g_n         :   -3.82609 dimensionless
mu_d/mu_e   :   -0.000466435 dimensionless
mu_d/mu_p   :   0.307012 dimensionless
mu_d/mu_n   :   -0.448207 dimensionless

    helion: 

m_h         :   5.00641e-27 kg

    alpha particle: 

m_alpha     :   6.64466e-27 kg
//]

@endverbatim
**/

#include <iostream>

#include <boost/units/io.hpp>
#include <boost/units/systems/si.hpp>
#include <boost/units/systems/si/constants.hpp>

#if BOOST_UNITS_HAS_TYPEOF 

int main()
{   
    using namespace boost::units::SI::constants::CODATA;
        
    std::cout << "CODATA physical constants:" << std::endl;
    
    std::cout << std::endl << "Universal constants: " << std::endl << std::endl
              << "c           :\t" << c << std::endl
              << "mu_0        :\t" << mu_0 << std::endl
              << "epsilon_0   :\t" << epsilon_0 << std::endl
              << "Z_0         :\t" << Z_0 << std::endl
              << "G           :\t" << G << std::endl
              << "h           :\t" << h << std::endl
              << "hbar        :\t" << hbar << std::endl
              << "m_P         :\t" << m_P << std::endl
              << "T_P         :\t" << T_P << std::endl
              << "l_P         :\t" << l_P << std::endl
              << "t_P         :\t" << t_P << std::endl
              << std::endl << "Electromagnetic constants: " << std::endl << std::endl
              << "e           :\t" << e << std::endl
              << "e/h         :\t" << e_over_h << std::endl
              << "Phi_0       :\t" << Phi_0 << std::endl
              << "G_0         :\t" << G_0 << std::endl
              << "K_J         :\t" << K_J << std::endl
              << "R_K         :\t" << R_K << std::endl
              << "mu_B        :\t" << mu_B << std::endl
              << "mu_N        :\t" << mu_N << std::endl
              << std::endl << "Physico-chemical constants: " << std::endl << std::endl
              << "N_A         :\t" << N_A << std::endl
              << "m_u         :\t" << m_u << std::endl
              << "F           :\t" << F << std::endl
              << "R           :\t" << R << std::endl
              << "k_B         :\t" << k_B << std::endl
              << "V_m         :\t" << V_m << std::endl
              << "sigma_SB    :\t" << sigma_SB << std::endl
              << "c_1         :\t" << c_1 << std::endl
              << "c_2         :\t" << c_2 << std::endl
              << "b           :\t" << b << std::endl
              << std::endl << "Atomic and nuclear constants: " << std::endl << std::endl
              << "alpha       :\t" << alpha << std::endl
              << "R_infinity  :\t" << R_infinity << std::endl
              << "a_0         :\t" << a_0 << std::endl
              << "E_h         :\t" << E_h << std::endl
              << std::endl << "    electron: " << std::endl << std::endl
              << "m_e         :\t" << m_e << std::endl
              << "m_e/m_mu    :\t" << m_e_over_m_mu << std::endl
              << "m_e/m_tau   :\t" << m_e_over_m_tau << std::endl
              << "m_e/m_p     :\t" << m_e_over_m_p << std::endl
              << "m_e/m_n     :\t" << m_e_over_m_n << std::endl
              << "m_e/m_d     :\t" << m_e_over_m_d << std::endl
              << "m_e/m_alpha :\t" << m_e_over_m_alpha << std::endl
              << "e/m_e       :\t" << e_over_m_e << std::endl
              << "M_e         :\t" << M_e << std::endl
              << "lambda_C    :\t" << lambda_C << std::endl
              << "r_e         :\t" << r_e << std::endl
              << "sigma_e     :\t" << sigma_e << std::endl
              << "mu_e        :\t" << mu_e << std::endl
              << "a_e         :\t" << a_e << std::endl
              << "g_e         :\t" << g_e << std::endl
              << "mu_e/mu_mu  :\t" << mu_e_over_mu_mu << std::endl
              << "mu_e/mu_p   :\t" << mu_e_over_mu_p << std::endl
              << "mu_e/mu_pp  :\t" << mu_e_over_mu_p_prime << std::endl
              << "mu_e/mu_n   :\t" << mu_e_over_mu_n << std::endl
              << "mu_e/mu_d   :\t" << mu_e_over_mu_d << std::endl
              << "mu_e/mu_hp  :\t" << mu_e_over_mu_h_prime << std::endl
              << "gamma_e     :\t" << gamma_e << std::endl
              << std::endl << "    muon: " << std::endl << std::endl
              << "m_mu        :\t" << m_mu << std::endl
              << "m_mu/m_e    :\t" << m_mu_over_m_e << std::endl
              << "m_mu/m_tau  :\t" << m_mu_over_m_tau << std::endl
              << "m_mu/m_p    :\t" << m_mu_over_m_p << std::endl
              << "m_mu/m_n    :\t" << m_mu_over_m_n << std::endl
              << "M_mu        :\t" << M_mu << std::endl
              << "lambda_C_mu :\t" << lambda_C_mu << std::endl
              << "mu_mu       :\t" << mu_mu << std::endl
              << "a_mu        :\t" << a_mu << std::endl
              << "g_mu        :\t" << g_mu << std::endl
              << "mu_mu/mu_p  :\t" << mu_mu_over_mu_p << std::endl
              << std::endl << "    tau: " << std::endl << std::endl
              << "m_tau       :\t" << m_tau << std::endl
              << "m_tau/m_e   :\t" << m_tau_over_m_e << std::endl
              << "m_tau/m_mu  :\t" << m_tau_over_m_mu << std::endl
              << "m_tau/m_p   :\t" << m_tau_over_m_p << std::endl
              << "m_tau/m_n   :\t" << m_tau_over_m_n << std::endl
              << "M_tau       :\t" << M_tau << std::endl
              << "lambda_C_tau:\t" << lambda_C_tau << std::endl
              << std::endl << "    proton: " << std::endl << std::endl
              << "m_p         :\t" << m_p << std::endl
              << "m_p/m_e     :\t" << m_p_over_m_e << std::endl
              << "m_p/m_mu    :\t" << m_p_over_m_mu << std::endl
              << "m_p/m_tau   :\t" << m_p_over_m_tau << std::endl
              << "m_p/m_n     :\t" << m_p_over_m_n << std::endl
              << "e/m_p       :\t" << e_over_m_p << std::endl
              << "M_p         :\t" << M_p << std::endl
              << "R_p         :\t" << R_p << std::endl
              << "mu_p        :\t" << mu_p << std::endl
              << "g_p         :\t" << g_p << std::endl
              << "mu_p/mu_n   :\t" << mu_p_over_mu_n << std::endl
              << "mu_pp       :\t" << mu_p_prime << std::endl
              << "gamma_p     :\t" << gamma_p << std::endl
              << "gamma_pp    :\t" << gamma_p_prime << std::endl
              << std::endl << "    neutron: " << std::endl << std::endl
              << "m_n         :\t" << m_n << std::endl
              << "m_n/m_e     :\t" << m_n_over_m_e << std::endl
              << "m_n/m_mu    :\t" << m_n_over_m_mu << std::endl
              << "m_n/m_tau   :\t" << m_n_over_m_tau << std::endl
              << "m_n/m_p     :\t" << m_n_over_m_p << std::endl
              << "lambda_C_n  :\t" << lambda_C_n << std::endl
              << "M_n         :\t" << M_n << std::endl
              << "mu_n        :\t" << mu_n << std::endl
              << "g_n         :\t" << g_n << std::endl
              << "mu_n/mu_p   :\t" << mu_n_over_mu_p << std::endl
              << "mu_n/mu_pp  :\t" << mu_n_over_mu_p_prime << std::endl
              << "gamma_n     :\t" << gamma_n << std::endl
              << std::endl << "    deuteron: " << std::endl << std::endl
              << "m_d         :\t" << m_d << std::endl
              << "m_d/m_e     :\t" << m_d_over_m_e << std::endl
              << "m_d/m_p     :\t" << m_d_over_m_p << std::endl
              << "M_d         :\t" << M_d << std::endl
              << "R_d         :\t" << R_d << std::endl
              << "mu_d        :\t" << mu_d << std::endl
              << "g_n         :\t" << g_n << std::endl
              << "mu_d/mu_e   :\t" << mu_d_over_mu_e << std::endl
              << "mu_d/mu_p   :\t" << mu_d_over_mu_p << std::endl
              << "mu_d/mu_n   :\t" << mu_d_over_mu_n << std::endl
              << std::endl << "    helion: " << std::endl << std::endl 
              << "m_h         :\t" << m_h << std::endl
              << std::endl << "    alpha particle: " << std::endl << std::endl 
              << "m_alpha     :\t" << m_alpha << std::endl
              << std::endl;

    return 0;
}

#else

int main(void)
{
    std::cout << "No typeof enabled" << std::endl;
    
    return 0;
}

#endif // BOOST_UNITS_HAS_TYPEOF
