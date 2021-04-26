//
//  main.cpp
//  static-range-sum-queries
//
//  Created by Saba Khutsishvili on 4/26/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long

const ll N = 2e5+2;
vector<ll> x(N, 0), sum(N, 0);

int main() {
    ll n, q, a, b;
    
    cin >> n >> q;
    for (ll i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for (ll i = 1; i <= n; ++i) {
        sum[i] = sum[i-1] + x[i];
    }
    while (q--) {
        cin >> a >> b;
        cout << sum[b] - sum[a-1] << "\n";
    }
    
    return 0;
}
