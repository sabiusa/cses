//
//  main.cpp
//  flight-routes-check
//
//  Created by Saba Khutsishvili on 4/24/21.
//

#include <iostream>
#include <vector>
#include <stack>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
const ll N = 1e5+2;
vector<vector<ll>> adj(N), adjr(N);
vector<ll> vis(N, 0), visr(N, 0);
stack<ll> st;

void dfs(ll i) {
    vis[i] = 1;
    for (ll a : adj[i]) {
        if (vis[a] == 0) {
            dfs(a);
        }
    }
}

void dfsr(ll i) {
    visr[i] = 1;
    for (ll a : adjr[i]) {
        if (visr[a] == 0) {
            dfsr(a);
        }
    }
}

int main() {
    ll n, m, a, b;
    
    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adjr[b].push_back(a);
    }
    for (ll i = 1; i <= n; ++i) {
        if (vis[i] == 0) {
            dfs(i);
            st.push(i);
        }
    }
    ll x = st.top();
    dfsr(x);
    for (ll i = 1; i <= n; ++i) {
        if (i == x) continue;
        if (visr[i] == 0) {
            cout << "NO" << "\n";
            cout << i << " " << x << "\n";
            return 0;
        }
    }
    cout << "YES" << "\n";
    
    return 0;
}
