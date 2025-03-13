#pragma once
#include <cstdint>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <type_traits>

// we need a float type for the log operation
// we might end up depending on boost int types to convert to/from float types
#include <boost/multiprecision/mpfr.hpp>

namespace profile_integer {

template<typename T, typename U>
class profile_integer;

template<typename T, typename U>
constexpr bool operator==(const profile_integer<T, U>& lhs, const profile_integer<T, U>& rhs);

template<typename T, typename U>
constexpr bool operator!=(const profile_integer<T, U>& lhs, const profile_integer<T, U>& rhs);

template<typename T, typename U>
constexpr profile_integer<T, U> operator+(const profile_integer<T, U>& unary_value);

template<typename T, typename U>
constexpr profile_integer<T, U> operator-(const profile_integer<T, U>& unary_value);


template<typename T, typename U>
constexpr profile_integer<T, U> operator+(const profile_integer<T, U>& lhs, const profile_integer<T, U>& rhs);

template<typename T, typename U>
constexpr profile_integer<T, U> operator-(const profile_integer<T, U>& lhs, const profile_integer<T, U>& rhs);

template<typename T, typename U>
constexpr profile_integer<T, U> operator*(const profile_integer<T, U>& lhs, const profile_integer<T, U>& rhs);

template<typename T, typename U, typename V>
typename std::enable_if<! std::is_same<profile_integer<T, U>, V>::value, profile_integer<T, U>>::type operator*(const V& lhs, const profile_integer<T, U>& rhs);

template<typename T, typename U>
constexpr profile_integer<T, U> operator/(const profile_integer<T, U>& lhs, const profile_integer<T, U>& rhs);

std::size_t get_limb_count(const boost::multiprecision::mpz_int& x);

template<typename T, typename U = std::size_t>
class profile_integer 
{
private:
   T value{}; 
   static std::map<U, U> product_counts;

public:
   profile_integer() : value{0} {}

   template<typename V>
   constexpr profile_integer(V x) : value{x} {}


   static void reset_counts();
   // self operators

   constexpr profile_integer<T, U>& operator+=(const profile_integer<T, U>& other);
   constexpr profile_integer<T, U>& operator-=(const profile_integer<T, U>& other);

   // can't be constexpr until C++23 and Boost isn't testing against that standard; there are warnings I don't want to get into. 
   profile_integer<T, U>& operator*=(const profile_integer<T, U>& other);

   // equality operators

   friend constexpr bool operator==<T, U>(const profile_integer<T, U>& lhs, const profile_integer<T, U>& rhs);
   friend constexpr bool operator!=<T, U>(const profile_integer<T, U>& lhs, const profile_integer<T, U>& rhs);

   // unary operators
   friend constexpr profile_integer<T, U> operator+<T, U>(const profile_integer<T, U>& unary_value);
   friend constexpr profile_integer<T, U> operator-<T, U>(const profile_integer<T, U>& unary_value);

   // binary operators

   friend constexpr profile_integer<T, U> operator+<T, U>(const profile_integer<T, U>& lhs, const profile_integer<T, U>& rhs);
   friend constexpr profile_integer<T, U> operator-<T, U>(const profile_integer<T, U>& lhs, const profile_integer<T, U>& rhs);
   friend constexpr profile_integer<T, U> operator*<>(const profile_integer<T, U>& lhs, const profile_integer<T, U>& rhs);

   // according to 13.7.4(8) this may not be a constexpr

   template<typename V> 
   friend typename std::enable_if_t<! std::is_same_v<profile_integer<T, U>, V>, profile_integer<T, U>> operator*(const V& lhs, const profile_integer<T, U>& rhs)
   {
      profile_integer<T, U> x;
      x.value = rhs.value * lhs;
      x.product_counts = rhs.product_counts;
      x.product_counts[get_limb_count(rhs.value)]++;
      return x;
   }

   friend constexpr profile_integer<T, U> operator/<T, U>(const profile_integer<T, U>& lhs, const profile_integer<T, U>& rhs);

