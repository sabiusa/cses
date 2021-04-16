//
//  main.cpp
//  flight-discount
//
//  Created by Saba Khutsishvili on 4/16/21.
//

#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
const ll N = 1e5+2, INF = 1e18;
vector<vector<pair<ll, ll>>> adj(N);
priority_queue<
    pair<ll, pair<ll, ll>>,
    vector<pair<ll, pair<ll, ll>>>,
    greater<pair<ll, pair<ll, ll>>>
> q;
vector<ll> full(N, INF), disc(N, INF);
vector<ll> vis_full(N, 0), vis_disc(N, 0);
 
int main() {
    ll n, m, a, b, w;
    
    cin >> n >> m;
    while (m--) {
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }
    full[1] = 0;
    disc[1] = 0;
    q.push({0, {1, 0}});
    while (!q.empty()) {
        auto p = q.top();
        q.pop();
        ll cost = p.first;
        ll dest = p.second.first;
        ll coupon = p.second.second;
        
        if (coupon == 0) {
            if (vis_full[dest]) continue;
            else vis_full[dest] = 1;
        }
        if (coupon == 1) {
            if (vis_disc[dest]) continue;
            else vis_disc[dest] = 1;
        }
        
        for (auto a : adj[dest]) {
            b = a.first; w = a.second;
            
            if (coupon == 0) {
                if (full[b] > cost + w) {
                    full[b] = cost + w;
                    q.push({full[b], {b, 0}});
                }
                if (disc[b] > cost + w/2) {
                    disc[b] = cost + w/2;
                    q.push({disc[b], {b, 1}});
                }
            }
            if (coupon == 1) {
                if (disc[b] > cost + w) {
                    disc[b] = cost + w;
                    q.push({disc[b], {b, 1}});
                }
            }
        }
    }
    cout << disc[n] << "\n";
    
    return 0;
}
