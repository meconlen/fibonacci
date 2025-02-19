#include <algorithm>
#include <cstdint>
#include <iostream>

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/gmp.hpp>
#include <boost/multiprecision/tommath.hpp>

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

TEST(fibonacci, recursive_uint64_t)
{
    EXPECT_EQ(fibonacci_recursive<uint64_t>(11), uint64_t{89});
}

TEST(fibonacci, recursive_int)
{
    EXPECT_EQ(fibonacci_recursive<int>(11), int{89});
}

#ifdef HAVE_BOOST_MULTIPRECISION_CPP_INT_HPP
TEST(fibonacci, recursive_cpp_int)
{
    EXPECT_EQ(fibonacci_recursive<cpp_int>(11), cpp_int(89));
}
#endif 

#ifdef HAVE_GMP_H
TEST(fibonacci, recursive_mpz_int)
{
    EXPECT_EQ(fibonacci_recursive<mpz_int>(11), mpz_int{89});
}
#endif // HAVE_GMP_H

#ifdef HAVE_TOMMATH_H
TEST(fibonacci, recursive_tom_int)
{
    EXPECT_EQ(fibonacci_recursive<tom_int>(11), tom_int{89});
}
#endif // HAVE_TOMMATH_H


TEST(fibonacci, iterative_uint64_t)
{
    EXPECT_EQ(fibonacci_iterative<uint64_t>(uint64_t{11}), uint64_t{89});
}

TEST(fibonacci, iterative_int)
{
    EXPECT_EQ(fibonacci_iterative<int>(11), int{89});
}

#ifdef HAVE_BOOST_MULTIPRECISION_CPP_INT_HPP
TEST(fibonacci, iterating_vector_assign_scalar)
{
    EXPECT_EQ(fibonacci_iterative<cpp_int>(11), cpp_int(89));
}
#endif 

#ifdef HAVE_GMP_H
TEST(fibonacci, iterative_mpz_int)
{
    EXPECT_EQ(fibonacci_iterative<mpz_int>(11), mpz_int{89});
}
#endif // HAVE_GMP_H

#ifdef HAVE_TOMMATH_H
TEST(fibonacci, iterative_tom_int)
{
    EXPECT_EQ(fibonacci_iterative<tom_int>(11), tom_int{89});
}
#endif // HAVE_TOMMATH_H

// TEST(fibonacci, iterative)
// {
//     unsigned int n = 100000;
//     mpz_int fn = fibonacci_iterative_mpz(n);
//     EXPECT_EQ(fn, F_100000_mpz);
// 	return;
// }

// TEST(fibonacci, matrix_pow)
// {
//     unsigned int n = 100000;
//     mpz_int fn = fibonacci_matrix_pow_mpz(n);
//     EXPECT_EQ(fn, F_100000_mpz);
// 	return;
// }




TEST(fibonacci, matrix_pow_uint64_t)
{
    unsigned int n = 11;
    uint64_t fn = fibonacci_matrix_pow<uint64_t>(n);
    EXPECT_EQ(fn, (unsigned int)89);
	return;
}

#ifdef HAVE_BOOST_MULTIPRECISION_CPP_INT_HPP
TEST(fibonacci, matrix_pow_cpp_int)
{
    unsigned int n = 100000;
    cpp_int fn = fibonacci_matrix_pow<cpp_int>(n);
    EXPECT_EQ(fn, F_100000_cpp);
	return;
}
#endif 

#ifdef HAVE_GMP_H
TEST(fibonacci, matrix_pow_mpz_int)
{
    unsigned int n = 100000;
    mpz_int fn = fibonacci_matrix_pow<mpz_int>(n);
    EXPECT_EQ(fn, F_100000_mpz);
	return;
}
#endif // HAVE_GMP_H

#ifdef HAVE_TOMMATH_H
TEST(fibonacci, matrix_pow_tom_int)
{
    unsigned int n = 100000;
    tom_int fn = fibonacci_matrix_pow<tom_int>(n);
    EXPECT_EQ(fn, F_100000_tom);
	return;
}
#endif // HAVE_TOMMATH_H

// TEST(fibonacci, fibonacci_fast_doubling_memoized_mpz)
// {
//     unsigned int n = 100000;
//     mpz_int fn = fibonacci_fast_doubling_memoized_mpz(n);
//     EXPECT_EQ(fn, F_100000_mpz);
// 	return;
// }




TEST(fibonacci, fibonacci_fast_doubling_uint64_t)
{
    unsigned int n = 11;
    uint64_t fn = fibonacci_fast_doubling<uint64_t>(n);
    EXPECT_EQ(fn, uint64_t{89});
}

#ifdef HAVE_BOOST_MULTIPRECISION_CPP_INT_HPP
TEST(fibonacci, fibonacci_fast_doubling_cpp_int)
{
    unsigned int n = 100000;
    cpp_int fn = fibonacci_fast_doubling<cpp_int>(n);
    EXPECT_EQ(fn, F_100000_cpp);
}
#endif 

