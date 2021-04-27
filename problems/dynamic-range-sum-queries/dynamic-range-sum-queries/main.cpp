//
//  main.cpp
//  dynamic-range-sum-queries
//
//  Created by Saba Khutsishvili on 4/27/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long

const ll N = 2e5+2;
vector<ll> fen(N, 0), orig(N, 0);

void add(ll i, ll x, ll n) {
    while (i <= n) {
        fen[i] += x;
        i += i & (-i); // add last set bit
    }
}

void update(ll i, ll x, ll n) {
    ll dif = x - orig[i];
    orig[i] = x;
    add(i, dif, n);
}

ll sum(ll i) {
    ll sum = 0;
    while (i) {
        sum += fen[i];
        i -= i & (-i); // remove last set bit
    }
    return sum;
}

ll query(ll a, ll b) {
    return sum(b) - sum(a-1);
}

int main() {
    ll n, q, k, a, b;
    
    cin >> n >> q;
    for (ll i = 1; i <= n; ++i) {
        cin >> orig[i];
    }
    for (ll i = 1; i <= n; ++i) {
        add(i, orig[i], n);
    }
    while (q--) {
        cin >> k >> a >> b;
        if (k == 1) {
            update(a, b, n);
        } else {
            cout << query(a, b) << "\n";
        }
    }
    
    return 0;
}
