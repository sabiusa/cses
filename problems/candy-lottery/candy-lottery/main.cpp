//
//  main.cpp
//  candy-lottery
//
//  Created by Saba Khutsishvili on 5/18/21.
//

#include <iostream>
#include <vector>
#include <iomanip>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
const ll N = 100;

int main() {
    ll n, k;
    double ans = 0;
    
    cin >> n >> k;
    for (ll i = 1; i <= k; ++i) {
        double mxi = 1, other = 1;
        for (ll j = 1; j <= n; ++j) {
            mxi *= i/(double)k;
            other *= (i-1)/(double)k;
        }
        ans += (mxi - other) * i;
    }
    cout << setprecision(6) << fixed << ans << "\n";
    
    return 0;
}
