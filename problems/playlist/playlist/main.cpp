//
//  main.cpp
//  playlist
//
//  Created by Saba Khutsishvili on 3/21/21.
//

#include <iostream>
#include <map>

using namespace std;

#define ll long long
#define ull unsigned long long

//int main() {
//    ll n, k, r = 0, mx = 0;
//    map<ll, ll> mp;
//
//    cin >> n;
//    for (ll i = 0; i < n; ++i) {
//        cin >> k;
//        if (mp.find(k) == mp.end()) {
//            ++r;
//        } else {
//            ll dup = mp[k]; // index of duplicate
//            r = i - mp[k];
//            auto it = mp.begin();
//            while (it != mp.end()) { // erase all values before, including duplicate
//                if (it->second <= dup) {
//                    mp.erase(it++); // erase, while maintaining valid iterator
//                } else {
//                    ++it;
//                }
//            }
//        }
//        mp[k] = i;
//        mx = max(mx, r);
//    }
//    cout << mx << "\n";
//
//    return 0;
//}
