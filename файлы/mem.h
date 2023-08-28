#ifndef MEM_H
#define MEM_H

//{----------------------------------------------------------------------------
//!
//! The function checks the pointer to nullptr
//!
//! @param *func_coeff Pointer to an element of the coefficient structure
//! @param line        Line number
//!
//}----------------------------------------------------------------------------
void check_pointer ( void *func_coeff, int line );

//{----------------------------------------------------------------------------
//!
//! A function that fills a given number of array elements with a given number
//!
//! @param *val   Pointer to the beginning of an array of elements
//! @param number The value that is assigned to the elements of the array
//! @param value  The number of array elements to fill in
//!
//}----------------------------------------------------------------------------
void my_memset ( void *val, const char number, const size_t value );

//{------------------------------------------------------------------------------
//!
//! Checks the buffer for overflow
//!
//! @see void print_color ( const char *c, enum Color_t COLOR, ... )
//!
//! @param mux_buf_value         Maximum number of array elements
//! @param *input_element_number Pointer to an array element
//! @param n_overflow            Number of array overflow
//!
//! @note  Returns false if the array was not overflowed
//! @note  Returns true if the array was overflowed
//!
//}-------------------------------------------------------------------------------
bool buf_overflow ( const int max_buf_value, int *input_element_number, bool n_overflow );

#endif
