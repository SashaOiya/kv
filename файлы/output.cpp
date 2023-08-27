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
#include "output.h"

void output_roots ( const Roots_t *roots, N_Roots_t n_roots )
{
    switch ( n_roots ) {
        case ROOT_ZER:
            printf ( "zero roots" );
            break;
        case ROOT_ONE:
            printf ( "one root : x = %g", roots->x1 );
            break;
        case ROOT_TWO:
            printf ( "roots : x1 = %g\tx2 = %g", roots->x1, roots->x2 );
            break;
        case ROOT_ALL:
            printf ( "all numbers" );
            break;
        case ROOT_ERR:
            printf ( " 'wtf' error" );
            *(int*)0 = 0;
            break;
        default:
            *(int*)0 = 0;
            break;
    }
    printf ( "\n" );
}



