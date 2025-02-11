#include <algorithm>
#include <iostream>

#include "fibonacci.hpp"
#include "fibonacci_test_data.hpp"

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

TEST(fibonacci, fibonacci_fast_doubling_mpz)
{
    mpz_int n = 100000;
    mpz_int fn = fibonacci_fast_doubling_mpz(n);
    EXPECT_EQ(fn, F_100000_mpz);
	return;
}





TEST(fibonacci_matrix, fibonacci_matrix_pow)
{
    matrix<mpz_int> fib_m_1 = util::fibonacci_matrix_pow(0);
    matrix<mpz_int> fib_identity = util::fibonacci_matrix_identity();
    EXPECT_TRUE(std::equal(fib_m_1.begin1(), fib_m_1.end1(), fib_identity.begin1()));

    matrix<mpz_int> expected(2, 2);
    expected(0, 0) = 8;
    expected(0, 1) = 5;
    expected(1, 0) = 5;
    expected(1, 1) = 3;
    matrix<mpz_int> rv = util::fibonacci_matrix_pow(5);
    EXPECT_TRUE(std::equal(rv.begin1(), rv.end1(), expected.begin1())); 
}

TEST(fibonacci_matrix, fibonacci_matrix_pow_square_odd)
{
    matrix<mpz_int> fib_m_1 = util::fibonacci_matrix_pow_square(0);
    matrix<mpz_int> fib_identity = util::fibonacci_matrix_identity();
    EXPECT_TRUE(std::equal(fib_m_1.begin1(), fib_m_1.end1(), fib_identity.begin1() ));

    matrix<mpz_int> expected(2, 2);
    expected(0, 0) = 8;
    expected(0, 1) = 5;
    expected(1, 0) = 5;
    expected(1, 1) = 3;
    matrix<mpz_int> rv = util::fibonacci_matrix_pow_square(5);
    EXPECT_TRUE(std::equal(rv.begin1(), rv.end1(), expected.begin1())); 
}


TEST(fibonacci_matrix, fibonacci_matrix_pow_square_power_2)
{
    matrix<mpz_int> expected(2, 2);
    expected(0, 0) = 5;
    expected(0, 1) = 3;
    expected(1, 0) = 3;
    expected(1, 1) = 2;
    matrix<mpz_int> rv = util::fibonacci_matrix_pow_square(4);
    EXPECT_TRUE(std::equal(rv.begin1(), rv.end1(), expected.begin1())); 
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
