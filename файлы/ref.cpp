#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <cmath>
#include <stdarg.h>
#include <string.h>
#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <cmath>
#include <string.h>
#include <ctype.h>

bool buf_overflow_cat ( const int MAX_BUF_VALUE, int *i, bool n_overflow )
{
    if ( *i + 1 > MAX_BUF_VALUE && n_overflow == 0 ) {
        printf ( "buffer is full\n" );
        *i = 0;
        return ++n_overflow;
    }
    else if ( *i + 1 > MAX_BUF_VALUE && n_overflow == true ) {
        *i = 0;
    }
   return n_overflow;
}
                                                                 //
void buf_overflow_duck ( const int MAX_BUF_VALUE, int *i, bool *overflow_indicator, bool *incorrect_input )
{
    if ( *i + 1 > MAX_BUF_VALUE && *overflow_indicator == false ) {
        printf ( "buffer is full\n" );
        *i = 0;
        *overflow_indicator = true;
        *incorrect_input = true;
    }
    else if ( *i + 1 > MAX_BUF_VALUE && *overflow_indicator == true ) {    //
        *i = 0;
    }
}

#include <stdio.h>

#include "checker.h"

//!@param [in] a lox

struct Coeff_t {
    double a = 0;
    double b = 0;
    double c = 0;
};

struct Roots_t {
    double x1 = 0;
    double x2 = 0;
};

enum Mode_t {
    LINEAR,     //
    QUADRATIC,
    Error,
    START,
    HELP,
    BYE,
    OPTION_MEOW
};

enum N_Roots_t {
    ROOT_ZERO = 0,
    ONE_ROOT  = 1,
    TWO_ROOTS = 2,
    ROOTS_ALL = 3,
    ERR       = 4
};

Mode_t interface ();
void print_duck ( const int n_duck );
void get_one_coeff ( double *func_coeff);
void get_coeff ( const char *coeff, double *n_coeff );
void check_pointer ( void *func_coeff, int line );
void my_memset ( void *s, const char number, const size_t value );
void output_roots ( const Roots_t *roots, N_Roots_t n_roots );
N_Roots_t solve_quadratic ( Coeff_t *func_coeff, Roots_t *roots );
N_Roots_t solve_linear ( Coeff_t *func_coeff, Roots_t *roots );
bool Test_One_Case ( double a, double b, double c, int n_roots_ref, double x1_ref, double x2_ref );
int Test_All_Cases ( );
Mode_t interface_input ( bool start_indicator );
