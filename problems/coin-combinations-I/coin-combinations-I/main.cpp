//
//  main.cpp
//  coin-combinations-I
//
//  Created by Saba Khutsishvili on 4/2/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long

//const ll INF = 1e18, MOD = 1e9+7, N = 1e6+1;
//
//ll cnt(ll x, vector<ll> &c, vector<ll> &mem) {
//    if (x < 0) return 0;
//    if (x == 0) return 1;
//    if (mem[x] > -1) return mem[x];
//    ll cs = 0;
//    for (ull i = 0; i < c.size(); ++i) {
//        cs += cnt(x - c[i], c, mem);
//        cs %= MOD;
//    }
//    mem[x] = cs;
//    return cs;
//}
//
//int main() {
//    ll n, x;
//    
//    cin >> n >> x;
//    vector<ll> c(n), mem(N, -1);
//    for (ll i = 0; i < n; ++i) {
//        cin >> c[i];
//    }
//    cout << cnt(x, c, mem) << "\n";
//    
//    return 0;
//}
