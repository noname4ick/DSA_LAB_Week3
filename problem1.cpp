#include <chrono>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace std::chrono;


int arraySum(int A[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += A[i];
    }
    return sum;
}

int main() {

    int n = 100000;
    int A[n];
    srand(time(0));
    for (int i = 0; i < n; i++) {
        A[i] = rand() % 1000;
    }

    auto start = high_resolution_clock::now();

    int sum = arraySum(A, n);
    cout << "Sum: " << sum << endl;


    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken: " << duration.count() << " microseconds" << endl;
    return 0;
}
