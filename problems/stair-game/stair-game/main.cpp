//
//  main.cpp
//  stair-game
//
//  Created by Saba Khutsishvili on 5/21/21.
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
        ll p, ans = 0;
        for (ll i = 0; i < n; ++i) {
            cin >> p;
            if (i % 2) {
                ans ^= p;
            }
        }
        if (ans) cout << "first" << "\n";
        else cout << "second" << "\n";
    }
    
    return 0;
}
