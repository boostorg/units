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

c           :	  2.9979245800000e+08 (exact) m s^(-1)
mu_0        :	  1.2566370614359e-06 (exact) m kg s^(-2) A^(-2)
epsilon_0   :	  8.8541878176204e-12 (exact) m^(-3) kg^(-1) s^4 A^2
Z_0         :	  3.7673031346177e+02 (exact) m^2 kg s^(-3) A^(-2)
G           :	  6.6742800000000e-11 (rel. unc. = 1.0e-04) m^3 kg^(-1) s^(-2)
h           :	  6.6260689600000e-34 (rel. unc. = 5.0e-08) m^2 kg s^(-1)
hbar        :	  1.0545716280000e-34 (rel. unc. = 5.0e-08) m^2 kg s^(-1)
m_P         :	  2.1764400000000e-08 (rel. unc. = 5.1e-05) kg
T_P         :	  1.4167850000000e+32 (rel. unc. = 5.0e-05) K
l_P         :	  1.6162520000000e-35 (rel. unc. = 5.0e-05) m
t_P         :	  5.3912400000000e-44 (rel. unc. = 5.0e-05) s

Electromagnetic constants: 

e           :	  1.6021764870000e-19 (rel. unc. = 2.5e-08) s A
e/h         :	  2.4179894540000e+14 (rel. unc. = 2.5e-08) m^(-2) kg^(-1) s^2 A
Phi_0       :	  2.0678336670000e-15 (rel. unc. = 2.5e-08) m^2 kg s^(-2) A^(-1)
G_0         :	  7.7480917004000e-05 (rel. unc. = 6.8e-10) m^(-2) kg^(-1) s^3 A^2
K_J         :	  4.8359789100000e+14 (rel. unc. = 2.5e-08) m^(-2) kg^(-1) s^2 A
R_K         :	  2.5812807557000e+04 (rel. unc. = 6.9e-10) m^2 kg s^(-3) A^(-2)
mu_B        :	  9.2740091500000e-24 (rel. unc. = 2.5e-08) m^2 A
mu_N        :	  5.0507832400000e-27 (rel. unc. = 2.6e-08) m^2 A

Physico-chemical constants: 

N_A         :	  6.0221417900000e+23 (rel. unc. = 5.0e-08) mol^(-1)
m_u         :	  1.6605387820000e-27 (rel. unc. = 5.0e-08) kg
F           :	  9.6485339900000e+04 (rel. unc. = 2.5e-08) s A mol^(-1)
R           :	  8.3144720000000e+00 (rel. unc. = 1.8e-06) m^2 kg s^(-2) K^(-1) mol^(-1)
k_B         :	  1.3806504000000e-23 (rel. unc. = 1.7e-06) m^2 kg s^(-2) K^(-1)
V_m         :	  2.2413996000000e-02 (rel. unc. = 1.7e-06) m^3 mol^(-1)
sigma_SB    :	  5.6704000000000e-08 (rel. unc. = 7.1e-06) kg s^(-3) K^(-4)
c_1         :	  3.7417711800000e-16 (rel. unc. = 5.1e-08) m^4 kg s^(-3)
c_2         :	  1.4387752000000e-02 (rel. unc. = 1.7e-06) m K
b           :	  2.8977685000000e-03 (rel. unc. = 1.8e-06) m K

Atomic and nuclear constants: 

alpha       :	  7.2973525376000e-03 (rel. unc. = 6.9e-10) dimensionless
R_infinity  :	  1.0973731568527e+07 (rel. unc. = 6.7e-12) m^(-1)
a_0         :	  5.2917720859000e-11 (rel. unc. = 6.8e-10) m
E_h         :	  4.3597439400000e-18 (rel. unc. = 5.0e-08) m^2 kg s^(-2)

    electron: 

