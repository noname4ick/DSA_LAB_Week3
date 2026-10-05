#include <chrono>
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

int main() {

    int n = 100000;

    // ==========================================
    // (a) Vector WITHOUT reservation
    // ==========================================

    vector<int> v;

    cout << "Capacity changes for v:" << endl;

    size_t oldCapacity = v.capacity();

    for (int i = 0; i < n; i++) {
        v.push_back(rand());

        if (v.capacity() != oldCapacity) {
            cout << "Size: " << v.size()
                 << " | Capacity: " << v.capacity()
                 << endl;

            oldCapacity = v.capacity();
        }
    }


    // ==========================================
    // (b) Vector WITH reservation
    // ==========================================

    vector<int> w;

    w.reserve(n);

    cout << "\nVector w after reserve:" << endl;
    cout << "Size: " << w.size()
         << " | Capacity: " << w.capacity()
         << endl;

    for (int i = 0; i < n; i++) {
        w.push_back(rand());
    }

    cout << "After inserting " << n << " elements:" << endl;
    cout << "Size: " << w.size()
         << " | Capacity: " << w.capacity()
         << endl;


    // ==========================================
    // Time WITHOUT reserve
    // ==========================================

    auto start = high_resolution_clock::now();

    vector<int> a;

    for (int i = 0; i < n; i++) {
        a.push_back(rand());
    }

    auto stop = high_resolution_clock::now();

    auto duration1 =
        duration_cast<microseconds>(stop - start);

    cout << "\nTime without reserve: "
         << duration1.count()
         << " microseconds" << endl;


    // ==========================================
    // Time WITH reserve
    // ==========================================

    start = high_resolution_clock::now();

    vector<int> b;

    b.reserve(n);

    for (int i = 0; i < n; i++) {
        b.push_back(rand());
    }

    stop = high_resolution_clock::now();

    auto duration2 =
        duration_cast<microseconds>(stop - start);

    cout << "Time with reserve: "
         << duration2.count()
         << " microseconds" << endl;

    cout << "Without reserve: "<< duration1.count() << " microseconds" << endl;

    cout << "With reserve:    "<< duration2.count()<< " microseconds" << endl;


    return 0;
}
