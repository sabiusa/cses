//
//  main.cpp
//  subordinates
//
//  Created by Saba Khutsishvili on 4/28/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long

const ll N = 2e5+2;
vector<vector<ll>> adj(N);
vector<ll> mem(N, 0);

void dfs(ll i, ll p) {
    mem[i] = 1;
    for (ll a : adj[i]) {
        if (a == p) continue;
        dfs(a, i);
        mem[i] += mem[a];
    }
}

int main() {
    ll n, a;
        
    cin >> n;
    for (ll i = 2; i <= n; ++i) {
        cin >> a;
        adj[a].push_back(i);
    }
    dfs(1, 0);
    for (ll i = 1; i <= n; ++i) {
        cout << mem[i]-1 << " ";
    }
    cout << "\n";
    
    return 0;
}
