//
//  main.cpp
//  exponentiation
//
//  Created by Saba Khutsishvili on 5/6/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long

const ll MOD = 1e9+7;

ll expo(ll a, ll b, ll m) {
    if (b == 0) return 1;
    ll temp = expo(a, b/2, m) % m;
    ll res = (temp * temp) % m;
    if (b % 2) res = (res * a) % m;
    return res;
}

ll expo_it(ll a, ll b, ll m) {
    ll res = 1;
    while (b) {
        if (b % 2) res = (res * a) % m;
        a = (a * a) % m;
        b /= 2;
    }
    return res;
}

int main() {
    ll n, a, b;
    
    cin >> n;
    while (n--) {
        cin >> a >> b;
        cout << expo_it(a, b, MOD) << "\n";
    }
    
    return 0;
}
