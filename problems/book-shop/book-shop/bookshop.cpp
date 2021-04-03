//
//  bookshop.cpp
//  book-shop
//
//  Created by Saba Khutsishvili on 4/3/21.
//

#include <iostream>
#include <string.h>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long

int main() {
    ll n, x;
    
    cin >> n >> x;
    int p[n], s[n];
    for (ll i = 0; i < n; ++i) {
        cin >> p[i];
    }
    for (ll i = 0; i < n; ++i) {
        cin >> s[i];
    }
    
    ll mem[x + 1];
    memset(mem, 0, sizeof(mem));
    for (ll i = 0; i < n; ++i) {
        ll pr = p[i];
        ll ps = s[i];
        for (ll j = x; j >= pr; --j) {
            mem[j] = max(mem[j], mem[j-pr] + ps);
        }
    }
    cout << mem[x] << "\n";
    
    return 0;
}
