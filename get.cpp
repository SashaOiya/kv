#include <stdio.h>
#include <stdlib.h>              // error 1) nullptr +
#include <ctype.h>               //         2)
#include <cmath>
#include <stdarg.h>
#include <string.h>
#include <iostream>

const int MAX_BUF_VALUE = 100;

struct Coeff_t {
    double a = 0;
    double b = 0;
    double c = 0;
};

struct Roots_t {                 //
    double x1 = 0;
    double x2 = 0;
};

#define DEBUG

#ifdef DEBUG        // препроцессор должен сразу компилировать, а не сначала препроц., а потом комп.
    #define OUTPUT_ERROR(a) if( a == nullptr) { printf( "line number %d\n", __LINE__ ); abort(); }
#endif

void print_duck ( int n_duck );
void input_coeffs ( Coeff_t *func_coeff );
void get_one_coeff ( double *func_coeff);
void my_memset ( void *s, int number, size_t value );

void get_one_coeff ( double *func_coeff )
{
    OUTPUT_ERROR ( func_coeff );

    bool incorrect_input = false;
    static char buf[MAX_BUF_VALUE] = {0} ;
    static int n_duck = 0;

    printf ( "input coefficient: " );

    do {
        my_memset ( buf, 0, sizeof ( buf ) );

        int i, n_point, c;
         i = n_point = 0;                   //

        for ( incorrect_input = false; ( c = getchar () ) != '\n'  ; ++i ) {    //getchar() error 1) EOF 2) - 3) ГЄГ®Г­Г±Г®Г«Гј Г¬ГЁГ­ГіГ±                                                         // Г®ГЎГєГҐГ¤ГЁГ­ГЁГІГј ГўГ±ГҐ !isdigit Гў Г®Г¤Г­Г®
            if ( isdigit ( c ) || ( i == 0 && c == '-' ) || ( c == '.' && n_point++ == 0 ) ) {
                buf[i] = ( char ) c;
            }
            else {
                incorrect_input = true;
            }
        }

        incorrect_input = ( i == 0 || i > MAX_BUF_VALUE  ) ?  true : incorrect_input;

        if ( incorrect_input ) {                   //
            if ( i > MAX_BUF_VALUE ) {
                printf ( "buffer is full\n" );
            }
            print_duck ( ++n_duck );
        }
    } while ( incorrect_input );

    *func_coeff = atof(buf);
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
            // error
            break;
     }
}

void my_memset ( void *s, int number, size_t value )
{
    unsigned char *val = ( unsigned char *) s;
    int i = 0;

    for ( ; ( unsigned int ) i < ( unsigned int ) value; ++i ) {
        *( val + ( unsigned char ) i ) = ( unsigned char ) number;
    }
    //while ( value > 0 ) {        // РЅРµ СЂР°Р±РѕС‚Р°РµС‚ СѓС‚РєР°
    //    val[value--] = number;
    // }
}

