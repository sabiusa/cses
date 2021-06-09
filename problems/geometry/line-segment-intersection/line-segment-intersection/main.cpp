//
//  main.cpp
//  line-segment-intersection
//
//  Created by Saba Khutsishvili on 6/8/21.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
#define ull unsigned long long

#define x first
#define y second

pair<ll, ll> a, b, c, d;
pair<ll, ll> ca, cb, da, db;

bool common_vertex() {
    if ((a == c) || (a == d) || (b == c) || (b == d)) {
        return true;
    }
    return false;
}

bool same_line() {
    ca = {c.x - a.x, c.y - a.y};
    cb = {c.x - b.x, c.y - b.y};
    da = {d.x - a.x, d.y - a.y};
    db = {d.x - b.x, d.y - b.y};
    ll cpc = (ca.x * cb.y) - (cb.x * ca.y);
    ll cpd = (da.x * db.y) - (db.x * da.y);
    if (cpc == 0 && cpd == 0) {
        vector<pair<pair<ll, ll>, ll>> p;
        p.push_back({a, 1});
        p.push_back({b, 1});
        p.push_back({c, 2});
        p.push_back({d, 2});
        sort(p.begin(), p.end());
        if (p[0].second != p[1].second) {
            return true;
        }
    }
    return false;
}

bool diff_sign(ll a, ll b) {
    ll as = 0, bs = 0;
    if (a > 0) as = 1;
    if (a < 0) as = -1;
    if (b > 0) bs = 1;
    if (b < 0) bs = -1;
    return as != bs;
}

bool intersect() {
    pair<ll, ll> bc, bd, ac, ad;
    
    ca = {c.x - a.x, c.y - a.y};
    cb = {c.x - b.x, c.y - b.y};
    da = {d.x - a.x, d.y - a.y};
    db = {d.x - b.x, d.y - b.y};
    ll cpc = (ca.x * cb.y) - (cb.x * ca.y);
    ll cpd = (da.x * db.y) - (db.x * da.y);
    
    ac = {a.x - c.x, a.y - c.y};
    ad = {a.x - d.x, a.y - d.y};
    bc = {b.x - c.x, b.y - c.y};
    bd = {b.x - d.x, b.y - d.y};
    ll cpa = (ac.x * ad.y) - (ad.x * ac.y);
    ll cpb = (bc.x * bd.y) - (bd.x * bc.y);
    
    return diff_sign(cpc, cpd) && diff_sign(cpa, cpb);
}

string check() {
    if (common_vertex() || same_line() || intersect()) {
        return "YES";
    }
    return "NO";
}

int main() {
    ll t;
    
    cin >> t;
    while (t--) {
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
        cout << check() << "\n";
    }
    
    return 0;
}
