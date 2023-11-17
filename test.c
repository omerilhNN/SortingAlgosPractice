#include <stdio.h>
#include <stdlib.h>

void readInput(int *N, int **firstMatrice, int **secondMatrice){
    FILE *inputFile = fopen("input.txt", "r");//Get reading access to the input.txt with "r" keyword.
    fscanf(inputFile, "%d", N);//N input in order to create two NxN matrices.

    //Dynamic memory allocation for matrices with unknown number of elements.
    *firstMatrice = (int *)malloc(((*N) * (*N + 1)) / 2 * sizeof(int));
    *secondMatrice = (int *)malloc(((*N) * (*N + 1)) / 2 * sizeof(int));


    //These two for loops are getting inputs from input.txt file
    for (int i = 0; i < ((*N) * (*N + 1)) / 2; i++) {//Reference: CENG-205 Lecture4 Slide -> Non-zero element size formule for upper triangular matrices
        fscanf(inputFile, "%d", &firstMatrice[i]); //Assign first line inputs (inside of the input.txt file) to the firstMatrix[i]'s address
    }
    for (int i = 0; i < ((*N) * (*N + 1)) / 2; i++) { //Number of elements of the array formule is  (n*(n+1))/2
        fscanf(inputFile, "%d", &secondMatrice[i]); //Assign inputs from inputFile of second line to this secondMatrix Array
    }
    fclose(inputFile);// Prevents resource leaks, releases resource after
}

void multiplyMatrices(int n, int *firstMatrix, int *secondMatrix, int *result) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            result[i * n + j] = 0;
            for (int k = i; k <= j; k++) {
                resultMatrix[i * n + j] += firstMatrix[i * n + k] * secondMatrix[k * n + j];
            }
        }
    }
}

void print1DArray(int n, int *arr) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            printf("%d ", arr[i * n + j]);
        }
    }
}

void print2DMatrix(int n, int *arr) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", arr[i * n + j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    int *firstMatrix,**secondMatrix,*resultMatrix;

    readInput(&n, firstMatrix, secondMatrix);
    multiplyMatrices(n, firstMatrix, secondMatrix, resultMatrix);

    printf(" Result as 1D Array:\n");
    print1DArray(n, resultMatrix);

    printf("\n\n");

    printf(" Result as 2D Matrix:\n");
    print2DMatrix(n, resultMatrix);

    //Free all arrays that dynamically allocated in memory.
    free(firstMatrix);
    free(secondMatrix);
    free(resultMatrix);


    return 0;
}
