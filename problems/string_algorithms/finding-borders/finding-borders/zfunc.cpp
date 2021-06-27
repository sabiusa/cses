//
//  zfunc.cpp
//  finding-borders
//
//  Created by Saba Khutsishvili on 25.06.21.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define ll long long
#define ull unsigned long long

const ll N = 1e6+2;
string s;
ll ss;
vector<ll> z(N);

void calc_z() {
    for (ll i = 1, l = 0, r = 0; i < ss; ++i) {
        if (i <= r) {
            z[i] = min(r-i+1, z[i-l]);
        }
        while (i + z[i] < ss && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i+z[i]-1 > r) {
            l = i;
            r = i+z[i]-1;
        }
    }
}

void print_borders() {
    vector<ll> ans;
    for (ll i = 1; i < ss; ++i) {
        if (i + z[i] == ss) {
            ans.push_back(z[i]);
        }
    }
    sort(ans.begin(), ans.end());
    for (ll a : ans) {
        cout << a << " ";
    }
    cout << "\n";
}

int main() {
    
    cin >> s;
    ss = (ll)s.size();
    calc_z();
    print_borders();
    
    return 0;
}
