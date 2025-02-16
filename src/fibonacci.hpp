#ifndef FIBONACCI_HPP
#define FIBONACCI_HPP

#include <boost/multiprecision/gmp.hpp>

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/multiprecision/gmp.hpp>

#include <map>
#include <utility>

// NB: we will index the sequence at 0 so F_0 = 0, F_1 = 1

namespace fibonacci {
    boost::multiprecision::mpz_int fibonacci_recursive(boost::multiprecision::mpz_int n);
    boost::multiprecision::mpz_int fibonacci_matrix_pow_mpz(boost::multiprecision::mpz_int n);
    boost::multiprecision::mpz_int fibonacci_matrix_pow_square_mpz(boost::multiprecision::mpz_int n);
    boost::multiprecision::mpz_int fibonacci_iterative_mpz(boost::multiprecision::mpz_int n);
    boost::multiprecision::mpz_int fibonacci_fast_doubling_memoized_mpz(boost::multiprecision::mpz_int n);
    boost::multiprecision::mpz_int fibonacci_fast_doubling_recursive_mpz(boost::multiprecision::mpz_int n);
    boost::multiprecision::mpz_int fibonacci_fast_doubling_recursive_quad_mpz(const boost::multiprecision::mpz_int &n);
    boost::multiprecision::mpz_int fibonacci_binet_mpf(const boost::multiprecision::mpz_int &n);
    // the pow() function we use onl accepts unsigned int
    boost::multiprecision::mpz_int fibonacci_z5_mpz(const unsigned int &n);
    namespace util {
        boost::multiprecision::mpz_int fast_doubling_mpz_impl(boost::multiprecision::mpz_int n, std::map<boost::multiprecision::mpz_int, boost::multiprecision::mpz_int> &memo);
        std::pair<boost::multiprecision::mpz_int, boost::multiprecision::mpz_int> fast_doubling_mpz_impl(boost::multiprecision::mpz_int n);
        std::pair<boost::multiprecision::mpz_int, boost::multiprecision::mpz_int> fast_doubling_quad_mpz_impl(const boost::multiprecision::mpz_int &n);
        boost::numeric::ublas::matrix<boost::multiprecision::mpz_int> matrix_identity();
        boost::numeric::ublas::matrix<boost::multiprecision::mpz_int> matrix_pow(boost::multiprecision::mpz_int n);
        boost::numeric::ublas::matrix<boost::multiprecision::mpz_int> matrix_pow_square(boost::multiprecision::mpz_int n);
    }
}

#endif // FIBONACCI_HPP
