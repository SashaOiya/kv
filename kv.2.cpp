#include <stdio.h>
#include <stdlib.h>              // error 1) nullptr +
#include <ctype.h>               //         2)
#include <cmath>
#include <stdarg.h>
#include <string.h>
#include <iostream>
#include <stdint.h>

const int MAX_BUF_VALUE = 5;

// TODO: interface

#define DEBUG

#ifdef DEBUG
    #define ASSERT( a ); check_pointer ( a, __LINE__ )
#else
    #defune ASSERT(a) ;
#endif

enum N_Roots_t {        // enum bla {] bla;
    ROOT_ZERO,
    ONE_ROOT ,
    TWO_ROOTS,
    ROOTS_ALL
};

struct Coeff_t {
    double a = 0;
    double b = 0;
    double c = 0;
};

struct Roots_t {
    double x1 = 0;
    double x2 = 0;
};

enum Mode {
    LINER,
    QUADRATIC
};

// struct errors

Mode interface ();
void print_duck ( int n_duck );
void get_one_coeff ( double *func_coeff);
void check_pointer ( void *func_coeff, int line );
void my_memset ( void *s, char number, size_t value );
void input_coeffs ( Coeff_t *func_coeff ); //, const int *choice );
void output_roots ( const Roots_t *roots, N_Roots_t n_roots );

N_Roots_t solve ( Coeff_t *func_coeff, Roots_t *roots ); //, const int *choice );

int main ( int argc, char *argv[] )
{    // FIXE:
    //const int choice = interface ();            // вместо утки кота

    struct Coeff_t func_coeff;      /* coefficients : ax^2 + bx + c = 0*/
    input_coeffs ( &func_coeff ); //, &choice );

    struct Roots_t roots;

    enum N_Roots_t n_roots = solve ( &func_coeff, &roots ); //, &choice );

    ASSERT ( &func_coeff.a );
    ASSERT ( &func_coeff.b );
    ASSERT ( &func_coeff.c );

    output_roots ( &roots, n_roots );

    return 0;
}

void get_one_coeff ( double *func_coeff)
{
    ASSERT ( func_coeff );

    bool incorrect_input = false;
    static char buf[MAX_BUF_VALUE] = {0};
    static int n_duck = 0;
    double value = 0;

    printf ( "input coefficient: " );

    do {
        my_memset ( buf, 0, sizeof ( buf ) );

        int c;
        char *end = buf;

        ASSERT ( end );

        scanf ( "%s", &buf );
        if ( strlen ( buf ) > MAX_BUF_VALUE ) {
            incorrect_input = true;
            printf ( "buffer is full\n" );
        }
        value = strtod( &buf[0], &end);

        ASSERT ( end );

        if ( value == 0 || *end != '\0' ) {
            incorrect_input = true;
        }

        if (errno == ERANGE){
            printf("range error, got ");
            errno = 0;
        }

        if ( incorrect_input ) {
            print_duck ( ++n_duck );
        }
    } while ( incorrect_input );

    *func_coeff = value;
}

void input_coeffs ( Coeff_t *func_coeff ) //, const int *choice )
{
    get_one_coeff ( &func_coeff->a );
    printf ( "A = %g\n", func_coeff->a );

    get_one_coeff ( &func_coeff->b );
    printf ( "B = %g\n", func_coeff->b );

    get_one_coeff ( &func_coeff->c );
    printf ( "C = %g\n", func_coeff->c );

}

N_Roots_t solve ( Coeff_t *func_coeff, Roots_t *roots ) //, const int *choice )
{
    double epsilon = 1e-6;

    if ( fabs ( func_coeff->a - 0 ) < epsilon )             // solve liner
    {
        if ( fabs ( func_coeff->b - 0 ) >= epsilon ) {
            roots->x1 = roots->x2 = -func_coeff->c / func_coeff->b;

            return ONE_ROOT;
        }
        else if ( fabs ( func_coeff->b - 0 ) < epsilon && fabs ( func_coeff->c - 0 ) >= epsilon) {

            return ROOT_ZERO;
        }
        else {

            return ROOTS_ALL;
        }
    }
    else
    {
        double D = func_coeff->b * func_coeff->b - 4 * func_coeff->a * func_coeff->c;

        if ( fabs ( func_coeff->a - 0 ) < epsilon ) {
// TODO: blue text
            printf ( "Are you stupid?!?!?! THIS IS QUADRATIC EQUATION !!!\n");
            abort();
        }

        if ( D < 0 ) {

            return ROOT_ZERO;
        }
        else if ( D > 0 ) {
            double radical = sqrt ( D );
            roots->x1 = ( -func_coeff->b - radical ) / ( 2 * func_coeff->a );
            roots->x2 = ( -func_coeff->b + radical ) / ( 2 * func_coeff->a );
        }
        else if ( fabs ( D - 0 ) < epsilon ) {
            roots->x1 = roots->x2 = -func_coeff->b / ( 2 * func_coeff->a );

            return ONE_ROOT;
        }
    }

    return TWO_ROOTS;
}

