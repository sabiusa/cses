//
//  main.cpp
//  convex-hull
//
//  Created by Saba Khutsishvili on 13.06.21.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
#define ull unsigned long long

#define x first
#define y second

ll pos(pair<ll, ll> &a, pair<ll, ll> &b, pair<ll, ll> &c) {
    pair<ll, ll> ca, cb;
    ca = {c.x - a.x, c.y - a.y};
    cb = {c.x - b.x, c.y - b.y};
    return (ca.x * cb.y) - (cb.x * ca.y);
}

int main() {
    ll n, x, y;
    
    cin >> n;
    vector<pair<ll, ll>> pt(n), hull;
    for (ll i = 0; i < n; ++i) {
        cin >> x >> y;
        pt[i] = {x, y};
    }
    sort(pt.begin(), pt.end());
    for (ll i = 0; i < 2; ++i) {
        ll hs = (ll)hull.size();
        for (auto b : pt) {
            while ((ll)hull.size() - hs > 1) {
                auto a = *(hull.end() - 2);
                auto c = *(hull.end() - 1);
                if (pos(a, b, c) <= 0) break; // C is on left of AB or on it, so it's good
                hull.pop_back();
            }
            hull.push_back(b);
        }
        hull.pop_back(); // next ietration will add it back
        reverse(pt.begin(), pt.end());
    }
    cout << (ll)hull.size() << "\n";
    for (auto a : hull) {
        cout << a.x << " " << a.y << "\n";
    }
    
    return 0;
}
