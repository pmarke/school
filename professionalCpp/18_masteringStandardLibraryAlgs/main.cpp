#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

// A predicate function used by an algorithm returns a boolean. Note that the
// parameter is not an iterator, but the value the iterator points to.
bool perfectScore(int num) { return (num >= 100); }

int product(int num1, int num2) { return num1 * num2; }

void increment(int& value) { ++value; }

int main(int, char**) {
  std::array<int, 5> nums{1, 2, 3, 4, 5};

  // accumulate can perform other operations than addition.
  int val = std::accumulate(nums.begin(), nums.end(), 1, product);
  std::cout << "product: " << val << std::endl;

  // std::function can be used to create a type that can point to a function, a
  // function object, or lambda expression. std::function<R(ArgTypes...)>
  std::function<int(int, int)> p = product;
  val = std::accumulate(nums.begin(), nums.end(), 1, p);
  std::cout << "product: " << val << std::endl;

  // std::bind can be used to bind a value to a parameter of a function. the
  // std::placeholder::_ indicates where the passed in value goes.
  auto productBind = std::bind(product, std::placeholders::_1, 10);
  std::cout << "product bind: " << productBind(3) << std::endl;

  // std::bind makes a copy of the parameter it is binding. To have it use a
  // reference or constant reference you need to use std::ref or std::cref.
  int index = 0;
  auto incr = std::bind(increment, std::ref(index));
  incr();
  std::cout << "index: " << index << std::endl;

  // You can use mem_fn to use a member function as a call back
  std::vector<std::string> words{"hi", "how", "are", "you", ""};
  auto it =
      find_if(words.begin(), words.end(), std::mem_fn(&std::string::empty));
  std::cout << *(--it) << std::endl;
}
