#include "mem.h"
#include "checker.h"

void check_pointer ( void *func_coeff, int line )
{
    if ( func_coeff == nullptr ) {

        printf ( "line number %d\n", line );
        *(int*)0 = 0;
    }
}

void my_memset ( void *s, const char number, const size_t value )
{
    ASSERT ( s );

    char *val = (char *)s;

    for ( size_t i = 0 ; i < value; ++i ) {
        *( val + i ) = number;
    }
}

bool buf_overflow ( const int MAX_BUF_VALUE, int *i, bool n_overflow )
{
    if ( *i + 1 > MAX_BUF_VALUE && n_overflow == 0 ) {

        printf ( "buffer is full\n" );

        *i = 0;

        return ++n_overflow;
    }
    else if ( *i + 1 > MAX_BUF_VALUE && n_overflow == true ) {

        *i = 0;
    }

   return n_overflow;
}

