//
//  main.cpp
//  high-score
//
//  Created by Saba Khutsishvili on 4/14/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long

const ll N = 2502, M = 5000, INF = 1e16;
vector<vector<ll>> edg(M, vector<ll> (3));
vector<ll> dist(N, INF);
vector<vector<ll>> adj(N), adjr(N);
vector<ll> vis(N, 0), visr(N, 0);

void dfs(ll n) {
    vis[n] = 1;
    for (ll a : adj[n]) {
        if (vis[a] == 0) {
            dfs(a);
        }
    }
}

void dfsr(ll n) {
    visr[n] = 1;
    for (ll a : adjr[n]) {
        if (visr[a] == 0) {
            dfsr(a);
        }
    }
}

int main() {
    ll n, m, a, b, w;
    
    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        cin >> a >> b >> w;
        edg[i] = {a, b, -w};
        adj[a].push_back(b);
        adjr[b].push_back(a);
    }
    dfs(1);
    dfsr(n);
    dist[1] = 0;
    for (ll i = 1; i < n; ++i) {
        for (auto e : edg) {
            a = e[0]; b = e[1]; w = e[2];
            if (dist[a] + w < dist[b]) {
                dist[b] = dist[a] + w;
            }
        }
    }
    for (auto e : edg) {
        a = e[0]; b = e[1]; w = e[2];
        if (dist[a] + w < dist[b]) {
            if (vis[b] && visr[b]) {
                cout << -1 << "\n";
                return 0;
            }
        }
    }
    cout << -dist[n] << "\n";
    
    return 0;
}
