#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MATRIX_SIZE 4
#define DISPLAY_MATRIX

// function to compute the entry c_ij
void* multi(void* arg) {
    int* data = (int*)arg;
    int k = 0;
    
    for (int i = 1; i <= data[0]; i++)
        k += data[i]*data[i + data[0]];
    
    int* p = (int*)malloc(sizeof(int));
    *p = k;

    // terminate a thread, return value by pass as a pointer
    pthread_exit(p);
}

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

    /////////////////////////////////////////////////////////////////////////////////
    //                                 multi thread                                //
    /////////////////////////////////////////////////////////////////////////////////

    // multiplication of matrix using thread
    pthread_t* threads;
    //declaring array of threads which is 
    threads = (pthread_t*)malloc(MATRIX_SIZE * MATRIX_SIZE * sizeof(pthread_t));

    int count = 0;
    // use for storing row and column elements
    int* data = NULL;

    for (int row = 0; row < MATRIX_SIZE; row++) {
        for (int col = 0; col < MATRIX_SIZE; col++) {
            // storing row and column elements in data
            data = (int *)malloc((20)*sizeof(int));
            
            // storing size of matrix
            data[0] = MATRIX_SIZE;

            for (int i = 0; i < MATRIX_SIZE; i++)
                data[i + 1] = matrixA[row][i];

            for (int i = 0; i < MATRIX_SIZE; i++)
                data[i + MATRIX_SIZE + 1] = matrixB[i][col];

            // create thread, each thread computes single element entries of c
            pthread_create(&threads[count++], NULL, multi, (void*)(data));

        }
    }

#ifdef DISPLAY_MATRIX
    
    printf("---Matrix C---\n");
    for (int i = 0; i < MATRIX_SIZE * MATRIX_SIZE; i++) {
        void* result;

        // join thread, get all result from each thread
        pthread_join(threads[i], &result);

        int *p = (int *)result;
        printf("%d ", *p);
        if ((i + 1) % MATRIX_SIZE == 0)
            printf("\n");
    }

    printf("----------\n");

    // printMatrix(matrixC);
#endif
    return 0;
}
