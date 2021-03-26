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
        if (sk.empty()) {
            cout << 0 << " ";
        } else {
            while (!sk.empty()) {
                if (sk.top().first < x) {
                    cout << sk.top().second << " ";
                    goto push;
                } else {
                    sk.pop();
                }
            }
            cout << 0 << " ";
        }
push:
        sk.push({x, i});
    }
    cout << "\n";
    
    return 0;
}
