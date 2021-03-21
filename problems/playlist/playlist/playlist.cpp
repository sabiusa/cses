//
//  playlist.cpp
//  playlist
//
//  Created by Saba Khutsishvili on 3/21/21.
//

#include <iostream>
#include <map>

using namespace std;

#define ll long long
#define ull unsigned long long

int main() {
    ll n, mx = 0;
    map<ll, ll> mp;
    
    cin >> n;
    ll a[n];
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (ll l = 0, r = 0; r < n; ++r) {
        auto it = mp.find(a[r]); // find index of possible duplicate
        if (it != mp.end()) {
            l = max(l, it->second + 1); // slide left counter if duplicate found
        }
        mp[a[r]] = r; // save index
        mx = max(mx, r - l + 1);
    }
    cout << mx << "\n";
    
    return 0;
}
