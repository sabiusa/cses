//
//  main.cpp
//  eulerian-subgraphs
//
//  Created by Saba Khutsishvili on 23.07.21.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define ll long long
#define ull unsigned long long

ll MOD = 1e9+7;
int n, m, back_edges = 0;
vector<vector<int>> adj;
vector<int> vis, in, low;

void resize() {
    adj.resize(n+1);
    vis.resize(n+1);
    in.resize(n+1);
    low.resize(n+1);
}

void dfs(int i, int p) {
    vis[i] = 1;
    for (int a : adj[i]) {
        if (a == p) continue;
        if (!vis[a]) {
            dfs(a, i);
        } else if (vis[a] == 1) {
            cout << i << " " << a << endl;
            back_edges++;
        }
    }
    vis[i] = 2;
}

ll expo(ll i, ll n) {
    ll res = 1;
    while (n) {
        if (n % 2) res = (res * i) % MOD;
        i = (i * i) % MOD;
        n /= 2;
    }
    return res;
}

int main() {
    int a, b;
    
    cin >> n >> m;
    resize();
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs(i, -1);
        }
    }
    cout << expo(2, back_edges) << "\n";
    
    return 0;
}
