#include <iostream>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

class Node {
private:
    Node *left;
    Node *right;

    union signedptr_t {
        signed signed_part;
        Node *pointer_part;
    };

    bool ptr_negative(signedptr_t s) {
        return s.signed_part < 0;
    }

    signed ptr_signed(signedptr_t s) {
        return s.signed_part;
    }

    Node *ptr_ptr(signedptr_t s) {
        return s.pointer_part;
    }

    signedptr_t ptr_wrap(Node *p) {
        signedptr_t sp;
        sp.pointer_part = p;
        return sp;
    }

    signedptr_t ptr_make_signed(signed x) {
        signedptr_t sp;
        sp.signed_part = x;
        return sp;
    }

    // -1: This node is found to be not the ancestor of either a or b
    // -2: This node is found to be an ancestor of one of a or b but not both
    // pointer: The return value is the deepest common ancestor
    signedptr_t internal_lca(Node *n, int a, int b) {
        if (n) {
            if (n->left) {
                if (n->right) {
                    if (n->left->data == a) {
                        if (n->right->data == b) {
                            return ptr_wrap(this);
                        }
                        else {
                            signedptr_t r = internal_lca(n->right, a, b);
                            if (ptr_negative(r)) {
                                return ptr_make_signed(-2);
                            }
                            else {
                                return r;
                            }
                        }
                    }
                    else {
                        if (n->right->data == b) {
                            signedptr_t r = internal_lca(n->left, a, b);
                            if (ptr_negative(r)) {
                                return ptr_make_signed(-2);
                            }
                            else {
                                return r;
                            }
                        }
                        else {
                            signedptr_t l = internal_lca(n->left, a, b);
                            signedptr_t r = internal_lca(n->right, a, b);
                            if (ptr_negative(l)) {
                                if (ptr_signed(r) == -1) {
                                    return ptr_make_signed(-1);
                                }
                                else {
                                    if (ptr_signed(r) == -2) {
                                        return ptr_make_signed(-2);
                                    }
                                    else {
                                        return r;
                                    }
                                }
                            }
                            else {
                                // logic too complicated
                            }
                        }
                    }
                }
            }
        }
        else {
            return ptr_make_signed(-1);
        }
    }

public:
    int data;

    // BFS interpretation
    static Node *bfs_interpret(string const &str) {
        if (str.size() && str[0] != 'N') {
            queue<Node *> q;
            istringstream in(str);
            Node *root;
            for (string s; in >> s;) {
                int x = stoi(s);
                root = new Node(x);
                q.push(root);
                while (!q.empty()) {
                    Node *n = q.front();
                    q.pop();

                    // left child
                    string ns;
                    if (in >> ns) {
                        if (ns.size() && ns[0] != 'N') {
                            int nx = stoi(ns);
                            n->left = new Node(nx);
                            q.push(n->left);
                        }
                    }

                    // right child
                    if (in >> ns) {
                        if (ns.size() && ns[0] != 'N') {
                            int nx = stoi(ns);
                            n->right = new Node(nx);
                            q.push(n->right);
                        }
                    }
                }
            }
            return root;
        }
        else {
            return nullptr;
        }
    }

    Node(int x) : data(x), left(nullptr), right(nullptr) {
    }

    ~Node() {
        if (left) {
            delete left;
        }
        if (right) {
            delete right;
        }
    }

    void print_inorder() {
        if (left) {
            left->print_inorder();
        }
        cout << data << " ";
        if (right) {
            right->print_inorder();
        }
    }

    Node *lca(int child_1, int child_2) {
        
    }
};

int main() {
    size_t t;
    cin >> t;
    while (--t) {
        size_t a, b;
        cin >> a >> b;
        string s;
        getline(cin, s);
        Node *n = Node::bfs_interpret(s);
        Node *r = n->lca(a, b);
        cout << r->data << endl;
    }
    return 0;
}
