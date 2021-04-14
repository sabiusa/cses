//
//  main.cpp
//  shortest-routes-II
//
//  Created by Saba Khutsishvili on 4/14/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long

const ll N = 502, INF = 1e18;
vector<vector<ll>> dist(N, vector<ll> (N, INF));
vector<ll> vis(N, 0);

int main() {
    ll n, m, q, a, b, w;
    
    cin >> n >> m >> q;
    for (ll i = 0; i < m; ++i) {
        cin >> a >> b >> w;
        dist[a][b] = min(dist[a][b], w);
        dist[b][a] = dist[a][b];
    }
    
    for (ll i = 1; i <= n; ++i) {
        dist[i][i] = 0;
    }
    for (ll k = 1; k <= n; ++k) {
        for (ll i = 1; i <= n; ++i) {
            for (ll j = 1; j <= n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    while (q--) {
        cin >> a >> b;
        ll ans = dist[a][b] == INF ? -1 : dist[a][b];
        cout << ans << "\n";
    }
    
    return 0;
}

