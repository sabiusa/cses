//
//  main.cpp
//  distinct-routes
//
//  Created by Saba Khutsishvili on 6/6/21.
//
 
#include <iostream>
#include <vector>
#include <queue>
#include <set>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
const ll INF = 1e9;
ll n, m, t;
vector<vector<ll>> adj, cap, res, vis;
vector<vector<ll>> paths;
 
void resize() {
    t = (2 * n) + 1;
    adj.resize(t+1);
    cap.resize(t+1);
    paths.resize(n+1);
    vis.resize(n+1);
    for (ll i = 0; i <= t; ++i) {
        cap[i].resize(t+1);
        if (i <= n) vis[i].resize(n+1);
    }
}
 
ll bfs(ll s, ll t, vector<ll> &par) {
    fill(par.begin(), par.end(), -1);
    par[0] = -2;
    queue<pair<ll, ll>> q;
    q.push({s, INF});
    while (q.size()) {
        auto f = q.front();
        ll cur = f.first;
        ll flow = f.second;
        q.pop();
        for (ll a : adj[cur]) {
            if (cap[cur][a] && par[a] == -1) {
                par[a] = cur;
                ll mn = min(flow, cap[cur][a]);
                if (a == t) return mn;
                q.push({a, mn});
            }
        }
    }
    return 0;
}
 
void maxflow(ll s, ll t) {
    vector<ll> par(t+1);
    ll ans = 0, flow;
    while ((flow = bfs(s, t, par))) {
        ans += flow;
        ll cur = t;
        while (cur != s) {
            ll prev = par[cur];
            cap[cur][prev] += flow;
            cap[prev][cur] -= flow;
            cur = prev;
        }
    }
}
 
void calc_routes() {
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j < t; ++j) {
            if (cap[i][j] == 0) continue;
            if (j <= n) {
                paths[i].push_back(j);
            } else {
                paths[i].push_back(j-n);
            }
        }
    }
    for (ll i = n+1; i < t; ++i) {
        for (ll j = 1; j < t; ++j) {
            if (cap[i][j] == 0) continue;
            if (j <= n) {
                paths[j].push_back(i-n);
            } else {
                paths[j-n].push_back(i-n);
            }
        }
    }
}
 
bool dfs_path(ll i, ll p, vector<ll> &tmp) {
    vis[p][i] = 1;
    tmp.push_back(i);
    if (i == n) {
        return true;
    }
    for (ll a : paths[i]) {
        if (!vis[i][a]) {
            bool ans = dfs_path(a, i, tmp);
            if (ans) return true;
        }
    }
//    vis[p][i] = 0;
    tmp.pop_back();
    return false;
}
 
void dfs_routes() {
    for (ll a : paths[1]) {
        vector<ll> tmp = {1};
        bool ans = dfs_path(a, 1, tmp);
        if (ans) {
            res.push_back(tmp);
        }
    }
}
 
void print_routes() {
    ll sz = (ll)res.size();
    cout << sz << "\n";
    for (ll i = 0; i < sz; ++i) {
        ll szi = (ll)res[i].size();
        cout << szi << "\n";
        for (ll j = 0; j < szi; ++j) {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
}
 
int main() {
    ll a, b;
    
    cin >> n >> m;
    resize();
    for (ll i = 0; i < m; ++i) {
        cin >> a >> b;
        b += n;
        
        adj[0].push_back(a);
        adj[a].push_back(0);
        
        adj[a].push_back(b);
        adj[b].push_back(a);
        
        adj[b].push_back(t);
        adj[t].push_back(b);
        
        cap[0][a] = 1;
        cap[a][b] = 1;
        cap[b][t] = 1;
    }
    maxflow(0, t);
    calc_routes();
    dfs_routes();
    print_routes();
    
    return 0;
}
