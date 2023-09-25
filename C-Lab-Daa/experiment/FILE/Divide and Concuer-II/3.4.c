#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform standard matrix multiplication (naive method)
void standardMultiply(int **A, int **B, int **C, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Function to allocate memory for a matrix
int **allocateMatrix(int n)
{
    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }
    return matrix;
}

// Function to deallocate memory for a matrix
void deallocateMatrix(int **matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to add two matrices
void matrixAdd(int **A, int **B, int **C, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to subtract two matrices
void matrixSubtract(int **A, int **B, int **C, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Function to perform Strassen's matrix multiplication
void strassenMultiply(int **A, int **B, int **C, int n)
{
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = n / 2;

    // Allocate memory for submatrices
    int **A11 = allocateMatrix(newSize);
    int **A12 = allocateMatrix(newSize);
    int **A21 = allocateMatrix(newSize);
    int **A22 = allocateMatrix(newSize);

    int **B11 = allocateMatrix(newSize);
    int **B12 = allocateMatrix(newSize);
    int **B21 = allocateMatrix(newSize);
    int **B22 = allocateMatrix(newSize);

    int **C11 = allocateMatrix(newSize);
    int **C12 = allocateMatrix(newSize);
    int **C21 = allocateMatrix(newSize);
    int **C22 = allocateMatrix(newSize);

    int **P1 = allocateMatrix(newSize);
    int **P2 = allocateMatrix(newSize);
    int **P3 = allocateMatrix(newSize);
    int **P4 = allocateMatrix(newSize);
    int **P5 = allocateMatrix(newSize);
    int **P6 = allocateMatrix(newSize);
    int **P7 = allocateMatrix(newSize);

    // Divide matrices A and B into 4 submatrices each
    for (int i = 0; i < newSize; i++)
    {
        for (int j = 0; j < newSize; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Calculate 7 products (P1 to P7) recursively
    matrixAdd(A11, A22, C11, newSize);
    matrixAdd(B11, B22, C12, newSize);
    strassenMultiply(C11, C12, P1, newSize);

    matrixAdd(A21, A22, C11, newSize);
    strassenMultiply(C11, B11, P2, newSize);

    matrixSubtract(B12, B22, C11, newSize);
    strassenMultiply(A11, C11, P3, newSize);

    matrixSubtract(B21, B11, C11, newSize);
    strassenMultiply(A22, C11, P4, newSize);

    matrixAdd(A11, A12, C11, newSize);
    strassenMultiply(C11, B22, P5, newSize);

    matrixSubtract(A21, A11, C11, newSize);
    matrixAdd(B11, B12, C12, newSize);
    strassenMultiply(C11, C12, P6, newSize);

    matrixSubtract(A12, A22, C11, newSize);
    matrixAdd(B21, B22, C12, newSize);
    strassenMultiply(C11, C12, P7, newSize);

    // Calculate the result submatrices C11, C12, C21, C22
    matrixAdd(P1, P4, C11, newSize);
    matrixSubtract(C11, P5, C11, newSize);
    matrixAdd(C11, P7, C11, newSize);

    matrixAdd(P3, P5, C12, newSize);

    matrixAdd(P2, P4, C21, newSize);

    matrixAdd(P1, P3, C22, newSize);
    matrixSubtract(C22, P2, C22, newSize);
    matrixAdd(C22, P6, C22, newSize);

    // Combine the result submatrices into C
    for (int i = 0; i < newSize; i++)
    {
        for (int j = 0; j < newSize; j++)
        {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }

    // Deallocate memory for submatrices
    deallocateMatrix(A11, newSize);
    deallocateMatrix(A12, newSize);
    deallocateMatrix(A21, newSize);
    deallocateMatrix(A22, newSize);

    deallocateMatrix(B11, newSize);
    deallocateMatrix(B12, newSize);
    deallocateMatrix(B21, newSize);
    deallocateMatrix(B22, newSize);

    deallocateMatrix(C11, newSize);
    deallocateMatrix(C12, newSize);
    deallocateMatrix(C21, newSize);
    deallocateMatrix(C22, newSize);

    deallocateMatrix(P1, newSize);
    deallocateMatrix(P2, newSize);
    deallocateMatrix(P3, newSize);
    deallocateMatrix(P4, newSize);
    deallocateMatrix(P5, newSize);
    deallocateMatrix(P6, newSize);
    deallocateMatrix(P7, newSize);
}

// Function to print a matrix
void printMatrix(int **A, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    srand(time(NULL));

    FILE *outputFile;
    outputFile = fopen("matrix_multiply_times.txt", "w");

    if (outputFile == NULL)
    {
        printf("Error opening the file.\n");
        return 1;
    }

    // Loop over different array sizes
    for (int n = 64; n <= 2000; n *= 2)
    {
        // Allocate memory for matrices A, B, and C
        int **A = allocateMatrix(n);
        int **B = allocateMatrix(n);
        int **C = allocateMatrix(n);

        // Initialize matrices A and B (you can set your own values)
        // ...
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // Fill A and B with random integers between 1 and 100 (adjust the range as needed)
                A[i][j] = rand() % 100 + 1;
                B[i][j] = rand() % 100 + 1;
            }
        }

        clock_t start, end;
        double normalTime, strassenTime;

        // Perform standard matrix multiplication
        start = clock();
        standardMultiply(A, B, C, n);
        end = clock();
        normalTime = (double)(end - start) / CLOCKS_PER_SEC;

        // Perform Strassen's matrix multiplication
        int **D = allocateMatrix(n);
        start = clock();
        strassenMultiply(A, B, D, n);
        end = clock();
        strassenTime = (double)(end - start) / CLOCKS_PER_SEC;

        printf("n = %d\n", n);
        printf("Time complexity by standar method: %lf\n", normalTime);
        printf("Time complexity by Strassen's method: %lf\n", strassenTime);

        // Write data to the output file
        fprintf(outputFile, "%d %lf %lf\n", n, normalTime, strassenTime);

        // Deallocate memory
        deallocateMatrix(A, n);
        deallocateMatrix(B, n);
        deallocateMatrix(C, n);
        deallocateMatrix(D, n);
    }

    fclose(outputFile);
    return 0;
}
