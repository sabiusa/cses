//
//  main.cpp
//  gray-code
//
//  Created by Saba Khutsishvili on 3/18/21.
//

#include <iostream>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long

string bin(ll i, ull n) {
    string s = "";
    while (i) {
        if (i & 1) {
            s = '1' + s;
        } else {
            s = '0' + s;
        }
        i >>= 1;
    }
    while (s.length() < n) {
        s = '0' + s;
    }
    return s;
}

int main() {
    ull n;
    
    cin >> n;
    for (ll i = 0; i < (1 << n); ++i) { // 1 << n <=> 2^n
        ull g = i ^ (i >> 1); // get gray code
        cout << bin(g, n) << "\n";
    }
    
    return 0;
}
