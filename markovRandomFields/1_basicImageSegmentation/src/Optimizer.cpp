#include <Optimizer.hpp>

void Optimizer::optimize(const cv::Mat& noisyImage, const cv::Mat& labels,
                         uint8_t numClasses, std::vector<float>& mu,
                         std::vector<float>& std, float& beta) {
  google::InitGoogleLogging("optimizer");

  //   std::vector<double> mu_h;
  //   mu_h.resize(numClasses, 10);
  //   std::vector<double> std_h;
  //   std_h.resize(numClasses, 10);

  double mu1{1};
  double mu2{1};
  double std1{1};
  double std2{1};

  std::array<double*, 2> mu_h{&mu1, &mu2};
  std::array<double*, 2> std_h{&std1, &std2};
  double beta_h{1};

  ceres::Problem problem;

  // Setup the optimization.
  for (size_t ww = 0; ww < noisyImage.cols; ++ww) {
    for (size_t hh = 0; hh < noisyImage.rows; ++hh) {
      uint8_t index = labels.at<uchar>(ww, hh);
      double val = noisyImage.at<uchar>(ww, hh);

      size_t minWW = ww == 0 ? 0 : ww - 1;
      size_t maxWW = ww == noisyImage.cols ? noisyImage.cols : ww + 1;

      size_t minHH = hh == 0 ? 0 : hh - 1;
      size_t maxHH = hh == noisyImage.cols ? noisyImage.cols : hh + 1;

      std::vector<uchar> neighborLabels;
      for (size_t ii = minWW; ii <= maxWW; ++ii) {
        for (size_t jj = minHH; jj <= maxHH; ++jj) {
          neighborLabels.push_back(labels.at<uchar>(ii, jj));
        }
      }

      uchar label = labels.at<uchar>(ww, hh);

      ceres::CostFunction* cost_functionU1A =
          new ceres::AutoDiffCostFunction<LossFunctionU1A, 1, 1, 1>(
              new LossFunctionU1A(val));
      ceres::CostFunction* cost_functionU1B =
          new ceres::AutoDiffCostFunction<LossFunctionU1B, 1, 1>(
              new LossFunctionU1B);
      ceres::CostFunction* cost_functionV =
          new ceres::AutoDiffCostFunction<LossFunctionV, 1, 1>(
              new LossFunctionV(neighborLabels, label));

      problem.AddResidualBlock(cost_functionU1A, nullptr, mu_h.at(index),
                               std_h.at(index));
      problem.AddResidualBlock(cost_functionU1B, nullptr, std_h.at(index));
      problem.AddResidualBlock(cost_functionV, nullptr, &beta_h);
    }
  }

  ceres::Solver::Options options;
  options.linear_solver_type = ceres::DENSE_QR;
  options.minimizer_progress_to_stdout = true;
  ceres::Solver::Summary summary;
  ceres::Solve(options, &problem, &summary);

  std::cout << summary.BriefReport() << std::endl;

  mu.resize(numClasses);
  std.resize(numClasses);

  //   std::cout << "ajskd " << mu_h[0] << std::endl;

  for (size_t ii = 0; ii < numClasses; ++ii) {
    mu[ii] = *mu_h[ii];
    std[ii] = *std_h[ii];
  }

  beta = beta_h;
}