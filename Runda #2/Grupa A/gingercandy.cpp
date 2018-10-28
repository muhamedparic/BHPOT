#include <bits/stdc++.h>
#pragma GCC optimize("O0")

using namespace std;

void init(int n, int T);
void add(int a, int b, int s);
void flat(int a, int b);
long long sum(int a, int b);

struct Akum {
    long long suma;
    bool reset;
    Akum() {
        suma = 0;
        reset = false;
    }
};

struct Node {
    Node* left;
    Node* right;
    int a, b;
    Akum akum;
    long long prev_sum;

    Node(int a, int b): a(a), b(b), prev_sum(0) {left = right = nullptr; akum = Akum();}

    Node* access_left() {
        if (left == nullptr) {
//            cout << "EVO MEEE" << a << " " << b << endl;
            return left = new Node(a, (a+b)/2);
        }
        return left;
    }

    Node* access_right() {
        if (right == nullptr) {
//            cout << "EVO MEEE" << a << " " << b << endl;
            return right = new Node((a+b)/2 + 1, b);
        }
        return right;
    }

    void add_s(long long s) {
        akum.suma += s;
    }

    void apply_set(long long s) {
        akum.reset = true;
        akum.suma = s;
        prev_sum = 0;
    }

    void apply_top_akum(const Akum& ak) {
        if (ak.reset) {
            apply_set(ak.suma);
        } else {
            add_s(ak.suma);
        }
    }

    void reset_akum() {
        akum.suma = 0;
        akum.reset = false;
        prev_sum = access_left()->give_suma() + access_right()->give_suma();
    }

    long long give_suma() {
        if (akum.reset) {
            return akum.suma * (b-a+1);
        } else {
            return prev_sum + akum.suma * (b-a+1);
        }
    }

    ~Node() {
        delete left;
        left = nullptr;
        delete right;
        right = nullptr;
    }
};




struct SegTree {
    Node* root;
    explicit SegTree(int n) {
        root = new Node(0, n-1);
    }

    void intern_add(Node* tr, int a, int b, long long s) {
        if (tr->a >= a && tr->b <= b) {
            tr->add_s(s);
            return;
        }
        if (tr->b < a || tr->a > b) {
            return;
        }

        tr->access_left()->apply_top_akum(tr->akum);
        intern_add(tr->access_left(), a, b, s);

        tr->access_right()->apply_top_akum(tr->akum);
        intern_add(tr->access_right(), a, b, s);

        tr->reset_akum();
    }

    void intern_set(Node* tr, int a, int b, long long s) {
        if (tr->a >= a && tr->b <= b) {
            tr->apply_set(s);
            return;
        }
        if (tr->b < a || tr->a > b) {
            return;
        }

        tr->access_left()->apply_top_akum(tr->akum);
        intern_set(tr->access_left(), a, b, s);

        tr->access_right()->apply_top_akum(tr->akum);
        intern_set(tr->access_right(), a, b, s);

        tr->reset_akum();
    }

    long long intern_sum(Node *tr, int a, int b) {
        if (tr->a >= a && tr->b <= b) {
            return tr->give_suma();
        }
        if (tr->b < a || tr->a > b) {
            return 0;
        }

        long long suma = 0;

        tr->access_left()->apply_top_akum(tr->akum);
        suma += intern_sum(tr->access_left(), a, b);

        tr->access_right()->apply_top_akum(tr->akum);
        suma += intern_sum(tr->access_right(), a, b);

        tr->reset_akum();

        return suma;
    }


    void add(int a, int b, int s) {
        intern_add(root, a, b, (long long)s);
    }

    void set(int a, int b, long long s) {
        intern_set(root, a, b, s);
    }

    long long sum(int a, int b) {
        return intern_sum(root, a, b);
    }

    ~SegTree() {
        delete root;
    }
} *seg_tree;

void init(int n, int t) {
    seg_tree = new SegTree(n);
}

void oblak(int a, int b, int s) {
    seg_tree->add(a, b, s);
}

void vjetar(int a, int b) {
    long long val = sum(a, b)/(b-a+1);
    seg_tree->set(a, b, val);
}

long long sum(int a, int b) {
    seg_tree->sum(a, b);
}