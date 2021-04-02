//
//  main.cpp
//  dice-combinations
//
//  Created by Saba Khutsishvili on 4/1/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long

//ll mod = 1e9+7;
//
//ll cnt(ll n, vector<ll> &mem) {
//    if (n < 0) return 0;
//    if (n < 2) return 1;
//    if (mem[n]) return mem[n];
//    ll ans = 0;
//    for (ll i = 1; i <= 6; ++i) {
//        ans += cnt(n - i, mem);
//        ans %= mod;
//    }
//    mem[n] = ans;
//    return ans;
//}
//
//int main() {
//    ll n;
//
//    cin >> n;
//    vector<ll> mem(n + 1, 0);
//    cout << cnt(n, mem) << "\n";
//
//    return 0;
//}
