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

TEST(fibonacci, fibonacci_z5_exponent)
{
    EXPECT_EQ(fibonacci_z5_mpz(100000), F_100000_mpz);
}

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

using namespace quadratic;

TEST(quadratic, to_string)
{
    quadratic_integer<5> q(1, 1);
    EXPECT_EQ(q.to_string(), "1 + 1 sqrt(5)");
}

TEST(quadratic, constructor)
{
    quadratic_integer<5> q((int)1, (unsigned int)1);
    quadratic_integer<5> expected(1, 1);
    EXPECT_EQ(q, expected);
}

TEST(quadratic, equality)
{
    quadratic_integer<5> q(1, 1), r(1, 1);
    EXPECT_EQ(q == r, true);
    quadratic_integer<5> s(2, 1);
    EXPECT_EQ(q == s, false);
}

TEST(quadratic, not_equal)
{
    quadratic_integer<5> q(1, 1), r(1, 1);
    EXPECT_EQ(q != r, false);
    quadratic_integer<5> s(2, 1);
    EXPECT_EQ(q != s, true);
}
TEST(quadratic, operator_plus_equal)
{
    quadratic_integer<5> a(1, 1);
    quadratic_integer<5> b(2, 3);
    a += b;
    EXPECT_EQ(a, quadratic_integer<5>(3, 4));
}

TEST(quadratic, operator_minus_equal)
{
    quadratic_integer<5> a(5, 6);
    quadratic_integer<5> b(1, 2);
    a -= b;
    EXPECT_EQ(a, quadratic_integer<5>(4, 4));
}
// (1+1S[5])(1+1S[5]) = 1+1S[5]+1S[5]+5
//                    = 6+2S[5]
TEST(quadratic, oeprator_star_equal)
{
    quadratic_integer<5> q(1, 1);
    q *= q;
    EXPECT_EQ(q, quadratic_integer<5>(6, 2));
}

TEST(quadratic, operator_unary_plus)
{
    quadratic_integer<5> q(1, 1);
    EXPECT_EQ(+q, quadratic_integer<5>(1, 1) );
}

TEST(quadratic, operator_unary_minus)
{
    quadratic_integer<5> q(1, 1);
    EXPECT_EQ(-q, quadratic_integer<5>(-1, -1));
}

TEST(quadratic, operator_plus)
{
    quadratic_integer<5> a(1, 2), b(3, 4);
    EXPECT_EQ(a+b, quadratic_integer<5>(4, 6));
}

TEST(quadratic, operator_minus)
{
    quadratic_integer<5> a(3, 4), b(1, 2);
    EXPECT_EQ(a-b, quadratic_integer<5>(2, 2));
}

TEST(quadratic, operator_star)
{
    quadratic_integer<5> a(1, 1), b(2, 2);
    EXPECT_EQ(a*b, quadratic_integer<5>(12, 4));
}

TEST(quadratic, pow)
{
    quadratic_integer<5> a(2, 0);
    EXPECT_EQ(pow(a, 1), a);
    EXPECT_EQ(pow(a, 2), quadratic_integer<5>(4, 0));
    EXPECT_EQ(pow(pow(a, 2), 3), quadratic_integer<5>(64, 0) );

    quadratic_integer<5> phi(1, 1), psi(1, -1);
    EXPECT_EQ(pow(phi, 5),quadratic_integer<5>(176, 80));

    EXPECT_EQ(pow(phi, 1), quadratic_integer<5>(1, 1));
    EXPECT_EQ(pow(psi, 1), quadratic_integer<5>(1, -1));
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
