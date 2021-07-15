//
//  main.cpp
//  reachable-nodes
//
//  Created by Saba Khutsishvili on 14.07.21.
//

#include <iostream>
#include <vector>
#include <bitset>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long

const int N = 5e4+1;
int n, m;
vector<vector<int>> adj;
vector<int> vis, tp;
vector<bitset<N>> reach;

void resize() {
    vis.resize(n+1);
    adj.resize(n+1);
    reach.resize(n+1);
}

void topsort(int i) {
    vis[i] = 1;
    for (int a : adj[i]) {
        if (vis[a] == 0) {
            topsort(a);
        }
    }
    vis[i] = 2;
    tp.push_back(i);
}

int main() {
    int a, b;
    
    cin >> n >> m;
    resize();
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for (int i = 1; i <= n; ++i) {
        if (vis[i] == 0) {
            topsort(i);
        }
    }
    for(int i = 0, cur = tp[i]; i < n; ++i, cur = tp[i]) {
        reach[cur].set(cur);
        for (int a : adj[cur]) {
            reach[cur] |= reach[a];
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << reach[i].count() << " ";
    }
    cout << "\n";
    
    return 0;
}
