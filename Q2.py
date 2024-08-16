import numpy as np
import time

def matrix_multiplication(N, dtype):
    A = np.random.randint(0, 100, size=(N, N)).astype(dtype)
    B = np.random.randint(0, 100, size=(N, N)).astype(dtype)
    C = np.zeros((N, N), dtype=dtype)

    start_time = time.time()
    # Manual matrix multiplication
    for i in range(N):
        for j in range(N):
            for k in range(N):
                C[i][j] += A[i][k] * B[k][j]
    end_time = time.time()

    return end_time - start_time

def main():
    sizes = [64, 128, 256, 512, 1024]
    for N in sizes:
        print(f"Matrix Size: {N}x{N}")
        
        int_time = matrix_multiplication(N, np.int32)
        print(f"Integer Multiplication Time: {int_time:.6f} seconds")
        
        double_time = matrix_multiplication(N, np.float64)
        print(f"Double Multiplication Time: {double_time:.6f} seconds")
        
        print("-" * 30)

if __name__ == "__main__":
    main()
