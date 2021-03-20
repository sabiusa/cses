//
//  main.cpp
//  missing-coin-sum
//
//  Created by Saba Khutsishvili on 3/20/21.
//

#include <iostream>
#include <set>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
int main() {
    ll n, r = 1;
    multiset<ll> mt;
    
    cin >> n;
    while (n--) {
        ll a;
        cin >> a;
        mt.insert(a);
    }
    for (auto it = mt.begin(); it != mt.end(); ++it) {
        if (*it > r) {
            break;
        } else {
            r += *it;
        }
    }
    cout << r << "\n";
    
    return 0;
}
