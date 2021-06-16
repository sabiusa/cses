//
//  main.cpp
//  polygon-lattice-points
//
//  Created by Saba Khutsishvili on 15.06.21.
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

ll n;
vector<Point> pol;

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll boundary() {
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        ll j = i == n-1 ? 0 : i+1;
        Point a = pol[i], b = pol[j], d = b - a;
        if (d.x == 0) ans += abs(d.y);
        else if (d.y == 0) ans += abs(d.x);
        else ans += gcd(abs(d.x), abs(d.y));
    }
    return ans;
}

ll area() {
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        ll j = i == n-1 ? 0 : i+1;
        Point a = pol[i], b = pol[j];
        ans += a * b;
    }
    return ans;
}

ll interior(ll b) { // Pick's theorem. A = i + b/2 - 1 => i = A - b/2 + 1
    ll a2 = abs(area()); // area * 2 => 2*i = 2*A - b + 2
    return (a2 - b + 2) / 2;
}

int main() {
    ll x, y;
    
    cin >> n;
    pol.resize(n);
    for (ll i = 0; i < n; ++i) {
        cin >> x >> y;
        pol[i] = {x, y};
    }
    ll b = boundary();
    ll i = interior(b);
    cout << i << " " << b << "\n";
    
    return 0;
}
