#include <Math.hpp>

Eigen::Matrix2d MyMath::multiply(const Eigen::Matrix2d& m1,
                                 const Eigen::Matrix2d& m2) {
  return m1 * m2;
}

Eigen::Matrix2d MyMath::add(const Eigen::Matrix2d& m1,
                            const Eigen::Matrix2d& m2) {
  return m1 + m2;
}

std::string MyMath::getFirstWord() { return m_words.getFirstWord(); }
