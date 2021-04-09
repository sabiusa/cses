//
//  main.cpp
//  projects
//
//  Created by Saba Khutsishvili on 4/8/21.
//

#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
const ll INF = 1e18, MOD = 1e9+7;

int main() {
    ll n, a, b, p;

    cin >> n;
    vector<vector<ll>> v(n+1, vector<ll> (3, 0));
    for (ll i = 1; i <= n; ++i) {
        cin >> a >> b >> p;
        v[i] = {b, a, p};
    }
    sort(v.begin(), v.end());

    vector<ll> et(n);
    for (ll i = 1; i <= n; ++i) {
        et[i-1] = v[i][0]; // store sorted end dates
    }
    vector<ll> mem(n+1);
    mem[0] = 0;
    for (ll i = 1; i <= n; ++i) {
        ll id = 0;
        // find project with highest end time compared to current project's start date
        auto it = lower_bound(et.begin(), et.end(), v[i][1]);
        if (it != et.begin()) {
            id = distance(et.begin(), it);
        }
        ll pick = v[i][2] + mem[id]; // pick project, get reward
        ll no_pick = mem[i-1]; // do not pick this project
        mem[i] = max(pick, no_pick);
    }
    cout << mem[n] << "\n";

    return 0;
}