   std::string to_string() const;
   std::string counts_to_string() const;
   T get_value() const;
   std::map<U, U> get_product_counts() const;
};

template<typename T, typename U>
std::map<U, U> profile_integer<T, U>::product_counts{};

template<typename T, typename U>
void profile_integer<T, U>::reset_counts()
{
   product_counts.clear();
}

template<typename T, typename U>
constexpr profile_integer<T, U>& profile_integer<T, U>::operator+=(const profile_integer<T, U>& other)
{
   value += other.value;
   return *this;
}

template<typename T, typename U>
constexpr profile_integer<T, U>& profile_integer<T, U>::operator-=(const profile_integer<T, U>& other)
{
   value -= other.value;
   return *this;
}

std::size_t get_limb_count(const boost::multiprecision::mpz_int& x)
{
      std::size_t limb_bits = sizeof(mp_limb_t) * 8;
      boost::multiprecision::mpfr_float mpz_base =static_cast<boost::multiprecision::mpfr_float>(boost::multiprecision::mpz_int(1) << limb_bits);
      boost::multiprecision::mpfr_float float_x = static_cast<boost::multiprecision::mpfr_float>(x);
      std::size_t rv = static_cast<std::size_t>(ceil(log(float_x)/log(mpz_base)));
      return rv;
}

// creation of a non-literal type make sthis non-constexpr
// change this when going to c++23

template<typename T, typename U>
profile_integer<T, U>& profile_integer<T, U>::operator*=(const profile_integer<T, U>& other)
{
   value *= other.value;
   T max = value > other.value ? value : other.value;
   product_counts[get_limb_count(max)]++;
   return *this;
}

template<typename T, typename U>
constexpr bool operator==(const profile_integer<T, U>& lhs, const profile_integer<T, U>& rhs)
{
   return lhs.value == rhs.value;
}

template<typename T, typename U>
constexpr bool operator!=(const profile_integer<T, U>& lhs, const profile_integer<T, U>& rhs)
{
   return lhs.value != rhs.value;
}

template<typename T, typename U>
constexpr profile_integer<T, U> operator+(const profile_integer<T, U>& unary_value)
{
   return unary_value;
}

template<typename T, typename U>
constexpr profile_integer<T, U> operator-(const profile_integer<T, U>& unary_value)
{
   profile_integer<T, U> x;
   x.value = -unary_value.value;
   return x;
}

template<typename T, typename U>
constexpr profile_integer<T, U> operator+(const profile_integer<T, U>& lhs, const profile_integer<T, U>& rhs)
{
   profile_integer<T, U> x;
   x.value = lhs.value + rhs.value;
   return x;
}

template<typename T, typename U>
constexpr profile_integer<T, U> operator-(const profile_integer<T, U>& lhs, const profile_integer<T, U>& rhs)
{
   profile_integer<T, U> x;
   x.value = lhs.value - rhs.value;
   return x;
}

template<typename T, typename U>
constexpr profile_integer<T, U> operator*(const profile_integer<T, U>& lhs, const profile_integer<T, U>& rhs)
{
   profile_integer<T, U> x;
   x.value = lhs.value * rhs.value;
   T max = lhs.value > rhs.value ? lhs.value : rhs.value;
   x.product_counts[get_limb_count(max)]++;
   return x;
}

template<typename T, typename U>
constexpr profile_integer<T, U> operator/(const profile_integer<T, U>& lhs, const profile_integer<T, U>& rhs)
{
   profile_integer<T, U> x;
   x.value = lhs.value / rhs.value;
   return x;
}

template<typename T, typename U>
std::string profile_integer<T, U>::to_string() const
{
   std::ostringstream oss;
   oss << value;
   return oss.str();
}

template<typename T, typename U>
std::string profile_integer<T, U>::counts_to_string() const
{
   std::ostringstream oss;
   for(const auto& [k, v] : product_counts) {
      oss << "{" << k << ", " << v << "} -> " << log2(static_cast<double>(v)) << std::endl;
   }
   return oss.str();
}

template<typename T, typename U>
std::ostream& operator<<(std::ostream& s, const profile_integer<T, U>& v)
{
   s << v.to_string();
   return s;
}

template<typename T, typename U>
T profile_integer<T, U>::get_value() const
{
   return value;
}

template<typename T, typename U>
std::map<U, U> profile_integer<T, U>::get_product_counts() const
{
   return product_counts;
}

}