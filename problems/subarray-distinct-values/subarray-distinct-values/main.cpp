//
//  main.cpp
//  subarray-distinct-values
//
//  Created by Saba Khutsishvili on 3/28/21.
//

#include <iostream>
#include <map>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
int main() {
    ll n, k, ans = 0;
    
    cin >> n >> k;
    ll arr[n];
    for (ll i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    ll d = 0;
    map<ll, ll> mp;
    for (ll l = 0, r = 0; r < n; ++r) {
        if (mp[arr[r]] == 0) {
            d++;
        }
        mp[arr[r]]++;
        if (d > k) {
            while (d > k) {
                mp[arr[l]]--;
                if (mp[arr[l]] == 0) {
                    d--;
                }
                l++;
            }
        }
        ans += r - l + 1;
    }
    cout << ans << "\n";
    
    return 0;
}
