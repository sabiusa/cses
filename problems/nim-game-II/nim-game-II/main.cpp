//
//  main.cpp
//  nim-game-II
//
//  Created by Saba Khutsishvili on 5/20/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
const ll N = 2e5+2;

int main() {
    ll t, n;
    
    cin >> t;
    while (t--) {
        cin >> n;
        vector<ll> x(n);
        for (ll i = 0; i < n; ++i) {
            cin >> x[i];
            x[i] %= 4;
        }
        ll xor_sum = 0;
        for (ll i = 0; i < n; ++i) {
            xor_sum ^= x[i];
        }
        if (xor_sum) cout << "first" << "\n";
        else cout << "second" << "\n";
    }
    
    return 0;
}
