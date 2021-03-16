//
//  main.cpp
//  coin-piles
//
//  Created by Saba Khutsishvili on 3/16/21.
//

#include <iostream>

using namespace std;

#define ll long long

int main() {
    ll t, a, b;
    
    cin >> t;
    while (t--) {
        cin >> a >> b;
        ll mx = max(a, b);
        ll mn = min(a, b);
        if (mn * 2 < mx) {
            cout << "NO" << "\n";
        } else {
            if ((a + b) % 3 == 0) {
                cout << "YES" << "\n";
            } else {
                cout << "NO" << "\n";
            }
        }
    }
    
    return 0;
}
