#pragma once
#include <vector>

using Matrix = std::vector<std::vector<int>>;

Matrix add(Matrix matrixA, Matrix matrixB);
Matrix subtract(Matrix matrixA, Matrix matrixB);
void split(Matrix matrix, Matrix& matrix11, Matrix& matrix12, Matrix& matrix21, Matrix& matrix22);
Matrix combine(Matrix matrix11, Matrix matrix12, Matrix matrix21, Matrix matrix22);
Matrix createRandomMatrix(int n);
void printMatrix(Matrix matrix);
size_t getCurrentMemoryUsageInMB();