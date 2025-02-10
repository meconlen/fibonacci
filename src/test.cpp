#include <iostream>

#include "fibonacci.hpp"
#include "fibonacci_test_data.hpp"

#include "../config.h"


#ifdef HAVE_GTEST_GTEST_H
#include <gtest/gtest.h>
#endif

using namespace boost::multiprecision;

#ifdef HAVE_GTEST_GTEST_H
TEST(fibonacci, iterative)
{
    mpz_int n = 100000;
    mpz_int fn = fibonacci_iterative(n);
    EXPECT_EQ(fn, F_100000);
	return;
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
