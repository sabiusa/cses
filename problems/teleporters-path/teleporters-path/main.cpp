//
//  main.cpp
//  teleporters-path
//
//  Created by Saba Khutsishvili on 5/30/21.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>

using namespace std;

#define ll long long
#define ull unsigned long long

const ll N = 1e5+2;
ll n, m;
vector<vector<ll>> adj(N);
vector<ll> in(N), out(N);
vector<bool> vis(N);
deque<ll> path;

void dfs_comp(ll i) {
    vis[i] = 1;
    for (ll a : adj[i]) {
        if (!vis[a]) {
            dfs_comp(a);
        }
    }
}

bool check_comp() {
    dfs_comp(1);
    for (ll i = 1; i <= n; ++i) {
        if (!vis[i]) {
            if (!adj[i].empty()) {
                return false; // edges not in same component
            }
        }
    }
    return true;
}

bool check_degrees() {
    for (ll i = 2; i < n; ++i) {
        if (in[i] != out[i]) {
            return false; // all other nodes in = out
        }
    }
    if (in[1] == out[1] && in[n] == out[n]) {
        return false; // no need for circuit
    }
    if (in[1] == out[1]-1 && in[n] == out[n]+1) {
        return true; // path is possible
    }
    return false;
}

bool check() {
    return check_comp() && check_degrees();
}

void dfs_path(ll i) {
    deque<ll> temp;
    temp.push_front(i);
    while (temp.size()) {
        ll a = temp.front();
        if (adj[a].size() == 0) {
            path.push_front(a);
            temp.pop_front();
        } else {
            ll b = adj[a].back();
            temp.push_front(b);
            adj[a].pop_back();
        }
    }
}

int main() {
    ll a, b;
    
    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        out[a]++;
        in[b]++;
    }
    if (check()) {
        dfs_path(1);
        if (path.size() != m+1) {
            cout << "IMPOSSIBLE";
        } else {
            for (ll i = 0; i < (ll)path.size(); ++i) {
                cout << path[i] << " ";
            }
        }
    } else {
        cout << "IMPOSSIBLE";
    }
    cout << "\n";
    
    return 0;
}
