#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <cmath>

enum num_roots {
    root_zero,
    one_root,
    two_roots,
    root_all
};

struct Coeff_t {
    double a = 0;
    double b = 0;
    double c = 0;
};

double get_one_coeff ( );
Coeff_t get_all_coeff ( Coeff_t func_coeff );
int solve ( double *func_coeff_a, double *func_coeff_b, double *func_coeff_c, float *x1, float *x2 );
void output_coeff ( float *x1, float *x2, int solution );

int main()
{
    struct Coeff_t func_coeff;      /* coefficients : ax^2 + bx + c = 0*/
    func_coeff = get_all_coeff ( func_coeff );

    float x1, x2;
    x1 = x2 = 0;

    int solution = solve ( &func_coeff.a, &func_coeff.b, &func_coeff.c, &x1, &x2 );
    output_coeff ( &x1, &x2, solution );

    return 0;
}

void get_one_coeff ( double *func_coeff )
{
    int c, i, num, indicator = 0;
    i = 0;
    num = 0;
    char s[100];

    do {
        while ( i > 0 ) {
            s[--i] = 0;
        }

        for ( i = 0, indicator = 0, num = 0; ( c = getchar () ) != '\n'; ++i ) {
            if ( isdigit ( c ) )
            {
                s[i] = c;
            }
            else if ( c == '.' ) {
                if ( num == 0 ) {
                    s[i] = 0;
                    ++num;
                }
                else if ( num != 0 ) {
                    indicator = 1;
                }
            }
            else if ( isalpha ( c ) || c == ' ' || c == '\t'  ) {
                indicator = 1;
            }
        }
        if ( indicator == 1 ) {
            printf ( "incorrect input\n" );
        }
    } while ( indicator == 1 );

    *func_coeff = atof(s);

}

Coeff_t get_all_coeff ( Coeff_t func_coeff )
{
    get_one_coeff ( &func_coeff.a );
    printf ( "A = %g\n", func_coeff.a );

    get_one_coeff ( &func_coeff.b );
    printf ( "B = %g\n", func_coeff.b );

    get_one_coeff ( &func_coeff.c );
    printf ( "C = %g\n", func_coeff.c );

    return func_coeff;
}

int solve ( double *func_coeff_a, double *func_coeff_b, double *func_coeff_c, float *x1, float *x2 )
{
    enum num_roots volume;

    if ( *func_coeff_a == 0 )
    {
        if ( *func_coeff_b != 0 && ( *func_coeff_c != 0 || *func_coeff_c == 0 ) ) {
            *x1 = *x2 = -*func_coeff_c / *func_coeff_b;

            return one_root;     // b = 0
        }
        else if ( *func_coeff_b == 0 && *func_coeff_c != 0 ) {

            return root_zero;
        }
        else {

            return root_all;
        }
    }
    else
    {
        float D = pow ( *func_coeff_b, 2 ) - 4 * *func_coeff_a * *func_coeff_c;

        if ( D < 0 ) {

            return root_zero;
        }
        else {
            *x1 = ( -*func_coeff_b - sqrt(D) ) / ( 2 * *func_coeff_a );
            *x2 = ( -*func_coeff_b + sqrt(D) ) / ( 2 * *func_coeff_a );
        }
    }

    return two_roots;
}

void output_coeff ( float *x1, float *x2, int solution )
{
    enum num_roots volume;

    if ( solution == root_zero ) {
        printf ( "zero roots" );
    }
    else if ( solution == one_root ) {
        printf ( "one root : x = %g", *x1 );
    }
    else if ( *x1 == *x2 ) {
        printf ( "one root : x = %g", *x2 );
    }
    else if ( solution == two_roots ) {
        printf ( "roots : x1 = %g\tx2 = %g", *x1, *x2 );
    }
    else if ( solution == root_all ) {
        printf ( "all numbers" );
    }

}
