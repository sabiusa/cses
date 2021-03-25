//
//  main.cpp
//  sum-of-three-values
//
//  Created by Saba Khutsishvili on 3/24/21.
//

#include <iostream>
#include <array>
#include <algorithm>
 
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
    
    for (ll i = 0; i < n; ++i) {
        ll m = x - arr[i][0];
        for (ll j = i + 1, k = n; j < k;) {
            if (j < k && arr[j][0] + arr[k][0] > m) {
                --k;
                continue;
            }
            if (arr[j][0] + arr[k][0] == m) {
                cout << arr[i][1] << " " << arr[j][1] << " " << arr[k][1] << "\n";
                return 0;
            }
            ++j;
        }
    }
    cout << "IMPOSSIBLE" << "\n";
    
    return 0;
}
