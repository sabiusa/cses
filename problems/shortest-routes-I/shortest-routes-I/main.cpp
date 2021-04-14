//
//  main.cpp
//  shortest-routes-I
//
//  Created by Saba Khutsishvili on 4/14/21.
//

#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long

const ll N = 1e5+2, INF = 1e18;
vector<vector<pair<ll, ll>>> adj(N);
vector<ll> dist(N, INF);
vector<ll> vis(N, 0);
priority_queue<pair<ll, ll>> q;

int main() {
    ll n, m, a, b, w;
    
    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }
    dist[1] = 0;
    q.push({0, 1});
    while (!q.empty()) {
        ll cur = q.top().second;
        q.pop();
        if (vis[cur]) continue;
        vis[cur] = 1;
        for (auto c : adj[cur]) {
            ll cb = c.first, cw = c.second;
            if (dist[cur] + cw < dist[cb]) {
                dist[cb] = dist[cur] + cw;
                q.push({-dist[cb], cb});
            }
        }
    }
    for (ll i = 1; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << "\n";
    
    return 0;
}
