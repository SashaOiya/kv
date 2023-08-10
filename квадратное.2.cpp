#include <stdio.h>
#include <ctype.h>
#include <cmath>

double vvod ();

int main () {
    double a,b,c;      /* коэффициенты : ax^2 + bx + c = 0*/
    double D, x_1, x_2;
    a = vvod();
    if ( a == 0 )
        printf ( "non-quadratic function" );
    b = vvod();
    c = vvod();
    D = b * b - 4 * a * c;
    x_1 = ( -b - sqrt(D) ) / ( 2 * a );
    x_2 = ( -b + sqrt(D) ) / ( 2 * a );
    printf ( "root 1: %g\nroot 2: %g", x_1, x_2 );
    return 0;
}

/* vvod: */
double vvod () {
    int c, sign = 1;
    double s = 0;
    int ten = 1;
    while ( ( c = getchar() ) == ' ' || c == '\t' )     /* пропускаем пробелы и табул€ции */
        ;
    if ( c == '-' ) {       /* определ€ем знак */
        sign = -1;
        c = getchar();
    }
    for ( ; isdigit (c); c = getchar() )        /* вводим целую часть */
        s = s * 10 + ( c - '0' );
    if ( c == '.' )
        c = getchar() ;
    for ( ; isdigit(c); c = getchar() ) {       /* вводим дробную часть, если есть */
        s = s * 10 + ( c - '0' );
        ten = ten * 10;
    }
    s = ( sign * s ) / ten;
    return s ;
}
