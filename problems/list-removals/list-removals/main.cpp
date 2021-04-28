//
//  main.cpp
//  list-removals
//
//  Created by Saba Khutsishvili on 4/28/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long

ll n;
vector<ll> seg, orig, rem;

void fill() {
    for (ll i = n-1; i > 0; --i) {
        seg[i] = seg[i*2] + seg[i*2+1];
    }
}

void update(ll i) {
    i += n;
    seg[i] = 0;
    for (i >>= 1; i > 0; i >>= 1) {
        seg[i] = seg[i*2] + seg[i*2+1];
    }
}

ll query(ll a, ll b) {
    ll sum = 0;
    for (a += n, b += n; a < b; a >>= 1, b >>= 1) {
        if (a & 1) sum += seg[a++];
        if (b & 1) sum += seg[--b];
    }
    return sum;
}

int main() {
    ll k;
    
    cin >> n;
    seg.resize(n*2);
    orig.resize(n+1);
    rem.resize(n+1);
    for (ll i = 1; i <= n; ++i) {
        cin >> k;
        orig[i] = k;
        seg[i+n-1] = 1;
        rem[i] = 0;
    }
    fill();
    ll q = n;
    while (q--) {
        cin >> k;
        ll l = k-1; ll r = n;
        while (l < r) {
            ll m = l + (r-l)/2;
            ll a = query(0, m+1);
            if (a > k) {
                r = m;
            } else if (a < k) {
                l = m + 1;
            } else {
                if (rem[m] == 0) {
                    l = m;
                    break;
                } else {
                    r = m - 1;
                }
            }
        }
        rem[l] = 1;
        update(l);
        cout << orig[l+1] << " ";
    }
    cout << "\n";
    
    return 0;
}
