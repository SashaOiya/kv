#include <stdio.h>

#include <cmath>
#include <string.h>
#include <ctype.h>
#include "output.h"

void output_roots ( const Roots_t *roots, N_Roots_t n_roots )
{
    switch ( n_roots ) {
        case ROOT_ZER:
            printf ( "zero roots\n" );
            break;
        case ROOT_ONE:
            printf ( "one root : x = %g\n", roots->x1 );
            break;
        case ROOT_TWO:
            printf ( "roots : x1 = %g\tx2 = %g\n", roots->x1, roots->x2 );
            break;
        case ROOT_ALL:
            printf ( "all numbers\n" );
            break;
        case ROOT_ERR:
            printf ( " 'wtf' error\n" );
            *(int*)0 = 0;
            break;
        default:
            *(int*)0 = 0;
            break;
    }
    printf ( "\n" );
}



