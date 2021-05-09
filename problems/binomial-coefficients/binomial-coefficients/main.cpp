//
//  main.cpp
//  binomial-coefficients
//
//  Created by Saba Khutsishvili on 5/9/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
const ll N = 1e6+2, MOD = 1e9+7;
vector<ll> inv(N), fac(N), fac_inv(N);

void calc_inv() {
    inv[1] = 1;
    for (ll i = 2; i < N; ++i) {
        inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
    }
}

void calc_fac() {
    fac[0] = fac_inv[0] = 1;
    for (ll i = 1; i < N; ++i) {
        fac[i] = (fac[i-1] * i) % MOD;
        fac_inv[i] = (fac_inv[i-1] * inv[i]) % MOD;
    }
}

int main() {
    ll n, a, b;
    
    cin >> n;
    calc_inv();
    calc_fac();
    while (n--) {
        cin >> a >> b;
        cout << ((fac[a] * fac_inv[b] % MOD) * fac_inv[a-b]) % MOD << "\n";
    }
    
    return 0;
}
