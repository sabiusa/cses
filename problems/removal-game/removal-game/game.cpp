//
//  game.cpp
//  removal-game
//
//  Created by Saba Khutsishvili on 4/7/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
const ll INF = 1e18;
 
int main() {
    ll n, sum = 0;
    
    cin >> n;
    vector<ll> x(n);
    for (ll i = 0; i < n; ++i) {
        cin >> x[i];
        sum += x[i];
    }
    
    vector<vector<pair<ll, ll>>> mem(n, vector<pair<ll, ll>> (n, {0, 0}));
    for (ll i = n-1; i >= 0; --i) {
        for (ll j = i; j < n; ++j) {
            if (i == j) {
                mem[i][j].first = x[i];
            } else {
                ll l = x[i] + mem[i+1][j].second;
                ll r = x[j] + mem[i][j-1].second;
                
                if (l > r) {
                    mem[i][j].first = l;
                    mem[i][j].second = mem[i+1][j].first;
                } else {
                    mem[i][j].first = r;
                    mem[i][j].second = mem[i][j-1].first;
                }
            }
        }
    }
    cout << mem[0][n-1].first << "\n";
    
    return 0;
}
