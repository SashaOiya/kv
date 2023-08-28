#ifndef INPUT_H
#define INPUT_H

//{----------------------------------------------------------------------------
//!
//! The function passes the value to an element of the coefficients structure
//!
//! @see void print_duck ( const int n_duck )
//! @see void my_memset ( void *val, const char number, const size_t value )
//! @see bool buf_overflow ( const int max_buf_value, int *input_element_number, bool n_overflow )
//! @see bool compare_value_min ( double x1, double x2)
//!
//! @param *func_coeff Pointer to an element of the coefficient structure
//!
//}----------------------------------------------------------------------------
void get_one_coeff ( double *func_coeff);

//{----------------------------------------------------------------------------
//!
//! The function prints a string with the coefficient name and its value
//!
//! @see void get_one_coeff ( double *func_coeff)
//!
//! @param *coeff_name Pointer to the string with the element name
//! @param *coeff_ptr  Pointer to the coefficient value
//!
//}----------------------------------------------------------------------------
void get_coeff ( const char *coeff_name, double *coeff_ptr );

#endif  // INPUT_H
