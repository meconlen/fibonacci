#ifndef QUADRATIC_HPP
#define QUADRATIC_HPP

// this isn't really a quadratic integer class, buit it's enough for 
// the problem I'm solving which is Z[Sqrt(5)] rather than an extension of Q

#include <cstdint>
#include <iostream>
#include <sstream>
#include <string>

#include <boost/multiprecision/gmp.hpp>

namespace quadratic {
template<uint64_t D>
class quadratic_integer
{

private:
    boost::multiprecision::mpz_int a{0}, b{0};

public:
    quadratic_integer(boost::multiprecision::mpz_int x, boost::multiprecision::mpz_int y) : a{x}, b{y} {};
    template<typename U>
    constexpr quadratic_integer(U x) : a{x}, b{0} {}

    template<typename U, typename V>
    constexpr quadratic_integer(U x, V y) : a{x}, b{y} {}

    // constexpr quadratic_integer<D>& operator=(const quadratic_integer<D>& rhs)
    // {
    //     a = rhs.a;
    //     b = rhs.b;
    //     return *this;
    // }

    std::string to_string() const;

    constexpr quadratic_integer<D>& operator+=(const quadratic_integer<D>& other);
    constexpr quadratic_integer<D>& operator-=(const quadratic_integer<D>& other);
    constexpr quadratic_integer<D>& operator*=(const quadratic_integer<D>& other);

    boost::multiprecision::mpz_int integer_coefficient() { return a; }
    boost::multiprecision::mpz_int radical_coefficient() { return b; }
    template<uint64_t E>
    friend constexpr bool operator==(const quadratic_integer<E>& lhs, const quadratic_integer<E>& rhs);

    template<uint64_t E>
    friend constexpr bool operator!=(const quadratic_integer<E>& lhs, const quadratic_integer<E>& rhs);

    template<uint64_t E>
    friend constexpr quadratic_integer<E> operator+(const quadratic_integer<E>& value);

    template<uint64_t E>
    friend constexpr quadratic_integer<E> operator-(const quadratic_integer<E>& value);

    template<uint64_t E>
    friend constexpr quadratic_integer<E> operator+(const quadratic_integer<E>& lhs, const quadratic_integer<E>& rhs);

    template<uint64_t E>
    friend constexpr quadratic_integer<E> operator-(const quadratic_integer<E>& lhs, const quadratic_integer<E>& rhs);

    template<uint64_t E>
    friend constexpr quadratic_integer<E> operator*(const quadratic_integer<E>& lhs, const quadratic_integer<E>& rhs);

    template<uint64_t E>
    friend quadratic_integer<E> operator/(const quadratic_integer<E>& lhs, const boost::multiprecision::mpz_int rhs);
};

template<uint64_t D>
std::string quadratic_integer<D>::to_string() const
{
    std::ostringstream oss;
    oss << a << " + " << b << " sqrt(" << D << ")";
    return oss.str();
}

template<uint64_t D>
std::ostream& operator<<(std::ostream& s, const quadratic_integer<D>& q)
{
    s << q.to_string();
    return s;
}

template<uint64_t D>
constexpr bool operator==(const quadratic_integer<D>& lhs, const quadratic_integer<D>& rhs)
{
    return lhs.a == rhs.a && lhs.b == rhs.b;
}

template<uint64_t D>
constexpr bool operator!=(const quadratic_integer<D>& lhs, const quadratic_integer<D>& rhs)
{
    return ! (lhs == rhs);
}

template<uint64_t D>
constexpr quadratic_integer<D>& quadratic_integer<D>::operator+=(const quadratic_integer<D>& other)
{
    a += other.a;
    b += other.b;
    return *this;
}

template<uint64_t D>
constexpr quadratic_integer<D>& quadratic_integer<D>::operator-=(const quadratic_integer<D>& other)
{
    a -= other.a;
    b -= other.b;
    return *this;    
}

template<uint64_t D>
constexpr quadratic_integer<D>& quadratic_integer<D>::operator*=(const quadratic_integer<D>& other)
{
    // a+b S[D}] * o.a+b S[D] = (a * o.a) + (a*o.b) S[D] + (b*o.a) S[D] + (b*o.b)D 
    //                        = (a * o.a) + D(b*o.b) + S[D] (a*o.b + b*o.a) 
    //                        = (a * o.a) + D(b*o.b)) + (a*o.b + b*o.a) S[D]

    quadratic_integer<D> n(a * other.a + D * b * other.b, a * other.b + b * other.a);
    *this = n;
    return *this;
}

template<uint64_t E>
constexpr quadratic_integer<E> operator+(const quadratic_integer<E>& value)
{
    return value;
}

template<uint64_t E>
constexpr quadratic_integer<E> operator-(const quadratic_integer<E>& value)
{
    return quadratic_integer<E>(-value.a, -value.b);
}

template<uint64_t E>
constexpr quadratic_integer<E> operator+(const quadratic_integer<E>& lhs, const quadratic_integer<E>& rhs)
{
    return quadratic_integer<E>(lhs.a + rhs.a, lhs.b + rhs.b);
}

template<uint64_t E>
constexpr quadratic_integer<E> operator-(const quadratic_integer<E>& lhs, const quadratic_integer<E>& rhs)
{
    return quadratic_integer<E>(lhs.a - rhs.a, lhs.b - rhs.b);
}

template<uint64_t E>
constexpr quadratic_integer<E> operator*(const quadratic_integer<E>& lhs, const quadratic_integer<E>& rhs)
{
    return quadratic_integer<E>(lhs.a * rhs.a + E * lhs.b * rhs.b, lhs.a*rhs.b + lhs.b * rhs.a);
}

template<uint64_t E>
quadratic_integer<E> operator/(const quadratic_integer<E>& lhs, const boost::multiprecision::mpz_int rhs)
{
    return quadratic_integer<E>(lhs.a / rhs, lhs.b / rhs);
}


// a quadratic integer to an integer power
template<typename T, uint64_t E>
constexpr quadratic_integer<E> pow(quadratic_integer<E> x, T exponent)
{
    if(exponent == 0) return quadratic_integer<E>(1, 0);
    quadratic_integer<E> y(1, 0);
    while(exponent > 1) {
        if(exponent % 2 == 1) {
            y = x * y;
            exponent--;
        }
        x = x * x;
        exponent /= 2;
    }
    return x * y;
}

} // namespace quadratic

#endif // QUADRATIC_HPP
