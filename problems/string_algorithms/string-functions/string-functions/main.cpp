//
//  main.cpp
//  string-functions
//
//  Created by Saba Khutsishvili on 05.07.21.
//

#include <iostream>
#include <vector>
#include <string.h>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long

string s;
ll ss;
vector<ll> z, pi;

void calc_z() {
    for (ll i = 1, l = 0, r = 0; i < ss; ++i) {
        if (i <= r) {
            z[i] = min(r-i+1, z[i-l]);
        }
        while (i+z[i] < ss && s[z[i]] == s[z[i]+i]) {
            z[i]++;
        }
        if (z[i]+i-1 > r) {
            l = i;
            r = z[i]+i-1;
        }
    }
}

void calc_pi() {
    for (ll i = 1; i < ss; ++i) {
        ll j = pi[i-1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j-1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }
}

void print_funcs() {
    for (ll i = 0; i < ss; ++i) {
        cout << z[i] << " ";
    }
    cout << "\n";
    for (ll i = 0; i < ss; ++i) {
        cout << pi[i] << " ";
    }
    cout << "\n";
}

int main() {
    
    cin >> s;
    ss = (ll)s.size();
    z.resize(ss+1);
    pi.resize(ss+1);
    calc_z();
    calc_pi();
    print_funcs();
    
    return 0;
}
