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
#include "test.h"
#include "solve.h"
#include "checker.h"
#include "color.h"
#include "solve.h"
#include "mem.h"

bool Test_One_Case ( Coeff_Root *data )
{
$   Coeff_t func_coeffs = data->coeffs;

    Roots_t roots = {0} ;
    int n_roots = 0;
$
    if ( compare_value_min ( func_coeffs.a, 0 ) ) {  //

        n_roots = solve_linear ( &func_coeffs, &roots );

        if ( compare_value_min ( n_roots, data->roots.n_roots ) &&
             compare_value_min ( roots.x1, data->roots.x1 ) ) {

            print_color ( "Test OK\n", COLOR_GREEN );
        }
        else {

            print_color ( " x1  = %g, n_roots = %d\n", COLOR_RED, roots.x1, n_roots );
            print_color ( "expected:\n x1 = %g, n_roots = %d\n\n", COLOR_RED, data->roots.x1, data->roots.n_roots );

            return false;

        }
    }
    else {

        n_roots = solve_quadratic ( &func_coeffs, &roots );

        if ( compare_value_min ( roots.x1, data->roots.x1     ) &&
             compare_value_min ( roots.x2, data->roots.x2     ) &&
             compare_value_min ( n_roots, data->roots.n_roots ) ) {

            print_color ( "Test OK\n", COLOR_GREEN );
        }
        else {

            print_color ( "x1 = %g, x2 = %g, n_roots = %d\n", COLOR_RED, roots.x1, roots.x2, n_roots, data->roots.x1 );
            print_color ( "expected:\nx1 = %g, x2 = %g, n_roots = %d\n\n", COLOR_RED, data->roots.x2, data->roots.n_roots );

            return false;
        }
    }

    return true;
}

int Test_All_Cases ( )
{
$   int n_test_ok = 0;

$   Coeff_Root data[] = {
        { {  1,   6, 9 }, {  -3, -3, ROOT_ONE } },
        { {  0,   1, 1 }, {  -1, -1, ROOT_ONE } },
        { {  1,   5, 6 }, {  -3, -2, ROOT_TWO } },
        { { 10, 100, 0 }, { -10,  0, ROOT_TWO } },
        { {  0,   0, 0 }, {   0,  0, ROOT_ALL } },
        { {  1,   2, 3 }, {   0,  0, ROOT_ZER } },
    };

    const int N_TEST = sizeof (data) / sizeof (data[0]);

    for (int i = 0; i < N_TEST; ++i ) {

$       if ( Test_One_Case ( &data[i] ) ) {       // n_test
$           ++n_test_ok;
        }
    }
$   return n_test_ok;
}
