//
//  main.cpp
//  removal-game
//
//  Created by Saba Khutsishvili on 4/6/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
//const ll INF = 1e18;
// 
//int main() {
//    ll n, sum = 0;
//    
//    cin >> n;
//    vector<ll> x(n);
//    for (ll i = 0; i < n; ++i) {
//        cin >> x[i];
//        sum += x[i];
//    }
//    
//    vector<vector<ll>> mem(n, vector<ll> (n, 0));
//    for (ll i = n-1; i >= 0; --i) {
//        for (ll j = i; j < n; ++j) {
//            if (i == j) { // one choise, has to be taken
//                mem[i][j] = x[i];
//            } else {
//                ll l = x[i] - mem[i+1][j]; // pick first
//                ll r = x[j] - mem[i][j-1]; // pick last
//                mem[i][j] = max(l, r);
//            }
//        }
//    }
//    cout << (sum + mem[0][n-1]) / 2 << "\n";
//    
//    return 0;
//}
