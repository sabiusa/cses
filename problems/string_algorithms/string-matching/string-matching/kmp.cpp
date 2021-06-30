//
//  kmp.cpp
//  string-matching
//
//  Created by Saba Khutsishvili on 29.06.21.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define ll long long
#define ull unsigned long long

const ll N = 2e6+2;
string s, p;
ll ss, ps;
vector<ll> pi(N);

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

ll match() {
    ll ans = 0;
    for (ll i = ps+1; i < ss; ++i) {
        if (pi[i] == ps) {
            ans++;
        }
    }
    return ans;
}

int main() {
    
    cin >> s >> p;
    s = p + "-" + s;
    ss = (ll)s.size();
    ps = (ll)p.size();
    calc_pi();
    cout << match() << "\n";
    
    return 0;
}
