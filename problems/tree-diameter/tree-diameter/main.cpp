//
//  main.cpp
//  tree-diameter
//
//  Created by Saba Khutsishvili on 4/29/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long

const ll N = 2e5+2;
vector<vector<ll>> adj;
vector<ll> dist(N);
ll max_dist = 0, max_pos = 1;

void dfs1(ll i, ll p, ll c) {
    dist[i] = c;
    for (ll a : adj[i]) {
        if (a == p) continue;
        dfs1(a, i, c+1);
        if (max_dist < dist[a]) {
            max_dist = dist[a];
            max_pos = a;
        }
    }
}

void dfs2(ll i, ll p, ll c) {
    dist[i] = c;
    for (ll a : adj[i]) {
        if (a == p) continue;
        dfs2(a, i, c+1);
        max_dist = max(max_dist, dist[a]);
    }
}

int main() {
    ll n, a, b;
    
    cin >> n;
    adj.resize(n+1);
    dist.resize(n+1);
    for (ll i = 1; i < n; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(1, 0, 0);
    fill(dist.begin(), dist.end(), 0);
    dfs2(max_pos, 0, 0);
    cout << max_dist << "\n";
    
    return 0;
}
