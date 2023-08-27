#ifndef TEST_H
#define TEST_H

#include "solve.h"

struct Coeff_Root {
    Coeff_t coeffs;
    Roots_t roots;
};

//{--------------------------------------
//! Does one test. Compares the return value from the solution with the reference solution
//!
//! @param data Pointer to the structure of reference coefficients and roots
//!
//! @note Writes "test ok" if the value from the solution coincides with the reference valu;
//!       writes the roots and the number of roots from the solution and from the reference.
//! @par Usage example
//}
bool Test_One_Case ( Coeff_Root *data );
int Test_All_Cases ( );

#endif // TEST_H
