#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
using namespace std;
using Clock = chrono::steady_clock;

struct Node {
    int data;
    Node* next;
};

static double ms(Clock::time_point s, Clock::time_point e) {
    return chrono::duration<double, milli>(e - s).count();
}

int main() {
    const int n = 1000000;
    const int target = n - 10;
    volatile long long sink = 0;
    cout << fixed << setprecision(3);

    vector<int> v;
    auto t0 = Clock::now();
    for (int i = 0; i < n; i++) v.push_back(i);
    auto t1 = Clock::now();
    int foundV = -1;
    for (size_t i = 0; i < v.size(); i++) if (v[i] == target) { foundV = (int)i; break; }
    auto t2 = Clock::now();
    sink += foundV;
    double vIns = ms(t0, t1), vSrch = ms(t1, t2);
    size_t vBytes = v.capacity() * sizeof(int);

    t0 = Clock::now();
    int* arr = new int[n];
    for (int i = 0; i < n; i++) arr[i] = i;
    t1 = Clock::now();
    int foundA = -1;
    for (int i = 0; i < n; i++) if (arr[i] == target) { foundA = i; break; }
    t2 = Clock::now();
    sink += foundA;
    double aIns = ms(t0, t1), aSrch = ms(t1, t2);
    size_t aBytes = (size_t)n * sizeof(int);

    Node* head = nullptr;
    Node* tail = nullptr;
    t0 = Clock::now();
    for (int i = 0; i < n; i++) {
        Node* node = new Node{i, nullptr};
        if (!head) head = tail = node;
        else { tail->next = node; tail = node; }
    }
    t1 = Clock::now();
    int foundL = -1;
    for (Node* p = head; p; p = p->next) if (p->data == target) { foundL = p->data; break; }
    t2 = Clock::now();
    sink += foundL;
    double lIns = ms(t0, t1), lSrch = ms(t1, t2);
    size_t lBytes = (size_t)n * sizeof(Node);

    cout << "n = " << n << ", target = " << target << "\n";
    cout << "Node size: " << sizeof(Node) << " bytes" << endl;
    cout << "Structure\tInsert (ms)\tSearch (ms)\tBytes/elem\tTotal bytes\n";
    cout << "vector\t" << vIns << "\t" << vSrch << "\t" << (double)vBytes / n << "\t" << vBytes << "\n";
    cout << "array\t"  << aIns << "\t" << aSrch << "\t" << (double)aBytes / n << "\t" << aBytes << "\n";
    cout << "list\t"   << lIns << "\t" << lSrch << "\t" << (double)lBytes / n << "\t" << lBytes << "\n";

    // free everything
    delete[] arr;
    while (head) { Node* nx = head->next; delete head; head = nx; }
    return 0;
}
