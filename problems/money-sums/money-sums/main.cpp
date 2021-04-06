//
//  main.cpp
//  money-sums
//
//  Created by Saba Khutsishvili on 4/6/21.
//

#include <iostream>
#include <vector>
#include <set>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
const ll INF = 1e18;
 
int main() {
    ll n, mx = 0;
    
    cin >> n;
    vector<ll> x(n+1);
    for (ll i = 1; i <= n; ++i) {
        cin >> x[i];
        mx = max(mx, x[i]);
    }
    
    mx *= n; // maximum possible number
    vector<vector<ll>> mem(n+1, vector<ll> (mx + 1, 0));
    for (ll i = 1; i <= n; ++i) {
        ll c = x[i]; // current coin
        for (ll j = 1; j <= mx; ++j) {
            if (j == c) { // exact coin
                mem[i][j] = 1;
            } else if (mem[i-1][j]) { // created on prev iteration
                mem[i][j] = 1;
            } else if (j > c && mem[i-1][j-c]) { // can be new combo
                mem[i][j] = 1;
            }
        }
    }
    
    vector<ll> ans;
    for (ll i = 1; i <= mx; ++i) {
        if (mem[n][i]) {
            ans.push_back(i);
        }
    }
    cout << ans.size() << "\n";
    for (ll s : ans) {
        cout << s << " ";
    }
    cout << "\n";
    
    return 0;
}
