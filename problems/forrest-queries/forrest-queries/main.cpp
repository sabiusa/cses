//
//  main.cpp
//  forrest-queries
//
//  Created by Saba Khutsishvili on 4/27/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long

int main() {
    ll n, q;
    char c;
    
    cin >> n >> q;
    vector<vector<ll>> mem(n+2, vector<ll> (n+2, 0));
    for (ll i = 1; i <= n; ++i) {
        ll s = 0;
        for (ll j = 1; j <= n; ++j) {
            cin >> c;
            s += (c == '*') ? 1 : 0;
            mem[i][j] = mem[i-1][j] + s;
        }
    }
    while(q--) {
        ll ux, uy, bx, by;
        cin >> uy >> ux >> by >> bx;
        ll all = mem[by][bx];
        ll top = mem[uy-1][bx];
        ll left = mem[by][ux-1];
        ll extra = mem[uy-1][ux-1];
        cout << all - top - left + extra << "\n";
    }
    
    return 0;
}
