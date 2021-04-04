//
//  main.cpp
//  array-description
//
//  Created by Saba Khutsishvili on 4/3/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long

const ll MOD = 1e9+7;

int main() {
    ll n, m, ans = 0;
    
    cin >> n >> m;
    vector<ll> v(n+1);
    for (ll i = 1 ; i <= n; ++i) {
        cin >> v[i];
    }
    
    vector<vector<ll>> mem(n+2, vector<ll> (m+2, 0)); // +2 for handling both edge cases left/right
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= m; ++j) {
            if (i == 1) {
                if (v[i] == 0 || v[i] == j) {
                    mem[i][j] = 1;
                }
            } else {
                if (v[i] == 0 || v[i] == j) {
                    // number of 1-element-less sized arrays that end either with j-1, j or j+1
                    mem[i][j] = mem[i-1][j-1] + mem[i-1][j] + mem[i-1][j+1];
                    mem[i][j] %= MOD; // these arrays we can extend with j
                }
            }
        }
    }
    
    for (ll j = 1; j <= m; ++j) {
        ans += mem[n][j]; // sum up n-sized arrays
        ans %= MOD;
    }
    cout << ans << "\n";
    
    return 0;
}
