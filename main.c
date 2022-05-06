#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MATRIX_SIZE 3

void printMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("----------\n");
}

int main(int argc, char *argv[]) {
    // srand(time(0));

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
    //     c_ij = sum from k=1 to n a_ik b_kj ; when a is m x n matrix and b is n x p matrix c is matrix product
    int matrixC[MATRIX_SIZE][MATRIX_SIZE];

    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            int sum = 0;
            // sum
            for (int k = 0; k < MATRIX_SIZE; k++) {
                sum += matrixA[i][k] * matrixB[k][j];
            }
            matrixC[i][j] = sum;
        }
    }

    printMatrix(matrixA);
    printMatrix(matrixB);

    printf("----------\n");

    printMatrix(matrixC);
    return 0;
}
