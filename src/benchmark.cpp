#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/gmp.hpp>
#include <boost/multiprecision/tommath.hpp>

#include <benchmark/benchmark.h>
#include "fibonacci.hpp"

#include "../config.h"

using namespace boost::multiprecision;
using namespace boost::numeric::ublas;
using namespace fibonacci;

static void BM_FIBONACCI_RECURSIVE_UINT64_T(benchmark::State& state) {
    unsigned int n = 30;

    for (auto _ : state) {
        mpz_int fn = fibonacci_recursive<uint64_t>(n);
    }
}
BENCHMARK(BM_FIBONACCI_RECURSIVE_UINT64_T);

#ifdef HAVE_BOOST_MULTIPRECISION_CPP_INT_HPP
static void BM_FIBONACCI_RECURSIVE_CPP(benchmark::State& state) {
    unsigned int n = 30;

    for (auto _ : state) {
        cpp_int fn = fibonacci_recursive<cpp_int>(n);
    }
}
BENCHMARK(BM_FIBONACCI_RECURSIVE_CPP);
#endif 

#ifdef HAVE_GMP_H
static void BM_FIBONACCI_RECURSIVE_MPZ(benchmark::State& state) {
    unsigned int n = 30;

    for (auto _ : state) {
        mpz_int fn = fibonacci_recursive<mpz_int>(n);
    }
}
BENCHMARK(BM_FIBONACCI_RECURSIVE_MPZ);
#endif // HAVE_GMP_H

#ifdef HAVE_TOMMATH_H
static void BM_FIBONACCI_RECURSIVE_TOM(benchmark::State& state) {
    unsigned int n = 30;

    for (auto _ : state) {
        tom_int fn = fibonacci_recursive<tom_int>(n);
    }
}
BENCHMARK(BM_FIBONACCI_RECURSIVE_TOM);
#endif 

#ifdef HAVE_BOOST_MULTIPRECISION_CPP_INT_HPP
static void BM_FIBONACCI_ITERATIVE_CPP(benchmark::State& state) {
    unsigned int n = 100000;

    for (auto _ : state) {
        cpp_int fn = fibonacci_iterative<cpp_int>(n);
    }
}
BENCHMARK(BM_FIBONACCI_ITERATIVE_CPP);
#endif 

#ifdef HAVE_GMP_H
static void BM_FIBONACCI_ITERATIVE_MPZ(benchmark::State& state) {
    unsigned int n = 100000;

    for (auto _ : state) {
        mpz_int fn = fibonacci_iterative<mpz_int>(n);
    }
}
BENCHMARK(BM_FIBONACCI_ITERATIVE_MPZ);
#endif 

#ifdef HAVE_TOMMATH_H
static void BM_FIBONACCI_ITERATIVE_TOM(benchmark::State& state) {
    unsigned int n = 100000;

    for (auto _ : state) {
        tom_int fn = fibonacci_iterative<tom_int>(n);
    }
}
BENCHMARK(BM_FIBONACCI_ITERATIVE_TOM);
#endif 

// static void BM_FIBONACCI_MATRIX_POW_MPZ(benchmark::State& state) {
//     unsigned int n = 100000;

//     for (auto _ : state) {
//         mpz_int fn = fibonacci_matrix_pow_mpz(n);
//     }
// }
// BENCHMARK(BM_FIBONACCI_MATRIX_POW_MPZ);

#ifdef HAVE_BOOST_MULTIPRECISION_CPP_INT_HPP
static void BM_FIBONACCI_MATRIX_POW_CPP(benchmark::State& state) {
    unsigned int n = 100000;
    for (auto _ : state) {
        cpp_int fn = fibonacci_matrix_pow<cpp_int>(n);
    }
}
BENCHMARK(BM_FIBONACCI_MATRIX_POW_CPP);
#endif

#ifdef HAVE_GMP_H
static void BM_FIBONACCI_MATRIX_POW_MPZ(benchmark::State& state) {
    unsigned int n = 100000;
    for (auto _ : state) {
        mpz_int fn = fibonacci_matrix_pow<mpz_int>(n);
    }
}
BENCHMARK(BM_FIBONACCI_MATRIX_POW_MPZ);
#endif

