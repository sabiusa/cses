//
//  topsort.cpp
//  game-routes
//
//  Created by Saba Khutsishvili on 4/20/21.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
 
#define ll long long
#define ull unsigned long long

const ll N = 1e5+2, INF = 1e18, MOD = 1e9+7;
vector<vector<ll>> adj(N);
vector<ll> vis(N, 0), mem(N, 0), ts;

void top_sort(ll cur) {
    vis[cur] = 1;
    for (ll a : adj[cur]) {
        if (vis[a] == 0) {
            top_sort(a);
        }
    }
    ts.push_back(cur);
}

void count_paths(ll n) {
    reverse(ts.begin(), ts.end());
    mem[1] = 1;
    for (ll cur : ts) {
        for (ll a : adj[cur]) {
            mem[a] += mem[cur];
            mem[a] %= MOD;
        }
    }
}

int main() {
    ll n, m, a, b;
    
    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
    }
    top_sort(1);
    count_paths(n);
    cout << mem[n] << "\n";
    
    return 0;
}
