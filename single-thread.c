#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MATRIX_SIZE 100
// #define DISPLAY_MATRIX

int main(int argc, char *argv[]) {
    srand(time(NULL));
    // matrix A, B
    int matrixA[MATRIX_SIZE][MATRIX_SIZE];
    int matrixB[MATRIX_SIZE][MATRIX_SIZE];

    // random value in matrix
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            matrixA[i][j] = rand() % 10;
            matrixB[i][j] = rand() % 10;
        }
    }

    // multiplication
    // Definition: 
    //     the entry c_ij = sum from k=1 to n a_ik b_kj
    //     when a is m x n matrix and b is n x p matrix c is matrix product

    /////////////////////////////////////////////////////////////////////////////////
    //                               single thread                                 //
    /////////////////////////////////////////////////////////////////////////////////

    int matrixC[MATRIX_SIZE][MATRIX_SIZE];

    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            int sum = 0;
            // sum of multiplying term-by-term the entries
            for (int k = 0; k < MATRIX_SIZE; k++) {
                sum += matrixA[i][k] * matrixB[k][j];
            }
            matrixC[i][j] = sum;
        }
    }

#ifdef DISPLAY_MATRIX
    printf("matrix multilplication\n");
    printf("---Matrix A---\n");
    printMatrix(matrixA);
    printf("---Matrix B---\n");
    printMatrix(matrixB);

    printf("---Matrix C---\n");
    printMatrix(matrixC);
    printf("----------\n\n\n");
#endif
    return 0;
}