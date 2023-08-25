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


int main ( )
{
    printf ( "Hi. This program solves both a quadratic equation and a linear one.\n"
             "Write 'help' to see the list of available functions:\n" );

    bool start_indicator = true;
    int equation_type = 0;

    do {
        equation_type = interface_input ( start_indicator );

        if ( equation_type == BYE  ) {

            return 0;
        }
    } while ( equation_type != LINEAR && equation_type != QUADRATIC );

    start_indicator = false;

    struct Coeff_t func_coeff = {};

    TEST();

    struct Roots_t   roots = {};
    enum N_Roots_t n_roots = ERR; // undef

    ASSERT ( &func_coeff.a );
    ASSERT ( &func_coeff.b );
    ASSERT ( &func_coeff.c );

    switch ( equation_type ) {
$       case LINEAR:
$           get_coeff ( "K", &func_coeff.b );
$           get_coeff ( "B", &func_coeff.c );
$           n_roots = solve_linear ( &func_coeff, &roots );
$
$           ASSERT ( &func_coeff.b );
$           ASSERT ( &func_coeff.c );

$           break;
$       case QUADRATIC:
$           get_coeff ( "A", &func_coeff.a );
$           get_coeff ( "B", &func_coeff.b );
$           get_coeff ( "C", &func_coeff.c );

$           n_roots = solve_quadratic ( &func_coeff, &roots );
$
$           ASSERT ( &func_coeff.a );
$           ASSERT ( &func_coeff.b );
$           ASSERT ( &func_coeff.c );

$           break;

        default:
            *(int*)0 = 0;
            break;
    }

    ASSERT ( &roots );

    output_roots ( &roots, n_roots );

$   do {
        equation_type = interface_input ( start_indicator );

        if ( equation_type == BYE  ) {

            return 0;
        }
$   } while ( equation_type != BYE );

    return 0;
}
