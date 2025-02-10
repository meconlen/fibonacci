#include <benchmark/benchmark.h>
#include "fibonacci.hpp"

using namespace boost::multiprecision;

static void BM_FIBONACCI_ITERATIVE(benchmark::State& state) {

    mpz_int n = 1000000;

   for (auto _ : state) {
        mpz_int fn = fibonacci_iterative(n);
   }
}
BENCHMARK(BM_FIBONACCI_ITERATIVE);


BENCHMARK_MAIN();