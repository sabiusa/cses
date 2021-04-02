//
//  dice.cpp
//  dice-combinations
//
//  Created by Saba Khutsishvili on 4/1/21.
//

#include <iostream>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long

ll mod = 1e9+7;

int main() {
    ll n;
    
    cin >> n;
    ll mem[n + 1];
    mem[0] = 1;
    for (ll i = 1; i <= n; ++i) {
        ll cs = 0; // current sum
        for (ll j = 1; j <= min(i, (ll)6); ++j) {
            cs += mem[i - j];
            cs %= mod;
        }
        mem[i] = cs;
    }
    cout << mem[n] << "\n";
    
    return 0;
}
