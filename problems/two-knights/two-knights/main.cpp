//
//  main.cpp
//  two-knights
//
//  Created by Saba Khutsishvili on 3/15/21.
//

#include <iostream>

using namespace std;

#define ll long long

int main() {
    ll n;
    
    cin >> n;
    for (int k = 1; k <= n; ++k) {
        ll k2 = k * k; // total squares
        ll t = k2 * (k2 - 1); // total placements of 2 Knights
        ll u = t / 2; // unique placements of 2 Knights
        ll s23 = (k - 1) * (k - 2); // number of 2X3 rects on board
        ll sa = 2 * s23; // same number is for 3X2 rects
        ll a = 2 * sa; // in 2X3 / 3X2 rects, Knights attach in 2 ways
        cout << u - a << "\n";
    }
    
    return 0;
}
