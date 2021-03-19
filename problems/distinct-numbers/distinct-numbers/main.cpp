//
//  main.cpp
//  distinct-numbers
//
//  Created by Saba Khutsishvili on 3/19/21.
//

#include <iostream>
#include <set>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long

int main() {
    ll n, x;
    set<ll> st;
    
    cin >> n;
    while (n--) {
        cin >> x;
        st.insert(x);
    }
    cout << st.size() << "\n";
    
    return 0;
}
