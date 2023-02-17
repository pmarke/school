#include <algorithm>
#include <bitset>
#include <iostream>

template <size_t N>
std::bitset<N> reverse(const std::bitset<N>& bitSet) {
  std::bitset<N> reversed;
  for (size_t ii = 0; ii < N; ++ii) {
    reversed[ii] = bitSet[N - ii - 1];
  }
  return reversed;
}

int main(int, char**) {
  uint32_t val = 0b11110000111100000000000000000000;
  std::bitset<32> reversed = reverse(std::bitset<32>(val));

  std::cout << reversed << std::endl;
}
