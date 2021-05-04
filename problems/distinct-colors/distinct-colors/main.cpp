//
//  main.cpp
//  distinct-colors
//
//  Created by Saba Khutsishvili on 5/4/21.
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long

const ll N = 2e5+2;
ll n;
vector<vector<ll>> adj(N);
vector<ll> ans(N);
vector<set<ll>> cols;

void dfs(ll i, ll p) {
    for (ll a : adj[i]) {
        if (a != p) {
            dfs(a, i);
            if (cols[i].size() < cols[a].size()) {
                swap(cols[i], cols[a]);
            }
            cols[i].insert(cols[a].begin(), cols[a].end());
        }
    }
    ans[i] = cols[i].size();
}

int main() {
    ll a, b;
    
    cin >> n;
    cols.resize(n+1);
    for (ll i = 1; i <= n; ++i) {
        cin >> a;
        cols[i] = {a};
    }
    for (ll i = 1; i < n; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    for (ll i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    
    return 0;
}
