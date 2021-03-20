//
//  main.cpp
//  stick-lengths
//
//  Created by Saba Khutsishvili on 3/20/21.
//

#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
int main() {
    ll n, r = 0;
    vector<ll> v;
    
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    ll m = v[n / 2];
    for (ll i = 0; i < n; ++i) {
        r += abs(m - v[i]);
    }
    cout << r << "\n";
    
    return 0;
}
