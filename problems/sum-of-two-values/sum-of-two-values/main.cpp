//
//  main.cpp
//  sum-of-two-values
//
//  Created by Saba Khutsishvili on 3/20/21.
//

#include <iostream>
#include <map>

using namespace std;

#define ll long long
#define ull unsigned long long

int main() {
    ll n, x;
    map<ll, ll> mp;
    
    cin >> n >> x;
    for (ll i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        ll o = x - a;
        if (mp.find(o) != mp.end()) {
            cout << i + 1 << " " << mp[o] << "\n";
            return 0;
        }
        mp[a] = i + 1;
    }
    cout << "IMPOSSIBLE" << "\n";
    
    return 0;
}
