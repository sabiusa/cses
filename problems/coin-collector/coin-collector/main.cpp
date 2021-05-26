//
//  main.cpp
//  coin-collector
//
//  Created by Saba Khutsishvili on 5/26/21.
//

#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

const ll N = 1e5+2;
ll n;
vector<ll> k(N), out, comp(N), sums(N), mem(N);
vector<vector<ll>> adj(N), adjr(N), adjc(N);
vector<bool> vis(N);

void dfs_out(ll i) {
    vis[i] = 1;
    for (ll a : adj[i]) {
        if (!vis[a]) {
            dfs_out(a);
        }
    }
    out.push_back(i);
}

void dfs_comp(ll i, ll c) {
    comp[i] = c;
    sums[c] += k[i];
    for (ll a : adjr[i]) {
        if (!comp[a]) {
            dfs_comp(a, c);
        }
    }
}

void dfs_res(ll i) {
    vis[i] = 1;
    for (ll a : adjc[i]) {
        if (!vis[a]) {
            dfs_res(a);
        }
        mem[i] = max(mem[i], mem[a]);
    }
    mem[i] += sums[i];
}

int main() {
    ll m, a, b, c = 1, mx = 0;
    
    cin >> n >> m;
    for (ll i = 1; i <= n; ++i) {
        cin >> k[i];
    }
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
    for (ll i = (ll)out.size()-1; i >= 0; --i) {
        ll l = out[i];
        if (!comp[l]) {
            dfs_comp(l, c);
            c++;
        }
    }
    for (ll i = 1; i <= n; ++i) {
        for (ll a : adj[i]) {
            if (comp[i] != comp[a]) {
                adjc[comp[i]].push_back(comp[a]);
            }
        }
    }
    vis.assign(N, 0);
    for (ll i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs_res(i);
            mx = max(mx, mem[i]);
        }
    }
    cout << mx << "\n";
    
    return 0;
}
