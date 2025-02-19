#ifndef FIBONACCI_HPP
#define FIBONACCI_HPP

#include <boost/multiprecision/gmp.hpp>

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/multiprecision/gmp.hpp>

#include <map>
#include <utility>

#include "quadratic.hpp"

// NB: we will index the sequence at 0 so F_0 = 0, F_1 = 1

namespace fibonacci {

namespace util {
    template<typename T, typename U>
    std::pair<T, T> fast_doubling_impl(U n)
    {
        if(n == 0) return {0, 1};
        if(n == 1) return {1, 1};
        U k = ( n % 2 == 0 ? n/(U)2 : (n-(U)1)/(U)2 );
        auto [f_k, f_k_1] = fast_doubling_impl<T, U>(k);
        T f_n = f_k * (2*f_k_1 - f_k);
        T f_n_1 =  f_k_1*f_k_1 + f_k * f_k;

        if(n % 2 == 0) {
            return {f_n, f_n_1};
        } else {
            return {f_n_1, f_n_1 + f_n};
        }
    }

    // std::pair<boost::multiprecision::mpz_int, boost::multiprecision::mpz_int> fast_quad_mpz_impl(const boost::multiprecision::mpz_int &n);

    template<typename T, typename U>
    std::pair<T, T> fast_quad_impl(const U &n)
    {
        if(n == 0) return {0, 1};
        if(n == 1) return {1, 1}; 
        if(n == 2) return {1, 2};
        if(n == 3) return {2, 3};

        U k = 0;
        if(n % 4 == 0) k = n/(U) 4;
        if(n % 4 == 1) k = (n-(U)1)/(U)4;
        if(n % 4 == 2) k = (n-(U)2)/(U)4;
        if(n % 4 == 3) k = (n-(U)3)/(U)4;

        auto [f_k, f_k_1] = fast_quad_impl<T, U>(k);

        T A = f_k*f_k_1;
        T B = f_k*f_k;
        T C = f_k_1*f_k_1;

        T E = B+C;

        if(n % 4 == 0) {
            T D = C-A;
            T f_n = (2*A-B)*(2*D+3*B);
            T f_n_1 = B*(4*D+B)+E*E;
            return {f_n, f_n_1};
        }
        if(n % 4 == 1) {
            T f_n = B*(4*(C-A)+B)+E*E;
            T f_n_1 = (C+4*A-B)*E;
            return {f_n, f_n_1};
        }
        if(n % 4 == 2) {
            T f_n = (C+4*A-B)*E;
            T f_n_1 = C*(C+4*(A+B))+E*E;
            return {f_n, f_n_1};
        }
        if(n % 4 == 3) {
            T f_n = (C+4*A-B)*E;
            T f_n_1 = C*(C+4*(A+B))+E*E;
            return {f_n_1, f_n + f_n_1};
        }
        return {0, 1};
    }



    template<typename T>
    boost::numeric::ublas::matrix<T> matrix_identity()
    {
        boost::numeric::ublas::matrix<T> identity(2, 2);
        identity(0, 0) = 1;
        identity(0, 1) = 0;
        identity(1, 0) = 0;
        identity(1, 1) = 1;
        return identity;
    }

    // boost::numeric::ublas::matrix<boost::multiprecision::mpz_int> matrix_pow(boost::multiprecision::mpz_int n);

