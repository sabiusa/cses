//
//  main.cpp
//  counting-necklaces
//
//  Created by Saba Khutsishvili on 5/13/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
const ll N = 1e6+2, MOD = 1e9+7;
vector<ll> pows(N);

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll expo(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b % 2) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}

ll inv(ll n) {
    return expo(n, MOD-2);
}

ll burnside(ll n, ll m) {
    ll s = 0;
    for (ll i = 0; i < n; ++i) {
        ll k = gcd(i, n);
        if (pows[k]) {
            s = (s + pows[k]) % MOD;
        } else {
            ll e = expo(m, k);
            s = (s + e) % MOD;
            pows[k] = e;
        }
    }
    s = (s * inv(n)) % MOD;
    return s;
}

int main() {
    ll n, m;
    
    cin >> n >> m;
    cout << burnside(n, m) << "\n";
    
    return 0;
}
