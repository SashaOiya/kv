#include <stdio.h>

#include <cmath>
#include <string.h>
#include <ctype.h>
#include "output.h"
#include "color.h"

void output_roots ( const Roots_t *roots, N_Roots_t n_roots )
{
    switch ( n_roots ) {
        case ROOT_ZER:
            print_color ( "zero roots\n", COLOR_BLUE );
            break;
        case ROOT_ONE:
            print_color ( "one root : x = %g\n", COLOR_BLUE, roots->x1 );
            break;
        case ROOT_TWO:
            print_color ( "roots : x1 = %g\tx2 = %g\n", COLOR_BLUE, roots->x1, roots->x2 );
            break;
        case ROOT_ALL:
            print_color ( "roots are all numbers\n", COLOR_BLUE );
            break;
        case ROOT_ERR:
            print_color ( " 'wtf' error\n", COLOR_BLUE );
            *(int*)0 = 0;
            break;
        default:
            *(int*)0 = 0;
            break;
    }
    printf ( "\n" );
}



