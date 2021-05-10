//
//  main.cpp
//  creating-strings-II
//
//  Created by Saba Khutsishvili on 5/10/21.
//

#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
const ll N = 1e6+2, MOD = 1e9+7;
vector<ll> inv(N), fac(N), fac_inv(N), counts(26);

void fill_inv() {
    inv[1] = 1;
    for (ll i = 2; i < N; ++i) {
        inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
    }
}

void fill_facs() {
    fac[0] = fac_inv[0] = 1;
    for (ll i = 1; i < N; ++i) {
        fac[i] = (fac[i-1] * i) % MOD;
        fac_inv[i] = (fac_inv[i-1] * inv[i]) % MOD;
    }
}

ll cnt(ll n) {
    ll ans = fac[n];
    for (ll i = 0; i < 26; ++i) {
        if (counts[i]) {
            ans = (ans * fac_inv[counts[i]]) % MOD;
        }
    }
    return ans;
}

int main() {
    ll n;
    string s;
    
    cin >> s;
    n = (ll)s.size();
    for (char d : s) {
        counts[d-'a']++;
    }
    fill_inv();
    fill_facs();
    cout << cnt(n) << "\n";
    
    return 0;
}
