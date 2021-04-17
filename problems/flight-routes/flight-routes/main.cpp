//
//  main.cpp
//  flight-routes
//
//  Created by Saba Khutsishvili on 4/17/21.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
 
#define ll long long
#define ull unsigned long long

const ll N = 1e5+2, INF = 1e18, K = 10;
vector<vector<pair<ll, ll>>> adj(N);
priority_queue<
    pair<ll, ll>,
    vector<pair<ll, ll>>,
    greater<pair<ll, ll>>
> q;
vector<vector<ll>> dest(N, vector<ll> (K, INF));

int main() {
    ll n, m, k, a, b, w;
    
    cin >> n >> m >> k;
    for (ll i = 0; i < m; ++i) {
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }
    q.push({0, 1});
    while (q.size()) {
        auto e = q.top();
        q.pop();
        ll c = e.first;
        ll d = e.second;
        
        if (dest[d][k-1] < c) continue; // we already have better deal
        
        for (auto a : adj[d]) {
            b = a.first; w = a.second;
            ll deal = w + c;
            if (dest[b][k-1] > deal) { // better deal
                dest[b][k-1] = deal;
                sort(dest[b].begin(), dest[b].end());
                q.push({deal, b});
            }
        }
    }
    for (ll i = 0; i < k; ++i) {
        cout << dest[n][i] << " ";
    }
    cout << "\n";
    
    return 0;
}
