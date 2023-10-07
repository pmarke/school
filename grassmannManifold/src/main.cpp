#include <Eigen/Core>
#include <Eigen/Eigenvalues>
#include <iostream>
#include <unsupported/Eigen/MatrixFunctions>

Eigen::Matrix3d ssm(double x, double y, double z) {
  Eigen::Matrix3d s;
  s << 0, -z, y, z, 0, -x, -y, x, 0;
  return s;
}

Eigen::Matrix3d logO(const Eigen::Matrix3d& s) {
  Eigen::Matrix3d e = s;
  e = e.exp();
  return e;
}

int main(int, char**) {
  // Eigen::Matrix3d P0;
  // P0 << 1, 0, 0, 0, 1, 0, 0, 0, 0;

  // Eigen::Matrix3d O;
  // O.setIdentity();

  // std::cout << P0 << std::endl;
  // std::cout << O * P0 * O.transpose() << std::endl;
  // O = logO(ssm(0.1, 0.2, 0.4));
  // Eigen::Matrix3d P1 = O * P0 * O.transpose();

  // std::cout << P1 << std::endl;
  // std::cout << P1 * P1 << std::endl;
  // std::cout << ssm(0.1, 0.2, 0.4) * P0 << std::endl;
  // std::cout << P0 * ssm(0.1, 0.2, 0.4).transpose() << std::endl;
  std::cout << logO(ssm(0, 0, 0.1)) << std::endl;

  Eigen::Matrix<double, 5, 5> M;
  M << 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0,
      1;

  Eigen::Matrix<double, 5, 1> u1, u2, u3;
  u1 << 1, 1, 0, 1, 0;
  u2 << 0, 0, 1, 0, 1;
  u3 << 1, 1, 1, 1, 1;

  std::cout << u1.transpose() * M * u1 << std::endl;
  std::cout << u2.transpose() * M * u2 << std::endl;
  std::cout << u3.transpose() * M * u3 << std::endl;

  Eigen::EigenSolver<Eigen::Matrix<double, 5, 5>> eigenSolver(M);
  std::cout << eigenSolver.eigenvalues() << std::endl;
  std::cout << eigenSolver.eigenvectors() << std::endl;
  std::cout << M * u3 << std::endl;

  std::cout << "Hello, world!\n";
}
