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
    ll n;
    stack<pair<ll, ll>> sk;
    
    cin >> n;
    ll arr[n + 1];
    for (ll i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    for (ll i = 1; i <= n; ++i) {
        while (!sk.empty() && sk.top().first >= arr[i]) {
            sk.pop();
        }
        if (sk.empty()) {
            cout << 0 << " ";
        } else {
            cout << sk.top().second << " ";
        }
        sk.push({arr[i], i});
    }
    cout << "\n";
    
    return 0;
}
