#include <iostream>
#include <type_traits>

template <typename T>
struct TypeIsIntegral {
  static constexpr bool VALUE{false};
};

template <>
struct TypeIsIntegral<char> {
  static constexpr bool VALUE{true};
};

template <>
struct TypeIsIntegral<signed char> {
  static constexpr bool VALUE{true};
};

template <>
struct TypeIsIntegral<unsigned char> {
  static constexpr bool VALUE{true};
};

template <>
struct TypeIsIntegral<short int> {
  static constexpr bool VALUE{true};
};

template <>
struct TypeIsIntegral<unsigned short int> {
  static constexpr bool VALUE{true};
};

template <>
struct TypeIsIntegral<int> {
  static constexpr bool VALUE{true};
};

template <>
struct TypeIsIntegral<unsigned int> {
  static constexpr bool VALUE{true};
};

template <>
struct TypeIsIntegral<long int> {
  static constexpr bool VALUE{true};
};

template <>
struct TypeIsIntegral<unsigned long int> {
  static constexpr bool VALUE{true};
};

template <>
struct TypeIsIntegral<bool> {
  static constexpr bool VALUE{true};
};

int main(int, char**) {
  std::cout << "my implementation <int>: " << TypeIsIntegral<int>::VALUE
            << std::endl;
  std::cout << "type_traits implementation <int>: "
            << std::is_integral<int>::value << std::endl
            << std::endl;

  std::cout << "my implementation <bool>: " << TypeIsIntegral<bool>::VALUE
            << std::endl;
  std::cout << "type_traits implementation <bool>: "
            << std::is_integral<bool>::value << std::endl
            << std::endl;

  std::cout << "my implementation <char>: " << TypeIsIntegral<char>::VALUE
            << std::endl;
  std::cout << "type_traits implementation <char>: "
            << std::is_integral<char>::value << std::endl
            << std::endl;

  std::cout << "my implementation <float>: " << TypeIsIntegral<float>::VALUE
            << std::endl;
  std::cout << "type_traits implementation <float>: "
            << std::is_integral<float>::value << std::endl
            << std::endl;

  std::cout << "my implementation <double>: " << TypeIsIntegral<double>::VALUE
            << std::endl;
  std::cout << "type_traits implementation <double>: "
            << std::is_integral<double>::value << std::endl
            << std::endl;
}
