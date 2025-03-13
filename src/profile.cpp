
#include <iostream>
#include <string>

#include <boost/multiprecision/gmp.hpp>

#include "fibonacci.hpp"
#include "profile_integer.hpp"

#include "../config.h"


using namespace boost::multiprecision;
using namespace fibonacci;

int main(int argc, char* argv[])
{
    int n{};
    if(argc > 1) {
        n = std::stoi(argv[1]);
    } else {
        n = 20000000;
    }
    std::cout << "fast doubling" << std::endl;
    profile_integer::profile_integer<mpz_int> fn1{};
    fn1 = fibonacci_fast_doubling<profile_integer::profile_integer<mpz_int>>(n);
    std::cout << fn1.counts_to_string() << std::endl;
    fn1.reset_counts();
    std::cout << "fast quad" << std::endl;
    profile_integer::profile_integer<mpz_int> fn2{};
    fn2 = fibonacci_fast_quad<profile_integer::profile_integer<mpz_int>>(n);
    std::cout << fn2.counts_to_string() << std::endl;
    return 0;
}