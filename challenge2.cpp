#include <iostream>
#include <vector>
#include <random>
#include <chrono>
using namespace std;

using Matrix = vector<vector<int>>;

Matrix makeRandom(int n, mt19937& rng) {
    uniform_int_distribution<int> dist(0, 9);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            m[i][j] = dist(rng);
    return m;
}

Matrix multiply(const Matrix& A, const Matrix& B, int n) {
    Matrix C(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}

int main() {
    mt19937 rng(12345);
    int sizes[] = {50, 100, 200, 400};

    cout << "n\tTime (ms)\tApprox. bytes\n";
    for (int n : sizes) {
        Matrix A = makeRandom(n, rng);
        Matrix B = makeRandom(n, rng);

        auto start = chrono::high_resolution_clock::now();
        Matrix C = multiply(A, B, n);
        auto end = chrono::high_resolution_clock::now();

        double ms = chrono::duration<double, milli>(end - start).count();

        long long checksum = 0;
        for (int i = 0; i < n; i++) checksum += C[i][i];

        cout << n << "\t" << ms << "\t\t"
             << 3LL * n * n * sizeof(int)
             << "\t(checksum " << checksum << ")\n";
    }
    return 0;
}
