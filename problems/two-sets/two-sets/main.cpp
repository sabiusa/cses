//
//  main.cpp
//  two-sets
//
//  Created by Saba Khutsishvili on 3/16/21.
//

#include <iostream>
#include <vector>

using namespace std;

#define ll long long

void print_vec(vector<ll> v) {
    cout << v.size() << "\n";
    for (ll i : v) {
        cout << i << " ";
    }
    cout << "\n";
}

int main() {
    ll n, t, s1 = 0, s2 = 0;
    vector<ll> v1, v2;
    
    cin >> n;
    t = (n * (n + 1)) / 2; // sum 1...n
    if (t % 2 == 1) {
        cout << "NO" << "\n";
    } else {
        cout << "YES" << "\n";
        for (ll i = n; i > 0; --i) {
            if (s1 < s2) {
                v1.push_back(i);
                s1 += i;
            } else {
                v2.push_back(i);
                s2 += i;
            }
        }
        print_vec(v1);
        print_vec(v2);
    }
    
    return 0;
}
