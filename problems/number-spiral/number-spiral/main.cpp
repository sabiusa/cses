//
//  main.cpp
//  number-spiral
//
//  Created by Saba Khutsishvili on 3/15/21.
//

#include <iostream>

using namespace std;

#define ll long long

int main() {
    ll t, x, y;
    
    cin >> t;
    while (t--) {
        cin >> y >> x;
        
        ll ys = (y % 2) ? (y - 1) * (y - 1) + 1 : y * y;
        ll xs = (x % 2) ? (x * x) : (x - 1) * (x - 1) + 1;
        
        if (y < x) {
            if (x % 2) {
                cout << xs - y + 1 << "\n";
            } else {
                cout << xs + y - 1 << "\n";
            }
        } else {
            if (y % 2) {
                cout << ys + x - 1 << "\n";
            } else {
                cout << ys - x + 1 << "\n";
            }
        }
    }
    
    return 0;
}
