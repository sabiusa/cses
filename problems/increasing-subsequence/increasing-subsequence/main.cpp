//
//  main.cpp
//  increasing-subsequence
//
//  Created by Saba Khutsishvili on 4/7/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
int main() {
    ll n, x;
    
    cin >> n;
    vector<ll> mem;
    for (ll i = 0; i < n; ++i) {
        cin >> x;
        auto it = lower_bound(mem.begin(), mem.end(), x);
        if (it == mem.end()) {
            mem.push_back(x);
        } else {
            *it = x;
        }
    }
    cout << mem.size() << "\n";
    
    return 0;
}
