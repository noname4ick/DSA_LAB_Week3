#include <iostream>
#include <chrono>
#include <iomanip>
using namespace std;

long long fibRecursive(int n) {
    if (n <= 1) return n;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

unsigned long long fibIterative(int n) {
    unsigned long long a = 0, b = 1;
    for (int i = 0; i < n; i++) {
        unsigned long long next = a + b;
        a = b;
        b = next;
    }
    return a;
}

template <class F>
double timeMs(F f, int reps, long long& sink) {
    auto s = chrono::steady_clock::now();
    for (int r = 0; r < reps; r++) sink += f();
    auto e = chrono::steady_clock::now();
    return chrono::duration<double, milli>(e - s).count() / reps;
}

int main() {
    long long sink = 0;
    cout << fixed << setprecision(6);
    cout << "n\tRecursive (ms)\tIterative (ms)\n";

    int small[] = {20, 25, 30, 35};
    for (int n : small) {
        double r  = timeMs([&]{ return fibRecursive(n); }, n < 30 ? 20 : 1, sink);
        double it = timeMs([&]{ return (long long)fibIterative(n); }, 100000, sink);
        cout << n << "\t" << r << "\t" << it << "\n";
    }

    int big[] = {1000, 1000000};
    for (int n : big) {
        double it = timeMs([&]{ return (long long)fibIterative(n); },
                           n == 1000 ? 10000 : 100, sink);
        cout << n << "\t-\t" << it << "\n";
    }
    cerr << sink << "\n";
}
