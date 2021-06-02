//
//  main.cpp
//  knight's-tour
//
//  Created by Saba Khutsishvili on 6/2/21.
//

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

#define ll long long
#define ull unsigned long long

int tour[8][8], deg[8][8];
vector<vector<vector<pair<int, int>>>> moves(8, vector<vector<pair<int, int>>>(8));

bool is_valid(int i, int j) {
    return (i >= 0 && i <= 7) && (j >= 0 && j <= 7);
}

void fill_moves() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (is_valid(i-1, j-2)) { deg[i][j]++; moves[i][j].push_back({i-1, j-2}); }
            if (is_valid(i-1, j+2)) { deg[i][j]++; moves[i][j].push_back({i-1, j+2}); }
            if (is_valid(i+1, j-2)) { deg[i][j]++; moves[i][j].push_back({i+1, j-2}); }
            if (is_valid(i+1, j+2)) { deg[i][j]++; moves[i][j].push_back({i+1, j+2}); }
            if (is_valid(i-2, j-1)) { deg[i][j]++; moves[i][j].push_back({i-2, j-1}); }
            if (is_valid(i-2, j+1)) { deg[i][j]++; moves[i][j].push_back({i-2, j+1}); }
            if (is_valid(i+2, j-1)) { deg[i][j]++; moves[i][j].push_back({i+2, j-1}); }
            if (is_valid(i+2, j+1)) { deg[i][j]++; moves[i][j].push_back({i+2, j+1}); }
        }
    }
}

void print_tour() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            cout << tour[i][j] << " ";
        }
        cout << "\n";
    }
}

void dfs_tour(int x, int y, int c) {
    tour[x][y] = c;
    if (c == 64) {
        print_tour();
        exit(0);
    }
    vector<array<int, 3>> next;
    auto pos = moves[x][y];
    for (int i = 0; i < (int)pos.size(); ++i) {
        int ki = pos[i].first;
        int kj = pos[i].second;
        if (!tour[ki][kj]) { // free square
            int ks = deg[ki][kj];
            next.push_back({ks, ki, kj});
        }
    }
    sort(next.begin(), next.end()); // Warnsdorf’s rule to select minimum outdegree square for next move
    for (auto a : next) {
        dfs_tour(a[1], a[2], c+1);
    }
    tour[x][y] = 0;
}

int main() {
    int x, y;
    
    cin >> x >> y;
    fill_moves();
    dfs_tour(y-1, x-1, 1);
    
    return 0;
}
