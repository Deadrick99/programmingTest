#include <iostream>
#include "standard.h"
#include "strassen.h"
#include "matrix_utils.h"
#include <chrono>

int main() {
    std::cout << "Strassen Project Build Successful\n";
    Matrix matrixA = createRandomMatrix(1024);
    Matrix matrixB = createRandomMatrix(1024);

    //printMatrix(matrixA);
    //printMatrix(matrixB);

    auto start = std::chrono::high_resolution_clock::now();
    Matrix normal = standardMultiply(matrixA, matrixB);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Time taken: " << duration.count() << " seconds" << std::endl;
    //printMatrix(normal);
    start = std::chrono::high_resolution_clock::now();
    Matrix strassen = strassenMultiply(matrixA, matrixB);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "Time taken: " << duration.count() << " seconds" << std::endl;
    //printMatrix(strassen);
    return 0;
}
