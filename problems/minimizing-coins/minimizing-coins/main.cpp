//
//  main.cpp
//  minimizing-coins
//
//  Created by Saba Khutsishvili on 4/2/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long

ll INF = 1e18;

ll cnt(ll x, vector<ll> &c, vector<ll> &mem) {
    if (x < 0) return INF;
    if (x == 0) return 0;
    if (mem[x]) return mem[x];
    ll cs = INF;
    for (ull i = 0; i < c.size(); ++i) {
        cs = min(cs, cnt(x - c[i], c, mem) + 1);
    }
    mem[x] = cs;
    return cs;
}

int main() {
    ll n, x;
    
    cin >> n >> x;
    vector<ll> c(n), mem(1e6 + 1, 0);
    for (ll i = 0; i < n; ++i) {
        cin >> c[i];
    }
    ll ans = cnt(x, c, mem);
    if (ans == INF) cout << -1;
    else cout << ans;
    cout << "\n";
    
    return 0;
}
