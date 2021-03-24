//
//  room.cpp
//  room-allocation
//
//  Created by Saba Khutsishvili on 3/23/21.
//

#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
int main() {
    ll n, a, b;
    
    cin >> n;
    vector<pair<ll, pair<ll, ll>>> v;
    for (ll i = 1; i <= n; ++i) {
        cin >> a >> b;
        v.push_back({a, {-1, i}}); // arrival
        v.push_back({b, {1, i}}); // departure
    }
    sort(v.begin(), v.end());
    
    vector<ll> rooms;
    ll oc = 0, mx = 0;
    ll ans[(int)2e5];
    for (auto g : v) {
        ll st = g.second.first; // status
        ll oo = g.second.second; // original index
        if (st == 1) { // departure
            rooms.push_back(ans[oo]);
        } else { // arrival of new
            if (oc == rooms.size()) {
                ans[oo] = ++mx; // customer needs new room
            } else {
                ans[oo] = rooms[oc++]; // give free room
            }
        }
    }
    
    cout << mx << "\n";
    for (ll i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    
    return 0;
}
