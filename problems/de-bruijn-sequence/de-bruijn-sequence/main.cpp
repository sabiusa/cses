//
//  main.cpp
//  de-bruijn-sequence
//
//  Created by Saba Khutsishvili on 5/30/21.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

#define ll long long
#define ull unsigned long long

const ll K = 2;
char c[K] = {'0', '1'}; // possible chars
unordered_map<string, bool> vis;
vector<ll> path;

void dfs(string s) {
    for (ll i = 0; i < K; ++i) {
        string tmp = s + c[i];
        if (!vis[tmp]) {
            vis[tmp] = 1;
            dfs(tmp.substr(1)); // abcd -> bcd
            path.push_back(i);
        }
    }
}

ll expo(ll n, ll k) {
    ll res = 1;
    while (k) {
        if (k % 2) res *= n;
        n *= n;
        k /= 2;
    }
    return res;
}

string de_bruijn(ll n) {
    string s = string(n-1, c[0]); // all n-1 combinations, starting with all 0s
    dfs(s);
    
    string ans;
    ll p = expo(K, n); // total number of edges
    for (ll i = 0; i < p; ++i) {
        ans += c[path[i]];
    }
    return ans + s;
}

int main() {
    ll n;
    
    cin >> n;
    vis.reserve(1 << n);
    cout << de_bruijn(n) << "\n";
    
    return 0;
}
