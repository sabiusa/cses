//
//  main.cpp
//  counting-towers
//
//  Created by Saba Khutsishvili on 4/4/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
const ll MOD = 1e9+7;
 
int main() {
    ll t, n = 1;

    cin >> t;
    vector<ll > v(t);
    for (ll i = 0; i < t; ++i) {
        cin >> v[i];
        n = max(n, v[i]);
    }
    
    vector<vector<ll>> mem(n+1, vector<ll> (2, 0));
    mem[0][0] = mem[0][1] = 1;
    for (ll i = 1; i <= n; ++i) {
        ll no_ext = mem[i-1][0] + mem[i-1][1]; // do not extend any of the prev tiles
        ll ext_both = mem[i-1][0]; // extend both of the prev tiles
        ll ext_one = mem[i-1][0] * 2; // extend only one of the prev tiles
        ll ext = mem[i-1][1]; // extend bottom 2-width tile
        
        mem[i][0] = (no_ext + ext_both + ext_one) % MOD;
        mem[i][1] = (no_ext + ext) % MOD;
    }
    
    for (ll i = 0; i < t; ++i) {
        ll c2 = mem[v[i]-1][0]; // starting with 2 tiles, all possible answers
        ll c1 = mem[v[i]-1][1]; // starting with 1 tile, all possible answers
        ll ans = (c2 + c1) % MOD;
        cout << ans << "\n";
    }
    
    return 0;
}
