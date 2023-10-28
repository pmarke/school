#include <concepts>
#include <iostream>

// Concept syntax
// template <parameter-list>
// concept concept-name = constraints-expression

// examples
template <typename T>
concept size4Concept = sizeof(T) == 4;

// Requires Expressions
// requires (parameter-list) {requirement1; requirement2;...}
// the parameter-list is optional
// four types: simple, type, compound, nested

// Simple Requirements
template <typename T>
concept Incrementable = requires(T x) {
  x++;
  ++x;
};  // T is required to have the post and pre incremental operators defined

template <typename T>
concept Decrementable = requires(T x) {
  x--;
  --x;
};

// Type requirement
template <typename T>
concept ValueType = requires {
  typename T::value_type;
};  // The template class must have a type value_type

// Compound Requirement
template <typename T>
concept SwapNoExcept = requires(T x, T y) {
  { x.swap(y) }
  noexcept;
};  // checks that T has a function called swap that does not throw an exception

template <typename T>
concept SizeConvert = requires(const T x) {
  { x.size() } -> std::convertible_to<unsigned int>;
};  // The return value of x.size is convertible to unsigned int.

// Nested requirements
template <typename T>
concept NestedRequirement = requires(T t) {
  requires sizeof(T) == 4;
  ++t, --t, t++, t--;
};

// Can combine concepts using && and ||
template <typename T>
concept IncrementableAndDecremantable = Incrementable<T> && Decrementable<T>;

// The template must support incrementing and decrementing
template <IncrementableAndDecremantable T>
class Class1 {
 public:
  int sum(T x, T y) { return x + y; }
};

// Other syntax
template <typename T>
requires IncrementableAndDecremantable<T>
class Class2 {
 public:
  int sum(T x, T y) { return x + y; }
};

// you can overload a function template with different type constraints. It will
// always use the more specific one.
template <typename T>
requires std::integral<T>
void process(const T& t) { std::cout << "integral<T>" << std::endl; }
template <typename T>
requires(std::integral<T>&& size4Concept<T>) void process(const T& t) {
  std::cout << "integral<T> && size4Concept<T>" << std::endl;
}
