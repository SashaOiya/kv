#include <stdio.h>
#include <ctype.h>
#include <cmath>

int on = 1;

void input( float *, float *, float * );
void algorithm( float ,float , float , float *, float * );
void output( float *, float* );

int main()
{
    float a, b, c;      /* coefficients : ax^2 + bx + c = 0*/
    a = b = c = 0;

    input( &a, &b, &c );

    float x1, x2;
    x1 = x2 = 0;       /*проблемы с выводом несуществующий корней*/

    algorithm( a, b, c, &x1, &x2 );

    output( &x1, &x2 );

    return 0;
}

void input( float *a, float *b, float *c )
{
    printf ( "A = " );
    scanf ( "%f", a );

    printf ( "B = " );
    scanf ( "%f", b );

    printf ( "C = " );
    scanf ( "%f", c );
}

void algorithm ( float a,float b, float c, float *x1, float *x2 )
{
    if ( a == 0 )
    {
        printf ( "non-quadratic function : \n" );

        if ( ( b != 0 && c != 0 ) || ( b != 0 && c == 0 ) ) {
            *x1 = *x2 = -c / b ;
        }
        else if ( b == 0 && c != 0 ) {
            printf ( "zero roots ");
            extern int on;
            on = 0;
        }
        else {
            printf ( "all numbers" );
        }
    }
    else
    {
        float D = pow( b, 2 ) - 4 * a * c;

        if ( D < 0 ) {
            printf ( "zero roots" );
            on = 0;
        }
        else {
            *x1 = ( -b - sqrt(D) ) / ( 2 * a );
            *x2 = ( -b + sqrt(D) ) / ( 2 * a );
        }
    }
}

void output( float *x1, float *x2 )
{
    extern int n;

    if ( *x1 == *x2  && on == 1 ) {
        printf ( "one root : x = %g", *x1 );
    }
    else if ( *x1 != *x2 && on == 1 ) {
        printf ( "roots : x1 = %g\tx2 = %g", *x1, *x2 );
    }
}
