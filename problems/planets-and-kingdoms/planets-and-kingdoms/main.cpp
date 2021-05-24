//
//  main.cpp
//  planets-and-kingdoms
//
//  Created by Saba Khutsishvili on 5/24/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long

const ll N = 1e5+2;
ll n;
vector<vector<ll>> adj(N), adjr(N);
vector<bool> vis(N);
vector<ll> out, kg(N);

void dfs_out(ll i) {
    vis[i] = 1;
    for (ll a : adj[i]) {
        if (!vis[a]) {
            dfs_out(a);
        }
    }
    out.push_back(i);
}

void dfs_scc(ll i, ll k) {
    kg[i] = k;
    for (ll a : adjr[i]) {
        if (!kg[a]) {
            dfs_scc(a, k);
        }
    }
}

int main() {
    ll m, a, b, k = 1;
    
    cin >> n >> m;
    while (m--) {
        cin >> a >> b;
        adj[a].push_back(b);
        adjr[b].push_back(a);
    }
    for (ll i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs_out(i);
        }
    }
    for (ll i = n-1; i >= 0; --i) {
        if (!kg[out[i]]) {
            dfs_scc(out[i], k);
            k++;
        }
    }
    cout << k-1 << "\n";
    for (ll i = 1; i <= n; ++i) {
        cout << kg[i] << " ";
    }
    cout << "\n";
    
    return 0;
}