#ifdef HAVE_GMP_H
TEST(fibonacci, fibonacci_fast_doubling_mpz_int)
{
    unsigned int n = 100000;
    mpz_int fn = fibonacci_fast_doubling<mpz_int>(n);
    EXPECT_EQ(fn, F_100000_mpz);
}
#endif // HAVE_GMP_H

#ifdef HAVE_TOMMATH_H
TEST(fibonacci, fibonacci_fast_doubling_tom_int)
{
    unsigned int n = 100000;
    tom_int fn = fibonacci_fast_doubling<tom_int>(n);
    EXPECT_EQ(fn, F_100000_tom);
}
#endif // HAVE_TOMMATH_H

#ifdef HAVE_GMP_H
TEST(fibonacci, fibonacci_fast_doubling_even)
{
    unsigned int n = 100000;
    mpz_int fn = fibonacci_fast_doubling<mpz_int>(n);
    EXPECT_EQ(fn, F_100000_mpz);
	return;
}

TEST(fibonacci, fibonacci_fast_doubling_odd)
{
    unsigned int n = 11;
    mpz_int fn = fibonacci_fast_doubling<mpz_int>(n);
    EXPECT_EQ(fn, 89);
	return;
}
#endif // HAVE_GMP_H

#ifdef HAVE_BOOST_MULTIPRECISION_CPP_INT_HPP
TEST(fibonacci, fibonacci_fast_quad_large_cpp_int)
{
    unsigned int n = 100000;
    cpp_int fn = fibonacci_fast_quad<cpp_int>(n);
    EXPECT_EQ(fn, F_100000_cpp);
	return;
}
#endif // HAVE_BOOST_MULTIPRECISION_CPP_INT_HPP

#ifdef HAVE_GMP_H
TEST(fibonacci, fibonacci_fast_quad_large)
{
    unsigned int n = 100000;
    mpz_int fn = fibonacci_fast_quad<mpz_int>(n);
    EXPECT_EQ(fn, F_100000_mpz);
	return;
}
#endif // HAVE_GMP_INT

#ifdef HAVE_TOMMATH_H
TEST(fibonacci, fibonacci_fast_quad_large_tom_int)
{
    unsigned int n = 100000;
    tom_int fn = fibonacci_fast_quad<tom_int>(n);
    EXPECT_EQ(fn, F_100000_tom);
	return;
}
#endif // HAVE_TOMMATH_H

#ifdef HAVE_GMP_H
TEST(fibonacci, fibonacci_fast_quad_mod_zero)
{
    unsigned int n = 16;
    mpz_int fn = fibonacci_fast_quad<mpz_int>(n);
    EXPECT_EQ(fn, 987);
	return;
}

TEST(fibonacci, fibonacci_fast_quad_mod_one)
{
    unsigned int n = 17;
    mpz_int fn = fibonacci_fast_quad<mpz_int>(n);
    EXPECT_EQ(fn, 1597);
	return;
}

TEST(fibonacci, fibonacci_fast_quad_mod_two)
{
    unsigned int n = 18;
    mpz_int fn = fibonacci_fast_quad<mpz_int>(n);
    EXPECT_EQ(fn, 2584);
	return;
}

TEST(fibonacci, fibonacci_fast_quad_mod_three)
{
    unsigned int n = 19;
    mpz_int fn = fibonacci_fast_quad<mpz_int>(n);
    EXPECT_EQ(fn, 4181);
	return;
}

TEST(fibonacci, fibonacci_fast_quad_odd)
{
    unsigned int n = 11;
    mpz_int fn = fibonacci_fast_quad<mpz_int>(n);
    EXPECT_EQ(fn, 89);
	return;
}
#endif 

TEST(fibonacci, fibonacci_binet)
{
    unsigned int n = 100000;
    mpz_int fn = fibonacci_binet<mpf_float, mpz_int, unsigned int>(n);
    EXPECT_EQ(fn, F_100000_mpz);
	return;
}

#ifdef HAVE_GMP_H
TEST(fibonacci, fibonacci_z5)
{
    mpz_int fn = fibonacci_z5<mpz_int, uint64_t>(100000);
    EXPECT_EQ(fn, F_100000_mpz);
}
#endif // HAVE_GMP_H

TEST(fibonacci_matrix, matrix_pow_odd)
{
    matrix<mpz_int> fib_m_1 = util::matrix_pow<mpz_int>(0);
    matrix<mpz_int> fib_identity = util::matrix_identity<mpz_int>();
    EXPECT_TRUE(std::equal(fib_m_1.begin1(), fib_m_1.end1(), fib_identity.begin1() ));

    matrix<mpz_int> expected(2, 2);
    expected(0, 0) = 8;
    expected(0, 1) = 5;
    expected(1, 0) = 5;
    expected(1, 1) = 3;
    matrix<mpz_int> rv = util::matrix_pow<mpz_int>(5);
    EXPECT_TRUE(std::equal(rv.begin1(), rv.end1(), expected.begin1())); 
}


