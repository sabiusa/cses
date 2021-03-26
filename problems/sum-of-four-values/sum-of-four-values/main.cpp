//
//  main.cpp
//  sum-of-four-values
//
//  Created by Saba Khutsishvili on 3/25/21.
//

#include <iostream>
#include <array>
#include <algorithm>
#include <set>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
int main() {
    ll n, x;
    
    cin >> n >> x;
    array<ll, 2> arr[n];
    for (ll i = 0; i < n; ++i) {
        cin >> arr[i][0];
        arr[i][1] = i + 1;
    }
    sort(arr, arr + n);
    
    ll sn = (n * (n - 1)) / 2; // number of distinct permutaions n!/r!(n-r)!, r=2
    array<ll, 3> sums[sn];
    for (ll i = 0, k = 0; i < n - 1; ++i) {
        for (ll j = i + 1; j < n; ++j, ++k) {
            sums[k][0] = arr[i][0] + arr[j][0];
            sums[k][1] = arr[i][1];
            sums[k][2] = arr[j][1];
        }
    }
    sort(sums, sums + sn);
    
    for (ll i = 0, j = sn - 1; i < j;) {
        ll sum = sums[i][0] + sums[j][0];
        if (sum == x) {
            set<ll> st = {sums[i][1], sums[i][2], sums[j][1], sums[j][2]};
            if (st.size() == 4) {
                cout << sums[i][1] << " " << sums[i][2] << " " << sums[j][1] << " " << sums[j][2] << "\n";
                return 0;
            } else {
                --j;
                continue;
            }
        }
        if (sum > x) {
            --j;
            continue;
        }
        ++i;
    }
    
    cout << "IMPOSSIBLE" << "\n";
    
    return 0;
}
