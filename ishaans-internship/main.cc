#include <iostream>
#include <cmath>

using namespace std;

int main() {
    size_t t;
    cin >> t;
    while (t--) {
        size_t n, k;
        cin >> n >> k;
        cout << pow(k, floor(log(n) / log(k))) << endl;
    }
    return 0;
}
