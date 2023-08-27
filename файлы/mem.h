#ifndef MEM_H
#define MEM_H

void check_pointer ( void *func_coeff, int line );
void my_memset ( void *val, const char number, const size_t value );
bool buf_overflow ( const int MAX_BUF_VALUE, int *input_element_number, bool n_overflow ); //lowercase-----MAX_BUF_VALUE

#endif
