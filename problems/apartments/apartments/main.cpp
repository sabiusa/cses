//
//  main.cpp
//  apartments
//
//  Created by Saba Khutsishvili on 3/19/21.
//

#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long

int main() {
    ll n, m, k, t;
    vector<ll> a, b;
    
    cin >> n >> m >> k;
    for (ll i = 0; i < n; ++i) {
        cin >> t;
        a.push_back(t);
    }
    for (ll i = 0; i < m; ++i) {
        cin >> t;
        b.push_back(t);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    t = 0;
    for (ll i = 0, j = 0, r = 0; i < n && j < m; ++i) {
        for (j = r; j < m; ++j) {
            ll mn = b[j] - k;
            ll mx = b[j] + k;
            if (a[i] < mn) {
                r = j;
                break;
            } else if ((a[i] >= mn) && (a[i] <= mx)) {
                r = ++j;
                ++t;
                break;
            }
        }
    }
    cout << t << "\n";
    
    return 0;
}
