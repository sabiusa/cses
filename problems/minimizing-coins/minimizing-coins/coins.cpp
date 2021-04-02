//
//  coins.cpp
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

int main() {
    ll n, x;

    cin >> n >> x;
    vector<ll> c(n), mem(x + 1, INF);
    mem[0] = 0;
    for (ll i = 0; i < n; ++i) {
        cin >> c[i];
    }
    for (ll i = 1; i <= x; ++i) {
        ll cs = INF;
        for (ll j = 0; j < n; ++j) {
            if (i - c[j] >= 0) {
                cs = min(cs, mem[i - c[j]] + 1);
            }
        }
        mem[i] = cs;
    }
    if (mem[x] == INF) cout << -1;
    else cout << mem[x];
    cout << "\n";

    return 0;
}
