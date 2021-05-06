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

int main() {
    ll n, a, b;
    
    cin >> n;
    while (n--) {
        cin >> a >> b;
        cout << expo(a, b, MOD) << "\n";
    }
    
    return 0;
}
