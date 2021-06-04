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

void mincut(ll s, ll t) {
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

void print_path() {
    cout << "\n";
}

int main() {
    ll a, b;
    
    cin >> n >> m;
    adj.resize(n+1);
    for (ll i = 0; i < m; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        cap[a][b] = 1;
        cap[b][a] = 1;
    }
    mincut(1, n);
    print_path();
    
    return 0;
}
