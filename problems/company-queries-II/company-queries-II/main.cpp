//
//  main.cpp
//  company-queries-II
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
vector<vector<ll>> adj(N), anc(LOG, vector<ll> (N, 0));
vector<ll> dep(N, 0);

void dfs(ll i, ll p, ll d) {
    dep[i] = d;
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

ll query(ll a, ll b) {
    if (dep[a] < dep[b])
        swap(a, b);
    ll k = dep[a] - dep[b];
    for (ll i = LOG-1; i >= 0; --i) { // get a & b on same level
        if (k & (1 << i)) {
            a = anc[i][a];
        }
    }
    if (a == b) {
        return a;
    }
    for (ll i = LOG-1; i >= 0; --i) {
        if (anc[i][a] != anc[i][b]) { // get to nodes just below LCA
            a = anc[i][a];
            b = anc[i][b];
        }
    }
    return anc[0][a];
}

int main() {
    ll q, a, b;
    
    cin >> n >> q;
    for (ll i = 2; i <= n; ++i) {
        cin >> a;
        adj[a].push_back(i);
        anc[0][i] = a;
    }
    dfs(1, 0, 0);
    fill();
    while (q--) {
        cin >> a >> b;
        cout << query(a, b) << "\n";
    }
    
    return 0;
}
