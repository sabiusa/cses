//
//  main.cpp
//  investigation
//
//  Created by Saba Khutsishvili on 4/20/21.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
 
#define ll long long
#define ull unsigned long long

struct info {
    ll cost, path_count, min_path, max_path;
};

const ll N = 1e5+2, INF = 1e18, MOD = 1e9+7;
vector<vector<pair<ll, ll>>> adj(N);
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
vector<info> mem(N, {INF, 0, 0, 0});

void dij() {
    q.push({0, 1});
    mem[1].path_count = 1;
    while (q.size()) {
        auto cur = q.top();
        q.pop();
        ll src = cur.second;
        ll cost = cur.first;
        
        if (mem[src].cost < cost) continue;
        
        for (auto a : adj[src]) {
            ll b = a.first;
            ll w = a.second;
            if (mem[b].cost == cost + w) {
                mem[b].path_count += mem[src].path_count;
                mem[b].path_count %= MOD;
                mem[b].min_path = min(mem[b].min_path, mem[src].min_path + 1);
                mem[b].max_path = max(mem[b].max_path, mem[src].max_path + 1);
            } else if (mem[b].cost > cost + w) {
                mem[b].cost = cost + w;
                mem[b].path_count = mem[src].path_count;
                mem[b].min_path = mem[src].min_path + 1;
                mem[b].max_path = mem[src].max_path + 1;
                q.push({mem[b].cost, b});
            }
        }
    }
}

int main() {
    ll n, m, a, b, w;
    
    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }
    dij();
    cout << mem[n].cost << " " << mem[n].path_count << " ";
    cout << mem[n].min_path << " " << mem[n].max_path << "\n";
    
    return 0;
}

