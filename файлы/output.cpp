#include "output.h"

void output_roots ( const Roots_t *roots, N_Roots_t n_roots )
{
    switch ( n_roots ) {
        case ROOT_ZERO:
            printf ( "zero roots" );
            break;
        case ONE_ROOT:
            printf ( "one root : x = %g", roots->x1 );
            break;
        case TWO_ROOTS:
            printf ( "roots : x1 = %g\tx2 = %g", roots->x1, roots->x2 );
            break;
        case ROOTS_ALL:
            printf ( "all numbers" );
            break;
        case ERR:
            printf ( " 'wtf' error" );
            *(int*)0 = 0;
            break;
        default:
            *(int*)0 = 0;
            break;
    }
    printf ( "\n" );
}
