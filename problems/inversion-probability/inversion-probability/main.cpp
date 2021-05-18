//
//  main.cpp
//  inversion-probability
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
vector<ll> r;

double calc(ll n) {
    double ans = 0;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < i; j++) {
            double m = 0;
            if (r[j] <= r[i]) {
                m = (double)(r[j] * (r[j]-1)) / 2; // r[j] choose 2
            } else {
                m = (double)(r[i] * (r[i]-1)) / 2;
                m += (double)(r[j]-r[i]) * r[i];
            }
            ans += m / (r[i] * r[j]);
        }
    }
    return ans;
}

int main() {
    ll n;
    
    cin >> n;
    r.resize(n);
    for (ll i = 0; i < n; ++i) {
        cin >> r[i];
    }
    cout << setprecision(6) << fixed << calc(n) << "\n";
    
    return 0;
}
