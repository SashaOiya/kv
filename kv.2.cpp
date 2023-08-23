#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <cmath>
#include <stdarg.h>
#include <string.h>
#include <iostream>
#include <stdint.h>
//#include "test.cpp"

#define DEBUG

#ifdef DEBUG
    #define ASSERT( a ) check_pointer ( a, __LINE__ )
   // #define GET_ERROR check_getchar ( __LINE__ )
#else
    #defune ASSERT( a ) ;
    //#define GET_ERROR ;
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

enum Mode_t {
    LINEAR,
    QUADRATIC,
    ERROR
};

Mode_t interface ();
void print_duck ( const int n_duck );
void get_one_coeff ( double *func_coeff);
void get_coeff ( const char *coeff, double *n_coeff );
void check_pointer ( void *func_coeff, int line );
void my_memset ( void *s, const char number, const size_t value );
void input_coeffs ( Coeff_t *func_coeff, const int *choice );
void output_roots ( const Roots_t *roots, N_Roots_t n_roots );
N_Roots_t solve ( Coeff_t *func_coeff, Roots_t *roots, const int *choice );
int Test_All_Cases ( Coeff_t *func_coeffs );
bool Test_One_Case ( Coeff_t *func_coeffs, Roots_t *ref_roots, int choice, int n_roots_ref );
//void check_getchar ( int line );

int main ( )
{
    const int choice = interface (); // equation type
    if (choice == ERROR) {
        return ERROR; //
    }

    struct Coeff_t func_coeff; //      /* coefficients : ax^2 + bx + c = 0*/
    //input_coeffs ( &func_coeff, &choice );

    // switch
    //if ( choice == QUADRATIC ) {
    //    get_coeff ( "A", &func_coeff->a );
    //    get_coeff ( "B", &func_coeff->b );
    //get_coeff ( "C", &func_coeff->c );
    //}
    //else if ( *choice == LINEAR ) {
    //    get_coeff ( "K", &func_coeff->b );
    //    get_coeff ( "B", &func_coeff->c );
    //}

    struct Roots_t   roots; //
    Test_All_Cases ( &func_coeff )

    //if ( choice == LINEAR )
    //solve_linear...

    enum N_Roots_t n_roots = solve ( &func_coeff, &roots, &choice ); // -choice

    ASSERT ( &func_coeff.a );
    ASSERT ( &func_coeff.b );
    ASSERT ( &func_coeff.c );

    output_roots ( &roots, n_roots );

    return 0;
}

void get_one_coeff ( double *func_coeff)
{
    ASSERT ( func_coeff );

    const int MAX_BUF_VALUE = 100;
    bool incorrect_input = false;
    bool overflow_indicator = false;
    static char buf[MAX_BUF_VALUE] = {0};
    static int n_duck = 0;
    double value = 0;
    const double epsilon = 1e-6;

    printf ( "input coefficient: " );

    do {
        if ( incorrect_input ) {
            print_duck ( ++n_duck );
        }
        my_memset ( buf, 0, strlen ( buf ) );
        incorrect_input = false;
        overflow_indicator = false;

        char *end = buf;
        int i = 0;

        ASSERT ( end );

        for ( int c = 0; ( c = getchar() ) != '\n' && c != EOF; ++i ) {
            buf[i] = (char)c;
            if ( i + 1 > MAX_BUF_VALUE && overflow_indicator == false ) {
                printf ( "buffer is full\n" );
                i = 0;
                overflow_indicator = true;
                incorrect_input = true;
            }
            else if ( i + 1 > MAX_BUF_VALUE && overflow_indicator == true ) {
                i = 0;
            }
        }
        if ( feof ( stdin ) ) {
            puts ( "End of file reached" );
        }
        else if ( ferror ( stdin ) ) {
            perror ( "getchar()" );
            fprintf ( stderr, "getchar() failed in file %s at line # %d\n", __FILE__,__LINE__-9 );
            exit ( EXIT_FAILURE );
        }
        value = strtod ( &buf[0], &end );

        ASSERT ( end );

        if ( ( fabs ( value - 0 ) <= epsilon && buf[0] != '0' ) || *end != '\0' ) {
            incorrect_input = true;
        }
        if (errno == ERANGE){
            printf("range error, got ");
            errno = 0;
        }
    } while ( incorrect_input );

    *func_coeff = value;
}

void input_coeffs ( Coeff_t *func_coeff, const int *choice )
{
    if ( *choice == QUADRATIC ) {
        get_coeff ( "A", &func_coeff->a );
        get_coeff ( "B", &func_coeff->b );
        get_coeff ( "C", &func_coeff->c );
    }
    else if ( *choice == LINEAR ) {
        get_coeff ( "K", &func_coeff->b );
        get_coeff ( "B", &func_coeff->c );
    }
    else if ( *choice == ERROR ) {
        exit ( EXIT_FAILURE );
    }
}

