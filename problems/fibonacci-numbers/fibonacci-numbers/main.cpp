//
//  main.cpp
//  fibonacci-numbers
//
//  Created by Saba Khutsishvili on 5/14/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
const ll N = 1e6+2, MOD = 1e9+7;
vector<vector<ll>> tr(2, vector<ll>(2)), id(2, vector<ll> (2)), fib(1, vector<ll>(2));

void fill_tran() { // transition matrix
    tr[0][0] = 0; // |F1, F2| * |A B| = |F2 F3|
    tr[0][1] = 1; //            |C D|
    tr[1][0] = 1; // F1*A + F2*C = F2 => A = 0, C = 1
    tr[1][1] = 1; // F1*B + F2*D = F3 => B = 1, D = 1 (fib(3) = fib(2) + fib(1))
}

void fill_iden() { // identity matrix
    id[0][0] = 1; // |1 0|
    id[0][1] = 0; // |0 1|
    id[1][0] = 0;
    id[1][1] = 1;
}

void fill_fib() {
    fib[0][0] = 1;
    fib[0][1] = 1;
}

void mult(vector<vector<ll>> &m1, vector<vector<ll>> &m2) {
    vector<vector<ll>> res(2, vector<ll> (2, 0));
    for (ull i = 0; i < m1.size(); ++i) {
        for (ull j = 0; j < m1[0].size(); ++j) {
            res[i][j] = 0;
            for (ull k = 0; k < m1.size(); ++k) {
                ll r = (m1[i][k] * m2[k][j]) % MOD;
                res[i][j] = (res[i][j] + r) % MOD;
            }
        }
    }
    m1 = res;
}

void expo_tran(ll n) {
    while (n) {
        if (n % 2) mult(id, tr);
        mult(tr, tr);
        n /= 2;
    }
}

ll calc_fib(ll n) {
    if (n == 0) {
        return 0;
    } else if (n < 3) {
        return 1;
    } else {
        expo_tran(n);
        mult(fib, id);
        return fib[0][1];
    }
}

int main() {
    ll n;
    
    cin >> n;
    fill_tran();
    fill_iden();
    fill_fib();
    cout << calc_fib(n) << "\n";
    
    return 0;
}
