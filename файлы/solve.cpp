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
#include "checker.h"
#include "solve.h"
#include "mem.h"
#include "color.h"

bool compare_value_min ( double x1, double x2)
{

    return fabs ( x1 - x2 ) < EPSILON;
}

bool compare_value_max ( double x1, double x2)
{

    return fabs ( x1 - x2 ) >= EPSILON;
}

void fix_zero ( double *x )
{
    *x = ( fabs ( *x - 0 ) < EPSILON ) ? 0: *x;
}

N_Roots_t solve_linear ( Coeff_t *func_coeff, Roots_t *roots )
{
    ASSERT ( func_coeff );
    ASSERT ( roots );

    roots->x1 = 0;
    roots->x2 = 0;

    if ( compare_value_max ( func_coeff->b, 0 ) ) {

        roots->x1 = roots->x2 = -func_coeff->c / func_coeff->b;

        fix_zero ( &roots->x1 );
        fix_zero ( &roots->x2 );

        return ROOT_ONE;
    }
    else if ( compare_value_min ( func_coeff->b, 0 ) &&
              compare_value_max ( func_coeff->c, 0 )  ) {

        return ROOT_ZER;
    }
    else {

        return ROOT_ALL;
    }
}

N_Roots_t solve_quadratic ( Coeff_t *func_coeff, Roots_t *roots )
{
    double D = func_coeff->b * func_coeff->b - 4 * func_coeff->a * func_coeff->c;

    fix_zero ( &D );

    if ( compare_value_min ( func_coeff->a, 0 ) ) {

        print_color ( "Are you stupid?!?!?! THIS IS QUADRATIC EQUATION !!!\n", COLOR_BLUE );

        return ROOT_ERR;
    }
    if ( compare_value_min ( D, 0 ) ) {

        roots->x1 = roots->x2 = -func_coeff->b / ( 2 * func_coeff->a );

        fix_zero ( &roots->x1 );
        fix_zero ( &roots->x2 );

        return ROOT_ONE;
    }
    else if ( D > 0 ) {

        double sqrt_d = sqrt ( D );

        roots->x1 = ( -func_coeff->b - sqrt_d ) / ( 2 * func_coeff->a );
        roots->x2 = ( -func_coeff->b + sqrt_d ) / ( 2 * func_coeff->a );
    }
    else if ( D < 0 ) {

        return ROOT_ZER;
    }

    return ROOT_TWO;
}




