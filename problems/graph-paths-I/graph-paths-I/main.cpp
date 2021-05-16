//
//  main.cpp
//  graph-paths-I
//
//  Created by Saba Khutsishvili on 5/15/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
const ll N = 102, MOD = 1e9+7;
vector<vector<ll>> adj(N);

void resize(ll n) {
    adj.resize(n);
    for (ll i = 0; i < n; ++i) {
        adj[i].resize(n);
    }
}

vector<vector<ll>> mult(vector<vector<ll>> a, vector<vector<ll>> b) {
    ll n = (ll)a.size();
    vector<vector<ll>> res(n, vector<ll> (n));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            for (ll k = 0; k < n; ++k) {
                ll m = (a[i][k] * b[k][j]) % MOD;
                res[i][j] = (res[i][j] + m) % MOD;
            }
        }
    }
    return res;
}

void expo(ll n, ll k) {
    vector<vector<ll>> res(n, vector<ll> (n)); // identity matrix
    for (ll i = 0; i < n; ++i) res[i][i] = 1;
    while (k) {
        if (k % 2) res = mult(res, adj);
        adj = mult(adj, adj);
        k /= 2;
    }
    adj = res;
}

ll calc(ll n, ll k) {
    expo(n, k);
    return adj[0][n-1];
}

int main() {
    ll n, m, k, a, b;
    
    cin >> n >> m >> k;
    resize(n);
    for (ll i = 1; i <= m; ++i) {
        cin >> a >> b;
        adj[a-1][b-1]++;
    }
    cout << calc(n, k) << "\n";
    
    return 0;
}
