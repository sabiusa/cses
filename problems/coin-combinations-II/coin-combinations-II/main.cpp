//
//  main.cpp
//  coin-combinations-II
//
//  Created by Saba Khutsishvili on 4/2/21.
//

#include <iostream>
#include <vector>
#include <algorithm>
 
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
    sort(c.begin(), c.end());
    
    mem[0] = 1;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 1; j <= x; ++j) {
            if (j - c[i] >= 0) {
                mem[j] += mem[j - c[i]];
                mem[j] %= MOD;
            }
        }
    }
    cout << mem[x] << "\n";
    
    return 0;
}
