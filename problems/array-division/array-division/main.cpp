//
//  main.cpp
//  array-division
//
//  Created by Saba Khutsishvili on 3/29/21.
//

#include <iostream>
#include <map>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
int main() {
    ll n, k, mx = 0;
    
    cin >> n >> k;
    ll arr[n];
    for (ll i = 0; i < n; ++i) {
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }
    
    ll l = mx, r = 1e18;
    while (l <= r) { // binary search for
        ll m = l + ((r - l) / 2);
        ll cs = 0; // current sum
        ll cnt = 0; // subarray count
        for (ll i = 0; i < n; ++i) {
            if (cs + arr[i] > m) {
                cs = arr[i];
                cnt++;
            } else {
                cs += arr[i];
            }
        }
        if (cnt < k) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << l << "\n";
    
    return 0;
}
