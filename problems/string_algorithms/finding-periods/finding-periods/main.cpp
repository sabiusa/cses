//
//  main.cpp
//  finding-periods
//
//  Created by Saba Khutsishvili on 22.06.21.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define ll long long
#define ull unsigned long long

const ll N = 1e6+2, BASE = 26, MOD=1e9+7;
string s;
ll ss;
vector<ll> h(N), t(N);

ll cd(ll i) {
    return s[i] - 'a' + 1;
}

void precalc() {
    h[0] = cd(0);
    t[0] = 1;
    for (ll i = 1; i <= ss; ++i) {
        h[i] = (h[i-1] * BASE + cd(i)) % MOD;
        t[i] = (t[i-1] * BASE) % MOD;
    }
}

ll get_hash(ll a, ll b) {
    ll ans;
    if (a < 1) ans = h[b];
    else ans = (h[b] - (h[a-1] * t[b-a+1])) % MOD;
    if (ans < 0) ans = (ans + MOD) % MOD;
    return ans;
}

int main() {
    
    cin >> s;
    ss = (ll)s.length();
    precalc();
    for (ll k = 1; k <= ss; ++k) {
        ll i, f = 1, h1 = get_hash(0, k-1), h2 = -1;
        for (i = k; i+k-1 < ss; i += k) {
            h2 = get_hash(i, i+k-1);
            if (h1 != h2) {
                f = 0;
                break;
            }
        }
        if (f) {
            ll m  = ss % k;
            if (m) {
                h1 = get_hash(0, m-1);
                h2 = get_hash(ss-m, ss-1);
                if (h1 == h2) {
                    cout << k << " ";
                }
            } else {
                cout << k << " ";
            }
        }
    }
    cout << "\n";
    
    return 0;
}
