#include <stdio.h>

struct Roots_t {
    double x1 = 0;
    double x2 = 0;
};

enum N_Roots_t {
    ROOT_ZERO = 0,
    ONE_ROOT  = 1,
    TWO_ROOTS = 2,
    ROOTS_ALL = 3,
    ERR       = 4
};

void output_roots ( const Roots_t *roots, N_Roots_t n_roots );
