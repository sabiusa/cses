//
//  trie.cpp
//  word-combinations
//
//  Created by Saba Khutsishvili on 29.06.21.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define ll long long
#define ull unsigned long long

const ll M = 26, MOD = 1e9+7;

struct Node {
    ll count = 0;
    bool end = false;
    Node* arr[M];
    
    Node() {
        for (ll i = 0; i < M; ++i) {
            arr[i] = NULL;
        }
    }
};

Node *root = new Node();
string s, p;
ll k, ss;

void insert(string &p) {
    Node *cur = root;
    for (char c : p) {
        ll k = c - 'a';
        if (cur->arr[k] == NULL) {
            cur->arr[k] = new Node();
        }
        cur = cur->arr[k];
        cur->count++;
    }
    cur->end = true;
}

ll calc() {
    vector<ll> mem(ss+1, 0);
    mem[0] = 1;
    for (ll i = 0; i < ss; ++i) {
        Node *cur = root;
        for (ll j = i, l = 1; j < ss; ++j, ++l) {
            ll k = s[j] - 'a';
            if (cur->arr[k] == NULL) break;
            cur = cur->arr[k];
            if (cur->end) {
                mem[i+l] = (mem[i+l] + mem[i]) % MOD;
            }
        }
    }
    return mem[ss];
}

int main() {
    
    cin >> s;
    cin >> k;
    ss = (ll)s.size();
    while (k--) {
        cin >> p;
        insert(p);
    }
    cout << calc() << "\n";
    
    return 0;
}
