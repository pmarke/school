#ifndef __OPTIMIZER__
#define __OPTIMIZER__

#include <ceres/ceres.h>

#include <Eigen/Dense>
#include <opencv2/core.hpp>

struct LossFunctionU1A {
  LossFunctionU1A(double val) : m_val{val} {}

  template <typename T>
  bool operator()(const T* const mu, const T* const std, T* residual) const {
    residual[0] = (static_cast<T>(m_val) - mu[0]) / (sqrt(2.0) * std[0]);
    return true;
  }

  double m_val{0};
};

struct LossFunctionU1B {
  template <typename T>
  bool operator()(const T* const std, T* residual) const {
    residual[0] = sqrt(log(2 * M_PI * std[0]));
    return true;
  }
};

struct LossFunctionV {
  LossFunctionV(const std::vector<uchar>& neighborLabels, uchar label)
      : m_neighborLabels{neighborLabels}, m_label{label} {}

  template <typename T>
  bool operator()(const T* const beta, T* residual) const {
    T r{1e3};

    for (auto& nLabel : m_neighborLabels) {
      if (nLabel == m_label) {
        r -= beta[0];
      } else {
        r += beta[0];
      }
    }

    residual[0] = r;
    return true;
  }

  std::vector<uchar> m_neighborLabels;
  uchar m_label;
};

/*
struct LossFunction {
  LossFunction(cv::Mat noisyImage, cv::Mat labels, uint8_t numClasses)
      : m_image{noisyImage}, m_labels{labels}, m_numClasses{numClasses} {
    // std::cout << "type: " << m_labels.type() << std::endl;
    // std::cout << "mlables: " << m_labels << std::endl;
  }

  template <typename T>
  bool operator()(const T* const mu, const T* const std, const T* const beta,
                  T* residual) const {
    residual[0] = computeU1(mu, std) + beta[0];  // + computeU2(beta);
    return true;
  }

  template <typename T>
  T computeU1(const T* const mu, const T* const std) const {
    T sum{0.0};
    uint8_t index{0};
    for (size_t ww = 0; ww < m_image.cols; ++ww) {
      for (size_t hh = 0; hh < m_image.rows; ++hh) {
        index = m_labels.at<uchar>(ww, hh);
        // std::cerr << "index: " << index << std::endl;
        T m = mu[index];
        T s = std[index];
        T f = static_cast<T>(m_image.at<uchar>(ww, hh));
        if (s == static_cast<T>(0)) {
          std::cout << "oh no" << std::endl;
        }
        // sum += s * s + m * m;
        sum += (f - m) / s + s;
        // log(sqrt(2.0 * M_PI * s * s)) + (f - m) * (f - m) / (2.0 * s * s);
      }
    }
    // std::cout << "sum : " << sum << std::endl;
    // std::cout << "index : " << index << std::endl;
    return sum;
    // return mu[0] * mu[0] + mu[1] * mu[1] + std[0] * std[0] + std[1] * std[1];
  }

  template <typename T>
  T computeU2(const T* const beta) const {
    T sum{0.0};
    T b = beta[0];
    for (size_t ww = 0; ww < m_image.cols; ++ww) {
      for (size_t hh = 0; hh < m_image.rows; ++hh) {
        sum += computeV2(ww, hh, b);
      }
    }
    return sum;
  }

  template <typename T>
  T computeV2(size_t ww, size_t hh, T b) const {
    T sum{0.0};
    auto val = m_labels.at<uint8_t>(ww, hh);

    if (ww > 0) {
      sum += (m_labels.at<uint8_t>(ww - 1, hh)) == val ? -b : b;
    }

    if (ww < m_image.cols - 1) {
      sum += (m_labels.at<uint8_t>(ww + 1, hh)) == val ? -b : b;
    }

    if (hh > 0) {
      sum += (m_labels.at<uint8_t>(ww, hh - 1)) == val ? -b : b;
    }

    if (hh < m_image.rows - 1) {
      sum += (m_labels.at<uint8_t>(ww, hh + 1)) == val ? -b : b;
    }
    return sum;
  }

  cv::Mat m_image;
  cv::Mat m_labels;
  cv::Mat m_numClasses;
};
*/

class Optimizer {
 public:
  void optimize(const cv::Mat& noisyImage, const cv::Mat& labels,
                uint8_t numClasses, std::vector<float>& mu,
                std::vector<float>& std, float& beta);

 private:
};

#endif  //__OPTIMIZER__