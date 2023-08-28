#include <stdio.h>
#include <iostream>
#include <string.h>

#include "checker.h"
#include "input.h"
#include "duck_cat.h"
#include "mem.h"
#include "solve.h"
#include "color.h"


void get_one_coeff ( double *func_coeff)
{
    ASSERT ( func_coeff );

    *func_coeff = 0;

    const int MAX_BUF_VALUE = 257;
    bool incorrect_input = false,  overflow_indicator = false;
    static char buf[MAX_BUF_VALUE] = {0};
    static int n_duck = 0;
    double value = 0;

    print_color ( "input coefficient: ", COLOR_GREEN );

    do {
        if ( incorrect_input ) {

            print_duck ( ++n_duck );
        }

        my_memset ( buf, 0, strlen ( buf ) );

        incorrect_input = overflow_indicator = false;

        char *end = buf;
        int i = 0;

        ASSERT ( end );

        for ( int c = 0; ( c = getchar() ) != '\n' && c != EOF; ++i ) {

            buf[i] = (char)c;
            overflow_indicator = incorrect_input = buf_overflow ( MAX_BUF_VALUE, &i, incorrect_input );
        }

        value = strtod ( buf, &end ); /// cppref

        ASSERT ( end );

        if ( ( compare_value_min ( value, 0 ) && buf[0] != '0' ) || *end != '\0' ) {

            incorrect_input = true;
        }

        if ( errno == ERANGE ) {

            print_color ("range error, got ", COLOR_RED );
            errno = 0;
        }

    } while ( incorrect_input );

    *func_coeff = value;
}

void get_coeff ( const char *coeff_name, double *coeff_ptr )
{
    get_one_coeff ( coeff_ptr );

    printf ( "%c = %g\n", *coeff_name, *coeff_ptr );
}
