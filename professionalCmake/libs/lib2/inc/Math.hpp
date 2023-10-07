#pragma once

#include <Eigen/Core>
#include <Words.hpp>

class MyMath {
 public:
  Eigen::Matrix2d multiply(const Eigen::Matrix2d& m1,
                           const Eigen::Matrix2d& m2);

  Eigen::Matrix2d add(const Eigen::Matrix2d& m1, const Eigen::Matrix2d& m2);

  std::string getFirstWord();

  Words m_words;
};