#include <boost/multiprecision/gmp.hpp>

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

#include <map>

// NB: we will index the sequence at 0 so F_0 = 0, F_1 = 1

namespace fibonacci {
    boost::multiprecision::mpz_int fibonacci_matrix_pow_mpz(boost::multiprecision::mpz_int n);
    boost::multiprecision::mpz_int fibonacci_matrix_pow_square_mpz(boost::multiprecision::mpz_int n);
    boost::multiprecision::mpz_int fibonacci_iterative_mpz(boost::multiprecision::mpz_int n);
    boost::multiprecision::mpz_int fibonacci_fast_doubling_mpz(boost::multiprecision::mpz_int n);

    namespace util {
        boost::multiprecision::mpz_int fibonacci_fast_doubling_mpz_impl(boost::multiprecision::mpz_int n, std::map<boost::multiprecision::mpz_int, boost::multiprecision::mpz_int> &memo);
        boost::numeric::ublas::matrix<boost::multiprecision::mpz_int> fibonacci_matrix_identity();
        boost::numeric::ublas::matrix<boost::multiprecision::mpz_int> fibonacci_matrix_pow(boost::multiprecision::mpz_int n);
        boost::numeric::ublas::matrix<boost::multiprecision::mpz_int> fibonacci_matrix_pow_square(boost::multiprecision::mpz_int n);
    }
}