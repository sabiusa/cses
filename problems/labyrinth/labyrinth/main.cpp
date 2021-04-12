//
//  main.cpp
//  labyrinth
//
//  Created by Saba Khutsishvili on 4/12/21.
//

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
const ll N = 1e3+2;
vector<vector<char>> mem(N, vector<char> (N, '#'));
pair<ll, ll> sp, ep;
queue<pair<ll, ll>> q;

void print_path() {
    string s;
    ll i = ep.first, j = ep.second;
    while (mem[i][j] != 'A') {
        s += mem[i][j];
        if (mem[i][j] == 'U') {
            i++;
        } else if (mem[i][j] == 'D') {
            i--;
        } else if (mem[i][j] == 'L') {
            j++;
        } else if (mem[i][j] == 'R') {
            j--;
        }
    }
    string rev = string(s.rbegin(), s.rend());
    cout << "YES" << "\n" << s.length() << "\n" << rev << "\n";
    exit(0);
}

bool can_go(ll i, ll j) {
    return mem[i][j] == '.' || mem[i][j] == 'B';
}

void bfs() {
    q.push(sp);
    while (q.size()) {
        auto pos = q.front();
        ll i = pos.first;
        ll j = pos.second;
        q.pop();
        if (pos == ep) {
            print_path();
        } else {
            if (can_go(i-1, j)) { // can go up
                q.push({i-1, j});
                mem[i-1][j] = 'U';
            }
            if (can_go(i+1, j)) { // can go down
                q.push({i+1, j});
                mem[i+1][j] = 'D';
            }
            if (can_go(i, j-1)) { // can go left
                q.push({i, j-1});
                mem[i][j-1] = 'L';
            }
            if (can_go(i, j+1)) { // can go right
                q.push({i, j+1});
                mem[i][j+1] = 'R';
            }
        }
    }
}
 
int main() {
    ll n, m;
    
    cin >> n >> m;
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= m; ++j) {
            char c;
            cin >> c;
            mem[i][j] = c;
            if (c == 'A')
                sp = {i, j};
            if (c == 'B')
                ep = {i, j};
        }
    }
    bfs();
    cout << "NO" << "\n";
    
    return 0;
}
