//
//  main.cpp
//  increasing-array
//
//  Created by Saba Khutsishvili on 3/15/21.
//

#include <iostream>

using namespace std;

#define ll long long

int main() {
    ll n, k, p, r = 0;
    
    cin >> n >> k;
    while (--n) {
        cin >> p;
        if (p < k) {
            r += (k - p);
        }
        k = max(k, p);
    }
    cout << r << "\n";
    
    return 0;
}
