#ifndef DUCK_CAT_H
#define DUCK_CAT_H

enum Mode_t {
    LINEAR      = 0,
    QUADRATIC   = 1,
    Error       = 2,
    START       = 3,
    HELP        = 4,
    BYE         = 5,
    OPTION_MEOW = 6
};

void print_duck ( const int n_duck );
Mode_t interface_input ( bool start_indicator );
void print_cat_small ();
void print_cat_big ();

#endif
