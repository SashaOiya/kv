#include <stdio.h>
#include <stdlib.h>              // error 1) nullptr +
#include <ctype.h>               //         2)
#include <cmath>
#include <stdarg.h>
#include <string.h>
#include <iostream>

const int MAX_BUF_VALUE = 5;   // 100

#define DEBUG

#ifdef DEBUG        // препроцессор должен сразу компилировать, а не сначала препроц., а потом комп.
    #define OUTPUT_ERROR(a) if( a == nullptr) { printf( "line number %d\n", __LINE__ ); abort(); }
#endif
enum N_Roots_t {      //
    ROOT_ZERO,
    ONE_ROOT,
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

void output_error ( double *func_coeff );
void get_one_coeff ( double *func_coeff);
void input_coeffs ( Coeff_t *func_coeff );
int solve ( Coeff_t *func_coeff, Roots_t *roots );
void output_coeff ( Roots_t *roots, int n_roots );
void print_duck ( int n_duck );

int main()
{
    struct Coeff_t func_coeff;      /* coefficients : ax^2 + bx + c = 0*/
    input_coeffs ( &func_coeff );    //

    struct Roots_t roots;

    int n_roots = solve ( &func_coeff, &roots );

    OUTPUT_ERROR ( &func_coeff.a )
    OUTPUT_ERROR ( &func_coeff.b )
    OUTPUT_ERROR ( &func_coeff.c )

    output_coeff ( &roots, n_roots );       //

    return 0;
}

void get_one_coeff ( double *func_coeff )
{
    OUTPUT_ERROR ( func_coeff );

    bool incorrect_input;
    static char buf[MAX_BUF_VALUE];    //wtf   // {0}
    static int n_duck = 0;

    printf ( "input coefficient: " );

    do {
        memset ( buf, 0, sizeof ( buf ) );        // print my memset

        int i, n_buf, n_point, c;                     // num ??? кол-во точек в вводе
        i = n_point = n_buf = 0;

        for ( incorrect_input = false; ( c = getchar () ) != '\n'  ; ++i ) {    //getchar() error 1) EOF 2) - 3) консоль минус
            if ( ++n_buf > MAX_BUF_VALUE ) {
                incorrect_input = true;
            }                                                          // объединить все !isdigit в одно
            else if ( isdigit ( c ) || ( i == 0 && c == '-' ) ) {
                buf[i] = c;
            }
            else if ( c == '.' && n_point == 0 ) {
                    buf[i] = c;
                    ++n_point;
            }
            else {
                incorrect_input = true;
            }
        }
        if ( i == 0 ) {
            incorrect_input = true;
        }
        if ( incorrect_input ) {
            if ( n_buf > MAX_BUF_VALUE ) {
                printf ( "buffer is full\n" );
            }
            printf ( "incorrect input\t\t" );
            ++n_duck;
            print_duck ( n_duck );
        }
    } while ( incorrect_input );

    *func_coeff = atof(buf);
}

void input_coeffs ( Coeff_t *func_coeff )
{                            //double *func_coeff_a = &func_coeff->a;     почему сразу нельзя &(&...)
    get_one_coeff ( &func_coeff->a );
    printf ( "A = %g\n", func_coeff->a );  // what

    get_one_coeff ( &func_coeff->b );
    printf ( "B = %g\n", func_coeff->b );

    get_one_coeff ( &func_coeff->c );
    printf ( "C = %g\n", func_coeff->c );
}

int solve ( Coeff_t *func_coeff, Roots_t *roots )
{

    if ( func_coeff->a == 0 )
    {
        if ( func_coeff->b != 0 ) {
            roots->x1 = roots->x2 = -func_coeff->c / func_coeff->b;

            return ONE_ROOT;
        }
        else if ( func_coeff->b == 0 && func_coeff->c != 0 ) {

            return ROOT_ZERO;
        }
        else {

            return ROOTS_ALL;
        }
    }
    else
    {
        float D = func_coeff->b * func_coeff->b - 4 * func_coeff->a * func_coeff->c;

        if ( D < 0 ) {

            return ROOT_ZERO;
        }
        else if ( D > 0 ) {
            double radical = sqrt ( D );
            roots->x1 = ( -func_coeff->b - radical ) / ( 2 * func_coeff->a );
            roots->x2 = ( -func_coeff->b + radical ) / ( 2 * func_coeff->a );
        }
        else if ( D == 0 ) {
            roots->x1 = roots->x2 = -func_coeff->b / ( 2 * func_coeff->a );

            return ONE_ROOT;
        }
    }

    return TWO_ROOTS;
}

void output_coeff ( Roots_t *roots, int n_roots )   // +
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
    }
    printf ( "\n" );
}

void print_duck ( int n_duck )           // +
{
    switch ( n_duck % 4 ) {
        case 1:
            printf (       "________________________________________________\n" );
            printf ( "\t\t\t__________*******_______________________________\n" );
            printf ( "\t\t\t________***    ****_____________________________\n" );
            printf ( "\t\t\t______****   0   ****___________________________\n" );
            printf ( "\t\t\t__(////////        ***__________________________\n" );
            printf ( "\t\t\t___(////////         ***________________________\t" );
            printf ( "input coefficient: " );
            break;
        case 2:
            printf (       "_________**         **__________________________\n" );
            printf ( "\t\t\t___________****)     **_________________________\n" );
            printf ( "\t\t\t________________)    **_________________________\n" );
            printf ( "\t\t\t_________________)    ** _______________________\n" );
            printf ( "\t\t\t_________________)     **_______________________\n" );
            printf ( "\t\t\t_________________)      UU_______________ )))___\t" );
            printf ( "input coefficient: " );
            break;
        case 3:
            printf (       "________________))       UUUU________ ((  )))___\n" );
            printf ( "\t\t\t_______________))       UUUUUUUU__ ((   )))_____\n" );
            printf ( "\t\t\t______________))          UUUUUUU ((   )))______\n" );
            printf ( "\t\t\t_____________)                       )))________\n" );
            printf ( "\t\t\t____________)                        )))________\n" );
            printf ( "\t\t\t___________))                        )))________\t" );
            printf ( "input coefficient: " );
            break;
        case 0:
            printf (       "___________))                       )))_________\n" );
            printf ( "\t\t\t____________))                       )))________\n" );
            printf ( "\t\t\t_____________))                     )))_________\n" );
            printf ( "\t\t\t______________))                 )))____________\n" );
            printf ( "\t\t\t_______________))<<<<<<<<<<<<<<<<_______________\n" );
            printf ( "\t\t\t________________________________________________\t" );
            printf ( "input coefficient: " );
            break;
     }
}