N_Roots_t solve ( const Coeff_t *func_coeff, Roots_t *roots, const int *choice )   // убрать указатель
{
    const double epsilon = 1e-6;

    if ( *choice == LINEAR ) {            // solve linear
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
    else if ( *choice == QUADRATIC ) {
        double D = func_coeff->b * func_coeff->b - 4 * func_coeff->a * func_coeff->c;

        if ( fabs ( func_coeff->a - 0 ) < epsilon ) {
// TODO: blue text
            printf ( "Are you stupid?!?!?! THIS IS QUADRATIC EQUATION !!!\n");
            exit ( EXIT_FAILURE ); ////
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
            exit ( EXIT_FAILURE );
    }
    printf ( "\n" );
}

void print_duck ( const int n_duck )
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
            break;     // exit(...);
     }
}

void check_pointer ( void *func_coeff, int line )
{
    char *val = (char *)func_coeff;
    if ( val == nullptr ) {
       // 0x123
        printf( "Segmentation fault \nline number %d\n", line );
        exit ( EXIT_FAILURE );
    }
}

void my_memset ( void *s, const char number, const size_t value )
{
    char *val = (char *)s;

    for (size_t i = 0 ; i < value; ++i ) {
        *( val + i ) = number;
    }
}

Mode_t interface ()
{
    printf ( "select mode : linear (1) or quadratic (2)\n" );

    const int MAX_BUF_VALUE = 13;
    char buf[MAX_BUF_VALUE] = {0};     // buffer overflow
    int n_overflow = 0;

    for ( int c, i = 0; ( c = getchar() ) != '\n' && c != EOF; ++i ) {  // errors
        buf[i] = (char)c;
        if ( i + 1 > MAX_BUF_VALUE && n_overflow == 0 ) {
            printf ( "buffer is full\n" );
            i = 0;
            ++n_overflow;
        }
        else if ( i + 1 > MAX_BUF_VALUE && n_overflow > 1 ) {
            i = 0;
        }
    }
    if ( strcmp( buf, "linear" ) == 0 ||
         strcmp( buf, "1") == 0 ) {
        return LINEAR;
    }
    else if ( strcmp( buf, "quadratic" ) == 0 ||
              strcmp( buf, "2") == 0 ) {
        return QUADRATIC;
    }
    else {
        printf ( "Please enter correctly\n\n");
        printf ( "           _,/|             _.-''``-...___..--';   \n" );
        printf ( "          /_ \'.      __..-' ,      ,--...--'''    \n" );
        printf ( "         'L..   ''''               /'              \n" );
        printf ( "           -';'               ;   ; ;              \n" );
        printf ( "  __...--''     ___...--_..'  .;.'                 \n" );
        printf ( " (,__....----'''       (,..--''                  \n\n" );
        interface();
    }
}

void get_coeff ( const char *coeff, double *n_coeff )
{

    get_one_coeff ( n_coeff );
    printf ( "%c = %g\n",*coeff, *n_coeff );
}

//void check_getchar ( int line )
//{
//
//    if (feof(stdin))
//      puts("End of file reached");
//    else if (ferror(stdin))
//         {
//            perror("getchar()");
//            fprintf(stderr,"getchar() failed in file %s at line # %d\n", __FILE__,__LINE__-9);
//            exit(EXIT_FAILURE);
//         }
//}

bool Test_One_Case ( Coeff_t *func_coeffs, Roots_t *ref_roots, int choice, int n_roots_ref )
{
    Roots_t roots ; // initil
    const int n_roots = solve ( func_coeffs, roots, &choice );
    if ( choice == LINEAR ) {
        if ( roots.x1 != ref_roots->x1 || n_roots != n_roots_ref ) {
            printf ( " x1  = %g, n_roots = %d\nexpected: x1 = %g, n_roots = %d", roots.x1, n_roots, ref_roots->x1, n_roots_ref );
            return false;
        }
        else {
            printf ( "Test OK" );
        }
    }
    else if ( choice == QUADRATIC ) {
        if ( roots.x1 != ref_roots->x1 || roots.x2 != ref_roots->x2 || n_roots != n_roots_ref ) {
            printf ( " x1 = %g, x2 = %g, n_roots = %d\nexpected: x1 = %g, x2 = %g, n_roots = %d", roots.x1, roots.x2, n_roots, ref_roots->x1, ref_roots->x2, n_roots_ref );
            return false;
        }
        else {
            printf ( "Test OK" );
        }
    }
    return true;
}

int Test_All_Cases ( Coeff_t *func_coeffs )
{
    int test_ok = 0;
    const int N_TEST = 10;

    func_coeffs->a = 1;
    func_coeffs->b = 6;
    func_coeffs->c = 9;

    Roots_t ref_roots;

    ref_roots.x1 = ref_roots.x2 = -3 ;
    if ( Test_One_Case ( func_coeffs, &ref_roots, QUADRATIC, 1 ) ) {
        ++test_ok;
        // обнулять корни
    }
}






