//
//  zfunc.cpp
//  finding-periods
//
//  Created by Saba Khutsishvili on 25.06.21.
//

#include <iostream>
#include <vector>
#include <string>

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
        while (i+z[i] < ss && s[z[i]] == s[i+z[i]]) {
            z[i]++;
        }
        if (i+z[i]-1 > r) {
            l = i;
            r = i+z[i]-1;
        }
    }
}

int main() {
    
    cin >> s;
    ss = (ll)s.size();
    calc_z();
    for (ll k = 1; k < ss; ++k) {
        if (z[k] == ss - k) {
            cout << k << " ";
        }
    }
    cout << s.size() << "\n";
    
    return 0;
}