#ifdef HAVE_TOMMATH_H
static void BM_FIBONACCI_MATRIX_POW_TOM(benchmark::State& state) {
    unsigned int n = 100000;
    for (auto _ : state) {
        tom_int fn = fibonacci_matrix_pow<tom_int>(n);
    }
}
BENCHMARK(BM_FIBONACCI_MATRIX_POW_TOM);
#endif

#ifdef HAVE_BOOST_MULTIPRECISION_CPP_INT_HPP
static void BM_FIBONACCI_MATRIX_POW_CPP_20000000(benchmark::State& state) {
    unsigned int n = 20000000;

    for (auto _ : state) {
        cpp_int fn = fibonacci_matrix_pow<cpp_int>(n);
    }
}
BENCHMARK(BM_FIBONACCI_MATRIX_POW_CPP_20000000);
#endif

#ifdef HAVE_GMP_H
static void BM_FIBONACCI_MATRIX_POW_MPZ_20000000(benchmark::State& state) {
    unsigned int n = 20000000;

    for (auto _ : state) {
        mpz_int fn = fibonacci_matrix_pow<mpz_int>(n);
    }
}
BENCHMARK(BM_FIBONACCI_MATRIX_POW_MPZ_20000000);
#endif

#ifdef HAVE_TOMMATH_H
static void BM_FIBONACCI_MATRIX_POW_TOM_20000000(benchmark::State& state) {
    unsigned int n = 20000000;

    for (auto _ : state) {
        tom_int fn = fibonacci_matrix_pow<tom_int>(n);
    }
}
BENCHMARK(BM_FIBONACCI_MATRIX_POW_TOM_20000000);
#endif

#ifdef HAVE_BOOST_MULTIPRECISION_CPP_INT_HPP
static void BM_FIBONACCI_FAST_DOUBLING_CPP_20000000(benchmark::State& state) {
    unsigned int n = 20000000;

    for (auto _ : state) {
        cpp_int fn = fibonacci_fast_doubling<cpp_int>(n);
    }
}
BENCHMARK(BM_FIBONACCI_FAST_DOUBLING_CPP_20000000);
#endif

#ifdef HAVE_GMP_H
static void BM_FIBONACCI_FAST_DOUBLING_MPZ_20000000(benchmark::State& state) {
    unsigned int n = 20000000;

    for (auto _ : state) {
        mpz_int fn = fibonacci_fast_doubling<mpz_int>(n);
    }
}
BENCHMARK(BM_FIBONACCI_FAST_DOUBLING_MPZ_20000000);
#endif

#ifdef HAVE_TOMMATH_H
static void BM_FIBONACCI_FAST_DOUBLING_TOM_20000000(benchmark::State& state) {
    unsigned int n = 20000000;

    for (auto _ : state) {
        tom_int fn = fibonacci_fast_doubling<tom_int>(n);
    }
}
BENCHMARK(BM_FIBONACCI_FAST_DOUBLING_TOM_20000000);
#endif


// static void BM_FIBONACCI_FAST_QUAD_RECURSIVE_MPZ_20000000(benchmark::State& state) {
//     unsigned int n = 20000000;

//     for (auto _ : state) {
//         mpz_int fn = fibonacci_fast_quad_recursive_mpz(n);
//     }
// }
// BENCHMARK(BM_FIBONACCI_FAST_QUAD_RECURSIVE_MPZ_20000000);


#ifdef HAVE_BOOST_MULTIPRECISION_CPP_INT_HPP
static void BM_FIBONACCI_FAST_QUAD_CPP_20000000(benchmark::State& state) {
    unsigned int n = 20000000;

    for (auto _ : state) {
        cpp_int fn = fibonacci_fast_quad<cpp_int>(n);
    }
}
BENCHMARK(BM_FIBONACCI_FAST_QUAD_CPP_20000000);
#endif // HAVE_BOOST_MULTIPRECISION_CPP_INT_HPP

