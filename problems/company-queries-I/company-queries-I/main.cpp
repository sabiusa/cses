//
//  main.cpp
//  company-queries-I
//
//  Created by Saba Khutsishvili on 4/30/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
const ll N = 2e5+2, LOG = 20;
ll n;
vector<vector<ll>> adj(N), anc(LOG, vector<ll> (N, 0));
vector<ll> dep(N);

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

ll query(ll x, ll k) {
    if (k > dep[x]) return -1;
    for (ll j = 0; j < LOG; ++j) {
        if (k & (1 << j)) {
            if (x == 0) return -1;
            x = anc[j][x];
        }
    }
    return x;
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
