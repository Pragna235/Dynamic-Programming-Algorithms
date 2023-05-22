#include <iostream>
#include <vector>
using namespace std;

int yuckdonalds(const vector<int>& m, const vector<int>& p, int k) {
    vector<int> T(p.size(), 0);

    for (int i = 0; i < m.size(); i++) {
        T[i] = p[i];
        for (int j = i - 1; j >= 0; j--) {
            if (m[i] - m[j] >= k) {
                T[i] = max(T[i], p[i] + T[j]);
            }
        }
        T[i] = max(T[i], (i > 0) ? T[i - 1] : 0);
    }

    return T.back();
}

int main() {
    vector<int> m = {0, 5, 6, 11, 14, 20, 22, 28}; //miles
    vector<int> p = {30, 10, 40, 1, 15, 5, 23, 17};//profits
    int k = 5; //min distance between two shops
    cout << "m = ";
    for (int i : m) {
        cout << i << " ";
    }
    cout <<endl;
    cout << "p = ";
    for (int i : p) {
        cout << i << " ";
    }
    cout << endl;
    cout << "k = " << k << endl;
    int p_ = yuckdonalds(m, p, k);
    cout << "Maximum total profit = " << p_ << endl;
    cout<<endl;

    m = {1, 10, 16, 21, 22, 35, 38};
    p = {30, 9, 13, 25, 23, 3, 10};
    k = 10;
    cout << "m = ";
    for (int i : m) {
        cout << i << " ";
    }
    cout << endl;
    cout << "p = ";
    for (int i : p) {
        cout << i << " ";
    }
    cout << endl;
    cout << "k = " << k << endl;
    p_ = yuckdonalds(m, p, k);
    cout << "Maximum total profit = " << p_ << endl;
    cout<<endl;

    m = {10, 20, 25, 30, 40};
    p = {100, 100, 101, 100, 100};
    k = 10;
    cout << "m = ";
    for (int i : m) {
        cout << i << " ";
    }
    cout << endl;
    cout << "p = ";
    for (int i : p) {
        cout << i << " ";
    }
    cout << endl;
    cout << "k = " << k << endl;
    p_ = yuckdonalds(m, p, k);
    cout << "Maximum total profit = " << p_ << endl;
    cout<<endl;

    m = {0, 4, 8};
    p = {10, 42, 31};
    k = 5;
    cout << "m = ";
    for (int i : m) {
        cout << i << " ";
    }
    cout << endl;
    cout << "p = ";
    for (int i : p) {
        cout << i << " ";
    }
    cout << endl;
    cout << "k = " << k << endl;
    p_ = yuckdonalds(m, p, k);
    cout << "Maximum total profit = " << p_ << endl;

    return 0;
}
