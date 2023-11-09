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
