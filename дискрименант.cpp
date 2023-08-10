#include <stdio.h>       /* ax^2+bx+c*/
#include <cmath>

int vvod_1 ();
int vvod_2 ();
int vvod_3 ();

int main()
{
    int a,b,c;
    int D;
    a = vvod_1();
    if ( a == 0 )
        printf ( "не квадратичное" );
    b = vvod_2();
    c = vvod_3();
    D = b * b - 4 * a * c;
    printf ( "%d", D );
    return 0;
}

int vvod_1 ()
{
    int i, k, g, c, p;
    g = 0;
    p = 0;
    for ( k = 0; ( c = getchar() ) != '\n'; ++k) {
        if ( g == -1 && c == '1' && p == 0  ) {
            g = -1;
            ++p;
        }
        else if ( g == -1 && c == '1' && p != 0  )
            g= g * 10 - ( c - 48 );
        else if ( g == -1 && c != '1' && p <= 0 )
            g = g * ( c - 48);
        else if ( g == -1 && c != '1' && p > 0 )
            g= g * 10 - ( c - 48 );
        else if ( c == '-' )
            g = -1;
        else if ( g >= 0 )
             g= g * 10 + ( c - 48 );
        else if ( g <= 0 )
                g= g * 10 - ( c - 48 );
    }
    return g;
}

int vvod_2 ()
{
    int i, k, g, c, p;
    g = 0;
    p = 0;
    for ( k = 0; ( c = getchar() ) != '\n'; ++k) {
        if ( g == -1 && c == '1' && p == 0  ) {
            g = -1;
            ++p;
        }
        else if ( g == -1 && c == '1' && p != 0  )
            g= g * 10 - ( c - 48 );
        else if ( g == -1 && c != '1' && p <= 0 )
            g = g * ( c - 48);
        else if ( g == -1 && c != '1' && p > 0 )
            g= g * 10 - ( c - 48 );
        else if ( c == '-' )
            g = -1;
        else if ( g >= 0 )
             g= g * 10 + ( c - 48 );
        else if ( g <= 0 )
                g= g * 10 - ( c - 48 );
    }
    return g;
}

int vvod_3 ()
{
    int i, k, g, c, p;
    g = 0;
    p = 0;
    for ( k = 0; ( c = getchar() ) != '\n'; ++k) {
        if ( g == -1 && c == '1' && p == 0  ) {
            g = -1;
            ++p;
        }
        else if ( g == -1 && c == '1' && p != 0  )
            g= g * 10 - ( c - 48 );
        else if ( g == -1 && c != '1' && p <= 0 )
            g = g * ( c - 48);
        else if ( g == -1 && c != '1' && p > 0 )
            g= g * 10 - ( c - 48 );
        else if ( c == '-' )
            g = -1;
        else if ( g >= 0 )
             g= g * 10 + ( c - 48 );
        else if ( g <= 0 )
                g= g * 10 - ( c - 48 );
    }
    return g;
}


