//
//  money.cpp
//  money-sums
//
//  Created by Saba Khutsishvili on 4/6/21.
//

#include <iostream>
#include <vector>
#include <set>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
const ll INF = 1e18;
 
int main() {
    ll n, mx = 0;
    
    cin >> n;
    vector<ll> x(n+1);
    for (ll i = 1; i <= n; ++i) {
        cin >> x[i];
        mx += x[i];
    }
    
    vector<ll> mem(mx + 1, 0);
    set<ll> st;
    mem[0] = 1;
    for (ll i = 1; i <= n; ++i) {
        ll c = x[i]; // current coin
        for (ll j = mx; j >= c; --j) {
            if (mem[j-c]) {
                mem[j] = 1;
                st.insert(j);
            }
        }
    }
    
    cout << st.size() << "\n";
    for (ll s : st) {
        cout << s << " ";
    }
    cout << "\n";
    
    return 0;
}
