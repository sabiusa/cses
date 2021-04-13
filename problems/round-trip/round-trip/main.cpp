//
//  main.cpp
//  round-trip
//
//  Created by Saba Khutsishvili on 4/13/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
const ll N = 1e5+1;
vector<vector<ll>> adj(N);
vector<ll> vis(N, 0);

void print_path(ll i) {
    vector<ll> v;
    v.push_back(i);
    ll cur = i;
    while (1) {
        cur = vis[cur];
        v.push_back(cur);
        if (cur == i) {
            break;
        }
    }
    cout << v.size() << "\n";
    for (ull i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << "\n";
    exit(0);
}

void dfs(ll i, ll p) {
    vis[i] = p;
    for (ll c : adj[i]) {
        if (c == p) continue;;
        if (vis[c] == 0) {
            dfs(c, i);
        } else {
            vis[c] = i;
            print_path(c);
        }
    }
}

int main() {
    ll n, m, a, b;
    
    cin >> n >> m;
    while (m--) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (ll i = 1; i <= n; ++i) {
        if (vis[i] == 0) {
            dfs(i, 0);
        }
    }
    cout << "IMPOSSIBLE" << "\n";
    
    return 0;
}

