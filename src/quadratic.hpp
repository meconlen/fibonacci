#ifndef QUADRATIC_HPP
#define QUADRATIC_HPP

// this isn't really a quadratic integer class, buit it's enough for 
// the problem I'm solving which is Z[Sqrt(5)] rather than an extension of Q

#include <cstdint>
#include <iostream>
#include <sstream>
#include <string>


namespace quadratic {
template<uint64_t D, typename T>
class quadratic_integer
{

private:
    T a{0}, b{0};

public:
    quadratic_integer(T x, T y) : a{x}, b{y} {};
    template<typename U>
    constexpr quadratic_integer(U x) : a{x}, b{0} {}

    template<typename U, typename V>
    constexpr quadratic_integer(U x, V y) : a{x}, b{y} {}

    std::string to_string() const;

    constexpr quadratic_integer<D, T>& operator+=(const quadratic_integer<D, T>& other);
    constexpr quadratic_integer<D, T>& operator-=(const quadratic_integer<D, T>& other);
    constexpr quadratic_integer<D, T>& operator*=(const quadratic_integer<D, T>& other);

    T integer_coefficient() { return a; }
    T radical_coefficient() { return b; }
    template<uint64_t E, typename U>
    friend constexpr bool operator==(const quadratic_integer<E, U>& lhs, const quadratic_integer<E, U>& rhs);

    template<uint64_t E, typename U>
    friend constexpr bool operator!=(const quadratic_integer<E, U>& lhs, const quadratic_integer<E, U>& rhs);

    template<uint64_t E, typename U>
    friend constexpr quadratic_integer<E, U> operator+(const quadratic_integer<E, U>& value);

    template<uint64_t E, typename U>
    friend constexpr quadratic_integer<E, U> operator-(const quadratic_integer<E, U>& value);

    template<uint64_t E, typename U>
    friend constexpr quadratic_integer<E, U> operator+(const quadratic_integer<E, U>& lhs, const quadratic_integer<E, U>& rhs);

    template<uint64_t E, typename U>
    friend constexpr quadratic_integer<E, U> operator-(const quadratic_integer<E, U>& lhs, const quadratic_integer<E, U>& rhs);

    template<uint64_t E, typename U>
    friend constexpr quadratic_integer<E, U> operator*(const quadratic_integer<E, U>& lhs, const quadratic_integer<E, U>& rhs);

    template<uint64_t E, typename U, typename V>
    friend quadratic_integer<E, U> operator/(const quadratic_integer<E, U>& lhs, const V& rhs);
};

template<uint64_t D, typename T>
std::string quadratic_integer<D, T>::to_string() const
{
    std::ostringstream oss;
    oss << a << " + " << b << " sqrt(" << D << ")";
    return oss.str();
}

template<uint64_t D, typename T>
std::ostream& operator<<(std::ostream& s, const quadratic_integer<D, T>& q)
{
    s << q.to_string();
    return s;
}

template<uint64_t D, typename T>
constexpr bool operator==(const quadratic_integer<D, T>& lhs, const quadratic_integer<D, T>& rhs)
{
    return lhs.a == rhs.a && lhs.b == rhs.b;
}

template<uint64_t D, typename T>
constexpr bool operator!=(const quadratic_integer<D, T>& lhs, const quadratic_integer<D, T>& rhs)
{
    return ! (lhs == rhs);
}

template<uint64_t D, typename T>
constexpr quadratic_integer<D, T>& quadratic_integer<D, T>::operator+=(const quadratic_integer<D, T>& other)
{
    a += other.a;
    b += other.b;
    return *this;
}

template<uint64_t D, typename T>
constexpr quadratic_integer<D, T>& quadratic_integer<D, T>::operator-=(const quadratic_integer<D, T>& other)
{
    a -= other.a;
    b -= other.b;
    return *this;    
}

template<uint64_t D, typename T>
constexpr quadratic_integer<D, T>& quadratic_integer<D, T>::operator*=(const quadratic_integer<D, T>& other)
{
    // a+b S[D}] * o.a+b S[D] = (a * o.a) + (a*o.b) S[D] + (b*o.a) S[D] + (b*o.b)D 
    //                        = (a * o.a) + D(b*o.b) + S[D] (a*o.b + b*o.a) 
    //                        = (a * o.a) + D(b*o.b)) + (a*o.b + b*o.a) S[D]

    quadratic_integer<D, T> n(a * other.a + D * b * other.b, a * other.b + b * other.a);
    *this = n;
    return *this;
}

template<uint64_t E, typename U>
constexpr quadratic_integer<E, U> operator+(const quadratic_integer<E, U>& value)
{
    return value;
}

template<uint64_t E, typename U>
constexpr quadratic_integer<E, U> operator-(const quadratic_integer<E, U>& value)
{
    return quadratic_integer<E, U>(-value.a, -value.b);
}

template<uint64_t E, typename U>
constexpr quadratic_integer<E, U> operator+(const quadratic_integer<E, U>& lhs, const quadratic_integer<E, U>& rhs)
{
    return quadratic_integer<E, U>(lhs.a + rhs.a, lhs.b + rhs.b);
}

template<uint64_t E, typename U>
constexpr quadratic_integer<E, U> operator-(const quadratic_integer<E, U>& lhs, const quadratic_integer<E, U>& rhs)
{
    return quadratic_integer<E, U>(lhs.a - rhs.a, lhs.b - rhs.b);
}

template<uint64_t E, typename U>
constexpr quadratic_integer<E, U> operator*(const quadratic_integer<E, U>& lhs, const quadratic_integer<E, U>& rhs)
{
    return quadratic_integer<E, U>(lhs.a * rhs.a + E * lhs.b * rhs.b, lhs.a*rhs.b + lhs.b * rhs.a);
}

template<uint64_t E, typename U, typename V>
quadratic_integer<E, U> operator/(const quadratic_integer<E, U>& lhs, const V& rhs)
{
    return quadratic_integer<E, U>(lhs.a / rhs, lhs.b / rhs);
}


// a quadratic integer to an integer power
template<typename T, uint64_t E, typename U>
constexpr quadratic_integer<E, U> pow(quadratic_integer<E, U> x, T exponent)
{
    if(exponent == 0) return quadratic_integer<E, U>(1, 0);
    quadratic_integer<E, U> y(1, 0);
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
