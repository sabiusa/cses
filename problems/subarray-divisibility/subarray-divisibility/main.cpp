//
//  main.cpp
//  subarray-divisibility
//
//  Created by Saba Khutsishvili on 3/27/21.
//

#include <iostream>
#include "string.h"
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
int main() {
    ll n, a, rem = 0, ans = 0;
    
    cin >> n;
    ll arr[n];
    memset(arr, 0, sizeof(arr));
    arr[0] = 1;
    for (ll i = 0; i < n; ++i) {
        cin >> a;
        ll neg = (a % n) + n; // work around negative numbers
        rem = (rem + neg) % n;
        ans += arr[rem];
        arr[rem]++;
    }
    cout << ans << "\n";
    
    return 0;
}
