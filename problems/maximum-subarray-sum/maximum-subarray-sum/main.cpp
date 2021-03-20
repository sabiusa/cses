//
//  main.cpp
//  maximum-subarray-sum
//
//  Created by Saba Khutsishvili on 3/20/21.
//

#include <iostream>

using namespace std;

#define ll long long
#define ull unsigned long long

int main() {
    ll n, r = -1e18, mx = -1e18;
    
    cin >> n;
    while (n--) {
        ll x;
        cin >> x;
        r = max(r + x, x);
        mx = max(mx, r);
    }
    cout << mx << "\n";
    
    return 0;
}
