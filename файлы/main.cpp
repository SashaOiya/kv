#include <stdio.h>
#include "checker.h"
#include "duck_cat.h"
#include "mem.h"
#include "solve.h"
#include "input.h"
#include "output.h"
#include "test.h"

int main ( )
{
/// @note hi ������� ��������� ��� ��������� �������������� ������
    printf ( "Hi. This program solves both a quadratic equation and a linear one.\n"
             "Write 'help' to see the list of available functions:\n" );

    bool start_indicator = true;
    int equation_type = 0;

//! @note ���������� ������� ����� �� ������, ������� ����� ����������, ������� help
    do {
//! @note ����� ������������ �� ��� ���, ���� �� �� �������� 'bye-bye' ��� 'start'
//! @note ����� bye-bye �������� ������� �� ���������, ������ ����� ����� ������ ���� �� ������ �������, ���� �����.
//! @note ����� start ��������� ������� ���������
/// \endcode
        equation_type = interface_input ( start_indicator );

        if ( equation_type == BYE  ) {

            return 0;
        }
    } while ( equation_type != LINEAR && equation_type != QUADRATIC );

    start_indicator = false;

    struct Coeff_t func_coeff = {};

    TEST();

    struct Roots_t   roots = {};
    enum N_Roots_t n_roots = ROOT_ERR;

    do {
        switch ( equation_type ) {
$           case LINEAR:
$                get_coeff ( "K", &func_coeff.b );
$                get_coeff ( "B", &func_coeff.c );

$                n_roots = solve_linear ( &func_coeff, &roots );

$           break;
$           case QUADRATIC:
$               get_coeff ( "A", &func_coeff.a );
$               get_coeff ( "B", &func_coeff.b );
$               get_coeff ( "C", &func_coeff.c );

$               n_roots = solve_quadratic ( &func_coeff, &roots );

$           break;
        }

    } while ( n_roots == ROOT_ERR );

    ASSERT ( &roots );

    output_roots ( &roots, n_roots );

$   do {
        equation_type = interface_input ( start_indicator );

        if ( equation_type == BYE  ) {

            return 0;
        }
$   } while ( equation_type != BYE );

    return 0;
}
