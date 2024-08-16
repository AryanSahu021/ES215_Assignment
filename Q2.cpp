#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

template<typename T>
void matrixMultiplication(int N) {
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

    auto start = chrono::high_resolution_clock::now();
    // Perform matrix multiplication
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < N; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;

    cout << "Time taken: " << diff.count() << " seconds" << endl;
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
