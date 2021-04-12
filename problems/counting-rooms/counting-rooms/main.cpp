//
//  main.cpp
//  counting-rooms
//
//  Created by Saba Khutsishvili on 4/12/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long

const ll N = 1e3+2;
vector<vector<ll>> mem(N, vector<ll> (N, -1));

void dfs(ll i, ll j) {
    mem[i][j] = 1;
    if (mem[i-1][j] == 0) // can go up
        dfs(i-1, j);
    if (mem[i+1][j] == 0) // can go down
        dfs(i+1, j);
    if (mem[i][j-1] == 0) // can go left
        dfs(i, j-1);
    if (mem[i][j+1] == 0) // can go right
        dfs(i, j+1);
}

int main() {
    ll n, m, ans = 0;
    
    cin >> n >> m;
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= m; ++j) {
            char c;
            cin >> c;
            if (c == '.') {
                mem[i][j] = 0;
            }
        }
    }
    
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= m; ++j) {
            if (mem[i][j] == 0) {
                dfs(i, j);
                ans++;
            }
        }
    }
    cout << ans << "\n";
    
    return 0;
}
