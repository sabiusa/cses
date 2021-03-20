//
//  main.cpp
//  restaurant-customers
//
//  Created by Saba Khutsishvili on 3/20/21.
//

#include <iostream>
#include <set>

using namespace std;

#define ll long long
#define ull unsigned long long

int main() {
    ll n, r = 0, mx = 0;
    set<pair<ll, ll>> st;
    
    cin >> n;
    while (n--) {
        ll a, b;
        cin >> a >> b;
        st.insert(make_pair(a, 1));
        st.insert(make_pair(b, -1));
    }
    for (auto it = st.begin(); it != st.end(); ++it) {
        r += it->second;
        mx = max(mx, r);
    }
    cout << mx << "\n";
    
    return 0;
}
