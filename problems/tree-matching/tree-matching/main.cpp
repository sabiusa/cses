//
//  main.cpp
//  tree-matching
//
//  Created by Saba Khutsishvili on 4/29/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long

const ll N = 2e5+2;
ll ans = 0;
vector<vector<ll>> adj;
vector<ll> vis(N, 0);

void dfs(ll i, ll p) {
    for (ll a : adj[i]) {
        if (a == p) continue;
        dfs(a, i);
        if (vis[i] == 0 && vis[a] == 0) {
            vis[i] = vis[a] = 1;
            ans++;
        }
    }
}

int main() {
    ll n, a, b;
    
    cin >> n;
    adj.resize(n+1);
    for (ll i = 1; i < n; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    cout << ans << "\n";
    
    return 0;
}