    template<typename T, typename U>
    boost::numeric::ublas::matrix<T> matrix_pow(U n)
    {
        if(n == 0) return matrix_identity<T>();
        boost::numeric::ublas::matrix<T> fib_m(2, 2), fib_exp_m(2, 2);
        fib_m(0, 0) = 1;
        fib_m(0, 1) = 1;
        fib_m(1, 0) = 1;
        fib_m(1, 1) = 0;
        if(n == 1) return fib_m;
        fib_exp_m = matrix_identity<T>();
        
        while(n > 1) {
            if(n % 2 == 1)  { 
                fib_exp_m = prod(fib_exp_m, fib_m); 
                n--;
            }
            fib_m = prod(fib_m, fib_m); 
            n /= 2;
        }
        fib_exp_m = prod(fib_exp_m, fib_m);
        return fib_exp_m;
    }


}

template<typename T, typename U = unsigned int>
T fibonacci_recursive(U n)
{
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fibonacci_recursive<T, U>(n-1) + fibonacci_recursive<T, U>(n-2);
}

template<typename T, typename U = unsigned int>
T fibonacci_iterative(U n)
{
    if(n == 0) return 0;
    if(n == 1) return 1;
    T f_2 = 0;
    T f_1 = 1;
    T f_0 = 1;
    T T_n{n};
    for(T i = 2; i < T_n; i++) {
        f_2 = f_1;
        f_1 = f_0;
        f_0 = f_2 + f_1;
    }
    return f_0;
}

boost::multiprecision::mpz_int fibonacci_matrix_pow_mpz(unsigned int n);

template<typename T>
T fibonacci_matrix_pow(unsigned int n)
{
    if(n == 0) return 0;
    if(n == 1) return 1;
    boost::numeric::ublas::matrix<T> fib_matrix = util::matrix_pow<T>(n);
    return fib_matrix(0, 1);
}


// boost::multiprecision::mpz_int fibonacci_matrix_pow_square_mpz(unsigned int n);
// boost::multiprecision::mpz_int fibonacci_fast_doubling_memoized_mpz(unsigned int n);
boost::multiprecision::mpz_int fibonacci_fast_doubling_recursive_mpz(unsigned int n);

template<typename T, typename U = unsigned int>
T fibonacci_fast_doubling(U n)
{
    if(n == 0) return 0;
    if(n == 1) return 1;
    U k = ( n % 2 == 0 ? n/(U)2 : (n-(U)1)/(U)2 );
    auto [f_k, f_k_1] = util::fast_doubling_impl<T, U>(k);

    if(n % 2 == 0) {
        T f_n = f_k * (2*f_k_1 - f_k);
        return f_n;
    } else {
        T f_n_1 =  f_k_1*f_k_1 + f_k * f_k;;
        return f_n_1;
    }

    return util::fast_doubling_impl<T, U>(n).first;
}

// boost::multiprecision::mpz_int fibonacci_fast_quad_recursive_mpz(unsigned int n);

template<typename T, typename U>
T fibonacci_fast_quad(U n)
{
    if(n == 0) return 0;
    if(n == 1) return 1; 
    if(n == 2) return 1;
    if(n == 3) return 2;

    U k = 0;
    if(n % 4 == 0) k = n/4;
    if(n % 4 == 1) k = (n-1)/4;
    if(n % 4 == 2) k = (n-2)/4;
    if(n % 4 == 3) k = (n-3)/4;

    auto [f_k, f_k_1] = util::fast_quad_impl<T, U>(k);

    T A = f_k*f_k_1;
    T B = f_k*f_k;
    T C = f_k_1*f_k_1;

    if(n % 4 == 0) {
        T f_n = (2*A-B)*(2*(C-A)+3*B);
        return f_n;
    }
    if(n % 4 == 1) {
        T E = B+C;
        T f_n = B*(4*(C-A)+B)+E*E;
        return f_n;
    }
    if(n % 4 == 2) {
        T f_n = (C+4*A-B)*(B+C);
        return f_n;
    }
    if(n % 4 == 3) {
        T E = B+C;
        T f_n_1 = C*(C+4*(A+B))+E*E;
        return f_n_1;
    }
    return util::fast_quad_impl<T, U>(n).first;
}

// NB: fibonacci_binet() requires T::default_precision() which fixes the precision at run time
// to use fixed precision we would need to instantiate the template with either the precision 
// or n, which would be used to compute the precision at compile time. 

// Alteratively we could declare some types of various magnitudes and select the smallest
// acceptable magnitude. 

// if we wanted to use this with other types which can fix the precision at runtime we could 
// build something which allows us to define the function which sets the precision

template<typename T, typename U, typename V>
U fibonacci_binet(const V& n)
{
    // first we compute how many digits we need
    T est_phi = (1+sqrt((T{5})))/2;
    T est_digits = n * log(est_phi)/log(10);
    // NB: we include some padding in the precision. MPFR requires this 
    T::default_precision(round(est_digits).template convert_to<V>() + 2);
    // now we compute the result
    T a = 5;
    T phi = (1+sqrt(a))/2;
    T psi = (1-sqrt(a))/2;
    T result = (pow(phi, n) - pow(psi, n))/sqrt(a);
    return round(result).template convert_to<U>();
}


template<typename T, typename U>
T fibonacci_z5(const U& n)
{
    quadratic::quadratic_integer<5, T> phi(1, 1);
    quadratic::quadratic_integer<5, T> psi(1, -1);
    quadratic::quadratic_integer<5, T> fn_numerator = (pow(phi, n) - pow(psi, n))/boost::multiprecision::pow(T{2}, n);
    return fn_numerator.radical_coefficient();
}


}

#endif // FIBONACCI_HPP
