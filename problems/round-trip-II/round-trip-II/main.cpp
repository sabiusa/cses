//
//  main.cpp
//  round-trip-II
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
vector<ll> vis(N, 0), path(N, 0);

void dfs(ll n, ll p) {
    vis[n] = 1;
    path[n] = p;
    for (ll a : adj[n]) {
        if (vis[a] == 1) {
            path[a] = n;
            vector<ll> v;
            v.push_back(n);
            for (ll x = path[n]; ; x = path[x]) {
                v.push_back(x);
                if (x == a) {
                    v.push_back(n);
                    break;
                }
            }
            cout << v.size() << "\n";
            for (ll i = (ll)v.size() - 1; i >= 0; --i) {
                cout << v[i] << " ";
            }
            cout << "\n";
            exit(0);
        }
        if (vis[a] == 0) {
            dfs(a, n);
        }
    }
    vis[n] = 2;
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
            dfs(i, i);
        }
    }
    cout << "IMPOSSIBLE" << "\n";
    
    return 0;
}
