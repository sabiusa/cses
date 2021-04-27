//
//  main.cpp
//  range-update-queries
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
    for (ll i = 0; i < n; ++i) {
        seg[i] = 0;
    }
}

void update(ll a, ll b, ll x) {
    for (a += n, b += n; a < b; a >>= 1, b >>= 1) {
        if (a & 1) seg[a++] += x;
        if (b & 1) seg[--b] += x;
    }
}

ll query(ll a) {
    ll ans = 0;
    for (a += n; a > 0; a >>= 1) {
        ans += seg[a];
    }
    return ans;
}

int main() {
    ll q, k, a, b, u;
    
    cin >> n >> q;
    seg.resize(2*n);
    for (ll i = n; i < 2*n; ++i) {
        cin >> seg[i];
    }
    while (q--) {
        cin >> k;
        if (k == 1) {
            cin >> a >> b >> u;
            update(a-1, b, u);
        } else {
            cin >> a;
            cout << query(a-1) << "\n";
        }
    }
    
    return 0;
}
