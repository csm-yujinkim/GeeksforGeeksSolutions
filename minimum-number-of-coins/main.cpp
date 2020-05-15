#include <iostream>

using namespace std;

#define proc(n, m) if (n >= m) { cout << #m " "; n -= m; continue; }

int main() {
    size_t t;
    cin >> t;
    while (t--) {
        size_t n;
        cin >> n;
        while (n) {
            proc(n, 2000);
            proc(n, 500);
            proc(n, 200);
            proc(n, 100);
            proc(n, 50);
            proc(n, 20);
            proc(n, 10);
            proc(n, 5);
            proc(n, 2);
            proc(n, 1);
        }
        cout << '\n';
    }
}
