//
//  main.cpp
//  necessary-cities
//
//  Created by Saba Khutsishvili on 22.07.21.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define ll long long
#define ull unsigned long long

int n, m, t = 0;
vector<vector<int>> adj;
vector<int> vis, low, in;
set<int> art;

void resize() {
    adj.resize(n+1);
    vis.resize(n+1);
    low.resize(n+1);
    in.resize(n+1);
}

void dfs(int i, int p) {
    vis[i] = 1;
    in[i] = low[i] = ++t;
    int child = 0;
    for (int a : adj[i]) {
        if (a == p) continue;
        if (vis[a]) {
            low[i] = min(low[i], in[a]);
        } else {
            dfs(a, i);
            low[i] = min(low[i], low[a]);
            if (low[a] >= in[i] && p != -1) {
                art.insert(i);
            }
            child++;
        }
    }
    if (p == -1 && child > 1) {
        art.insert(i);
    }
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
    cout << art.size() << "\n";
    for (auto a : art) {
        cout << a << " ";
    }
    cout << "\n";
    
    return 0;
}
