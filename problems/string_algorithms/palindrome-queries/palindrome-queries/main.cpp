//
//  main.cpp
//  palindrome-queries
//
//  Created by Saba Khutsishvili on 28.06.21.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long

const ll N = 2e5+2, BASE = 26, MOD = 1e9+7;
string s, rs;
ll ss;
vector<ll> segs, segrs, t(N);

void precalc() {
    t[0] = 1;
    for (ll i = 1; i <= ss; ++i) {
        t[i] = (t[i-1] * BASE) % MOD;
    }
}

ll cd(string &s, ll i) {
    return s[i] - 'a' + 1;
}

void fill() {
    for (ll i = ss; i < 2*ss; ++i) {
        segs[i] = (cd(s, i-ss) * t[ss-(i-ss)-1]) % MOD;
        segrs[i] = (cd(rs, i-ss) * t[ss-(i-ss)-1]) % MOD;
    }
    for (ll i = ss-1; i > 0; --i) {
        segs[i] = (segs[i*2] + segs[i*2+1]) % MOD;
        segrs[i] = (segrs[i*2] + segrs[i*2+1]) % MOD;
    }
}

void update(ll a, string &c) {
    ll nc = c[0]-'a'+ 1, i = a+ss;
    segs[i] = (nc * t[ss-a-1]) % MOD;
    for (i /= 2; i; i /= 2) {
        segs[i] = (segs[i*2] + segs[i*2+1]) % MOD;
    }
    ll ra = ss-a-1;
    i = ra+ss;
    segrs[i] = (nc * t[ss-ra-1]) % MOD;
    for (i /= 2; i; i /= 2) {
        segrs[i] = (segrs[i*2] + segrs[i*2+1]) % MOD;
    }
}

ll query(vector<ll> &seg, ll a, ll b) {
    ll ans = 0;
    for (a += ss, b += ss; a < b; a /= 2, b /= 2) {
        if (a % 2) ans = (ans + seg[a++]) % MOD;
        if (b % 2) ans = (ans + seg[--b]) % MOD;
    }
    return ans;
}

string cmp(ll a, ll b) {
    ll ra = ss-a-1, rb = ss-b-1, d = abs(a-rb);
    ll c1 = query(segs, a, b);
    ll c2 = query(segrs, rb, ra);
    if (a > rb) {
        c1 = (c1 * t[d]) % MOD;
    } else {
        c2 = (c2 * t[d]) % MOD;
    }
    return c1 == c2 ? "YES" : "NO";
}

int main() {
    ll m, k, a, b;
    string c;
    
    cin >> ss >> m;
    cin >> s;
    rs = s;
    reverse(rs.begin(), rs.end());
    segs.resize(ss*2);
    segrs.resize(ss*2);
    precalc();
    fill();
    while (m--) {
        cin >> k;
        if (k == 1) {
            cin >> a >> c;
            update(a-1, c);
        } else {
            cin >> a >> b;
            cout << cmp(a-1, b-1) << "\n";
        }
    }
    
    return 0;
}
