#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <cmath>

struct num_roots {
    const int root_zero = 0;
    const int one_root = 1;
    const int two_roots = 2;
    const int root_all = 3;
};

struct coeff {
    double a = 0;
    float b = 0;
    float c = 0;
};


coeff get_coeff ( coeff coeff_func );
int solve ( coeff coeff_func, float *x1, float *x2 );
void put_coeff ( float *x1, float *x2, int solve );

int main()
{
    struct coeff coeff_func;        /* coefficients : ax^2 + bx + c = 0*/
    coeff_func = get_coeff ( coeff_func );

    float x1, x2;
    x1 = x2 = 0;

    put_coeff ( &x1, &x2, solve ( coeff_func, &x1, &x2 ) );

    return 0;
}

coeff get_coeff( coeff coeff_func )
{
    int c, i, indicator = 0;
    i = 0; //
    char s[100];

    do {
        while ( i > 0 ) {
            s[--i] = 0;
        }

        for ( i = 0, indicator = 0; ( c = getchar () ) != '\n'; ++i )  {
            if ( isdigit ( c ) || c == '.' ) {
                s[i] = c;
            }
            else if ( isalpha ( c ) || c == ' ' || c == '\t'  ) {
                printf ( "lox \n");
                indicator = 1;  //
            }
        }
    } while ( indicator == 1 );

    coeff_func.a = atof(s);
    printf ( "A = %g\n", coeff_func.a  );

    printf ( "B = " );
    scanf ( "%f", &coeff_func.b );

    printf ( "C = " );
    scanf ( "%f", &coeff_func.c );

    return coeff_func;
}

int solve ( coeff coeff_func, float *x1, float *x2 )
{
    struct num_roots volume;
    if ( coeff_func.a == 0 )
    {
        if ( coeff_func.b != 0 && ( coeff_func.c != 0 || coeff_func.c == 0 ) ) {
            *x1 = *x2 = -coeff_func.c / coeff_func.b;

            return volume.one_root;
        }
        else if ( coeff_func.b == 0 && coeff_func.c != 0 ) {

            return volume.root_zero;
        }
        else {

            return volume.root_all;
        }
    }
    else
    {
        float D = pow ( coeff_func.b, 2 ) - 4 * coeff_func.a * coeff_func.c;

        if ( D < 0 ) {

            return volume.root_zero;
        }
        else {
            *x1 = ( -coeff_func.b - sqrt(D) ) / ( 2 * coeff_func.a );
            *x2 = ( -coeff_func.b + sqrt(D) ) / ( 2 * coeff_func.a );
        }
    }

    return volume.two_roots;
}

void put_coeff ( float *x1, float *x2, int solve )   //switch
{
    if ( solve == 0 ) {
        printf ( "zero roots" );
    }
    else if ( solve == 1 ) {
        printf ( "one root : x = %g", *x1 );
    }
    else if ( solve == 2 ) {
        printf ( "roots : x1 = %g\tx2 = %g", *x1, *x2 );
    }
    else if ( solve == 3 ) {
        printf ( "all numbers" );
    }
}
