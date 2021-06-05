//
//  main.cpp
//  police-chase
//
//  Created by Saba Khutsishvili on 6/4/21.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define ll long long
#define ull unsigned long long

const ll N = 501, INF = 1e9;
ll n, m;
vector<vector<ll>> adj;
vector<vector<ll>> orig(N, vector<ll> (N));
vector<vector<ll>> cap(N, vector<ll> (N));
vector<bool> vis(N);
vector<pair<ll, ll>> ans;

void resize() {
    vis.resize(n+1);
    adj.resize(n+1);
    cap.resize(n+1);
    orig.resize(n+1);
    for (ll i = 0; i <= n; ++i) {
        cap[i].resize(n+1);
        orig[i].resize(n+1);
    }
}

ll bfs(ll s, ll t, vector<ll> &par) {
    fill(par.begin(), par.end(), -1);
    par[s] = -2;
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
    vector<ll> par(n+1);
    ll ans = 0, flow;
    while ((flow = bfs(s, t, par))) {
        ans += flow;
        ll cur = t;
        while (cur != s) {
            ll prev = par[cur];
            cap[cur][prev] += flow; // reverse capasity increased
            cap[prev][cur] -= flow; // original decreased
            cur = prev;
        }
    }
}

void dfs(ll i) {
    vis[i] = 1;
    for (ll a : adj[i]) {
        if (!vis[a] && cap[i][a]) {
            dfs(a);
        }
    }
}

void mincut() {
    dfs(1);
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= n; ++j) {
            if (vis[i] && !vis[j]) { // i reachable, j not
                if (orig[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
    }
    ll sz = (ll)ans.size();
    cout << sz << "\n";
    for (ll i = 0; i < sz; ++i) {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
}

int main() {
    ll a, b;
    
    cin >> n >> m;
    resize();
    for (ll i = 0; i < m; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        cap[a][b] = orig[a][b] = 1;
        cap[b][a] = orig[b][a] = 1;
    }
    maxflow(1, n);
    mincut();
    
    return 0;
}
