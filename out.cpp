enum N_Roots_t {
    ROOT_ZERO,
    ONE_ROOT,
    TWO_ROOTS,
    ROOTS_ALL
};

int solve ( Coeff_t *func_coeff, Roots_t *roots );   // N_Roots_t
void output_coeff ( Roots_t *roots, int n_roots );

int solve ( Coeff_t *func_coeff, Roots_t *roots )
{

    if ( func_coeff->a == 0 )
    {
        if ( func_coeff->b != 0 ) {
            roots->x1 = roots->x2 = -func_coeff->c / func_coeff->b;

            return ONE_ROOT;
        }
        else if ( func_coeff->b == 0 && func_coeff->c != 0 ) {

            return ROOT_ZERO;
        }
        else {

            return ROOTS_ALL;
        }
    }
    else
    {
        float D = func_coeff->b * func_coeff->b - 4 * func_coeff->a * func_coeff->c;

        if ( D < 0 ) {

            return ROOT_ZERO;
        }
        else if ( D > 0 ) {
            roots->x1 = ( -func_coeff->b - sqrt(D) ) / ( 2 * func_coeff->a );
            roots->x2 = ( -func_coeff->b + sqrt(D) ) / ( 2 * func_coeff->a );
        }
        else if ( D == 0 ) {
            roots->x1 = roots->x2 = -func_coeff->b / ( 2 * func_coeff->a );

            return ONE_ROOT;
        }
    }

    return TWO_ROOTS;
}

void output_coeff ( Roots_t *roots, int n_roots )
{
    switch ( n_roots) {
        case ROOT_ZERO :
            printf ( "zero roots" );
            break;
        case ONE_ROOT :
            printf ( "one root : x = %g", roots->x1 );
            break;
        case TWO_ROOTS :
            printf ( "roots : x1 = %g\tx2 = %g", roots->x1, roots->x2 );
            break;
        case ROOTS_ALL :
            printf ( "all numbers" );
            break;
    }
    printf ( "\n" );
}
