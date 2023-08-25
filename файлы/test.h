#include <stdio.h>
#include <cmath>
#include <windows.h>

struct Coeff_t {
    double a;
    double b;
    double c;
};

struct Roots_t {
    double x1;
    double x2;
    double n_roots;     //
};

enum N_Roots_t {
    ROOT_ZERO,
    ONE_ROOT ,
    TWO_ROOTS,
    ROOTS_ALL,
    ERR                  //
};

struct Coeff_Root {
    Coeff_t coeffs;
    Roots_t roots;
};

bool Test_One_Case ( Coeff_Root *data );
int Test_All_Cases ( );
