//
//  main.cpp
//  path-queries
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
vector<ll> trav(N), sz(N), path(N), id(N), seg;

void dfs(ll i, ll p, ll d) {
    trav[++c] = i; // traversal array
    ll sum = d + orig[i].val; // path sum up to this node, parent + itself
    path[c] = sum;
    sz[i] = 1; // subtree size
    id[orig[i].i] = c; // map original index to traversal index
    for (ll a : adj[i]) {
        if (a == p) continue;
        dfs(a, i, sum);
        sz[i] += sz[a];
    }
}

void gen_seg_tree() {
    for (ll i = 0; i < n; ++i) {
        seg[i] = 0;
    }
    for (ll i = 1; i <= n; ++i) {
        seg[i+n-1] = path[i];
    }
}

void update(ll a, ll b) {
    ll s = sz[a];
    ll d = b - orig[a].val;
    orig[a].val = b;
    a = id[a];
    ll l = a + n - 1;
    ll r = l + s;
    for (; l < r; l >>= 1, r >>= 1) {
        if (l & 1) seg[l++] += d;
        if (r & 1) seg[--r] += d;
    }
}

ll query(ll a) {
    a = id[a];
    a = a + n - 1;
    ll sum = seg[a];
    for (a >>= 1; a > 0; a >>= 1) {
        sum += seg[a];
    }
    return sum;
}

int main() {
    ll q, k, a, b;
    
    cin >> n >> q;
    for (ll i = 1; i <= n; ++i) {
        cin >> a;
        orig[i] = {i, a};
    }
    for (ll i = 1; i < n; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0, 0);
    seg.resize(n*2);
    gen_seg_tree();
    while (q--) {
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
