//
//  main.cpp
//  message-route
//
//  Created by Saba Khutsishvili on 4/13/21.
//

#include <iostream>
#include <vector>
#include <queue>
#include <deque>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long

const ll N = 1e5+1;
vector<vector<ll>> adj(N);
vector<ll> vis(N, -1);

void bfs() {
    queue<ll> q;
    q.push(1);
    vis[1] = 0;
    while (q.size()) {
        ll cur = q.front(); q.pop();
        for (ll n : adj[cur]) {
            if (vis[n] < 0) {
                q.push(n);
                vis[n] = cur;
            }
        }
    }
}

int main() {
    ll n, m, a, b;
    
    cin >> n >> m;
    while (m--) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs();
    if (vis[n] < 0) {
        cout << "IMPOSSIBLE" << "\n";
    } else {
        deque<ll> d;
        ll i = n;
        while (i > 0) {
            d.push_front(i);
            i = vis[i];
        }
        cout << d.size() << "\n";
        for (ull i = 0; i < d.size(); ++i) {
            cout << d[i] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
