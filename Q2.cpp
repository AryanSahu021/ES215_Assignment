#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

template<typename T>
void matrixMultiplication(int N) {
    struct timespec start_sys, start_cpu, end_sys, end_cpu;
    long long sec_sys, nano_sys;
    long long sec_cpu, nano_cpu;
    double t_sys, t_cpu;
    struct timespec startf_sys, startf_cpu, endf_sys, endf_cpu;
    long long fsec_sys, fnano_sys;
    long long fsec_cpu, fnano_cpu;
    double ft_sys, ft_cpu;

    clock_gettime(CLOCK_MONOTONIC, &startf_sys);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &startf_cpu);
    
    vector<vector<T>> A(N, vector<T>(N));
    vector<vector<T>> B(N, vector<T>(N));
    vector<vector<T>> C(N, vector<T>(N));

    // Initialize matrices with random values
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            A[i][j] = rand() % 100;
            B[i][j] = rand() % 100;
        }
    }

    clock_gettime(CLOCK_MONOTONIC, &start_sys);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start_cpu);
    // Perform matrix multiplication
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < N; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    clock_gettime(CLOCK_MONOTONIC, &end_sys);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end_cpu);
    clock_gettime(CLOCK_MONOTONIC, &endf_sys);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &endf_cpu);

    sec_sys = end_sys.tv_sec - start_sys.tv_sec;
    nano_sys = end_sys.tv_nsec - start_sys.tv_nsec;
    t_sys = sec_sys + nano_sys * 1e-9;

    sec_cpu = end_cpu.tv_sec - start_cpu.tv_sec;
    nano_cpu = end_cpu.tv_nsec - start_cpu.tv_nsec;
    t_cpu = sec_cpu + nano_cpu * 1e-9;

    fsec_sys = endf_sys.tv_sec - startf_sys.tv_sec;
    fnano_sys = endf_sys.tv_nsec - startf_sys.tv_nsec;
    ft_sys = fsec_sys + fnano_sys * 1e-9;

    fsec_cpu = endf_cpu.tv_sec - startf_cpu.tv_sec;
    fnano_cpu = endf_cpu.tv_nsec - startf_cpu.tv_nsec;
    ft_cpu = fsec_cpu + fnano_cpu * 1e-9;

    cout << "System Time (Full): " << ft_sys << " seconds" << endl;
    cout << "CPU Time (Full): " << ft_cpu << " seconds" << endl;
    cout << "System Time (Meat): " << t_sys << " seconds" << endl;
    cout << "CPU Time (Meat): " << t_cpu << " seconds" << endl;
}

int main() {
    int sizes[] = { 64, 128, 256, 512, 1024 };

    for (int N : sizes) {
        cout << "Matrix Size: " << N << "x" << N << endl;

        cout << "Integer Multiplication:" << endl;
        matrixMultiplication<int>(N);

        cout << "Double Multiplication:" << endl;
        matrixMultiplication<double>(N);

        cout << "-------------------------" << endl;
    }

    return 0;
}
