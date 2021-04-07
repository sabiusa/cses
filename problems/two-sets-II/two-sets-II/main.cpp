//
//  main.cpp
//  two-sets-II
//
//  Created by Saba Khutsishvili on 4/7/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
//const ll INF = 1e18, MOD = 1e9+7;
// 
//int main() {
//    ll n, sum = 0, h;
//    
//    cin >> n;
//    sum = (n * (n+1)) / 2;
//    if (sum % 2) {
//        cout << 0 << "\n";
//        return 0;
//    }
//    
//    h = sum / 2;
//    vector<vector<ll>> mem(n, vector<ll> (h+1, 0));
//    mem[0][0] = 1;
//    for (ll i = 1; i < n; ++i) {
//        for (ll j = 0; j <= h; ++j) {
//            mem[i][j] = mem[i-1][j];
//            if (j >= i) {
//                mem[i][j] += mem[i-1][j-i];
//                mem[i][j] %= MOD;
//            }
//        }
//    }
//    cout << mem[n-1][h] << "\n";
//    
//    return 0;
//}
