//
//  main.cpp
//  stick-game
//
//  Created by Saba Khutsishvili on 5/19/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
const ll N = 1e6+2;
vector<ll> p(N);
vector<char> res;

void calc(ll n, ll k) {
    res[0] = 'L';
    for (ll i = 1; i <= n; ++i) {
        res[i] = 'L';
        for (ll j = 0; j < k; ++j) {
            ll pos = i - p[j];
            if (pos >= 0 && res[pos] == 'L') { // if move leads to losing state, then win
                res[i] = 'W';
            }
        }
    }
}

int main() {
    ll n, k;
    
    cin >> n >> k;
    p.resize(k);
    res.resize(n+1);
    for (ll i = 0; i < k; ++i) {
        cin >> p[i];
    }
    calc(n, k);
    for (ll i = 1; i <= n; ++i) {
        cout << res[i];
    }
    cout << "\n";
    
    return 0;
}
