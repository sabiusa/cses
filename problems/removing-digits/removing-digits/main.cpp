//
//  main.cpp
//  removing-digits
//
//  Created by Saba Khutsishvili on 4/2/21.
//

#include <iostream>
#include <set>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long

const ll INF = 1e18, MOD = 1e9+7, N = 1e6+1;

int main() {
    ll n, ans = 0;
    set<ll> st;
    
    cin >> n;
    while (n) {
        st.clear();
        ll m = n;
        while (m) {
            st.insert(m % 10);
            m /= 10;
        }
        n -= *(prev(st.end()));
        ans++;
    }
    cout << ans << "\n";
    
    return 0;
}
