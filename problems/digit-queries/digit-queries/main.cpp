//
//  main.cpp
//  digit-queries
//
//  Created by Saba Khutsishvili on 3/18/21.
//

#include <iostream>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long

int main() {
    ll n, k;
    
    cin >> n;
    while (n--) {
        ll l = 1; // group length 1,2,3...digit numbers
        ll f = 1; // group starter, 1, 10, 100...
        cin >> k;
        while (k > 9 * f * l) {
            k -= 9 * f * l; // number of digits in group
            l += 1;
            f *= 10;
        }
        ll q = (k - 1) / l; // count of numbers within group
        ll r = (k - 1) % l; // position of digit
        string s = to_string(f + q); // reconstruct number
        cout << s[r] << "\n";
    }
    
    return 0;
}
