#include <chrono>
#include <iostream>
#include <vector>
using namespace std;
using namespace std::chrono;

vector<int> v;                 // (a) no reservation
for (int i = 0; i < n; i++) {
    v.push_back(rand());
    // TODO: occasionally print v.capacity() to see it jump
}

vector<int> w;                 // (b) reserved ahead of time
w.reserve(n);
for (int i = 0; i < n; i++) {
    w.push_back(rand());
}

int main() {




    auto start = high_resolution_clock::now();

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken : " << duration.count() << " microseconds" << endl;


    return 0;
}
