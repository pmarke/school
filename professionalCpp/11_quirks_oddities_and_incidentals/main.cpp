#include <iostream>

bool equal(int i, int j) { return i == j; }

bool notEqual(int i, int j) { return i != j; }

// Literal definitions
double operator"" _ms(long double num) { return num * 1e-3; }

// A function pointer alias to a function that returns a bool and takes in two
// ints as arguments.S
using MatchFunction = bool (*)(int, int);

int main(int, char**) {
  MatchFunction equalPtr = &equal;
  MatchFunction notEqualPtr = &notEqual;

  std::cout << "equal: " << equalPtr(1, 1) << std::endl;
  std::cout << "not equal:" << notEqualPtr(1, 2) << std::endl;
  std::cout << "seconds: " << 1.0_ms << std::endl;
}
