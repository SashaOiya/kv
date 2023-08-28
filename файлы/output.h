#ifndef OUTPUT_H
#define OUTPUT_H

#include "solve.h"

//{----------------------------------------------------------------------------
//!
//! The function outputs the number of roots and their values
//!
//! @param *n_roots Element of enumeration of the number of roots
//! @param *roots   Pointer to a root structure element
//!
//}----------------------------------------------------------------------------
void output_roots ( const Roots_t *roots, N_Roots_t n_roots );

#endif // OUTPUT_H
