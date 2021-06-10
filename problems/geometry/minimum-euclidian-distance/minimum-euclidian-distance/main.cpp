//
//  main.cpp
//  minimum-euclidian-distance
//
//  Created by Saba Khutsishvili on 6/10/21.
//

#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

#define x first
#define y second

int main() {
    ll n, x, y;
    
    cin >> n;
    vector<pair<ll, ll>> pt(n);
    for (ll i = 0; i < n; ++i) {
        cin >> x >> y;
        pt[i] = {x, y};
    }
    cout << "\n";
    
    return 0;
}
