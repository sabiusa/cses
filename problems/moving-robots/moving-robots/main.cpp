//
//  main.cpp
//  moving-robots
//
//  Created by Saba Khutsishvili on 5/17/21.
//

#include <iostream>
#include <vector>
#include <array>
#include <iomanip>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
const ll N = 8;
vector<vector<ll>> cnt(N, vector<ll> (N, 4));
vector<vector<double>> ans(N, vector<double> (N, 1));

void fill_cnt() { // neighbour counts
    for (ll i = 0; i < N; ++i) {
        for (ll j = 0; j < N; ++j) {
            if (i == 0 || i == 7) cnt[i][j]--;
            if (j == 0 || j == 7) cnt[i][j]--;
        }
    }
}

vector<vector<double>> kth_pass(vector<vector<double>> &path) {
    vector<vector<double>> res(N, vector<double> (N));
    for (ll i = 0; i < N; ++i) {
        for (ll j = 0; j < N; ++j) {
            double nc = cnt[i][j]; // neighbour count
            double p = path[i][j] / nc; // probability of going from here
            if (i != 0) res[i-1][j] += p;
            if (i != 7) res[i+1][j] += p;
            if (j != 0) res[i][j-1] += p;
            if (j != 7) res[i][j+1] += p;
        }
    }
    return res;
}

void calc_paths(ll n) {
    for (ll x = 0; x < N; ++x) {
        for (ll y = 0; y < N; ++y) {
            vector<vector<double>> path(N, vector<double> (N));
            path[x][y] = 1;
            for (ll k = 0; k < n; ++k) {
                path = kth_pass(path);
            }
            for (ll i = 0; i < N; ++i) {
                for (ll j = 0; j < N; ++j) {
                    ans[i][j] *= (1 - path[i][j]);
                }
            }
        }
    }
}

double calc() {
    double res = 0;
    for (ll i = 0; i < N; ++i) {
        for (ll j = 0; j < N; ++j) {
            res += ans[i][j];
        }
    }
    return res;
}

int main() {
    ll k;
    
    cin >> k;
    fill_cnt();
    calc_paths(k);
    cout << setprecision(6) << fixed << calc() << "\n";
    
    return 0;
}
