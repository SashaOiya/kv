#include "checker.h"
#include "solve.h"

void check_pointer ( void *func_coeff, int line );

N_Roots_t solve_linear ( Coeff_t *func_coeff, Roots_t *roots )
{
    if ( fabs ( func_coeff->b - 0 ) >= epsilon ) {

        roots->x1 = roots->x2 = -func_coeff->c / func_coeff->b;

        compar_zero ( &( roots->x1 ) );
        compar_zero ( &( roots->x2 ) );

        return ONE_ROOT;
    }
    else if ( fabs ( func_coeff->b - 0 ) < epsilon &&
              fabs ( func_coeff->c - 0 ) >= epsilon ) {

        roots->x1 = roots->x2 = 0;

        return ROOT_ZERO;
    }
    else {

        roots->x1 = roots->x1 = 0;

        return ROOTS_ALL;
    }
}

N_Roots_t solve_quadratic ( Coeff_t *func_coeff, Roots_t *roots )
{
    double D = func_coeff->b * func_coeff->b - 4 * func_coeff->a * func_coeff->c;
    compar_zero ( &D );

    if ( fabs ( func_coeff->a - 0 ) < epsilon ) {
// TODO: blue text
        printf ( "Are you stupid?!?!?! THIS IS QUADRATIC EQUATION !!!\n");

        return ERR;
    }
    if ( D < 0 ) {

        return ROOT_ZERO;
    }
    else if ( D > 0 ) {

        double radical = sqrt ( D );

        roots->x1 = ( -func_coeff->b - radical ) / ( 2 * func_coeff->a );
        roots->x2 = ( -func_coeff->b + radical ) / ( 2 * func_coeff->a );
    }
    else if ( fabs ( D - 0 ) < epsilon ) {

        roots->x1 = roots->x2 = -func_coeff->b / ( 2 * func_coeff->a );

        compar_zero ( &( roots->x1 ) );
        compar_zero ( &( roots->x2 ) );

        return ONE_ROOT;
    }

    return TWO_ROOTS;
}

void compar_zero ( double *value )
{
    ASSERT ( value );

    if ( fabs ( *value - 0 ) < epsilon && fabs ( *value - 0 ) > -epsilon ) {

        *value = 0;
    }
}
