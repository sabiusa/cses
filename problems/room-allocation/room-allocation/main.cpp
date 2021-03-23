//
//  main.cpp
//  room-allocation
//
//  Created by Saba Khutsishvili on 3/22/21.
//

#include <iostream>
#include <array>
#include <set>
#include <algorithm>
#include <string.h>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
int main() {
    ll n, a, b;
    
    cin >> n;
    ll ans[n];
    array<ll, 3> arr[n];
    memset(ans, 0, sizeof(ans));
    memset(arr, 0, sizeof(arr));
    
    for (ll i = 0; i < n; ++i) {
        cin >> a >> b;
        arr[i][0] = b; // departure
        arr[i][1] = a; // arrival
        arr[i][2] = i; // original order
    }
    sort(arr, arr + n); // sort by departure
    
    set<array<ll, 2>> st;
    for (ll i = 0; i < n; ++i) {
        ll dp = arr[i][0]; // departure time
        ll at = arr[i][1]; // arrival time
        ll oo = arr[i][2]; // original order
        auto it = st.lower_bound({at});
        if (it == st.begin()) {
            ans[oo] = st.size();
        } else {
            --it;
            ans[oo] = (*it)[1];
            st.erase(it);
        }
        st.insert({dp, ans[oo]});
    }
    
    cout << st.size() << "\n";
    for (ll i = 0; i < n; ++i) {
        cout << ans[i] + 1 << " ";
    }
    cout << "\n";
    
    return 0;
}
