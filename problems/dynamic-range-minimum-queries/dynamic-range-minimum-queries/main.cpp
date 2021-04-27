//
//  main.cpp
//  dynamic-range-minimum-queries
//
//  Created by Saba Khutsishvili on 4/27/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long

const ll N = 2e5+2, INF = 1e18;
ll n;
vector<ll> seg(N);

void fill() {
    for (ll i = n-1; i > 0; --i) {
        seg[i] = min(seg[2*i], seg[2*i+1]);
    }
}

void update(ll i, ll x) {
    i = i + n; // go to index of actual value
    seg[i] = x; // update actual value
    for (i >>= 1; i; i >>= 1) {
        seg[i] = min(seg[2*i], seg[2*i+1]);
    }
}

ll query(ll a, ll b) {
    ll mn = INF;
    for (a += n, b += n; a < b; a >>= 1, b >>= 1) {
        if (a & 1) mn = min(mn, seg[a++]);
        if (b & 1) mn = min(mn, seg[--b]);
    }
    return mn;
}

int main() {
    ll q, k, a, b;
    
    cin >> n >> q;
    seg.resize(n * 2);
    seg[0] = 0;
    for (ll i = n; i < 2*n; ++i) {
        cin >> seg[i];
    }
    fill();
    while (q--) {
        cin >> k >> a >> b;
        if (k == 1) {
            update(a-1, b);
        } else {
            cout << query(a-1, b) << "\n";
        }
    }
    
    return 0;
}
