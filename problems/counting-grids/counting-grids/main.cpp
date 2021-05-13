//
//  main.cpp
//  counting-grids
//
//  Created by Saba Khutsishvili on 5/13/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
const ll N = 1e6+2, MOD = 1e9+7;
vector<ll> pows(N);

ll expo(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b % 2) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}

ll inv(ll a) {
    return expo(a, MOD-2);
}

ll cnt90(ll n) {
    if (n % 2) {
        return (n/2 * (n/2 + 1)) + 1; // sum of all even numbers +1
    } else {
        return (n/2 * n/2); // sum of all odd numbers
    }
}

ll cnt180(ll n) {
    if (n % 2) {
        return n * (n/2) + ((n+1)/2);
    } else {
        return n * (n/2);
    }
}

/*
 0               180            90 / 270
 (4 X 4)
 * * * *     |   * * * *    |   * * * -
 * * * *     |   * * * *    |   - - * -
 * * * *     |   - - - -    |   - - - -
 * * * *     |   - - - -    |   - - - -
                           
 (5 X 5)
 * * * * *   |   * * * * *  |   * * * * -
 * * * * *   |   * * * * *  |   - - - * -
 * * * * *   |   * * * - -  |   - - * * -
 * * * * *   |   - - - - -  |   - - - - -
 * * * * *   |   - - - - -  |   - - - - -
 */

ll burnside(ll n) {
    ll s = 0;
    ll s0 = expo(2, n*n); // 0 degree rotation count
    ll s90 = expo(2, cnt90(n));
    ll s180 = expo(2, cnt180(n));
    ll s270 = s90;
    s = (((s0 + s90) % MOD + s180) % MOD + s270) % MOD;
    s = (s * inv(4)) % MOD;
    return s;
}

int main() {
    ll n;
    
    cin >> n;
    cout << burnside(n) << "\n";
    
    return 0;
}
