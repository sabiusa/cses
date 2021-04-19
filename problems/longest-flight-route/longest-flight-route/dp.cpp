//
//  mem.cpp
//  longest-flight-route
//
//  Created by Saba Khutsishvili on 4/18/21.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
 
#define ll long long
#define ull unsigned long long

const ll N = 1e5+2, INF = 1e18;
vector<vector<ll>> adj(N);
vector<ll> vis(N, 0), mem(N, -1), path(N, 0);

ll dfs(ll cur, ll n) {
    vis[cur] = 1;
    if (cur == n) {
        mem[cur] = 0;
        return mem[cur];
    }
    for (ll a : adj[cur]) {
        if (vis[a] == 0) {
            dfs(a, n);
        }
        if (mem[a] == -1) {
            continue;
        }
        if (mem[a] + 1 > mem[cur]) {
            mem[cur] = mem[a] + 1;
            path[cur] = a;
        }
    }
    return mem[cur];
}

void print_path(ll n) {
    vector<ll> ans = {1};
    for (ll x = path[1]; ; x = path[x]) {
        ans.push_back(x);
        if (x == n)
            break;
    }
    cout << ans.size() << "\n";
    for (ll a : ans)
        cout << a << " ";
    cout << "\n";
    exit(0);
}

int main() {
    ll n, m, a, b;
    
    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
    }
    if (dfs(1, n) == -1) {
        cout << "IMPOSSIBLE" << "\n";
    } else {
        print_path(n);
    }
    
    return 0;
}
