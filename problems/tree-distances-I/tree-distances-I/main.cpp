//
//  main.cpp
//  tree-distances-I
//
//  Created by Saba Khutsishvili on 4/29/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long

const ll N = 2e5+2;
vector<vector<ll>> adj;
vector<ll> distA, distB(N);
ll max_dist = 0, max_pos = 1;

void dfs1(ll i, ll p, ll c) {
    distA[i] = c;
    for (ll a : adj[i]) {
        if (a == p) continue;
        dfs1(a, i, c+1);
        if (max_dist <= distA[a]) {
            max_dist = distA[a];
            max_pos = a;
        }
    }
}

void dfs2(ll i, ll p, ll c) {
    distB[i] = c;
    for (ll a : adj[i]) {
        if (a == p) continue;
        dfs2(a, i, c+1);
    }
}

int main() {
    ll n, a, b;
    
    cin >> n;
    adj.resize(n+1);
    distA.resize(n+1);
    distB.resize(n+1);
    for (ll i = 1; i < n; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(1, 0, 0); // find radius of tree a-b
    a = max_pos;
    fill(distA.begin(), distA.end(), 0);
    dfs1(a, a, 0); // max distances from a
    b = max_pos;
    dfs2(b, b, 0); // max distances from b
    for (ll i = 1; i <= n; ++i) { //
        cout << max(distA[i], distB[i]) << " "; // either from a or b
    }
    cout << "\n";
    
    return 0;
}
