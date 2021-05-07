//
//  main.cpp
//  common-divisors
//
//  Created by Saba Khutsishvili on 5/7/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
const ll N = 1e6+2;
vector<ll> nums(N, 0), divs(N, 0);

ll gcd() {
    ll gcd = 1;
    for (ll i = 2; i < N; ++i) {
        for (ll j = i; j < N; j += i) {
            if (nums[j]) {
                divs[i] += nums[j];
                if (divs[i] > 1) {
                    gcd = max(gcd, i);
                }
            }
        }
    }
    return gcd;
}

int main() {
    ll n, x;
    
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        cin >> x;
        nums[x]++;
    }
    cout << gcd() << "\n";
    
    return 0;
}
