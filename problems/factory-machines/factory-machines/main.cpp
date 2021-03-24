//
//  main.cpp
//  factory-machines
//
//  Created by Saba Khutsishvili on 3/23/21.
//

#include <iostream>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
int main() {
    ll n, t;
    
    cin >> n >> t;
    ll v[n];
    for (ll i = 0; i < n; ++i) {
        cin >> v[i];
    }
    
    ll l = 0, r = 1e18;
    while (l < r) {
        ll m = l + ((r - l) / 2);
        ll s = 0;
        for (ll i = 0; i < n; ++i) { // check for overflow
            s += m / v[i]; // products made by machines in `m` time
            if (s >= t) {
                break;
            }
        }
        if (s >= t) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    cout << l << "\n";
    
    return 0;
}
