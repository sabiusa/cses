//
//  main.cpp
//  concert-tickets
//
//  Created by Saba Khutsishvili on 3/19/21.
//

#include <iostream>
#include <set>

using namespace std;

#define ll long long
#define ull unsigned long long

int main() {
    ll n, m, w;
    multiset<ll> h;
    
    cin >> n >> m;
    for (ll i = 0; i < n; ++i) {
        cin >> w;
        h.insert(w);
    }
    for (ll i = 0; i < m; ++i) {
        cin >> w;
        auto it = h.upper_bound(w);
        if (it == h.begin()) {
            cout << "-1" << endl;
        } else {
            --it;
            cout << *it << endl;
            h.erase(it);
        }
    }
    
    return 0;
}
