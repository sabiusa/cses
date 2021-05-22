//
//  main.cpp
//  grundy's-game
//
//  Created by Saba Khutsishvili on 5/22/21.
//

#include <iostream>
#include <vector>
#include <unordered_set>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
const ll N = 2e3;
vector<ll> mem(N);

ll mex(vector<ll> &v) {
    unordered_set<ll> st;
    st.reserve(N);
    for (auto a : v) {
        st.insert(a);
    }
    for (ll i = 0; i < N; ++i) {
        if (st.count(i) == 0)
            return i;
    }
    return 0;
}

void fill() {
    for (ll i = 3; i < N; ++i) {
        ll h = i/2;
        if (i%2 == 0) h--;
        vector<ll> v;
        for (ll j = 1; j <= h; ++j) {
            v.push_back(mem[j] ^ mem[i-j]);
        }
        mem[i] = mex(v);
    }
}

int main() {
    ll t, n;
    
    cin >> t;
    fill();
    while (t--) {
        cin >> n;
        if (n >= N) cout << "first" << "\n";
        else if (mem[n]) cout << "first" << "\n";
        else cout << "second" << "\n";
    }
    
    return 0;
}
