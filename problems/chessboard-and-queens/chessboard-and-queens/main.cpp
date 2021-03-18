//
//  main.cpp
//  chessboard-and-queens
//
//  Created by Saba Khutsishvili on 3/17/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long

ll n = 8;
vector<vector<ll>> b(n, vector<ll> (n, 0)); // board
vector<ll> cols;
vector<vector<ll>> res;

bool attack(ll x1, ll y1, ll x2, ll y2) {
    if ((x1 == x2) ||
        (y1 == y2) ||
        (x1 + y1) == (x2 + y2) ||
        (abs(x1 - x2) == abs(y1 - y2)))
    {
        return true;
    }
    return false;
}

bool can_add(ll row, ll qc) {
    if (b[row][qc] == 0) {
        return false;
    }
    for (ull i = 0; i < cols.size(); ++i) {
        if (attack(row, qc, i, cols[i])) {
            return false;
        }
    }
    return true;
}

void backtrack(ll row) {
    if (row == n) {
        res.push_back(cols);
    } else {
        for (ll qc = 0; qc < n; ++qc) {
            if (can_add(row, qc)) {
                cols.push_back(qc);
                backtrack(row + 1);
                cols.pop_back();
            }
        }
    }
}
 
int main() {
    char c;
    
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            cin >> c;
            b[i][j] = c == '.' ? 1 : 0;
        }
    }
    backtrack(0);
    cout << res.size() << "\n";
        
    return 0;
}
