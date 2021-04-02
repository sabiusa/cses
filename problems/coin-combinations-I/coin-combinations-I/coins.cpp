//
//  coins.cpp
//  coin-combinations-I
//
//  Created by Saba Khutsishvili on 4/2/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long

const ll INF = 1e18, MOD = 1e9+7, N = 1e6+1;

int main() {
    ll n, x;

    cin >> n >> x;
    vector<ll> c(n), mem(N, 0);
    for (ll i = 0; i < n; ++i) {
        cin >> c[i];
    }
    
    mem[0] = 1;
    for (ll i = 1; i <= x; ++i) {
        ll cs = 0;
        for (ll j = 0; j < n; ++j) {
            if (i - c[j] >= 0) {
                cs += mem[i - c[j]];
                cs %= MOD;
            }
        }
        mem[i] = cs;
    }
    cout << mem[x] << "\n";

    return 0;
}

