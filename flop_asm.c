#include <stdio.h>
#include <time.h>

#define ROWS_A 3
#define COLS_A 2
#define ROWS_B 2
#define COLS_B 3

void matrix_multiply(int A[][COLS_A], int B[][COLS_B], int C[][COLS_B]) {
    int i, j, k;

    for (i = 0; i < ROWS_A; i++) {
        for (j = 0; j < COLS_B; j++) {
            C[i][j] = 0;
            for (k = 0; k < COLS_A; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

double measure_flops(int num_iterations) {
    double a = 2.0, b = 3.0, c;
    clock_t start_time, end_time;

    start_time = clock();

    for (int i = 0; i < num_iterations; i++) {
        asm volatile("fld %1; fld %2; fmulp" : "=t" (c) : "m" (a), "m" (b));
    }

    end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    double flops = (num_iterations * 2) / elapsed_time; // Assuming one multiplication is one FLOP

    return flops;
}

void display_matrix(int matrix[][COLS_B], int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrixA[ROWS_A][COLS_A] = {
        {1, 2},
        {3, 4},
        {5, 6}
    };

    int matrixB[ROWS_B][COLS_B] = {
        {7, 8, 9},
        {10, 11, 12}
    };

    int result[ROWS_A][COLS_B];

    double flops;
    int num_iterations = 1000000;

    matrix_multiply(matrixA, matrixB, result);

    printf("Matrix A:\n");
    display_matrix(matrixA, ROWS_A, COLS_A);

    printf("Matrix B:\n");
    display_matrix(matrixB, ROWS_B, COLS_B);

    printf("Resultant Matrix:\n");
    display_matrix(result, ROWS_A, COLS_B);

    flops = measure_flops(num_iterations);
    printf("Estimated FLOPs: %lf\n", flops);

    return 0;
}
