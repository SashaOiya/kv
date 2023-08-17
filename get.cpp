#include <stdio.h>
#include <stdlib.h>              // error 1) nullptr +
#include <ctype.h>               //         2)
#include <cmath>
#include <stdarg.h>
#include <string.h>
#include <iostream>

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

