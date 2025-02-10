#include "fibonacci.hpp"

using namespace boost::multiprecision;

boost::multiprecision::mpz_int fibonacci_iterative(boost::multiprecision::mpz_int n)
{
    if(n == 0) return 0;
    if(n == 1) return 1;
    mpz_int f_2 = 0;
    mpz_int f_1 = 1;
    mpz_int f_0 = 1;
    for(boost::multiprecision::mpz_int i = 2; i < n; i++) {
        f_2 = f_1;
        f_1 = f_0;
        f_0 = f_2 + f_1;
    }

    return f_0;
}