//
//  main.cpp
//  exponentiation-II
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
    ll res = 1;
    while (b) {
        if (b % 2) res = (res * a) % m;
        a = (a * a) % m;
        b /= 2;
    }
    return res;
}

ll expo(ll a, ll b, ll c, ll m) {
    ll e = expo(b, c, m-1);
    return expo(a, e, m);
}

int main() {
    ll n, a, b, c;
    
    cin >> n;
    while (n--) {
        cin >> a >> b >> c;
        cout << expo(a, b, c, MOD) << "\n";
    }
    
    return 0;
}
