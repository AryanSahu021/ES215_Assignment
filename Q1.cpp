#include <iostream>
#include <chrono>
#include <vector>

long long fibonacci_recursive(int n, int a, int b) {
    if (n == 1) return b;
    if (n == 0) return a;
    return fibonacci_recursive(n - 1, b, a+b);
}

void print_fibonacci_recursive() {
    for (int i = 0; i < 45; i++) {
        std::cout << fibonacci_recursive(i, 0, 1) << " ";
    }
    std::cout << std::endl;
}
void print_fibonacci_loop() {
    std::cout << "0 ";
    for (int j = 1; j < 45; ++j) {
        int a = 0;
        int b = 1;
        for (int i = 2; i <= j; i++) {
            int c = a + b;
            a = b;
            b = c;
        }
        std::cout << b << " ";
    }
     std::cout << std::endl;
}
std::vector<long long> memo(45, -1);

long long fibonacci_memoization(int n) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    memo[n] = fibonacci_memoization(n - 1) + fibonacci_memoization(n - 2);
    return memo[n];
}

void print_fibonacci_memoization() {
    for (int i = 0; i < 45; i++) {
        std::cout << fibonacci_memoization(i) << " ";
    }
    std::cout << std::endl;
}
void print_fibonacci_loop_memoization() {
    std::vector<long long> fib(45);
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i < 45; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    for (int i = 0; i < 45; i++) {
        std::cout << fib[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Time measurement for recursion
    auto start = std::chrono::high_resolution_clock::now();
    print_fibonacci_recursive();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_recursive = end - start;
    std::cout << "Time taken by recursion: " << time_recursive.count() << " seconds" << std::endl;

    // Time measurement for loop
    start = std::chrono::high_resolution_clock::now();
    print_fibonacci_loop();
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_loop = end - start;
    std::cout << "Time taken by loop: " << time_loop.count() << " seconds" << std::endl;

    // Time measurement for recursion with memoization
    start = std::chrono::high_resolution_clock::now();
    print_fibonacci_memoization();
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_rec_memo = end - start;
    std::cout << "Time taken by recursion with memoization: " << time_rec_memo.count() << " seconds" << std::endl;

    // Time measurement for loop with memoization
    start = std::chrono::high_resolution_clock::now();
    print_fibonacci_loop_memoization();
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_loop_memo = end - start;
    std::cout << "Time taken by loop with memoization: " << time_loop_memo.count() << " seconds" << std::endl;

    // Calculate and display speedups
    std::cout << "Speedup of loop over recursion: " << time_recursive.count() / time_loop.count() << std::endl;
    std::cout << "Speedup of recursion with memoization over recursion: " << time_recursive.count() / time_rec_memo.count() << std::endl;
    std::cout << "Speedup of loop with memoization over recursion: " << time_recursive.count() / time_loop_memo.count() << std::endl;

    return 0;
}