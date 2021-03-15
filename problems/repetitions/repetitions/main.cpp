//
//  main.cpp
//  repetitions
//
//  Created by Saba Khutsishvili on 3/15/21.
//

#include <iostream>

using namespace std;

#define ll long long

int main() {
    ll m = 0, r = 0;
    string s;
    char p = 'A';
    
    cin >> s;
    for (char c : s) {
        if (c == p) {
            ++r;
            m = max(m, r);
        } else {
            p = c;
            r = 1;
        }
    }
    cout << m << "\n";
    
    return 0;
}

