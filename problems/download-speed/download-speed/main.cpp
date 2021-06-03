//
//  main.cpp
//  download-speed
//
//  Created by Saba Khutsishvili on 6/3/21.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define ll long long
#define ull unsigned long long

const ll N = 501, INF = 1e9+2;
ll n, m;
vector<vector<ll>> adj;
vector<vector<ll>> cap(N, vector<ll> (N));

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
            if (par[a] == -1 && cap[cur][a]) {
                par[a] = cur;
                ll mn = min(flow, cap[cur][a]);
                if (a == t) {
                    return mn;
                }
                q.push({a, mn});
            }
        }
    }
    return 0;
}

ll maxflow(ll s, ll t) {
    vector<ll> par(n+1);
    ll ans = 0, flow;
    while ((flow = bfs(s, t, par))) {
        ans += flow;
        ll cur = t;
        while (cur != s) {
            ll prev = par[cur];
            cap[cur][prev] += flow; // reverse capasity increased
            cap[prev][cur] -= flow; // original capasity decreased
            cur = prev;
        }
    }
    return ans;
}

int main() {
    ll a, b, c;
    
    cin >> n >> m;
    adj.resize(n+1);
    for (ll i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        adj[a].push_back(b);
        adj[b].push_back(a);
        cap[a][b] += c;
    }
    cout << maxflow(1, n) << "\n";
    
    return 0;
}
