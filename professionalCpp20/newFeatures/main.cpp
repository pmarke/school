#include <algorithm>
#include <array>
#include <compare>
#include <concepts.hpp>
#include <format>
#include <iostream>
#include <numbers>
#include <ranges>
#include <source_location>
#include <string>
#include <utility>
#include <vector>

void threeWayComparisonInt(int val1, int val2) {
  std::strong_ordering result = val1 <=> val2;

  if (result == std::strong_ordering::less) {
    std::cout << val1 << " is less than " << val2 << std::endl;
  }

  if (result == std::strong_ordering::equal) {
    std::cout << val1 << " is equal to " << val2 << std::endl;
  }

  if (result == std::strong_ordering::greater) {
    std::cout << val1 << " is greater than " << val2 << std::endl;
  }
}

/**
 * @brief Designated Initializers
 * No custom constructors
 * No virtual methods
 * Only public member variables
 */

struct Dinit {
  int val1;
  double val2;
  std::string val3;
  bool val4;
};

constexpr double inchToMm(double inch) { return inch * 25.4; }
consteval double inchToMmE(double inch) { return inch * 25.4; }

/**
 * c++ 20 will automatically create the != comparison operator from
 * the == operator. And you only need to implement the <=> operator
 * and c++20 will do the rest for you.
 *
 */
class MyComparisonClass {
 public:
  MyComparisonClass(int val) : val{val} {}
  int val;

  [[nodiscard]] bool operator==(const MyComparisonClass& other) const {
    return val == other.val;
  }

  [[nodiscard]] std::strong_ordering operator<=>(
      const MyComparisonClass& other) const {
    return val <=> other.val;
  }
};

// deduce template type

decltype(auto) addNumbers(const auto& val1, const auto& val2) {
  return val1 + val2;
}

// source location
void logMessage(std::string_view msg, const std::source_location& location =
                                          std::source_location::current()) {
  std::cout << std::format(
      "File Name: {}, Function Name {}, Line Number: {}, Msg: {}\n",
      location.file_name(), location.function_name(), location.line(), msg);
}

// print ranges
void printRanges(std::string_view msg, auto& range) {
  std::cout << msg;
  for (const auto& val : range) {
    std::cout << val << " ";
  }
  std::cout << std::endl;
}

int main(int, char**) {
  // Three way comparison
  std::cout << "Three way comparison " << std::endl;
  threeWayComparisonInt(1, 2);
  threeWayComparisonInt(1, 1);
  threeWayComparisonInt(2, 1);

  // initializers for range based for loop
  std::cout << std::endl << "initializer in range based for loop " << std::endl;
  for (std::array<int, 4> a{1, 2, 3, 4}; int val : a) {
    std::cout << val << std::endl;
  }

  // Designated initializers.
  // They have to be declared in order, but you can skip some.
  Dinit dInit{.val1 = 2, .val2 = 3.0, .val4 = false};

  // Consteval vs constexpr
  // Consteval forces evaluation at compiler time while constexpr
  // does not.
  constexpr double mm1{inchToMm(6.0)};    // compile time
  constexpr double mm1E{inchToMmE(6.0)};  // compile time

  double inch{90};             // dynamic value
  double mm2{inchToMm(inch)};  // runtime
  // double mm2E{inchToMmE(inch)}  // won't do run time. Compile error.

  // start with and ends with
  std::string myString{"Hello There"};
  std::cout << myString << std::endl;
  std::cout << myString.starts_with("Hello") << std::endl;
  std::cout << myString.ends_with("There") << std::endl;

  // format
  std::cout << std::endl << "Format " << std::endl;
  std::string formatStr = std::format("{} x {} = {}", 5, 4, 5 * 4);
  int i{42};
  // fill alight with width
  std::cout << std::format("|{:7}|", i) << std::endl;
  std::cout << std::format("|{:^7}|", i) << std::endl;
  std::cout << std::format("|{:<7}|", i) << std::endl;
  std::cout << std::format("|{:>7}|", i) << std::endl;
  std::cout << std::format("|{:_^7}|", i) << std::endl;

  // Predefined constants
  std::cout << std::endl << "Predefined constants: " << std::endl;
  std::cout << std::numbers::pi << std::endl;

  // Comparison Operators
  std::cout << std::endl << "Comparison Operations: " << std::endl;
  MyComparisonClass compare1(1);
  MyComparisonClass compare2(2);
  std::cout << std::boolalpha << (compare1 == compare1) << std::endl;
  // This support is automatically added.
  std::cout << std::boolalpha << (compare2 != compare1) << std::endl;

  // bit_cast
  // can be done at compile time.
  // The same bits used by float are used by unsigned int
  // copies the bits
  // source and target must be the same size.
  float asFloat{5};
  unsigned int asUInt{std::bit_cast<unsigned int>(asFloat)};

  // abbreviated function template
  std::cout << std::endl << "abreviated function template" << std::endl;
  std::cout << addNumbers(1, 1.0) << std::endl;
  std::cout << addNumbers(2.0, 1.0) << std::endl;

  // Concepts
  std::cout << "Concepts: " << std::endl;
  std::string strHi{"hi"};
  // Incrementable auto value1{strHi}; // not valid
  Incrementable auto value1{1};
  Class1<int> conceptInt;
  // Class1<std::string> conceptString;  // not valid;

  // function overloading
  process(int(1));
  process(short(1));

  std::cout << "log messages: " << std::endl;
  logMessage("This is a message");

  // comparison of mixed types
  std::cout << (-1 > 0u) << std::endl;  // incorrectly returns true
  std::cout << std::cmp_greater(-1, 0u) << std::endl;

  // ranges
  // It is a concept that requires the object to have T::begin() and T::end()
  // Ranges support projection which is a function applied to each element in
  // the container before it is given to the algorithm.
  std::cout << "ranges" << std::endl;
  std::vector<int> rangeData{5, 3, 6, -8, 7, -9, 1, 2};
  std::sort(std::begin(rangeData), std::end(rangeData));
  for (auto& val : rangeData) {
    std::cout << val;
  }
  std::cout << std::endl;
  // or using a projection
  std::ranges::sort(rangeData, {}, [](const int val) { return val * val; });
  for (auto& val : rangeData) {
    std::cout << val;
  }
  std::cout << std::endl;

  // Views can be created using range adapters.
  // They are not evaluated when constructed.
  auto result1{rangeData |
               std::views::filter([](const auto& val) { return val > 0; })};
  printRanges("filter positive", result1);
  auto result2{result1 | std::views::transform(
                             [](const auto& val) { return val * val; })};
  printRanges("squared", result2);
}
