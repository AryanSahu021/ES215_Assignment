#include <iostream>
#include <ctime>
#include <vector>

long long fibonacci_recursive(int n) {
    if (n <= 1) return n;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n-2);
}

void print_fibonacci_recursive() {
    for (int i = 0; i < 50; i++) {
        std::cout << fibonacci_recursive(i) << " ";
    }
    std::cout << std::endl;
}
void print_fibonacci_loop() {
    std::cout << "0 ";
    for (int j = 1; j < 50; ++j) {
        long long a = 0;
        long long b = 1;
        for (int i = 2; i <= j; i++) {
            long long c = a + b;
            a = b;
            b = c;
        }
        std::cout << b << " ";
    }
     std::cout << std::endl;
}
std::vector<long long> memo(50, -1);

long long fibonacci_memoization(int n) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    memo[n] = fibonacci_memoization(n - 1) + fibonacci_memoization(n - 2);
    return memo[n];
}

void print_fibonacci_memoization() {
    for (int i = 0; i < 50; i++) {
        std::cout << fibonacci_memoization(i) << " ";
    }
    std::cout << std::endl;
}
void print_fibonacci_loop_memoization() {
    std::vector<long long> fib(50);
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i < 50; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    for (int i = 0; i < 50; i++) {
        std::cout << fib[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Time measurement for recursion
    long sec, nano;
    double trec, tloop, trecm, tloopm;
    struct timespec start,end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    print_fibonacci_recursive();
    clock_gettime(CLOCK_MONOTONIC, &end);
    sec = end.tv_sec - start.tv_sec;
    nano = end.tv_nsec - start.tv_nsec;
    trec = sec + nano * 1e-9;
    std::cout << "Time taken by recursion: " << trec << " seconds" << std::endl;

    // Time measurement for loop
    clock_gettime(CLOCK_MONOTONIC, &start);
    print_fibonacci_loop();
    clock_gettime(CLOCK_MONOTONIC, &end);
    sec = end.tv_sec - start.tv_sec;
    nano = end.tv_nsec - start.tv_nsec;
    tloop = sec + nano * 1e-9;
    std::cout << "Time taken by loop: " << tloop << " seconds" << std::endl;

    // Time measurement for recursion with memoization
    clock_gettime(CLOCK_MONOTONIC, &start);
    print_fibonacci_memoization();
    clock_gettime(CLOCK_MONOTONIC, &end);
    sec = end.tv_sec - start.tv_sec;
    nano = end.tv_nsec - start.tv_nsec;
    trecm = sec + nano * 1e-9;
    std::cout << "Time taken by recursion with memoization: " << trecm << " seconds" << std::endl;

    // Time measurement for loop with memoization
    clock_gettime(CLOCK_MONOTONIC, &start);
    print_fibonacci_loop_memoization();
    clock_gettime(CLOCK_MONOTONIC, &end);
    sec = end.tv_sec - start.tv_sec;
    nano = end.tv_nsec - start.tv_nsec;
    tloopm = sec + nano * 1e-9;
    std::cout << "Time taken by loop with memoization: " << tloopm << " seconds" << std::endl;

    // Calculate and display speedups
    std::cout << "Speedup of loop over recursion: " << trec / tloop << std::endl;
    std::cout << "Speedup of recursion with memoization over recursion: " << trec / trecm << std::endl;
    std::cout << "Speedup of loop with memoization over recursion: " << trec / tloopm << std::endl;

    return 0;
}