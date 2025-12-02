#include <iostream>
#include "standard.h"
#include "strassen.h"
#include "matrix_utils.h"
#include <chrono>

int main(int argc, char* argv[]) {
    int matrixSize = std::stoi(argv[1]);
    Matrix matrixA = createRandomMatrix(matrixSize);
    Matrix matrixB = createRandomMatrix(matrixSize);

    //printMatrix(matrixA);
    //printMatrix(matrixB);
    if (std::string(argv[2]) == "-n")
    {
        std::cout << "------------------------------------------ Normal selected: matrix size:" << argv[1] << "------------------------------------------" <<std::endl;
        auto start = std::chrono::high_resolution_clock::now();
        Matrix normal = standardMultiply(matrixA, matrixB);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        std::cout << "Time taken: " << duration.count() << " seconds" << std::endl;    
        //printMatrix(normal);
        std::cout << "------------------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;

    }
    else if (std::string(argv[2]) == "-s")
    {
        int baseCase = 2;
        if (argc != 4)
        {
            std::cout << "If using strassen must provide base case size to use in standard multiply" << std::endl << "You used" << argc << "arguments" << std::endl;
            return -1;
        }
        else
        {
            baseCase = std::atoi(argv[3]);    
        }
        std::cout << "------------------------------------------ Strassen selected: Matrix size:" << argv[1] << "Base case size:" << argv[3] << "------------------------------------------" <<std::endl;
        auto start = std::chrono::high_resolution_clock::now();
        Matrix strassen = strassenMultiply(matrixA, matrixB, baseCase);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        std::cout << "Time taken: " << duration.count() << " seconds" << std::endl;    
        //printMatrix(strassen);
        std::cout << "------------------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;

    }
    else
    {
        std::cout<< "This program takes two argurments. The first is an int representing the matrix size. The second either '-s' for strassen or '-n' for normal";
    }
    return 0;
}
