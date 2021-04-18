//
//  main.cpp
//  course-schedule
//
//  Created by Saba Khutsishvili on 4/18/21.
//

#include <iostream>
#include <vector>

using namespace std;
 
#define ll long long
#define ull unsigned long long

const ll N = 1e5+2, INF = 1e18;
vector<vector<ll>> adj(N);
vector<ll> vis(N, 0), ans;

void dfs(ll n) {
    vis[n] = 1;
    for (ll a : adj[n]) {
        if (vis[a] == 1) {
            cout << "IMPOSSIBLE" << "\n";
            exit(0);
        }
        if (vis[a] == 0) {
            dfs(a);
        }
    }
    vis[n] = 2;
    ans.push_back(n);
}

int main() {
    ll n, m, a, b;
    
    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for (ll i = 1; i <= n; ++i) {
        if (vis[i] == 0) {
            dfs(i);
        }
    }
    for (ll i = (ll)ans.size()-1; i >= 0; --i) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    
    return 0;
}
