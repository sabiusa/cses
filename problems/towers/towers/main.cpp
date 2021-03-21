//
//  main.cpp
//  towers
//
//  Created by Saba Khutsishvili on 3/21/21.
//

#include <iostream>
#include <set>

using namespace std;

#define ll long long
#define ull unsigned long long

int main() {
    ll n, k;
    multiset<ll> mt;
    
    cin >> n;
    while (n--) {
        cin >> k;
        auto it = mt.upper_bound(k);
        if (it != mt.end()) {
            mt.erase(it);
        }
        mt.insert(k);
    }
    cout << mt.size() << "\n";
    
    return 0;
}
