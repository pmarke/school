#include <Math.hpp>
#include <iostream>

int main() {
  MyMath myMath;
  Eigen::Matrix2d m1, m2, m3;

  m3 = myMath.multiply(m1, m2);
  std::cout << myMath.getFirstWord() << std::endl;
  std::cout << myMath.m_words.getSecondWord() << std::endl;
  return 0;
}