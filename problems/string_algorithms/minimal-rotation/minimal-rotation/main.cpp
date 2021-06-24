//
//  main.cpp
//  minimal-rotation
//
//  Created by Saba Khutsishvili on 22.06.21.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define ll long long
#define ull unsigned long long

const ll N = 2e6+2, BASE = 26, MOD=1e9+7;
string o, s, mn, c;
ll os, ss;
vector<ll> h(N), t(N);
pair<ll, ll> mnp, cp;

ll cd(ll i) {
    return s[i] - 'a' + 1;
}

void precalc() {
    h[0] = cd(0);
    t[0] = 1;
    for (ll i = 1; i <= ss; ++i) {
        h[i] = ((h[i-1] * BASE) + cd(i)) % MOD;
        t[i] = (t[i-1] * BASE) % MOD;
    }
}

ll get_hash(ll a, ll b) {
    ll ans = 0;
    if (a < 1) ans = h[b];
    else ans = (h[b] - (h[a-1] * t[b-a+1])) % MOD;
    if (ans < 0) ans += MOD;
    return ans;
}

ll common_prefix() {
    ll l = 0, r = os;
    while (l < r) {
        ll m = l + ((r-l) / 2);
        ll h1 = get_hash(mnp.first, mnp.first + m);
        ll h2 = get_hash(cp.first, cp.first + m);
        if (h1 != h2) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return l;
}

int main() {
    
    cin >> o;
    s = o + o;
    os = (ll)o.length();
    ss = (ll)s.length();
    mn = o;
    mnp = {0, os-1};
    precalc();
    for (ll i = 1; i < os; ++i) {
        cp = {i, i+os-1};
        ll pos = common_prefix();
        if (pos != os) {
            ll mn_c = mnp.first + pos;
            ll cur_c = cp.first + pos;
            if (s[cur_c] < s[mn_c]) {
                mnp = cp;
            }
        }
    }
    for (ll i = mnp.first; i <= mnp.second; ++i) {
        cout << s[i];
    }
    cout << "\n";
    
    return 0;
}
