//
//  main.cpp
//  missing-number
//
//  Created by Saba Khutsishvili on 3/15/21.
//

#include <iostream>

using namespace std;

#define ll long long

int main() {
    ll n, t, k, s = 0;
    
    cin >> n;
    t = (n * (n + 1)) / 2;
    while (--n) {
        cin >> k;
        s += k;
    }
    cout << t - s << "\n";
    
    return 0;
}
