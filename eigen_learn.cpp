#include <Eigen/Dense>
#include <iostream>

int main(int argc, char *argv[]) {
    // 获取并打印命令行参数
    std::cout << "argc: " << argc << '\n';
    for (int i = 0; i < argc; ++i) {
        std::cout << "argument " << i << ": " << argv[i] << "\n";
    }

    // Eigen 基本类型
    Eigen::Vector3d vec; // 3维向量
    Eigen::MatrixXd mat; // 动态大小的矩阵

    // 初始化向量
    vec << 1.0, 2.0, 3.0;

    // 初始化矩阵
    mat = Eigen::MatrixXd::Random(3, 3); // 随机数矩阵

    // 打印向量和矩阵
    std::cout << "Vector:\n" << vec << "\n";
    std::cout << "Matrix:\n" << mat << "\n";

    // 创建固定大小的向量和矩阵
    Eigen::Vector3d fixedSizeVector; // 3维向量
    Eigen::Matrix3d fixedSizeMatrix; // 3x3 矩阵

    // 创建动态大小的向量和矩阵
    Eigen::VectorXd dynamicVector(5); // 大小为 5 的向量
    Eigen::MatrixXd dynamicMatrix(4, 4); // 4x4 矩阵

    // 获取并打印矩阵的形状
    std::cout << "Matrix shape: " << dynamicMatrix.rows() << "x" << dynamicMatrix.cols() << "\n";

    // 获取并打印向量的大小
    std::cout << "Vector size: " << dynamicVector.size() << "\n";

    // 给向量赋值
    dynamicVector << 1, 2, 3, 4, 5;
    std::cout << "Dynamic Vector:\n" << dynamicVector << "\n";

    // 给矩阵赋值
    dynamicMatrix << 1, 2, 3, 4,
                     5, 6, 7, 8,
                     9, 10, 11, 12,
                     13, 14, 15, 16;
    std::cout << "Dynamic Matrix:\n" << dynamicMatrix << "\n";

    // 给向量的某些元素赋值
    dynamicVector.segment(1, 3) << 10, 20, 30; // 修改第2到第4个元素
    std::cout << "Modified Vector:\n" << dynamicVector << "\n";

    // 给矩阵的某个区块赋值
    dynamicMatrix.block(1, 1, 2, 2) << 100, 200,
                                        300, 400; // 修改一个 2x2 的子矩阵
    std::cout << "Modified Matrix:\n" << dynamicMatrix << "\n";

    // 矩阵转置和求逆
    Eigen::MatrixXd mat_transposed = mat.transpose();
    Eigen::MatrixXd mat_inverse = mat.inverse();

    // 向量和矩阵的运算
    Eigen::Vector3d result = mat * vec;

    // 矩阵的迹和行列式
    double trace = mat.trace();
    double determinant = mat.determinant();

    // Eigen求解线性方程组
    Eigen::Vector3d b(1, 2, 3);
    Eigen::Vector3d x = mat.colPivHouseholderQr().solve(b);

    // Eigen值和Eigen向量
    Eigen::EigenSolver<Eigen::MatrixXd> eigensolver(mat);
    if (eigensolver.info() == Eigen::Success) {
        Eigen::EigenSolver<Eigen::MatrixXd>::EigenvalueType eigenvalues = eigensolver.eigenvalues();
        Eigen::EigenSolver<Eigen::MatrixXd>::EigenvectorsType eigenvectors = eigensolver.eigenvectors();
        std::cout << "Eigenvalues:\n" << eigenvalues << "\n";
        std::cout << "Eigenvectors:\n" << eigenvectors << "\n";
    }

    // 创建特殊矩阵（如单位矩阵、零矩阵）
    Eigen::MatrixXd identity_matrix = Eigen::MatrixXd::Identity(3, 3);
    Eigen::MatrixXd zero_matrix = Eigen::MatrixXd::Zero(3, 3);

    return 0;
}
