//
//  main.cpp
//  static-range-minimum-queries
//
//  Created by Saba Khutsishvili on 4/26/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long

const ll N = 2e5+2, LOG = 20;
vector<ll> lg(N, 0);
vector<vector<ll>> spt(LOG, vector<ll> (N, 0));

int main() {
    ll n, q, a, b;
    
    cin >> n >> q;
    for (ll i = 1; i <= n; ++i) {
        cin >> spt[0][i];
    }
    for (ll i = 2; i <= n; ++i) {
        lg[i] = lg[i/2] + 1;
    }
    for (ll j = 1; j < LOG; ++j) {
        for (ll i = 1; i + (1 << j) <= n+1; ++i) { // 1<<j = 2^j
            spt[j][i] = min(spt[j-1][i], spt[j-1][i+(1<<(j-1))]);
        }
    }
    while (q--) {
        cin >> a >> b;
        ll len = b - a + 1; // interval length
        ll log = lg[len]; // log for the size of this interval
        ll mn = min(spt[log][a], spt[log][b-(1<<log)+1]);
        cout << mn << "\n";
    }
    
    return 0;
}
