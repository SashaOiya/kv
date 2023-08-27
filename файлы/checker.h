#define MY_DEBUG

#ifdef MY_DEBUG
    #define $ printf ("%s:%d\n", __FILE__, __LINE__ );
    #define ASSERT( a ) check_pointer ( a, __LINE__ )
    #define TEST() Test_All_Cases ( );
#else
    #define ASSERT( a ) ;
    #define TEST();
    #define $ ;
#endif


