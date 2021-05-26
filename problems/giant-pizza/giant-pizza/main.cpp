//
//  main.cpp
//  giant-pizza
//
//  Created by Saba Khutsishvili on 5/25/21.
//

#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

const ll N = 2e5+2;
ll n;
vector<vector<ll>> adj(N), adjr(N);
vector<bool> vis(N), ans(N);
vector<ll> out, comp(N);

void dfs_out(ll i) {
    vis[i] = 1;
    for (ll a : adj[i]) {
        if (!vis[a]) {
            dfs_out(a);
        }
    }
    out.push_back(i);
}

void dfs_comp(ll i, ll c) {
    comp[i] = c;
    vis[i] = 1;
    for (ll a : adjr[i]) {
        if (!vis[a]) {
            dfs_comp(a, c);
        }
    }
}

int main() {
    ll m, a, b;

    cin >> n >> m;
    for (ll i = 0; i < n; ++i) {
        char s1, s2;
        cin >> s1 >> a >> s2 >> b;
        a--;
        b--;
        a *= 2; // k -> 2k
        b *= 2;
        if (s1 == '-') a++; // !k -> 2k+1
        if (s2 == '-') b++;
        adj[a^1].push_back(b); // (!a => b)
        adj[b^1].push_back(a); // (!b => a)
    }
    for (ll i = 0; i < 2*m; ++i) {
        for (ll a : adj[i]) {
            adjr[a].push_back(i);
        }
    }
    for (ll i = 0; i < 2*m; ++i) {
        if (!vis[i]) {
            dfs_out(i);
        }
    }
    vis.assign(N, 0);
    comp.resize(2*m);
    for (ll i = (ll)out.size() - 1, c = 1; i >= 0; --i) {
        if (!vis[out[i]]) {
            dfs_comp(out[i], c);
            c++;
        }
    }
    for (ll i = 0; i < 2*m; i+=2) {
        if (comp[i] == comp[i+1]) {
            cout << "IMPOSSIBLE" << "\n";
            return 0;
        }
        ans[i/2] = comp[i] > comp[i+1];
    }
    for (ll i = 0; i < m; ++i) {
        if (ans[i]) cout << "+ ";
        else cout << "- ";
    }
    cout << "\n";

    return 0;
}
