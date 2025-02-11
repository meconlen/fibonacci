#include "fibonacci.hpp"

using namespace boost::multiprecision;
using namespace boost::numeric::ublas;

namespace fibonacci {
boost::multiprecision::mpz_int fibonacci_iterative_mpz(boost::multiprecision::mpz_int n)
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

boost::multiprecision::mpz_int fibonacci_matrix_pow_mpz(boost::multiprecision::mpz_int n)
{
    if(n == 0) return 0;
    if(n == 1) return 1;
    matrix<mpz_int> fib_matrix = util::fibonacci_matrix_pow(n);
    return fib_matrix(0, 1);
}

boost::multiprecision::mpz_int fibonacci_matrix_pow_square_mpz(boost::multiprecision::mpz_int n)
{
    if(n == 0) return 0;
    if(n == 1) return 1;
    matrix<mpz_int> fib_matrix = util::fibonacci_matrix_pow_square(n);
    return fib_matrix(0, 1);
}

namespace util {


matrix<mpz_int> fibonacci_matrix_identity()
{
    matrix<mpz_int> identity(2, 2);
    identity(0, 0) = 1;
    identity(0, 1) = 0;
    identity(1, 0) = 0;
    identity(1, 1) = 1;
    return identity;
}

// exponential of the Fibonacci matrix. 
// Note we don't find eigenvectors here because that takes us into the realm of 
// floating point without knowing the precision we want. 
matrix<mpz_int> fibonacci_matrix_pow(mpz_int n)
{
    if(n == 0) return fibonacci_matrix_identity();
    matrix<mpz_int> fib_m(2, 2), fib_exp_m(2, 2);
    fib_m(0, 0) = 1;
    fib_m(0, 1) = 1;
    fib_m(1, 0) = 1;
    fib_m(1, 1) = 0;
    if(n == 1) return fib_m;
    fib_exp_m = fib_m;
    for(mpz_int i = 1; i < n; i++) {
        fib_exp_m = prod(fib_exp_m, fib_m);
    }
    return fib_exp_m;
}

matrix<mpz_int> fibonacci_matrix_pow_square(mpz_int n)
{
    if(n == 0) return fibonacci_matrix_identity();
    matrix<mpz_int> fib_m(2, 2), fib_exp_m(2, 2);
    fib_m(0, 0) = 1;
    fib_m(0, 1) = 1;
    fib_m(1, 0) = 1;
    fib_m(1, 1) = 0;
    if(n == 1) return fib_m;
    fib_exp_m = fib_m;

    // for(mpz_int i = 1; i < n; i++) {
    n--;
    while(n > 0) {
        if(n % 2 == 1)  { 
            fib_exp_m = prod(fib_exp_m, fib_m); 
            n--;
        }
        else { 
            fib_exp_m = prod(fib_exp_m, fib_exp_m); 
            n /= 2;
        }
    }
    return fib_exp_m;
}


}
}