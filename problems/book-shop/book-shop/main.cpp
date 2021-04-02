//
//  main.cpp
//  book-shop
//
//  Created by Saba Khutsishvili on 4/2/21.
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
    
    int m[n+1][x+1];
    memset(m, 0, sizeof(m));
    for (ll i = 1; i <= n; ++i) {
        int pr = p[i-1]; // price
        int pg = s[i-1]; // pages count
        for (int j = 0; j <= x; ++j) {
            int pre = m[i-1][j]; // prev count
            if (j < pr) {
                m[i][j] = pre;
            } else {
                m[i][j] = max(pre, m[i-1][j-pr] + pg);
            }
        }
    }
    cout << m[n][x] << endl;
    
    return 0;
}
