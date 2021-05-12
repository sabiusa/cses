//
//  main.cpp
//  christmas-party
//
//  Created by Saba Khutsishvili on 5/11/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
const ll N = 1e6+2, MOD = 1e9+7;
vector<ll> mem(N);

void derange() {
    mem[1] = 0; mem[2] = 1;
    for (ll i = 3; i < N; ++i) {
        mem[i] = (((i-1) * mem[i-1] % MOD) + ((i-1) * mem[i-2] % MOD)) % MOD;
    }
}

int main() {
    ll n;
    
    cin >> n;
    derange();
    cout << mem[n] << "\n";
    
    return 0;
}
