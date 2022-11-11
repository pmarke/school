#include "PatternGenerator.hpp"

PatternGenerator::PatternGenerator(const std::vector<uint8_t>& colorMeans,
                                   const std::vector<float>& colorStd,
                                   bool circles) {
  m_colorMeans = colorMeans;
  m_colorStd = colorStd;

  // Generate a random indices for the color means and std vectors.
  std::vector<uint8_t> indices;
  indices.resize(colorMeans.size());
  std::iota(indices.begin(), indices.end(), 0);
  auto rng = std::default_random_engine{
      std::chrono::system_clock::now().time_since_epoch().count()};
  std::shuffle(indices.begin(), indices.end(), rng);

  m_image = cv::Mat(m_imageSize, CV_8U);
  m_noise = cv::Mat(m_imageSize, CV_32F);
  m_label = cv::Mat(m_imageSize, CV_8U);

  cv::Mat imageBlock = cv::Mat(m_blockSize, CV_8U);
  cv::Mat noiseBlock = cv::Mat(m_blockSize, CV_32F);

  uint8_t numBlocksWidth = m_imageSize.width / m_blockSize.width;
  uint8_t numBlocksHeight = m_imageSize.height / m_blockSize.height;

  uint8_t index = 0;

  for (uint8_t ww = 0; ww < numBlocksWidth; ++ww) {
    for (uint8_t hh = 0; hh < numBlocksHeight; hh++) {
      cv::Rect roi(ww * m_blockSize.width, hh * m_blockSize.height,
                   m_blockSize.width, m_blockSize.height);

      imageBlock = colorMeans[indices[index]];
      cv::randn(noiseBlock, 0, colorStd[indices[index]]);

      imageBlock.copyTo(m_image(roi));
      noiseBlock.copyTo(m_noise(roi));
      m_label(roi) = indices[index];

      // Wrap index around.
      index++;
      if (index >= indices.size()) {
        index = 0;
      }
    }
  }

  cv::Mat tmp;
  m_image.convertTo(tmp, CV_32F);
  cv::add(m_noise, tmp, m_noisyImage);
  m_noisyImage.convertTo(m_noisyImage, CV_8U);
}