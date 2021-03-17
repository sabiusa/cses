//
//  main.cpp
//  apple-division
//
//  Created by Saba Khutsishvili on 3/17/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long

ll sum(vector<ll> v) {
    ll s = 0;
    for (ull i = 0; i < v.size(); ++i) {
        s += v[i];
    }
    return s;
}

void gen_subsets(ll n, vector<ll> &v, vector<ll> &cur, vector<ll> &s) {
    s.push_back(sum(cur));
    for (ull i = n; i < v.size(); ++i) {
        cur.push_back(v[i]);
        gen_subsets(i + 1, v, cur, s);
        cur.pop_back();
    }
}
 
int main() {
    ll n, p, t = 0, mn = INT64_MAX;
    vector<ll> v, cur, s;
    
    cin >> n;
    while (n--) {
        cin >> p;
        v.push_back(p);
        t += p;
    }
    gen_subsets(0, v, cur, s); // generate all subset sums
    for (ull i = 0; i < s.size(); ++i) {
        ll g1 = s[i]; // group 1
        ll g2 = t - g1; // group 2
        ll d = abs(g1 - g2); // difference
        mn = min(mn, d);
    }
    cout << mn << "\n";
    
    return 0;
}
