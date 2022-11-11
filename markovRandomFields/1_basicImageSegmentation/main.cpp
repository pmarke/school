#include <Optimizer.hpp>
#include <PatternGenerator.hpp>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

int main(int, char**) {
  std::vector<uint8_t> colorMeans{100, 200};
  std::vector<float> colorStd{10, 20};

  PatternGenerator patternGenerator(colorMeans, colorStd);

  std::vector<float> mu_o;
  std::vector<float> std_o;
  float beta_o{0};

  Optimizer optimizer;
  optimizer.optimize(patternGenerator.getNoisyImage(),
                     patternGenerator.getImageLabels(), colorMeans.size(), mu_o,
                     std_o, beta_o);

  // These are the output of the optimizer
  const std::vector<float> mu{100.445, 205.593};
  const std::vector<float> std{10.277, 19.37};
  const float beta{116.188};
  const float betaOffset{1e3};

  cv::imshow("image", patternGenerator.getImage());
  cv::imshow("noisy image", patternGenerator.getNoisyImage());
  cv::imshow("label", patternGenerator.getImageLabels() * 200);
  cv::waitKey(0);
}
