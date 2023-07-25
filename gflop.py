import numpy as np
import time

def matrix_multiply(A, B):
    return np.dot(A, B)

def measure_flops(num_iterations):
    a, b = 2.0, 3.0
    start_time = time.time()

    for i in range(num_iterations):
        c = a * b

    end_time = time.time()
    elapsed_time = end_time - start_time

    flops = (num_iterations * 2) / elapsed_time  # Assuming one multiplication is one FLOP

    return flops

def display_matrix(matrix):
    print(matrix)

def main():
    matrixA = np.array([
        [1, 2],
        [3, 4],
        [5, 6]
    ])

    matrixB = np.array([
        [7, 8, 9],
        [10, 11, 12]
    ])

    result = matrix_multiply(matrixA, matrixB)

    print("Matrix A:")
    display_matrix(matrixA)

    print("Matrix B:")
    display_matrix(matrixB)

    print("Resultant Matrix:")
    display_matrix(result)

    num_iterations = 1000000
    flops = measure_flops(num_iterations)
    print("Estimated FLOPs:", flops)

if __name__ == "__main__":
    main()
