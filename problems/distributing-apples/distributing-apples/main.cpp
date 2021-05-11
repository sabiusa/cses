//
//  main.cpp
//  distributing-apples
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

ll expo(ll a, ll p, ll m) {
    ll res = 1;
    while (p) {
        if (p % 2) res = (res * a) % m;
        a = (a * a) % m;
        p /= 2;
    }
    return res;
}

ll inv(ll a) {
    return expo(a, MOD-2, MOD);
}

ll cnt(ll n, ll m) {
    ll res = fac[n+m-1];
    res = (res * inv(fac[m])) % MOD;
    res = (res * inv(fac[n-1])) % MOD;
    return res;
}

int main() {
    ll n, m;
    
    cin >> n >> m;
    fill_fac();
    cout << cnt(n, m) << "\n";
    
    return 0;
}
