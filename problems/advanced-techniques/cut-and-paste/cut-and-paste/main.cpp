//
//  main.cpp
//  cut-and-paste
//
//  Created by Saba Khutsishvili on 20.07.21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long

int n, m;
string s;

struct Node {
    Node *left, *right;
    int weight, size, value;
    
    Node(int v) {
       left = right = NULL;
       weight = rand();
       size = 1;
       value = v;
    }
};

int size(Node* treap) {
    if (treap == NULL) return 0;
    return treap->size;
}

void split(Node* treap, Node* &left, Node* &right, int k) {
    if (treap == NULL) {
        left = right = NULL;
    } else {
        if (size(treap->left) < k) {
            split(treap->right, treap->right, right, k-size(treap->left)-1);
            left = treap;
        } else {
            split(treap->left, left, treap->left, k);
            right = treap;
        }
        treap->size = size(treap->left) + size(treap->right) + 1;
    }
}

void merge(Node* &treap, Node* left, Node* right) {
    if (left == NULL) treap = right;
    else if (right == NULL) treap = left;
    else {
        if (left->weight < right->weight) {
            merge(left->right, left->right, right);
            treap = left;
        } else {
            merge(right->left, left, right->left);
            treap = right;
        }
        treap->size = size(treap->left) + size(treap->right) + 1;
    }
}

Node* build() {
    Node* treap = new Node(1);
    for (int i = 2; i <= n; ++i) {
        merge(treap, treap, new Node(i));
    }
    return treap;
}

void print_treap(Node *node) {
    if (node == NULL) return;
    print_treap(node->left);
    cout << s[node->value-1];
    print_treap(node->right);
}

int main() {
    Node* treap;
    
    cin >> n >> m;
    cin >> s;
    treap = build();
    
    while (m--) {
        int a, b;
        cin >> a >> b;
        if (b == n) continue;
        Node *left, *mid, *right;
        split(treap, left, mid, a-1);
        split(mid, mid, right, b-a+1);
        merge(left, left, right);
        merge(left, left, mid);
        treap = left;
    }
    print_treap(treap);
    cout << "\n";
    
    return 0;
}
