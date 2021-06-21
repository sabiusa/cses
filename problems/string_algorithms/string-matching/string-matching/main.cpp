//
//  main.cpp
//  string-matching
//
//  Created by Saba Khutsishvili on 17.06.21.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define ll long long
#define ull unsigned long long

const ll N = 1e6+2, BASE = 26, MOD=1e9+7;
string s, p;
ll ss, ps, ph = 0;
vector<ll> h(N), t(N);

ll cd(string &s, ll i) {
    return s[i] - 'a' + 1;
}

void precalc() {
    h[0] = cd(s, 0);
    t[0] = 1;
    for (ll i = 1; i < ss; ++i) { // calc prefix hashes and powers
        h[i] = ((h[i-1] * BASE) + cd(s, i)) % MOD;
        t[i] = (t[i-1] * BASE) % MOD;
    }
    for (ll i = ps-1, pow = 1; i >= 0; --i) { // calc pattern hash
        ph = (ph + (cd(p, i) * pow)) % MOD;
        pow = (pow * BASE) % MOD;
    }
}

ll get_hash(ll a, ll b) {
    ll ans;
    if (a < 1) ans = h[b];
    else ans = (h[b] - (h[a-1] * t[b-a+1])) % MOD;
    return (ans + MOD) % MOD;
}


int main() {
    ll ans = 0;
    
    cin >> s >> p;
    ss = (ll)s.size();
    ps = (ll)p.size();
    h.resize(20);
    t.resize(20);
    precalc();
    for (ll a = 0, b = ps-1; b < ss; ++a, ++b) {
        ll hash = get_hash(a, b);
        if (hash == ph) {
            ans++;
        }
    }
    cout << ans << "\n";
    
    return 0;
}
