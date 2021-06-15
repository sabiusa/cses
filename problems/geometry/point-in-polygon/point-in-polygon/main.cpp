//
//  main.cpp
//  point-in-polygon
//
//  Created by Saba Khutsishvili on 14.06.21.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
#define ull unsigned long long

struct Point {
    ll x, y;
    
    void in() {
        cin >> x >> y;
    }
    
    Point operator - (Point b) const {
        return {x - b.x, y - b.y};
    }
    
    ll operator * (Point b) const {
        return (x * b.y) - (b.x * y);
    }
    
    ll triangle(Point b, Point c) const {
        Point ca = c - *this;
        Point cb = c - b;
        return ca * cb;
    }
    
    pair<ll, ll> to_pair() const {
        return {x, y};
    }
    
    bool operator < (const Point & b) const {
        return this->to_pair() < b.to_pair();
    }
    
    bool operator == (const Point& b) const {
        return x == b.x && y == b.y;
    }
};

ll n, m;
vector<Point> pol, pt;
vector<ll> vis(1001);

bool same_points(Point a, Point b, Point c, Point d) {
    if (a == c || a == d || b == c || b == d) {
        return true;
    }
    return false;
}
 
bool same_line(Point a, Point b, Point c, Point d) {
    ll ca = a.triangle(b, c), da = a.triangle(b, d);
    if (ca == 0 && da == 0) { // on same line
        vector<pair<Point, ll>> v;
        v.push_back({a, 1});
        v.push_back({b, 1});
        v.push_back({c, 2});
        v.push_back({d, 2});
        sort(v.begin(), v.end());
        if (v[0].second != v[1].second) {
            return true;
        }
    }
    return false;
}
 
ll sign(ll n) {
    if (n > 0) return 1;
    if (n < 0) return -1;
    return 0;
}
 
bool cross(Point a, Point b, Point c, Point d) {
    ll ca = a.triangle(b, c), da = a.triangle(b, d);
    ll ac = c.triangle(d, a), bc = c.triangle(d, b);
    if ((sign(ca) != sign(da)) && (sign(ac) != sign(bc))) {
        return true;
    }
    return false;
}
 
bool intersect(Point a, Point b, Point c, Point d) {
    if (same_points(a, b, c, d) || same_line(a, b, c, d) || cross(a, b, c, d)) {
        return true;
    }
    return false;
}

bool on_boundary(Point a, Point b, Point c) {
    if (a.triangle(b, c) == 0) {
        vector<pair<Point, ll>> v;
        v.push_back({a, 1});
        v.push_back({b, 1});
        v.push_back({c, 2});
        sort(v.begin(), v.end());
        if (v[1].second == 2) {
            return true;
        }
    }
    return false;
}

int main() {
    ll x, y;
    
    cin >> n >> m;
    pol.resize(n);
    pt.resize(m);
    for (ll i = 0; i < n; ++i) {
        cin >> x >> y;
        pol[i] = {x, y};
    }
    for (ll i = 0; i < m; ++i) {
        cin >> x >> y;
        Point c = {x, y};
        ll cs = 0, bf = 0;
        for (ll i = 0; i < n; ++i) {
            ll j = i == n-1 ? 0 : i+1;
            Point a = pol[i], b = pol[j], d = {x+1, (ll)3e9+1};
            if (on_boundary(a, b, c)) {
                bf = 1;
                break;
            }
            if (intersect(c, d, a, b)) {
                cs++;
            }
        }
        if (bf) {
            cout << "BOUNDARY" << "\n";
        } else if (cs % 2) {
            cout << "INSIDE" << "\n";
        } else {
            cout << "OUTSIDE" << "\n";
        }
    }
    
    return 0;
}
