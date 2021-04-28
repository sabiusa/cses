//
//  main.cpp
//  hotel-queries
//
//  Created by Saba Khutsishvili on 4/28/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long

const ll INF = 1e18;
ll n;
vector<ll> seg;

void fill() {
    for (ll i = n-1; i > 0; --i) {
        seg[i] = max(seg[2*i], seg[2*i+1]);
    }
}

void update(ll i, ll x) {
    i += n;
    seg[i] -= x;
    for (i >>= 1; i > 0; i >>= 1) {
        seg[i] = max(seg[2*i], seg[2*i+1]);
    }
}

ll query(ll a, ll b) {
    ll mx = -INF;
    for (a += n, b += n; a < b; a >>= 1, b >>= 1) {
        if (a & 1) mx = max(mx, seg[a++]);
        if (b & 1) mx = max(mx, seg[--b]);
    }
    return mx;
}

int main() {
    ll q, k;

    cin >> n >> q;
    seg.resize(2*n);
    for (ll i = n; i < 2*n; ++i) {
        cin >> seg[i];
    }
    fill();
    while (q--) {
        cin >> k;
        ll l = 0, r = n-1;
        if (n == 1) {
            if (k > seg[1]) {
                l = -1;
            } 
        } else {
            while (l < r) {
                ll m = l+(r-l)/2;
                if (query(l, m+1) >= k) {
                    r = m;
                } else if (query(m, r+1) >= k) {
                    l = m+1;
                } else {
                    l = -1;
                    break;
                }
            }
        }
        if (l == -1) {
            cout << 0 << " ";
        } else {
            cout << l+1 << " ";
            update(l, k);
        }
    }
    cout << "\n";
    
    return 0;
}
