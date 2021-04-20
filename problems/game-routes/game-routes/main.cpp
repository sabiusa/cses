//
//  main.cpp
//  game-routes
//
//  Created by Saba Khutsishvili on 4/20/21.
//

#include <iostream>
#include <vector>

using namespace std;
 
#define ll long long
#define ull unsigned long long

//const ll N = 1e5+2, INF = 1e18, MOD = 1e9+7;
//vector<vector<ll>> adj(N);
//vector<ll> vis(N, 0), mem(N, 0);
//
//void dfs(ll cur, ll n) {
//    vis[cur] = 1;
//    if (cur == n) {
//        mem[n] = 1;
//        return;
//    }
//    for (ll a : adj[cur]) {
//        if (vis[a] == 0) {
//            dfs(a, n);
//        }
//        mem[cur] += mem[a];
//        mem[cur] %= MOD;
//    }
//}
//
//int main() {
//    ll n, m, a, b;
//    
//    cin >> n >> m;
//    for (ll i = 0; i < m; ++i) {
//        cin >> a >> b;
//        adj[a].push_back(b);
//    }
//    dfs(1, n);
//    cout << mem[1] << "\n";
//    
//    return 0;
//}
