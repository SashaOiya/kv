#define TEST

struct Coeff_t {
    double a = 0;
    double b = 0;
    double c = 0;
};

struct Roots_t {
    double x1 = 0;
    double x2 = 0;
};

enum Mode_t {
    LINEAR      = 0,
    QUADRATIC   = 1,
    Error       = 2,
    START       = 3,
    HELP        = 4,
    BYE         = 5,
    OPTION_MEOW = 6
};

enum N_Roots_t {
    ROOT_ZER = 0,
    ROOT_ONE = 1,
    ROOT_TWO = 2,
    ROOT_ALL = 3,
    ROOT_ERR = 4
};
