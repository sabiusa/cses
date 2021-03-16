//
//  main.cpp
//  bit-strings
//
//  Created by Saba Khutsishvili on 3/16/21.
//

#include <iostream>

using namespace std;

#define ll long long
#define mod 1e9+7

int main() {
    ll n, r = 1;
    
    cin >> n;
    for (ll i = 1; i <= n; ++i) {
        r <<= 1;
        r %= (ll)mod;
    }
    cout << r << "\n";
    
    return 0;
}
