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
    matrix<mpz_int> fib_matrix = util::matrix_pow(n);
    return fib_matrix(0, 1);
}

boost::multiprecision::mpz_int fibonacci_matrix_pow_square_mpz(boost::multiprecision::mpz_int n)
{
    if(n == 0) return 0;
    if(n == 1) return 1;
    matrix<mpz_int> fib_matrix = util::matrix_pow_square(n);
    return fib_matrix(0, 1);
}

boost::multiprecision::mpz_int fibonacci_fast_doubling_memoized_mpz(boost::multiprecision::mpz_int n)
{
    std::map<boost::multiprecision::mpz_int, boost::multiprecision::mpz_int> memo{{0, 0}, {1, 1}, {2, 1}, {3, 2}, {4, 3}, {5, 5}};
    return util::fast_doubling_mpz_impl(n, memo);
}

boost::multiprecision::mpz_int fibonacci_fast_doubling_recursive_mpz(boost::multiprecision::mpz_int n)
{
    if(n == 0) return 0;
    if(n == 1) return 1;
    mpz_int k = ( n % 2 == 0 ? n/(mpz_int)2 : (n-(mpz_int)1)/(mpz_int)2 );
    auto [f_k, f_k_1] = util::fast_doubling_mpz_impl(k);

    if(n % 2 == 0) {
        mpz_int f_n = f_k * (2*f_k_1 - f_k);
        return f_n;
    } else {
        mpz_int f_n_1 =  f_k_1*f_k_1 + f_k * f_k;;
        return f_n_1;
    }

    return util::fast_doubling_mpz_impl(n).first;
}

boost::multiprecision::mpz_int fibonacci_fast_doubling_recursive_quad_mpz(boost::multiprecision::mpz_int n)
{
    return util::fast_doubling_quad_mpz_impl(n).first;
}


namespace util {

boost::multiprecision::mpz_int fast_doubling_mpz_impl(boost::multiprecision::mpz_int n, std::map<boost::multiprecision::mpz_int, boost::multiprecision::mpz_int> &memo)
{
    if(memo.contains(n)) return memo[n];
    mpz_int k = ( n % 2 == 0 ? n/(mpz_int)2 : (n-(mpz_int)1)/(mpz_int)2 );
    mpz_int f_k = fast_doubling_mpz_impl(k, memo);
    mpz_int f_k_1 = fast_doubling_mpz_impl(k+1, memo);

    // if n == 2k then we return F[k] * (2 F[k+1] - F[k])
    // if n == 2k+1 then we return F[k+1]^2 + F[k]^2

    if(n % 2 == 0) {
        mpz_int f_n = f_k * (2*f_k_1 - f_k);
        memo.insert({n, f_n});
        return f_n;
    } else {
        mpz_int f_n = f_k_1*f_k_1 + f_k * f_k;
        memo.insert({n, f_n});
        return f_n;
    }
}

std::pair<boost::multiprecision::mpz_int, boost::multiprecision::mpz_int> fast_doubling_mpz_impl(boost::multiprecision::mpz_int n)
{
    if(n == 0) return {0, 1};
    if(n == 1) return {1, 1};
    mpz_int k = ( n % 2 == 0 ? n/(mpz_int)2 : (n-(mpz_int)1)/(mpz_int)2 );
    auto [f_k, f_k_1] = fast_doubling_mpz_impl(k);
    mpz_int f_n = f_k * (2*f_k_1 - f_k);
    mpz_int f_n_1 =  f_k_1*f_k_1 + f_k * f_k;;

    if(n % 2 == 0) {
        return {f_n, f_n_1};
    } else {
        return {f_n_1, f_n_1 + f_n};
    }
}

std::pair<boost::multiprecision::mpz_int, boost::multiprecision::mpz_int> fast_doubling_quad_mpz_impl(boost::multiprecision::mpz_int n)
{
    return {0, 1};
}


matrix<mpz_int> matrix_identity()
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
matrix<mpz_int> matrix_pow(mpz_int n)
{
    if(n == 0) return matrix_identity();
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

matrix<mpz_int> matrix_pow_square(mpz_int n)
{
    if(n == 0) return matrix_identity();
    matrix<mpz_int> fib_m(2, 2), fib_exp_m(2, 2);
    fib_m(0, 0) = 1;
    fib_m(0, 1) = 1;
    fib_m(1, 0) = 1;
    fib_m(1, 1) = 0;
    if(n == 1) return fib_m;
    fib_exp_m = matrix_identity();
    
    while(n > 1) {
        if(n % 2 == 1)  { 
            fib_exp_m = prod(fib_exp_m, fib_m); 
            n--;
        }
        fib_m = prod(fib_m, fib_m); 
        n /= 2;
    }
    fib_exp_m = prod(fib_exp_m, fib_m);
    return fib_exp_m;
}


}
}