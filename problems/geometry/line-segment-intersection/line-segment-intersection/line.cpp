//
//  line.cpp
//  line-segment-intersection
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

Point a, b, c, d;

bool same_points() {
    if (a == c || a == d || b == c || b == d) {
        return true;
    }
    return false;
}

bool same_line() {
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

bool cross() {
    ll ca = a.triangle(b, c), da = a.triangle(b, d);
    ll ac = c.triangle(d, a), bc = c.triangle(d, b);
    if ((sign(ca) != sign(da)) && (sign(ac) != sign(bc))) {
        return true;
    }
    return false;
}

string check() {
    if (same_points() || same_line() || cross()) {
        return "YES";
    }
    return "NO";
}

int main() {
    ll t;
    
    cin >> t;
    while (t--) {
        a.in();
        b.in();
        c.in();
        d.in();
        cout << check() << "\n";
    }
    
    return 0;
}
