int main ( void )
{
    struct Coeff_t func_coeff;
    input_coeffs ( &func_coeff );

    struct Roots_t roots;

    int n_roots = solve ( &func_coeff, &roots );

    OUTPUT_ERROR ( &func_coeff.a );
    OUTPUT_ERROR ( &func_coeff.b );
    OUTPUT_ERROR ( &func_coeff.c );

    output_roots ( &roots, n_roots );

    return 0;
}
