AC_PREREQ(2.61)
AC_INIT([fibonacci], [0.1], [mike@conlen.org])
AC_CONFIG_SRCDIR([src/test.cpp])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE
LT_INIT
AC_PROG_CC
AC_PROG_CXX
AC_LANG([C++])

CXXFLAGS="$CXXFLAGS -Wall -Wextra -Wuninitialized -Wmissing-declarations -Wno-deprecated-copy -Wno-unused-parameter -Werror=pedantic -pedantic-errors --std=c++20"
LDFLAGS="$LDFLAGS"
AC_CHECK_HEADERS([stdio.h])
AC_CHECK_HEADERS([stdlib.h])
AC_CHECK_HEADERS([malloc.h])
AC_CHECK_HEADERS([sys/malloc.h])
AC_CHECK_HEADERS([malloc/malloc.h])

AC_LANG_PUSH([C++])
AC_CHECK_HEADERS([gtest/gtest.h], [], [AC_MSG_ERROR([Google Test not installed])])
AC_CHECK_HEADERS([benchmark/benchmark.h], [], [AC_MSG_ERROR([Google Benchmark not installed])])
AC_CHECK_HEADERS([boost/multiprecision/cpp_int.hpp], [AC_MSG_RESULT([Found Boost Multiprecision headers])], [AC_MSG_ERROR([Boost Multiprecision Libraries not installed])])
AC_CHECK_HEADERS([gmp.h], [], [AC_MSG_ERROR([GMP headers not found])])
AC_LANG_POP

AC_FUNC_MALLOC
AC_FUNC_MMAP
AC_CHECK_FUNCS([fstat])

# DeleteThreadLocalValue is a C function defined in google test. If that ever changes 
# we need to update this. 

AC_SEARCH_LIBS([DeleteThreadLocalValue], [gtest], [], 
    AC_MSG_WARN([libgtest (Google C++ Unit Testing Framework) is not installed.]))
AC_SEARCH_LIBS([pthread_create], [pthread])
AC_SEARCH_LIBS([__gmpz_init], [gmp], [], [AC_MSG_ERROR([GMP library not found])])
AC_CONFIG_FILES([Makefile
	src/Makefile
])
AC_OUTPUT