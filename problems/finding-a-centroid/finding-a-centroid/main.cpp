//
//  main.cpp
//  finding-a-centroid
//
//  Created by Saba Khutsishvili on 5/4/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long

const ll N = 2e5+2;
ll n;
vector<vector<ll>> adj(N);
vector<ll> sz(N);

void dfs(ll i, ll p) {
    sz[i] = 1;
    for (ll a : adj[i]) {
        if (a == p) continue;
        dfs(a, i);
        sz[i] += sz[a];
    }
}

ll centroid(ll i, ll p) {
    for (ll a : adj[i]) {
        if (a == p) continue;
        if (sz[a] > n/2) {
            return centroid(a, i);
        }
    }
    return i;
}

int main() {
    ll a, b;
    
    cin >> n;
    for (ll i = 1; i < n; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    cout << centroid(1, 0) << "\n";
    
    return 0;
}
