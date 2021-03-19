//
//  main.cpp
//  ferris-wheel
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
    ll n, x, w, r = 0;
    vector<ll> p;
    
    cin >> n >> x;
    for (ll i = 0; i < n; ++i) {
        cin >> w;
        p.push_back(w);
    }
    sort(p.begin(), p.end());
    for (ll i = 0, j = n - 1;
         i <= j;
         --j, ++r)
    {
        if (p[i] + p[j] <= x) {
            ++i;
        }
    }
    cout << r << "\n";
    
    return 0;
}
