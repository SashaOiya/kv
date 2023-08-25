#ifndef TEST_H          //
#define TEST_H

#include "test.h"
#include "checker.h"

N_Roots_t solve_quadratic ( Coeff_t *func_coeff, Roots_t *roots );
N_Roots_t solve_linear ( Coeff_t *func_coeff, Roots_t *roots );
void check_pointer ( void *func_coeff, int line );

#endif // TEST_H

bool Test_One_Case ( Coeff_Root *data )
{
$   Coeff_t func_coeffs = data->coeffs;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    Roots_t roots = {0} ;
    int n_roots = 0;
$
    if ( fabs ( func_coeffs.a - 0 ) < epsilon ) {

        n_roots = solve_linear ( &func_coeffs, &roots );

        if ( fabs ( roots.x1 - 0 ) != fabs ( data->roots.x1 - 0 ) ||
             fabs ( n_roots - 0 )  != fabs ( data->roots.n_roots - 0 ) ) {

            SetConsoleTextAttribute ( hConsole, 4 );

            printf ( " x1  = %g, n_roots = %d\n", roots.x1, n_roots );
            printf ( "expected:\n x1 = %g, n_roots = %d\n\n", data->roots.x1, data->roots.n_roots );

            SetConsoleTextAttribute ( hConsole, 15 );

            return false;
        }
        else {

            SetConsoleTextAttribute ( hConsole, 10 );

            printf ( "Test OK\n" );

            SetConsoleTextAttribute ( hConsole, 15 );
        }
    }
    else {

        n_roots = solve_quadratic ( &func_coeffs, &roots );

        if ( roots.x1 != data->roots.x1 ||
             roots.x2 != data->roots.x2 ||
              n_roots != data->roots.n_roots ) {

            printf ( "x1 = %g, x2 = %g, n_roots = %d\n", roots.x1, roots.x2, n_roots, data->roots.x1 );
            printf ( "expected:\nx1 = %g, x2 = %g, n_roots = %d\n\n",data->roots.x2, data->roots.n_roots );

            return false;
        }
        else {

            printf ( "Test OK\n" );
        }
    }

    return true;
}

int Test_All_Cases ( )
{
$   int test_ok = 0;

$   Coeff_Root data[] = { { {  1,   6, 9 }, {  -3, -3, ONE_ROOT  } },
                          { {  0,   1, 1 }, {  -1, -1, ONE_ROOT  } },
                          { {  1,   5, 6 }, {  -3, -2, TWO_ROOTS } },
                          { { 10, 100, 0 }, { -10,  0, TWO_ROOTS } },
                          { {  0,   0, 0 }, {   0,  0, ROOTS_ALL } }
                        };

    const int N_TEST = sizeof (data) / sizeof (data[0]);

    for (int i = 0; i < N_TEST; ++i ) {

$       if ( Test_One_Case ( &data[i] ) ) {
$           ++test_ok;
        }
    }
$   return test_ok;
}
