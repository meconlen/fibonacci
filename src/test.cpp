#include <algorithm>
#include <iostream>

#include "fibonacci.hpp"
#include "fibonacci_test_data.hpp"
#include "quadratic.hpp"

#include "../config.h"


#ifdef HAVE_GTEST_GTEST_H
#include <gtest/gtest.h>
#endif

using namespace boost::multiprecision;
using namespace boost::numeric::ublas;
using namespace fibonacci;

#ifdef HAVE_GTEST_GTEST_H
TEST(fibonacci, iterative)
{
    mpz_int n = 100000;
    mpz_int fn = fibonacci_iterative_mpz(n);
    EXPECT_EQ(fn, F_100000_mpz);
	return;
}

TEST(fibonacci, matrix_pow)
{
    mpz_int n = 100000;
    mpz_int fn = fibonacci_matrix_pow_mpz(n);
    EXPECT_EQ(fn, F_100000_mpz);
	return;
}

TEST(fibonacci, matrix_pow_square)
{
    mpz_int n = 100000;
    mpz_int fn = fibonacci_matrix_pow_square_mpz(n);
    EXPECT_EQ(fn, F_100000_mpz);
	return;
}

TEST(fibonacci, fibonacci_fast_doubling_memoized_mpz)
{
    mpz_int n = 100000;
    mpz_int fn = fibonacci_fast_doubling_memoized_mpz(n);
    EXPECT_EQ(fn, F_100000_mpz);
	return;
}

TEST(fibonacci, fibonacci_fast_doubling_recursive_even_mpz)
{
    mpz_int n = 100000;
    mpz_int fn = fibonacci_fast_doubling_recursive_mpz(n);
    EXPECT_EQ(fn, F_100000_mpz);
	return;
}

TEST(fibonacci, fibonacci_fast_doubling_recursive_odd_mpz)
{
    mpz_int n = 11;
    mpz_int fn = fibonacci_fast_doubling_recursive_mpz(n);
    EXPECT_EQ(fn, 89);
	return;
}

TEST(fibonacci, fibonacci_fast_doubling_recursive_quad_large_mpz)
{
    mpz_int n = 100000;
    mpz_int fn = fibonacci_fast_doubling_recursive_quad_mpz(n);
    EXPECT_EQ(fn, F_100000_mpz);
	return;
}

TEST(fibonacci, fibonacci_fast_doubling_recursive_quad_mod_zero_mpz)
{
    mpz_int n = 16;
    mpz_int fn = fibonacci_fast_doubling_recursive_quad_mpz(n);
    EXPECT_EQ(fn, 987);
	return;
}

TEST(fibonacci, fibonacci_fast_doubling_recursive_quad_mod_one_mpz)
{
    mpz_int n = 17;
    mpz_int fn = fibonacci_fast_doubling_recursive_quad_mpz(n);
    EXPECT_EQ(fn, 1597);
	return;
}

TEST(fibonacci, fibonacci_fast_doubling_recursive_quad_mod_two_mpz)
{
    mpz_int n = 18;
    mpz_int fn = fibonacci_fast_doubling_recursive_quad_mpz(n);
    EXPECT_EQ(fn, 2584);
	return;
}

TEST(fibonacci, fibonacci_fast_doubling_recursive_quad_mod_three_mpz)
{
    mpz_int n = 19;
    mpz_int fn = fibonacci_fast_doubling_recursive_quad_mpz(n);
    EXPECT_EQ(fn, 4181);
	return;
}

TEST(fibonacci, fibonacci_fast_doubling_recursive_quad_odd_mpz)
{
    mpz_int n = 11;
    mpz_int fn = fibonacci_fast_doubling_recursive_quad_mpz(n);
    EXPECT_EQ(fn, 89);
	return;
}

TEST(fibonacci, fibonacci_binet)
{
    mpz_int n = 100000;
    mpz_int fn = fibonacci_binet_mpf(n);
    EXPECT_EQ(fn, F_100000_mpz);
	return;
}

// TEST(fibonacci, fibonacci_binet_20000000)
// {
//     EXPECT_EQ(fibonacci_fast_doubling_recursive_mpz(20000000), fibonacci_binet_mpf(20000000));
//     return;
// }

TEST(fibonacci_matrix, fibonacci_matrix_pow)
{
    matrix<mpz_int> fib_m_1 = util::matrix_pow(0);
    matrix<mpz_int> fib_identity = util::matrix_identity();
    EXPECT_TRUE(std::equal(fib_m_1.begin1(), fib_m_1.end1(), fib_identity.begin1()));

    matrix<mpz_int> expected(2, 2);
    expected(0, 0) = 8;
    expected(0, 1) = 5;
    expected(1, 0) = 5;
    expected(1, 1) = 3;
    matrix<mpz_int> rv = util::matrix_pow(5);
    EXPECT_TRUE(std::equal(rv.begin1(), rv.end1(), expected.begin1())); 
}

TEST(fibonacci_matrix, matrix_pow_square_odd)
{
    matrix<mpz_int> fib_m_1 = util::matrix_pow_square(0);
    matrix<mpz_int> fib_identity = util::matrix_identity();
    EXPECT_TRUE(std::equal(fib_m_1.begin1(), fib_m_1.end1(), fib_identity.begin1() ));

    matrix<mpz_int> expected(2, 2);
    expected(0, 0) = 8;
    expected(0, 1) = 5;
    expected(1, 0) = 5;
    expected(1, 1) = 3;
    matrix<mpz_int> rv = util::matrix_pow_square(5);
    EXPECT_TRUE(std::equal(rv.begin1(), rv.end1(), expected.begin1())); 
}


TEST(fibonacci_matrix, matrix_pow_square_power_2)
{
    matrix<mpz_int> expected(2, 2);
    expected(0, 0) = 5;
    expected(0, 1) = 3;
    expected(1, 0) = 3;
    expected(1, 1) = 2;
    matrix<mpz_int> rv = util::matrix_pow_square(4);
    EXPECT_TRUE(std::equal(rv.begin1(), rv.end1(), expected.begin1())); 
}

TEST(quadratic, to_string)
{
    quadratic_integer<5> q(1, 1);
    EXPECT_EQ(q.to_string(), "1 + 1 sqrt(5)");
}

#endif

int main(int argc, char **argv) {
#ifdef HAVE_GTEST_GTEST_H
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
#else
    return 1;
#endif
}