#ifdef HAVE_GMP_H
static void BM_FIBONACCI_FAST_QUAD_MPZ_20000000(benchmark::State& state) {
    unsigned int n = 20000000;

    for (auto _ : state) {
        mpz_int fn = fibonacci_fast_quad<mpz_int>(n);
    }
}
BENCHMARK(BM_FIBONACCI_FAST_QUAD_MPZ_20000000);
#endif // HAVE_GMP_H

#ifdef HAVE_TOMMATH_H
static void BM_FIBONACCI_FAST_QUAD_TOM_20000000(benchmark::State& state) {
    unsigned int n = 20000000;

    for (auto _ : state) {
        tom_int fn = fibonacci_fast_quad<tom_int>(n);
    }
}
BENCHMARK(BM_FIBONACCI_FAST_QUAD_TOM_20000000);
#endif // HAVE_TOMMATH_H

#ifdef HAVE_GMP_H
static void BM_FIBONACCI_BINET_GMP_20000000(benchmark::State& state) {
    unsigned int n = 20000000;
    mpz_int result = 0;
    for (auto _ : state) {
        mpz_int fn = fibonacci_binet<mpf_float, mpz_int, unsigned int>(n);
        result = fn;
    }
}
BENCHMARK(BM_FIBONACCI_BINET_GMP_20000000);
#endif 

#ifdef HAVE_GMP_H
static void BM_FIBONACCI_Z5_GMP_20000000(benchmark::State& state) {
    unsigned long n = 20000000;
    mpz_int result = 0;
    for (auto _ : state) {
        mpz_int fn = fibonacci_z5<mpz_int>(n);
        result = fn;
    }
}
BENCHMARK(BM_FIBONACCI_Z5_GMP_20000000);
#endif // HAVE_GMP_H

#ifdef HAVE_BOOST_MULTIPRECISION_CPP_INT_HPP
static void BM_FIBONACCI_Z5_CPP_100000(benchmark::State& state) {
    unsigned long n = 100000;
    cpp_int result = 0;
    for (auto _ : state) {
        cpp_int fn = fibonacci_z5<cpp_int>(n);
        result = fn;
    }
}
BENCHMARK(BM_FIBONACCI_Z5_CPP_100000);
#endif // HAVE_BOOST_MULTIPRECISION_CPP_INT_HPP

#ifdef HAVE_TOMMATH_H
static void BM_FIBONACCI_Z5_TOM_100000(benchmark::State& state) {
    unsigned long n = 100000;
    tom_int result = 0;
    for (auto _ : state) {
        tom_int fn = fibonacci_z5<tom_int>(n);
        result = fn;
    }
}
BENCHMARK(BM_FIBONACCI_Z5_TOM_100000);
#endif // HAVE_TOMMATH_H

#ifdef HAVE_BOOST_MULTIPRECISION_CPP_INT_HPP
static void BM_MATRIX_POW_CPP(benchmark::State& state) {
    unsigned int n = 100000;

    for (auto _ : state) {
        matrix<cpp_int> rv = util::matrix_pow<cpp_int>(n);
    }
}
BENCHMARK(BM_MATRIX_POW_CPP);
#endif // HAVE_BOOST_MULTIPRECISION_CPP_INT_HPP

#ifdef HAVE_GMP_H
static void BM_MATRIX_POW_MPZ(benchmark::State& state) {
    unsigned int n = 100000;

    for (auto _ : state) {
        matrix<mpz_int> rv = util::matrix_pow<mpz_int>(n);
    }
}
BENCHMARK(BM_MATRIX_POW_MPZ);
#endif // HAVE_GMP_H

#ifdef HAVE_TOMMATH_H
static void BM_MATRIX_POW_TOM(benchmark::State& state) {
    unsigned int n = 100000;

    for (auto _ : state) {
        matrix<tom_int> rv = util::matrix_pow<tom_int>(n);
    }
}
BENCHMARK(BM_MATRIX_POW_TOM);
#endif // HAVE_TOMMATH_H
BENCHMARK_MAIN();