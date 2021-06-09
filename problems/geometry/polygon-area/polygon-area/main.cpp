//
//  main.cpp
//  polygon-area
//
//  Created by Saba Khutsishvili on 6/9/21.
//

#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

#define x first
#define y second

ll n;

int main() {
    ll area = 0, x, y;
    vector<pair<ll, ll>> v;
    
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        cin >> x >> y;
        v.push_back({x, y});
    }
    v.push_back(v[0]);
    for (ll i = 0; i < n; ++i) {
        area += (v[i].x * v[i+1].y) - (v[i+1].x * v[i].y);
    }
    cout << abs(area) << "\n";
    
    return 0;
}
