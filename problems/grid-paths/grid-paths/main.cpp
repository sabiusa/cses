//
//  main.cpp
//  grid-paths
//
//  Created by Saba Khutsishvili on 4/2/21.
//

#include <iostream>
#include <string.h>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long

const ll INF = 1e18, MOD = 1e9+7, N = 1e3+1;

int main() {
    ll n;
    
    cin >> n;
    char g[n][n];
    ll mem[n][n];
    memset(mem, 0, sizeof(mem));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            cin >> g[i][j];
        }
    }
    for (ll i = 0; i < n; ++i) {
        if (g[0][i] == '.')
            mem[0][i] = 1;
        else break;
    }
    for (ll i = 0; i < n; ++i) {
        if (g[i][0] == '.')
            mem[i][0] = 1;
        else break;
    }
    for (ll i = 1; i < n; ++i) {
        for (ll j = 1; j < n; ++j) {
            if (g[i][j] == '*') {
                mem[i][j] = 0;
            } else {
                mem[i][j] += mem[i-1][j] + mem[i][j-1];
                mem[i][j] %= MOD;
            }
        }
    }
    cout << mem[n-1][n-1] << "\n";
    
    return 0;
}
