//
//  main.cpp
//  palindrome-reorder
//
//  Created by Saba Khutsishvili on 3/16/21.
//

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

#define ll long long

int main() {
    string s, r;
    ll a[26] = {};
    ll oc = 0, odd = -1;
    
    cin >> s;
    for (char c : s) {
        ++a[c - 'A'];
    }
    for (ll i = 0; i < 26; ++i) {
        if (a[i] % 2) {
            ++oc;
            odd = i;
            if (oc > 1) {
                cout << "NO SOLUTION" << "\n";
                return 0;
            }
        }
    }
    for (ll i = 0; i < 26; ++i) {
        if (i != odd) {
            for (ll j = 0; j < a[i] / 2; ++j) {
                r += ('A' + i);
            }
        }
    }
    cout << r;
    if (odd > -1) {
        for (ll i = 0; i < a[odd]; ++i) {
            cout << char('A' + odd);
        }
    }
    reverse(r.begin(), r.end());
    cout << r << "\n";
    
    return 0;
}
