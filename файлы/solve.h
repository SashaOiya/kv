#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <cmath>
#include <stdint.h>

enum N_Roots_t {
    ROOT_ZERO = 0,
    ONE_ROOT  = 1,
    TWO_ROOTS = 2,
    ROOTS_ALL = 3,
    ERR       = 4
};

struct Coeff_t {
    double a = 0;
    double b = 0;
    double c = 0;
};

struct Roots_t {
    double x1 = 0;
    double x2 = 0;
};

N_Roots_t solve_linear ( Coeff_t *func_coeff, Roots_t *roots );
N_Roots_t solve_quadratic ( Coeff_t *func_coeff, Roots_t *roots );
void compar_zero ( double *value );
