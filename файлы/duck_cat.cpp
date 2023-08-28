#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <cmath>
#include <stdarg.h>
#include <string.h>
#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <cmath>
#include <string.h>
#include <ctype.h>
#include "checker.h"
#include "duck_cat.h"
#include "color.h"
#include "mem.h"

void print_color ( const char *line, enum Color_t COLOR, ... )
{
    HANDLE hConsole = GetStdHandle ( STD_OUTPUT_HANDLE );

    va_list args;
    va_start ( args, COLOR );

    SetConsoleTextAttribute ( hConsole, COLOR );

    vprintf ( (char *)line, args );   //

    SetConsoleTextAttribute ( hConsole, 15 );

    va_end ( args );
}

void print_duck ( const int n_duck )
{
    switch ( n_duck % 4 ) {
        case 1:
            print_color ( "incorrect input\t\t________________________________________________\n"
                                       "\t\t\t__________*******_______________________________\n"
                                       "\t\t\t________***    ****_____________________________\n"
                                       "\t\t\t______****   0   ****___________________________\n"
                                       "\t\t\t__(////////        ***__________________________\n"
                                       "\t\t\t___(////////         ***________________________\t"
                                       "input coefficient: ", COLOR_GREEN );
            break;
        case 2:
            print_color ( "incorrect input\t\t_________**         **__________________________\n"
                                       "\t\t\t___________****)     **_________________________\n"
                                       "\t\t\t________________)    **_________________________\n"
                                       "\t\t\t_________________)    ** _______________________\n"
                                       "\t\t\t_________________)     **_______________________\n"
                                       "\t\t\t_________________)      UU_______________ )))___\t"
                                       "input coefficient: ", COLOR_GREEN );
            break;
        case 3:
            print_color ( "incorrect input\t\t________________))       UUUU________ ((  )))___\n"
                                       "\t\t\t_______________))       UUUUUUUU__ ((   )))_____\n"
                                       "\t\t\t______________))          UUUUUUU ((   )))______\n"
                                       "\t\t\t_____________)                       )))________\n"
                                       "\t\t\t____________)                        )))________\n"
                                       "\t\t\t___________))                        )))________\t"
                                       "input coefficient: ", COLOR_GREEN );
            break;
        case 0:
            print_color ( "incorrect input\t\t___________))                       )))_________\n"
                                       "\t\t\t____________))                       )))________\n"
                                       "\t\t\t_____________))                     )))_________\n"
                                       "\t\t\t______________))                 )))____________\n"
                                       "\t\t\t_______________))<<<<<<<<<<<<<<<<_______________\n"
                                       "\t\t\t________________________________________________\t"
                                       "input coefficient: ", COLOR_GREEN );
            break;
        default :
            print_color ( "programmer error, sorry", COLOR_BLUE );
            break;
     }
}

Mode_t interface_input ( bool start_indicator )
{
$   const int MAX_BUF_VALUE = 100 ;
$   char buf[MAX_BUF_VALUE] = {0};
$   bool n_overflow = false;
    int start_check = 0;

    for ( int c = 0, i = 0; ( c = getchar() ) != '\n' && c != EOF; ++i ) {

        if ( isspace ( c ) ) {
            i--;
        }

$       buf[i] = (char)c;
$       n_overflow = buf_overflow ( MAX_BUF_VALUE, &i, n_overflow );
    }

    if ( start_indicator && strcmp ( buf, "start" ) == 0 ) {

        print_color ( "Select mode : linear (1) or quadratic (2) : ", COLOR_BLUE );

        do {

$           const int MAX_BUF_VALUE =  13;
$           char buf[MAX_BUF_VALUE] = {0};
$           bool n_overflow = false;

            for ( int c, i = 0; ( c = getchar() ) != '\n' && c != EOF; ++i ) {

                if ( isspace ( c ) ) {
                    i--;
                }

$               buf[i] = (char)c;
$               n_overflow = buf_overflow ( MAX_BUF_VALUE, &i, n_overflow );
            }

            if ( strcmp ( buf, "linear" ) == 0 ||      // func --
                 strcmp ( buf, "1") == 0 ) {

$               return LINEAR;
            }
            else if ( strcmp ( buf, "quadratic" ) == 0 ||
                      strcmp ( buf, "2") == 0 ) {

$               return QUADRATIC;
            }
            else {

                print_cat_small ();

                start_check = ERROR;
            }

        } while ( start_check == ERROR );
    }
    else if ( strcmp( buf, "help" ) == 0 ) {

        print_color ( "Here is a list of supported features :"
                 "\n\n  start  \n\n  help  \n\n  bye-bye  \n\n  option-meow  \n\n", COLOR_BLUE );

$       return HELP;
    }
    else if ( strcmp ( buf, "bye-bye" ) == 0 ) {

        return BYE;
    }
    else if ( strcmp ( buf, "option-meow" ) == 0 ) {

        print_cat_big ();

$       return OPTION_MEOW;
    }
    else {

        print_color ( "This option was not found. Use the list of presented functions:\n", COLOR_BLUE );

        return Error;
    }
}

void print_cat_small ()
{
    print_color ( "Please enter correctly\n\n"
                  "           _,/|             _.-''``-...___..--';   \n"
                  "          /_ \'.      __..-' ,      ,--...--'''    \n"
                  "         'L..   ''''               /'              \n"
                  "           -';'               ;   ; ;              \n"
                  "  __...--''     ___...--_..'  .;.'                 \n"
                  " (,__....----'''       (,..--''                  \n\n", COLOR_RED );

}

void print_cat_big ()
{
    print_color ( "   ,';,               ,';,                                     \n"
                  "  ,' , :;             ; ,,.;                                   \n"
                  "  | |:; :;           ; ;:|.|                                   \n"
                  "| |::; ';,,,,,,,,,'  ;:|.|    ,,,;;;;;;;;,,,                   \n"
                  "; |''  ___      ___   ';.;,,''             ''';,,,             \n"
                  "',:   /   \    /   \    .;.                      '';,          \n"
                  ";    /    |    |    \     ;,                        ';,        \n"
                  ";    |    /|    |\    |    :|                          ';,     \n"
                  "|    |    \|    |/    |    :|     ,,,,,,,               ';,    \n"
                  "|     \ ___| __ |____/     :;  ,''                        ;,   \n"
                  ";           /  \          :; ,'                           :;   \n"
                  "',        `----'        :; |'                            :|    \n"
                  "',,  `----------'  ..;',|'                             :|      \n"
                  ",'  ',,,,,,,,,,,;;;;''  |'                              :;     \n"
                  ",'  ,,,,                  |,                              :;   \n"
                  "| ,'   :;, ,,''''''''''   '|.   ...........                ';, \n"
                  ";       :;|               ,,';;;''''''                      ';,\n"
                  "',,,,,;;;|.............,'                          ....      ;,\n"
                  "       ''''''''''''|        .............;;;;;;;''''',    ':;  \n"
                  "                    |;;;;;;;;'''''''''''''             ;    :| \n"
                  "                                                    ,,,'     :;\n"
                  "                                        ,,,,,,,,,,''       .;' \n"
                  "...............................................................\n", COLOR_PINK );
}


