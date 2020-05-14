#include <iostream>

int my_tree(int n, int k, int l) {
    if (l == 1) {
        return 1;
    }
    int m = (n - l * k) / l;
    int s = 0;
    for (int i = 0; i <= m; ++i) {
        s += my_tree(n, i, l - 1);
    }
    return s;
}

int main() {
    size_t t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        int s = 0;
        int m = n / 3;
        for (int i = 0; i <= m; ++i) {
            s += my_tree(n, i, 2);
        }
        std::cout << s << '\n';
    }
    return 0;
}
