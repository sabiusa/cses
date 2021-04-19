//
//  main.cpp
//  longest-flight-route
//
//  Created by Saba Khutsishvili on 4/18/21.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
 
#define ll long long
#define ull unsigned long long

//const ll N = 1e5+2, INF = 1e18;
//vector<vector<ll>> adj(N);
//vector<ll> vis(N, 0), ts, dist(N, 0), path(N, 1);
//
//void top_sort(ll n) {
//    vis[n] = 1;
//    for (ll a : adj[n]) {
//        if (vis[a] == 1) {
//            cout << "IMPOSSIBLE" << "\n"; // not needed, but still
//            exit(0);
//        }
//        if (vis[a] == 0) {
//            top_sort(a);
//        }
//    }
//    vis[n] = 2;
//    ts.push_back(n);
//}
//
//void find_paths() {
//    for (ll n : ts) {
//        for (ll a : adj[n]) {
//            if (dist[a] > dist[n] - 1) { // since edges have no weights, consider weight -1
//                dist[a] = dist[n] - 1;
//                path[a] = n;
//            }
//        }
//    }
//}
//
//void print_path(ll n) {
//    vector<ll> ans = {n};
//    for (ll x = path[n]; ; x = path[x]) {
//        ans.push_back(x);
//        if (x == 1) {
//            break;
//        }
//    }
//    reverse(ans.begin(), ans.end());
//    cout << ans.size() << "\n";
//    for (ll a : ans)
//        cout << a << " ";
//    cout << "\n";
//}
//
//int main() {
//    ll n, m, a, b;
//    
//    cin >> n >> m;
//    for (ll i = 0; i < m; ++i) {
//        cin >> a >> b;
//        adj[a].push_back(b);
//    }
//    top_sort(1);
//    if (vis[n] == 0) {
//        cout << "IMPOSSIBLE" << "\n";
//    } else {
//        reverse(ts.begin(), ts.end());
//        find_paths();
//        print_path(n);
//    }
//    
//    return 0;
//}
