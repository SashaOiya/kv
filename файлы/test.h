#ifndef TEST_H
#define TEST_H

#include "solve.h"

//{----------------------------------------------------------------------------------------
//!
//! Structure including the structure of roots and coefficients
//!
//}-----------------------------------------------------------------------------------------
struct Coeff_Root {
    Coeff_t coeffs;
    Roots_t roots;
};

//{----------------------------------------------------------------------------------------
//! Does one test. Compares the return value from the solution with the reference solution
//!
//! @see N_Roots_t solve_quadratic ( Coeff_t *func_coeff, Roots_t *roots )
//! @see N_Roots_t solve_quadratic ( Coeff_t *func_coeff, Roots_t *roots )
//! @see bool compare_value_max ( double x1, double x2)
//! @see bool compare_value_min ( double x1, double x2)
//! @see void print_color ( const char *c, enum Color_t COLOR, ... )
//!
//! @param data Pointer to the structure of reference coefficients and roots
//! @param n_test Test number
//!
//! @note Writes "test ok" if the value from the solution coincides with the reference valu;
//! @note Writes the roots and the number of roots from the solution and from the reference.
//!
//}-----------------------------------------------------------------------------------------
bool Test_One_Case ( Coeff_Root *data, int n_test );

//{-----------------------------------------------------------------------------------------
//!
//! The function does not accept any parameters
//!
//! Passes pre-entered values to the "Test_One_Case" function
//!
//! @see bool Test_One_Case ( Coeff_Root *data )
//!
//! @note Displays the number of successfully completed tests
//!
//}-----------------------------------------------------------------------------------------
int Test_All_Cases ( );

#endif // TEST_H
