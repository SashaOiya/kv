#include <stdio.h>
#include <stdlib.h>              // error 1) nullptr +
#include <ctype.h>               //         2)
#include <cmath>
#include <stdarg.h>
#include <string.h>
#include <iostream>

#define DEBUG

#ifdef DEBUG        // препроцессор должен сразу компилировать, а не сначала препроц., а потом комп.
    #define OUTPUT_ERROR(a) if( a == nullptr) { printf( "line number %d\n", __LINE__ ); abort(); }
#endif
enum N_Roots_t {
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

struct Roots_t {                 //
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

void get_one_coeff ( double *func_coeff )//, double **func_coeff_p )
{
    bool indicator = 0;
    static char buf[100];   //
    static int n_duck = 0;  //wtf

    do {
        memset ( buf, 0, sizeof ( buf ) );

        int i, num, c;

        for ( i = 0, indicator = 0, num = 0; ( c = getchar () ) != '\n' ; ++i ) {
            if ( isdigit ( c ) || ( i == 0 && c == '-' ) ) {
                buf[i] = c;
            }
            else if ( c == '.' && num == 0 ) {
                    buf[i] = c;
                    ++num;
            }
            else {
                indicator = 1;
            }
        }
        if ( indicator == 1 ) {
            printf ( "incorrect input\t\t" );
            ++n_duck;
            print_duck ( n_duck );
        }
    } while ( indicator == 1 );

    *func_coeff = atof(buf);

    //*func_coeff_p = nullptr;
}

void input_coeffs ( Coeff_t *func_coeff )
{
    //double *func_coeff_a = &func_coeff->a;          // почему сразу нельзя &(&...)
    //double **func_coeff_p = &( func_coeff_a );

    get_one_coeff ( &func_coeff->a );
    printf ( "A = %g\n", func_coeff->a );
    OUTPUT_ERROR( &func_coeff->a )

    get_one_coeff ( &func_coeff->b );
    printf ( "B = %g\n", func_coeff->b );
    OUTPUT_ERROR( &func_coeff->b )

    get_one_coeff ( &func_coeff->c );
    printf ( "C = %g\n", func_coeff->c );
    OUTPUT_ERROR( &func_coeff->c )
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
            roots->x1 = ( -func_coeff->b - sqrt(D) ) / ( 2 * func_coeff->a );
            roots->x2 = ( -func_coeff->b + sqrt(D) ) / ( 2 * func_coeff->a );
        }
        else if ( D == 0 ) {
            roots->x1 = roots->x2 = -func_coeff->b / ( 2 * func_coeff->a );

            return ONE_ROOT;
        }
    }

    return TWO_ROOTS;
}

void output_coeff ( Roots_t *roots, int n_roots )
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

void print_duck ( int n_duck )
{
    switch ( n_duck % 4 ) {
        case 1:
            printf ( "__________*******____________________________\n ");
            printf ( "\t\t\t________***    ****__________________________ \n ");
            printf ( "\t\t\t______****   0   ****_______________________\n ");
            printf ( "\t\t\t__(////////        ***_____________________\n");
            printf ( "\t\t\t___(////////         ***____________________\n ");
            printf ( "\t\t\t_________**         **______________________");
            break;
        case 2:
            printf ( "___________****)     **______________________ \n ");
            printf ( "\t\t\t________________)    **______________________ \n ");
            printf ( "\t\t\t_________________)    ** ______________________ \n ");
            printf ( "\t\t\t_________________)     **_____________________\n");
            printf ( "\t\t\t_________________)      UU_______________ )))__\n ");
            printf ( "\t\t\t________________))       UUUU________ ((  )))___");
            break;
        case 3:
            printf ( "_______________))       UUUUUUUU__ ((   )))____\n ");
            printf ( "\t\t\t______________))          UUUUUUU ((   )))____\n ");
            printf ( "\t\t\t_____________)                       )))_____ \n ");
            printf ( "\t\t\t____________)                        )))_____\n");
            printf ( "\t\t\t___________))                        )))_____ \n ");
            printf ( "\t\t\t___________))                       )))_____");
            break;
        case 0:
            printf ( "____________))                       )))____ \n ");
            printf ( "\t\t\t_____________))                     )))_____\n ");
            printf ( "\t\t\t______________))                 )))_______\n ");
            printf ( "\t\t\t_______________))<<<<<<<<<<<<<<<<__________ \n");
            printf ( "\t\t\t________________________________________________ ");
            break;
     }
}
