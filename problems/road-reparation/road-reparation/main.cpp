//
//  main.cpp
//  road-reparation
//
//  Created by Saba Khutsishvili on 4/24/21.
//

#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
const ll N = 1e5+2;
vector<vector<ll>> edg;
vector<ll> par(N), sz(N, 1);

ll find(ll x) {
    if (x == par[x]) return x;
    par[x] = find(par[x]);
    return par[x];
}

bool unite(ll a, ll b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    par[b] = a;
    return true;
}

int main() {
    ll n, m, a, b, w;
    
    cin >> n >> m;
    edg.resize(m);
    for (ll i = 0; i < m; ++i) {
        cin >> a >> b >> w;
        edg[i] = {w, a, b};
    }
    sort(edg.begin(), edg.end());
    for (ll i = 1; i <= n; ++i) {
        par[i] = i;
    }
    
    ll cnt = 0, cst = 0;
    for (ll i = 0; i < m; ++i) {
        w = edg[i][0]; a = edg[i][1]; b = edg[i][2];
        if (unite(a, b)) { // not in same component
            cnt++;
            cst += w;
        }
    }
    if (cnt < n-1) {
        cout << "IMPOSSIBLE" << "\n";
    } else {
        cout << cst << "\n";
    }
    
    return 0;
}
