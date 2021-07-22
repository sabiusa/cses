//
//  main.cpp
//  reversals-and-sums
//
//  Created by Saba Khutsishvili on 21.07.21.
//

#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

int n, m;
vector<int> v;

struct Node {
    Node *left, *right;
    int weight, size, value;
    bool rev;
    ll sum;

    Node(int val) {
        left = right = NULL;
        weight = rand();
        size = 1;
        value = val;
        rev = false;
        sum = val;
    }
};

int size(Node* treap) {
    if (treap == NULL) return 0;
    return treap->size;
}

ll sum(Node* treap) {
    if (treap == NULL) return 0;
    return treap->sum;
}

void propagete(Node* treap) {
    if (treap && treap->rev) {
        treap->rev = false;
        swap(treap->left, treap->right);
        if (treap->left) treap->left->rev ^= 1;
        if (treap->right) treap->right->rev ^= 1;
    }
}

void split(Node* treap, Node* &left, Node* &right, int k) {
    if (treap == NULL) {
        left = right = NULL;
    } else {
        propagete(treap);
        if (size(treap->left) < k) {
            split(treap->right, treap->right, right, k-size(treap->left)-1);
            left = treap;
        } else {
            split(treap->left, left, treap->left, k);
            right = treap;
        }
        treap->size = size(treap->left) + size(treap->right) + 1;
        treap->sum = sum(treap->left) + sum(treap->right) + treap->value;
    }
}

void merge(Node* &treap, Node* left, Node* right) {
    if (left == NULL) treap = right;
    else if (right == NULL) treap = left;
    else {
        propagete(left);
        propagete(right);
        if (left->weight < right->weight) {
            merge(left->right, left->right, right);
            treap = left;
        } else {
            merge(right->left, left, right->left);
            treap = right;
        }
        treap->size = size(treap->left) + size(treap->right) + 1;
        treap->sum = sum(treap->left) + sum(treap->right) + treap->value;
    }
}

Node* build() {
    Node* treap = new Node(v[0]);
    for (int i = 1; i < n; ++i) {
        merge(treap, treap, new Node(v[i]));
    }
    return treap;
}

void reverse(Node* &treap, int a, int b) {
    Node *left, *mid, *right;
    split(treap, left, mid, a-1);
    split(mid, mid, right, b-a+1);
    mid->rev ^= 1;
    merge(treap, left, mid);
    merge(treap, treap, right);
}

void print_treap(Node *node) {
    if (node == NULL) return;
    propagete(node);
    print_treap(node->left);
    cout << node->value << " ";
    print_treap(node->right);
}

ll calc_sum(Node* treap, int a, int b) {
    Node *left, *mid, *right;
    split(treap, left, mid, a-1);
    split(mid, mid, right, b-a+1);
    ll ans = mid->sum;
    merge(treap, left, mid);
    merge(treap, treap, right);
    return ans;
}

int main() {
    int t, a, b;

    cin >> n >> m;
    v.resize(n+1);
    for (int i = 0; i < n; ++i) {
        cin >> a;
        v[i] = a;
    }
    Node* treap = build();
    while (m--) {
        cin >> t >> a >> b;
        if (t == 1) {
            reverse(treap, a, b);
        } else {
            cout << calc_sum(treap, a, b) << "\n";
        }
    }

    return 0;
}