<<<<<<< unit_example_19.cpp
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
mu_e/mu_p'  :   -658.228 dimensionless
mu_e/mu_n   :   960.92 dimensionless
mu_e/mu_d   :   -2143.92 dimensionless
mu_e/mu_hp  :   864.058 dimensionless
gamma_e     :   1.76086 kg^(-1) s A
=======
m_e         :	  9.1093821500000e-31 (rel. unc. = 4.9e-08) kg
m_e/m_mu    :	  4.8363317100000e-03 (rel. unc. = 2.5e-08) dimensionless
m_e/m_tau   :	  2.8756400000000e-04 (rel. unc. = 1.6e-04) dimensionless
m_e/m_p     :	  5.4461702177000e-04 (rel. unc. = 4.4e-10) dimensionless
m_e/m_n     :	  5.4386734459000e-04 (rel. unc. = 6.1e-10) dimensionless
m_e/m_d     :	  2.7244371093000e-04 (rel. unc. = 4.4e-10) dimensionless
m_e/m_alpha :	  1.3709335557000e-04 (rel. unc. = 4.2e-10) dimensionless
e/m_e       :	  1.7588201500000e+11 (rel. unc. = 2.5e-08) kg^(-1) s A
M_e         :	  5.4857990943000e-07 (rel. unc. = 4.2e-10) kg mol^(-1)
lambda_C    :	  2.4263102175000e-12 (rel. unc. = 1.4e-09) m
r_e         :	  2.8179402894000e-15 (rel. unc. = 2.1e-09) m
sigma_e     :	  6.6524585580000e-29 (rel. unc. = 4.1e-09) m^2
mu_e        :	 -9.2847637700000e-24 (rel. unc. = 2.5e-08) m^2 A
a_e         :	  1.1596521811100e-03 (rel. unc. = 6.4e-10) dimensionless
g_e         :	 -2.0023193043622e+00 (rel. unc. = 7.5e-13) dimensionless
mu_e/mu_mu  :	  2.0676698770000e+02 (rel. unc. = 2.5e-08) dimensionless
mu_e/mu_p   :	 -6.5821068480000e+02 (rel. unc. = 8.2e-09) dimensionless
mu_e/mu_pp  :	 -6.5822759710000e+02 (rel. unc. = 1.1e-08) dimensionless
mu_e/mu_n   :	  9.6092050000000e+02 (rel. unc. = 2.4e-07) dimensionless
mu_e/mu_d   :	 -2.1439234980000e+03 (rel. unc. = 8.4e-09) dimensionless
mu_e/mu_hp  :	  8.6405825700000e+02 (rel. unc. = 1.2e-08) dimensionless
gamma_e     :	  1.7608597700000e+11 (rel. unc. = 2.5e-08) kg^(-1) s A
>>>>>>> 1.4

    muon: 

m_mu        :	  1.8835313000000e-28 (rel. unc. = 5.8e-08) kg
m_mu/m_e    :	  2.0676828230000e+02 (rel. unc. = 2.5e-08) dimensionless
m_mu/m_tau  :	  5.9459200000000e-02 (rel. unc. = 1.6e-04) dimensionless
m_mu/m_p    :	  1.1260952610000e-01 (rel. unc. = 2.6e-08) dimensionless
m_mu/m_n    :	  1.1245451670000e-01 (rel. unc. = 2.6e-08) dimensionless
M_mu        :	  1.1342892560000e-04 (rel. unc. = 2.6e-08) kg mol^(-1)
lambda_C_mu :	  1.1734441040000e-14 (rel. unc. = 2.6e-08) m
mu_mu       :	 -4.4904478600000e-26 (rel. unc. = 3.6e-08) m^2 A
a_mu        :	  1.1659206900000e-03 (rel. unc. = 5.1e-07) dimensionless
g_mu        :	 -2.0023318414000e+00 (rel. unc. = 6.0e-10) dimensionless
mu_mu/mu_p  :	 -3.1833451370000e+00 (rel. unc. = 2.7e-08) dimensionless

    tau: 

m_tau       :	  3.1677700000000e-27 (rel. unc. = 1.6e-04) kg
m_tau/m_e   :	  3.4774800000000e+03 (rel. unc. = 1.6e-04) dimensionless
m_tau/m_mu  :	  1.6818300000000e+01 (rel. unc. = 1.6e-04) dimensionless
m_tau/m_p   :	  1.8939000000000e+00 (rel. unc. = 1.6e-04) dimensionless
m_tau/m_n   :	  1.8912900000000e+00 (rel. unc. = 1.6e-04) dimensionless
M_tau       :	  1.9076800000000e-03 (rel. unc. = 1.6e-04) kg mol^(-1)
lambda_C_tau:	  6.9772000000000e-16 (rel. unc. = 1.6e-04) m

    proton: 

<<<<<<< unit_example_19.cpp
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
mu_p'       :   1.41057e-26 m^2 A
gamma_p     :   2.67522e+08 kg^(-1) s A
gamma_p'    :   2.67515e+08 kg^(-1) s A
=======
m_p         :	  1.6726216370000e-27 (rel. unc. = 5.0e-08) kg
m_p/m_e     :	  1.8361526724700e+03 (rel. unc. = 4.4e-10) dimensionless
m_p/m_mu    :	  8.8802433900000e+00 (rel. unc. = 2.6e-08) dimensionless
m_p/m_tau   :	  5.2801200000000e-01 (rel. unc. = 1.6e-04) dimensionless
m_p/m_n     :	  9.9862347824000e-01 (rel. unc. = 4.6e-10) dimensionless
e/m_p       :	  9.5788339200000e+07 (rel. unc. = 2.5e-08) kg^(-1) s A
M_p         :	  1.0072764667700e-03 (rel. unc. = 9.9e-11) kg mol^(-1)
R_p         :	  8.7680000000000e-16 (rel. unc. = 7.9e-03) m
mu_p        :	  1.4106066620000e-26 (rel. unc. = 2.6e-08) m^2 A
g_p         :	  5.5856947130000e+00 (rel. unc. = 8.2e-09) dimensionless
mu_p/mu_n   :	 -1.4598980600000e+00 (rel. unc. = 2.3e-07) dimensionless
mu_pp       :	  1.4105704190000e-26 (rel. unc. = 2.7e-08) m^2 A
gamma_p     :	  2.6752220990000e+08 (rel. unc. = 2.6e-08) kg^(-1) s A
gamma_pp    :	  2.6751533620000e+08 (rel. unc. = 2.7e-08) kg^(-1) s A
>>>>>>> 1.4

    neutron: 

