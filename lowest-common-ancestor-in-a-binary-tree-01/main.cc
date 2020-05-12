#include <iostream>
#include <string>

using namespace std;

class set_graph {
    static size_t constexpr EDGES_SIZE = 1001;
    signed *edges;
    void edge(signed const from, signed const to) {
        if (from >= 0) {
            edges[from] = to;
        }
    }
    size_t ancestors(signed *report, signed a) {
        // Start from i = 0. Do it until node with -1 parent found.
        size_t i = 0;
        signed ancestor = a;
        while (ancestor >= 0) {
            report[i++] = ancestor;
            ancestor = edges[ancestor];
        }
        return i;
    }
public:
    set_graph() : edges(new signed[EDGES_SIZE]) {
        fill_n(edges, EDGES_SIZE, -1);
    }
    ~set_graph() {
        delete[] edges;
    }
    void interpret(signed const *traversal, size_t const n) {
        signed const * const traversal_end = traversal + n;
        signed * const row = new signed[32];
        size_t n_fetch = 1;
        for (;;) {
            // Process n_fetch elements.
            // Record # of non-negatives in m.
            size_t m = 0;
            for (size_t i = 0; i < n_fetch; ++i) {
                auto const x = traversal[i];
                if (x >= 0) {
                    row[m++] = x;
                }
            }
            traversal += n_fetch;
            if (traversal < traversal_end) {
                for (size_t i = 0, j = 0; i < m; ++i) {
                    auto const x = row[i];
                    edge(traversal[j++], x);
                    edge(traversal[j++], x);
                }
                n_fetch = m << 1;
            }
            else {
                break;
            }
        }
        delete[] row;
    }
    signed least_common_ancestor(signed a, signed b) {
        size_t constexpr MAX_NODES = 100;
        signed *a_ancestors = new signed[MAX_NODES];
        signed *b_ancestors = new signed[MAX_NODES];

        if (ancestors(a_ancestors, a) && ancestors(b_ancestors, b)) {
            for (size_t i = 0;; ++i) {
                if (a_ancestors[i] == b_ancestors[i]) {
                    signed lcm = a_ancestors[i];
                    delete[] a_ancestors;
                    delete[] b_ancestors;
                    return lcm;
                }
            }
        }

        delete[] a_ancestors;
        delete[] b_ancestors;
        return -1;
    }
    void print() {
        for (size_t i = 0; i < EDGES_SIZE; ++i) {
            if (edges[i] >= 0) {
                cout << i << " -> " << edges[i] << endl;
            }
        }
    }
};

int main() {
    set_graph s;
    string x;       // for converting string to number
    size_t n;       // number of nodes, including non-vertices (negative)
    cin >> n;
    size_t a, b;    // children whose ancestors must be found.
    cin >> a >> b;

    signed *traversal = new signed[n];
    for (size_t i = 0; i < n; ++i) {
        cin >> x;
        if (x != "N") {
            signed p = stoi(x);
            traversal[i] = p;
        }
        else {
            traversal[i] = -1;
        }
    }
    s.interpret(traversal, n);
    delete[] traversal;

    s.print();
    cout << s.least_common_ancestor(a, b) << endl;
    return 0;
}
