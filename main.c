#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MATRIX_SIZE 4
#define DISPLAY_MATRIX

void printMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    printf("----------\n");
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

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

    /////////////////////////////////////////////////////////////////////////////////
    //                               single thread                                 //
    /////////////////////////////////////////////////////////////////////////////////


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

#ifdef DISPLAY_MATRIX
    printf("matrix multilplication\n");
    printf("---Matrix A---\n");
    printMatrix(matrixA);
    printf("---Matrix B---\n");
    printMatrix(matrixB);

    printf("---Matrix C---\n");
    printMatrix(matrixC);
#endif

    /////////////////////////////////////////////////////////////////////////////////
    //                                 multi thread                                //
    /////////////////////////////////////////////////////////////////////////////////

    // multiplication of matrix using thread
    int count = 0;
    int* data = NULL;
    pthread_t* threads;
    threads = (pthread_t*)malloc(MATRIX_SIZE * MATRIX_SIZE * sizeof(pthread_t));


#ifdef DISPLAY_MATRIX
    
    printf("----------\n");

    // printMatrix(matrixC);
#endif
    return 0;
}
