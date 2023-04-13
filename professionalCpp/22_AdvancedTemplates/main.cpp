#include <iostream>
#include <string>
#include <tuple>
#include <type_traits>

// if constexpr is evaluated at compile time.
template <typename TupleType, int n = std::tuple_size<TupleType>::value>
void tuple_print(const TupleType& t) {
  if constexpr (n > 1) {
    tuple_print<TupleType, n - 1>(t);
  }
  std::cout << std::get<n - 1>(t) << std::endl;
}

// Allows you to do template specialization based on a type trait.
template <typename T1, typename T2>
std::enable_if_t<std::is_same_v<T1, T2>, bool> check_type(const T1& t1,
                                                          const T2& t2) {
  std::cout << "'" << t1 << "' and '" << t2 << "' ";
  std::cout << "are the same types." << std::endl;
  return true;
}

template <typename T1, typename T2>
std::enable_if_t<!std::is_same_v<T1, T2>, bool> check_type(const T1& t1,
                                                           const T2& t2) {
  std::cout << "'" << t1 << "' and '" << t2 << "' ";
  std::cout << "are different types." << std::endl;
  return false;
}

int main(int, char**) {
  auto val = std::make_tuple(167, "Testing", false, 2.3);

  tuple_print(val);

  check_type(1, 32);
  check_type(1, 3.01);
  check_type(3.01, "Test");
}

// Integer sequence with folding