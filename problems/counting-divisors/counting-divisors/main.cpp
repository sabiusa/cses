//
//  main.cpp
//  counting-divisors
//
//  Created by Saba Khutsishvili on 5/7/21.
//

#include <iostream>
#include <vector>
#include <map>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
const ll N = 1e6+2;
vector<int> sieve(N, 1);

void fill() {
    for (ll i = 2; i < N; ++i) {
        for (ll j = i; j < N; j += i) {
            sieve[j]++;
        }
    }
}

int main() {
    int n, x;
    
    cin >> n;
    fill();
    for (int i = 0; i < n; ++i) {
        cin >> x;
        cout << sieve[x] << "\n";
    }
    
    return 0;
}
