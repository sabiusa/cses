//
//  zfunc.cpp
//  string-matching
//
//  Created by Saba Khutsishvili on 24.06.21.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define ll long long
#define ull unsigned long long

//const ll N = 2e6+2;
//string s, p;
//ll ss, ps;
//vector<ll> z(N);
//
//void calc_z() {
//    for (ll i = 1, l = 0, r = 0; i < ss; ++i) {
//        if (i <= r) {
//            z[i] = min(r-i+1, z[i-l]);
//        }
//        while (s[z[i]] == s[i+z[i]] && i+z[i] < ss) {
//            z[i]++;
//        }
//        if (i+z[i]-1 > r) {
//            l = i;
//            r = i+z[i]-1;
//        }
//    }
//}
//
//ll match() {
//    ll ans = 0;
//    for (ll i = ps+1; i < ss; ++i) {
//        if (z[i] == ps) {
//            ans++;
//        }
//    }
//    return ans;
//}
//
//int main() {
//
//    cin >> s >> p;
//    s = p + '-' + s;
//    ss = (ll)s.size();
//    ps = (ll)p.size();
//    calc_z();
//    cout << match() << "\n";
//
//    return 0;
//}
