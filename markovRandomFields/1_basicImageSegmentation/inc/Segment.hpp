#ifndef __SEGMENT_
#define __SEGMENT_

#include <opencv2/core.hpp>
#include <vector>

class Segment {
 public:
  Segment(const std::vector<float>& means, const std::vector<float>& stds,
          float beta, float betaOffset)
      : m_means{means}, m_stds{stds}, m_beta{beta}, m_betaOffset{betaOffset} {}

  cv::Mat labelImage(const cv::Mat& image) {}

 private:
  std::vector<float> m_means;
  std::vector<float> m_stds;
  float m_beta;
  float m_betaOffset;
};

#endif  // __SEGMENT_
