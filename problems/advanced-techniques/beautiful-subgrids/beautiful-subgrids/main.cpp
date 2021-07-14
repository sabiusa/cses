//
//  main.cpp
//  beautiful-subgrids
//
//  Created by Saba Khutsishvili on 14.07.21.
//

#include <iostream>
#include <vector>
#include <bitset>

#pragma GCC target("popcnt")
 
using namespace std;
 
#define ll long long
#define ull unsigned long long

const int N = 3e3;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, ans = 0;
    string s;
    
    cin >> n;
    bitset<N> grid[n];
    for (int i = 0; i < n; ++i) {
        cin >> s;
        grid[i] = bitset<N>(s);
    }
    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j) {
            ll cnt = (ll)(grid[i] & grid[j]).count();
            ans += cnt * (cnt-1) / 2;
        }
    }
    cout << ans << "\n";
    
    return 0;
}
