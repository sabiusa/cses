//
//  main.cpp
//  movie-festival
//
//  Created by Saba Khutsishvili on 3/20/21.
//

#include <iostream>
#include <set>

using namespace std;

#define ll long long
#define ull unsigned long long

int main() {
    ll n, r = 0, p = 0;
    multiset<pair<ll, ll>> st;
    
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        st.insert({b, a});
    }
    for (auto it = st.begin(); it != st.end(); ++it) {
        if (it->second >= p) {
            ++r;
            p = it->first;
        }
    }
    cout << r << "\n";
    
    return 0;
}
