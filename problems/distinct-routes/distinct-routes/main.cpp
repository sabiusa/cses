//
//  main.cpp
//  distinct-routes
//
//  Created by Saba Khutsishvili on 6/6/21.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define ll long long
#define ull unsigned long long

const ll INF = 1e9;
ll n, m, t;
vector<vector<ll>> adj, cap;

void resize() {
    t = (2 * n) + 1;
    adj.resize(t+1);
    cap.resize(t+1);
    for (ll i = 0; i <= t; ++i) {
        cap[i].resize(t+1);
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

void routes() {
    
    cout << "\n";
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
    routes();
    
    return 0;
}
