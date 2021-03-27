//
//  main.cpp
//  subarray-sums-II
//
//  Created by Saba Khutsishvili on 3/27/21.
//

#include <iostream>
#include <unordered_map>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
int main() {
    ll n, x, a, sum = 0, ans = 0;
    
    cin >> n >> x;
    unordered_map<ll, ll> mp;
    mp.reserve(1 << 18);
    mp[0] = 1;
    for (ll i = 0; i < n; ++i) {
        cin >> a;
        sum += a;
        ll m = sum - x;
        ans += mp[m];
        ++mp[sum];
    }
    cout << ans << "\n";
    
    return 0;
}
