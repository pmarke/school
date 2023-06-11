#include <algorithm>
#include <iostream>
#include <iteratorClass.hpp>
#include <numeric>

int main() {
  // We can now use our custom integer container with the std library
  // algorithms.
  Integers myInts;
  std::fill(myInts.begin(), myInts.end(), 1);
  std::cout << "sum: " << std::accumulate(myInts.begin(), myInts.end(), 0)
            << std::endl;

  return 0;
}
