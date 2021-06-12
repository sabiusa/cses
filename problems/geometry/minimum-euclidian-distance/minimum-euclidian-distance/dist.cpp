//
//  dist.cpp
//  minimum-euclidian-distance
//
//  Created by Saba Khutsishvili on 6/11/21.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
#define ull unsigned long long

#define x first
#define y second

//bool sort_y(pair<ll, ll> a, pair<ll, ll> b) {
//    return a.y < b.y;
//}
//
//long long sq(ll a) {
//    return a * a;
//}
//
//long long dist(pair<ll, ll> a, pair<ll, ll> b) {
//    return sq(a.x - b.x) + sq(a.y - b.y);
//}
//
//long long calc(vector<pair<ll, ll>> p, vector<pair<ll, ll>> pty) {
//    ll n = (ll)p.size();
//    if (n <= 1) return 8e18;
//    vector<pair<ll, ll>> left, right, mid, lefty, righty;
//    left = vector<pair<ll, ll>> (p.begin(), p.begin() + n/2);
//    right = vector<pair<ll, ll>> (p.begin() + n/2, p.end());
//    for (auto a : pty) {
//        if (a < right[0]) lefty.push_back(a);
//        else righty.push_back(a);
//    }
//    ll ld = calc(left, lefty);
//    ll rd = calc(right, righty);
//    ll d = min(ld, rd);
//    ll midx = right[0].x;
//    for (auto a : pty) {
//        if (d > sq(a.x - midx)) {
//            mid.push_back(a);
//        }
//    }
//    ll mn = (ll)mid.size();
//    for (ll i = 0; i < mn; ++i) {
//        for (ll j = i+1; j < mn; ++j) {
//            if (d < sq(mid[j].y - mid[i].y)) break;
//            d = min(d, dist(mid[i], mid[j]));
//        }
//    }
//    return d;
//}
//
//int main() {
//    ll n, x, y;
//    
//    cin >> n;
//    vector<pair<ll, ll>> pt(n), pty;
//    for (ll i = 0; i < n; ++i) {
//        cin >> x >> y;
//        pt[i] = {x, y};
//    }
//    sort(pt.begin(), pt.end());
//    pty = pt;
//    sort(pty.begin(), pty.end(), sort_y);
//    cout << calc(pt, pty) << "\n";
//    
//    return 0;
//}
