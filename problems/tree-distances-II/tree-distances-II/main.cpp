//
//  main.cpp
//  tree-distances-II
//
//  Created by Saba Khutsishvili on 4/30/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
const ll N = 2e5+2;
vector<vector<ll>> adj;
vector<ll> dep(N), dist(N);

void dfs1(ll i, ll p, ll d) {
    dist[1] += d;
    dep[i] = 1;
    for (ll a : adj[i]) {
        if (a == p) continue;
        dfs1(a, i, d+1);
        dep[i] += dep[a];
    }
}

void dfs2(ll i, ll p, ll n) {
    for (ll a : adj[i]) {
        if (a == p) continue;
        dist[a] = dist[i] + n - (2 * dep[a]);
        dfs2(a, i, n);
    }
}

int main() {
    ll n, a, b;
    
    cin >> n;
    adj.resize(n+1);
    dep.resize(n+1);
    dist.resize(n+1);
    for (ll i = 1; i < n; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(1, 0, 0);
    dfs2(1, 0, n);
    for (ll i = 1; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << "\n";
    
    return 0;
}
