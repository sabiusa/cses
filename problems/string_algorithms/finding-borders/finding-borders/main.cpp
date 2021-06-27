//
//  main.cpp
//  finding-borders
//
//  Created by Saba Khutsishvili on 21.06.21.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define ll long long
#define ull unsigned long long

//const ll N = 1e6+2, BASE = 26, MOD=1e9+7;
//string s;
//ll ss;
//vector<ll> h(N), t(N);
//
//ll cd(ll i) {
//    return s[i] - 'a' + 1;
//}
//
//void precalc() {
//    h[0] = cd(0);
//    t[0] = 1;
//    for (ll i = 1; i <= ss; ++i) { // calc prefix hashes
//        h[i] = ((h[i-1] * BASE) + cd(i)) % MOD;
//        t[i] = (t[i-1] * BASE) % MOD;
//    }
//}
//
//ll get_hash(ll a, ll b) {
//    ll ans = 0;
//    if (a < 1) ans = h[b];
//    else ans = (h[b] - (h[a-1] * t[b-a+1])) % MOD;
//    ans = (ans + MOD) % MOD;
//    return ans;
//}
//
//int main() {
//    
//    cin >> s;
//    ss = (ll)s.size();
//    precalc();
//    for (ll i = 0, j = ss-1; i < ss-1; ++i, --j) {
//        ll l = get_hash(0, i), r = get_hash(j, ss-1);
//        if (l == r) {
//            cout << i+1 << " ";
//        }
//    }
//    cout << "\n";
//    
//    return 0;
//}
