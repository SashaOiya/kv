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
#include "mem.h"
#include "checker.h"
#include "color.h"

void check_pointer ( void *func_coeff, int line )
{
    if ( func_coeff == nullptr ) {

        print_color ( "line number %d\n", COLOR_RED, line );
        *(int*)0 = 0;
    }
}

void my_memset ( void *val, const char number, const size_t value )
{
    ASSERT ( val );

    for ( size_t i = 0 ; i < value; ++i ) {

        *( (char *)val + i ) = number;
    }
}

bool buf_overflow ( const int MAX_BUF_VALUE, int *input_element_number, bool n_overflow )
{
    ASSERT ( input_element_number );

    if ( *input_element_number + 1 > MAX_BUF_VALUE && n_overflow == false ) {

        print_color ( "buffer is full\n", COLOR_BLUE );

        *input_element_number = 0;

        return ++n_overflow;
    }
    else if ( *input_element_number + 1 > MAX_BUF_VALUE && n_overflow == true ) {

        *input_element_number = 0;
    }

   return n_overflow;
}

