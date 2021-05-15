//
//  main.cpp
//  throwing-dice
//
//  Created by Saba Khutsishvili on 5/14/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
const ll N = 1e6+2, MOD = 1e9+7;
vector<vector<ll>> tr(6, vector<ll>(6)), id(6, vector<ll> (6));

void fill_tran() {                  // | 0 1 0 0 0 0 |
    for(ll i = 0; i < 5; ++i) {     // | 0 0 1 0 0 0 |
        tr[i][i + 1] = 1;           // | 0 0 0 1 0 0 |
    }                               // | 0 0 0 0 1 0 |
    for(ll i = 0; i < 6; ++i) {     // | 0 0 0 0 0 1 |
        tr[5][i] = 1;               // | 1 1 1 1 1 1 |
    }
}

void fill_ident() { // identity matrix
    for (ll i = 0; i < 6; ++i) {
        id[i][i] = 1;
    }
}

vector<vector<ll>> mult(vector<vector<ll>> x, vector<vector<ll>> y) {
    vector<vector<ll>> res(6, vector<ll>(6));
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            for (int k = 0; k < 6; ++k) {
                ll m = (x[i][k] * y[k][j]) % MOD;
                res[i][j] = (res[i][j] + m) % MOD;
            }
        }
    }
    return res;
}

vector<vector<ll>> expo_tran(ll n) {
    auto res = id;
    while (n) {
        if (n % 2) res = mult(tr, res);
        tr = mult(tr, tr);
        n /= 2;
    }
    return res;
}

ll calc(ll n) {
    auto dice = expo_tran(n);
    return dice[5][5];
}

int main() {
    ll n;

    cin >> n;
    fill_tran();
    fill_ident();
    cout << calc(n) << "\n";

    return 0;
}
