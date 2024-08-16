import numpy as np
import time

def matrix_multiplication(N, dtype):
    start_sys = time.time()
    start_cpu = time.process_time()

    A = np.random.randint(0, 100, size=(N, N)).astype(dtype)
    B = np.random.randint(0, 100, size=(N, N)).astype(dtype)
    C = np.zeros((N, N), dtype=dtype)

    mstart_sys = time.time()
    mstart_cpu = time.process_time()
    # Manual matrix multiplication
    for i in range(N):
        for j in range(N):
            for k in range(N):
                C[i][j] += A[i][k] * B[k][j]
    mend_sys = time.time()
    mend_cpu = time.process_time()
    end_sys = time.time()
    end_cpu = time.process_time()

    msystime = mend_sys - mstart_sys
    mcputime = mend_cpu - mstart_cpu
    systime = end_sys - start_sys
    cputime = end_cpu - start_cpu
    return systime, cputime, msystime, mcputime

def main():
    sizes = [64, 128, 256, 512, 1024]

    for N in sizes:
        print(f"Matrix Size: {N}x{N}")
        systime, cputime, msystime, mcputime = matrix_multiplication(N, np.int32)
        print(f"Integer Multiplication Time")
        print(f"System Time: {systime:.6f} seconds")
        print(f"CPU Time: {cputime:.6f} seconds")
        print(f"System Time  (Meat): {msystime:.6f} seconds")
        print(f"CPU Time (Meat): {mcputime:.6f} seconds")
        systime, cputime, msystime, mcputime = matrix_multiplication(N, np.float64)
        print(f"Double Multiplication Time")
        print(f"System Time: {systime:.6f} seconds")
        print(f"CPU Time: {cputime:.6f} seconds")
        print(f"System Time (Meat): {msystime:.6f} seconds")
        print(f"CPU Time (Meat): {mcputime:.6f} seconds")
        print("-" * 30)

if __name__ == "__main__":
    main()
