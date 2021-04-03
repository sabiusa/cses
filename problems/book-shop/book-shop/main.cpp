//
//  main.cpp
//  book-shop
//
//  Created by Saba Khutsishvili on 4/2/21.
//

#include <iostream>
#include <string.h>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long

//int main() {
//    ll n, x;
//    
//    cin >> n >> x;
//    int p[n], s[n];
//    for (ll i = 0; i < n; ++i) {
//        cin >> p[i];
//    }
//    for (ll i = 0; i < n; ++i) {
//        cin >> s[i];
//    }
//    
//    int mem[n+1][x+1];
//    memset(mem, 0, sizeof(mem));
//    for (ll i = 1; i <= n; ++i) {
//        int pr = p[i-1]; // price
//        int pg = s[i-1]; // pages count
//        for (int j = 0; j <= x; ++j) {
//            int pre = mem[i-1][j]; // prev count
//            if (j < pr) {
//                mem[i][j] = pre;
//            } else {
//                mem[i][j] = max(pre, mem[i-1][j-pr] + pg);
//            }
//        }
//    }
//    cout << mem[n][x] << endl;
//    
//    return 0;
//}
