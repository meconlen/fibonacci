#include <benchmark/benchmark.h>
#include "fibonacci.hpp"

using namespace boost::multiprecision;
using namespace boost::numeric::ublas;
using namespace fibonacci;

static void BM_FIBONACCI_RECUSRIVE_MPZ(benchmark::State& state) {
    unsigned int n = 30;

    for (auto _ : state) {
        mpz_int fn = fibonacci_recursive_mpz(n);
    }
}
BENCHMARK(BM_FIBONACCI_RECUSRIVE_MPZ);

static void BM_FIBONACCI_ITERATIVE_MPZ(benchmark::State& state) {
    unsigned int n = 100000;

    for (auto _ : state) {
        mpz_int fn = fibonacci_iterative_mpz(n);
    }
}
BENCHMARK(BM_FIBONACCI_ITERATIVE_MPZ);

static void BM_FIBONACCI_MATRIX_POW_MPZ(benchmark::State& state) {
    unsigned int n = 100000;

    for (auto _ : state) {
        mpz_int fn = fibonacci_matrix_pow_mpz(n);
    }
}

BENCHMARK(BM_FIBONACCI_MATRIX_POW_MPZ);

static void BM_FIBONACCI_MATRIX_POW_SQUARE_MPZ(benchmark::State& state) {
    unsigned int n = 100000;

    for (auto _ : state) {
        mpz_int fn = fibonacci_matrix_pow_square_mpz(n);
    }
}
BENCHMARK(BM_FIBONACCI_MATRIX_POW_SQUARE_MPZ);


static void BM_FIBONACCI_MATRIX_POW_SQUARE_MPZ_20000000(benchmark::State& state) {
    unsigned int n = 20000000;

    for (auto _ : state) {
        mpz_int fn = fibonacci_matrix_pow_square_mpz(n);
    }
}
BENCHMARK(BM_FIBONACCI_MATRIX_POW_SQUARE_MPZ_20000000);

static void BM_FIBONACCI_FAST_DOUBLING_MEMOIZED_MPZ_20000000(benchmark::State& state) {
    unsigned int n = 20000000;

    for (auto _ : state) {
        mpz_int fn = fibonacci_fast_doubling_memoized_mpz(n);
    }
}
BENCHMARK(BM_FIBONACCI_FAST_DOUBLING_MEMOIZED_MPZ_20000000);

static void BM_FIBONACCI_FAST_DOUBLING_RECURSIVE_MPZ_20000000(benchmark::State& state) {
    unsigned int n = 20000000;

    for (auto _ : state) {
        mpz_int fn = fibonacci_fast_doubling_recursive_mpz(n);
    }
}
BENCHMARK(BM_FIBONACCI_FAST_DOUBLING_RECURSIVE_MPZ_20000000);

static void BM_FIBONACCI_FAST_DOUBLING_RECURSIVE_QUAD_MPZ_20000000(benchmark::State& state) {
    unsigned int n = 20000000;

    for (auto _ : state) {
        mpz_int fn = fibonacci_fast_doubling_recursive_quad_mpz(n);
    }
}
BENCHMARK(BM_FIBONACCI_FAST_DOUBLING_RECURSIVE_QUAD_MPZ_20000000);

static void BM_FIBONACCI_BINET_GMP_20000000(benchmark::State& state) {
    unsigned int n = 20000000;
    mpz_int result = 0;
    for (auto _ : state) {
        mpz_int fn = fibonacci_binet_mpf(n);
        result = fn;
    }
}

BENCHMARK(BM_FIBONACCI_BINET_GMP_20000000);

static void BM_FIBONACCI_Z5_GMP_20000000(benchmark::State& state) {
    unsigned long n = 20000000;
    mpz_int result = 0;
    for (auto _ : state) {
        mpz_int fn = fibonacci_z5_mpz(n);
        result = fn;
    }
}

BENCHMARK(BM_FIBONACCI_Z5_GMP_20000000);


static void BM_MATRIX_POW(benchmark::State& state) {
    unsigned int n = 100000;

    for (auto _ : state) {
        matrix<mpz_int> rv = util::matrix_pow(n);
    }
}

BENCHMARK(BM_MATRIX_POW);

static void BM_MATRIX_POW_SQUARE(benchmark::State& state) {
    unsigned int n = 100000;

    for (auto _ : state) {
        matrix<mpz_int> rv = util::matrix_pow_square(n);
    }
}
BENCHMARK(BM_MATRIX_POW_SQUARE);

BENCHMARK_MAIN();