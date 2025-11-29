#include "matrix_utils.h"
#include <cstdlib>
#include <iostream>

// Adds Matrix B to Matrix A and returns the resulting matrix
Matrix add(Matrix matrixA, Matrix matrixB)
{
    int matrixSize = matrixA.size();
    Matrix returnMatrix(matrixSize, std::vector<int>(matrixSize));
    for (int i = 0; i < matrixSize; i++ )
    {
        for(int j = 0; j < matrixSize; j++)
        {
            int matrixAValue = matrixA[i][j];
            int matrixBValue = matrixB[i][j];
            int sum = matrixAValue + matrixBValue;
            returnMatrix[i][j] = sum;
        }
    }
    return returnMatrix;
}

// Subtracts matrix B from matrix A and returns the resulting matrix
Matrix subtract(Matrix matrixA, Matrix matrixB)
{
    int matrixSize = matrixA.size();
    Matrix returnMatrix(matrixSize, std::vector<int>(matrixSize));
    for (int i = 0; i < matrixSize; i++ )
    {
        for(int j = 0; j < matrixSize; j++)
        {
            int matrixAValue = matrixA[i][j];
            int matrixBValue = matrixB[i][j];
            int difference = matrixAValue - matrixBValue;
            returnMatrix[i][j] = difference;
        }
    }
    return returnMatrix;
}

//splits matrix into four quadrants: matrix11, matrix12, matrix21, matrix 22.
void split(Matrix matrix, Matrix& matrix11, Matrix& matrix12, Matrix& matrix21, Matrix& matrix22)
{
    int matrixSize = matrix.size();
    for (int i = 0; i < matrixSize; i++ )
    {
        for(int j = 0; j < matrixSize; j++)
        {
            int shift = matrixSize / 2;
            bool isUpperHalf = (i * 2) < matrixSize;
            bool isLowerHalf = (i * 2) >= matrixSize;
            bool isRightHalf = (j * 2) >= matrixSize;
            bool isLeftHalf = (j * 2) < matrixSize;

            if(isUpperHalf && isLeftHalf)
            {
                matrix11[i][j] = matrix[i][j];
            }
            else if(isUpperHalf && isRightHalf)
            {
                matrix12[i][j - shift] = matrix[i][j];
            }
            else if(isLowerHalf && isLeftHalf)
            {
                matrix21[i - shift][j] = matrix[i][j];
            }
            else if(isLowerHalf && isRightHalf)
            {
                matrix22[i - shift][j - shift] = matrix[i][j];
            }
        }
    }
}

//Combines four matrices into one and returns it
Matrix combine(Matrix matrix11, Matrix matrix12, Matrix matrix21, Matrix matrix22)
{
    int matrixSize = matrix11.size() * 2;
    Matrix returnMatrix(matrixSize, std::vector<int>(matrixSize));
    for (int i = 0; i < matrixSize; i++ )
    {
        for(int j = 0; j < matrixSize; j++)
        {
            int shift = matrixSize / 2;
            bool isUpperHalf = (i * 2) < matrixSize;
            bool isLowerHalf = (i * 2) >= matrixSize;
            bool isRightHalf = (j * 2) >= matrixSize;
            bool isLeftHalf = (j * 2) < matrixSize;

            if(isUpperHalf && isLeftHalf)
            {
                returnMatrix[i][j] = matrix11[i][j];
            }
            else if(isUpperHalf && isRightHalf)
            {
                returnMatrix[i][j] = matrix12[i][j - shift];
            }
            else if(isLowerHalf && isLeftHalf)
            {
                returnMatrix[i][j] = matrix21[i - shift][j];
            }
            else if(isLowerHalf && isRightHalf)
            {
                returnMatrix[i][j] = matrix22[i - shift][j - shift];
            }
        }
    }
    return returnMatrix;
}
//Creates a matrix of size n containing random values from 1 - 100
Matrix createRandomMatrix(int n)
{
    Matrix matrix(n, std::vector<int>(n));
    for (int i = 0; i < n; i++ )
    {
        for(int j = 0; j < n; j++)
        {
            matrix[i][j] = rand() % 101;
        }
    }
    return matrix;
}

void printMatrix(Matrix matrix)
{
    int matrixSize = matrix.size();

    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixSize; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl; 
}