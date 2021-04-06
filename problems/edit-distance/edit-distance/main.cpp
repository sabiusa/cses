//
//  main.cpp
//  edit-distance
//
//  Created by Saba Khutsishvili on 4/6/21.
//

#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
int main() {
    string ns, ms;

    cin >> ns >> ms;
    ll n = ns.size();
    ll m = ms.size();
    vector<vector<ll>> mem(n+1, vector<ll> (m+1, 0));
    for (ll i = 0; i <= n; ++i) {
        mem[i][0] = i;
    }
    for (ll i = 0; i <= m; ++i) {
        mem[0][i] = i;
    }
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= m; ++j) {
            if (ns[i-1] == ms[j-1]) {
                mem[i][j] = mem[i-1][j-1];
            } else {
                mem[i][j] = 1 + min(mem[i-1][j-1], min(mem[i-1][j], mem[i][j-1]));
            }
        }
    }
    cout << mem[n][m] << "\n";
    
    return 0;
}
