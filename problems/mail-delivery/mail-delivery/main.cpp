//
//  main.cpp
//  mail-delivery
//
//  Created by Saba Khutsishvili on 5/27/21.
//

#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <string>

using namespace std;

#define ll long long
#define ull unsigned long long

const ll N = 1e5+2;
ll n, m;
vector<vector<ll>> adj(N);
vector<ll> in(N), out(N);
vector<bool> vis(N);
deque<ll> path;
unordered_map<string, ll> del;

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
            if (adj[i].size()) {
                return false; // edges not in same component
            }
        }
    }
    return true;
}

bool check_degree() {
    for (ll i = 1; i <= n; ++i) {
        if ((in[i]) % 2) {
            return false; // circuit needs all even degrees
        }
    }
    return true;
}

bool check() {
    return check_degree() && check_comp();
}

void dfs_path(ll i) {
    deque<ll> temp;
    temp.push_front(i);
    while (!temp.empty()) {
        ll a = temp.front();
        if (adj[a].size() == 0) {
            temp.pop_front();
            path.push_front(a);
        } else {
            ll next = adj[a].back();
            if (del[to_string(a) + "-" + to_string(next)]) {
                adj[a].pop_back();
            } else {
                temp.push_front(next);
                adj[a].pop_back();
                del[to_string(next) + "-" + to_string(a)] = 1; // save as id for deletion later
            }
        }
    }
}

int main() {
    ll a, b;
    
    cin >> n >> m;
    del.reserve(2*N);
    adj.resize(n+1); in.resize(n+1); out.resize(n+1);
    for (ll i = 0; i < m; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        in[a]++;
        out[a]++;
        in[b]++;
        out[b]++;
    }
    if (!check()) {
        cout << "IMPOSSIBLE";
    } else {
        vis.assign(N, 0);
        dfs_path(1);
        if ((ll)path.size() != m+1) {
            cout << "IMPOSSIBLE";
        } else {
            for (ll i = 0; i < (ll)path.size(); ++i) {
                cout << path[i] << " ";
            }
        }
    }
    cout << "\n";
    
    return 0;
}
