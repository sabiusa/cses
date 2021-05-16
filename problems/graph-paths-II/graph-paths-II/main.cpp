//
//  main.cpp
//  graph-paths-II
//
//  Created by Saba Khutsishvili on 5/16/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
const ll N = 102, MOD = 1e9+7, INF = 2e18;
vector<vector<ll>> adj(N, vector<ll> (N, INF));

void resize(ll n) {
    adj.resize(n);
    for (ll i = 0; i < n; ++i) {
        adj[i].resize(n);
    }
}

vector<vector<ll>> min_mult(vector<vector<ll>> a, vector<vector<ll>> b) {
    ll n = (ll)a.size();
    vector<vector<ll>> res(n, vector<ll> (n, INF));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            for (ll k = 0; k < n; ++k) {
                ll w = a[i][k] + b[k][j];
                res[i][j] = min(res[i][j], w);
            }
        }
    }
    return res;
}

void expo(ll k) {
    auto res = adj;
    while (k) {
        if (k % 2) res = min_mult(res, adj);
        adj = min_mult(adj, adj);
        k /= 2;
    }
    adj = res;
}

ll calc(ll n, ll k) {
    expo(k-1);
    ll cost = adj[0][n-1];
    return cost == INF ? -1 : cost;
}

int main() {
    ll n, m, k, a, b, w;
    
    cin >> n >> m >> k;
    resize(n);
    for (ll i = 0; i < m; ++i) {
        cin >> a >> b >> w;
        adj[a-1][b-1] = min(adj[a-1][b-1], w);
    }
    cout << calc(n, k) << "\n";
    
    return 0;
}
