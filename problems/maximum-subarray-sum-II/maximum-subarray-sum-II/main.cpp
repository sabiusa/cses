//
//  main.cpp
//  maximum-subarray-sum-II
//
//  Created by Saba Khutsishvili on 3/31/21.
//

#include <iostream>
#include <set>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
int main() {
    ll n, a, b, ans = -1e18;
    
    cin >> n >> a >> b;
    ll pref[n + 1];
    pref[0] = 0;
    for (ll x, i = 1; i <= n; ++i) {
        cin >> x;
        pref[i] = pref[i - 1] + x;
    }
    
    multiset<ll> mt;
    for (ll i = a; i <= n; ++i) {
        if (i > b) {
            mt.erase(mt.find(pref[i - b - 1]));
        }
        mt.insert(pref[i - a]);
        ans = max(ans, pref[i] - *mt.begin());
    }
    cout << ans << "\n";
    
    return 0;
}
