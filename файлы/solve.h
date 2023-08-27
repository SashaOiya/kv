#ifndef SOLVE_H
#define SOLVE_H

struct Coeff_t {
    double a;
    double b;
    double c;
};

enum N_Roots_t {
    ROOT_ZER = 0,
    ROOT_ONE = 1,
    ROOT_TWO = 2,
    ROOT_ALL = 3,
    ROOT_ERR = 4
};

struct Roots_t {
    double x1;
    double x2;
    double n_roots;
};

const double epsilon = 1e-6; // CAPS

/*
    @brief Solves


*/
N_Roots_t solve_linear ( Coeff_t *func_coeff, Roots_t *roots );
N_Roots_t solve_quadratic ( Coeff_t *func_coeff, Roots_t *roots );
void compar_zero ( double *value );
bool compare_value_min ( double x1, double x2);
bool compare_value_max ( double x1, double x2);
void fix_zero ( double *x );

#endif // SOLVE_H
