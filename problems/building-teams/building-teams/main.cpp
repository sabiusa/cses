//
//  main.cpp
//  building-teams
//
//  Created by Saba Khutsishvili on 4/13/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
const ll N = 1e5+1;
vector<vector<ll>> adj(N);
vector<ll> vis(N, 0);

void dfs(ll i, ll col) {
    vis[i] = col;
    for (ll cur : adj[i]) {
        if (vis[cur] == 0) {
            dfs(cur, 3-col);
        } else if (vis[cur] == col) {
            cout << "IMPOSSIBLE" << "\n";
            exit(0);
        }
    }
}

int main() {
    ll n, m, a, b;
    
    cin >> n >> m;
    while (m--) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (ll i = 1; i <= n; ++i) {
        if (vis[i] == 0) {
            dfs(i, 1);
        }
    }
    for (ll i = 1; i <= n; ++i) {
        cout << vis[i] << " ";
    }
    cout << "\n";
    
    return 0;
}
