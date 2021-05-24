//
//  main.cpp
//  josephus-queries
//
//  Created by Saba Khutsishvili on 5/23/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
const ll N = 1e5;

ll calc(ll n, ll k) {
    if (n <= 1) return 1;
    if (k <= (n+1)/2) {
        if (2*k > n) {
            return 2*k % n;
        }
        else return 2*k;
    }
    ll m = calc(n/2, k - (n+1)/2);
    if (n % 2) return 2*m + 1;
    else return 2*m - 1;
}

int main() {
    ll q, n, k;
    
    cin >> q;
    while (q--) {
        cin >> n >> k;
        cout << calc(n, k) << "\n";
    }
    
    return 0;
}
