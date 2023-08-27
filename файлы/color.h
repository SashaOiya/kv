#include <windows.h>

enum Color_t {
    COLOR_GREEN = 10,
    COLOR_WHILE = 15,
    COLOR_RED   =  4,
    COLOR_PINK  = 12,
    COLOR_BLUE  =  9
};

void print_color ( const char *c, const int COLOR, ... ); // enum
