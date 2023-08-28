#ifndef DUCK_CAT_H
#define DUCK_CAT_H

//{----------------------------------------------------------------------------
//!
//! Enumeration of return values for selecting the operating mode
//!
//}----------------------------------------------------------------------------
enum Mode_t {
    LINEAR      = 0,
    QUADRATIC   = 1,
    Error       = 2,
    START       = 3,
    HELP        = 4,
    BYE         = 5,
    OPTION_MEOW = 6
};

//{----------------------------------------------------------------------------
//!
//! Prints a duck
//!
//! @see void print_color ( const char *c, enum Color_t COLOR, ... )
//!
//! @param n_duck The number of ducks already displayed
//!               ( == the number of incorrectly entered values )
//!
//}----------------------------------------------------------------------------
void print_duck ( const int n_duck );

//{----------------------------------------------------------------------------
//!
//! The function compares two values
//!
//! @see bool buf_overflow ( const int max_buf_value, int *input_element_number, bool n_overflow )
//! @see void print_color     ( const char *c, enum Color_t COLOR, ... )
//! @see void print_cat_small ()
//! @see void print_cat_big   ()
//!
//! @param start_indicator Number of starts written
//!
//! @note  Returns the selected mode
//!
//}----------------------------------------------------------------------------
Mode_t interface_input ( bool start_indicator );

//{----------------------------------------------------------------------------
//!
//! Prints a small cat
//!
//}----------------------------------------------------------------------------
void print_cat_small ();

//{----------------------------------------------------------------------------
//!
//! Prints a big cat
//!
//}----------------------------------------------------------------------------
void print_cat_big ();

#endif
