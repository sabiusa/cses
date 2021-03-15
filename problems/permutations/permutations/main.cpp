//
//  main.cpp
//  permutations
//
//  Created by Saba Khutsishvili on 3/15/21.
//

#include <iostream>

using namespace std;

#define ll long long

int main() {
    ll n;
    
    cin >> n;
    if (n == 2 || n == 3) {
        cout << "NO SOLUTION" << "\n";
    } else { // generate all evens 2,4... then all odds: 1,3,5...
        for (ll i = 2; i <= n; i += 2) {
            cout << i << " ";
        }
        for (ll i = 1; i <= n; i += 2) {
            cout << i << " ";
        }
    }
    cout << "\n";
    
    return 0;
}
