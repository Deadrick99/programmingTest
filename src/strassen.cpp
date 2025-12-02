#include "strassen.h"
#include "matrix_utils.h"
#include "standard.h"

Matrix strassenMultiply(Matrix matrixA, Matrix matrixB, int baseCase)
{
    int matrixSize = matrixA.size();
    int quadrantSize = matrixSize/2;

    Matrix returnMatrix(matrixSize, std::vector<int>(matrixSize));

    if (matrixSize <= baseCase)
    {
        return standardMultiply(matrixA, matrixB);
    }
    
    Matrix matrixA11(quadrantSize, std::vector<int>(quadrantSize));
    Matrix matrixA12(quadrantSize, std::vector<int>(quadrantSize));
    Matrix matrixA21(quadrantSize, std::vector<int>(quadrantSize));
    Matrix matrixA22(quadrantSize, std::vector<int>(quadrantSize));

    Matrix matrixB11(quadrantSize, std::vector<int>(quadrantSize));
    Matrix matrixB12(quadrantSize, std::vector<int>(quadrantSize));
    Matrix matrixB21(quadrantSize, std::vector<int>(quadrantSize));
    Matrix matrixB22(quadrantSize, std::vector<int>(quadrantSize));

    split(matrixA, matrixA11, matrixA12, matrixA21, matrixA22);
    split(matrixB, matrixB11, matrixB12, matrixB21, matrixB22);

    Matrix M1 = strassenMultiply(add(matrixA11, matrixA22), add(matrixB11, matrixB22), baseCase);
    Matrix M2 = strassenMultiply(add(matrixA21, matrixA22), matrixB11, baseCase);
    Matrix M3 = strassenMultiply(matrixA11, subtract(matrixB12, matrixB22), baseCase);
    Matrix M4 = strassenMultiply(matrixA22, subtract(matrixB21, matrixB11), baseCase);
    Matrix M5 = strassenMultiply(add(matrixA11, matrixA12), matrixB22, baseCase);
    Matrix M6 = strassenMultiply(subtract(matrixA21, matrixA11), add(matrixB11, matrixB12), baseCase);
    Matrix M7 = strassenMultiply(subtract(matrixA12, matrixA22), add(matrixB21, matrixB22), baseCase);

    Matrix returnMatrix11 = add(subtract(add(M1, M4), M5), M7);
    Matrix returnMatrix12 = add(M3, M5);
    Matrix returnMatrix21 = add(M2, M4);
    Matrix returnMatrix22 = add(subtract(add(M1, M3), M2), M6);

    returnMatrix = combine(returnMatrix11, returnMatrix12, returnMatrix21, returnMatrix22);

    return returnMatrix;
}