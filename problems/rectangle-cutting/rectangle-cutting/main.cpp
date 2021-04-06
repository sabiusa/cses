//
//  main.cpp
//  rectangle-cutting
//
//  Created by Saba Khutsishvili on 4/6/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long

const ll INF = 1e18;
 
int main() {
    ll a, b;
    
    cin >> a >> b;
    vector<vector<ll>> mem(a+1, vector<ll> (b+1, INF));
    for (ll i = 0; i <= a; ++i) {
        for (ll j = 0; j <= b; ++j) {
            if  (i == j) {
                mem[i][j] = 0;
            } else {
                for (ll k = 1; k < i; ++k) {
                    mem[i][j] = min(mem[i][j], mem[k][j] + mem[i-k][j] + 1);
                }
                for (ll k = 1; k < j; ++k) {
                    mem[i][j] = min(mem[i][j], mem[i][k] + mem[i][j-k] + 1);
                }
            }
        }
    }
    cout << mem[a][b] << "\n";
    
    return 0;
}
