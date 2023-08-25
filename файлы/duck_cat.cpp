#include "checker.h"
#include "duck_cat.h"

bool buf_overflow ( const int MAX_BUF_VALUE, int *i, bool n_overflow );

void print_duck ( const int n_duck )
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    switch ( n_duck % 4 ) {
        case 1:
            SetConsoleTextAttribute ( hConsole, 10 );

            printf ( "incorrect input\t\t________________________________________________\n"
                                  "\t\t\t__________*******_______________________________\n"
                                  "\t\t\t________***    ****_____________________________\n"
                                  "\t\t\t______****   0   ****___________________________\n"
                                  "\t\t\t__(////////        ***__________________________\n"
                                  "\t\t\t___(////////         ***________________________\t"
                                                                       "input coefficient: " );
            SetConsoleTextAttribute ( hConsole, 15 );

            break;
        case 2:
            SetConsoleTextAttribute ( hConsole, 10 );

            printf ( "incorrect input\t\t_________**         **__________________________\n"
                                  "\t\t\t___________****)     **_________________________\n"
                                  "\t\t\t________________)    **_________________________\n"
                                  "\t\t\t_________________)    ** _______________________\n"
                                  "\t\t\t_________________)     **_______________________\n"
                                  "\t\t\t_________________)      UU_______________ )))___\t"
                                                                       "input coefficient: " );
            SetConsoleTextAttribute ( hConsole, 15 );

            break;
        case 3:
            SetConsoleTextAttribute ( hConsole, 10 );

            printf ( "incorrect input\t\t________________))       UUUU________ ((  )))___\n"
                                  "\t\t\t_______________))       UUUUUUUU__ ((   )))_____\n"
                                  "\t\t\t______________))          UUUUUUU ((   )))______\n"
                                  "\t\t\t_____________)                       )))________\n"
                                  "\t\t\t____________)                        )))________\n"
                                  "\t\t\t___________))                        )))________\t"
                                                                       "input coefficient: " );
            SetConsoleTextAttribute ( hConsole, 15 );

            break;
        case 0:
            SetConsoleTextAttribute ( hConsole, 10 );

            printf ( "incorrect input\t\t___________))                       )))_________\n"
                                  "\t\t\t____________))                       )))________\n"
                                  "\t\t\t_____________))                     )))_________\n"
                                  "\t\t\t______________))                 )))____________\n"
                                  "\t\t\t_______________))<<<<<<<<<<<<<<<<_______________\n"
                                  "\t\t\t________________________________________________\t"
                                                                       "input coefficient: " );
            SetConsoleTextAttribute ( hConsole, 15 );

            break;
        default :
            printf ( "programmer error, sorry" );
            break;
     }
}

Mode_t interface_input ( bool start_indicator )
{
$   const int MAX_BUF_VALUE = 100 ;
$   char buf[MAX_BUF_VALUE] = {0};
$   bool n_overflow = false;
    int start_check = 0;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    for ( int c = 0, i = 0; ( c = getchar() ) != '\n' && c != EOF; ++i ) {

$       buf[i] = (char)c;
$       n_overflow = buf_overflow ( MAX_BUF_VALUE, &i, n_overflow );
    }

    if ( start_indicator && strcmp ( buf, "start" ) == 0 ) {

        printf ( "Select mode : linear (1) or quadratic (2)\n" );

        do {

$           const int MAX_BUF_VALUE =  13;
$           char buf[MAX_BUF_VALUE] = {0};
$           bool n_overflow = false;

            for ( int c, i = 0; ( c = getchar() ) != '\n' && c != EOF; ++i ) {

$               buf[i] = (char)c;
$               n_overflow = buf_overflow ( MAX_BUF_VALUE, &i, n_overflow );
            }

            if ( strcmp ( buf, "linear" ) == 0 ||
                 strcmp ( buf, "1") == 0 ) {

$               return LINEAR;
            }
            else if ( strcmp ( buf, "quadratic" ) == 0 ||
                      strcmp ( buf, "2") == 0 ) {

$               return QUADRATIC;
            }
            else {

                SetConsoleTextAttribute ( hConsole, 4 );

                printf ( "Please enter correctly\n\n"
                        "           _,/|             _.-''``-...___..--';   \n"
                        "          /_ \'.      __..-' ,      ,--...--'''    \n"
                        "         'L..   ''''               /'              \n"
                        "           -';'               ;   ; ;              \n"
                        "  __...--''     ___...--_..'  .;.'                 \n"
                        " (,__....----'''       (,..--''                  \n\n" );

                SetConsoleTextAttribute ( hConsole, 15 );

                start_check = ERROR;
            }

        } while ( start_check == ERROR );
    }
    else if ( strcmp( buf, "help" ) == 0 ) {

        printf ( "Here is a list of supported features :"
                 "\n\nstart\n\nhelp\n\nbye-bye\n\noption_meow\n\n" );

$       return HELP;
    }
    else if ( strcmp ( buf, "bye-bye" ) == 0 ) {

        return BYE;
    }
    else if ( strcmp ( buf, "option_meow" ) == 0 ) {

        SetConsoleTextAttribute ( hConsole, 12 );

        printf ( "   ,';,               ,';,                                     \n"
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
                 "                                        |              .;;;;'  \n"
                 "                                        ';;;;;;;;;;;;;;'       \n" );

        SetConsoleTextAttribute ( hConsole, 15 );

$       return OPTION_MEOW;
    }
    else {

        printf ( "This function was not found. Use the list of presented functions:\n" );

        return Error;
    }
}


