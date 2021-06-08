//
//  complex.cpp
//  point-location-test
//
//  Created by Saba Khutsishvili on 6/8/21.
//

#include <iostream>
#include <vector>
#include <complex>

using namespace std;

#define ll long long
#define ull unsigned long long

int main() {
    ll t, x1, x2, y1, y2, px, py;
    
    cin >> t;
    while (t--) {
        cin >> x1 >> y1 >> x2 >> y2 >> px >> py;
        
        ll ux = px - x1;
        ll uy = py - y1;
        ll vx = px - x2;
        ll vy = py - y2;
        complex<ll> u = {ux, uy}, v = {vx, vy};
        ll cp = (conj(u) * v).imag(); // cross product
        
        if (cp > 0) cout << "LEFT" << "\n";
        else if (cp == 0) cout << "TOUCH" << "\n";
        else cout << "RIGHT" << "\n";
    }
    return 0;
}
