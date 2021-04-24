//
//  main.cpp
//  road-construction
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
ll cnt, mx;

ll find(ll x) {
    if (x == par[x]) return x;
    par[x] = find(par[x]);
    return par[x];
}

void unite(ll a, ll b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    par[b] = a;
    cnt--;
    mx = max(mx, sz[a]);
}

int main() {
    ll n, m, a, b;
    
    cin >> n >> m;
    edg.resize(m);
    for (ll i = 0; i < m; ++i) {
        cin >> a >> b;
        edg[i] = {a, b};
    }
    cnt = n; mx = 1;
    for (ll i = 1; i <= n; ++i) {
        par[i] = i;
    }
    for (ll i = 0; i < m; ++i) {
        a = edg[i][0]; b = edg[i][1];
        unite(a, b);
        cout << cnt << " " << mx << "\n";
    }
    
    return 0;
}
