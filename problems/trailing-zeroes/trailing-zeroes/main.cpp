//
//  main.cpp
//  trailing-zeroes
//
//  Created by Saba Khutsishvili on 3/16/21.
//

#include <iostream>

using namespace std;

#define ll long long

int main() {
    ll n, r = 0;
    
    cin >> n;
    for (ll i = 5; i <= n; i *= 5) { // every 5 adds one 0, then every 25 another 0, then 125 and so on
        r += n / i; // (n/5) + (n/25) + (n/125) + ...
    }
    cout << r << "\n";
    
    return 0;
}
