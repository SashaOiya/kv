#include <stdio.h>

#include "checker.h"
#include "duck_cat.h"
#include "mem.h"
#include "solve.h"
#include "input.h"
#include "output.h"
#include "test.h"
#include "color.h"

int main ( )
{
    print_color ( "Hi. This program solves both a quadratic equation and a linear one.\n"
                  "Write 'help' to see the list of available functions:\n", COLOR_BLUE );

    bool start_indicator = true;
    int equation_type = 0;

    do {
         equation_type = interface_input ( start_indicator );

        if ( equation_type == MODE_BYE  ) {

            return 0;
        }
    } while ( equation_type != MODE_LINEAR &&
              equation_type != MODE_QUADRATIC );

    start_indicator = false;

    struct Coeff_t func_coeff = { 0, 0, 0 };

    TEST();

    struct Roots_t   roots = { 0, 0, 0 };
    enum N_Roots_t n_roots = ROOT_ERR;

    do {
        switch ( equation_type ) {
$           case MODE_LINEAR:
$               get_coeff ( "K", &func_coeff.b );
$               get_coeff ( "B", &func_coeff.c );

$               n_roots = solve_linear ( &func_coeff, &roots );

$               break;
$           case MODE_QUADRATIC:
$               get_coeff ( "A", &func_coeff.a );
$               get_coeff ( "B", &func_coeff.b );
$               get_coeff ( "C", &func_coeff.c );

$               n_roots = solve_quadratic ( &func_coeff, &roots );

$               break;
            default:
                printf ( "sorry, unexpected error\n" );
                *(int*)0 = 0;
                break;
        }

    } while ( n_roots == ROOT_ERR );

    output_roots ( &roots, n_roots );

    print_color ( "Write 'help' to see the list of available functions:\n", COLOR_BLUE );

$   do {
        equation_type = interface_input ( start_indicator );

$   } while ( equation_type != MODE_BYE );

    return 0;
}
