//
//  main.cpp
//  dice-probability
//
//  Created by Saba Khutsishvili on 5/16/21.
//

#include <iostream>
#include <vector>
#include <iomanip>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
#define ld long double
 
const ll N = 602, MOD = 1e9+7, INF = 2e18;

int main() {
    ll n, a, b;
    
    cin >> n >> a >> b;
    vector<vector<double>> mem(n+1, vector<double> (b+1, 0.0));
    mem[0][0] = 1.0;
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= b; ++j) {
            for (ll k = 1; k <= min(j, (ll)6); ++k) {
                mem[i][j] += mem[i-1][j-k];
            }
            mem[i][j] /= 6;
        }
    }
    double ans = 0;
    for (ll i = a; i <= b; ++i) {
        ans += mem[n][i];
    }
    cout << setprecision(6) << fixed << ans << "\n";
    
    return 0;
}
