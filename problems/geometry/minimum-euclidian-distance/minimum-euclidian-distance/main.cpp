//
//  main.cpp
//  minimum-euclidian-distance
//
//  Created by Saba Khutsishvili on 6/10/21.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
#define ull unsigned long long

#define x first
#define y second

bool sort_x(pair<ll, ll> a, pair<ll, ll> b) {
    return a.x < b.x;
}

bool sort_y(pair<ll, ll> a, pair<ll, ll> b) {
    return a.y < b.y;
}

long long sq(ll a) {
    return a * a;
}

long long dist(pair<ll, ll> a, pair<ll, ll> b) {
    return sq(a.x - b.x) + sq(a.y - b.y);
}

long long calc(vector<pair<ll, ll>> p) {
    ll n = (ll)p.size();
    if (n <= 1) return 8e18;
    vector<pair<ll, ll>> left, right, mid;
    left = vector<pair<ll, ll>> (p.begin(), p.begin() + n/2);
    right = vector<pair<ll, ll>> (p.begin() + n/2, p.end());
    ll ld = calc(left);
    ll rd = calc(right);
    ll d = min(ld, rd);
    ll midx = right[0].x;
    for (auto a : left) {
        if (d > sq(a.x - midx)) {
            mid.push_back(a);
        }
    }
    for (auto a : right) {
        if (d > sq(a.x - midx)) {
            mid.push_back(a);
        }
    }
    sort(mid.begin(), mid.end(), sort_y);
    ll mn = (ll)mid.size();
    for (ll i = 0; i < mn; ++i) {
        for (ll j = i+1; j < mn; ++j) {
            if (d < sq(mid[j].y - mid[i].y)) break;
            d = min(d, dist(mid[i], mid[j]));
        }
    }
    return d;
}

int main() {
    ll n, x, y;
    
    cin >> n;
    vector<pair<ll, ll>> pt(n);
    for (ll i = 0; i < n; ++i) {
        cin >> x >> y;
        pt[i] = {x, y};
    }
    sort(pt.begin(), pt.end(), sort_x);
    cout << calc(pt) << "\n";
    
    return 0;
}
