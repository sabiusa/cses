//
//  main.cpp
//  collecting-numbers
//
//  Created by Saba Khutsishvili on 3/20/21.
//

#include <iostream>
#include <map>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
int main() {
    ll n, c = 1e9, r = 0;
    map<ll, ll> mp;
    
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        mp[x] = i;
    }
    for (ll i = 1; i <= n; ++i) {
        if (mp[i] < c) {
            ++r;
        }
        c = mp[i];
    }
    cout << r << "\n";
    
    return 0;
}
