//
//  main.cpp
//  planets-queries-I
//
//  Created by Saba Khutsishvili on 4/22/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
const ll N = 2e5+2, INF = 1e18, LOG = 30;
vector<vector<ll>> suc(LOG, vector<ll> (N));

void fill_suc(ll n) {
    for (ll i = 1; i < LOG; ++i) {
        for (ll j = 1; j <= n; ++j) {
            suc[i][j] = suc[i-1][suc[i-1][j]];
        }
    }
}

ll query(ll x, ll k) {
    for (ll i = 0; i < LOG; ++i) {
        if((k >> i) & 1) {
            x = suc[i][x];
        }
    }
    return x;
}

int main() {
    ll n, q, t, x, k;
    
    cin >> n >> q;
    for (ll i = 1; i <= n; ++i) {
        cin >> t;
        suc[0][i] = t;
    }
    fill_suc(n);
    while (q--) {
        cin >> x >> k;
        cout << query(x, k) << "\n";
    }
    
    return 0;
}