TEST(fibonacci_matrix, matrix_pow_square_power_2)
{
    matrix<mpz_int> expected(2, 2);
    expected(0, 0) = 5;
    expected(0, 1) = 3;
    expected(1, 0) = 3;
    expected(1, 1) = 2;
    matrix<mpz_int> rv = util::matrix_pow<mpz_int>(4);
    EXPECT_TRUE(std::equal(rv.begin1(), rv.end1(), expected.begin1())); 
}




using namespace quadratic;

TEST(quadratic, to_string)
{
    quadratic_integer<5, mpz_int> q(1, 1);
    EXPECT_EQ(q.to_string(), "1 + 1 sqrt(5)");
}

TEST(quadratic, constructor)
{
    quadratic_integer<5, mpz_int> q((int)1, (unsigned int)1);
    quadratic_integer<5, mpz_int> expected(1, 1);
    EXPECT_EQ(q, expected);
}

TEST(quadratic, equality)
{
    quadratic_integer<5, mpz_int> q(1, 1), r(1, 1);
    EXPECT_EQ(q == r, true);
    quadratic_integer<5, mpz_int> s(2, 1);
    EXPECT_EQ(q == s, false);
}

TEST(quadratic, not_equal)
{
    quadratic_integer<5, mpz_int> q(1, 1), r(1, 1);
    EXPECT_EQ(q != r, false);
    quadratic_integer<5, mpz_int> s(2, 1);
    EXPECT_EQ(q != s, true);
}
TEST(quadratic, operator_plus_equal)
{
    quadratic_integer<5, mpz_int> a(1, 1);
    quadratic_integer<5, mpz_int> b(2, 3);
    a += b;
    quadratic_integer<5, mpz_int> expected(3, 4);
    EXPECT_EQ(a, expected);
}

TEST(quadratic, operator_minus_equal)
{
    quadratic_integer<5, mpz_int> a(5, 6);
    quadratic_integer<5, mpz_int> b(1, 2);
    a -= b;
    quadratic_integer<5, mpz_int> expected(4, 4);
    EXPECT_EQ(a, expected);
}
// (1+1S[5])(1+1S[5]) = 1+1S[5]+1S[5]+5
//                    = 6+2S[5]
TEST(quadratic, oeprator_star_equal)
{
    quadratic_integer<5, mpz_int> q(1, 1);
    q *= q;
    quadratic_integer<5, mpz_int> expected(6, 2);
    EXPECT_EQ(q, expected);
}

TEST(quadratic, operator_unary_plus)
{
    quadratic_integer<5, mpz_int> q(1, 1);
    quadratic_integer<5, mpz_int> expected(1, 1);
    EXPECT_EQ(q, expected);
}

TEST(quadratic, operator_unary_minus)
{
    quadratic_integer<5, mpz_int> q(1, 1);
    quadratic_integer<5, mpz_int> expected(-1, -1);
    EXPECT_EQ(-q, expected);
}

TEST(quadratic, operator_plus)
{
    quadratic_integer<5, mpz_int> a(1, 2), b(3, 4);
    quadratic_integer<5, mpz_int> expected(4, 6);
    EXPECT_EQ(a+b, expected);
}

TEST(quadratic, operator_minus)
{
    quadratic_integer<5, mpz_int> a(3, 4), b(1, 2);
    quadratic_integer<5, mpz_int> expected(2, 2);
    EXPECT_EQ(a-b, expected);
}

TEST(quadratic, operator_star)
{
    quadratic_integer<5, mpz_int> a(1, 1), b(2, 2);
    quadratic_integer<5, mpz_int> expected(12, 4);
    EXPECT_EQ(a*b, expected);
}

TEST(quadratic, pow)
{
    quadratic_integer<5, mpz_int> a(2, 0);
    EXPECT_EQ(pow(a, 1), a);
    quadratic_integer<5, mpz_int> expected_1(4, 0);
    EXPECT_EQ(pow(a, 2),expected_1);
    quadratic_integer<5, mpz_int> expected_2(64, 0);

    EXPECT_EQ(pow(pow(a, 2), 3), expected_2);

    quadratic_integer<5, mpz_int> phi(1, 1), psi(1, -1);
    quadratic_integer<5, mpz_int> expected_3(176, 80);
    EXPECT_EQ(pow(phi, 5), expected_3);

    quadratic_integer<5, mpz_int> expected_4(1, 1);
    EXPECT_EQ(pow(phi, 1), expected_4);
    quadratic_integer<5, mpz_int> expected_5(1, -1);
    EXPECT_EQ(pow(psi, 1), expected_5);
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
