#ifndef SOLVE_H
#define SOLVE_H

//{----------------------------------------------------------------------------
//!
//! The structure of the values of the coefficients of the equation
//!
//}----------------------------------------------------------------------------
struct Coeff_t {
    double a;
    double b;
    double c;
};

//{----------------------------------------------------------------------------
//!
//! Enumeration of the number of roots
//!
//}----------------------------------------------------------------------------
enum N_Roots_t {
    ROOT_ZER = 0,
    ROOT_ONE = 1,
    ROOT_TWO = 2,
    ROOT_ALL = 3,
    ROOT_ERR = 4
};


//{----------------------------------------------------------------------------
//!
//! Structure of values and number of roots
//!
//}----------------------------------------------------------------------------

struct Roots_t {
    double x1;
    double x2;
    double n_roots;
};

//{----------------------------------------------------------------------------
//!
//! A constant for comparing numbers
//!
//}----------------------------------------------------------------------------

const double EPSILON = 1e-6;

//{----------------------------------------------------------------------------
//!
//! The function solves the linear equation
//!
//! @param *func_coeff Pointer to an element of the coefficient structure
//! @param *roots Pointer to a root structure element
//!
//! @note  Returns the number of roots of the equation.
//! @note  Passes new values to the elements of the root structure
//!
//}----------------------------------------------------------------------------
N_Roots_t solve_linear ( Coeff_t *func_coeff, Roots_t *roots );

//{----------------------------------------------------------------------------
//!
//! The function solves the quadratic equation
//!
//! @see bool compare_value_max ( double x1, double x2)
//! @see bool compare_value_min ( double x1, double x2)
//!
//! @param *func_coeff Pointer to an element of the coefficient structure
//! @param *roots Pointer to a root structure element
//!
//! @note  Returns the number of roots of the equation.
//! @note  Passes new values to the elements of the root structure
//!
//}----------------------------------------------------------------------------
N_Roots_t solve_quadratic ( Coeff_t *func_coeff, Roots_t *roots );

//{----------------------------------------------------------------------------
//!
//! The function compares two values
//!
//! @see bool compare_value_min ( double x1, double x2)
//! @see void fix_zero ( double *x )
//!
//! @param x1 The first  value being compared
//! @param x2 The second value being compared
//!
//! @note  Returns true if the values are equal.
//! @note  Returns false if the values are not equal
//!
//}----------------------------------------------------------------------------
bool compare_value_min ( double x1, double x2);

//{----------------------------------------------------------------------------
//!
//! The function compares two values
//!
//! @param x1 The first  value being compared
//! @param x2 The second value being compared
//!
//! @note  Returns true  if the values are not equal.
//! @note  Returns false if the values are equal
//!
//}----------------------------------------------------------------------------
bool compare_value_max ( double x1, double x2);

//{----------------------------------------------------------------------------
//!
//! The function compares the value of a variable with zero
//!
//! @param *x1 Pointer to the value being compared
//!
//! @note  If the value of a variable is close to zero,
//!        then assigns the value 0 to this variable
//!
//}----------------------------------------------------------------------------
void fix_zero ( double *x );

#endif // SOLVE_H
