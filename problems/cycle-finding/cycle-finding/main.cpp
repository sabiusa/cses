//
//  main.cpp
//  cycle-finding
//
//  Created by Saba Khutsishvili on 4/16/21.
//

#include <iostream>
#include <vector>

using namespace std;
 
#define ll long long
#define ull unsigned long long

struct edge {
    ll a, b, w;
};

const ll N = 2502, INF = 1e18;
vector<edge> adj;
vector<ll> dist(N, INF), path(N, 0);

int main() {
    ll n, m, a, b, w;
    
    cin >> n >> m;
    adj.resize(m);
    for (ll i = 0; i < m; ++i) {
        cin >> a >> b >> w;
        adj[i] = {a, b, w};
    }
    dist[1] = 0;
    for (ll i = 1; i < n; ++i) {
        for (edge e : adj) {
            if (dist[e.b] > dist[e.a] + e.w) {
                dist[e.b] = dist[e.a] + e.w;
                path[e.b] = e.a;
            }
        }
    }
    for (edge e : adj) { // detect cycle in n-th iteration
        if (dist[e.b] > dist[e.a] + e.w) {
            path[e.b] = e.a;
            ll c = e.b;
            for (ll i = 1; i < n; ++i) { // Atmost n-1 iterations needed to end up in the cycle
                c = path[c];
            }
            vector<ll> v = {c};
            for (ll x = path[c]; ; x = path[x]) {
                v.push_back(x);
                if (x == c) {
                    break;
                }
            }
            cout << "YES" << "\n";
            for (ll i = (ll)v.size()-1 ; i >= 0; --i) {
                cout << v[i] << " ";
            }
            cout << "\n";
            return 0;
        }
    }
    cout << "NO" << "\n";
    
    return 0;
}
