#ifndef __PATTERN_GENERATOR_
#define __PATTERN_GENERATOR_

#include <algorithm>
#include <array>
#include <chrono>
#include <iostream>
#include <opencv2/core.hpp>
#include <random>
#include <vector>

class PatternGenerator {
 public:
  PatternGenerator(const std::vector<uint8_t>& colorMeans,
                   const std::vector<float>& colorStd, bool circles = false);

  const cv::Mat& getImage() const { return m_image; }
  const cv::Mat& getNoisyImage() const { return m_noisyImage; }
  const cv::Mat& getImageLabels() const { return m_label; }

 private:
  uint8_t m_numColors{0};
  cv::Mat m_image;
  cv::Mat m_noise;
  cv::Mat m_label;
  cv::Mat m_noisyImage;

  cv::Size m_blockSize{20, 20};
  cv::Size m_imageSize{100, 100};

  static constexpr uint8_t MIN_VAL{0};
  static constexpr uint8_t MAX_VAL{255};
  std::vector<uint8_t> m_colorMeans;
  std::vector<float> m_colorStd;
};

#endif  // __PATTERN_GENERATOR_
