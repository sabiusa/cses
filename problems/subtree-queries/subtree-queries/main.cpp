//
//  main.cpp
//  subtree-queries
//
//  Created by Saba Khutsishvili on 5/3/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long

struct node {
    ll i, val;
};
 
const ll N = 2e5+2;
ll n, c = 0;
vector<vector<ll>> adj(N);
vector<node> orig(N);
vector<ll> trav(N), id(N), sz(N), seg(N);

void dfs(ll i, ll p) {
    trav[++c] = i; // construct traversal array
    seg[c+n-1] = orig[i].val; // corresponding values in segment tree
    id[orig[i].i] = c; // map original index to traversal array
    sz[i] = 1;
    for (ll a : adj[i]) {
        if (a == p) continue;
        dfs(a, i);
        sz[i] += sz[a]; // sizes of subtrees
    }
}

void gen_seg_tree() {
    for (ll i = n-1; i > 0; --i) {
        seg[i] = seg[i*2] + seg[i*2+1];
    }
}

void update(ll a, ll b) {
    a = id[a]; // map original index to traversal
    a = a + n - 1;
    seg[a] = b;
    for (a >>= 1; a > 0; a >>= 1) {
        seg[a] = seg[a*2] + seg[a*2+1];
    }
}

ll query(ll a) {
    ll s = sz[a]; // size of subtree
    a = id[a]; // map original index to traversal
    ll l = a + n - 1;
    ll r = l + s;
    ll sum = 0;
    for (; l < r; l >>= 1, r >>= 1) {
        if (l & 1) sum += seg[l++];
        if (r & 1) sum += seg[--r];
    }
    return sum;
}

int main() {
    ll q, k, a, b;
    
    cin >> n >> q;
    seg.resize(2*n);
    for (ll i = 1; i <= n; ++i) {
        cin >> a;
        orig[i] = {i, a};
    }
    for (ll i = 1; i < n; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    gen_seg_tree();
    for (ll i = 0; i < q; ++i) {
        cin >> k;
        if (k == 1) {
            cin >> a >> b;
            update(a, b);
        } else {
            cin >> a;
            cout << query(a) << "\n";
        }
    }
    
    return 0;
}
