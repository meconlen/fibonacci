#include <benchmark/benchmark.h>
#include "fibonacci.hpp"

using namespace boost::multiprecision;
using namespace boost::numeric::ublas;
using namespace fibonacci;

static void BM_FIBONACCI_ITERATIVE_MPZ(benchmark::State& state) {
    mpz_int n = 100000;

    for (auto _ : state) {
        mpz_int fn = fibonacci_iterative_mpz(n);
    }
}
BENCHMARK(BM_FIBONACCI_ITERATIVE_MPZ);

static void BM_FIBONACCI_MATRIX_POW_MPZ(benchmark::State& state) {
    mpz_int n = 100000;

    for (auto _ : state) {
        mpz_int fn = fibonacci_matrix_pow_mpz(n);
    }
}

BENCHMARK(BM_FIBONACCI_MATRIX_POW_MPZ);

static void BM_FIBONACCI_MATRIX_POW_SQUARE_MPZ(benchmark::State& state) {
    mpz_int n = 100000;

    for (auto _ : state) {
        mpz_int fn = fibonacci_matrix_pow_square_mpz(n);
    }
}
BENCHMARK(BM_FIBONACCI_MATRIX_POW_SQUARE_MPZ);


static void BM_FIBONACCI_MATRIX_POW_SQUARE_MPZ_20000000(benchmark::State& state) {
    mpz_int n = 20000000;

    for (auto _ : state) {
        mpz_int fn = fibonacci_matrix_pow_square_mpz(n);
    }
}
BENCHMARK(BM_FIBONACCI_MATRIX_POW_SQUARE_MPZ_20000000);

static void BM_FIBONACCI_FAST_DOUBLING_MPZ_20000000(benchmark::State& state) {
    mpz_int n = 20000000;

    for (auto _ : state) {
        mpz_int fn = fibonacci_fast_doubling_mpz(n);
    }
}
BENCHMARK(BM_FIBONACCI_FAST_DOUBLING_MPZ_20000000);

static void BM_FIBONACCI_MATRIX_POW(benchmark::State& state) {
    mpz_int n = 100000;

    for (auto _ : state) {
        matrix<mpz_int> rv = util::fibonacci_matrix_pow(n);
    }
}
BENCHMARK(BM_FIBONACCI_MATRIX_POW);

static void BM_FIBONACCI_MATRIX_POW_SQUARE(benchmark::State& state) {
    mpz_int n = 100000;

    for (auto _ : state) {
        matrix<mpz_int> rv = util::fibonacci_matrix_pow_square(n);
    }
}
BENCHMARK(BM_FIBONACCI_MATRIX_POW_SQUARE);

BENCHMARK_MAIN();