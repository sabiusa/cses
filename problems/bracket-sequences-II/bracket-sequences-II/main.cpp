//
//  main.cpp
//  bracket-sequences-II
//
//  Created by Saba Khutsishvili on 5/11/21.
//

#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
const ll N = 3e6+2, MOD = 1e9+7;
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

ll catalan_convolution(ll n, ll k) {
    ll res = fac[2*n + k];
    res = (res * inv(fac[n])) % MOD;
    res = (res * inv(fac[n+k])) % MOD;
    res = (res * (k+1)) % MOD;
    res = (res * inv(n+k+1)) % MOD;
    return res;
}

int main() {
    ll n;
    string s;
    
    cin >> n >> s;
    fill_fac();
    ll oc = 0, cc = 0; // open/close counts
    for (ull i = 0; i < s.size(); ++i) {
        if (s[i] == '(') oc++;
        else cc++;
        if (cc > oc) {
            cout << 0 << "\n";
            return 0;
        }
    }
    if (n % 2) {
        cout << 0 << "\n";
    } else if (oc < cc) {
        cout << 0 << "\n";
    } else {
        n /= 2;
        ll k = oc - cc; // extra open brackets
        if (k > n) {
            cout << 0 << "\n";
        } else {
            n -= oc; // pair of closed brackets
            cout << catalan_convolution(n, k) << "\n";
        }
    }
    
    return 0;
}
