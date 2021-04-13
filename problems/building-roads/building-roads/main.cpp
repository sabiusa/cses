//
//  main.cpp
//  building-roads
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

void dfs(ll i) {
    vis[i] = 1;
    for (ll c : adj[i]) {
        if (vis[c] == 0) {
            dfs(c);
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
    
    vector<ll> ans;
    for (ll i = 1; i <= n; ++i) {
        if (vis[i] == 0) {
            dfs(i);
            if (i > 1) {
                ans.push_back(i);
            }
        }
    }
    
    cout << ans.size() << "\n";
    for (ull i = 0; i < ans.size(); ++i) {
        cout << 1 << " " << ans[i] << "\n";
    }
    cout << "\n";
    
    return 0;
}
