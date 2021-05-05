//
//  main.cpp
//  fixed-length-paths-I
//
//  Created by Saba Khutsishvili on 5/5/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
const ll N = 2e5+2;
ll n, k, ans = 0, md = 1;
vector<vector<ll>> adj(N);
vector<ll> sz(N), dep(N), rem(N);

void dfs_size(ll i, ll p) {
    sz[i] = 1;
    for (ll a : adj[i]) {
        if (a == p || rem[a]) continue;
        dfs_size(a, i);
        sz[i] += sz[a];
    }
}

ll centroid(ll i, ll p, ll s) {
    for (ll a : adj[i]) {
        if (a == p || rem[a]) continue;
        if (sz[a] > s/2) {
            return centroid(a, i, s);
        }
    }
    return i;
}

void dfs_path(ll i, ll p, ll d) {
    if (d > k) return;
    ll len = k - d; // length needed to create k-length path from i
    ans += dep[len];
    for (ll a : adj[i]) {
        if (a == p || rem[a]) continue;
        dfs_path(a, i, d+1);
    }
}

void dfs_dep(ll i, ll p, ll d) {
    if (d > k) return;
    dep[d]++; // accumulate d-length paths
    md = max(md, d);
    for (ll a : adj[i]) {
        if (a == p || rem[a]) continue;
        dfs_dep(a, i, d+1);
    }
}

void decomp(ll i, ll p) {
    dfs_size(i, p);
    ll s = sz[i]; // subtree size
    ll c = centroid(i, p, s);
    rem[c] = 1; // remove centroid
    md = 0;
    for (ll a : adj[c]) {
        if (rem[a]) continue;
        dfs_path(a, c, 1);
        dfs_dep(a, c, 1);
    }
    ans += dep[k];
    fill(dep.begin(), dep.begin()+md+1, 0);
    for (ll a : adj[c]) {
        if (rem[a]) continue;
        decomp(a, p);
    }
}

int main() {
    ll a, b;
    
    cin >> n >> k;
    for (ll i = 1; i < n; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    decomp(1, 0);
    cout << ans << "\n";
    
    return 0;
}
