#include "standard.h"
#include "matrix_utils.h"

// Multiplys two matrices: Matrix A and Matrix B and returns the resulting matrix
Matrix standardMultiply(Matrix matrixA, Matrix matrixB)
{
    int matrixSize = matrixA.size();
    Matrix returnMatrix(matrixSize, std::vector<int>(matrixSize, 0));
    for (int i = 0; i < matrixSize; i++ )
    {
        for(int j = 0; j < matrixSize; j++)
        {
            for (int k = 0; k < matrixSize; k++)
            {
                int matrixAValue = matrixA[i][k];
                int matrixBValue = matrixB[k][j];
                int product = matrixAValue * matrixBValue;
                returnMatrix[i][j] += product;
            }
        }
    }
    return returnMatrix;
}