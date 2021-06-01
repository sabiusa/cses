//
//  main.cpp
//  hamiltonian-flights
//
//  Created by Saba Khutsishvili on 6/1/21.
//

#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

const int N = 20, MOD = 1e9+7;
int n, m;
int mem[1<<N][N];
vector<vector<int>> adj(N);

int main() {
    int a, b;
    
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
    }
    mem[1][0] = 1;
    for (int i = 3; i < (1<<n); i+=2) { // skip even numbers, because last bit would be 0, so not reachable
        vector<int> mask;
        for (int j = 0; j < n; j++) {
            if (i & (1<<j)) {
                mask.push_back(j);
            }
        }
        if (mask.size()) {
            for (int j : mask) {
                for (int a : adj[j]) {
                    int prev = i ^ (1 << a);
                    mem[i][a] += mem[prev][j];
                    mem[i][a] %= MOD;
                }
            }
        }
    }
    cout << mem[(1<<n)-1][n-1] << "\n";
    
    return 0;
}
