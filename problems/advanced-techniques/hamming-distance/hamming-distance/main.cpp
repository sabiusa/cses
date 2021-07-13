//
//  main.cpp
//  hamming-distance
//
//  Created by Saba Khutsishvili on 13.07.21.
//

#include <iostream>
#include <vector>
#include <stdio.h>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long

int check(int a, int b) {
    return __builtin_popcount(a ^ b);
}

int main() {
    int n, k, mn = 1e8;
    string s;
    
    cin >> n >> k;
    vector<int> v(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = k-1; j >= 0; --j) {
            if (s[j] == '1') {
                v[i] += (1 << (k-j-1));
            }
        }
    }
    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j) {
            int tmp = check(v[i], v[j]);
            mn = min(mn, tmp);
        }
    }
    cout << mn << "\n";
    
    return 0;
}
