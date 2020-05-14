// Notes on Nearly Sorted Algorithm
//
// This tests on your knowledge of adaptive sorting algorithms
// A sorting algorithm is adaptive if it is significantly faster when the input is nearly sorted.
// Smoothsort is an adaptive variant of the heap sort algorithm, which is not adaptive.
//
// However, in practice (especially for small sets like the ones mentioned here)
// Most of the adaptive algorithms do worse than more conventional algorithms
// (Such as quicksort) because the popular algorithms are faster in a small scale.
//
// Thus this solution uses whatever internal algorithm std uses because
// the data is so small.

#include <array>
#include <algorithm>
#include <iostream>

using namespace std;

size_t t, n, k;
array<int, 100> xs;

int main() {
    cin >> t;
    while (t--) {
        // Not needed: k
        cin >> n >> k;
        for (size_t i = 0; i < n; ++i) {
            int x;
            cin >> x;
            xs[i] = x;
        }
        sort(xs.begin(), xs.begin() + n);
        for (size_t i = 0; i < n; ++i) {
            cout << xs[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
