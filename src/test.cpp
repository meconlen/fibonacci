#include <iostream>

#include "../config.h"

#ifdef HAVE_GTEST_GTEST_H
#include <gtest/gtest.h>
#endif

#ifdef HAVE_GTEST_GTEST_H
TEST(suite, test)
{
	FAIL();
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
