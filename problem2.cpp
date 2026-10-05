#include <chrono>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace std::chrono;


int linearSearch(int A[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (A[i] == key) return i;
    }
    return -1;
}


int main() {

    int n = 1000;
    int A[n];
    srand(time(0));
    for (int i = 0; i < n; i++) {
        A[i] = i;
    }
    auto start = high_resolution_clock::now();

    int best = linearSearch(A, n, 0);
    // int avg = linearSearch(A, n, 500);
    // int worst = linearSearch(A, n, -999999);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken : " << duration.count() << " microseconds" << endl;



    return 0;
}
