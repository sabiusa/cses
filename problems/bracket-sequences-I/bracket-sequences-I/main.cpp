//
//  main.cpp
//  bracket-sequences-I
//
//  Created by Saba Khutsishvili on 5/11/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
const ll N = 2e6+2, MOD = 1e9+7;
vector<ll> fac(N);

void fill_fac() {
    fac[0] = fac[1] = 1;
    for (ll i = 2; i < N; ++i) {
        fac[i] = (fac[i-1] * i) % MOD;
    }
}

ll expo(ll n, ll k) {
    ll res = 1;
    while (k) {
        if (k % 2) res = (res * n) % MOD;
        n = (n * n) % MOD;
        k /= 2;
    }
    return res;
}

ll inv(ll n) {
    return expo(n, MOD-2);
}

ll catalan(ll n) {
    ll res = fac[2*n];
    res = (res * inv(fac[n])) % MOD;
    res = (res * inv(fac[n+1])) % MOD;
    return res;
}

int main() {
    ll n;
    
    cin >> n;
    fill_fac();
    if (n % 2) {
        cout << 0 << "\n";
    } else {
        cout << catalan(n/2) << "\n";
    }
    
    return 0;
}
