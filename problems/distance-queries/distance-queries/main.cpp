//
//  main.cpp
//  distance-queries
//
//  Created by Saba Khutsishvili on 5/1/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
const ll N = 2e5+2, LOG = 20;
ll n;
vector<vector<ll>> trav(N), orig(N), adj(N), anc(LOG, vector<ll> (N, 0));
vector<ll> dep(N, 0);

void dfs(ll i, ll p, ll d) {
    dep[i] = d;
    anc[0][i] = p;
    for (ll a : adj[i]) {
        if (a == p) continue;
        dfs(a, i, d+1);
    }
}

void fill() {
    for (ll i = 1; i < LOG; ++i) {
        for (ll j = 1; j <= n; ++j) {
            anc[i][j] = anc[i-1][anc[i-1][j]];
        }
    }
}

ll lca(ll a, ll b) {
    if (dep[a] < dep[b]) {
        swap(a, b);
    }
    ll k = dep[a] - dep[b];
    for (ll i = LOG-1; i >= 0; --i) {
        if (k & (1 << i)) {
            a = anc[i][a];
        }
    }
    if (a == b) {
        return a;
    }
    for (ll i = LOG-1; i >= 0; --i) {
        if (anc[i][a] != anc[i][b]) {
            a = anc[i][a];
            b = anc[i][b];
        }
    }
    return anc[0][a];
}

ll query(ll a, ll b) {
    ll d = dep[lca(a, b)]; // depth of LCA
    return dep[a] + dep[b] - 2*d;
}

int main() {
    ll q, a, b;
    
    cin >> n >> q;
    for (ll i = 1; i < n; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0, 0);
    fill();
    while (q--) {
        cin >> a >> b;
        cout << query(a, b) << "\n";
    }
    
    return 0;
}
