#include <iostream>
#include <array>

using namespace std;

int main() {
    // There will be exactly 5000 primes.
    // Primes can be one of [2 to 48619].
    // sqrt(48619) = 220.50
    // Indices 1 to 5000.
    array<bool, 48619 + 1> composite;
    fill(composite.begin(), composite.end(), false);
    for (size_t j = 4; j < composite.size(); j += 2) {
        composite[j] = true;
    }
    for (size_t i = 3; i < 221; i += 2) {
        if (!composite[i]) {
            for (size_t j = 2 * i; j < composite.size(); j += i) {
                composite[j] = true;
            }
        }
    }
    array<long, 5001> prepop;
    size_t i, j;
    for (i = 1, j = 2; i < prepop.size(); ++i) {
        prepop[i] = j * j + 1;
        while (composite[++j]) {
        }
    }
    // Input
    size_t t;
    cin >> t;
    while(t--) {
        size_t n;
        cin >> n;
        cout << prepop[n] << '\n';
    }
    return 0;
}