<<<<<<< unit_example_19.cpp
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
mu_n/mu_p'  :   -0.684997 dimensionless
gamma_n     :   1.83247e+08 kg^(-1) s A
=======
m_n         :	  1.6749272110000e-27 (rel. unc. = 5.0e-08) kg
m_n/m_e     :	  1.8386836605000e+03 (rel. unc. = 6.0e-10) dimensionless
m_n/m_mu    :	  8.8924840900000e+00 (rel. unc. = 2.6e-08) dimensionless
m_n/m_tau   :	  5.2874000000000e-01 (rel. unc. = 1.6e-04) dimensionless
m_n/m_p     :	  1.0013784191800e+00 (rel. unc. = 4.6e-10) dimensionless
lambda_C_n  :	  1.3195908951000e-15 (rel. unc. = 1.5e-09) m
M_n         :	  1.0086649159700e-03 (rel. unc. = 4.3e-10) kg mol^(-1)
mu_n        :	 -9.6623641000000e-27 (rel. unc. = 2.4e-07) m^2 A
g_n         :	 -3.8260854500000e+00 (rel. unc. = 2.4e-07) dimensionless
mu_n/mu_p   :	 -6.8497934000000e-01 (rel. unc. = 2.3e-07) dimensionless
mu_n/mu_pp  :	 -6.8499694000000e-01 (rel. unc. = 2.3e-07) dimensionless
gamma_n     :	  1.8324718500000e+08 (rel. unc. = 2.3e-07) kg^(-1) s A
>>>>>>> 1.4

    deuteron: 

m_d         :	  3.3435832000000e-27 (rel. unc. = 5.1e-08) kg
m_d/m_e     :	  3.6704829654000e+03 (rel. unc. = 4.4e-10) dimensionless
m_d/m_p     :	  1.9990075010800e+00 (rel. unc. = 1.1e-10) dimensionless
M_d         :	  2.0135532127240e-03 (rel. unc. = 3.9e-11) kg mol^(-1)
R_d         :	  2.1402000000000e-15 (rel. unc. = 1.3e-03) m
mu_d        :	  4.3307346500000e-27 (rel. unc. = 2.5e-08) m^2 A
mu_d/mu_e   :	 -4.6643455370000e-04 (rel. unc. = 8.4e-09) dimensionless
mu_d/mu_p   :	  3.0701220700000e-01 (rel. unc. = 7.8e-09) dimensionless
mu_d/mu_n   :	 -4.4820652000000e-01 (rel. unc. = 2.5e-07) dimensionless

    helion: 

m_h         :	  5.0064119200000e-27 (rel. unc. = 5.0e-08) kg

    alpha particle: 

m_alpha     :	  6.6446562000000e-27 (rel. unc. = 5.0e-08) kg
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
              << "mu_e/mu_B   :\t" << mu_e_over_mu_B << std::endl
              << "mu_e/mu_N   :\t" << mu_e_over_mu_N << std::endl
              << "a_e         :\t" << a_e << std::endl
              << "g_e         :\t" << g_e << std::endl
              << "mu_e/mu_mu  :\t" << mu_e_over_mu_mu << std::endl
              << "mu_e/mu_p   :\t" << mu_e_over_mu_p << std::endl
              << "mu_e/mu_p'  :\t" << mu_e_over_mu_p_prime << std::endl
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
              << "mu_p'       :\t" << mu_p_prime << std::endl
              << "gamma_p     :\t" << gamma_p << std::endl
              << "gamma_p'    :\t" << gamma_p_prime << std::endl
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
              << "mu_n/mu_p'  :\t" << mu_n_over_mu_p_prime << std::endl
              << "gamma_n     :\t" << gamma_n << std::endl
              << std::endl << "    deuteron: " << std::endl << std::endl
              << "m_d         :\t" << m_d << std::endl
              << "m_d/m_e     :\t" << m_d_over_m_e << std::endl
              << "m_d/m_p     :\t" << m_d_over_m_p << std::endl
              << "M_d         :\t" << M_d << std::endl
              << "R_d         :\t" << R_d << std::endl
              << "mu_d        :\t" << mu_d << std::endl
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
