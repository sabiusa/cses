//
//  main.cpp
//  range-xor-queries
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
        seg[i] = seg[2*i] ^ seg[2*i+1];
    }
}

ll query(ll a, ll b) {
    ll sum = 0;
    for (a += n, b += n; a < b; a >>= 1, b >>= 1) {
        if (a & 1) sum ^= seg[a++];
        if (b & 1) sum ^= seg[--b];
    }
    return sum;
}

int main() {
    ll q, a, b;
    
    cin >> n >> q;
    seg.resize(n*2);
    seg[0] = 0;
    for (ll i = n; i < n*2; ++i) {
        cin >> seg[i];
    }
    fill();
    while (q--) {
        cin >> a >> b;
        cout << query(a-1, b) << "\n";
    }
    
    return 0;
}