void output_roots ( const Roots_t *roots, N_Roots_t n_roots )
{
    switch ( n_roots) {
        case ROOT_ZERO :
            printf ( "zero roots" );
            break;
        case ONE_ROOT :
            printf ( "one root : x = %g", roots->x1 );
            break;
        case TWO_ROOTS :
            printf ( "roots : x1 = %g\tx2 = %g", roots->x1, roots->x2 );
            break;
        case ROOTS_ALL :
            printf ( "all numbers" );
            break;
        default :
            printf ( " 'wtf' error" );
            break;
    }
    printf ( "\n" );
}

void print_duck ( int n_duck )
{
    switch ( n_duck % 4 ) {
        case 1:
            printf ( "incorrect input\t\t________________________________________________\n" );
            printf (              "\t\t\t__________*******_______________________________\n" );
            printf (              "\t\t\t________***    ****_____________________________\n" );
            printf (              "\t\t\t______****   0   ****___________________________\n" );
            printf (              "\t\t\t__(////////        ***__________________________\n" );
            printf (              "\t\t\t___(////////         ***________________________\t" );
            printf ( "input coefficient: " );
            break;
        case 2:
            printf ( "incorrect input\t\t_________**         **__________________________\n" );
            printf (              "\t\t\t___________****)     **_________________________\n" );
            printf (              "\t\t\t________________)    **_________________________\n" );
            printf (              "\t\t\t_________________)    ** _______________________\n" );
            printf (              "\t\t\t_________________)     **_______________________\n" );
            printf (              "\t\t\t_________________)      UU_______________ )))___\t" );
            printf ( "input coefficient: " );
            break;
        case 3:
            printf ( "incorrect input\t\t________________))       UUUU________ ((  )))___\n" );
            printf (              "\t\t\t_______________))       UUUUUUUU__ ((   )))_____\n" );
            printf (              "\t\t\t______________))          UUUUUUU ((   )))______\n" );
            printf (              "\t\t\t_____________)                       )))________\n" );
            printf (              "\t\t\t____________)                        )))________\n" );
            printf (              "\t\t\t___________))                        )))________\t" );
            printf ( "input coefficient: " );
            break;
        case 0:
            printf ( "incorrect input\t\t___________))                       )))_________\n" );
            printf (              "\t\t\t____________))                       )))________\n" );
            printf (              "\t\t\t_____________))                     )))_________\n" );
            printf (              "\t\t\t______________))                 )))____________\n" );
            printf (              "\t\t\t_______________))<<<<<<<<<<<<<<<<_______________\n" );
            printf (              "\t\t\t________________________________________________\t" );
            printf ( "input coefficient: " );
            break;
        default :
            printf ( "programmer error, sorry" );
            break;
     }
}

void check_pointer ( void *func_coeff, int line )
{
    char *val = (char *)func_coeff;
    if ( func_coeff == nullptr ) {
        printf( "line number %d\n", line );
        abort();
    }
}

void my_memset ( void *s, char number, size_t value )
{
    char *val = (char *)s;

    for (size_t i = 0 ; i < value; ++i ) {
        *( val + i ) = number;
    }
}

Mode interface ()
{
    printf ( "select mode : liner (1) or quadratic (2)\n" );

    char buf[13];     // buffer overflow

    scanf ( "%s", buf );

    if ( strcmp( buf, "liner" ) == 0 || strcmp( buf, "1") == 0 ) {
        return LINER;
    }
    else if ( strcmp( buf, "quadratic" ) == 0 || strcmp( buf, "2") == 0 ) {
        return QUADRATIC;
    }
    else {
// TODO: blue text
        printf ( "Are you stupid?!?!?! Please enter correctly\n");
        abort();
    }
}

