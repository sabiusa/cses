//
//  main.cpp
//  meet-in-the-middle
//
//  Created by Saba Khutsishvili on 12.07.21.
//

#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long

ll n, x, m;
vector<ll> vl, vr, suml, sumr;

void calc_sums() {
    for (ll i = 0; i < (1 << m); ++i) {
        ll sum = 0;
        for (ll j = 0; j < m; ++j) {
            if (i & (1 << j)) {
                sum += vl[j];
            }
        }
        suml.push_back(sum);
    }
    for (ll i = 0; i < (1 << (n-m)); ++i) {
        ll sum = 0;
        for (ll j = 0; j < (n-m); ++j) {
            if (i & (1 << j)) {
                sum += vr[j];
            }
        }
        sumr.push_back(sum);
    }
}

int main() {
    ll a, ans = 0;
    
    cin >> n >> x;
    m = n/2;
    for (ll i = 0; i < m; ++i) {
        cin >> a;
        vl.push_back(a);
    }
    for (ll i = m; i < n; ++i) {
        cin >> a;
        vr.push_back(a);
    }
    calc_sums();
    sort(suml.begin(), suml.end());
    for (ll i = 0; i < (ll)sumr.size(); ++i) {
        ll d = x - sumr[i];
        if (d >= 0) {
            auto itl = lower_bound(suml.begin(), suml.end(), d);
            auto itu = upper_bound(suml.begin(), suml.end(), d);
            ans += (itu - itl);
        }
    }
    cout << ans << "\n";
    
    return 0;
}
