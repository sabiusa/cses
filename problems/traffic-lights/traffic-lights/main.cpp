//
//  main.cpp
//  traffic-lights
//
//  Created by Saba Khutsishvili on 3/21/21.
//

#include <iostream>
#include <set>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
int main() {
    ll n, x, p;
    set<ll> st;
    multiset<ll> mt;
    
    cin >> x >> n;
    st.insert(0LL);
    st.insert(x);
    mt.insert(x);
    for (ll i = 0; i < n; ++i) {
        cin >> p;
        auto r = st.upper_bound(p); // closest light to right
        auto l = r; --l; // closest light to left
        mt.erase(mt.find(*r - *l)); // delete old segment
        st.insert(p);
        mt.insert(p - *l); // add new segment
        mt.insert(*r - p); // add new segment
        auto last = --mt.end(); // biggest element is last
        cout << *last << " ";
    }
    cout << "\n";
    
    return 0;
}
