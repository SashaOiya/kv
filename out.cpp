#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

enum N_Roots_t {
    ROOT_ZERO,
    ONE_ROOT,
    TWO_ROOTS,
    ROOTS_ALL
};

struct Coeff_t {
    double a = 0;
    double b = 0;
    double c = 0;
};

struct Roots_t {                 //
    double x1 = 0;
    double x2 = 0;
};

void error_checking ( double *func_coeff, int line );
int solve ( Coeff_t *func_coeff, Roots_t *roots );   //
void output_roots ( Roots_t *roots, int n_roots );

int solve ( Coeff_t *func_coeff, Roots_t *roots )
{
    double epsilon = 0.000001;

    if ( fabs ( func_coeff->a - 0 ) < epsilon )
    {
        if ( fabs ( func_coeff->b - 0 ) >= epsilon ) {
            roots->x1 = roots->x2 = -func_coeff->c / func_coeff->b;

            return ONE_ROOT;
        }
        else if ( fabs ( func_coeff->b - 0 ) < epsilon && fabs ( func_coeff->c - 0 ) >= epsilon) {

            return ROOT_ZERO;
        }
        else {

            return ROOTS_ALL;
        }
    }
    else
    {
        double D = func_coeff->b * func_coeff->b - 4 * func_coeff->a * func_coeff->c;

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

            return ONE_ROOT;
        }
    }

    return TWO_ROOTS;
}

void error_checking ( double *func_coeff, int line )
{
    if ( func_coeff == nullptr ) {
        printf( "line number %d\n", line );
        abort();
    }
}

void output_roots ( Roots_t *roots, int n_roots )
{
    switch ( n_roots) {
        case ROOT_ZERO :
            printf ( "zero roots" );
            break;
        case ONE_ROOT :
            printf ( "one root : x = %g", roots->x1 );
            break;
        case TWO_ROOTS :
            printf ( "roots : x1 = %g\tx2 = %g", roots->x1, roots->x2 );
            break;
        case ROOTS_ALL :
            printf ( "all numbers" );
            break;
        default :
            // error
            break;
    }
    printf ( "\n" );
}
