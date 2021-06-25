//
//  main.cpp
//  longest-plaindrome
//
//  Created by Saba Khutsishvili on 23.06.21.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define ll long long
#define ull unsigned long long

const ll N = 1e6+2, BASE = 26, MOD=1e9+7;
string s, r;
ll ss;
vector<ll> sh(N), rh(N), t(N);
pair<ll, ll> omxp, emxp, mxp, cp, cpr;

ll cd(string &s, ll i) {
    return s[i] - 'a' + 1;
}

void precalc() {
    sh[0] = cd(s, 0);
    rh[0] = cd(r, 0);
    t[0] = 1;
    for (ll i = 1; i <= ss; ++i) {
        sh[i] = ((sh[i-1] * BASE) + cd(s, i)) % MOD;
        rh[i] = ((rh[i-1] * BASE) + cd(r, i)) % MOD;
        t[i] = (t[i-1] * BASE) % MOD;
    }
}

ll get_hash(vector<ll> &h, ll a, ll b) {
    ll ans = 0;
    if (a < 1) ans = h[b];
    else ans = (h[b] - (h[a-1] * t[b-a+1])) % MOD;
    if (ans < 0) ans += MOD;
    return ans;
}

ll common_prefix(ll sz) {
    ll l = 0, r = sz;
    while (l < r) {
        ll m = l + (r-l)/2;
        ll hl = get_hash(sh, cp.first, cp.first+m);
        ll hr = get_hash(rh, cpr.first, cpr.first+m);
        if (hl != hr) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return l;
}

int main() {
    ll omx = 0, emx = 0;
    
    cin >> s;
    r = s;
    ss = (ll)s.size();
    reverse(r.begin(), r.end());
    precalc();
    for (ll i = 1; i < ss; ++i) {
        ll r = ss - i - 1;
        ll sz = min(i, r);
        
        cp = {i+1, i+sz};
        cpr = {r+1, r+sz};
        ll ep = common_prefix(sz); // even palindrome prefix
        
        cp = {i, i+sz-1};
        cpr = {r+1, r+sz-1};
        ll op = common_prefix(sz+1); // odd palindrome prefix
        
        if (ep > emx) {
            emx = ep;
            emxp = {i-ep, i+ep};
        }
        if (op > omx) {
            omx = op;
            omxp = {i-op, i+op-1};
        }
    }
    if (2*emx+1 > 2*omx) mxp = emxp;
    else mxp = omxp;
    for (ll i = mxp.first; i <= mxp.second; ++i) {
        cout << s[i];
    }
    cout << "\n";
    
    return 0;
}
