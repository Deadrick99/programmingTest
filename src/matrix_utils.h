#pragma once
#include <vector>

using Matrix = std::vector<std::vector<double>>;

Matrix add(const Matrix& A, const Matrix& B);
Matrix subtract(const Matrix& A, const Matrix& B);
void split(const Matrix& A, Matrix& A11, Matrix& A12, Matrix& A21, Matrix& A22);
Matrix combine(const Matrix& A11, const Matrix& A12, const Matrix& A21, const Matrix& A22);
Matrix padToPowerOfTwo(const Matrix& A);
Matrix unpad(const Matrix& A, int originalRows, int originalCols);
Matrix createRandomMatrix(int n);
