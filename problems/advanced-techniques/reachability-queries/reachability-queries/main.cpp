//
//  main.cpp
//  reachability-queries
//
//  Created by Saba Khutsishvili on 15.07.21.
//

#include <iostream>
#include <vector>
#include <set>
#include <bitset>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
const int N = 5e4+1;
int n, m, q;
vector<vector<int>> adj, adjr;
vector<int> vis, out, comp, sz, link;
vector<set<int>> scc;
vector<bitset<N>> reach;
 
void resize() {
    adj.resize(n+1);
    adjr.resize(n+1);
    vis.resize(n+1);
    scc.resize(n+1);
    reach.resize(n+1);
    sz.resize(n+1, 1);
    link.resize(n+1);
    for (int i = 1; i <= n; ++i) link[i] = i;
}
 
void dfs_out(int i) {
    vis[i] = 1;
    for (int a : adj[i]) {
        if (!vis[a]) {
            dfs_out(a);
        }
    }
    out.push_back(i);
}
 
void dfs_scc(int i) {
    vis[i] = 1;
    comp.push_back(i);
    for (int a : adjr[i]) {
        if (!vis[a]) {
            dfs_scc(a);
        }
    }
}
 
void dfs_reach(int i) {
    vis[i] = 1;
    for (int a : scc[i]) {
        if (!vis[a]) {
            dfs_reach(a);
        }
        reach[i] |= reach[a];
    }
}
 
int find(int i) {
    if (i == link[i]) return i;
    link[i] = find(link[i]);
    return link[i];
}
 
void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (a < b) swap(a, b);
    sz[a] += sz[b];
    link[b] = a;
}
 
int main() {
    int a, b;
    
    cin >> n >> m >> q;
    resize();
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adjr[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs_out(i);
        }
    }
    fill(vis.begin(), vis.end(), 0);
    for (int i = n-1, cur = out[i]; i >= 0; --i, cur = out[i]) {
        if (!vis[cur]) {
            dfs_scc(cur);
            for (int j = 1; j < (int)comp.size(); ++j) {
                unite(comp[j-1], comp[j]);
            }
            comp.clear();
        }
    }
    for (int i = 1; i <= n; ++i) {
        ll cur = find(i);
        reach[cur].set(i);
        for (int a : adj[i]) {
            int la = find(a);
            scc[cur].insert(la);
        }
    }
    fill(vis.begin(), vis.end(), 0);
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs_reach(i);
        }
    }
    while (q--) {
        cin >> a >> b;
        int la = find(a);
        int lb = find(b);
        if (reach[la][lb]) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    
    return 0;
}
