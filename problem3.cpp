#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;

void bubbleSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (A[j] > A[j + 1]) {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}


int main() {

    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int A[n];
    for (int i = 0; i < n; i++) {
        A[i] = n-i;
    }

    auto start = high_resolution_clock::now();

    bubbleSort(A, n);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken : " << duration.count() << " microseconds" << endl;



    return 0;
}
