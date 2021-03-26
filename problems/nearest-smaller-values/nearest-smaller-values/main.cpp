//
//  main.cpp
//  nearest-smaller-values
//
//  Created by Saba Khutsishvili on 3/26/21.
//

#include <iostream>
#include <stack>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
int main() {
    ll n, x;
    stack<pair<ll, ll>> sk;
    
    cin >> n;
    for (ll i = 1; i <= n; ++i) {
        cin >> x;
        while (!sk.empty() && sk.top().first >= x) {
            sk.pop();
        }
        if (sk.empty()) {
            cout << 0 << " ";
        } else {
            cout << sk.top().second << " ";
        }
        sk.push({x, i});
    }
    cout << "\n";
    
    return 0;
}
